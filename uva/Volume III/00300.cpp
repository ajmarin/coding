#include <cstdio>
#include <map>
#include <string>
using namespace std;
map < string, int > m;
const char *dayname[20] = {"imix", "ik", "akbal", "kan", "chicchan",
						   "cimi", "manik", "lamat", "muluk", "ok",
						   "chuen", "eb", "ben", "ix", "mem",
						   "cib", "caban", "eznab", "canac", "ahau"};
int main(void){
	m[string("ceh")] = 11; m[string("chen")] = 8; m[string("cumhu")] = 17;
	m[string("kankin")] = 13; m[string("koyab")] = 16; m[string("mac")] = 12;
	m[string("mol")] = 7; m[string("muan")] = 14; m[string("no")] = 1;
	m[string("pax")] = 15; m[string("pop")] = 0; m[string("tzec")] = 4;
	m[string("uayet")] = 18; m[string("xul")] = 5; m[string("yax")] = 9;
	m[string("yoxkin")] = 6; m[string("zac")] = 10; m[string("zip")] = 2;
	m[string("zotz")] = 3;
	int day, nd, t, year; scanf("%d", &t);
	char mnt[32];
	printf("%d\n", t);
	while(t--){
		scanf("%d. %s %d", &day, mnt, &year);
		nd = 365 * year + m[string(mnt)] * 20 + day;
		printf("%d %s %d\n", ((nd % 260) % 13) + 1, dayname[(nd % 260) % 20], nd / 260);
	}
	return 0;
}

