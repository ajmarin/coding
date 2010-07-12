/////////////////////////////////
// 00297 - Quadtrees
/////////////////////////////////
#include<cstdio>
#include<cstring>
char t1[1370],t2[1370],tree[1370];
unsigned int black_pixels,I,K,l1,l2,tnum,tree_idx;
unsigned int pixels[] = {1024,256,64,16,4,1};
void fuse(char a, char b){
	if(a == 'p'){
		if(b == 'e'){
			tree[tree_idx++] = 'p', I++;
			for(int i = 0; i < 4; i++) tree[tree_idx++] = t1[I++];
			K++;
		}
		else if(b == 'f') tree[tree_idx++] = 'f', I+=5, K++;
		else {
			tree[tree_idx++] = 'p', I++, K++;
			for(int i = 0; i < 4; i++) fuse(t1[I],t2[K]);
		}
	} else if(a == 'e'){
		if(b == 'p'){
			tree[tree_idx++] = 'p', K++;
			for(int i = 0; i < 4; i++) tree[tree_idx++] = t2[K++];
			I++;
		} else tree[tree_idx++] = t2[K], I++, K++;
	} else {
		tree[tree_idx++] = 'f', I++, K++;
		if(b == 'p') K+=4;
	}
}
void analyze(int depth){
	if(I == tree_idx) return;
	if(tree[I] == 'p'){
		//printf("its a parent, depth increased!\n");
		for(int i = 0; i < 4; i++) I++,analyze(depth+1);
	}
	else black_pixels += ((tree[I]-'e')*pixels[depth]);
}
int main(void){
	scanf("%u\n",&tnum);
	while(tnum--){
		gets(t1); gets(t2);
		//printf("fusing: %s\n\t%s\n",t1,t2);
		l1 = strlen(t1); l2 = strlen(t2);
		for(tree_idx = I = K = 0; I < l1 && K < l2; ) fuse(t1[I],t2[K]);		
		tree[tree_idx] = 0;
		//printf("result: %s\n",tree);
		I = black_pixels = 0;		
		analyze(0);
		printf("There are %u black pixels.\n",black_pixels);
	}
	return 0;
}
