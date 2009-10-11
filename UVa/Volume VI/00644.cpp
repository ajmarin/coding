#include <cstdio>

char nnn[1000][1000];

bool match(const char *a, const char *b){
	while(*a && *b) if(*a++ != *b++) return 0;
	return 1;
}

int main(void){
	int snum = 0;
	while(scanf("%s",nnn[0])==1){
		int k = 1;
		bool d = 1;
		while(scanf("%s",nnn[k]) && nnn[k][0] != '9'){
			for(int i = 0; d && i < k; ++i)
				if(match(nnn[i],nnn[k])) d = 0;
			k++;
		}
		printf("Set %d is ",++snum);
		if(!d) fputs("not ",stdout);
		puts("immediately decodable");
	}
	return 0;
}

