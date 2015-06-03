#include<iostream>
#include<stdio.h>
using namespace std;
#define MAX 100000
int arr[MAX+1];
int inv[MAX+1];
int main()
{
    int N, key;
    while(1)
    {
        cin>>N;
        if(N==0)break;
        else
        {
            for(int i = 1;i<=N;i++)
            {
                cin>>arr[i];
                inv[arr[i]]=i;
            }
            bool namb = false;
            for(int i = 1;i<=N;i++)
            {
                if(arr[i]!=inv[i])
                {
                    namb = true;
                    break;
                }
            }
            if(namb==false)
            {
                printf("ambiguous\n");
            }
            else printf("not ambiguous\n");
        }
    }
    return 0;
}
