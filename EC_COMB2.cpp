#include<iostream>
using namespace std;

unsigned int retRev(unsigned int b) {
  b = ((b * 0x80200802ULL) & 0x0884422110ULL) * 0x0101010101ULL >> 32;
  return (unsigned int)b;
}

int main()
{
    unsigned int T, A;
    cin>>T;
    while(T--)
    {
        cin>>A;
        if(A%2==0)cout<<retRev(A)<<"\n";
        else cout<<A<<"\n";
    }
    return 0;
}
