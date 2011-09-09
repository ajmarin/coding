#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <string>
#include <vector>
using namespace std;

#define RL(x)		readLine(x)
#define FOREACH(x)	for(typeof(x.begin()) it = x.begin(); it != x.end(); ++it)
struct driver {
	string cname, fname, lname;
	int pc[8], score;
	driver(string f, string l): fname(f), lname(l), score(0) {
		cname = fname + " " + lname;
		for(int i = 0; i < 8; ++i) pc[i] = 0;
	}
	bool operator<(driver d) const {
		if(score < d.score) return false;
		if(score > d.score) return true;
		for(int i = 0; i < 8; ++i)
			if(pc[i] != d.pc[i]) return pc[i] > d.pc[i];
		return lname < d.lname || (lname == d.lname && fname < d.fname);
	}
};
struct team {
	string name;
	int score;
	team(string s): name(s), score(0) {}
	bool operator<(team t) const {
		return score > t.score || (score == t.score && name < t.name);
	}
};
int readLine(char *s){
	int read = 1;
	char c = getc(stdin);
	if(c == '\n' || c == EOF) return -(c == EOF);
	for(*s++ = c; (c = getc(stdin)) != '\n'; *s++ = c, ++read);
	*s = 0;
	return read;
}
map < string, int > dname, tname;
int score[10] = {0, 10, 8, 6, 5, 4, 3, 2, 1, 0};
char line[1024];
int main(void){
	setvbuf(stdout, NULL, _IONBF, NULL);
	for(int n, season(1); RL(line) > 0 && sscanf(line, "%d", &n) == 1 && n; season++){
		int dtotal(0), ttotal(0);
		dname.clear();
		tname.clear();
		vector < driver > drivers;
		vector < team > teams;
		while(n--){
			RL(line); RL(line);
			while(RL(line) > 0 && strcmp(line, "---")){
				string dfn = "", dln = "", tn = "";
				int cnt(0), pos;
				char *ptr = strtok(line, " ");
				for( ; ptr != NULL; ptr = strtok(NULL, " "), ++cnt){
					if(!cnt) pos = atoi(ptr);
					else if(cnt == 1) dfn = string(ptr);
					else if(cnt == 2) dln = string(ptr);
					else tn += string(ptr) + " ";
				}
				tn = tn.substr(0, tn.size()-2);
				int &didx = dname[dfn+" "+dln], &tidx = tname[tn];
				if(!didx){
					didx = ++dtotal;
					drivers.push_back(driver(dfn, dln));
				}
				if(!tidx){
					tidx = ++ttotal;
					teams.push_back(team(tn));
				}
				drivers[didx-1].score += score[pos];
				++drivers[didx-1].pc[pos-1];
				teams[tidx-1].score += score[pos];
			}
		}
		printf("Season %d:\n", season);
		sort(drivers.begin(), drivers.end());
		sort(teams.begin(), teams.end());
		puts("Drivers Standing:");
		FOREACH(drivers) printf("%-25s %d\n", (it -> cname).c_str(), it -> score);
		puts("\nTeams Standing:");
		FOREACH(teams) printf("%-25s %d\n", (it -> name).c_str(), it -> score);
		puts("");
	}
	return 0;
}

