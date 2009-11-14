#include <cstdio>
#include <cmath>
 
#define EPS 1E-9
 
int x, y, z;
int p, m, g;
int qp, qm, qg;
bool impossivel;
 
void preenchelado(int x, int y) {
	int y0 = y;
	 
	while(x >= 30) {
		while(y >= 30) {
			y -= 30;
			qg++;
		}
		while(y >= 15) {
			y -= 15;
			qm += 2;
		}
		while(y >= 5) {
			y -= 5;
			qp += 6;
		}
		x -= 30;
		if(y > 0) impossivel = true;
		y = y0;
	}
	 
	while(x >= 15) {
		while(y >= 15) {
			y -= 15;
			qm++;
		}
		while(y >= 5) {
			y -= 5;
			qp += 3;
		}
		x -= 15;
		if(y > 0) impossivel = true;
		y = y0;
	}
	 
	while(x >= 5) {
		while(y >= 5) {
			y -= 5;
			qp++;
		}
		x -= 5;
		if(y > 0) impossivel = true;
		y = y0;
	}
}
 
int main(void) {
	double dx, dy, dz;
	 
	while(scanf("%lf %lf %lf", &dx, &dy, &dz)) {
		if(dx < EPS && dy < EPS && dz < EPS) break;
		 
		/* init */
		qp = qm = qg = 0;
		impossivel = false;
		 
		/* input */
		x = (int)floor(dx*100), y = (int)floor(dy*100), z = (int)floor(dz*100);
		scanf("%d %d %d", &p, &m, &g);
		 
		/* processa */
		preenchelado(x, z), preenchelado(x, z);
		preenchelado(y, z), preenchelado(y, z);
		preenchelado(x, y);
		 
		while(qg > g) qm += 4, qg--;
		while(qm > m) qp += 9, qm--;
		if(qp > p) impossivel = true;
		 
		/* output */
		if(impossivel) printf("impossivel\n");
		else printf("%d %d %d\n", qp, qm, qg);
	}
	 
	return 0;
}

