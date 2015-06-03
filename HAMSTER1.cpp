#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;
int main()
{
    int T;
    double V, K1, K2, KT;
    double theta;
    cin>>T;
    while(T--)
    {
        cin>>V>>K1>>K2;
        theta = 0.5*atan(-1*4*K1/K2);
        theta = theta + M_PI/2;
        V = V * V;
        KT = K1 * V * sin(2*theta)*0.1 + K2 * V * sin(theta) * sin(theta) * 0.05;
        printf("%.3lf %.3lf\n",theta,KT);
    }
    return 0;
}
