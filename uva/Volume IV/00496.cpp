#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <set>

using namespace std;

#define MMM 1<<20
#define tr(x) for(typeof(x.begin())it = x.begin(); it != x.end(); it++)

set < int > s[2];
char *n, nums[MMM];

bool buildset(bool f){
	if(fgets(nums, MMM, stdin) == NULL || !isdigit(nums[0])) return 0;
	n = strtok(nums, " ");
	while(n != NULL){
		s[f].insert(atoi(n));
		n = strtok(NULL, " ");
	}
	return 1;
}
int main(void){
	bool ainb, bina, disjoint;
	s[0].clear(); s[1].clear();
	while(buildset(0)){	
		buildset(1);
		ainb = bina = disjoint = 1;
		tr(s[0])
			if(s[1].find(*it) == s[1].end()) ainb = 0;
			else disjoint = 0;
		tr(s[1]) if(s[0].find(*it) == s[0].end()){ bina = 0; break; }
		if(ainb){
			if(bina) printf("A equals B\n");
			else printf("A is a proper subset of B\n");
		}
		else if(bina) printf("B is a proper subset of A\n");
		else if(disjoint) printf("A and B are disjoint\n");
		else printf("I'm confused!\n");
		s[0].clear(); s[1].clear();
	}
	return 0;
}

