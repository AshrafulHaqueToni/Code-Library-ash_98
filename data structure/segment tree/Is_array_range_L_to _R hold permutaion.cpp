https://www.codechef.com/problems/QRYLAND
struct info
{
	ll pre_sum;
	ll xor_sum;
	int id1,id2;
};
info pre[mx];
void func()
{
	for(int i=1;i<=mx-5;i++)
	{
		pre[i].pre_sum=pre[i-1].pre_sum+i;
		pre[i].xor_sum=pre[i-1].xor_sum^i;
		pre[i].id1=1;
		pre[i].id2=i;

	}
}

info Merge(info a,info b)
	{
		info c;
		c.pre_sum=a.pre_sum+b.pre_sum;
		c.xor_sum=a.xor_sum^b.xor_sum;
		c.id1=min(a.id1,b.id1);
		c.id2=max(a.id2,b.id2);
		return c;
	}

if pre[r-l+1] equals to info of L TO R of array then they holds permutations.
