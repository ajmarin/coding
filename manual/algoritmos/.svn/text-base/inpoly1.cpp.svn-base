bool inpoly(polygon q, point p) {
	bool in = false;
	point a, b;
	int i, j, t;

	for(i = 0; i < q.n; i++) {
		j = (i+1) % q.n;
		if(q.p[j].x > q.p[i].x) {
			a = q.p[i];
			b = q.p[j];
		} else {
			a = q.p[j];
			b = q.p[i];
		}
		t = cross(a, b, p);
		if(t == 0 && on_segment(a, b, p)) return true; /* LADO! */
		if((q.p[j].x < p.x) == (p.x <= q.p[i].x) && t < 0)
			in = !in;
	}

	return in;
}
