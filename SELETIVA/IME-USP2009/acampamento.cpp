#include <cstdio>
#include <vector>
using namespace std;
char names[128][64];
int f[128];
int joseph(int n){
	vector< pair<int , int> >  v;
	int died, i, m;
	for(i = 0; i < n; i++) v.push_back(make_pair(f[i],i));
	m = f[0];
	if(m&1) died = 1;
	else died = 0;
	for(i = 0; i < (n-1); i++){
		if(m&1) died = (died-1+m)%(n-i);
		else {
			m = -m;
			died = (died+m);
			while(died < 0) died += (n-i);
			died%=(n-i);
		}
		m = (*(v.begin()+died)).first;
		//printf("m(%d), died(%s,%d)\n",m,names[(*(v.begin()+died)).second],died);
		v.erase(v.begin()+died);
	}
	return (*v.begin()).second;
}

int main(void){
	int N, i;
	while(scanf("%d",&N) && N){
		for(i = 0; i < N; i++)
			scanf("%s%d",names[i],&f[i]);
		int k = joseph(N);
		printf("Vencedor(a): %s\n",names[k]);
	}
	return 0;
}

