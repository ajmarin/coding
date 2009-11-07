#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct cube { char st[7]; } c[2];

void cycswp(cube *k, int a, int b, int c, int d){
	char x = (*k).st[a];
	(*k).st[a] = (*k).st[b];
	(*k).st[b] = (*k).st[c];
	(*k).st[c] = (*k).st[d];
	(*k).st[d] = x;
}

void rotateX(cube *k){ cycswp(k,1,2,4,3);}
void rotateY(cube *k){ cycswp(k,0,1,5,4);}
void rotateZ(cube *k){ cycswp(k,0,2,5,3);}

bool readCube(cube *x){
	char i;
	for(i = 0; i < 6; i++)
		(*x).st[i] = getc ( stdin );
	(*x).st[i--] = 0;
	return (*x).st[i] != EOF;
}
int main(void){
	bool m;
	char cc[2][10];
	while(readCube(&c[0])){
		readCube(&c[1]);
		getc ( stdin );
		strcpy(cc[0],c[0].st);
		strcpy(cc[1],c[1].st);
		sort(cc[0],cc[0]+6);
		sort(cc[1],cc[1]+6);
		if(strcmp(cc[0],cc[1])){
			puts("FALSE");
			continue;
		}
		m = 0;
		for(int i = 0; !m && i < 4; rotateX(&c[0]), ++i)
			for(int j = 0; !m && j < 4; rotateY(&c[0]), ++j)
				for(int k = 0; k < 4; rotateZ(&c[0]), ++k){
					if(strcmp(c[0].st,c[1].st) == 0){
						m = 1;
						break;
					}
				}
		if(m) puts("TRUE");
		else puts("FALSE");
	}
	return 0;
}

