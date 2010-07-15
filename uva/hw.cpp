#include <cstdio>
#include <cstring>
#include <string>

using namespace std;
int showed = 0;
char pname[200];
const char *roman[] = {"","I","II","III","IV","V","VI","VII","VIII","IX",
"C","CI","CII","CIII","CIV","CV","CVI","CVII","CVIII","CIX","CX","CXI",
"CXII","CXIII","CXIV","CXV","CXVI","CXVII", "CXVIII"};

string vol; 
const char *site = "http://mrnvhs.webs.com/codes/Volume";
const char *begin = "./Volume ", *dotcpp = ".cpp";
FILE *plist, *html;
void show(int pnum, int vol){
	char dir[200], line[512], s[6], *ptr;
	int i;
	s[5] = 0;
	strcpy(dir,begin);strcpy(dir+strlen(begin),roman[vol]);
	for(ptr = dir; *ptr; ptr++); *(ptr++) = '/';
	for(i = 0; i < 5; i++) s[4-i] = pnum%10+'0', pnum/=10;
	strcpy(ptr,s); strcpy(ptr+5,dotcpp);
	FILE *cpp = fopen(dir,"r");
	showed += (cpp != NULL);
	if(cpp == NULL){ printf("Failed opening '%s'\n",dir); return;}
	fprintf(html,"\t\t<div class='pname'>%s\n",pname);		
	fprintf(html,"\t\t<pre class='sh_cpp'>\n",pnum);
	while(fgets(line,512,cpp)){ 
		for(ptr = line; *ptr; ptr++)
			switch((*ptr)){
				case '<': fprintf(html,"&lt;"); break;
				case '>': fprintf(html,"&gt;"); break;
				default : fputc((*ptr),html); break;
			}
	}
	fprintf(html,"\n\t\t</pre>\n\t\t</div>\n");
	fclose(cpp);
}
void doVol(int k){
	vol = "Volume";
	if(k > 9) vol.push_back(k/10 + '0');
	vol.push_back(k%10+'0');
	vol += ".html";
}
int main(void){
	plist = freopen("plist","r",stdin); 
	for(int c, i = 1; i < 29; i++){
		int pnum;
		doVol(i);
		html = fopen(vol.c_str(),"w");
		fprintf(html,"<h1 class='title'>Volume %s</h1>\n",roman[i]);
		fprintf(html,"<div class='entry'>\n\t<p>\n");
		if(i==1) fgets(pname, 200, stdin),sscanf(pname,"%u",&pnum);
		for(c = 1; pnum/100 == i || pnum/100 - 90 == i; c++){
			show(pnum,i);
			if(fgets(pname, 200, stdin)) sscanf(pname,"%u",&pnum);
			else break;
		}
		printf("Volume %s\t has %3d problems.\n",roman[i],c);
		fprintf(html,"\t</p>\n</div>\n");
		fclose(html);
	}
	fclose(plist);
	printf("Showed %d problems\n",showed);
	return 0;
}

