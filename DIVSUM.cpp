#include<iostream>
#include<cmath>
using namespace std;
long int ANS(long int N)
{
    long int SUM = 0;
    for(long int k = 1;k<=sqrt(N);k++)
    {
        if(N%k==0)
            ++SUM;
    }
    return SUM;
}
int main()
{
    long int T, N, S;
    cin>>T;
    while(T--)
    {
        cin>>N;
        cout<<2*ANS(N)<<"\n";
    }
    return 0;
}
