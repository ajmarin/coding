#include <cstdio>
#include <cmath>


struct point { 
	float x, y; 
	inline float sqr(float x) const { return x*x;}

	float sqdist(const point &p) const {return sqr(x-p.x)+sqr(y-p.y);}
};
point D, G, H;
const char *CANT = "The gopher cannot escape.";
int main(void){
	int N;
	while(scanf("%d %f %f %f %f",&N,&G.x,&G.y,&D.x,&D.y)==5){
		bool found = 0;
		while(N-- && scanf("%f %f",&H.x,&H.y)) {
			if(found) continue;
			if(H.sqdist(G)*4 <= H.sqdist(D)){
				found = 1;
				printf("The gopher can escape through the hole at (%.3f,%.3f).\n",
					H.x,H.y);
			}
		}
		if(!found) puts(CANT);
	}
	return 0;
}

