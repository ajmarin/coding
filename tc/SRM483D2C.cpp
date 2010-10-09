#include <algorithm>
#include <cmath>
#include <cstdio>
#include <string>

using namespace std;

typedef string ret;
class BestApproximationDiv2 {
	public:
		ret findFraction(int, string);
};
int compare(int a, int b, string number){
	int idx = 0, r = 1, k;
	while(number[idx++] != '.');
	while(idx < number.size()){
		a = 10 * a;
		k = a / b;
		a -= k * b;
		if(k != number[idx] - '0') break;
		r++; idx++;
	}
	return r;
}
string itos(int x){
	if(x == 0) return string("0");
	string s = "";
	while(x){
		s += ((x % 10) + '0');
		x /= 10;
	}
	reverse(s.begin(), s.end());
	return s;
}
ret BestApproximationDiv2::findFraction(int maxden, string number){
	ret s;
	int a, frac[2], maxvalor = -1, p[3], q[3], valor;
	double r = 0, y = atof(number.c_str());
	a = floor(y);
	r = y - a;
	y = 1 / r;
	frac[0] = 0; frac[1] = 1;
	p[0] = 1; p[1] = 0;
	q[0] = 0; q[1] = 1;
	maxvalor = compare(0, 1, number);
	for(;;){
		a = floor(y);
		r = y - a;
		y = 1 / r;
		p[2] = a * p[1] + p[0];
		q[2] = a * q[1] + q[0];
		if(q[2] > maxden || q[2] < q[1]) break;
		p[0] = p[1]; p[1] = p[2];
		q[0] = q[1]; q[1] = q[2];
		if(q[1] != 0) valor = compare(p[1], q[1], number);
		if(valor > maxvalor){
			maxvalor = valor;
			frac[0] = p[1];
			frac[1] = q[1];
		}
	}
	s = itos(frac[0]) + string("/") + itos(frac[1]) + string(" has ") + itos(maxvalor) +
		string(" exact digits");

	return s;
}

