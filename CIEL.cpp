#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T, N;
    cin>>T;
    while(T--)
    {
        cin>>N;
        if
            (N&(N-1)==0 && N<2049)cout<<"1\n";
        else if(N<2049)
           cout<<__builtin_popcount(N)<<"\n";
        else
            cout<<N/2048 + __builtin_popcount(N%2048)<<"\n";
    }
    return 0;
}
