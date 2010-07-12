/////////////////////////////////
// 00305 - Joseph
/////////////////////////////////
#include<cstdio>
//#include<vector>
using namespace std;
const int goodjoseph[] = {2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881};
unsigned char k;
/*unsigned int current,died,i,j,k,n,size,test;
int joseph(int m){
	vector<unsigned int> v;
	vector<unsigned int>::iterator it;
	//printf("m = %d\n",m);
	for(i = 0; i < n; i++) v.push_back(i+1);
	for(died = 0,i = 0; i < k; i++){
		died = (died-1+m)%(n-i);
		//printf("%d died\n",died);
		if(died < k) return 0;
		v.erase(v.begin()+died);
	}
	return 1;
}*/
int main(void){
	while(scanf("%u",&k) && k)
		/*n = k<<1;
		if(!goodjoseph[k-1])
			for(test = k+1; !joseph(test); test++);
				goodjoseph[k-1] = test;*/
		printf("%d\n",goodjoseph[k-1]);
	
	return 0;
}
