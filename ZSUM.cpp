#include<iostream>
#include<cstdio>
#define MOD 10000007
using namespace std;
typedef unsigned long long int LLI;
LLI fastPower(LLI base, LLI exp)
{
    LLI ans = 1;
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
    ios_base::sync_with_stdio(false);
    LLI N,K,l;
    while(1)
    {
        cin>>N>>K;
        if(N==0 && K==0)break;
        l = N;
        LLI sum = (2*(fastPower(l-1,K)%MOD + fastPower(l-1,l-1)%MOD)+(fastPower(l,K)%MOD+fastPower(l,l)%MOD))%MOD;
        cout<<sum<<"\n";
    }
    return 0;
}
