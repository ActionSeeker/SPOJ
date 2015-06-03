#include<iostream>
#include<string>
using namespace std;
string S;
char TOANDFRO[201][201];
int main()
{
    int COLS, ROWS, r, c;
    while(1)
    {
        cin>>COLS;
        if(COLS==0)break;
        else
        {
            cin>>S;
            ROWS = S.length()/COLS;
            r = 0;
            c = 0;

            for(int i = 0;i<S.length();i++)
            {
                if(r%2==0)
                {
                    TOANDFRO[r][c]=S[i];
                    ++c;
                    if(c==COLS)
                    {
                        ++r;
                        c = COLS-1;
                    }
                }
                else if(r%2==1)
                {
                    TOANDFRO[r][c]=S[i];
                    if(c==0)
                    {
                        ++r;
                        c = 0;
                        --i;
                    }
                    --c;
                }
            }
            for(int i = 0;i<COLS;i++)
            {
                for(int j = 0;j<ROWS;j++)
                {
                    cout<<TOANDFRO[j][i];
                }
            }
            cout<<"\n";
        }
    }
}
