#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

struct folder {
	map < string, int > sons;
	int files;
	folder(int _files = 0): files(_files) {}
} f[32768];
int fc = 0;
map < string, int > dir[5];
char ff[128], line[128];
int dfs(folder &cf, int &files){
	map< string, int>::iterator it; 
	int folders = 0;
	files += cf.files;
	for(it = cf.sons.begin(); it != cf.sons.end(); it++){
		folders += 1 + dfs(f[it->second], files);
	}
	return folders;
}
int main(void){
	folder *cf;
	string file;
	while(fgets(line, 128, stdin)){
		char *p = strtok(line, "\\");
		int dn = p[0] - 'C';
		p = strtok(NULL, "\\");
		if(dir[dn].count(p) == 1) cf = &f[dir[dn][p]];
		else cf = &f[(dir[dn][p] = fc++)];
		for(p = strtok(NULL, "\\"); p != NULL; ){
			file = p;
			if((p = strtok(NULL, "\\")) == NULL) break;
			if(cf->sons.count(file) == 1) cf = &f[cf->sons[file]];
			else cf = &f[(cf->sons[file] = fc++)];
		}
		cf->files++;
	}
	int max_files = 0, max_folders = 0;
	for(int i = 0; i < 5; ++i){
		map < string, int >::iterator it;
		for(it = dir[i].begin(); it != dir[i].end(); it++){
			int files = 0, folders = dfs(f[it->second], files);
			max_files = max(max_files, files);
			max_folders = max(max_folders, folders);
		}
	}
	printf("%d %d\n", max_folders, max_files);
	return 0;
}

