#include<iostream>
using namespace std;
double P,L,M;
int main()
{
    ios_base::sync_with_stdio(false);
    cin>>P>>L>>M;
    if(P*M>=L)cout<<"yes\n";
    else cout<<"no\n";
    return 0;
}
