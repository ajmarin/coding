/////////////////////////////////
// 00713 - Adding Reversed Numbers
/////////////////////////////////
#include<cstdio>
#include<cstring>
#include<vector>
char a[205], b[205],ans[205];
unsigned char l1, l2,i,j;
unsigned int c,cnum;
void add(){	
	l1 = strlen(a);
	l2 = strlen(b);
	c = 0;
	for(i = l1; i < l2; i++) a[i] = '0';
	for(i = l2; i < l1; i++) b[i] = '0';
	for(i = 0; i < l1 || i < l2; i++){
		c = (a[i]+b[i]+c-96);
		a[i] = c%10+'0';
		c/=10;
	}
	if(c) a[i++] = '1';
	a[i] = 0;
	b[l2] = 0;
}
int main(void){
	scanf("%u\n",&cnum);
	while(cnum--){
		scanf("%s %s\n",&a,&b);
		add();
		for(j = i-1; a[j] == '0'; j--);
		for(i = 0; a[i] == '0'; i++);		
		for(c = i; c <= j; c++) ans[c-i] = a[c];
		ans[c-i] = 0;
		printf("%s\n",ans);
	}
	return 0;
}