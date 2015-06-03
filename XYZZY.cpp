#include<iostream>
#include<list>
#include<limits.h>
#include<cstdio>

int DP[200];
int W[200];

using namespace std;

class Graph
{
    int V;
    list<int> *garray;
public:
    Graph(int x);
    void pushBack(int src, int dest);
    bool BellmanFord(int s);
    void InitSource(int s);
    void Relax(int u, int y, int w);
    void showGraph();
};
Graph::Graph(int x)
{
    this->V = x+1;
    garray = new list<int>[V];
}
void Graph::pushBack(int src, int dest)
{
    garray[src].push_back(dest);
}
void Graph::InitSource(int s)
{
    for(int i = 1;i<200;i++)
        DP[i] = INT_MAX;
    DP[s] = 0;
}
void Graph::Relax(int u, int v, int w)
{
    DP[v] = DP[u] + w;
}
bool Graph::BellmanFord(int s)
{
    InitSource(s);
    list<int>::iterator it;
    for(int i = 1;i<V-1;i++)
    {
        for(int i = 1;i<V-1;i++)
        {
            for(it = garray[i].begin();it!=garray[i].end();it++)
            {
                if(W[*it]<101)Relax(i,*it,W[*it]);
            }
        }
    }
    for(int i = 1;i<V;i++)
    {
        for(it = garray[i].begin();it!=garray[i].end();it++)
        {
            if(DP[*it]>DP[i]+W[*it])
               {
                   return false;
               }
        }
    }
    return true;
}
void Graph::showGraph()
{
    list<int>::iterator it;
    for(int i = 1;i<V;i++)
    {
        for(it = garray[i].begin();it!=garray[i].end();it++)
            cout<<*it<<" ";
        cout<<endl;
    }
}
int main()
{
    int V, numofnodes, node;
    int weight;
    while(1)
    {
        cin>>V;
        if(V==-1)break;
        else
        {
            Graph G(V);
            for(int i = 1;i<=V;i++)
            {
                cin>>W[i]>>numofnodes;
                while(numofnodes--)
                {
                    cin>>node;
                    G.pushBack(i,node);
                }
            }
            bool a = G.BellmanFord(1);
            int ans = DP[V];
            ans+=100;
            if(ans>0 && a)printf("winnable\n");
            else printf("hopeless\n");
        }
    }
    return 0;
}
