#include <cstdio>

int N, q[100], rem;
int head, tail;

struct rect {
	int xL, xR, yB, yT;
	bool r;
	rect(){}
	rect(int _a, int _b, int _c, int _d):
		xL(_a), xR(_b), yB(_c), yT(_d) {}
	bool operator==(const rect k) const {
		return (k.xL == xL && k.xR == xR && k.yB == yB && k.yT == yT);
	}
} r[100];

bool check(int k){
	rem++;
	for(int i = 0; i < N; ++i){
		if(r[i].r || r[i].yB < r[k].yT || r[i].xR <= r[k].xL || r[i].xL >= r[k].xR) continue;
		r[i].r = 1;
		q[tail++] = i;
	}
}

int main(void){
	rect rec;
	int t, xL, xR, yB, yT;
	while(scanf("%d", &N) && N){
		rem = 0;
		for(int i = 0; i < N; ++i){
			scanf("%d %d %d %d", &xL, &yB, &xR, &yT);
			if(xL > xR) t = xL, xL = xR, xR = t;
			if(yB > yT) t = yB, yB = yT, yT = t;
			r[i] = rect(xL, xR, yB, yT);
			r[i].r = 0;
		}
		scanf("%d %d %d %d", &xL, &yB, &xR, &yT);
		if(xL > xR) t = xL, xL = xR, xR = t;
		if(yB > yT) t = yB, yB = yT, yT = t;
		rec = rect(xL, xR, yB, yT);
		int k;
		head = tail = 0;
		for(k = 0; !(r[k] == rec); ++k);
		q[tail++] = k;
		r[k].r = 1;

		while(head != tail){
			int x = q[head++];
			check(x);
		}
		printf("%d\n", rem - 1);

	}
	return 0;
}

