#include<iostream>
#include<bits/stdc++.h>
long int KH[30000];
long int D[30000];
using namespace std;
int main()
{
    long int T, K, N, diff;
    cin>>T;
    while(T--)
    {
        cin>>N>>K;
            for(int i = 0;i<N;i++)
            {
                cin>>KH[i];
            }
            sort(KH,KH+N);
            long int diff = 0;
            for(int i = 0, j = K-1;i<(N-K+1);i++,j++)
            {
                D[i] = KH[i] - KH[j];
                D[i] = -1*D[i];
            }
        sort(D,D+N-K+1);
        if(K==1)diff = 0;
        else diff = D[0];
        cout<<diff<<"\n";
    }
    return 0;
}
