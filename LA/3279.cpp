#include <cstdio>

char n1[1024], n2[1024], oe[50];
int main(void){
	int even, odd, x, N;
	while(scanf("%s %s %s",&n1,&n2,&oe) && n1[0] != '#'){
		scanf("%d",&N);
		odd = even = 0;
		for(int i = 0 ; i < N; ++i){
			scanf("%d",&x);
			if(x&1) odd++; else even++;
		}
		if(oe[0] == 'e') printf("%s %d %s %d\n",n1,odd,n2,even);
		else printf("%s %d %s %d\n",n1,even,n2,odd);
	}
	return 0;
}

