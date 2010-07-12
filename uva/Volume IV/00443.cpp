/////////////////////////////////
// 00443 - Humble Numbers
/////////////////////////////////
#include<cstdio>
#include<algorithm>
#define BI2 2000000000
long long h[5843],res2,res3,res5,res7;
char i,j,k,l;
unsigned int idx,m2[31],m3[20],m5[14],m7[12],sidx;
const char *suf[] = {"th","st","nd","rd","th","th","th","th","th","th"};
int main(void){
	m2[0] = m3[0] = m5[0] = m7[0] = idx = 1;
	for(i = 1; i < 31; i++) m2[i] = m2[i-1]<<1;
	for(i = 1; i < 20; i++) m3[i] = 3*m3[i-1];
	for(i = 1; i < 14; i++) m5[i] = 5*m5[i-1];
	for(i = 1; i < 12; i++) m7[i] = 7*m7[i-1];
	for(i = 0; i < 31; i++){
		res2 = m2[i];
		for(j = 0; j < 20; j++){
			res3 = res2*m3[j];
			if(res3 > BI2) continue;
			for(k = 0; k < 14; k++){
				res5 = res3*m5[k];
				if(res5 > BI2) continue;
				for(l = 0; l < 12; l++){
					res7 = res5*m7[l];
					if(res7 > BI2) continue;					
					h[idx++] = res7;
				}
			}
		}
	}
	std::sort(h+1,h+5843);
	while(scanf("%u",&idx) && idx){
		sidx = idx%10;
		if(idx%100 < 14 && idx%100 > 10) sidx = 4;
		printf("The %u%s humble number is %llu.\n",idx,suf[sidx],h[idx]);
	}
	return 0;
}
