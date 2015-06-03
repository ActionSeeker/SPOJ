#include<string>
#include<iostream>
using namespace std;
string spelling;
int main()
{
    int T, DEL;
    cin>>T;
    for(int k = 1;k<=T;k++)
    {
        cin>>DEL>>spelling;
        cout<<k<<" ";
        for(int i = 0;i<spelling.length();i++)
        {
            if(i==DEL-1);
            else cout<<spelling[i];
        }
        cout<<"\n";
    }
    return 0;
}
