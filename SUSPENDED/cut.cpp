#include <cstdio>
#include <algorithm>

#define NN 4000

using namespace std;

struct LS_V { 
	int b, n, s, t;	bool m;
	LS_V(int a, int b, int c, bool d, int e): 
		b(a),t(b),n(c),m(d),s(e){}
	LS_V(){}
	bool operator<(const LS_V comp) const { 
		return ((t < comp.t)||(t==comp.t && s < comp.s)); 
	}
	bool operator()(LS_V a, LS_V b) {
		return ((a.b < b.b)||(a.b==b.b && a.s < b.s));
	}
} vord[NN], vert[NN];

struct LS_H {
	int l, n, r, s;	bool  m;
	LS_H(int a, int b, int c, bool d, int e):
		l(a),r(b),n(c),m(d),s(e){}
	LS_H(){}
	bool operator<(const LS_H comp) const {
		return ((r < comp.r)||(r==comp.r && s < comp.s));
	}
	bool operator()(LS_H a, LS_H b) {
		return ((a.l < b.l)||(a.l==b.l && a.s < b.s));
	}
} hord[NN], hznt[NN];

struct cut {
	int x1, x2, y1, y2;
	cut(int a, int b, int c, int d):
		x1(a),y1(b),x2(c),y2(d){}
	cut(){}
} cuts[NN];
int b[NN], l[NN], r[NN], t[NN];
int VSEG, HSEG;
void segment(int begin, int end, bool vertical, int l){
	if(vertical){
		vord[VSEG] = LS_V(begin,end,VSEG,0,l);
		vert[VSEG] = LS_V(begin,end,VSEG,0,l);
		VSEG++;
	} else{
		hord[HSEG] = LS_H(begin,end,HSEG,0,l);
		hznt[HSEG] = LS_H(begin,end,HSEG,0,l);
		HSEG++;
	}	
}

