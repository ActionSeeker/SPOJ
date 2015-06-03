#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ULLI;
#define MOD 1000007
int main()
{
    ULLI T,N;
    cin>>T;
    while(T--)
    {
        cin>>N;
        ULLI ans = N*(3*N+1)/2;
        ans = ans%1000007;
        cout<<ans<<"\n";
    }
    return 0;
}
