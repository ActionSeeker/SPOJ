#include<iostream>
using namespace std;
long long F, B, M, DIFF, D, COST;
int main()
{
    while(1)
    {
        cin>>D>>F>>B>>M;
        if(D==0 && F==0 && B==0 && M==0)break;
        else
        {
            COST = F*(F+1)/2 + 1;
            COST*= B;
            if(D - COST < M)//being cheated
            {
                DIFF = M - (D - COST);
                cout<<"The firm is trying to bankrupt Farmer Cream by "<<DIFF<<" Bsf.\n";
            }
            else cout<<"Farmer Cream will have "<<D - COST<<" Bsf to spend.\n";
        }
    }
    return 0;
}
