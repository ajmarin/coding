#include <algorithm>
#include <cstdio>
using namespace std;

const int NN = 256;
char a[NN], b[NN];
int main(void){
	int t; scanf("%d", &t);
	for(int c = 0; t-- && scanf("%s %s", a, b) == 2; ){
		int otz = 0, q = 0, za = 0, zb = 0, zto = 0;
		for(int i = 0; a[i]; ++i){
			za += a[i] == '0';
			zb += b[i] == '0';
			otz += a[i] == '1' && b[i] == '0';
			zto += a[i] == '0' && b[i] == '1';
			q += a[i] == '?';
		}
		printf("Case %d: ", ++c);
		if(zb > za + q) puts("-1");
		else printf("%d\n", otz + zto - min(otz, zto) + q);
	}
	return 0;
}

