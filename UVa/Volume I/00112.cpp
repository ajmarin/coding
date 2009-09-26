/////////////////////////////////
// 00112 - Tree Summing
/////////////////////////////////
#include<cstdio>
#include<cctype>
#include<cstring>
int l,root,sign;
bool yes, digit[60];
char c;
void readsons(int csum){
	bool hasleft,hasright;
	int left,right,sign;
	//printf("csum = %d\n",csum);
	hasleft = left = hasright = right = 0;
	while(c!='(') c = getc(stdin);
	sign = 1;
	c = ' ';while(c==' ') c = getc(stdin);
	if(c != ')'){
		hasleft = 1;
		if(c=='-') { sign = -1; c = getc(stdin);}
		while(digit[c]){			
			left*=10; left+=(c-'0');
			c = getc(stdin);
		}
		readsons(csum+left*sign);
	}
	while(c!=')') c = getc(stdin);	
	while(c!='(') c = getc(stdin);	
	c = ' ';while(c==' ') c = getc(stdin);
	sign = 1;
	if(c != ')'){
		hasright = 1;
		if(c=='-') { sign = -1; c = getc(stdin);}
		while(digit[c]){			
			right*=10; right+=(c-'0');
			c = getc(stdin);
		}
		readsons(csum+right*sign);
	}
	while(c!=')') c = getc(stdin);	
	if(!hasleft && !hasright && csum==l) yes = 1;
}
void clear(){
	while(c = getc(stdin))
		switch(c){
			case ' ':case '(':case')':case'\n':case 13: break;
			default: return;
		}
}
int main(void){
	memset(digit,0,sizeof(digit));
	digit['0'] = digit['1'] = digit['2'] = digit['3'] = digit['4'] = 1;
	digit['5'] = digit['6'] = digit['7'] = digit['8'] = digit['9'] = 1;
	while(scanf("%d",&l)==1){
		sign = 1;
		yes = root = 0;
		while((c=getc(stdin))!='(');
		c = ' ';	while(c == ' ') c = getc(stdin);
		if(c != ')'){
			if(c == '-'){ sign = -1; c = getc(stdin);}
			while(digit[c]){
				root*=10; root+=(c-'0');
				c = getc(stdin);
			}
			readsons(root*sign);
		}
		if(yes) printf("yes\n");
		else printf("no\n");
		clear();
		ungetc(c,stdin);
	}
	return 0;
}