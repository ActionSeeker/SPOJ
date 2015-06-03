#include<iostream>
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long int LLI;
LLI longPow(LLI b, LLI e)
{
    LLI ans = 1;
    while(e)
    {
        if(e%2)ans = (ans*b)%MOD;
        b = (b*b)%MOD;
        e/=2;
    }
    return ans;
}
LLI longModInv(LLI a)
{
    return longPow(a,MOD-2);
}
LLI modCoeff(LLI n, LLI k)
{
    LLI numerator = 1;
    LLI denominator = 1;
    for(int i = 0;i<k;i++)
        numerator = (numerator*(n-i))%MOD;
    for(int i = 1;i<=k;i++)
        denominator = (denominator*i)%MOD;
    return (numerator*longModInv(denominator))%MOD;
}
int main()
{
    long long int N;
    LLI ans;
        cin>>N;
        ans = 0;
        if(N>12)
        {
            if(N%2)//n is odd
            {
              int oddi = 1;
              while(N-oddi>11)
              {
                  ans+=modCoeff((N-oddi)/2-1,5);
                  ans = ans%MOD;
                  oddi+=2;
              }
            }
            else
            {
                int eveni=2;
                while(N-eveni>11)
                {
                    ans+=modCoeff((N-eveni)/2-1,5);
                    ans = ans%MOD;
                    eveni+=2;
                }
            }
        }
        cout<<ans<<endl;
    return 0;
}
