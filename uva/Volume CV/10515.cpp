/////////////////////////////////
// 10515 - Powers Et Al.
/////////////////////////////////
#include<cstdio>
#include<cstring>
char i,lastdigit,lenm,lenn,m[105],mod4,n[105];
char last[][4] = {{0,0,0,0},{1,1,1,1},{6,2,4,8},{1,3,9,7},{6,4,6,4},
				{5,5,5,5},{6,6,6,6},{1,7,9,3},{6,8,4,2},{1,9,1,9}};
int main(void){
	while(scanf("%s %s",&m,&n) && (m[0]!='0' || n[0]!='0')){
		lenm = strlen(m);
		lastdigit = m[lenm-1]-'0';
		if(n[0] == '0') printf("1\n");
		else {
			for(mod4 = i = 0; n[i]; i++) mod4 = (mod4*10+n[i]-'0')%4;
			printf("%u\n",last[lastdigit][mod4]);
		}
	}
	return 0;
}
