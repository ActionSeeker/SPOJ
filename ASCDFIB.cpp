#include<bits/stdc++.h>
using namespace std;
#define MOD 100000
#define gc getchar
#define SIZE 100001
typedef long long int LLI;
int ans[1110000];
int HASH[SIZE];
inline int read_int() {
    char c = getchar();
    while(c<'0' || c>'9') c = gc();
    long long int ret = 0;
    while(c>='0' && c<='9') {
    ret = 10 * ret + c - 48;
    c = gc();
    }
return ret;
}
int main()
{
    int T, beg, terms;
    T = read_int();
    ans[1] = 0;ans[2] = 1;
    for(int i = 3;i<1110000;i++)
    {
        ans[i] = (ans[i-1]+ans[i-2])%MOD;
    }
    for(int t = 1;t<=T;t++)
    {
        beg = read_int();
        terms = read_int();
        memset(HASH,0,sizeof(HASH));
        printf("Case %d: ",t);
        for(int i = beg;i<=beg+terms;i++)
        {
            HASH[ans[i]]++;
        }
        int count = 0;
        for(int i = 0; i<SIZE && count<=100;i++)
        {
           if(HASH[i]!=0)
           {
               int xyz = HASH[i];
               while(xyz--)
               {
                   printf("%d ",i);
                   ++count;
                   if(count>=100)break;
               }
               if(count>=100)break;
           }
           if(count>=100)break;
        }
        printf("\n");
    }
     return 0;
}
