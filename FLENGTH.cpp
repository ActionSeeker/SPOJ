#include<iostream>
#include<cmath>
#include<cstdio>
#define PI2 2*M_PI
using namespace std;
typedef unsigned long long int ULLI;
double ans;
int main()
{
    ULLI T, N;
    double L10E = log10(M_E);
    double L102PI = log10(PI2);
    cin>>T;
    while(T--)
    {
        cin>>N;
        if(N==0)ans = 0;
        else if(N==1)ans = 0;
        else ans = N*(log10(N)-L10E)+0.5*log10(N)+0.5*L102PI;
        cout<<(ULLI)(ans+1)<<"\n";
    }
    return 0;
}
