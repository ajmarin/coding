#include <cstdio>
#include <map>
#include <string>
#include <cstring>
using namespace std;

map < string, int > m;

int main(void){
	m["ACDT"] = 630; m["ACST"] = 570; m["ADT"] = -180; m["AEDT"] = 660;
	m["AEST"] = 600; m["AKDT"] = -480; m["AKST"] = -540; m["AST"] = -240;
	m["AWST"] = 480; m["BST"] = 60; m["CDT"] = -300; m["CEST"] = 120;
	m["CET"] = 60; m["CST"] = -360; m["EDT"] = -240; m["EEST"] = 180;
	m["EET"] = 120; m["EST"] = -300; m["GMT"] = 0; m["HST"] = -600;
	m["IST"] = 60; m["MDT"] = -360; m["MSD"] = 240; m["MSK"] = 180;
	m["MST"] = -420; m["NDT"] = -150; m["NST"] = -210; m["PDT"] = -420;
	m["PST"] = -480; m["UTC"] = 0; m["WEST"] = 60; m["WET"] = 0;
	int t; scanf("%d", &t);
	while(t--){
		char ampm[16], from[16], time[16], to[16];
		int a, b, z;
		scanf("%s", time);
		if(!strcmp(time, "noon") || !strcmp(time, "midnight")){
			if(*time == 'm') z = 0;
			else z = 720;
		} else {
			sscanf(time, "%d:%d", &a, &b);
			z = 60 * (a % 12) + b;
			scanf("%s", ampm);
			if(*ampm == 'p') z += 720;
		}
		scanf("%s %s", from, to);
		z = z + m[to] - m[from] + 2880;
		int h = (z / 60) % 24, m = z % 60;
		if(m || h % 12) printf("%d:%02d %c.m.\n", h % 12 + 12 * !(h % 12), m, h >= 12 ? 'p' : 'a');
		else puts(h ? "noon" : "midnight");
	}
	return 0;
}

