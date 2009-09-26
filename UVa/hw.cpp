/////////////////////////////////
// HTML writer
/////////////////////////////////
#include<cstdio>
#include<cstring>
int c, i, pnum, showed = 0;
char pname[200];
const char *roman[] = {"","I","II","III","IV","V","VI","VII","VIII","IX",
"C","CI","CII","CIII","CIV","CV","CVI","CVII","CVIII","CIX","CX","CXI",
"CXII","CXIII","CXIV","CXV","CXVI"};
const char *site = "http://mrnvhs.webs.com/codes/Volume";
const char *begin = "/home/mrn/coding/UVa/Volume ", *dotcpp = ".cpp";
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
	if(cpp != NULL) showed++;
	else{ printf("Failed opening '%s'\n",dir); return;}
	while(fgets(line,512,cpp)){ 
		for(ptr = line; *ptr; ptr++)
			switch((*ptr)){
				case '<': fprintf(html,"&lt;"); break;
				case '>': fprintf(html,"&gt;"); break;
				default : fputc((*ptr),html); break;
			}
	}
	fclose(cpp);
}
int main(void){
	plist = freopen("plist","r",stdin); 
	html = fopen("solved.html","w");	
	for(i = 1; i < 27; i++){
		fprintf(html,"<h1 class='title'>Volume %s</h1>\n",roman[i]);
		fprintf(html,"<div class='entry'>\n\t<p>\n");
		if(i==1) fgets(pname, 200, stdin),sscanf(pname,"%u",&pnum);
		for(c = 1; pnum/100 == i || pnum/100 - 90 == i; c++){
			fprintf(html,"\t\t<div class='pname'>%s\n",pname);		
			fprintf(html,"\t\t<pre class='sh_cpp'>\n",pnum);
			show(pnum,i);
			fprintf(html,"\n\t\t</pre>\n\t\t</div>\n");
			if(fgets(pname, 200, stdin)) sscanf(pname,"%u",&pnum);
			else break;
		}
		printf("Volume %s\t has %3d problems.\n",roman[i],c);
		fprintf(html,"\t</p>\n</div>\n");
	}
	fclose(plist);
	fclose(html);
	printf("Showed %d problems\n",showed);
	return 0;
}

