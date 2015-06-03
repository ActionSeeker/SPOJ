#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
int main()
{
    double r, N,ANS, THETA, COS;
    while(1)
    {
        cin>>r>>N;
        if(r==0 && N==0)break;
        else
        {
            N = N*2;
            THETA = 2*M_PI/N;
            COS = 1-cos(THETA);
            ANS = r * sqrt((2)/COS);
            printf("%.2lf\n",ANS);
        }
    }
    return 0;
}
