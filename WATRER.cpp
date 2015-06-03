#include<iostream>
#include<algorithm>
#include<queue>
#define pp pair<int,int>
#define PUD(i,j) PUDDLE[i][j]
#define VIS(i,j) VISITED[i][j]
using namespace std;
int PUDDLE[100][100];
int VISITED[100][100];

queue<pair<int,int> > Q;
void Init()
{
    for(int i = 0;i<100;i++)
        for(int j = 0;j<100;j++)
        {
            PUDDLE[i][j] = 0;
            VISITED[i][j]=0;
        }
}
int main()
{
    int T, N, M;
    int hoff[4]={-1,0,+1,0};
    int voff[4]={0,1,0,-1};
    cin>>T;
    while(T--)
    {
        cin>>N>>M;
        for(int i = 0;i<N;i++)
            for(int j = 0;j<M;j++)
                cin>>PUDDLE[i][j];
        Init();
        int i = 1, j = 1;
        int ans = 0;
        Q.push(pp(i,j));//traversal begins from here, pushing coordinates
        while(!Q.empty())
        {
            pp V = Q.front();
            Q.pop();
            i = V.first;
            j = V.second;
            int key = PUD(i,j);
            VISITED[i][j]=1;
            int dir = 0;
            int hi = 0,vi = 0;
            while(dir<4)
            {
                ++dir;
                if(PUD(i+hoff[hi],j+voff[vi])<key && !VIS(i+hoff[hi],j+voff[vi]))
                   {
                       Q.push(pp(i+hoff[hi],j+voff[vi]));
                   }
                else if(VIS(i+hoff[hi],j+voff[vi])==1)
                {
                    ans += PUD(i+hoff[hi],j+voff[vi]);cout<<ans<<endl;
                }
                else
                {
                    ans += PUD(i+hoff[hi],j+voff[vi])-PUD(i,j);cout<<ans<<endl;
                }
                VIS(i,j) = 1;
                ++hi;
                ++vi;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
