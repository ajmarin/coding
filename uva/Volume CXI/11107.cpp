#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <string>
using namespace std;

/* {{{ Suffix array */
#define N 104857
char w[N];
int H = 0, bucket[N], lcp[N], new_bucket[N], rank[N], sn[N];
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
	int i, id;
	for(i = id = 0; i < L; ++i)
		new_bucket[pos[i].z] = (id += i && !(pos[i] == pos[i - 1]));
	memcpy(bucket, new_bucket, L << 2);
	return id != L - 1;
}

void suffix_array(int L){
	int c = 1;
	memset(bucket, -1, sizeof bucket);
	for(int i = H = 0; i < L; ++i) pos[i].z = i;
	for(H = 0; c; H = (H << 1) | !H){
		sort(pos, pos + L); 
		c = update_buckets(L);
	}
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

/* {{{ Interval tree */
#define LEFT(x) (2 * (x - d) + d + 1)
#define RIGHT(x) (2 * (x - d) + d + 2)
struct interval { int left, right, value; } d[4*N];
int init_interval(interval *i, int left, int right){
	i -> left = left;
	i -> right = right;
	if(left < right){
		int mid = (left + right) >> 1;
		i -> value = min(
			init_interval(LEFT(i), left, mid),
			init_interval(RIGHT(i), mid + 1, right)
		);
	} else i -> value = lcp[left];
	return i -> value;
}
int query(interval *i, int left, int right){
	if(left > i -> right || right < i -> left) return 1 << 30;
	if(left <= i -> left && i -> right <= right) return i -> value;
	return min(query(LEFT(i), left, right), query(RIGHT(i), left, right));
}
/* }}} */

int cnt[128], xx[N];
int main(void){
	bool first = true;
	for(int n; scanf("%d", &n) == 1 && n; first = false){
		int half = n / 2, L = 0;
		if(!first) puts("");
		for(int i = 0; i < n; ++i){
			scanf("%s", w + L);
			while(w[L]) sn[L++] = i;
			sn[L] = -1;
			cnt[i] = 0;
			w[L++] = '$';
		}
		if(n == 1){
			w[L-1] = 0;
			puts(w);
			continue;
		}
		w[L] = 0;
		suffix_array(L);
		compute_lcp(L);
		init_interval(d, 1, L);

		int maxlcp = 0;
		for(int i = 0; i < L; ++i) xx[i] = -1;
		for(int i = 0, in = 0, j = 0; i < L; ++i){
			while(in <= half && j < L){
				j++;
				if(sn[pos[j].z] != -1 && !cnt[sn[pos[j].z]]++) ++in;
			}
			if(j >= L) break;
			xx[i] = query(d, i + 1, j);
			maxlcp = max(maxlcp, xx[i]);
			if(sn[pos[i].z] != -1 && !--cnt[sn[pos[i].z]]) --in;
		}
		if(maxlcp == 0) printf("?\n");
		else {
			set < string > seen;
			for(int i = 0; i < L; i++) if(xx[i] == maxlcp) {
				char temp = w[pos[i].z + maxlcp];
				w[pos[i].z + maxlcp] = 0;
				if(seen.find(w + pos[i].z) == seen.end()){
					seen.insert(w + pos[i].z);
					puts(w + pos[i].z);
				}
				w[pos[i].z + maxlcp] = temp;
			}
		}
	}
	return 0;
}

