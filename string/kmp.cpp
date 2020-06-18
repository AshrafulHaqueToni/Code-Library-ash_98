#include<bits/stdc++.h>
using namespace std;

vector<int> build_lps(string s)
{
    vector<int>tem(s.size());
    int idx=0;
    int len=s.size();
    for(int i=1;i<len;)
    {
        if(s[i]==s[idx])
        {
            tem[i]=idx+1;
            idx++;
            i++;
        }
        else
        {
            if(idx!=0)idx=tem[idx-1];
            else tem[i]=idx,i++;
        }
    }
    return tem;
}

void kmp(string text,string pattern)
{
    bool f=false;
    int cnt=0;
    vector<int>lps=build_lps(pattern);
    int j=0,i=0,len1=text.size(),len2=pattern.size();
    while(i<len1)
    {
        if(text[i]==pattern[j])i++,j++;
        else
        {
            if(j!=0)j=lps[j-1];
            else i++;
        }
        if(j==len2)
        {
            f=true;
            cout<<"fount at: "<<(i-len2)<<endl;
            j=lps[j-1];
            cnt++;///koy bar ace sei tar jonno

        }
    }
    if(!f)cout<<"not found\n";
}

int main()
{
    string a,b;
    getline(cin,a);
    getline(cin,b);
    kmp(a,b);
}
