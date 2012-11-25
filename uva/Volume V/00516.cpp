#include <cstdlib>
#include <cstdio>
#include <cstring>

int exp[32], factors[32], top;

void push(int p, int e){
	factors[top] = p;
	exp[top] = e;
	top++;
}

template <typename _T> _T Square(_T a) { return a * a;					}
template <typename _T> _T Power(_T b, _T e){ // returns b^e
	// Depends: Square
	for(_T r = 1; ; b = Square(b)){
		if(e & 1) r = r * b;
		if(!(e >>= 1)) return r;
	}
}
template <typename _T> void Reduce(_T &n, _T d){ 
	if(n % d) return;
	_T c = 0;
	do { n /= d; ++c; } while(!(n % d));
	push(d, c);
}

int main(void){
	for(char line[1024]; fgets(line, 1024, stdin) && *line != '0'; ){
		int base = -1, z = 1;
		for(char *p = strtok(line, " "); p != NULL; p = strtok(NULL, " "))
			if(base == -1) base = atoi(p);
			else { z *= Power(base, atoi(p)); base = -1; }
		--z;
		top = 0;
		Reduce(z, 2);
		Reduce(z, 3);
		for(int i = 6; ; i += 6){
			Reduce(z, i - 1);
			Reduce(z, i + 1);
			if(i * i + 2 * i + 1 > z) break;
		}
		if(z != 1) push(z, 1);
		while(top--) printf("%d %d%c", factors[top], exp[top], top ? 32 : 10);
	}
	return 0;
}

