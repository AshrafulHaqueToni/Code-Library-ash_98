#include<bits/stdc++.h>
using namespace std;

int Extended_Euclidean(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    int d=Extended_Euclidean(b,a%b,y,x);
    y=y-(a/b)*x;
    return d;
}

int main()
{
  int a,b,x,y;
  x=0,y=1; /// you can assign any value of x,y .you can find infinite solution for x and y
  scanf("%d%d",&a,&b);
  int gcd=Extended_Euclidean(a,b,x,y);
  printf("%d\n",gcd);
  printf("%d %d\n",x,y);
}
