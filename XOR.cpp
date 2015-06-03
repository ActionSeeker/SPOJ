#include<iostream>
using namespace std;
int main()
{
     ios_base::sync_with_stdio(false);
     long int T, N, S = 0;
     cin>>T;
     while(T--)
     {
         cin>>N;
         S = S ^ N;
     }
     cout<<S;
     return 0;
}
