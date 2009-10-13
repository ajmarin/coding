#include <algorithm>
#include <cctype>
#include <cstdio>

using namespace std;

#define IN getc ( stdin )

struct term {
	int c, xe, ye;
	term(int _c=0, int _xe=0, int _ye=0):c(_c),xe(_xe),ye(_ye){}
	bool operator<(const term k) const {
		return xe > k.xe || (xe == k.xe && ye < k.ye);
	}
	term operator*(const term k) {
		return term(c * k.c, xe + k.xe, ye + k.ye);
	}
	void clear(){ c = xe = ye = 0;}
};
struct pol { term t[1000]; int tc; } polA, polB, res;

void readPol(pol *pp){
	register char c = 0;
	int *k, sign = 1, v;
	while(c != '\n'){
		if(!c){
			c = IN;
			if(c != '-' && c != '+'){
				(*pp).tc++;
				(*pp).t[(*pp).tc].xe = (*pp).t[(*pp).tc].ye = 0;
				(*pp).t[(*pp).tc].c = 1;
				k = &((*pp).t[(*pp).tc].c);
			}
		}
		if(c == '-' || c == '+'){ 
			if(c == '-') sign = -1;
			else sign = 1;
			(*pp).tc++;
			(*pp).t[(*pp).tc].xe = (*pp).t[(*pp).tc].ye = 0;
			c = IN; k = &((*pp).t[(*pp).tc].c);
		} else if(c == 'x'){
			c = IN;	k = &((*pp).t[(*pp).tc].xe);
		} else if(c == 'y'){
			c = IN;	k = &((*pp).t[(*pp).tc].ye);
		} 
		if(!isdigit(c)) *k = 1;
		else {
			(*k) = 0; 
			do { (*k) = (*k) * 10 + (c - '0'); c = IN; }
			while(isdigit(c));
		}
		*k *= sign;
		sign = 1;
	}
	(*pp).tc++;
}
void sortClear(pol *pp){
	if(!(*pp).tc) return;
	sort((*pp).t, (*pp).t + (*pp).tc);
	for(int k = (*pp).tc; --k; )
		if((*pp).t[k].xe == (*pp).t[k-1].xe && 
			(*pp).t[k].ye == (*pp).t[k-1].ye){
			(*pp).t[k-1].c += (*pp).t[k].c;
			(*pp).t[k].clear();
		}
	for(int k = 0; k < (*pp).tc; ++k)
		if(!((*pp).t[k].c)) swap((*pp).t[k--],(*pp).t[--(*pp).tc]);
	if((*pp).tc) sort((*pp).t, (*pp).t + (*pp).tc);
}
char line[2][1024], s[15];
void itos(int k, char **f, char **g){
	char *p = s;
	while(k){ *p++ = (k % 10) + '0'; k /= 10; }
	for(int z = (p - s); z--; (*f)++, (*g)++) **f = ' ', **g = s[z];
}
int main(void){
	char c;
	while((c = IN) != '#'){
		ungetc(c, stdin);
		polA.tc = polB.tc = -1;
		res.tc = 0;
		readPol(&polA);
		sortClear(&polA);
		readPol(&polB);
		sortClear(&polB);
		for(int i = 0; i < polA.tc; ++i)
			for(int j = 0; j < polB.tc; ++j)
				res.t[res.tc++] = polA.t[i] * polB.t[j];
		sortClear(&res);
		register char *up = line[0], *dn = line[1];
		for(int i = 0; i < res.tc; ++i){
			if(!i && res.t[i].c < 0){ *up++ = ' '; *dn++ = '-';	}
			if(i){
				*up++ = *dn++ = ' '; *up++ = ' ';
				*dn++ = (res.t[i].c < 0 ? '-' : '+');
				*up++ = *dn++ = ' ';
			}
			if(res.t[i].c < 0) res.t[i].c *= -1; 
			if(res.t[i].c > 1 || (!res.t[i].xe && !res.t[i].ye))
				itos(res.t[i].c, &up, &dn);
			if(res.t[i].xe){
				*up++ = ' '; *dn++ = 'x';
				if(res.t[i].xe > 1) itos(res.t[i].xe, &dn, &up);
			}
			if(res.t[i].ye){
				*up++ = ' '; *dn++ = 'y';
				if(res.t[i].ye > 1) itos(res.t[i].ye, &dn, &up);
			}
		}
		*up = *dn = 0;
		puts(line[0]); puts(line[1]);
	}
	return 0;
}

