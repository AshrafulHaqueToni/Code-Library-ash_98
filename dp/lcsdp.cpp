#include<bits/stdc++.h>
using namespace std;

#define mx 1005

char ch1[mx],ch2[mx];
int dp[mx][mx],vis[mx][mx];
int nxt[mx][mx];

int len1,len2;

int func(int x,int y)
{
    if(x==len1||y==len2)return 0;

    if(vis[x][y])return dp[x][y];

    vis[x][y]=1;

    int re=0;

    if(ch1[x]==ch2[y]){
        re=1+func(x+1,y+1);
    }
    else
    {
        int p=func(x+1,y);
        int q=func(x,y+1);

        if(p>q)nxt[x][y]=1;
        else nxt[x][y]=2;

        re=max(p,q);
    }

    return dp[x][y]=re;

}

string ans="";

void printall(int x,int y)
{
    if(x==len1||y==len2)
    {
        cout<<ans<<endl;
        return;
    }

    if(ch1[x]==ch2[y])
    {
        ans+=ch1[x];

        printall(x+1,y+1);

        ans.erase(ans.end()-1);
    }

    else
    {
        if(dp[x+1][y]>dp[x][y+1])printall(x+1,y);
        else if(dp[x+1][y]<dp[x][y+1])printall(x,y+1);

        else{
            printall(x+1,y);
            printall(x,y+1);
        }
    }

}


int main()
{
    scanf("%s %s",ch1,ch2);
    len1=strlen(ch1);
    len2=strlen(ch2);

    printf("largest common subsequence :%d\n",func(0,0));


    int curx=0,cury=0;

    while(1)
    {
        if(curx==len1||cury==len2)break;

        printf("%d %d\n",curx,cury);

        if(ch1[curx]==ch2[cury])
        {
            printf("%c",ch1[curx]);
            curx++,cury++;
        }
        else
        {
            if(nxt[curx][cury]==1)curx++;
            else cury++;
        }
    }

    printf("\n");

    ///sob lcm gula print korte

     printall(0,0);

    return 0;
}
