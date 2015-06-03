#include<iostream>
using namespace std;
int main()
{
    int x, y, T;
    cin>>T;
    while(T--)
    {
        cin>>x>>y;
        if(x==y)
        {
            if(x%2 && y%2)cout<<2*x-1;
            else cout<<2*x;
        }
        else if(x-y==2)
        {
            if(x%2==0)
            {
                cout<<x+y;
            }
            else cout<<2*y+1;
        }
        else cout<<"No Number";
        cout<<"\n";
    }
    return 0;
}
