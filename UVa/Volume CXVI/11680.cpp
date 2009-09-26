#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define NN 300
#define EPS 1E-6
int h, t, N;
int deg[NN], dep[NN], points[NN][NN], q[NN], v[NN];
double cp[NN][NN], m1[NN], m2[NN], p[NN][NN];

struct corrida {
	int a, b, ind;
	bool operator<(const corrida x) const {return a < x.a;}
}c[NN];

void DOIT(double A[], double B[], int k){
	double r;
	int i, j;
	for(i = 0; i < N; i++){
		r = 0.;
		if(A[i] > EPS){
			for(j = 0; j < N; j++) if(B[j] > EPS) r += B[j]*p[i][j];
			cp[k][i] = r*A[i];			
		} else if(B[i] > EPS){
			for(j = 0; j < N; j++) if(A[j] > EPS) r += A[j]*p[i][j];
			cp[k][i] = r*B[i];
		} else cp[k][i] = 0.;
	}
}

void doRace(int x){
	if(c[x].a < N){
		m1[c[x].a] = 1.;
		if(c[x].b < N){
			m2[c[x].b] = 1.;
			DOIT(m1, m2, c[x].ind);
			m2[c[x].b] = 0.;
		}
		m1[c[x].a] = 0.;
	} else if(c[x].b < N){
		m2[c[x].b] = 1.;
		DOIT(cp[c[x].a-N], m2, c[x].ind);
		m2[c[x].b] = 0.;
	} else DOIT(cp[c[x].a-N], cp[c[x].b-N], c[x].ind);
}

void TOPOSOLVE(){
	int k;
	while(h != t){
		k = q[h++];
		doRace(k);
		for(int i = 0; i < deg[k]; i++)
			if(--dep[points[k][i]] == 0) q[t++] = points[k][i];
	}
	printf("%.6lf\n",cp[c[k].ind][0]);
}
int main(void){
	int a, b, i, j;
	for(i = 0; i < NN; i++) m1[i] = m2[i] = 0.;
	while(scanf("%d",&N) && N){
		for(h = i = t = 0; i < N; i++){
			deg[i] = dep[i] = 0;
			for(j = 0; j < N; j++)
				scanf("%lf",&p[i][j]);
		}
		j = N-1;
		for(i = 0; i < j; i++){
			scanf("%d%d",&a,&b);
			if(b > a) swap(a, b);
			c[i].a = --a;
			c[i].b = --b;
			c[i].ind = i;
			if(a >= N){
				int k = a-N;
				points[k][deg[k]++] = i;
				dep[i]++;
			}
			if(b >= N){
				int k = b-N;
				points[k][deg[k]++] = i;
				dep[i]++;
			}
			if(dep[i] == 0) q[t++] = i;
		}
		TOPOSOLVE();
	}
	return 0;
}

