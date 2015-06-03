#include<iostream>
#include<string>
using namespace std;typedef int K;
K main(){string m[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};K D,N;cin>>N;while(N--){cin>>D;cout<<(D&31)<<" "<<m[((D&(15<<5))>>5)-1]<<" "<<((D&(16383<<9))>>9)<<"\n";}}
