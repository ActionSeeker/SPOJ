#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define pp pair<int,int>
int chess[9][9];
int dist[9][9];
queue<pp >Q;
void Init()
{
    for(int i = 0;i<9;i++)
    {
        for(int j = 0;j<9;j++)
            {
                chess[i][j]=WHITE;
                dist[i][j]=0;
            }
    }
    while(!Q.empty())Q.pop();
}
int main()
{
    int T;
    string A, B;
   // freopen("Haw.txt","w",stdout);
    pp SRC, DEST;
    cin>>T;
    int H[8]={1,2,2,1,-1,-2,-2,-1};//add to X
    int VE[8]={2,1,-1,-2,-2,-1,1,2};//add to Y
    while(T--)
    {
        cin>>A>>B;
        SRC = pp(A[1]-48,A[0]-96);
        DEST = pp(B[1]-48,B[0]-96);
        Init();
        Q.push(SRC);
        bool found = false;
        int d = 0;
        if(SRC.first==DEST.first && SRC.second == DEST.second)
        {
            found = true;
            Q.pop();
        }
        while(!Q.empty() && found!=true)
        {
            pp V = Q.front();
            Q.pop();
            int i = V.first;
            int j = V.second;
            chess[i][j]=GRAY;
            d = dist[i][j];
            if(i==DEST.first && j==DEST.second)
             {
                found = true;break;
             }
            int dir = 0;
            while(dir<8)
            {
                int x = i+H[dir];
                int y = j+VE[dir];
                if(x>=1 && x<9 && y>=1 && y<9)
                {
                    if(chess[x][y]==WHITE)
                       {
                            Q.push(pp(x,y));
                            dist[x][y]=d+1;
                       }
                }
                 ++dir;
            }
            chess[i][j]=BLACK;
        }
        if(found)cout<<dist[DEST.first][DEST.second]<<"\n";
    }
    return 0;
}
