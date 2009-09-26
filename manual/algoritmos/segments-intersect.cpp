bool on_segment(point i, point j, point k) {
	return min(i.x, j.x) <= k.x && k.x <= max(i.x, j.x)
			&& min(i.y, j.y) <= k.y && k.y <= max(i.y, j.y);
}

int direction(point a, point b, point c) {
	return cross(a, c, b);
}

/* true se os segmentos ab e cd intercedem */
bool segments_intersect(point a, point b, point c, point d) {
	int d1 = direction(c, d, a);
	int d2 = direction(c, d, b);
	int d3 = direction(a, b, c);
	int d4 = direction(a, b, d);

	if(((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0))
			&& ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0))) return true;
	if(d1 == 0 && on_segment(c, d, a)) return true;
	if(d2 == 0 && on_segment(c, d, b)) return true;
	if(d3 == 0 && on_segment(a, b, c)) return true;
	if(d4 == 0 && on_segment(a, b, d)) return true;

	return false;
}
