#include<iostream>
#include<stdio.h>
typedef unsigned long long int LLI;
LLI MOD;
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
void mulBaseUnit()
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
void squareBase()
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
LLI fastMultiply(LLI N)
{
    setBase();
    setUnit();
    while(N)
    {
        if(N%2)mulBaseUnit();
        squareBase();
        N/=2;
    }
    return UNIT[0][1];
}
LLI powe2(LLI exp)
{
    LLI ans = 1;
    LLI base = 2;
    while(exp)
    {
        if(exp%2)ans = ans*base;
        base = base*base;
        exp/=2;
    }
    return ans;
}
using namespace std;
int main()
{
    LLI N,M;
    while(cin>>N>>M)
    {
        MOD = powe2(M);
        cout<<fastMultiply(N)<<"\n";
    }
}
