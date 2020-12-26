struct me
{
    int ans,sum;
    int max_pref,max_suf;
 
    void Merge(me p1,me p2)
    {
 
        sum=p1.sum+p2.sum;
 
        max_pref=max(p1.max_pref,p1.sum+p2.max_pref);
        max_suf=max(p2.max_suf,p2.sum+p1.max_suf);
 
        ans=max(max(p1.ans,p2.ans),p1.max_suf+p2.max_pref);
    }
 
    me()
    {
        ans=max_pref=max_suf=sum=0;
    }
 
    me(int val)
    {
        ans=max_pref=max_suf=sum=val;
    }
 
} 
