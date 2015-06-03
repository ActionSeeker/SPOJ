#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    long long int N, K, I;
    while(1)
    {
        cin>>N;
        bool flag = false;
        if(N==-1)break;
        else
        {
            --N;
            if(N % 3==0)
            {
                K = N/3;
                K = 4*K + 1;
                I = sqrt(K);
                if(K - I * I == 0)
                {
                    --K;
                    if(K % 2 ==0)
                        flag = true;
                }
            }
            if(flag)cout<<"Y\n";
            else cout<<"N\n";
        }
    }
}
