#include<iostream>
#include<stdio.h>
using namespace std;

    struct node
    {
    int segment_len,flip_cnt;
    } arr[500009];
    void update(int node,int low,int high,int i,int j)
    {
        if(low==i && high==j)
        {
            arr[node].flip_cnt++;
            arr[node].segment_len=high-low+1-arr[node].segment_len;
            return;
        }
        int left,mid,right;
        left=node<<1;
        right=left+1;
        mid=(low+high)/2;
        if(j<=mid)
        update(left,low,mid,i,j);
        else if(i>mid)
        update(right,mid+1,high,i,j);
        else
        {
            update(left,low,mid,i,mid);
            update(right,mid+1,high,mid+1,j);
        }
        arr[node].segment_len=arr[left].segment_len+arr[right].segment_len;
        if(arr[node].flip_cnt%2==1)
        arr[node].segment_len=high-low+1-arr[node].segment_len;
    }
    int query(int node,int low,int high,int i,int j,int flip)
    {
        if(low==i && high==j)
        {
            if(flip%2==0)
            return arr[node].segment_len;
            else if(flip%2==1)
            return high-low+1-arr[node].segment_len;
        }
        int left,right,mid;
        left=node<<1;
        right=left+1;
        mid=(low+high)/2;
        flip+=arr[node].flip_cnt;
        if(j<=mid)
        return query(left,low,mid,i,j,flip);
        else if(i>mid)
        return query(right,mid+1,high,i,j,flip);
        else
        return query(left,low,mid,i,mid,flip)+query(right,mid+1,high,mid+1,j,flip);
    }
    int main()
    {
    int n,k,i,j,a,l;
    cin>>n>>l;
    for(i=0;i<l;i++)
    {
    cin>>a>>j>>k;
    if(a==0)
    update(1,0,n-1,j,k);
    else
    {
    a=query(1,0,n-1,j,k,0);
    printf("%d\n",a);
    }
    }
    return 0;
    }
