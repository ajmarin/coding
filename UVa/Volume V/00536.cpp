/////////////////////////////////
// 00536 - Tree Recovery
/////////////////////////////////
#include<cstdio>
#include<cstring>
char ans[30], inord[30], left[30], preord[30], right[30];
char idx;
struct node{
	char c;
	struct node *L, *R;
};
char find(char k,char start){
	char pos;
	for(pos = start; inord[pos] != k; pos++);
	return pos;
}
void build(node *n,char ls, char index, char re){
	if(index != ls){
		node *l = new node;
		l->c = preord[idx++];
		n->L = l;
		build(l, ls, find(l->c,ls), index);
	}
	if(index != re-1){
		node *r = new node;
		r->c = preord[idx++];
		n->R = r;
		build(r, index+1, find(r->c,index+1), re);
	}	
}
void postorder(node *n){
	if(n->L != NULL) postorder(n->L);
	if(n->R != NULL) postorder(n->R);
	ans[idx++] = n->c;
}
int main(void){
	node *root = new node;
	while(scanf("%s %s",&preord,&inord)!=EOF){
		root->c = preord[0];
		idx = 1;
		build(root, 0, find(root->c,0), strlen(inord));
		idx = 0;
		postorder(root);
		ans[idx] = 0;		
		puts(ans);
	}
	return 0;
}

