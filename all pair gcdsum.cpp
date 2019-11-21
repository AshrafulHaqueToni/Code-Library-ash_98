#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define mx 100006

vector<int>v[mx];
int ans[mx];

void divisors()
{
    for(int i=1; i<mx; i++)
    {
        for(int j=i; j<mx; j+=i)
            v[j].push_back(i);
    }
}

int main()
{
    divisors();

    int n,re=0;

    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        int val;
        scanf("%d",&val);

        for(auto it: v[val])
            ans[it]++;//cout<<it<<" ";

            //cout<<endl;
    }


    for(int i=mx-1; i>=1; i--)
    {
        int cur=ans[i];

        cur=(cur*(cur-1))/2;

        for(int j=i+i; j<mx-1; j+=i)
            cur-=ans[j];

            ans[i]=cur;

        re+=i*cur;

        //cout<<i<<endl;

    }

    printf("%d\n",re);


    return 0;
}
