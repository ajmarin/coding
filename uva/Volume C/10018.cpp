/////////////////////////////////
// 10018 - Reverse and Add
/////////////////////////////////
#include<cstdio>
#include<cstring>
int cases;
char a[11],rev[11],v[11],i,j,len,n,temp,carry;
bool palindrome(void){
	j = 10-len;
	i = 9;
	while(i >= j) {
		if(v[i--] != v[j++]) return 0;
	}
	return 1;	
}
void revadd(void){
	n = 0;
	do{
		strcpy(rev,v);
		j = 10-len; i = 9;
		while(i >= j){
			temp = rev[i];
			rev[i--] = rev[j];
			rev[j++] = temp;
		}
		j = 9-len;
		for(carry = 0,i = 9; i > j; i--){
			temp = v[i]-'0';
			v[i] = (rev[i]+v[i]+carry-'0'-'0')%10+'0';
			carry = (temp+rev[i]+carry-'0')/10;
		}
		if(carry){
			v[i] = '1';
			len++;
		}
		n++;
	} while(!palindrome());
}
int main(void){
	scanf("%d",&cases);
	while(cases--){
		scanf("%s",&a);
		memset(v,'.',11);
		len = strlen(a);
		strcpy(v+10-len,a);
		revadd();
		printf("%d %s\n",n,v+10-len);
	}
	return 0;
}	
	
