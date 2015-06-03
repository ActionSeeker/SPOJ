#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long int ARR1[100001];
long int ARR2[100001];
long int MAXSUM(int S1, int S2)
{
    long int sum1 = 0;
    long int sum2 = 0;
    long int result = 0;
    int i = 0,j = 0;
    while(i<S1 && j<S2)
    {
        if(ARR1[i]>ARR2[j])
        {
            sum2=sum2+ARR2[j++];
        }
        else if(ARR2[j]>ARR1[i])
        {
            sum1=sum1+ARR1[i++];
        }
        else
        {
            result+=max(sum1,sum2);
            sum1 = 0;
            sum2 = 0;
            while(ARR1[i]==ARR2[j]&&i<S1&&j<S2)
            {
                result=result+ARR1[i++];
                j++;
            }
        }
    }
    if(i<S1)
    {
        while(i<S1)
            sum1+=ARR1[i++];
    }
    if(j<S2)
    {
        while(j<S2)
            sum2+=ARR2[j++];
    }
    result+=max(sum1,sum2);
    return result;
}
int main()
{
    int S1, S2;
    while(1)
    {
        cin>>S1;if(S1==0)break;for(int i = 0;i<S1;i++)cin>>ARR1[i];
        cin>>S2;if(S2==0)break;for(int i = 0;i<S2;i++)cin>>ARR2[i];
        cout<<MAXSUM(S1,S2)<<"\n";
    }
    return 0;
}
