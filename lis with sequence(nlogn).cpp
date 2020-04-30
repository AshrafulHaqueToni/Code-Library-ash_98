#include<bits/stdc++.h>
using namespace std;

#define mx 100005
int n;
int ar[mx];
vector<int>tailindices(mx,0),preindices(mx,-1);


int GetceilIndex(int l,int r,int key )
{
    while(r-l>1)
    {
        int m=l+(r-l)/2;
        if(ar[tailindices[m]]>=key)
            r=m;
        else
            l=m;

           // cout<<l<<" "<<r<<endl;
    }
    return r;
}

int LIS()
{
    int len=1;

    for(int i=1; i<n; i++)
    {
        if(ar[i]<ar[tailindices[0]])
            tailindices[0]=i;

        else if(ar[i]>ar[tailindices[len-1]])
        {
            preindices[i]=tailindices[len-1];
            tailindices[len++]=i;
        }
        else
        {
            int pos=GetceilIndex(-1,len-1,ar[i]);
            //cout<<pos<<endl;
            preindices[i]=tailindices[pos-1];
            tailindices[pos]=i;
        }
    }

    printf("the LIS sequence: \n");
    vector<int>ans;
    for(int i=tailindices[len-1]; i>=0; i=preindices[i])
        ans.push_back(ar[i]);
    reverse(ans.begin(),ans.end());
    for(auto it:ans)printf("%d ",it);

    printf("\n");

    return len;
}


int main()
{
    //int n;
    scanf("%d",&n);

    //int ar[n];

    for(int i=0; i<n; i++)
        scanf("%d",ar+i);

    printf("LIS size : %d\n",LIS());

    return 0;
}
