#include<iostream>
#include<algorithm>
#define INF 2139062143
using namespace std;
int TRIGRAPH[100000][3];
void clear()
{
    for(int i = 0;i<100000;i++)
        for(int j = 0;j<3;j++)
        {
            TRIGRAPH[i][j]=0;
        }
}
int main()
{
    int N;
    int P = 0, a, b, c, d;
    while(1)
    {
        cin>>N;
        if(N==0)break;
        else
        {
            clear();
            for(int i = 0;i<N;i++)
            {
                for(int j = 0;j<3;j++)
                    cin>>TRIGRAPH[i][j];
            }
            ++P;
            TRIGRAPH[0][0] = INF;
            TRIGRAPH[0][2]+=TRIGRAPH[0][1];
            for(int i = 1;i<N;i++)
                {
                    for(int j = 0;j<3;j++)
                    {

                        a = (j==2)?INF:TRIGRAPH[i-1][j+1];
                        b = TRIGRAPH[i-1][j];
                        c = (j==0)?INF:TRIGRAPH[i-1][j-1];
                        d = (j==0)?INF:TRIGRAPH[i][j-1];
                        TRIGRAPH[i][j]+=min(min(a,b),min(c,d));
                    }
                }
                cout<<P<<". "<<TRIGRAPH[N-1][1]<<"\n";
        }
    }
    return 0;
}
