#include <cstdio>
#include <cstring>
int D, ans_count, i, last;
bool used[10], dbg = 0, match;
char ans[25];
long long S, csum, num[10]; 
char choice[10], sep = ' ';
char mapit[10] = {'0','1','2','3','4','5','6','7','8','9'};
void build_show(int k){
	int XX, pos;
	match = 1;
	/* CONSTROI A STRING DE SAIDA */
	for(XX = pos = 0; XX <= k; XX++){
		if(XX && XX%D == 0) ans[pos++] = sep;
		ans[pos++] = mapit[choice[XX]];
	}
	ans[pos] = '\0';
	puts(ans);
	/* VERIFICA A POSSIBILIDADE DE SOMAR 0 */
	if((k%D) == D-1 && choice[k] > 6 && !used[0]){
		ans[pos++] = sep;
		ans[pos++] = '0';
		ans[pos] = '\0';
		puts(ans);
	}
}
void bt(int n, int k){
	if(used[n] || k == 10) return;
	int div = k/D, rest = k%D;
	long long added;
	used[n] = 1;
	choice[k] = n;
	if(!rest) num[div] = n;
	else num[div] = num[div]*10 + n;	
	csum += num[div];
	added = num[div];
	if(csum >= S){
		if(csum == S) build_show(k);
		csum -= num[div];
		num[div] /= 10;
		used[n] = 0;
		return;
	}
	if(rest != D-1) csum -= num[div];
	switch(n){
		case 1: bt(2,k+1); bt(4,k+1); bt(5,k+1); break;
		case 2: bt(1,k+1); bt(3,k+1); bt(4,k+1);
				bt(5,k+1); bt(6,k+1); break;
		case 3: bt(2,k+1); bt(5,k+1); bt(6,k+1); break;
		case 4: bt(1,k+1); bt(2,k+1); bt(5,k+1);
				bt(7,k+1); bt(8,k+1); break;
		case 5: bt(1,k+1); bt(2,k+1); bt(3,k+1);
				bt(4,k+1); bt(6,k+1); bt(7,k+1);
				bt(8,k+1); bt(9,k+1); break;
		case 6: bt(2,k+1); bt(3,k+1); bt(5,k+1);
				bt(8,k+1); bt(9,k+1); break;
		case 7: bt(0,k+1); bt(4,k+1); bt(5,k+1);
				bt(8,k+1); break;
		case 8: bt(0,k+1); bt(4,k+1); bt(5,k+1);
				bt(6,k+1); bt(7,k+1); bt(9,k+1); break;
		case 9: bt(0,k+1); bt(5,k+1); bt(6,k+1);
				bt(8,k+1); break;
		case 0: bt(7,k+1); bt(8,k+1); bt(9,k+1); break;
	}
	if(rest == D-1) csum -= added;
	num[div]/=10;
	used[n] = 0;
}
int main(void){
	for(int cnum = 1; scanf("%lld%d",&S,&D) && S != -1; cnum++){
		printf("#%d\n",cnum);
		for(match = i = 0; i < 10; i++) used[i] = 0;
		for(ans_count = i = 0; i < 10; i++) bt(i,0);
		if(!match) printf("impossivel\n");
	}
	return 0;
}
