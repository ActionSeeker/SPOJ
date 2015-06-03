#include<iostream>
#include<stdio.h>
typedef unsigned long long int LLI;
LLI BASE[2][2];
LLI UNIT[1][1];
LLI MOD;
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
LLI powerTwo(int N)
{
    LLI ans = 1;
    LLI base = 2;
    while(N)
    {
        if(N%2)ans = ans * base;
        base = base * base;
        N/=2;
    }
    return ans;
}
LLI fastMultiply(LLI N, LLI M)
{
    setBase();
    setUnit();
    MOD = powerTwo(M);
    while(N)
    {
        if(N%2)mulBaseUnit(MOD);
        squareBase(MOD);
        N/=2;
    }
    return UNIT[0][1];
}
using namespace std;
int main()
{
    LLI T,N, M;
    LLI SUM;
        scanf("%llu%llu",&N,&M);
        SUM = fastMultiply(N,M);
        printf("%llu\n",SUM);
    return 0;
}
