#include<iostream>
#include<map>
using namespace std;
map<int,int> M;//stores index, occurrence pairs
map<int,int>::iterator MIT;
int main()
{
    int T, S, temp;
    cin>>T;
    bool satisfied;
    while(T--)
    {
        cin>>S;
        while(S--)
        {
            cin>>temp;
            MIT = M.find(temp);
            if(MIT != M.end())//value found
            {
                M[temp]++;
            }
            else
            {
               M.insert(make_pair(temp,1));
            }
            for(MIT = M.begin();MIT!=M.end();MIT++)
                cout<<MIT->first<<MIT->second<<" ";
        }
    }
    return 0;
}
