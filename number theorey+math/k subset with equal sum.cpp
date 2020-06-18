#include<bits/stdc++.h>
using namespace std;
int ar[105];
int part[50];
int n,k=3; ///here partition is three
int target;

bool backtrack(int cur)
{
    if(cur==n)
    {
        for(int i=0;i<k;i++)
        {
            if(part[i]!=target)return false;
        }
        return true;
    }
    for(int i=0;i<k;i++)
    {
        if(part[i]+ar[cur]>target)continue;
        part[i]+=ar[cur];
        if(backtrack(cur+1))return true;
        part[i]-=ar[cur];
        if(part[i]==0)return false;
    }
    return false;
}

int main()
{
    scanf("%d",&n);
    int sum=0;
    for(int i=0;i<n;i++){
        scanf("%d",&ar[i]);
        sum+=ar[i];
    }
    if(sum%k!=0)
    {
        printf("0\n");
        return 0;
    }
    target=sum/k;
    bool f=backtrack(0);
    if(f)
    {
        printf("1\n");
    }
    else printf("0\n");

    return 0;
}
