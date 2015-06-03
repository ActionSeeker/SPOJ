#include<iostream>
#include<string>
using namespace std;
string num;
int main()
{
    int ans[10] = {1,0,0,0,0,0,1,0,2,1};
    long long int T;
    cin>>T;
    while(T--)
    {
        cin>>num;
        long long int sum = 0;
        for(int i = 0;i<num.length();i++)
        {
            sum+=ans[num[i]-48];
        }
        cout<<sum<<"\n";
    }
    return 0;
}
