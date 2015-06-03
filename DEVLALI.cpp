#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 1000000
#define SQT 1000
long int HARSHAD[MAX+1];
long int VAL[MAX+1];
void seive()
{
    HARSHAD[0]=HARSHAD[1]=1;
    for(long int i = 2;i<=SQT;i++)
    {
        for(long int j = 2;j<=MAX/i;j++)
        {
            HARSHAD[i*j]=1;
        }
    }
}
long int SUM(long int N)
{
    long int S = 0, R;
    while(N)
    {
        R = N%10;
        S +=R;
        N/=10;
    }
    return S;
}
void DEVLALI()
{
    for(long int i = 1;i<=MAX;i++)
    {
        long int T = i+SUM(i);
        if(T<=MAX)
            HARSHAD[T]=1;
    }
     seive();
     VAL[0]=1-HARSHAD[0];
     for(int i = 1;i<=MAX;i++)
     {
         VAL[i] = VAL[i-1]+(1-HARSHAD[i]);
     }
}
int main()
{
    ios_base::sync_with_stdio(false);
    DEVLALI();
    long int T, L, R, C;
    cin>>T;
    while(T--)
    {
        cin>>L>>R;
        C = VAL[R]-VAL[L];
        if(HARSHAD[L]==0)++C;
        cout<<C<<"\n";
    }
    return 0;
}
