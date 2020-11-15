// Created by ash_98

#include<bits/stdc++.h>
using namespace std;

#define mx 100005
#define ll long long
#define mod 1000000007

int ar[mx];
char ch[mx],ch1[mx];
int n,m,ii,k;

vector<int> Prefix_function()
{
	vector<int>pi(m);
	for(int i=1;i<m;i++)
	{
       int j=pi[i-1];
       while(j>0 && ch1[i]!=ch1[j])j=pi[j-1];
       if(ch1[j]==ch1[i])j++;
       pi[i]=j;
	}
	return pi;
}

void solve()
{
	
	scanf("%s%s",ch,ch1);
	n=strlen(ch);
	m=strlen(ch1);
	vector<int> pi=Prefix_function();
	for(int i=0;i<m;i++)printf("%d\n",pi[i] );

}

int main()
{
	int t=1;
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}
