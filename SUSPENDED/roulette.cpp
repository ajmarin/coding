#include <cstdio>
#include <cstring>

#define FOR(a,b) for(int a = 0; a < b; ++a)
#define FORI(a,b,c) for(int a = b; a < c; ++a)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)>(b)?(b):(a))
#define ABS(a)	 ((a)< 0?-(a):(a))

bool DBG = 0;
int b[150], r[300], map[600], B, R;
int dt, now, profit, SL;
int ns, ps, rn, rnm, rns, rp, rpm, rps;
char busy[300];

void bt(int i, int x){
	if(i == B){
		//if(DBG) printf("end: profit(%d) now(%d)\n",profit,now);
		profit = MAX(profit, now);
		return;
	}
	if((now + ns * rpm + ps * rnm) < profit) return;
	int ls = x + SL - ((B - i - 1)<<1) - 1, loss = 0;
	//if(DBG) printf("Ball(%d, %d) can go in range [%d, %d] (%d,%d)\n",i,b[i],map[x], map[ls],r[map[x-1]],r[map[ls]]);
	int neg = (b[i] < 0)*b[i], pos = (b[i] > 0)*b[i];
	FORI(j, x, ls){
		if(busy[map[j]]){  continue;}
		int k = map[j], v = r[k] * b[i], p = map[k-1+R], n = map[k+1];
		++busy[p];
		++busy[n];
		++busy[k];
		SL -= loss;
		ns += neg;
		ps -= pos;
		now -= v;
		//if(DBG) printf("%d - B(%3d), r(%3d), now(%3d)\n",i,b[i],r[k],now);
		bt(i+1, k+2);
		now += v;
		ps += pos;
		ns -= neg;
		SL += loss;
		--busy[k];
		--busy[n];
		--busy[p];
		loss++;
	}
}
int main(void){
	int cnum = 1;
	while(scanf("%d %d",&R,&B) && R){
		//DBG = (cnum == 43); cnum++;
		//if(DBG && R > 50) return 0;
		SL = R-2;
		memset(busy, 0, R);
		ns = ps = rn = rns = rp = rps = 0;
		FOR(i, R) scanf("%d",&r[i]);
		FOR(i, R<<1) map[i] = i%R;
		FOR(i, B){
			scanf("%d",&b[i]);
			if(b[i] < 0) ns -= b[i];
			else ps += b[i];
		}
		int s = r[0];
		profit = 1<<31;
		FOR(i, R){
			if(i != (R-1)) r[i] += r[i+1];
			else r[i] += s;
			if(r[i] < 0) ++rn, rns -= r[i];
			else if(r[i] > 0) ++rp, rps += r[i];
		}
		rnm = (rn ? (rns + rn - 1)/rn : 0);
		rpm = (rp ? (rps + rp - 1)/rp : 0);
		ns += b[0]*(b[0] < 0);
		ps -= b[0]*(b[0] > 0);
		FOR(i, R){
			int p = map[i-1+R], n = map[i+1];
			++busy[p]; ++busy[i]; ++busy[n];
			now =  - (r[i] * b[0]);
			//if(DBG)printf("\tBall(%d, %d) at (%d), now (%d)\n",0,b[0],r[i],now);
			bt(1, i+2);
			--busy[p]; --busy[i]; --busy[n];
		}

		printf("%d\n",profit);
	}
	return 0;
}

