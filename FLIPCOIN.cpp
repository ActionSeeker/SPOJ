#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
int A[MAX+1];
int SegTree[4*MAX+1];
int LazyUp[4*MAX+1];
void Update(int v, int a, int b, int L , int R)
{
    if(a>=R || b<=L)return;
    else if(a<=L && b>=R)
    {
        LazyUp[v]++;
        SegTree[v] = R-L+1-SegTree[v];
        LazyUp[v]%=2;
        return;
    }
    Update(v<<1,a,b,L,(L+R)>>1);
    Update((v<<1)+1,a,b,((L+R)>>1)+1,R);
    SegTree[v] = (SegTree[2*v]+SegTree[2*v+1]);//suppose
}
int Query(int v, int a, int b, int L, int R, int count)
{
    if(a>=R || b<=L)return 0;
    else if(a<=L && b>=R)
    {
        if(LazyUp[v]%2)return R-L+1-SegTree[v];
        else return SegTree[v];
    }
    if(a>=L && b<=R)
        return Query(2*v,a,b,L,(L+R)/2,count+LazyUp[v])+Query(2*v+1,a,b,(L+R)/2+1,R,count+LazyUp[v]);
    else if(b>=R)
        return Query(2*v,a,R,L,(L+R)/2,count)+Query(2*v+1,a,R,(L+R)/2+1,R,count+LazyUp[v]);
    else if(a<=L)return Query(2*v,L,b,L,(L+R)/2,count+LazyUp[v])+Query(2*v+1,L,b,(L+R)/2+1,R,count);
}
int main()
{
    int N,C;
    int opcode, QL, QR;
    cin>>N>>C;
    while(C--)
    {
        cin>>opcode;
        if(opcode==0)
        {
            cin>>QL>>QR;
            Update(1,QL,QR,0,N-1);
        }
        else
        {
            cin>>QL>>QR;
            cout<<Query(1,QL,QR,0,N-1,0)<<"\n";
        }
    }
    return 0;
}
