/////////////////////////////////
// 00573 - The Snail
/////////////////////////////////
#include<cstdio>
#include<cmath>
unsigned short fall,hght,sld,i;
float prc,c_cp,dc,chght;
bool conquer;
int main(void){
	while(scanf("%u %f %u %f",&hght,&c_cp,&sld,&prc) && hght){
		dc = c_cp*prc/100;
		chght = conquer = i = 0;
		while(true){
			chght += c_cp;
			if(chght > hght){
				printf("success on day %u\n",i+1); 
				break;
			}
			c_cp -= dc;
			chght -= sld;
			if(chght < 0){
				printf("failure on day %u\n",i+1);
				break;
			}			
			i++;
			if(c_cp < 0){
				fall = (int)(ceil(chght/sld));
				if(sld*fall < chght) fall++;
				printf("failure on day %u\n",i+1+fall);
				break;
			}				
		}
	}
	return 0;
}

