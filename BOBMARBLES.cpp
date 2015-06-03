#include<iostream>
using namespace std;
typedef unsigned long long int ULLI;
int main()
{
    ULLI N;
    while(1)
    {
        cin>>N;if(N==0)break;
        ++N;
        ULLI ans = (3*N*N - N)/2;
        cout<<ans<<"\n";
    }
    return 0;
}
