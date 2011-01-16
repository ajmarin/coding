/////////////////////////////////
// 10340 - All in All
/////////////////////////////////
#include<cstdio>
#include<cstring>
char s[100000], t[100000];
int i,j,last,lcs,m,n;
int main(void){
	while(scanf("%s %s",&s,&t)!=EOF){
		m = strlen(s);
		n = strlen(t);
		if(m > n) printf("No\n");
		else{
			for(lcs = last = i = 0; i < m && lcs == i; i++)
				for(j = last; j < n; j++)
					if(s[i] == t[j]){
						last = j+1;
						lcs++;
						break;
					}
			if(lcs == m) printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}