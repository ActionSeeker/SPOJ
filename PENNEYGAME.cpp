#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string>
using namespace std;
//USE KMP PATTERN
char str[1000];
char pat[3];
int fail[3];
void FailFunction(string pat)
{
    int i, j;
    fail[0]=-1;
    for(j=1;j<2;j++)
    {
        i = fail[j-1];
        while(pat[j]!=pat[i+1]&&i>=0)
        {
            i = fail[i];
        }
        if(pat[i+1]==pat[j])
            fail[j]=i+1;
        else fail[j]=-1;
    }
}
int KMP(char* str, string pat)
{
    FailFunction(pat);
    int i, j;
    int lens = strlen(str);
    int lenp = 23;
    i = 0;
    j = 0;
    int count = 0;
    while(i<lens && j<lenp)
    {
        if(str[i]==pat[j])
        {
            i++;
            j++;
        }
        else if(j==0)i++;
        else j = fail[j-1]+1;
        if(j==3)
        {
            j=0;
            i = i-2;
            ++count;
        }
    }
    return count;
}
int main()
{
    int T, SNO;
    cin>>T;
    while(T--)
    {
        cin>>SNO;
        scanf("%s",str);
        printf("%d %d %d %d %d ",SNO,KMP(str,"TTT"),KMP(str,"TTH"),KMP(str,"THT"),KMP(str,"THH"));
        printf("%d %d %d %d\n",KMP(str,"HTT"),KMP(str,"HTH"),KMP(str,"HHT"),KMP(str,"HHH"));
        //TTT, TTH, THT, THH, HTT, HTH, HHT and HHH
    }
    return 0;
}
