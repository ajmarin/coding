/////////////////////////////////
// 00130 - Roman Roulette
/////////////////////////////////
#include<cstdio>
#include<vector>
using namespace std;
unsigned char base[100];
int bury,ct,died,i,j,n,k,test;
bool s = 0;
// k = ppl, m = jump, start = starting position
bool joseph(int k, int m, int start){
	vector<unsigned int> v(base,base+k);
	for(died = start,i = 0; i < k-1; i++){
		died = (died+m-1)%(k-i);
		for(bury = died,ct = 0; ct < m; )
			if((++bury)%(k-i) != died) ct++;
		bury %= (k-i);
		if(*(v.begin()+died) == 1) return 0;		
		v[died] = v[bury];
		v.erase(v.begin()+bury);
		if(bury > died) died = (died+1)%(k-i-1);
		else if(died == k-i-1) died = 0;
	}
	return 1;
}
int main(void){
	for(i = 0; i < 101; i++) base[i] = i+1;
	while(scanf("%u %u",&n,&k) && n){
		for(test = 0; !joseph(n,k,test); test++);
			printf("%u\n",test+1);
	}
	return 0;
}
	
