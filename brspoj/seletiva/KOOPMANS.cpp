#include<cstdio>
#include<algorithm>
unsigned long long cand, LINF, LSUP, sum, v[10000];
int i, j, N, nums, sub, t;
bool debug = 0;
void bt(int prof, int start, long long cval){
	if(cval > LSUP) return;
	if(prof) {
		unsigned long long first, last, how_many, pavalue;
		if(LINF%cval) first = ((LINF/cval)+1)*cval;
		else first = LINF;
		if(LSUP%cval) last = (LSUP/cval)*cval;
		else last = LSUP;
		how_many = (last - first)/cval + 1;
		pavalue = (((first+last)*how_many)>>1);
		if(prof&1) sum += pavalue;
		else sum -= pavalue;
		if(prof == nums) return;
		for(int i = start; i < nums; i++)
			bt( prof+1, i+1, cval*v[i]);
	}
	else
		for(int i = start; i < nums; i++)
			bt( prof+1, i+1, cval+v[i]);
}
int main(void){
	scanf("%d",&t);
	while(t--){
		sum = 0;
		scanf("%lld %lld %d",&LINF,&LSUP,&N);
		for(sub = nums = i = 0; i < N; i++){
			scanf("%lld",&cand);
			if(cand > LSUP || 
			((LINF/cand)*cand < LINF && ((LINF/cand)+1)*cand  > LSUP))
				continue;
			v[nums++] = cand;
		}
		std::sort(v,v+nums);
		for(i = 1; i < nums; i++)
			for(j = 0; j < i; j++)
				if(v[i]%v[j] == 0){
					v[i] = 1000000001;
					sub++;
					break;
				}
		std::sort(v,v+nums);
		nums -= sub;
		bt(0,0,0);
		printf("%lld\n",sum%1300031);
	}
}
