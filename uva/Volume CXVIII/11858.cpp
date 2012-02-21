#include <cctype>
#include <cstdio>

const int N = 1048576;
int v[N], L[N], R[N];
long long ans;

/* {{{ FAST integer input */
#define X10(n)	((n << 3) + (n << 1))
#define RI		readint
const int MAXR = 65536;
char buf[MAXR], *lim = buf + MAXR - 1, *now = lim + 1;
bool adapt(){ // Returns true if there is a number waiting to be read, false otherwise
	while(now <= lim && !isdigit(*now)) ++now;
	if(now > lim){
		int r = fread(buf, 1, MAXR-1, stdin);
		buf[r] = 0;
		lim = buf + r - 1;
		if(r == MAXR - 1){
			while(isdigit(*lim)) ungetc(*lim--, stdin);
			if(*lim == '-') ungetc(*lim--, stdin);
		}
		now = buf;
	}
	while(now <= lim && !isdigit(*now)) ++now;
	return now <= lim;
}
bool readint(int& n){ // Returns true on success, false on failure
	if(!adapt()) return false;
	bool ngtv = *(now - 1) == '-';
	for(n = 0; isdigit(*now); n = X10(n) + *now++ - '0');
	if(ngtv) n = -n;
	return true;
}
/* }}} end FAST integer input */

void merge(int left, int mid, int right){
	int i, iL, iR, j, k;
	for(i = left, iL = 1; i <= mid; ++i) L[iL++] = v[i];
	for(i = mid+1, iR = 1; i <= right; ++i) R[iR++] = v[i];
	L[iL] = R[iR] = 1 << 30;
	i = j = 1;
	for(k = left; k <= right; ++k){
		if(L[i] > R[j]){
			ans += iL - i;
			v[k] = R[j++];
		} else v[k] = L[i++];
	}
}

void merge_sort(int left, int right){
	if(left < right){
		int mid = (left + right) >> 1;
		merge_sort(left, mid);
		merge_sort(mid + 1, right);
		merge(left, mid, right);
	}
}

int main(void){
	for(int n; RI(n); ){
		ans = 0;
		for(int i = 0; i < n; ++i) RI(v[i]);
		merge_sort(0, n - 1);
		printf("%lld\n", ans);
	}
	return 0;
}

