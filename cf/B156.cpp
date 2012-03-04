#include <cstdio>
const int N = 100048;

int canbe[N];
int neg[N], op[N], pos[N];
int main(void){
	for(int m, n; scanf("%d %d", &n, &m) == 2; ){
		int cnt = n, negc = 0, posc = 0;
		for(int i = 1; i <= n; ++i){
			neg[i] = pos[i] = 0;
			canbe[i] = true;
		}
		for(int i = 1, z; i <= n; ++i){
			scanf("%d", &z);
			op[i] = z;
			if(z < 0) ++neg[-z], ++negc;
			else ++pos[z], ++posc;
		}
		for(int i = 1; i <= n; ++i){
			int truth = pos[i] + negc - neg[i];
//			printf("[%d] %d told the truth\n", i, truth);
			if(truth != m){
//				printf("Cant be %d\n", i);
				canbe[i] = false;
				--cnt;
			}
		}
		for(int i = 1; i <= n; ++i){
			if(op[i] > 0){
				if(canbe[op[i]]) puts(cnt == 1 ? "Truth" : "Not defined");
				else puts("Lie");
			} else {
				if(canbe[-op[i]]) puts(cnt == 1 ? "Lie" : "Not defined");
				else puts("Truth");
			}
		}
	}
	return 0;
}

