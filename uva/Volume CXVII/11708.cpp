#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

long long f[20];
char a[32], b[32], o[32];
bool used[32];
int main(void){
	long long k;
	int pos, r;
	char *p;
	f[0] = 1;
	for(int i = 1; i < 20; ++i) f[i] = i * f[i - 1] + 1;
	scanf("%s", a);
	while(true){
		pos = k = 0;
		for(p = a; *p; ++p, ++pos);
		strcpy(o, a);
		sort(a, a + pos--);
		memset(used, 0, 32);
		for(p = o, r = pos; *p && r > -1; ++p){
			int c = 0, i;
			for(i = 0; a[i] != *p; ++i) if(!used[i]) c++;
			used[i] = 1;
			k += f[r--] * c + 1;
		}
		printf("%lld\n", k);			
		while(true){
			bool ok = scanf("%s", b) == 1;			
			if(!ok) return 0;
			if(b[0] > '9') break;
			for(p = b, k = 0; *p; ++p) k = k * 10 + (*p - '0');
			memset(used, 0, 32);
			r = pos;
			while(k){
				int idx = (k - 1) / f[r], c = 0, i;
				k = (k - 1) % f[r--];
				for(i = 0; c != idx; c += !used[i++]);
				while(used[i]) i++;
				used[i] = 1;
				putc(a[i], stdout);		
			}
			putc(10, stdout);
		}
		strcpy(a, b);
	}
	return 0;
}
