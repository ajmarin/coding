#include <cstdio>
#include <deque>
#include <string>
using namespace std;

int main(void){
	for(char c, line[1048576]; gets(line); ){
		bool home = false;
		deque < string > deq;
		string current;
		for(int i = 0; c = line[i]; ++i){
			switch(c){
				case '[':
					if(home) deq.push_front(current);
					else deq.push_back(current);
					home = true;
					current = "";
					break;
				case ']':
					if(home && current != ""){
						deq.push_front(current);
						current = "";
					}
					home = false;
					break;
				default:
					current.push_back(c);
					break;
			}
		}
		if(current != ""){
			if(home) deq.push_front(current);
			else deq.push_back(current);
		}
		while(!deq.empty()){
			printf("%s", deq.front().c_str());
			deq.pop_front();
		}
		puts("");
	}
	return 0;
}

