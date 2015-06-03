#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ULLI;
ULLI gcd(ULLI a, ULLI b)
{
    if(a==0)return b;
    else if(b==0)return a;
    else return gcd(b,a%b);
}
int main()
{
    int T;
    ULLI A,B;
    ULLI ans;
    cin>>T;
    while(T--)
    {
        cin>>A>>B;
        ans = A*B;
        ans = ans/gcd(A,B);
        cout<<ans<<"\n";
    }
    return 0;
}
