/////////////////////////////////
// 00446 - Kibbles "n" Bits "n" Bits "n" Bits
/////////////////////////////////
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
char sig;
int a,b,cases,i;
string sol;
string bin( int x){
    sol = "";
    do sol.push_back((x&1) + '0'); while(x>>=1);   
    reverse( sol.begin(), sol.end() );
    string k(13-sol.size(),'0');
    return k+sol;
}
int main(void){
	scanf("%d\n",&cases);
	while(scanf("%x %c %x\n",&a,&sig,&b)!=EOF)
		printf("%s %c %s = %d\n",bin(a).c_str(),sig,bin(b).c_str(),(sig == '+'? a+b:a-b));
	return 0;
}

