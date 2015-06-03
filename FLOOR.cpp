#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long double LD;
typedef unsigned long int ULLI;
ULLI powC(ULLI base, ULLI exp,ULLI mod)
{
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
    int T;
    ULLI N, MOD;
    cin>>T;
    while(T--)
    {
        cin>>N>>MOD;
        ULLI ans = 0;
        int k = sqrt(N);
        for(ULLI i = 1;i<=N;i++)
        {
            ans += ((powC(i,4,MOD))*((N/i)));
            if(i==k)cout<<ans<<" ";
            ans = ans%MOD;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
