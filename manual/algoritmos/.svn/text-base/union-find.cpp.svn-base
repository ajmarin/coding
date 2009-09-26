#define MAX 100000
int p[MAX], rank[MAX], len[MAX];

void makeset(int x) {
	p[x] = x;
	len[x] = 1;
	rank[x] = 0;
}

int findset(int x) {
	if(x != p[x])
		p[x] = findset(p[x]);
	return p[x];
}

void linkset(int x, int y) {
	if(rank[x] > rank[y]) {
		p[y] = x;
		len[x] += len[y];
	} else {
		p[x] = y;
		len[y] += len[x];
		if(rank[x] == rank[y])
			rank[y]++;
	}
}

void unionset(int x, int y) {
	linkset(findset(x), findset(y));
}

int sizeset(int x) {
	return len[findset(x)];
}
