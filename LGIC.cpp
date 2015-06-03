#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ULLI;
ULLI U, ans;
ULLI power(ULLI exp)
{
    ULLI A = 1;
    ULLI base = 2;
    while(exp)
    {
        if(exp%2)A = A*base;
        base = base*base;
        exp/=2;
    }
    return A;
}
ULLI factorial(ULLI num)
{
    ULLI fact = 1;
    for(int i = 1;i<=num;i++)
    {
        fact*=i;
    }
    return fact;
}
int main()
{
    cin>>U;
    ans = power(U)+ factorial(U) - U;
    cout<<ans;
    return 0;
}
