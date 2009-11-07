/////////////////////////////////
// 11219 - How old are you?
/////////////////////////////////
#include<cstdio>
unsigned short int b[3],c[3],age;
unsigned int cnum,tnum=0;
int main(void){
	scanf("%u",&cnum);
	while(cnum--){
		tnum++;
		scanf("%2hu/%2hu/%4hu\n",&c[0],&c[1],&c[2]);
		scanf("%2hu/%2hu/%4hu\n",&b[0],&b[1],&b[2]);
		if(c[2] < b[2] || (c[2] == b[2] && (c[1] < b[1] || (c[1] == b[1] && c[0] < b[0]))))
			printf("Case #%u: Invalid birth date\n",tnum);
		else {
			age = c[2] - b[2];
			if(c[1] < b[1] || (c[1] == b[1] && c[0] < b[0]))
				age--;
			if(age>130) 
				printf("Case #%u: Check birth date\n",tnum);
			else 
				printf("Case #%u: %u\n",tnum,age);
		}
	}
	return 0;
}
	
