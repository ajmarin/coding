string fill(char c, int n) {
	string s;
	while(n--) s += c;
	return s;
}

string toRoman(int n) {
	if(n < 4) return fill('i', n);
	if(n < 6) return fill('i', 5 - n) + "v";
	if(n < 9) return string("v") + fill('i', n - 5);
	if(n < 11) return fill('i', 10 - n) + "x";
	if(n < 40) return fill('x', n / 10) + toRoman(n % 10);
	if(n < 60) return fill('x', 5 - n / 10) + 'l' + toRoman(n % 10);
	if(n < 90) return string("l") + fill('x', n / 10 - 5) + toRoman(n % 10);
	if(n < 110) return fill('x', 10 - n / 10) + "c" + toRoman(n % 10);
	if(n < 400) return fill('c', n / 100) + toRoman(n % 100);
	if(n < 600) return fill('c', 5 - n / 100) + 'd' + toRoman(n % 100);
	if(n < 900) return string("d") + fill('c', n / 100 - 5) + toRoman(n % 100);
	if(n < 1100) return fill('c', 10 - n / 100) + "m" + toRoman(n % 100);
	if(n < 4000) return fill('m', n / 1000) + toRoman(n % 1000);
	return "?";
}

