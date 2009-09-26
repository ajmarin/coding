/* q = CH(p) */
void jarvis_march(polygon &q, polygon &p) {
	bool used[M];
	int top, bottom;
	int current, next;
	int i;

	q.n = 0;

	top = bottom = 0;
	for(i = 0; i < p.n; i++) {
		used[i] = 0;
		if(p.p[top].y < p.p[i].y) top = i;
		if(p.p[bottom].y > p.p[i].y || (p.p[bottom].y == p.p[i].y && p.p[bottom].x > p.p[i].x)) bottom = i;
	}

	/* right-chain */
	current = bottom;
	while(current != top) {
		used[current] = 1;
		q.p[q.n].x = p.p[current].x;
		q.p[q.n].y = p.p[current].y;
		q.n++;
		next = top;
		for(i = 0; i < p.n; i++) {
			if(used[i]) continue;
			int t = cross(p.p[current], p.p[i], p.p[next]);
			if(t > 0) {
				next = i;
			} else if(t == 0 && distsqr(p.p[i], p.p[current]) > distsqr(p.p[next], p.p[current])) {
				next = i;
			}
		}
		current = next;
	}

	/* left-chain */
	current = top; /* ! */
	while(current != bottom) { /* ! */
		used[current] = 1;
		q.p[q.n].x = p.p[current].x;
		q.p[q.n].y = p.p[current].y;
		q.n++;
		next = bottom; /* ! */
		for(i = 0; i < p.n; i++) {
			if(used[i]) continue;
			int t = cross(p.p[current], p.p[i], p.p[next]);
			if(t > 0) {
				next = i;
			} else if(t == 0 && distsqr(p.p[i], p.p[current]) > distsqr(p.p[next], p.p[current])) {
				next = i;
			}
		}
		current = next;
	}
}
