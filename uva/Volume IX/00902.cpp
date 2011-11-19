#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

/* {{{ Suffix array */
#define N 1048576
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
/* }}} */

int main(void){
	for(int L, n; scanf("%d %s", &n, w) == 2; ){
		for(L = 0; w[L]; ++L);
		w[L++] = '$';
		suffix_array(L);
		compute_lcp(L);
		int idx = -1, maxoc = 0;
		for(int i = 0, j; i < L; ++i)
			if(lcp[i] >= n){
				for(j = i; lcp[j] >= n; ++j);
				if(j - i > maxoc){
					maxoc = j - i;
					idx = i;
				}
				i = j - 1;
			}
		w[pos[idx].z + n] = 0;
		puts(w + pos[idx].z);
	}
	return 0;
}

