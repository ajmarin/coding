/////////////////////////////////
// 00100 - The 3n+1 problem
/////////////////////////////////
#include<cstdio>
#define SIZE 1000001
#define MAX(a,b) (a<b?b:a)
#define MIN(a,b) (a<b?a:b)
unsigned short csize[SIZE];
unsigned int I,K,begin,chain,temp,head,tail, finish;
unsigned long queue[524];
unsigned long b,max=0;
bool end;
unsigned short chainSize(){
	head = tail = 1;
	int chain = 1;
	end = false;
	for(b = begin; b!=1;chain++){
		b = (b&1)? (3*b+1): (b>>1);
		if(b < SIZE){
			queue[tail++] = b;
			if(csize[b]){end = true;break;}
		} else queue[tail++] = 0;
	}
	if(end) csize[begin] = chain+csize[b];
	else csize[begin] = chain;
	for(; head != tail; head++)
			csize[queue[head]] = csize[begin]-head;	
	return csize[begin];
}
int main(void){	
	while (scanf("%d %d",&I,&K)!=EOF){		
		chain = 0;
		begin = MIN(I,K);
		finish = MAX(I,K)+1;
		for(; begin < finish; ++begin){
			if(!csize[begin]) temp = chainSize();
			else temp = csize[begin];	
			chain = MAX(temp,chain);
		}
		printf("%d %d %d\n",I,K,chain);
	}
	return 0;
}
