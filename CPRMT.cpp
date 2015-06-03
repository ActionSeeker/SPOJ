#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a, b;
    while(cin>>a>>b)
    {
        vector<char> MS;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        set_intersection(a.begin(),a.end(),b.begin(),b.end(),back_inserter(MS));
        sort(MS.begin(),MS.end());
        for(vector<char>::iterator it= MS.begin();it!=MS.end();it++)
            cout<<*it;
        cout<<"\n";
    }
}
