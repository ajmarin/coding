#include <cstdio>
#include <cstdlib>
#include <set>
#include <string>
using namespace std;
set < string > s;
char drink[1024];
int main(void){
	s.insert("ABSINTH");
	s.insert("BEER");
	s.insert("BRANDY");
	s.insert("CHAMPAGNE");
	s.insert("GIN");
	s.insert("RUM");
	s.insert("SAKE");
	s.insert("TEQUILA");
	s.insert("VODKA");
	s.insert("WHISKEY");
	s.insert("WINE");
	int c = 0, n; scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%s", drink);
		if(drink[0] >= '0' && drink[0] <= '9'){
			int x = atoi(drink);
			c += x < 18;
		} else c += s.find(string(drink)) != s.end();
	}
	printf("%d\n", c);
	return 0;
}

