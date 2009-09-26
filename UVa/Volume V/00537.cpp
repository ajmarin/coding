#include <cstdio>
#include <cctype>

double I, P, U, val;
bool def[255];
char unit[128];

void getD(double *k){
	*k = 0.;
	register char x;
	while(isdigit(x = getc( stdin ))){
		(*k) *= 10.;
		(*k) += (x - '0');
	}
	if(x == '.'){
		double div = 10.;
		while(isdigit(x = getc( stdin ))){
			(*k) += (x - '0')/div;
			div *= 10.;
		}
	}
	if(x == 'm')	  (*k) /= 1000.;
	else if(x == 'k') (*k) *= 1000.;
	else if(x == 'M') (*k) *= 1000000.;
}
void getVal(){
	register char c, p;
	while((c = getc( stdin )) != '=') p = c;
	def[p] = 1;
	switch(p){
		case 'I': getD(&I); break;
		case 'P': getD(&P); break;
		case 'U': getD(&U); break;
	}
}
int main(void){
	int T;
	char c;
	scanf("%d",&T);
	unit['I'] = 'A'; unit['P'] = 'W'; unit['U'] = 'V';
	for(int pnum = 0; pnum < T; ){
		def['I'] = def['P'] = def['U'] = 0;
		getVal();
		getVal();
		if(def['I']){
			if(def['P']) c = 'U', val = P/I;
			else 		 c = 'P', val = I*U;
		} else c = 'I', val = P/U;
		printf("Problem #%d\n%c=%.2lf%c\n\n",++pnum,c,val,unit[c]);
	}
	return 0;
}

