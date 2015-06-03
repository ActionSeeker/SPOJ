#include<iostream>
#include<cmath>
using namespace std;
typedef unsigned long long int USI;
int main()
{
    USI T, X, ANS;
    cin>>T;
    while(T--)
    {
        cin>>X;
        ANS = sqrt(1+8*(X-1))-1;
        ANS/=2;
        cout<<ANS<<"\n";
    }
    return 0;
}
