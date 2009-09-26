void divbygcd(long long& a, long long& b) { 
	long long g = gcd(a, b); 
	a /= g; 
	b /= g; 
} 
long long C(int n, int k){ 
	long long numerator=1, denominator=1, toMul, toDiv, i; 
	if(k > n/2) k = n - k;				/* use smaller k */ 
	for(i = k; i; i--) { 
		toMul = n - k + i; 
		toDiv = i; 
		divbygcd(toMul, toDiv);			/* always divide before multiply */ 
		divbygcd(numerator, toDiv); 
		divbygcd(toMul, denominator); 
		numerator *= toMul; 
		denominator *= toDiv; 
	} 
	return numerator / denominator; 
}
