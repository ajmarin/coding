#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
using namespace std;
struct container {
	char word[16];
	int len;
	bool operator<(const container k) const{
		return len < k.len;
	}
} w[4096];
int cnt[128], map[128];
bool used[10];
int sqr(int x)			{ return x * x;							}
bool is_square(int x)	{ return sqr(floor(sqrt(x + .5))) == x;	}
int translate(int idx){
	int r = 0;
	if(map[w[idx].word[0]] == 0) return 3;
	for(int i = 0; i < w[idx].len; ++i)
		r = r * 10 + map[w[idx].word[i]];
	return r;
}
int test(int a, int b, int c){
	int r = -1;
	if(c == w[a].len){
		int ta = translate(a), tb = translate(b);
		if(is_square(ta) && is_square(tb)){
			printf("%s = %d ... %s = %d\n", w[a].word, ta, w[b].word, tb);
			return max(ta, tb);
		}
		return -1;
	}
	if(map[w[a].word[c]] != -1) r = max(r, test(a, b, c + 1));
	else for(int d = !c; d < 10; ++d){
		if(used[d]) continue;
		used[d] = 1;
		map[w[a].word[c]] = d;
		//printf("map[%c] = %d\n", w[a].word[c], d); 
		r = max(r, test(a, b, c + 1));
		map[w[a].word[c]] = -1;
		used[d] = 0;
	}
	return r;
}
bool anagram(int a, int b){
	for(int i = 'A'; i <= 'Z'; ++i) cnt[i] = 0;
	for(char *p = w[a].word, *q = w[b].word; *p; ) ++cnt[*p++], --cnt[*q++];
	for(int i = 'A'; i <= 'Z'; ++i)
		if(cnt[i] != 0) return 0;
	return 1;
}
int main(void){
	clock_t ini = clock();
	int ans = 0, n = 0;
	freopen("words.txt", "r", stdin);
	for(n = 0; scanf("%*[ \",]%[A-Z]", w[n].word, &w[n].len) == 1; ++n)
		w[n].len = strlen(w[n].word);
	sort(w, w + n);
	for(int i = 0; i < 10; ++i) used[i] = 0;
	for(int i = 0; i < 128; ++i) map[i] = -1;
	for(int i = 0; i < n; ++i)
		for(int j = i + 1; j < n; ++j){
			if(w[j].len != w[i].len) break;
			if(anagram(i, j)){
				printf("%s is an anagram of %s\n", w[j].word, w[i].word);
				ans = max(ans, test(i, j, 0));		
			}
		}
		//printf("%s [%d]\n", w[i].word, w[i].len);
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}
