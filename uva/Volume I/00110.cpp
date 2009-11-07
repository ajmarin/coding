#include <cstdio>
#include <string>

using namespace std;

void DOIT(string fin, string un, string rem, bool after){
	if( un.empty() ){
		fin.append(rem);
		putc(10, stdout);
		for(int a = 0 ; a < fin.size() ; a++) printf("  ");
		printf("writeln(");
		for(int a = 0 ; a < fin.size() ; a++){
			if(a) putc(',', stdout);
			putc(fin[a], stdout);
		}
		putc(')', stdout);
	} else {
		if( fin.empty() ){
			fin += un[0];
			fin.append( rem );
			rem.clear();
			un.erase(0,1);
			DOIT(fin, un, rem, false);
		} else {
			if(after) printf(" if ");
			else { 
				putc(10, stdout);
				for(int a = 0 ; a < fin.size() + rem.size(); a++) printf("  ");
				printf("if ");
			}
			putc(fin[ fin.size() - 1], stdout);
			printf(" < ");
			putc(un[0], stdout);
			printf(" then");
			string copy = un;
			copy.erase(0, 1);
			string a,b,c;
			a = fin;
			a += un[0];
			a += rem;
			b = copy;
			DOIT( a, b, "", false);
			putc(10, stdout);
			for(int a = 0 ; a < fin.size() + rem.size(); a++) printf("  ");
			printf("else");
			string copy2 = fin;
			copy2.erase(copy2.size() - 1);
			a = copy2;
			b = un;
			c = fin[ fin.size() - 1 ];
			c += rem;
			DOIT(a, b, c, true);
		}
	}
}
char vars[128];
int main(){
	int P, V, v, vs;
	scanf("%d",&P);
	while(P--){
		scanf("%d",&V);
		for(v = vs = 0; v < V; ++v){
			if(v) vars[vs++] = ',';
			vars[vs++] = 'a' + v;
		}
		vars[vs] = 0;
		printf("program sort(input,output);\nvar\n");
		fputs(vars, stdout);
		printf(" : integer;\nbegin\n  readln(");
		fputs(vars, stdout);
		printf(");");
		string rem;
		for(int v = 1; v < V; ++v) rem += 'a' + v;
		DOIT("a", rem, "", false);
		printf("\nend.\n");
		if(P) putc(10, stdout);
	}
return 0;
}

