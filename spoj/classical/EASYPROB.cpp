#include <cstdio>
#include <string>
using namespace std;
string r[15] = {"2(0)", "2"};
int list[7] = {137, 1315, 73, 136, 255, 1384, 16385}, p;
int main(void){
	for(int i = 2; i < 15; ++i){
		r[i] = ""; p = 0;
		for(int j = 0; 1 << j <= i; ++j)
			if(i & (1 << j))
				r[i] = r[j] + (p++?"+":"") + r[i];
		r[i] = "2(" + r[i] + ")";
	}
	for(int i = 0; i < 7; ++i){
		printf("%d=", list[i]);
		string rest = ""; p = 0;
		for(int c = 0, j = list[i]; j; j >>= 1, ++c)
			if(j & 1) rest = r[c] + (p++?"+":"") + rest;
		printf("%s\n", rest.c_str());
	}
	return 0;
}

