/////////////////////////////////
// 10701 - Pre, in and post
/////////////////////////////////
#include<cstdio>
#include<cstring>
char inord[60], left[60], postord[60], preord[60], right[60];
char idx;
unsigned int howmany,size;
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
	postord[idx++] = n->c;
}
int main(void){
	node *root = new node;
	scanf("%u",&howmany);
	while(howmany--){
		scanf("%u %s %s",&size,&preord,&inord);
		root->c = preord[0];
		root->L = root->R = NULL;
		idx = 1;
		build(root, 0, find(root->c,0), size);
		idx = 0;
		postorder(root);
		postord[idx] = 0;		
		puts(postord);
	}
	return 0;
}

