#include <cstdio>
#include <vector>
using namespace std;
vector < int > v;
vector < int >::iterator it;
int main(void){
	int i, j, mov, N, ord, P, R;
	for(int t = 1; scanf("%d%d",&P,&R) && P; t++){
		v.clear();
		for(i = 0; i < P; i++) scanf("%d",&j), v.push_back(j);
		for(i = 0; i < R; i++){
			scanf("%d%d",&N,&ord);
			for(it = v.begin(); it != v.end(); it++){
				scanf("%d",&mov);
				if(mov != ord) v.erase(it--);
			}
		}
		printf("Teste %d\n%d\n\n",t,*v.begin());
	}
	return 0;
}
