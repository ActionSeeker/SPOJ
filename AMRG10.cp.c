#include<iostream>
#include<bits/stdc++.h>
int KH[20000];
using namespace std;
int main()
{
    int T;
    int diff;
    cin>>T;
    while(T--)
    {
        cin>>N>>K;
        if(K==1)diff = 0;
        else
        {
            for(int i = 0;i<N;i++)
            {
                cin>>KH[i];
            }
            sort(KH,KH+N);

        }
    }
    return 0;
}
