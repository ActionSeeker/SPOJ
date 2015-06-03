#include<iostream>
typedef unsigned long long int ULLI;
using namespace std;
ULLI fastMul(ULLI base, ULLI pow)
{
    ULLI ans = 1;
    while(pow)
    {
        if(pow%2)ans = base*ans;
        base = base*base;
        pow/=2;
    }
    return ans;
}
int main()
{
    int T;
    ULLI TO;
    cin>>T;
    while(T--)
    {
        cin>>TO;
        cout<<fastMul(3,TO)-1<<"\n";
    }
    return 0;
}
