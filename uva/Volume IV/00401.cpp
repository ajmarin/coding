/////////////////////////////////
// 00401 - Palindromes
/////////////////////////////////
#include<cstdio>
#include<cstring>
char curr[25];
int i,n,mirror[128];
bool palindrome, mirrored;
void build(){
	mirror['A'] = 'A'; mirror['E'] = '3'; mirror['H'] = 'H';
	mirror['I'] = 'I'; mirror['J'] = 'L'; mirror['L'] = 'J';
	mirror['M'] = 'M'; mirror['O'] = 'O'; mirror['S'] = '2';
	mirror['T'] = 'T'; mirror['U'] = 'U'; mirror['V'] = 'V';
	mirror['W'] = 'W'; mirror['X'] = 'X'; mirror['Y'] = 'Y';
	mirror['Z'] = '5'; mirror['1'] = '1'; mirror['2'] = 'S';
	mirror['3'] = 'E'; mirror['5'] = 'Z'; mirror['8'] = '8';
}
int main(void){
	build();
	while(gets(curr)){
		n = strlen(curr);
		palindrome = mirrored = 1;
		for(i = 0; i < n/2; i++){			
			if(palindrome)
				if(curr[i] != curr[n-1-i]) palindrome = 0;
			if(mirrored)
				if(mirror[curr[i]] != curr[n-1-i]) mirrored = 0;
			if(!(mirrored || palindrome)) break;
		}
		if(n%2!=0 && mirror[curr[n/2]] != curr[n/2]) mirrored = 0;
		if(!mirrored && !palindrome) printf("%s -- is not a palindrome.\n\n",curr);
		else if(mirrored && palindrome) printf("%s -- is a mirrored palindrome.\n\n",curr);
		else if(mirrored) printf("%s -- is a mirrored string.\n\n",curr);
		else printf("%s -- is a regular palindrome.\n\n",curr);
	}
	return 0;
}