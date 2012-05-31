#include <cstdio>
#include <cstring>

struct area { 
	char code[16], name[32];
	int cl, cost;
} a[1 << 15];

bool match(char *a, char *b){
	int lena = strlen(a);
	int lenb = strlen(b);
	int d = lenb - lena;
	return (a[0] == '0' && d >= 4 && ((a[1] == '0' && d <= 10) || (a[1] != '0' && d <= 7)) &&
			!strncmp(a, b, lena));
}

int main(void){
	int an = 0, duration, i;
	char dial[16];
	const char *format = "%-15s %-25s%10s%5d%3d.%02d%4d.%02d\n";
	const char *ukfmt = "%-15s %-25s            %3d        -1.00\n";
	for(scanf("%s", a[an].code); strcmp(a[an].code, "000000"); scanf("%s", a[++an].code)){
		scanf(" %[^$]$%d", a[an].name, &a[an].cost);
		a[an].cl = strlen(a[an].code);
	}
	for(scanf("%s", dial); *dial != '#'; scanf("%s", dial)){
		scanf("%d", &duration);
		if(*dial != '0') // Local call
			printf(format, dial, "Local", dial, duration, 0, 0, 0, 0);
		else {
			for(i = 0; i < an && !match(a[i].code, dial); ++i);
			int c = a[i].cost;
			if(i == an) printf(ukfmt, dial, "Unknown", duration);
			else printf(format, dial, a[i].name, dial + a[i].cl, duration, c / 100, c % 100,
					duration * c / 100, (duration * c) % 100);
		}
	}
	return 0;
}

