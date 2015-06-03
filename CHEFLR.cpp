#include<iostream>
#include<string>
#define MOD 1000000007
using namespace std;
int main()
{
    int T;
    long int ANS;
    string S;
    cin>>T;
    while(T--)
    {
        cin>>S;
        ANS = 1;
        for(int i = 0;i<S.length();i++)
        {
            ANS = ANS%MOD;
            if(S[i]=='l')
            {
                if(i%2==1)ANS = (ANS*2-1)%MOD;//even levels
                else ANS = (ANS*2)%MOD;
            }
            else
            {
                if(i%2==1)ANS = (ANS*2+1)%MOD;//even levels
                else ANS = (ANS*2+2)%MOD;
            }
        }
        cout<<ANS<<"\n";
    }
}
