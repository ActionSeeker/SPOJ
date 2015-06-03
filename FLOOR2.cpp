#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ULLI;
ULLI powC(ULLI b, ULLI exp,ULLI mod)
{
    ULLI ans = 1;
    while(exp)
    {
        if(exp%2)ans = (ans*b)%mod;
        b = (b*b)%mod;
        exp/=2;
    }
    return ans;
}
ULLI sum4(ULLI num,ULLI mod)
{
    //calculate sum from 1 to num % mod
    ULLI sum = (6*powC(num,5,mod)) % mod + (15*powC(num,4,mod))%mod + (10*powC(num,3,mod))%mod - (num%mod);
    while(sum<0)sum = sum + mod;
    sum = sum % mod;
    return sum;
}
int main()
{
    int T;
    ULLI N, MOD;
    ULLI ans;
    ULLI sump;
    cin>>T;
    while(T--)
    {
        cin>>N>>MOD;
        ULLI ans = 0;
        ULLI root = sqrt(N);
        for(int i = 1;i*i<=N;i++)
        {
            ans = ans+powC(i,4,MOD)*(N/i);
            if(ans<0)ans = ans+MOD;
            ans = ans%MOD;
        }
        cout<<ans<<" ";
        ULLI beginNum = floor(N/(root+1));
        bool flag = true;
        if(beginNum==0)flag = false;
        ULLI lastIndex = root;
        while(beginNum>1)
        {
            ULLI numTerm = floor(N/beginNum);
            {
                ans = ans+(beginNum*(sum4(numTerm,30*MOD)/30-sum4(lastIndex,30*MOD)/30));
                ans = ans+MOD;
                ans = ans%MOD;
                lastIndex = numTerm;
                beginNum--;
            }
        }
        cout<<ans<<" ";
        if(flag)
        {
            ans = ans + sum4(N,30*MOD)/30 - sum4(N/2,30*MOD)/30;
            while(ans<0)ans = ans+MOD;
            ans = ans%MOD;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
