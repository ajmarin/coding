/////////////////////////////////
// 00105 - The Skyline Problem
/////////////////////////////////
#include<cstdio>
#include<cstring>
short int hcng[10004],hi,i,imax,li,ri,st;
int main(void){
	memset(hcng,0,sizeof(hcng));
	scanf("%hd %hd %hd\n",&li,&hi,&ri);
	st = li;
	imax = ri;
	for(i = li; i < ri; i++) hcng[i] = hi;
	while(scanf("%hd %hd %hd\n",&li,&hi,&ri)==3){
		if(ri > imax) imax = ri;
		for(i = li; i < ri; i++)
			if(hi > hcng[i]) hcng[i] = hi;
	}
	printf("%hd %hd",st,hcng[st]);
	for(i = st+1; i < imax+3; i++)
		if(hcng[i] != hcng[i-1])
			printf(" %hd %hd",i,hcng[i]);
	putchar('\n');
	return 0;
}
