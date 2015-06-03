#include<iostream>
using namespace std;
typedef unsigned long long int ULLI;
int main()
{
    ULLI K, T;
    ULLI A = 192;
    cin>>T;
    while(T--)
    {
        cin>>K;
        cout<<A+(K-1)*250<<"\n";
    }
    return 0;
}
