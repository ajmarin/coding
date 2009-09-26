/////////////////////////////////
// 10015 - Joseph's Cousin
/////////////////////////////////
#include<cstdio>
#include<vector>
#define MAX 32767
using namespace std;
bool sieve[32767];
unsigned short primes[3502];
unsigned short survivor[3502];
unsigned int current,k,i,j,n,idx,size;
void joseph(void){
	vector<unsigned int> v;
	vector<unsigned int>::iterator it;
	for(i = 0; i < n; i++) v.push_back(i+1);
	for(k = 0,i = 0; i < n-1; i++){
		if(primes[i] > n-i) idx = primes[i]%(n-i);
		else idx = primes[i];
		size = v.size();
		k = (k-1+idx)%size;
		v.erase(v.begin()+k);
	}
	survivor[n] = *v.begin();
}
int main(void){
	for(primes[0] = 2,i = 4; i < MAX; i+=2) sieve[i] = 1;
	for(idx = 1,i = 3; i < MAX && idx < 3502; i+=2)
		if(!sieve[i])
			for(primes[idx++] = i,j = i*i; j < MAX; j+=i) sieve[j] = 1;
	while(scanf("%d",&n) && n){
		if(!survivor[n]) joseph();
		printf("%d\n",survivor[n]);
	}
	return 0;
}