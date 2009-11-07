/////////////////////////////////
// 00119 - Greedy Gift Givers
/////////////////////////////////
#include<cstdio>
#include<cstring>
char name[10][13], giving[13], receiving[13];
int balance[10];
unsigned char people,i,j;
unsigned int money,split;
int search(const char *who){
	int s = 0;
	while(strcmp(who,name[s])) s++;
	return s;
}
int main(void){
	scanf("%u",&people);
	while(1){
		for(i = 0; i != people; balance[i] = 0,i++)
			scanf("%s",&name[i]);
		for(i = 0; i != people; i++){
			scanf("%s %d %d",&giving,&money,&split);
			if(split){
				money/=split;
				balance[search(giving)] -= (money*split);
				for(j = 0; j != split; j++){
					scanf("%s",&receiving);
					balance[search(receiving)]+=money;
				}
			}
		}
		for(i = 0; i != people; i++)
			printf("%s %d\n",name[i],balance[i]);
		if(scanf("%u",&people)==1)  putchar('\n');
		else break;
	}
	return 0;
}
