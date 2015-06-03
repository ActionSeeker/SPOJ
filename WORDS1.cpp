#include<iostream>
#include<stdio.h>
#include<cstring>
#define getchar_unlocked getchar
using namespace std;

#define INPUT "input"

string str;
int in[30];
int out[30];

string ip()
{
    string i="";
    int temp=getchar_unlocked();
    while(temp<'a'||temp>'z')
        temp=getchar_unlocked();
    while(temp>='a'&&temp<='z')
    {
        i+=(char)temp;
        temp=getchar_unlocked();
    }
    return i;
}

void setZero()
{
    for(int k = 0;k<27;k++)
    {
        in[k]=0;
        out[k]=0;
    }
}
int main()
{
    int T, N, i;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        int start = 0;
        int end = 0;
        setZero();
        while(N--)
        {
            str = ip();
            in[ str[0]-'a' ]++;
            int len = str.length();
            out[ str[len-1]-'a' ]++;
        }
        int smart=0;
        for(i = 0;i<26;i++)
        {
            //cout<<in[i]<<" "<<out[i]<<endl;
            if(in[i]==out[i]+1||out[i]==in[i]+1)
            {
                ++smart;
            }
            else if(in[i]!=out[i])
            {
                break;
            }
        }
        if(smart && i==26 )
            cout<<"Ordering is possible..\n";
            else cout<<"The door cannot be opened\n";
    }
    return 0;
}




