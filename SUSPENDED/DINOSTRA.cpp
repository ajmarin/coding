#include <cstdio>
#include <cstring>
#define MAX 1048577
#define LIM 1025
bool p[1048577];
int ffreq[10], plist[1025];
const char *no = "nao\n", *si = "sim\n";
int main(void){
	int cnum, f_size, i, j, l_size = 1, sp, N;
	memset(p,1,sizeof(p));
	p[0] = p[1] = 0;
	plist[0] = 2;
	for(i = 4; i < MAX; i+=2) p[i] = 0;
	for(i = 3; i < LIM; i+=2)
		if(p[i]){
			plist[l_size++] = i;
			for(j = i*i; j < MAX; j+=i) p[j] = 0;
		}
	//for(i = 2; i < 100; i++) if(p[i]) printf("%d ",i);
	//putc(10,stdout);
	for(int cnum = 1; scanf("%d",&N) != EOF; cnum++){
		printf("Instancia %d\n",cnum);
		if(p[N]){ puts(no); continue; }
		for(f_size = i = sp = 0; i < l_size; i++)
			if(!(N % plist[i])){
				ffreq[f_size] = 0;
				while(!(N % plist[i]))
					N /= plist[i], ffreq[f_size]++;
				if(ffreq[f_size] > 1) sp++;
				f_size++;
				if(N == 1) break;
			}
			if(i == l_size) f_size++;
			switch(f_size){
				case 1: (ffreq[0] > 7)	? puts(si):puts(no); break;
				case 2: (sp > 1 || *ffreq+*(ffreq+1) > 5)?
						puts(si):puts(no); break;
				case 3: (sp)			? puts(si):puts(no); break;
				default: puts(si); break;
			}
	}

	return 0;

}

