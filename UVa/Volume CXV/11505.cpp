/////////////////////////////////
// 11505 - LOGO
/////////////////////////////////
#include<cstdio>
#include<cmath>
#define conv 0.01745329251994329914588889
int c,i,n;
double posX, posY,dist,ang,qt;
char cmd[3];
int main(void){
	scanf("%d",&c);
	while(c){
		c--;
		posX = posY = ang = 0;
		scanf("%d",&n);		
		for(i = 0; i < n; i++){
			scanf("%s %lf",&cmd,&qt);
			if(cmd[0] == 'f'){
				posX += (qt*cos(ang*conv));
				posY -= (qt*sin(ang*conv));				
			}
			else if(cmd[0] == 'l') ang += qt;			
			else if(cmd[0] == 'r') ang -= qt;
			else {
				posX -= (qt*cos(ang*conv));
				posY += (qt*sin(ang*conv));
			}			
		}
		dist = sqrt(posX*posX+posY*posY);
		printf("%.0lf\n",dist);
	}
	return 0;
}
