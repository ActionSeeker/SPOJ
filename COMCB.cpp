#include<iostream>
#include<bits/stdc++.h>
#define pp pair<int,int>
using namespace std;
int MARKED[30][30];
#define TRUE 1
#define FALSE 0
string SEQ;
queue<pp >Q;
queue<int> nextMove;
void Init()
{
    for(int i = 0;i<30;i++)
        for(int j = 0;j<30;j++)
        MARKED[i][j]=0;
    SEQ.clear();
    while(!Q.empty())Q.pop();
}
int main()
{
    int T, R, C;
    cin>>T;
    while(T--)
    {
        cin>>R>>C;
        Init();
        Q.push(pp(0,0));
        int count = 0;
        int val = R*C;//the number of cells
        bool flag = false;
        nextMove.push(0);
        while(!Q.empty())
        {
            int i = Q.front().first;
            int j = Q.front().second;
            Q.pop();
            cout<<i<<" "<<j<<" "<<endl;
                MARKED[i][j]=TRUE;
                SEQ.push_back(j+65);
                SEQ.push_back(i+49);//column row format
                ++count;
            if(count == val)
            {
                flag = true;
                break;
            }
        }
        /*if(flag)*/cout<<SEQ<<"\n";
        //else cout<<"-1\n";
    }
    return 0;
}
