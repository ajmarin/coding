#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define NN 1024 
char s[NN];
int C, H, L;
int B[NN], NB[NN], SA[NN];

bool cmp(int x, int y){
	return H?B[x]==B[y]?B[x+H]<B[y+H]:B[x]<B[y]:s[x]<s[y];
}
bool eq(int x, int y){ return !(cmp(SA[x], SA[y]) || cmp(SA[y], SA[x])); }
int ub(){
	int st = 0, id = 0;
	bool c = 0;
	for(int i = 0; i < L; i++){
		if(i != 0 && !eq(i, i-1)) st = i, id++;
		c |= (i != st);
		NB[SA[i]] = id;
	}
	memcpy(B, NB, L << 2);
	return c;
}
int ss(){
	int ans = 0, i, j, l = 0, *PSA = SA;
	char *a, *b;
	for(i = 0; i < L; ++i) SA[i] = i;
	sort(SA, SA + L, cmp);
	for(C = ub(), H = 1; C; H <<= 1) sort(SA, SA+L, cmp), C = ub();
	for(i = 0; i < L; ++i) B[*PSA++] = i;
	for(i = 0; i < L; ++i) if(B[i]){
		j = SA[B[i] - 1];
		a = s + i + l, b = s + j + l;
		while(*a++ == *b++) l++;
		ans += l;
		l -= !!l;
	}
	return ans;
}
int main(){
	int t; scanf("%d\n", &t);
	while(t-- && scanf("%s%n\n", s, &L)){
		++L; H = 0;
		printf("%d\n", L * (L - 1) / 2 - ss());
	}
	return 0;
}

