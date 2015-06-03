#include<iostream>
#include<bits/stdc++.h>
#define SIZE 30000
#define pp pair<int,int>
#define needsClose first
#define needsOpen second
using namespace std;
pp A[SIZE+1];
pp SegTree[4*SIZE];
char expr[30001];
void BuildSegTree(int left, int right, int vertex)
{
    if(left==right)
        {
            SegTree[vertex].needsClose = SegTree[vertex].needsOpen = (expr[left]=='('?1:-1);
        }
    else
    {
        int mid = left + (right-left)/2;
        BuildSegTree(left,mid,2*vertex);
        BuildSegTree(mid+1,right,2*vertex+1);
        SegTree[vertex].needsClose = SegTree[2*vertex].needsClose+SegTree[2*vertex+1].needsClose;
        SegTree[vertex].needsOpen = min(SegTree[2*vertex].needsOpen,SegTree[2*vertex].needsClose+SegTree[2*vertex+1].needsOpen);
    }
}
void UpdateSegTree(int vertex, int tl, int tr, int pos)
{
    if(tl==tr)
        SegTree[vertex] = pp(-1*SegTree[vertex].needsClose, -1*SegTree[vertex].needsOpen);
    else
    {
        int tm = (tl)+(tr-tl)/2;
        if(pos<=tm)
            UpdateSegTree(2*vertex, tl, tm, pos);
        else
            UpdateSegTree(2*vertex+1, tm+1, tr, pos);
        SegTree[vertex].needsClose = SegTree[2*vertex].needsClose+SegTree[2*vertex+1].needsClose;
        SegTree[vertex].needsOpen = min(SegTree[2*vertex].needsOpen,SegTree[2*vertex].needsClose+SegTree[2*vertex+1].needsOpen);
    }
}
void Print()
{
    for(int i = 1;i<8;i++)
        cout<<SegTree[i].first<<","<<SegTree[i].second<<" ";
}
int main()
{
    int len,NOK, K;
    int cs = 1;
    while(scanf("%d", &len) == 1) {
        scanf("%s",expr);
        BuildSegTree(0,len-1,1);
        printf("Test %d:\n", cs++);
        scanf("%d",&NOK);
        for(int t = 0;t<NOK;t++)
        {
            scanf("%d",&K);
            if(K==0)
            {
                if(SegTree[1].first==0 && SegTree[1].second==0)printf("YES\n");
                else printf("NO\n");
            }
            else
            {
                UpdateSegTree(1,0,len-1,K-1);
            }
        }
    }
    return 0;
}