int main(void){
	int BOT, LEF, RIG, TOP;
	int i, n;
	while(scanf("%d",&n) && n){
		/* reinicia variaveis */
		BOT = LEF = 10000;
		TOP = RIG = -10000;
		VSEG = HSEG = 0;
		/* le entrada + define limites do retangulo */
		for(i = 0;  i < n; i++){
			scanf("%d%d%d%d",&l[i],&b[i],&r[i],&t[i]);
			if(l[i] <= LEF){
				LEF = l[i];
				if(b[i] < BOT) BOT = b[i];
			}
			if(r[i] >= RIG){
				RIG = r[i];
				if(t[i] > TOP) TOP = t[i];
			}
		}
		/* mostra limites */ 
		printf("LB(%d,%d) RT(%d,%d)\n",LEF,BOT,RIG,TOP);
		/* constroi segmentos */
		for(i = 0; i < n; i++){
			int lt = (l[i]+5000)*100000, rt = (r[i]+5000)*100000;
			int tt = t[i]+5000, bt = b[i]+5000;
			int LB = lt+bt, RB = rt+bt;
			int LT = lt+tt, RT = rt+tt;

			if(l[i] != LEF) segment(LB,LT,1,t[i]-b[i]);
			if(r[i] != RIG) segment(RB,RT,1,t[i]-b[i]);
			if(t[i] != TOP) segment(LT,RT,0,r[i]-l[i]);
			if(b[i] != BOT) segment(LB,RB,0,r[i]-l[i]);
		}
		/* mostra numero de segmentos */
		printf("HSEG(%d) VSEG(%d)\n",HSEG,VSEG);
		/* ordena os segmentos VERTICAIS pela coordenada do topo */
		sort(vord,vord+VSEG);
		/* liga segmentos VERTICAIS com "pontas" coincidentes */
		int bin_search = VSEG;
		for(i = 0; i < VSEG; i++){
			int key = vert[i].b, u, v;
			for(u = 0, v = bin_search-1; u < v; ){
				int c = (u+v)>>1;
				if(key == vord[c].t){ u = c; break; }
				if(key < vord[c].t) v = c; else u = c+1;
			}
			if(vord[u].t == key){
				if(vord[u].m){
					swap(vert[i],vert[--VSEG]);
					continue;
				}
				vord[u].m = 1;
				int p = vord[u].n;
				vert[i].b = vert[p].b;
				vert[i].s += vert[p].s;
				swap(vert[p],vert[--VSEG]);
			}
		}
		/* elimina segmentos VERTICAIS contidos em outros segmentos maiores */
		sort(vert,vert+VSEG,LS_V());
		for(i = 0; i < VSEG; i++) vert[i].m = 0;
		for(i = 1; i < VSEG; i++) vert[i-1].m = (vert[i].b==vert[i-1].b);
		for(i = 0; i < VSEG; i++)
			if(vert[i].m) swap(vert[i],vert[--VSEG]);
		sort(vert,vert+VSEG);
		for(i = 0; i < VSEG; i++) vert[i].m = 0;
		for(i = 1; i < VSEG; i++) vert[i-1].m = (vert[i].t==vert[i-1].t);
		for(i = 0; i < VSEG; i++)
			if(vert[i].m) swap(vert[i],vert[--VSEG]);
		/* ordena os segmentos HORIZONTAIS pela coordenada do topo */
		sort(hord,hord+HSEG);
		/* liga segmentos HORIZONTAIS com "pontas" coincidentes */
		bin_search = HSEG;
		for(i = 0; i  < HSEG; i++){
			int key = hznt[i].l, u, v;
			for(u = 0, v = bin_search-1; u < v; ){
				int c = (u + v)>>1;
				if(key == hord[c].r){ u = c; break; }
				if(key < hord[c].r) v = c; else u = c+1;
			}
			
			if(hord[u].r == key){
				if(hord[u].m){
					swap(hznt[i],hznt[--HSEG]);
					continue;
				}
				hord[u].m = 1;
				int p = hord[u].n;
				hznt[i].l = hznt[p].l;
				hznt[i].s += hznt[p].s;
				swap(hznt[p],hznt[--HSEG]);
			}
		}
		/* elimina segmentos HORIZONTAIS contidos em outros segmentos maiores */
		sort(hznt,hznt+HSEG,LS_H());
		for(i = 0; i < HSEG; i++) hznt[i].m = 0;
		for(i = 1; i < HSEG; i++) hznt[i-1].m = (hznt[i].l==hznt[i-1].l);
		for(i = 0; i < HSEG; i++)
			if(hznt[i].m) swap(hznt[i],hznt[--HSEG]);
		sort(hznt,hznt+HSEG);
		for(i = 0; i < HSEG; i++) hznt[i].m = 0;
		for(i = 1; i < HSEG; i++) hznt[i-1].m = (hznt[i].r==hznt[i-1].r);
		for(i = 0; i < HSEG; i++)
			if(hznt[i].m) swap(hznt[i],hznt[--HSEG]);
		printf("VSEG(%d) HSEG(%d)\n",VSEG,HSEG);
	//	for(i = 0; i < HSEG; i++)
	//		printf("HSEG[%d](%d) = (%d,%d)\n",i,hznt[i].s,hznt[i].l,hznt[i].r);
		int cut_num = 0;	
		for(i = 0; i < HSEG; i++){
			int x1 = hznt[i].l/100000 - 5000;
			int x2 = x1 + hznt[i].s;
			int y = hznt[i].l%10000 - 5000;
			cuts[cut_num] = cut(x1,y,x2,y);
			printf("HSEG[%d] = (%d,%d)-(%d,%d)\n",i,x1,y,x2,y);
		}
		for(i = 0; i < VSEG; i++){
			int x = vert[i].b/100000 - 5000;
			int y1 = vert[i].b%10000 - 5000;
			int y2 = y1 + vert[i].s;
			cuts[cut_num] = cut(x,y1,x,y2);
			printf("VSEG[%d] = (%d,%d)-(%d,%d)\n",i,x,y1,x,y2);
		}


		
	}
	return 0;

}
