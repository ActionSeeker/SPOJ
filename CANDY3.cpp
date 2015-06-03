#include<iostream>
using namespace std;
typedef long long int LLI;
int main()
{
    LLI T, CAN, SUM, MOD;
    cin>>T;
    while(T--)
    {
        cin>>MOD;
        SUM = 0;
        for(int i = 0;i<MOD;i++)
        {
            cin>>CAN;
            CAN = CAN%MOD;
            SUM = (SUM + CAN)%MOD;
        }
        SUM = SUM%MOD;
        if(SUM == 0)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
