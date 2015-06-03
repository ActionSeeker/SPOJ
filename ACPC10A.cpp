#include<iostream>
using namespace std;
int main()
{
    int A, B, C;
    while(1)
    {
        cin>>A>>B>>C;
        if(A == 0 && B == 0 && C==0)break;
        else
        {
            if(B*B == A*C)
                cout<<"GP "<<C*(B/A);
            else if(2*B == A + C)
                cout<<"AP "<<C+(B-A);
            cout<<"\n";
        }
    }
    return 0;
}
