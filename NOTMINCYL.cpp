#include<stdio.h>
#include<math.h>
#include<iostream>
#define PI 3.1415926535897
#define Max(x,y) x>y?x:y
#define Min(x,y) x<y?x:y
#define get getchar_unlocked
using namespace std;
int main()
{
    int T,w,h;
    double W,H,Temp,Radius,Height,r,Volume;
    cin>>T;
    while(T--)
    {
        Volume=0;
        int newW1,newW2;
        cin>>w>>h;
        W = (double)w; H = (double)h;
        Height = W;
        Radius = Min( H/3.0 , W/(PI*2.0) );
        Height = H - 2*Radius ;
        Volume = Max( Volume , PI*Radius*Radius*Height );
        if(H>=W*(PI+2))  {  newW1 = 1;  Radius=W/2.0;  }
        else if(H<=W*(PI+1)/2.0) {  newW1 = 2;  Radius=H/(PI+1)/2.0; }
        else
        {
            newW1 = 3;
            Radius = H*(PI+1);
            Radius += W;
            r = ((2*H*W*(PI+1)) - (W*W*PI*(PI+2)));
            if(r>=0)  {  r = sqrt(r);  Radius -= r; Radius /= (2*(PI+1)*(PI+1));  }
            else Radius = 0;
            if(W> 4*Radius || W< 2*Radius)  Radius = 0;
        }
        Volume = Max( Volume , PI*Radius*Radius*W );
        Temp = W;
        W = H;
        H = Temp;
        Radius = Min( H/3.0 , W/(PI*2.0) );
        Height = H - 2*Radius ;
        Volume = Max( Volume , PI*Radius*Radius*Height );
        Height=W;
        if(H>=W*(PI+2)) { newW2 = 9; Radius=W/2.0; }
        else if(H<=W*(PI+1)/2.0) { newW2 = 10; Radius=H/((PI+1)*2.0); }
        else
        {
            newW2 = 11;
            Radius = H*(PI+1);
            Radius += W;
            r = ((2*H*W*(PI+1)) - (W*W*PI*(PI+2)));
            if(r>=0)  {  r = sqrt(r);  Radius -= r;  Radius /= (2*(PI+1)*(PI+1)); }
            else Radius = 0;
            if(W> 4*Radius || W< 2*Radius)  Radius = 0;
        }
        if(Volume < PI*Radius*Radius*Height)  newW1 = newW2;
        Volume = Max( Volume , PI*Radius*Radius*Height );
      printf("%.11e\n",Volume);
    }
  return 0;
}
