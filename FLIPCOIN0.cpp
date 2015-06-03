#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
int SegTree[4*MAX+1];
int LazyUp[4*MAX+1];
int A[MAX+1];
void Update(int v, int a, int b, int L, int R)
{
    if(LazyUp[v]==1)
    {
        SegTree[v] = R-L+1-SegTree[v];
        if(L!=R)
        {
            LazyUp[2*v] = 1-LazyUp[2*v];
            LazyUp[2*v+1] = 1-LazyUp[2*v+1];
        }
        LazyUp[v]=0;
    }
    if(a>R||b<L)return;
    if(L>=a && b>=R)
    {
        SegTree[v] = R-L+1-SegTree[v];
        if(L!=R)
        {
            LazyUp[2*v] = 1-LazyUp[2*v];
            LazyUp[2*v+1] = 1-LazyUp[2*v+1];
        }
        return;
    }
    Update(2*v,a,b,L,(L+R)/2);
    Update(2*v+1,a,b,(L+R)/2+1,R);
    SegTree[v] = SegTree[2*v]+SegTree[2*v+1];
}
int Query(int v, int a, int b, int L, int R)
{
    if(a>R||b<L)return 0;
    if(LazyUp[v]==1)
    {
        SegTree[v] = R-L+1-SegTree[v];
        if(L!=R)
        {
            LazyUp[2*v] = 1-LazyUp[2*v];
            LazyUp[2*v+1] = 1-LazyUp[2*v+1];
        }
        LazyUp[v]=0;
    }
    if(a<=L && b>=R)return SegTree[v];
    return Query(2*v,a,b,L,(L+R)/2)+Query(2*v+1,a,b,(L+R)/2+1,R);
}
int main()
{
    int N,C;
    int opcode,QL,QR;
    cin>>N>>C;
    while(C--)
    {
        cin>>opcode>>QL>>QR;
        if(opcode==0)Update(1,QL,QR,0,N-1);
        else cout<<Query(1,QL,QR,0,N-1)<<"\n";
    }
    return 0;
}
