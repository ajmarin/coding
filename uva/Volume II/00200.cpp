#include <cstdio>
#include <cstring>

char c[2][32], d[32], *c1, *c2;
bool a[32][32];
void toposort(int k){
	putc(k+'A', stdout);
	int i, q[32], qs = 0;
	for(i = 0; i < 26; i++){
		if(a[k][i] && --d[i] == 0)
			q[qs++] = i;
	}
	for(i = 0; i < qs; i++)
		toposort(q[i]);
}
int main(void){
	bool n, p;
	int i;
	while(gets(c[0])){
		n = 1, p = 0;
		memset(d,-1,32);
		memset(a,0,1024);
		while(gets(c[n]) && c[n][0] != '#'){
			c2 = &c[n][0];
			c1 = &c[p][0];
			while((*c1 && *c2) && (*c1 == *c2)) c1++, c2++;
			if(*c1 && *c2){
				char pc = *c1 - 'A', nc = *c2 - 'A';
				if(!a[pc][nc]){
					//printf("%c->%c\n",*c1,*c2);
					if(d[pc] == -1) d[pc] = 0;
					if(d[nc] == -1) d[nc] = 0;
					a[pc][nc] = 1;
					d[nc]++;					
				}
			}
			n = !n; p = !p;
		}
		for(i = 0; i < 26; i++)
			if(d[i] == 0){ toposort(i); break; }
		putc(10, stdout);
	}
	return 0;
}
