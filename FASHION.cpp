#include<iostream>
#include<algorithm>
using namespace std;
int MEN[1000];
int WOMEN[1000];
int main()
{
    long int S, P;
    int T, H, M, N;
    cin>>T;
    while(T--)
    {
        cin>>N;
        S = 0;
        for(int i = 0;i<N;i++)
            cin>>MEN[i];
        for(int i = 0;i<N;i++)
            cin>>WOMEN[i];
        sort(MEN, MEN + N);
        sort(WOMEN, WOMEN + N);
        for(int i = 0;i<N;i++)
        {
            P = MEN[i]* WOMEN[i];
            S+=P;
        }
        cout<<S<<"\n";
    }
    return 0;
}
