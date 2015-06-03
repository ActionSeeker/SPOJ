#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;
int main()
{
    double L, AR;
    while(1)
    {
        cin>>L;
        if(L==0)break;
        else
        {
            AR = .5 * L * L/M_PI;
        }
        printf("%.2lf\n",AR);
    }
    return 0;
}
