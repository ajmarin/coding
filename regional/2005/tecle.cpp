#include <cstdio>

long long s; int d;
int num_sol;

int adj[10][8] = {{7, 8, 9, 0, 0, 0, 0, 0}, {2, 4, 5, 0, 0, 0, 0, 0}, {1, 3, 4, 5, 6, 0, 0, 0}, {2, 5, 6, 0, 0, 0, 0, 0}, {1, 2, 5, 7, 8, 0, 0, 0}, {1, 2, 3, 4, 6, 7, 8, 9}, {2, 3, 5, 8, 9, 0, 0, 0}, {0, 4, 5, 8, 0, 0, 0, 0}, {0, 4, 5, 6, 7, 9, 0, 0}, {0, 5, 6, 8, 0, 0, 0, 0}};
int adjn[10] = {3, 3, 5, 3, 5, 8, 5, 4, 6, 4};

long long seqsum(int i, int seq[10], int d) {
	long long total, sum;
	sum = total = 0;
	for(int j = 0; j < i; j++) {
		if(j % d == 0) {
			total += sum;
			sum = 0;
		}
		sum *= 10;
		sum += seq[j];
	}
	total += sum;
	return total;
}

void imprimeseq(int i, int seq[10], int d) {
	num_sol++;
	for(int j = 0; j < i; j++) {
		if(j % d == 0 && j > 0) printf(" ");
		printf("%d", seq[j]);
	}
	printf("\n");
}

void backtrack(int i, int seq[10], bool usado[10]) {
	long long soma = seqsum(i, seq, d);
	int j, k;

	if(soma > s) return;
	else {
		if(soma == s) imprimeseq(i, seq, d);
		int newseq[10];
		for(j = 0; j < i; j++) newseq[j] = seq[j];
		for(j = 0; j < adjn[seq[i-1]]; j++) {
			bool newusado[10];
			for(k = 0; k < 10; k++) newusado[k] = usado[k];
			k = adj[seq[i-1]][j];
			if(usado[k]) continue;
			newseq[i] = k;
			newusado[k] = true;
			backtrack(i+1, newseq, newusado);
		}
	}
}

int main(void) {
	for(int ncase = 1; scanf("%Ld %d", &s, &d); ncase++) {
		if(s == -1 && d == -1) break;

		num_sol = 0;
		printf("#%d\n", ncase);
		for(int i = 0; i < 10; i++) {
			int seq[10] = {i, 0, 0, 0, 0, 0, 0, 0, 0, 0};
			bool us[10];
			for(int j = 0; j < 10; j++) us[j] = j == i;
			backtrack(1, seq, us);
		}
		if(num_sol == 0) printf("impossivel\n");
	}

	return 0;
}
