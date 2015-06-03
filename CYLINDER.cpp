#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    int T;
    double W, H;
    double CYLR, VOL, VOL1, VOL2, CYLH, PMIN;
    while(1)
    {
        cin>>W>>H;
        if(W==0&&H==0)break;
        else
        {
            CYLR = .5*(W/M_PI);
            CYLH = (H - 2*CYLR);
            VOL1 = M_PI * CYLR * CYLR * CYLH;
            CYLR = min(W/2,H/(2*M_PI+2));
            CYLH = W;
            VOL2 = M_PI * CYLR * CYLR * CYLH;
            VOL = max(VOL1,VOL2);
        }
        printf("%.3lf\n",VOL);
    }
    return 0;
}
