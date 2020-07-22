bitset<mx>chk;
vector<int>prime;
int mobius[mx];

void seive(int n)
{
    for(int i=3;i*i<=n;i+=2)
    {
        if(!chk[i])
        {
            for(int j=i*i;j<=n;j+=2*i)
            {
                chk[j]=true;
            }
        }
    }
    prime.push_back(2);
    for(int i=3;i<=n;i+=2)if(!chk[i])prime.push_back(i);

    for(int i=1;i<=n;i++)mobius[i]=1;
    int sz=prime.size();

    for(int i=0;i<sz && prime[i]*prime[i]<=n;i++)
    {
        int val=prime[i];
         val=val*val;
        for(int j=val;j<=n;j+=val)mobius[j]=0;

    }
    for(int i=0;i<sz;i++)
    {
        int val=prime[i];
        for(int j=val;j<=n;j+=val)mobius[j]*=-1;
    }

}
