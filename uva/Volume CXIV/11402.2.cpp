#include <cmath>
#include <cstdio>

const int N = 1048576;
bool bucaneer[N];
int root, sections;

struct section { 
	int b, e, v, z;
	void flip(){ v = e - b + 1 - v; }
	void cnt(){ for(int i = b, &j = v = 0; i <= e; ++i) j += bucaneer[i]; }
} s[1024];

int max(int a, int b){ return a > b ? a : b; }
int min(int a, int b){ return a < b ? a : b; }


void init(int sn, int left, int right){
	s[sn].b = left;
	s[sn].e = right;
	s[sn].z = ' ';
	s[sn].cnt();
}

void update_interval(int left, int right, char u){
	switch(u){
		case 'I': for(int i = left; i <= right; ++i) bucaneer[i] = !bucaneer[i]; break;
		case 'E': for(int i = left; i <= right; ++i) bucaneer[i] = 0; break;
		case 'F': for(int i = left; i <= right; ++i) bucaneer[i] = 1; break;
	}
}

void update(int left, int right, char u){
	for(int i = 0; i < sections; ++i){
		if(left > s[i].e || right < s[i].b) continue;
		if(left <= s[i].b && s[i].e <= right){
			if(u == 'I'){
				s[i].flip();
				switch(s[i].z){
					case 'I': s[i].z = ' '; break;
					case ' ': s[i].z = 'I'; break;
					case 'E': s[i].z = 'F'; break;
					case 'F': s[i].z = 'E'; break;
				}
			} else {
				s[i].z = u;
				if(u == 'E') s[i].v = 0;
				else s[i].v = s[i].e - s[i].b + 1;
			}
		} else {
			if(s[i].z != ' ') update_interval(s[i].b, s[i].e, s[i].z);
			s[i].z = ' ';
			update_interval(max(left, s[i].b), min(right, s[i].e), u);
			s[i].cnt();
		}
	}
}

int query(int left, int right){
	int r = 0;
	for(int i = 0; i < sections; ++i){
		if(left > s[i].e || right < s[i].b) continue;
		if(left <= s[i].b && s[i].e <= right) r += s[i].v;
		else{
			if(s[i].z != ' ') update_interval(s[i].b, s[i].e, s[i].z);
			s[i].z = ' ';
			for(int j = max(left, s[i].b); j <= min(right, s[i].e); ++j) r += bucaneer[j];
		}
	}
	return r;
}

int main(void){
	int tcn; scanf("%d", &tcn);
	for(int i = 0, j, k, l; i++ < tcn; ){
		int a, b, pirates = 0, reps, queries, qc = 0, specs;
		char cmd, pattern[64];
		for(scanf("%d", &specs); specs--; ){
			scanf("%d %s", &reps, pattern);
			for(j = 0; pattern[j]; ++j) pattern[j] -= '0';
			for(k = 0; k < reps; ++k) for(l = 0; l < j; ++l) 
				bucaneer[pirates++] = pattern[l];
		}
		root = int(sqrt(pirates));
		sections = root + (root * root < pirates);
		for(int j = 0; j < sections; ++j) init(j, j * root, min((j + 1) * root, pirates) - 1);
		printf("Case %d:\n", i);
		for(scanf("%d", &queries); queries--; ){
			scanf(" %c %d %d", &cmd, &a, &b);
			if(cmd == 'S') printf("Q%d: %d\n", ++qc, query(a, b));
			else update(a, b, cmd);
		}
	}
	return 0;
}

