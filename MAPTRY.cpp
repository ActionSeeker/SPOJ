#include<iostream>
#include<map>
#include<set>
using namespace std;
struct INF
{
    int N;
    int freq;
    int tstamp;
    bool operator <(const INF &b)const
    {
        if(freq<b.freq)
        return false;
        else if(freq>b.freq)
            return true;
        else if(freq==b.freq)
        {
            if(tstamp<b.tstamp)
                return true;
            return false;
        }
    }
};
set<int>S;
map<int,INF> M;
map<int,INF>::iterator it;
int main()
{
    int N,C,S;
    INF P;
    int count = 0;
    cin>>N>>C;
    for(int i = 0;i<N;i++)
    {
        cin>>S;
        it = M.find(S);
        if(it==M.end())//i.e. does not exists
        {
            ++count;
            P.freq = 1;
            P.tstamp = count;
            M.insert(make_pair(S,P));
        }
        else
        {
            M[S].freq++;
        }
    }
    for(it = M.begin();it!=M.end();it++)
    {
        int freq = it->second.freq;
        while(freq--)
            cout<<it->first<<" ";
    }
    return 0;
}
