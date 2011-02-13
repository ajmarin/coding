#include <cassert>
#include <cstdio>

bool is_lower(char x){ return x >= 'a' && x <= 'z'; }
bool is_upper(char x){ return x >= 'A' && x <= 'Z'; }
bool is_alpha(char x){ return is_lower(x) || is_upper(x); }
bool is_digit(char x){ return x >= '0' && x <= '9'; }
char to_lower(char x){ return x + (is_upper(x) << 5); }
char to_upper(char x){ return x - (is_lower(x) << 5); }

int main(void){
	for(char i = 'a'; i <= 'z'; ++i){
		assert(is_alpha(i));
		assert(!is_digit(i));
		assert(is_lower(i));
		assert(!is_upper(i));
		assert(to_lower(i) == i);
		assert(to_upper(i) != i);
	}
	for(char i = 'A'; i <= 'Z'; ++i){
		assert(is_alpha(i));
		assert(!is_digit(i));
		assert(!is_lower(i));
		assert(is_upper(i));
		assert(to_lower(i) != i);
		assert(to_upper(i) == i);
	}
	for(char i = '0'; i <= '9'; ++i){
		assert(!is_alpha(i));
		assert(is_digit(i));
		assert(!is_lower(i));
		assert(!is_upper(i));
		assert(to_lower(i) == i);
		assert(to_upper(i) == i);
	}
	printf("TEST SUCEEDED\n");
	return 0;
}
