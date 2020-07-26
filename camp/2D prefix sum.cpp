#include<bits/stdc++.h>
using namespace std;
#define mx 1005

int ar[mx][mx];
int prefix[mx][mx];

int n,m;

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
                 scanf("%d",&ar[i][j]);

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
                prefix[i][j]=prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]+ar[i][j];

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            printf("%d ",prefix[i][j]);
        }
        printf("\n");
    }

    ///for query
    while(1)
    {
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        int re=prefix[x2][y2]-prefix[x1-1][y2]-prefix[x2][y1-1]+prefix[x1-1][y1-1];
        printf("%d\n",re);
    }

    return 0;
}

