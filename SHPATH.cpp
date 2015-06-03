#include<iostream>
#include<map>
#include<queue>
#include<stdio.h>
#include<list>
#define pp pair<int,int>
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
map<string,int> M;
list<pp> garray[10001];
int D[10001];

void Init(int s, int V)
{
    for(int i = 0;i<=V;i++)
    {
        D[i]=987654321;
    }
    D[s]=0;
}

class Graph
{
    int V;
public:
    Graph(int x);
    void pushBack(int src, pp dest);
};
Graph::Graph(int x)
{
    this->V = x+1;
    for(int i = 1;i<V;i++)
        garray[i].clear();
    M.clear();
}
void Graph::pushBack(int src, pp dest)
{
    garray[src].push_back(dest);
}


class Prioritize
{
public:
    int operator()(const pair<int, int>& a , const pair<int, int>& b)
    {
        return a.second < b.second;
    }
};


priority_queue<pp, vector<pp >, Prioritize> PQ;
string A, B, city;
int main()
{
    //ios_base::sync_with_stdio(0);
    int T;
    int N, NEIG, COST, K;
    T = read_int();
    while(T--)
    {
        N = read_int();
        int V = N;
        Graph G(N);
        int count = 1;
        while(N--)
        {
            cin>>city;
            M.insert(make_pair(city,count));
            K = read_int();
            while(K--)
            {
                NEIG = read_int();
                COST = read_int();
                //pushing into vector
                G.pushBack(count,pp(NEIG,COST));
            }
            ++count;
        }
        int NOP;
        NOP = read_int();
        while(NOP--)
        {
            cin>>A>>B;
            int src = M[A];
            Init(src,V);
            PQ.push(pp(0,src));
            while(!PQ.empty())
            {
                int v = PQ.top().second;
                int d = PQ.top().first;
                PQ.pop();
                if(d<=D[v])
                {
                    list<pp>::iterator it;
                    for(it = garray[v].begin();it!=garray[v].end();it++)
                    {
                        int v2 = it->first;
                        int w2 = it->second;
                        if(D[v2]>D[v]+w2)
                        {
                                D[v2] = D[v] + w2;
                              // add the vertex to queue
                              PQ.push(pp(D[v2], v2));
                        }
                    }
                }
            }
            printf("%d\n",D[M[B]]);
        }
    }
    return 0;
}
