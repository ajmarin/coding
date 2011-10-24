#include <cstdio>
#define FOR(i,n)	for(int i = 0; i < n; ++i)
using namespace std;
const int NN = 128;
char f1[NN], f2[NN];

void swap(char &a, char &b){ char tmp = a; a = b; b = tmp; }
void rev(char *p, int len){
	for(int i = 0; i < (len>>1); ++i) swap(p[i], p[len-1-i]);
}
int max(int a, int b){ return a > b ? a : b; }

int main(void){
	bool first = true;
	for(int i, l1, l2; scanf("%s%s", f1, f2) == 2; first = false){
		if(!first) puts("");
		for(l1 = 0; f1[l1]; ++l1); 
		for(i = l1; i < NN-1; ++i) f1[i] = '0';
		for(l2 = 0; f2[l2]; ++l2);
		for(i = l2; i < NN-1; ++i) f2[i] = '0';
		f1[NN-1] = f2[NN-1] = 0;
		rev(f1, l1);
		rev(f2, l2);
		for(i = 0; i < NN-1; ++i) f1[i] += f2[i] - '0';
		for(bool changed = true; changed; ){
			changed = false;
			for(i = 0; i < NN-1; ++i){
				changed |= f1[i] >= '2';
				while(f1[i] >= '2'){
					++f1[i+1];
					if(i) ++f1[max(i-2, 0)];
					f1[i] -= 2;
				}
				changed |= i && f1[i] == '1' && f1[i-1] == '1';
				if(i && f1[i] == '1' && f1[i-1] == '1')
					++f1[i+1], --f1[i], --f1[i-1];
			}
		}
		for(i = NN-2; i > 0 && f1[i] != '1'; --i);
		rev(f1, i+1);
		f1[i+1] = 0;
		puts(f1);
	}
	return 0;
}

