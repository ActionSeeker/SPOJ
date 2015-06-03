#include<iostream>
#include<queue>
#include<string.h>
#include<cstdio>
using namespace std;
queue<char> Q;
char str[100];
void QEmpty()
{
    while(!Q.empty())
        Q.pop();
}

int main()
{
   while(1)
   {
       if(scanf("%s",str)==EOF)break;
       bool broken = false;
       bool isjava = false, iscpp = false;
       if(str[0]!='_' && str[0]>90 &&str[strlen(str)-1]!='_')//valid
       {
           Q.push(str[0]);
           for(int i = 1;i<strlen(str);i++)
           {
                if(str[i]=='_')
                {
                    isjava = true;
                    if(iscpp)
                    {
                        broken=true;break;
                    }
                    if(str[i+1]=='_' || str[i+1]>=65 && str[i+1]<91)
                    {
                        broken=true;break;
                    }
                    else
                    {

                        Q.push(str[i+1]-32);
                        ++i;
                    }
                }
                else if(str[i]>64 && str[i]<91)
                {
                   iscpp = true;
                   if(isjava)
                   {
                       broken=true;
                       break;
                   }
                   if(str[i+1]=='_')
                   {
                       broken = true;
                       break;
                   }
                   else
                   {
                        Q.push('_');
                        Q.push(str[i]+32);
                   }
                }
                else Q.push(str[i]);
           }
       }
       else broken = true;
       if(broken == true)printf("Error!\n");
       else
       {
           while(!Q.empty())
           {
               cout<<Q.front();
               Q.pop();
           }
           cout<<"\n";
       }
       QEmpty();
   }
    return 0;
}
