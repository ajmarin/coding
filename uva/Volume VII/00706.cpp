/////////////////////////////////
// 00706 - LC-Display
/////////////////////////////////
#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int i,n,d[8],dig;
bool t[10],tl[10],tr[10],m[10],bl[10],br[10],b[10];
char c;
string s;
int main(void){
	t[0] = t[2] = t[3] = t[5] = t[6] = t[7] = t[8] = t[9] = 1; t[1] = t[4] = 0;
	tl[0] = tl[4] = tl[5] = tl[6] = tl[8] = tl[9] = 1; tl[1] = tl[2] = tl[3] = tl[7] = 0;
	tr[0] = tr[1] = tr[2] = tr[3] = tr[4] = tr[7] = tr[8] = tr[9] = 1; tr[5] = tr[6] = 0;
	m[2] = m[3] = m[4] = m[5] = m[6] = m[8] = m[9] = 1; m[0] = m[1] = m[7] = 0;
	bl[0] = bl[2] = bl[6] = bl[8] = 1; bl[1] = bl[3] = bl[4]= bl[5] = bl[7] = bl[9] = 0;
	br[0] = br[1] = br[3] = br[4] = br[5] = br[6] = br[7] = br[8] = br[9] = 1; br[2] = 0;
	b[0] = b[2] = b[3] = b[5] = b[6] = b[8] = b[9] = 1; b[1] = b[4] = b[7] = 0;
	while(scanf("%d ",&n) && n){
		for(dig = 0; (c = getchar())!= '\n'; dig++) d[dig] = c - '0';
		string aux(n,'-');
		string aux2(n,(char)32);		
		if(t[d[0]]) s = " "+aux+" ";
		else s = " "+aux2+" ";
		for(i = 1; i < dig; i++){
			if(t[d[i]])	s += "  "+aux+" ";
			else s += "  "+aux2+" ";
		}
		cout << s << endl;
		if(tl[d[0]]) s = "|";
		else s = " ";
		s+= aux2;
		if(tr[d[0]]) s += "|";
		else s += " ";
		for(i = 1; i < dig; i++){
			if(tl[d[i]]) s += " |";
			else s+= "  ";
			s += aux2;
			if(tr[d[i]]) s += "|";
			else s+= " ";
		}
		for(i = 0; i < n; cout << s << endl, i++);
		if(m[d[0]]) s = " "+aux+" ";
		else s = " "+aux2+" ";
		for(i = 1; i < dig; i++){
			if(m[d[i]])
				s += "  "+aux+" ";
			else s += "  "+aux2+" ";
		}
		cout << s << endl;
		if(bl[d[0]]) s = "|";
		else s = " ";
		s+= aux2;
		if(br[d[0]]) s += "|";
		else s += " ";
		for(i = 1; i < dig; i++){
			if(bl[d[i]]) s += " |";
			else s+= "  ";
			s += aux2;
			if(br[d[i]]) s += "|";
			else s+= " ";
		}
		for(i = 0; i < n; cout << s << endl, i++);
		if(b[d[0]]) s = " "+aux+" ";
		else s = " "+aux2+" ";
		for(i = 1; i < dig; i++){
			if(b[d[i]])
				s += "  "+aux+" ";
			else s += "  "+aux2+" ";
		}
		cout << s << endl;
		putchar('\n');
		
	}
}