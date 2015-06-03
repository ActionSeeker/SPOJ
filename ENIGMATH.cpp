#include<iostream>
using namespace std;
typedef long long int LLI;
LLI gcd(LLI a, LLI b)
{
    if(a==0)return b;
    else if(b==0)return a;
    else return gcd(b,a%b);
}
int main()
{
    int T;
    LLI A, B;
    cin>>T;
    while(T--)
    {
        cin>>A>>B;
        LLI g = gcd(A,B);
        A = A/g;
        B = B/g;
        cout<<B<<" "<<A<<"\n";
    }
    return 0;
}
