#include<bits/stdc++.h>
using namespace std;
int n;

bool Cansplit(int a[],int value,int m)
{
    int cntsub=1;
    int val=0;

    for(int i=0;i<n;i++)
    {
        val+=a[i];

        if(val>value)
        {
            val=a[i];
            cntsub++;

            if(cntsub>m)return false;
        }
    }

    return true;
}

int main()
{
    int t;
    scanf("%d",&t);

    for(int ii=1;ii<=t;ii++)
    {
        int m;
        scanf("%d%d",&n,&m);

        int a[n];

        for(int i=0;i<n;i++)scanf("%d",a+i);

        int be=0,en=0;

        for(int i=0;i<n;i++)be=max(a[i],be),en+=a[i];

        if(n==m)
        {
            printf("Case %d: %d\n",ii,be);
            continue;
        }
        if(m==1)
        {
            printf("Case %d: %d\n",ii,en);
            continue;
        }

        while(be<en)
        {
            int mid=(be+en)/2;

            if(Cansplit(a,mid,m))
            {
                en=mid;
            }
            else be=mid+1;
        }

        printf("Case %d: %d\n",ii,be);
    }

    return 0;
}
