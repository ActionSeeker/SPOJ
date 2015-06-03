#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int LLI;
LLI fastMul(LLI b, LLI e)
{
    LLI ans = 1;
    while(e)
    {
        if(e%2)ans = ans*b;
        b = b*b;
        e/=2;
    }
    return ans;
}
char S[40];
int main()
{
    LLI T;
   // cout<<fastMul(2,30);
    cin>>T;
    while(T--)
    {
        scanf("%s",S);
        LLI sum = 1, ans = 1;
        for(int i = 1;i<strlen(S);i++)
        {
            if(S[i]==S[i-1])
               ++sum;
            else
            {
                ans*=fastMul(2,sum-1);
                sum = 1;
            }
        }
        ans*=fastMul(2,sum-1);
        cout<<ans<<"\n";
        cout<<"\n";
    }
    return 0;
}
