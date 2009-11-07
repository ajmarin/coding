/////////////////////////////////
// 11369 - Shopaholic
/////////////////////////////////
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
vector<unsigned short int> values;
vector<unsigned short int>::iterator it;
unsigned short items, price, size, tnum;
unsigned int discount;
int main(void){
	scanf("%u",&tnum);
	while(tnum--){
		scanf("%u",&items);
		values.clear();
		discount = 0;
		while(items--){
			scanf("%u",&price);
			values.push_back(price);
		}
		sort(values.rbegin(),values.rend());
		size = values.size();
		for(it = values.begin()+2; it-values.begin() < size; it+=3)
			discount += *it;
		printf("%u\n",discount);
	}
	return 0;
}
