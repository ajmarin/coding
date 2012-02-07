#include <cstdio>

int main(void){
	for(char line[1024]; fgets(line, 1024, stdin) && *line != 'G'; ){
		char p = 0, pp = 0;
		int pnum = 0, points = 0, roll = 0, rp;
		for(int i = 0; line[i]; ++i){
			if(line[i] != ' ' && line[i] != '\n'){
				if(line[i] >= '0' && line[i] <= '9') rp = line[i] - '0';
				else if(line[i] == '/') rp = 10 - (p - '0');
				else if(line[i] == 'X') rp = 10;
				points += rp * ((roll < 10) + (p == '/' || p == 'X') + (pp == 'X'));
				pp = p;
				p = line[i];
				if(roll >= 10 && (line[i] == '/' || line[i] == 'X')) p = '_';
				if(line[i] >= '0' && line[i] <= '9'){ roll += pnum; pnum = 1 - pnum; }
				else { pnum = 0; ++roll; }
			}
		}
		printf("%d\n", points);
	}
	return 0;
}

