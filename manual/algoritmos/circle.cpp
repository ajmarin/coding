/* c = circulo que passa por a, b e tem raio r (ordem a, b importa) */
bool circle2ptsRad(point a, point b, double r, circle &c) {
	double det = r*r/distsqr(a, b) - 0.25;
	if(det < 0) return false;
	double h = sqrt(det);
	c.r = r;
	c.c.x = (a.x + b.x)*0.5 + (a.y - b.y)*h;
	c.c.y = (a.y + b.y)*0.5 + (b.x - a.x)*h;
	return true;
}

/* circulo por 3 pontos (shygypsy), TODO: mudar pro formato do nosso manual */
bool lineIntersect(double x[], double y[], double r[]) {
	double n[2]; n[0] = y[3] - y[2]; n[1] = x[2] - x[3];
	double denom = n[0] * (x[1] - x[0]) + n[1] * (y[1] - y[0]);
	if(fabs(denom) < EPS) return false;
	double num = n[0] * (x[0] - x[2]) + n[1] * (y[0] - y[2]);
	double t = -num / denom;
	r[0] = x[0] + t * (x[1] - x[0]);
	r[1] = y[0] + t * (y[1] - y[0]);
	return true;
}

double circle3pts(double x[], double y[], double r[]) {
	double lix[4], liy[4];
	lix[0] = 0.5 * (x[0] + x[1]); liy[0] = 0.5 * (y[0] + y[1]);
	lix[1] = lix[0] + y[1] - y[0];  liy[1] = liy[0] + x[0] - x[1];
	lix[2] = 0.5 * (x[1] + x[2]); liy[2] = 0.5 * (y[1] + y[2]);
	lix[3] = lix[2] + y[2] - y[1];  liy[3] = liy[2] + x[1] - x[2];
	if(!lineIntersect(lix, liy, r)) return -1.0;
	return sqrt((r[0] - x[0]) * (r[0] - x[0]) + (r[1] - y[0]) * (r[1] - y[0]));
}
