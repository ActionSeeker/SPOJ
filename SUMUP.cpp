#include<iostream>
#include<cstdio>
using namespace std;typedef long long LLI;float arr[10001],k;int main(){LLI N,T,C;arr[1]=1.0/3.0;for(LLI i=2;i<=10000;i++){k=i*1.0;arr[i]=arr[i-1]+k/((i*i+1)*(i*i+1)-(i*i)*1.0);}cin>>T;while(T--){cin>>N;printf("%.5f\n",arr[N]);}return 0;}
