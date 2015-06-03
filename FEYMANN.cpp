#include<iostream>
using namespace std;
int main()
{
    int N;
    while(1)
    {
        cin>>N;
        if(N==0)break;
        else cout<<N*(2*N+1)*(N+1)/6<<"\n";
    }
    return 0;
}
