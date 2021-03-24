// Created by ash_98

#include<bits/stdc++.h>
using namespace std;

#define mx 100005
#define ll long long
#define mod 1000000007

int ar[mx];
char ch[mx],ch1[mx];
int n,m,ii,k;

vector<int> Create_Pi_Table(const char* s)
{
	int sz=strlen(s);
	vector<int>pi(sz);
	for(int i=1;i<sz;i++)
	{
	       int j=pi[i-1];
	       while(j>0 && s[i]!=s[j])j=pi[j-1];
	       if(s[j]==s[i])j++;
	       pi[i]=j;
	}
	return pi;
}

void solve()
{
	
	scanf("%s%s",ch,ch1);
	n=strlen(ch);
	m=strlen(ch1);
	vector<int> pi=Create_Pi_Table(ch1);
	for(int i=0;i<m;i++)printf("%d\n",pi[i] );

}

int main()
{
	int t=1;
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}
