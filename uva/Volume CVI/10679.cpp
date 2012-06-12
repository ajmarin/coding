#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

/* {{{ Suffix array */
#define N 104857
char w[N];
int H = 0, bucket[N], lcp[N], new_bucket[N], rank[N];
struct suffix {
	int z;
	bool operator<(const suffix& s) const {
		if(!H) return w[z] < w[s.z];
		if(bucket[z] == bucket[s.z]) return bucket[z + H] < bucket[s.z + H];
		return bucket[z] < bucket[s.z];
	}
	bool operator==(const suffix& s) const {
		return !(*this < s) && !(s < *this);
	} 
} pos[N]; 
bool update_buckets(int L){
	int i, j, id;
	for(i = id = 0; i < L; ){
		for(j = i; j < L && bucket[pos[j].z] == bucket[pos[i].z]; ++j);
		if(j != i + 1) sort(pos + i, pos + j);
		while(i < j) {
			if(i && !(pos[i] == pos[i - 1])) ++id;
			new_bucket[pos[i++].z] = id;
		}
	}
	memcpy(bucket, new_bucket, L << 2);
	return id != L - 1;
}

void suffix_array(int L){
	memset(bucket, -1, sizeof bucket);
	for(int i = H = 0; i < L; ++i) pos[i].z = i;
	for(H = 0; update_buckets(L); H = (H << 1) | !H);
}

void compute_lcp(int L){
	for(int i = 0; i < L; ++i) rank[pos[i].z] = i;
	for(int h = 0, i = 0, j; i < L; ++i)
		if(rank[i]){
			j = pos[rank[i] - 1].z;			
			while(w[i + h] != '$' && w[i + h] == w[j + h]) ++h;
			lcp[rank[i]] = h;
			h -= h > 0;
		}
}

int find(char *hay, int L){
	int hl = strlen(hay);
	int h = L, l = 0, m;
	while(l < h){
		m = (l + h) >> 1;
		if(strncmp(hay, w + pos[m].z, hl) > 0) l = m + 1;
		else h = m;
	}
	return strncmp(hay, w + pos[l].z, hl) ? -1 : l;
}
/* }}} */

char hay[1024];
int main(void){
	int t; scanf("%d", &t);
	while(t--){
		int n, L;
		scanf(" %s%n", w, &L);
		w[L] = '$';
		w[++L] = 0;
		suffix_array(L);
		scanf("%d", &n);
		while(n--){
			scanf("%s", hay);
			if(find(hay, L) != -1) puts("y");
			else puts("n");
		}
	}

	return 0;
}

