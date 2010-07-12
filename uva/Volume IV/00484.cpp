/////////////////////////////////
// 00484 - The Department of Redundancy Department
/////////////////////////////////
#include<cstdio>
#include<cstring>
int idx[140000];
int b,i,n,nc;
struct numocc
{
	int num;
	int occ;
}data[10000];
void check()
{
	if(idx[n+66000]) return;
	idx[n+66000] = nc;
	data[nc].num = n;
	nc++;
}
int main(void)
{
	memset(idx,0,sizeof(idx));
	nc=1;
	while(scanf("%d",&n)!=EOF)
	{
		check();
		data[idx[n+66000]].occ++;
	}
	for(i=1;i<nc;i++)
		printf("%d %d\n",data[i].num,data[i].occ);
	return 0;
}
