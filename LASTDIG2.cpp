#include<iostream>
#include<string>
using namespace std;
typedef unsigned long long int ULL;
ULL fastMult(int b, ULL exp)
{
    ULL ans = 1;
    while(exp)
    {
        if(exp % 2)ans = (ans*b)%10;
        b = (b*b)%10;
        exp/=2;
    }
    return ans;
}
int main()
{
    string a;
    ULL b;
    int T, D;
    cin>>T;
    while(T--)
    {
        cin>>a>>b;
        D = a[a.length()-1]-48;
        if(D==0 || D==1)
            cout<<D<<"\n";
        else cout<<fastMult(D,b)<<"\n";
    }
    return 0;
}
