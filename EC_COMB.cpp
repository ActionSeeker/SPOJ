#include<iostream>
#include<queue>
using namespace std;
queue<int>Q;
long int retRev(int x)
{
    long int ans = 0;
    while(x)
    {
        Q.push(x%2);
        x/=2;
    }
    while(!Q.empty())
    {
        ans = ans * 2+Q.front();
        Q.pop();
    }
    return ans;
}
int main()
{
    int T, A;
    cin>>T;
    while(T--)
    {
        cin>>A;
        if(A%2==0)cout<<retRev(A)<<"\n";
        else cout<<A<<"\n";
    }
    return 0;
}
