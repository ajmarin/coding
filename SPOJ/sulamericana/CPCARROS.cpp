#include <cstdio>
#include <cctype>
#include <cstring>
int corr[2][255];
bool e[255];
int calcV(char *p, bool f){
	int i, ret = 0, w = 1;
	int base, is, pot10, add;
	if(f){
		base = 21; is = 5; 
		add = 175760000; pot10 = 100;
	}
	else {
		base = 26; is = 3; 
		add = 0; pot10 = 10000;
	}
	for(i = is; i--; w*=base)
		ret += corr[f][p[i]]*w;
	ret *= pot10;
	for(i = is; pot10/=10; i++)
		ret += (p[i]-'0')*pot10;
	ret += add;
	return ret;
}
int main(void){
	int av, bv, i, n, val;
	bool valid;
	char a[10],b[10];
	memset(e,0,sizeof(e));
	for(i = '0'; i <= '9'; i++) e[i] = 1;
	e['A'] = e['C'] = e['I'] = e['M'] = e['P'] = 1;
	for(i = 'A', val = 0; i <= 'Z'; i++){
		corr[0][i] = i-'A';
		if(!e[i]) corr[1][i] = val++;	
	}
	while(scanf("%s %s %d",a,b,&n) && a[0] != '*'){
		valid = true;
		for(bv = i = 0; i < 3; i++)
			if(!isalpha(b[i])) valid = false;
			else bv++;
		bv += isalpha(b[3])+isalpha(b[4]);
		if(bv > 3){
			if(bv == 4) valid = false;
			for(i = 0; valid && i < 5; i++)
				valid ^= e[b[i]];
			if(!valid){ printf("N\n"); continue; }
			bv = calcV(b,1);
		} else bv = calcV(b,0);
		if(isalpha(a[3])) av = calcV(a,1);
		else av = calcV(a,0);
		if(bv <= av || bv > av+n) printf("N\n");
		else printf("Y\n");
	}
	return 0;
}

