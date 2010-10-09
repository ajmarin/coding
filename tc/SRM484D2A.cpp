#include <string>

using namespace std;


typedef int ret;
class NumberMagicEasy {
	public:
		ret theNumber(string);
};
ret NumberMagicEasy::theNumber(string answer){
	ret r = 1;
	int val = 8;
	for(int i = 0; i < 4; ++i){
		if(answer[i] == 'N') r += val;
		val >>= 1;
	}
	return r;
}

