#include<cstdio>
typedef unsigned long long int ULLI;
using namespace std;
ULLI NMODP(ULLI n, ULLI p)
{
    ULLI res = 1;
    while(n>1)
    {
        res = (res*((n/p)%2?p-1:1))%p;
        for (ULLI i=2; i<=n%p; ++i)
			res = (res * i) % p;
		n /= p;
    }
    return res%p;
}
int main()
{
    ULLI N, P, T;
    scanf("%llu",&T);
    while(T--)
    {
        scanf("%llu%llu",&N,&P);
        printf("%llu\n",NMODP(N,P));
    }
    return 0;
}
