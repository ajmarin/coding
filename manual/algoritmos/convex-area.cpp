double polygon_area(polygon q) {
	double r = 0.0;
	int i, j;
	for(i = 0; i < q.n; i++) {
		j = (i+1) % q.n;
		r += q.p[i].x * q.p[j].y - q.p[j].x * q.p[i].y;
	}
	return r/2.0;
}
