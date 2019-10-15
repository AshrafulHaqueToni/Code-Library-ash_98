#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mx 100000001

int prime[(mx/32)+2];

//vector<int>v;

int chk(int pos,int i)
{
    return (bool)(pos & (1<<i));
}

int on(int pos,int i)
{
    return pos=(pos | (1<<i));
}

void func()
{
    for(int i=3;i*i<=mx;i+=2)
    {
        if(!chk(prime[i>>5] , i&31 ))

            for(int j=i*i;j<=mx;j+=2*i)

                prime[j>>5]=on(prime[j>>5],j&31);
    }

    //v.push_back(2);
    printf("2\n");

    for(int i=3;i<=mx;i+=2)
        if(!chk(prime[i>>5],i&31))//v.push_back(i);
            printf("%d\n",i);
}

int main()
{
    func();


    //for(auto it: v)
       // printf("%d\n",it);

   // cout<<v.size()<<endl;


    return 0;
}

