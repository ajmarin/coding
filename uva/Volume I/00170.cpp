/////////////////////////////////
// 00170 - Clock Patience
/////////////////////////////////
#include<cstdio>
#include<cstring>
int atual,exposed,head[13],i,j,k,n,q[13][4],tail[13];
char a,b,c, *ptr, line[100];
char fc(int a){
	if(a == 1) return 'A';
	if(a < 10) return '0'+a;
	if(a == 10) return 'T';
	if(a == 11) return 'J';
	if(a == 12) return 'Q';
	return 'K';
}
char np(int a){
	if(a == 1) return 'C';
	if(a == 2) return 'D';
	if(a == 3) return 'H';
	return 'S';
}
void push(){
	a = ptr[0]; b = ptr[1];
	if(a == 'A') n = 5;
	else if(a == 'T') n = 50;
	else if(a == 'J') n = 55;
	else if(a == 'Q') n = 60;
	else if(a == 'K') n = 65;
	else n = 5*(a - '0');
	if(b == 'C') n += 1;
	else if(b == 'D') n += 2;
	else if(b == 'H') n += 3;
	else if(b == 'S') n += 4;
	q[j][tail[j--]++] = n;
}
int pop(){
	k = q[atual][head[atual]];
	exposed++;
	return (q[atual][head[atual]++]/5 - 1);
}
int main(void){
	gets(line);
	while(true){
		if(line[0] == '#') break;
		for(i = 0; i < 13; head[i] = tail[i] = 0, i++);
		for(i = 0; i < 4; i++){			
			ptr = strtok(line," ");
			j = 12;
			while(ptr != NULL){
				push();
				ptr = strtok(NULL," ");				
			}
			gets(line);
		}	
		atual = 12;
		exposed = 0;	
		while(head[atual] < 4) atual = pop();
		a = fc(k/5);
		b = np(k%5);
		printf("%.2d,%c%c\n",exposed,a,b);
	}
}