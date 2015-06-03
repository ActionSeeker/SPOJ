#include<iostream>
#include<list>
#include<cstdio>
#include<set>
#define pp pair<int,int>
#include<map>
using namespace std;

#define gc getchar
inline int read_int() {
char c = gc();
while(c<'0' || c>'9') c = gc();
long long int ret = 0;
while(c>='0' && c<='9') {
ret = 10 * ret + c - 48;
c = gc();
}
return ret;
}

list<pp>::iterator it;
set<pp> Q;
int D[10001];
list<pp> garray[10001];
map<string,int> MCITY;
class Graph
{
    int V;
public:
    Graph(int x);
    void pushBack(int src, pp dest);
    void initSingSource(int s);
    void relax(int u, pp v);//contains both v and weight
    int Dijkstra(int s,int dest);
};
Graph::Graph(int x)
{
    this->V = x+1;
    for(int i = 1;i<V;i++)
        garray[i].clear();
    MCITY.clear();
}
void Graph::pushBack(int src, pp dest)
{
    garray[src].push_back(dest);
}
void Graph::initSingSource(int s)
{
    for(int i = 1;i<V;i++)
    {
        D[i] = 987654321;
    }
    D[s] = 0;
}
void Graph::relax(int u, pp y)
{
    //first gives the vertex and second gives the weight
    if(D[y.first]>D[u]+y.second)
    {
        D[y.first] = D[u] + y.second;
    }
}
int Graph::Dijkstra(int s, int dest)
{
    initSingSource(s);
    for(int i = 1;i<V;i++)
    {
        Q.insert(pp(D[i],i));
    }
    while(!Q.empty())
    {
        int u = Q.begin()->second;
        int uw = Q.begin()->first;
        Q.erase(Q.begin());
        for(it = garray[u].begin();it!=garray[u].end();it++)
        {
            int v = it->first;
            int w = it->second;
            if(D[v]>D[u]+w)
            {
                if(D[v]!=987654321)
                {
                    Q.erase(Q.find(pp(D[v],v)));
                }
                D[v] = D[u]+w;
                Q.insert(pp(D[v],v));
            }
        }
    }
    return D[dest];
}
string city;
int main()
{
    int T;
    int N, NEIG, COST, K;
    T = read_int();
    while(T--)
    {
        N = read_int();
        int count = 1;
        Graph G(N);
        while(N--)
        {
            cin>>city;
            MCITY.insert(make_pair(city,count));
            K = read_int();
            while(K--)
            {
                NEIG = read_int();
                COST = read_int();
                G.pushBack(count,pp(NEIG,COST));
            }
            ++count;
        }
        int NOP;
        string A, B;
        NOP = read_int();
        while(NOP--)
        {
            cin>>A>>B;
            printf("%d\n",G.Dijkstra(MCITY[A],MCITY[B]));

        }
    }
    return 0;
}

