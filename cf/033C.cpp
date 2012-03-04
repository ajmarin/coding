#include <cstdio>

#define NN 100048
int b[NN], v[NN];

int int_sum(int l, int r){
	if(l > r) return 0;
	return v[r] - v[l - 1];
}
int main(void){
	int n; scanf("%d", &n);
	int best = 0, minval = 0, sum = 0, temp, val = 0;
	int *ptr = v + 1;
	v[0] = 0;
	for(int i = 0; i < n; ++i){
		scanf("%d", &ptr[i]);
		ptr[i] += ptr[i - 1];
	}
	b[n + 1] = n + 1;
	v[n + 1] = 0;
	for(int i = n; i > -1; i--){
		val = *(v + n) - *(v + i - 1);//int_sum(i, n);
		b[i] = b[i + 1];
		if(val < minval){
			minval = val;
			b[i] = i;
		}
	}
	for(int i = 0; i < n; ++i){
		int k = b[i + 1];
//		temp = -int_sum(1, i) + int_sum(i + 1, k - 1) - int_sum(k, n);
		temp = (*(v + k - 1) << 1) - (*(v + i) << 1) - *(v + n);
		if(temp > best) best = temp;
	}
	printf("%d\n", best);
	return 0;
}


