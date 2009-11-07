#include <cstdio>
#include <vector>
using namespace std;
int N, K, M;
int joseph(){
	int d1, d2, k1, k2, left;
	vector < int > v;
	for(left = 1; left <= N; left++) v.push_back(left);
	d1 = d2 = 0;
	for(left = N; left; left--){
		d1 = (d1-1+K)%(left);
		d2 = d2 - M;
		while(d2 < 0) d2 += left;
		d2 %= left;
		k1 = *(v.begin()+d1);
		k2 = *(v.begin()+d2);
		if(d1 == d2) v.erase(v.begin()+d1);
		else {
			if(d2 > d1){
				v.erase(v.begin()+d2--);
				v.erase(v.begin()+d1);
			} else {
				v.erase(v.begin()+d1--);
				v.erase(v.begin()+d2);
			}
		}
		if(left != N) putc(',',stdout);
		if(k1 == k2) printf("%3d",k1);
		else left--, printf("%3d%3d",k1,k2);
	}
	putc(10, stdout);
}
int main(void){
	while(scanf("%d%d%d",&N,&K,&M) && N) joseph();
	return 0;
}
