#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
int EOS[MAX+1];
int segS[MAX+2];
vector<int> PRIMES;
void SOE()
{
    EOS[0] = EOS[1] = 1;
    for(int i = 2;i*i<=MAX;i++)
    {
        if(EOS[i]==0)
        {
            for(int j = 2;j<=MAX/i;j++)
            {
                EOS[i*j]=1;
            }
        }
    }
    for(int i = 2;i<=MAX;i++)
    {
        if(EOS[i]==0)PRIMES.push_back(i);
    }
}
void cls()
{
    for(int i = 0;i<=MAX+1;i++)
        segS[i]=0;
}
int main()
{
    SOE();
    int T, B, E;
    cin>>T;
    while(T--)
    {
        cin>>B>>E;
        if(B<=MAX && E<=MAX)
        {
            int i = 0;
            for(;;i++)
            {
                if(PRIMES[i]<B);
                else if(PRIMES[i]>E)break;
                else cout<<PRIMES[i]<<"\n";
            }
        }
        else
        {
            B = max(B,MAX);
            cls();
            int i;
            int k = 0;
            for(i = 0;PRIMES[i]*PRIMES[i]<=E;i++)
            {
                int nextBegin = (B/PRIMES[i])*PRIMES[i];
                nextBegin+=PRIMES[i];
                for(int j = nextBegin+PRIMES[i];j<=E;j+=PRIMES[i])
                {
                    segS[j-B]=1;
                }
            }
            for(int k=0;k<=(B-E+1);k++)
              if(segS[i]==0)cout<<k+B+1<<"\n";
        }
    }
}
