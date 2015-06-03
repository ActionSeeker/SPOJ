#include<iostream>
#include<stack>
#include<stdio.h>
#include<vector>
#include<set>
#define pp pair<int,int>
#define TRUE 1
#define FALSE 0
using namespace std;

char MAZE[25][25];
int VISITED[25][25];
stack<pp >S;
stack<int> D;
vector<pp > entries;

void Init()
{
    for(int i = 0;i<25;i++)
    {
        for(int j = 0;j<25;j++)
            VISITED[i][j]=FALSE;
    }
}

void StackEmpty()
{
    while(!S.empty())S.pop();
}

int main()
{
    int H[4]={-1,0,1,0};
   // freopen("ans.html","w",stdout);
    int V[4]={0,1,0,-1};
    int T, R, C;
    cin>>T;
    while(T--)
    {
        cin>>R>>C;
        pp ENT;
        pp EXIT;
        entries.clear();
        for(int i = 0;i<R;i++)
        {
            for(int j = 0;j<C;j++)
            {
                cin>>MAZE[i][j];
                if(MAZE[i][j]=='.' && (i==0 || i==R-1 || j==0 || j==C-1))
                {
                    entries.push_back(make_pair(i,j));
                }
            }
        }
        if(entries.size()!=2)
            cout<<"invalid\n";
        else
        {
            bool found = false;
            EXIT = make_pair(entries.at(1).first,entries.at(1).second);
            ENT = make_pair(entries.at(0).first, entries.at(0).second);
            StackEmpty();
            Init();
            S.push(ENT);
            while(!S.empty()&& !found)
            {
                pp vertex = S.top();S.pop();
                if(VISITED[vertex.first][vertex.second]==TRUE || vertex.first<0 || vertex.first>=R || vertex.second <0 || vertex.second>=C)
                    continue;
                if(vertex.first==EXIT.first && vertex.second == EXIT.second)
                {
                    found = true;
                    break;
                }
                VISITED[vertex.first][vertex.second]=TRUE;
                if(MAZE[vertex.first][vertex.second]=='#')continue;
                S.push(pp(vertex.first-1,vertex.second));
                S.push(pp(vertex.first,vertex.second+1));
                S.push(pp(vertex.first+1,vertex.second));
                S.push(pp(vertex.first, vertex.second-1));
            }
            if(found==true)cout<<"valid\n";
            else cout<<"invalid\n";
        }
    }
    return 0;
}
