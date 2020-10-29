#include<bits/stdc++.h>
using namespace std;
 
#define mx 1000005

void IO()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
}
 
char ch[mx];
int q,n;
 
struct me
{
    int open,close,ans;
}Tree[4*mx],dummy;


me Merge(me a, me b)
{
    me re;
    int valid=min(a.open,b.close);
    re.open=a.open+b.open-valid;
    re.close=a.close+b.close-valid;
    re.ans=a.ans+b.ans+valid;     /// this code works for maximum length of correct bracket sequence in l to r range
    /* if you want to see is it valid bracet squence length just change 
    re.ans=re.open+re.close;
    In query if re.ans gives 0 thats main the range is correct bracket sequence
    */
    return re;
}

 
void build(int node,int be,int en)
{
    if(be==en)
    {
        if(ch[be-1]=='(')Tree[node].open=1;
        else Tree[node].close=1;
        return;
    }
    int mid=(be+en)/2;
    build(node*2,be,mid);
    build(node*2+1,mid+1,en);
    Tree[node]=Merge(Tree[node*2],Tree[node*2+1]);
   
}

void update(int node,int be,int en,int pos)
{
    if(pos>en || pos<be)return;
    if(be==en)
    {
        if(ch[be-1]=='(')
        {
            Tree[node].open=0;
            Tree[node].close=1;
            ch[be-1]=')';
        }
        else
        {
            Tree[node].open=1;
            Tree[node].close=0;
            ch[be-1]='(';
        }
        return;
    }

    int mid=(be+en)/2;
    update(node*2,be,mid,pos);
    update(node*2+1,mid+1,en,pos);
    Tree[node]=Merge(Tree[node*2],Tree[node*2+1]);
}
 
me query(int node,int be,int en,int x,int y)
{
    if(be>y || en<x)return dummy;
    if(be>=x && en<=y)
    {
       return Tree[node];
    }
    int mid=(be+en)/2;
    return Merge(query(node*2,be,mid,x,y),query(node*2+1,mid+1,en,x,y));
}
 
int main()
{
    IO();
    scanf("%s%d",ch,&q);
    n=strlen(ch);
    build(1,1,n);
    while(q--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",query(1,1,n,x,y).ans*2);
    }
 
    return 0;
}
