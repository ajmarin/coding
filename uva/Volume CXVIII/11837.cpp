#include <cstdio>
#include <cstring>

#define KKL 10048
#define WWL 100048
char map[256], note[64], K[KKL], W[WWL];
const char *ans[2] = {"N", "S"};
int F[KKL];

void kmp_table(char *K, int KL){
	F[0] = F[1] = 0;
	int i, j;
	for(i = 2; i < KL; ++i){
		j = F[i - 1];
		while(1){
			if(K[j] == K[i - 1]){ F[i] = j + 1; break; }
			if(j == 0){ F[i] = 0; break; }
			j = F[j];
		}
	}
}
int kmp(char *W, int WL, char *K, int KL){
	kmp_table(K, KL);
	for(int i = 0, j = 0; j < WL; ){
		if(W[j] == K[i]){
			i++;
			j++;
			if(i == KL) return j;
		} else if(i > 0) i = F[i]; 
		else j++;
	}
	return -1;
}
void read_music(char *x, int L){
	char p, v;
	for(int i = 0; i < L; ++i){
		scanf("%s", note);
		p = v;
		v = map[note[0]] + (note[1] == '#') - (note[1] == 'b');
		v = (v + 12) % 12;
		if(i) x[i - 1] = (v - p + 12) % 12;
	}
}

int main(void){
	map['A'] = 0; map['B'] = 2;	map['C'] = 3;
	map['D'] = 5; map['E'] = 7; map['F'] = 8; map['G'] = 10;
	int z, KL, WL;
	while(scanf("%d %d", &WL, &KL) && WL){
		read_music(W, WL);
		read_music(K, KL);
		--WL, --KL;
		z = kmp(W, WL, K, KL);
		puts(ans[z != -1]);
	}
	return 0;
}

