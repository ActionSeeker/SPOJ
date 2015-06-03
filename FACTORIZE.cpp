#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define MAX 10001
#define NOP 1000000
#define MAXTRY 200
#define MAXTRY2 1000
typedef unsigned long long int ULLI;
ULLI PRIMES[NOP];
ULLI PDIV[NOP];
ULLI FACTORS[NOP];
char A[MAX];
int k;//gives the size of the seive
void Seive()
{
    PRIMES[0] = 1;
    PRIMES[1] = 1;
    for(int i = 2;i*i<=NOP;i++)
    {
        if(PRIMES[i]==0)
        {
            for(int j = 2;j<=NOP/i;j++)
            {
                PRIMES[i*j] = 1;
            }
        }
    }
    for(int i = 2;i<NOP;i++)
    {
        if(PRIMES[i]==0)
        {
            PDIV[k++] = i;
            //if(k<100)cout<<i<<" ";
        }
    }
}
int LongDiv(char* str, ULLI num)
{
    char QUO[MAX+1];
    int L = strlen(str);
    bool flag = true;
    long int sum = 0;
    int l = 0;
    for(int i = 0;i<L;i++)
    {
        sum = sum*10+A[i]-48;
        if(sum<num && flag);
        else
        {
            flag = false;
            QUO[l++] = sum/num+48;
            sum = sum % num;//the remainder
        }
    }
    if(sum!=0)return 0;
    else
    {
        QUO[l]='\0';
        strcpy(str,QUO);
        return 1;
    }
}
int main()
{
    Seive();
    long int T;//cout<<k<<"\n";
    cin>>T;
    while(T--)
    {
        cin>>A;
        int L = strlen(A);
        if(L<=18)
        {
            unsigned long long int SAY = 0;
            for(int i = 0;i<L;i++)
            {
                SAY = SAY*10+A[i]-48;
            }
           // cout<<SAY<<endl;
            int f = 0;
            for(int i = 0;i<k;i++)
            {
                if(SAY==1)break;
                while(SAY%PDIV[i]==0)
                {
                    //fully divisible1
                    SAY = SAY/PDIV[i];
                    FACTORS[f++] = PDIV[i];
                    if(SAY==1)break;
                }
            }
            if(SAY!=1)cout<<f+1<<"\n";
            else  cout<<f<<"\n";
            for(int i = 0;i<f;i++)
            {
                cout<<FACTORS[i]<<"\n";
            }
            if(SAY!=1)cout<<SAY<<"\n";
        }
        else
        {
           int f= 0;
           int j = 0;
           for(int i= 0;i<k && i<MAXTRY2;i++)
           {
               if(strlen(A)==1 && A[0]=='1')break;
               while(LongDiv(A,PDIV[i]) && ++j<MAXTRY)
               {
                   if(strlen(A)==1 && A[0]=='1')break;
                   FACTORS[f++] = PDIV[i];
               }
           }
            if(strlen(A)==1 && A[0]=='1')cout<<f+1<<"\n";
            else  cout<<f<<"\n";
            for(int i = 0;i<f;i++)
                {
                    cout<<FACTORS[i]<<"\n";
                }
            if((strlen(A)==1 && A[0]=='1')==false)cout<<A<<"\n";
        }
    }
    return 0;
}
