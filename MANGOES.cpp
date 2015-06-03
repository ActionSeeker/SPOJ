#include<iostream>
using namespace std;
int main()
{
    long long int T ,N;
    cin>>T;
    while(T--)
    {
        cin>>N;
        long long int ANS = (N-1)/2;
        ANS = (ANS * ANS)%N;
        cout<<ANS<<"\n";
    }
    return 0;
}
