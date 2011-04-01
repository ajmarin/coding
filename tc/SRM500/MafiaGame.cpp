#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int N = 500;
int votes[N];
bool v[N], hasv[N];
class MafiaGame {
public:
	double probabilityToLose( int n, vector <int> decisions ) {
		int nv = n, pv = -1;
		double ans = 0;
		for(int i = 0; i < n; ++i){
			votes[i] = 0;
			v[i] = 1;
			hasv[i] = 0;
		}
		for(int r = 0; ; ++r){
			pv = nv;
			/* Definite opinion votes */
			for(int i = 0; i < (int)decisions.size(); ++i){
				if(v[decisions[i]]){
					hasv[i] = 1;
					++votes[decisions[i]];
				}
			}
			/* Find max_votes before random votes */
			int max_b = 0, cnt = 0, cnt2 = 0;
			for(int i = 0; i < n; ++i)
				if(votes[i] > max_b) max_b = votes[i];
			for(int i = 0; i < n; ++i){
				cnt += votes[i] == max_b;
				cnt2 += v[i];
			}
			if(!ans && cnt == cnt2) ans = 1.0 / cnt;
			/* All the rest */
			for(int i = 0; i < n; ++i){
				if(!hasv[i]){
					hasv[i] = 1;
					int min_votes = 1024, idx = -1;
					for(int j = 0; j < n; ++j)
						if(v[j] && votes[j] < min_votes){
							min_votes = votes[j];
							idx = j;
						}
					++votes[idx];
				}
			}
			/* Find max number of votes */
			int max_votes = 0;
			for(int i = 0; i < n; ++i){
				if(votes[i] > max_votes) max_votes = votes[i];
			}
			nv = 0;
			for(int i = 0; i < n; ++i){
				nv += (v[i] = votes[i] == max_votes);
				hasv[i] = 0;
				votes[i] = 0;
			}
			if(nv == pv) return 0;
			if(nv == 1){
				if(ans) return ans;
				else return 1.0 / cnt;
			}
		}
	}
};
