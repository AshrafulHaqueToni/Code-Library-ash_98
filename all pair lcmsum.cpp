#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mx 100005

vector<int>v[mx];
ll ans[mx];
ll sumsq[mx],sqsum[mx];

void divisors()
{
    for(int i=1;i<mx;i++)
    {
        for(int j=i;j<mx;j+=i)v[j].push_back(i);
    }
}

///(a*b)/x+(b*c)/x+(c*a)/x=  (ab+bc+ca)/x
///(a+b+c)^2=a*a+b*b+c*c+2(ab+bc+ca)
///(ab+bc+ca)=((a+b+c)^2-(aa+bb+cc))/2


int main()
{
    divisors();

    int n;
    scanf("%d",&n);
    ll re=0;

    for(int i=0;i<n;i++)
    {
        int val;
        scanf("%d",&val);
        for(auto it:v[val])
        {
            sumsq[it]+=val;
            sqsum[it]+=val*val;
        }
    }

    for(int i=mx-1;i>=1;i--)
    {
       ll cur=sumsq[i]*sumsq[i];
       cur-=sqsum[i];
       cur/=2;

       for(int j=i+i;j<mx;j+=i)cur-=ans[j];

       ans[i]=cur;

       re+=cur/i;
    }

    printf("%lld\n",re);


    return 0;
}
