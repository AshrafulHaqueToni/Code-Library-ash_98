#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>>Set;
    int n;
    scanf("%d",&n);
    for(int i=0;i<(1<<n);i++)
    {
        vector<int>subset;

        for(int j=0;j<n;j++)
        {
            if(i & (1<<j))subset.push_back(j);
        }
        Set.push_back(subset);
    }
    for(auto it:Set)
    {
        for(auto it1:it)printf("%d ",it1);
        printf("\n");
    }

    return 0;
}
