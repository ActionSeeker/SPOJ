#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef  unsigned long long int ULLI;
ULLI power(ULLI base, ULLI exp, ULLI mod)
{
    base = base%mod;
    ULLI ans = 1;
    while(exp)
    {
        if(exp%2)ans = (ans*base)%mod;
        base = (base*base)%mod;
        exp/=2;
    }
    return ans;
}
int main()
{
    ULLI B,P,MOD;
    while(cin>>B>>P>>MOD)
    {
        cout<<power(B,P,MOD)<<"\n";
    }
    return 0;
}
