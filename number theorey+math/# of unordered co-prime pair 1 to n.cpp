int phi[mx];
ll suf[mx];

void eulor_totient(int n)
{
	phi[1]=1;
    for(int i=2; i<=n; i++) phi[i]=i;
    for(int i=2;i<=n;i+=2)
    {
        phi[i]>>=1;
    }
    for(int i=3; i<=n; i+=2) {
        if(phi[i]==i) {
            phi[i]--;
            for(int j=2*i; j<=n; j+=i)
                phi[j]-=(phi[j]/i);
        }
    }

    for(int i=1;i<=n;i++)suf[i]=suf[i-1]+phi[i]; // suf[i]= # of unordered coprime pair from 1 to i
}
