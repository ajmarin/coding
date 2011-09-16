#include <cstdio>
int pc, pt, k, t;
char in[100005], prog[100005], tape[100005];
int main(void){
	scanf("%d\n",&t);
	for(int i = 1; t--; i++){
		printf("Instancia %d\n",i);
		gets(in);
		gets(prog);		
		for(k = 0; k < 30000; k++) tape[k] = 0;
		pt = pc = k = 0;
		while(prog[pc]){
			switch(prog[pc]){
				case '>': pt++; break;
				case '<': pt--; break;
				case '+': tape[pt]++; break;
				case '-': tape[pt]--; break;
				case '.': putchar(tape[pt]); break;
				case ',': tape[pt] = in[k] ? in[k++] : 0; break;
				case '[':					
					for(int c = 1; !tape[pt] && c; ){
						if(prog[++pc] == '[') c++;
						if(prog[pc] == ']') c--;
					}
					break;
				case ']':
					for(int c = 1; tape[pt] && c; ){
						if(prog[--pc] == '[') c--;
						if(prog[pc] == ']') c++;
					}
					break;
				case '#':
					for(int i = 0; i < 10; i++)	putchar(tape[i]);
					break;
			}
			pc++;
		}
		puts("\n");
		getchar();
	}
	return 0;
}
