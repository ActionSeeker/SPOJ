#include<iostream>
#include<float.h>
#include<stdio.h>
#include<math.h>
using namespace std;
typedef long long int LLI;
int main()
{
    int T;
    LLI R1, R2, R3;
    double K1, K2, K3, K4 , KWE, R4;
    cin>>T;
    while(T--)
    {
        cin>>R1>>R2>>R3;
        K1 = R1*1.0;
        K2 = R2*1.0;
        K3 = R3*1.0;
        K1 = 1/K1;
        K2 = 1/K2;
        K3 = 1/K3;
        KWE = K1*K2 + K2*K3 + K3*K1;
        K4 = K1 + K2 + K3 + 2 * sqrt(KWE);
        R4 = 1/K4;
        printf("%.6lf\n",R4);
    }
    return 0;
}
