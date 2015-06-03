#include<iostream>
using namespace std;
int main()
{
    long int N,K,T,F,test;
    cin>>test;
    while(test--)
    {
        cin>>N>>K>>T>>F;
        cout<<F + (F - N)/(K - 1)<<"\n";
    }
    return 0;
}
