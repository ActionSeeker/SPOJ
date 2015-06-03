#include<iostream>
#include<queue>
using namespace std;
typedef long long int LLI;
deque<LLI> EXP;
deque<char> OPER;
int main()
{
    LLI T;
    LLI NUM, ANS, IA, IB, IC;
    char OP;
    cin>>T;
    while(T--)
    {
        //scan the expression and evaluate it
        while(1)
        {
            cin>>NUM;EXP.push_back(NUM);//cout<<EXP.back()<<endl;
            cin>>OP;
            if(OP =='=')
                break;
            else if(OP==' ');
            else OPER.push_back(OP);
        }
        while(OPER.size())
        {
            OP = OPER.front();OPER.pop_front();
            IA = EXP.front();EXP.pop_front();
            IB = EXP.front();EXP.pop_front();
            switch(OP)
            {
                case '+':{IC = IA+IB;EXP.push_front(IC);break;}
                case '-':{IC = IA-IB;EXP.push_front(IC);break;}
                case '*':{IC = IA*IB;EXP.push_front(IC);break;}
                case '/':{IC = IA/IB;EXP.push_front(IC);break;}
            }
        }
        cout<<EXP.front()<<"\n";
        EXP.pop_front();
    }
}
