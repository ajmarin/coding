#include<cstdio>
char i,num[127],tel[31];
int main(void){
	num['0'] = '0'; num['1'] = '1'; num['-'] = '-';
	num['A'] = num['B'] = num['C'] = '2';
	num['D'] = num['E'] = num['F'] = '3';
	num['G'] = num['H'] = num['I'] = '4';
	num['J'] = num['K'] = num['L'] = '5';
	num['M'] = num['N'] = num['O'] = '6';
	num['P'] = num['Q'] = num['R'] = num['S'] = '7';
	num['T'] = num['U'] = num['V'] = '8';
	num['W'] = num['X'] = num['Y'] = num['Z'] = '9';
	while(gets(tel)){
		for(i = 0; tel[i]; i++) tel[i] = num[tel[i]];
		printf("%s\n",tel);
	}
	return 0;
}
