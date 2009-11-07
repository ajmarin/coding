#include <cstdio>
#include <set>
#include <string>
#include <cstring>

using namespace std;

set < string > s;

char s1[128], s2[128], res[256], shf[256];
int main(void){
	int count, T, N;
	char *p1, *p2, *p3;
	bool notf;
	scanf("%d",&T);
	for(int cnum = 0; cnum < T; ){
		count = 0;
		s.clear();
		scanf("%d",&N);
		scanf("%s",s1);
		scanf("%s",s2);
		scanf("%s",res);
		shf[2*N] = 0;
		while(1){
			for(p1 = s1, p2 = s2, p3 = shf; *p1; *p1++, *p2++){
				*p3++ = *p2;
				*p3++ = *p1;
			}
			strncpy(s1, shf, N);
			strncpy(s2, shf+N, N);
			//printf("Produced: \"%s\"\n",shf);
			count++;
			if(strcmp(shf, res) == 0){
				notf = 0;
				break;
			} else if(s.find(string(shf)) != s.end()){
				notf = 1;
				break;
			} else s.insert(string(shf));
		}
		if(notf) printf("%d -1\n",++cnum);
		else printf("%d %d\n",++cnum,count);
	}
	return 0;
}

