#include <algorithm>
#include <vector>

point pivot;

bool graham_cmp(point a, point b) {
	int t = cross(pivot, b, a);
	if(t < 0) return true;
	if(t == 0) return distsqr(pivot, a) < distsqr(pivot, b);
	return false;
}

/* q = CH(p) */
void graham_scan(polygon &q, polygon &p) {
	vector<point> s(p.p, p.p+p.n);
	int i;

	/* pivot = ponto mais abaixo e mais a esquerda */
	pivot = p.p[0];
	for(i = 1; i < p.n; i++)
		if(p.p[i].y < pivot.y || (p.p[i].y == pivot.y && p.p[i].x < pivot.x))
			pivot = p.p[i];

	/* ordena s no sentido anti-horario, com relacao ao pivot */
	sort(s.begin(), s.end(), graham_cmp);

	/* remove elementos repetidos de s */
	for(i = 2; i < (int)s.size(); i++)
		if(cross(pivot, s[i], s[i-1]) == 0)
			s.erase(s.begin() + --i);

	/* here comes the fun */
	q.p[0] = s[0];
	q.p[1] = s[1];
	q.p[2] = s[2];
	q.n = 3;
	for(i = 3; i < (int)s.size(); i++) {
		while(cross(q.p[q.n-2], q.p[q.n-1], s[i]) <= 0) q.n--;
		q.p[q.n++] = s[i];
	}
}
