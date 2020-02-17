#include<bits/stdc++.h>
using namespace std;
#define mx 100005
#define block 555
 
struct me
{
    int left,right,result;
 
}tree[4*mx];
 
int a[mx],cnt[4*mx],ans[mx],fi=0;
 
bool comp(me p1,me p2)
{
    if(p1.left / block != p2.left / block)
 
        return p1.left / block < p2.left /block;
 
 
    return p1.right<p2.right;
}
 
 
void Add(int pos)
{
    int x=a[pos];
 
    if(cnt[x]==x)fi--;
    cnt[x]++;
    if(cnt[x]==x)fi++;
    //cout<<fi<<endl;
}
 
void Remove(int pos)
{
   int x=a[pos];
 
    if(cnt[x]==x)fi--;
    cnt[x]--;
    if(cnt[x]==x)fi++;
}
 
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
 
    for(int i=0;i<n;i++)
    {
        scanf("%d",a+i);
        if(a[i]>n)a[i]=n+1;
    }
 
 
    for(int i=0;i<q;i++)
    {
        scanf("%d %d",&tree[i].left,&tree[i].right);
 
        tree[i].right--,tree[i].left--;
        tree[i].result=i;
    }
 
    sort(tree,tree+q,comp);
 
//    for(int i=0;i<4*n;i++)
//    {
//        cout<<tree[i].left<<" "<<tree[i].right<<" "<<tree[i].result<<endl;
//    }
 
    int curentL=0,curentR=-1;
 
    for(int i=0;i<q;i++)
    {
        int l=tree[i].left,r=tree[i].right;
 
        while(curentR<r)
           Add(++curentR);
 
 
        while(curentR>r)
           Remove(curentR--);
 
 
        while(curentL<l)
           Remove(curentL++);
 
 
        while(curentL>l)
           Add(--curentL);
 
 
        ans[tree[i].result]=fi;
    }
 
    for(int i=0;i<q;i++)printf("%d\n",ans[i]);
 
    return 0;
}
