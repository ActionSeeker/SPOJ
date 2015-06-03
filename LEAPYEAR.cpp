#include<iostream>
#include<string>
using namespace std;
int main()
{
    string year;
    cin>>year;
    int l= year.length();
    if(l>=4)
    {int lasttwo = (year[l-2]-48)*10+(year[l-1]-48);
    if(lasttwo==0)
    {
        int then = (year[l-4]-48)*10+(year[l-3]-48);
        if(then%4==0)cout<<"YES";
        else cout<<"NO";
    }
    else if(lasttwo%4==0 && lasttwo!=0)
        cout<<"YES";
    else cout<<"NO";}
    else
    {
        int YEAR = 0;
        for(int i = 0;i<l;i++)
        {
            YEAR=10*YEAR+(year[i]-48);
        }
        if(YEAR % 100==0)
        {
            if(YEAR % 4 ==0 )cout<<"YES";
            else cout<<"NO";
        }
        else if(YEAR%4==0)cout<<"YES";
        else cout<<"NO";
    }
    return 0;
}
