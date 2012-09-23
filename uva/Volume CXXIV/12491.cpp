#include <cstdio>
#include <set>
#include <string>

using namespace std;

string A[32], B[32];
int n1, n2;
set < string > ss1, ss2;

int my_cmp(string a, string b){
	int sza = int(a.size()), szb = int(b.size());
	for(int i = 0; i < sza && i < szb; ++i)
		if(a[i] != b[i]) return -1;
	return sza > szb ? szb : sza;
}

bool bt(string s1, string s2){
	if(ss1.find(s1) != ss1.end() || ss2.find(s2) != ss2.end()) return false;
	int sz1 = int(s1.size()), sz2 = int(s2.size());
	bool found = false;
	if(!(sz1 | sz2)) return true;
	if(s1.size()){
		ss1.insert(s1);
		for(int i = 0, z; !found && i < n2; ++i){
			z = my_cmp(s1, B[i]);
			if(z != -1){
				if(z == sz1) found |= bt("", B[i].substr(z));
				else found |= bt(s1.substr(z), "");
			}
		}
	} else {
		ss2.insert(s2);
		for(int i =0, z; !found && i < n1; ++i){
			z = my_cmp(s2, A[i]);
			if(z != -1){
				if(z == sz2) found |= bt(A[i].substr(z), "");
				else found |= bt("", s2.substr(z));
			}
		}
	}
	return found;
}

int main(void){
	for(char word[64]; scanf("%d %d", &n1, &n2) == 2; ){
		bool possible = false;
		ss1.clear();
		ss2.clear();
		for(int i = 0; i < n1; ++i) scanf("%s", word), A[i] = word;
		for(int i = 0; i < n2; ++i) scanf("%s", word), B[i] = word;
		for(int i = 0; !possible && i < n1; ++i) possible |= bt(A[i], "");
		puts("N\0S" + (possible << 1));
	}
	return 0;
}

