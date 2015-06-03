#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int HASH[30000];
map<string,int> DNA;
string SEQ;
void Init()
{
    for(int i = 0;i<30000;i++)
        HASH[i]=0;
}
int main()
{
    int NOP, LEN;
    while(1)
    {
        cin>>NOP>>LEN;
        Init();
        DNA.clear();
        int N = NOP;
        if(NOP == 0 && LEN == 0)break;
        while(NOP--)
        {
            cin>>SEQ;
            if(DNA.find(SEQ)!=DNA.end())
            {
                DNA[SEQ]++;
            }
            else
            {
                DNA.insert(make_pair(SEQ,1));
            }
        }
        for(map<string,int>::iterator it = DNA.begin();it!=DNA.end();it++)
           {
               HASH[DNA[it->first]]++;
           }
        for(int i = 1;i<N+1;i++)
        {
            cout<<HASH[i]<<"\n";
        }
    }
    return 0;
}
