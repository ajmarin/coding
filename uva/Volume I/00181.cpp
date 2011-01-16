/////////////////////////////////
// 00181 - Hearts
/////////////////////////////////
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
struct card{	
	char v,s;
	card(char a, char b): v( a ), s ( b ){}	
};
struct player{
	vector<card> c;
	int score;
}p[5];
bool fsuit,ftrump,trumped;
char l1[2],l2[2],line[40], *ptr;
int counter,csuit,high,hval,i,j,ldr,tldr,trump,v1,v2;
vector<card>::iterator del, it, ittrump;
bool cmp(card a, card b){
	return (a.v < b.v || (a.v == b.v && a.s < b.s));
}
void follow(int plr){
	fsuit = ftrump = 0;
	/* FIND THE CARD TO PLAY */
	for(it = p[plr].c.begin(); it!= p[plr].c.end(); it++){
		if((*it).s == csuit){ 
			fsuit = 1;
			del = it;
			break;
		} else if(!ftrump && (*it).s == trump){
			ftrump = 1;
			ittrump = it;
		}
	}
	/* PLAY THE CARD */
	if(fsuit){
		if(csuit == 'H') hval += (*del).v;
		if(!trumped && (*del).v > high) high = (*del).v, ldr = plr;
		p[plr].c.erase(del);
	}
	else if(ftrump){
		if(!trumped) trumped = 1, high = (*ittrump).v, ldr = plr;
		else if((*ittrump).v > high) high = (*ittrump).v, ldr = plr;
		if((*ittrump).s == 'H') hval += (*ittrump).v;
		p[plr].c.erase(ittrump);
	}
	else{
		it = p[plr].c.begin();
		if((*it).s == 'H') hval += (*it).v;
		p[plr].c.erase(it);
	}
}
void lead(){
	counter++; tldr = ldr; hval = trumped = 0;
	it = del = p[ldr].c.begin();
	high = (*it).v; csuit = (*it).s;
	/* FIND THE HIGHEST CARD AND IF POSSIBLE USE TRUMP */
	while(it != p[ldr].c.end() && (*it).v == high){
		if((*it).s == trump){
			del = it;
			csuit = (*it).s;
			break;
		}
		it++;
	}
	if(csuit == 'H') hval = (*del).v;
	high = (*del).v;
	p[ldr].c.erase(del);
	/* FOLLOWERS PLAY */
	for(j = 1; j < 5; j++) follow((tldr+j)%5);
	p[ldr].score += hval;	
}
int value(int c){
	switch(c){
		case 'A': return 14;
		case 'K': return 13;
		case 'Q': return 12;
		case 'J': return 11;
		case 'T': return 10;
		default: return c-'0';
	}
}
int main(void){	
	while(gets(line) && line[0] != '#'){
		/* INPUT */
		for(i = 0; i < 3; i++){
			ptr = strtok(line," ");
			for(j = 0; j < 13; j++){
				p[(13*i+j)%5].c.push_back(card(value(*ptr),*(ptr+1)));
				ptr = strtok(NULL," ");
			}
			gets(line);
		}
		ptr = strtok(line," ");
		for(i = 4; i < 15; i++){
			p[i%5].c.push_back(card(value(*ptr),*(ptr+1)));
			ptr = strtok(NULL," ");
		}
		l1[0] = *ptr; l1[1] = *(ptr+1); l1[2] = 0;
		ptr = strtok(NULL," ");
		l2[0] = *ptr; l2[1] = *(ptr+1); l2[2] = 0;
		/* ORDER HANDS, CLEAR SCORES */
		for(i = 0; i < 5; i++){
			p[i].score = 0;
			sort(p[i].c.rbegin(),p[i].c.rend(),cmp);
		}
		/* FIND THE TRUMP */
		v1 = value(l1[0]); v2 = value(l2[0]);
		if(v1 > v2) trump = l1[1];
		else if(v1 < v2) trump = l2[1];
		else {
			if(l1[1] > l2[1]) trump = l1[1];
			else trump = l2[1];
		}
		/* SIMULATE */
		ldr = counter = 0;
		for(i = 0; i < 10; i++) lead();
		/* SHOW SCORES */
		printf("%3d",p[4].score);
		for(i = 0; i < 4; i++) printf("%3d",p[i].score);
		putchar('\n');
	}			
	return 0;
}
