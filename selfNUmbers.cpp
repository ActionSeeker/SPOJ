#include<iostream>
#include<stdio.h>
using namespace std;
#define MAX 1000000
int arr[MAX+1];
int sum(int N)
{
    int rem, S=0;
    while(N)
    {
        rem = N%10;
        S+=rem;
        N/=10;
    }
    return S;
}
int main()
{
    for(int i = 1;i<MAX+1;i++)
    {
        int SUM = i+sum(i);
        if(SUM<MAX)
        arr[i+sum(i)]=1;
    }
    for(int i = 1;i<MAX;i++)
    {
        if(arr[i]==0)
            cout<<i<<"\n";
    }
}
