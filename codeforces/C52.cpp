#include <cstdio>
#include <map>
#include <string>
using namespace std;
map < string, int > m;
int n = 0;
char name[32];
bool capital(char x){ return x >= 'A' && x <= 'Z'; }
void readEmployee(){
	string s = "";
	char c;
	while(capital(c = getc(stdin))) s.push_back(c);
	n += m[s]++;
	if(c == ':') while(c != '.') readEmployee(), c = getc(stdin);
	m[s]--;

}
int main(void){
	readEmployee();
	printf("%d\n", n);
	return 0;
}

