#include<iostream>
#include<stdio.h>
using namespace std;
typedef long long int LLI;
LLI BASE[2][2];
LLI UNIT[1][1];
void setBase()
{
    BASE[0][0]=BASE[0][1]=BASE[1][0]=1;
    BASE[1][1]=0;
}
void setUnit()
{
    UNIT[0][0]=UNIT[1][1]=1;
    UNIT[0][1]=UNIT[1][0]=0;
}
void mulBaseUnit(LLI MOD)
{
    //Multiply base and unit matrices
     LLI a,b,c,d;
    a = (UNIT[0][0]*BASE[0][0]+UNIT[0][1]*BASE[1][0])%MOD;
    b = (UNIT[0][0]*BASE[0][1]+UNIT[0][1]*BASE[1][1])%MOD;
    c = (UNIT[1][0]*BASE[0][0]+UNIT[1][1]*BASE[1][0])%MOD;
    d = (UNIT[1][0]*BASE[0][1]+UNIT[1][1]*BASE[1][1])%MOD;
    UNIT[0][0] = a;
    UNIT[0][1] = b;
    UNIT[1][0] = c;
    UNIT[1][1] = d;

}
void squareBase(LLI MOD)
{
    //square the base
   LLI a,b,c,d;
    a = (BASE[0][0]*BASE[0][0]+BASE[0][1]*BASE[1][0])%MOD;
    b = (BASE[0][0]*BASE[0][1]+BASE[0][1]*BASE[1][1])%MOD;
    c = (BASE[1][0]*BASE[0][0]+BASE[1][1]*BASE[1][0])%MOD;
    d = (BASE[1][0]*BASE[0][1]+BASE[1][1]*BASE[1][1])%MOD;
    BASE[0][0] = a;
    BASE[0][1] = b;
    BASE[1][0] = c;
    BASE[1][1] = d;
}
LLI fastMultiply(LLI N, LLI MOD)
{
    setBase();
    setUnit();
    while(N)
    {
        if(N%2)mulBaseUnit(MOD);
        squareBase(MOD);
        N/=2;
    }
    return UNIT[0][1];
}
int main()
{
    LLI T, MOD, ANS, N;
    cin>>T;
    while(T--)
    {
        cin>>N>>MOD;
        ANS = (2*(fastMultiply(N+2,MOD)-1)-N)%MOD;
        if(ANS<0)
        {
            LLI Q = -ANS/MOD + 1;
            ANS = (ANS + MOD*Q)%MOD;
        }
        cout<<ANS<<"\n";
    }
    return 0;
}
