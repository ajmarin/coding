#include <cstdio>

bool row[8] = {0, 0, 0, 0, 0, 0, 0, 0};
bool d1[16] = {0, 0, 0, 0, 0, 0, 0, 0,
			   0, 0, 0, 0, 0, 0, 0, 0};
bool d2[16] = {0, 0, 0, 0, 0, 0, 0, 0,
			   0, 0, 0, 0, 0, 0, 0, 0};
int qrow[8] = {0, 0, 0, 0, 0, 0, 0, 0};
int sol;
void paint(int r, int diag1, int diag2, bool busy){
	row[r] = d1[diag1] = d2[diag2] = busy;
}
void bt(int k){
	if(k == 8){
		printf("%2d     ", sol++);
		for(int i = 0; i < 8; ++i) printf(" %d", qrow[i]);
		putc(10, stdout);
		return;
	}
	if(qrow[k]){ bt(k + 1); return; }
	int diag1, diag2;
	for(int i = 0; i < 8; ++i){
		diag1 = 7 + i - k;
		diag2 = i + k;
		if(!row[i] && !d1[diag1] && !d2[diag2]){
			paint(i, diag1, diag2, 1);
			qrow[k] = i + 1;
			bt(k + 1);
			qrow[k] = 0;
			paint(i, diag1, diag2, 0);
		}
	}

}

int main(void){
	int c, n, r; scanf("%d", &n);
	while(n--){
		puts("SOLN       COLUMN");
		puts(" #      1 2 3 4 5 6 7 8\n");
		scanf("%d %d", &r, &c);
		sol = 1;
		paint(r - 1, 7 + r - c, r + c - 2, 1);
		qrow[c - 1] = r;
		bt(0);
		qrow[c - 1] = 0;
		paint(r - 1, 7 + r - c, r + c - 2, 0);
		if(n) putc(10, stdout);
	}
	return 0;
}
