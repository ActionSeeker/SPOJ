#include<iostream>
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
long long int power(long long int exp)
{
    long long base = 2;
    long long ans = 1;
    while(exp)
    {
        if(exp%2)ans = (ans*base)%MOD;
        base = (base*base)%MOD;
        exp/=2;
    }
    return ans;
}
int main()
{
    long long int T, N, ans;
    cin>>T;
    while(T--)
    {
        cin>>N;
        if(N&1)
        {
            N/=2;
            ans = ((power(N)<<2)%MOD-2+MOD)%MOD;
        }
        else
        {
            N/=2;
            ans = ((3*power(N))%MOD-2+MOD)%MOD;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
