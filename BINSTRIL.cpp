#include<iostream>
using namespace std;
typedef long long int LLI;
int main()
{
    LLI N, M, TOP, BOT, ANS;
    LLI T;
    cin>>T;
    while(T--)
    {
        cin>>N>>M;
        /*if(N==0 && M==0)ANS = 1;
        else if(N==0)ANS = 0;
        else if(M==0)ANS = 0;
        else if(N==M)ANS = 1;
        else
        {
            LLI CEIL = (M+1)/2 + 1;
            LLI FLOOR = (M-1);
            TOP = N - CEIL;
            BOT = FLOOR/2;
            while(1)
            {
                if(BOT==0)
                {
                    ANS = 1;break;
                }
                else if(BOT==1)
                {
                    ANS = (TOP%2);
                    break;
                }
                else if(TOP==BOT)
                {
                    ANS = 1;
                    break;
                }
                else if(TOP%2 == 0 && BOT%2 == 1)
                {
                    ANS = 0;
                    break;
                }
                else
                {
                    TOP = TOP/2;
                    BOT = BOT/2;
                }
            }
        }*/
        TOP = N-M;
        BOT = (M-1)/2;
        ANS = (TOP & BOT);
        if(ANS == 0)cout<<"1\n";
        else cout<<"0\n";
       //cout<<ANS<<"\n";
    }
    return 0;
}
