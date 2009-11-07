/////////////////////////////////
// 10131 - Is Bigger Smarter?
/////////////////////////////////
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct elephant{
	int n,q,s,w;
	vector<elephant>::iterator p;
	elephant(int a, int b, int c): w(a),s(b),n(c){}
};
vector<elephant> e;
vector<elephant>::iterator aux,it,end;
int i, n, W, S;
bool next(elephant a, elephant b){
	return (a.w < b.w && b.s < a.s);
}
bool ord(elephant a, elephant b){
	return (a.w < b.w);
}
void print_lis(vector<elephant>::iterator idx,int b){
	if(b) 
		print_lis((*idx).p, b-1),
		printf("%u\n",(*idx).n);
	else printf("%u\n",(*idx).n);
}
int main(void){	
	for(i = 1; scanf("%u %u",&W,&S)!=EOF; i++)
		e.push_back(elephant(W,S,i));
	sort(e.begin(),e.end(),ord);	
	for(it = e.begin(); it != e.end(); it++){
		n = 0;
		for(aux = e.begin(); aux != it; aux++)
			if(next(*aux,*it) && (*aux).q > n)
				n = (*aux).q, (*it).p = aux;
		(*it).q = n + 1;
	}
	for(n = 0, it = e.begin(); it != e.end(); it++)
		if((*it).q > n) n = (*it).q, end = it;
	printf("%u\n",n);
	if(n) print_lis(end,n-1);
	return 0;
}
