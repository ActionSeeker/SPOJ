#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define SIZE 100000
int ARR[SIZE+1];
int main()
{
    int N, M;
    char ch;
    int d;
    cin>>N>>M;
    int begIndex = -1;
    for(int i = 0;i<N;i++)
    {
        cin>>ARR[i];
    }
    while(M--)
    {
        cin>>ch>>d;
        switch(ch)
        {
            case 'R':cout<<ARR[(begIndex+d)%N]<<"\n";break;
            case 'C':begIndex = (begIndex+d)%N;break;
            case 'A':begIndex = (begIndex - d + N)%N;break;
        }
    }
    return 0;
}
