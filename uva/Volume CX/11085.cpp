#include <cstdio>

int r[8], v[8];
int sol[40320][8], sc = 0;

void bt(int c, int l, int d, int u){
	if(c == 8){
		for(int i = 0; i < 8; ++i) sol[sc][i] = v[i];
		++sc;
		return;
	}
	for(int i = 0; i < 8; ++i) if(!(l & (1 << i))){
		int down = 1 << (i - c + 7),  up = 1 << (i + c);
		if( (d & down) || (u & up) ) continue;
		v[c] = i;
		bt(c + 1, l | (1 << i), d | down, u | up);
	}
}

int main(void){
	bt(0, 0, 0, 0);
	for(int c = 0; scanf("%d", &r[0]) == 1 && r[0]--; ){
		int min_changes = 8;
		for(int i = 1; i <= 7; ++i) scanf("%d", &r[i]), --r[i];
		for(int i = 0; i < sc; ++i){
			int changes = 0;
			for(int j = 0; j < 8; ++j) changes += r[j] != sol[i][j];
			if(changes < min_changes) min_changes = changes;
		}
		printf("Case %d: %d\n", ++c, min_changes);
	}
	return 0;
}

