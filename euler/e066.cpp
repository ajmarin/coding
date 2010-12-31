#include <cmath>
#include <cstdio>
#include <ctime>
/*
   // these are the two bounding fractions 0 ~ inf
   n1 = 0; d1 = 1; n1 / d1 = 0;
   n2 = 1; d2 = 0; n2 / d2 = inf;
   while(true){ 
	   a = n1+n2; 
	   b = d1+d2; 
	   //a/b lies between n1/d1 and n2/d2
	   t = a*a - D*b*b; // see how close a^2/b^2 is to n 
	   if(t == 1) // we're done, break
		   break; 
	   else { // not there yet - adjust lo or hi bound 
		   if(t>0){ n2=a; d2=b;} // decrease hi bound
		   else {n1=a; d1=b;} // increase lo bound
	   } 
   }
*/
int sqr(int a){ return a * a; }
int main(void){
	int ans = 0, a, b, ls, maxls = 0;
	int d1, d2, n1, n2, t;
	clock_t ini = clock();
	for(int D = 2; D < 1000001; ++D){
		if(sqr(floor(sqrt(D + .5))) == D) continue;
		n1 = d2 = 0;
		d1 = n2 = 1;
		ls = 0;
		while(1){
			a = n1 + n2;
			b = d1 + d2;
			t = sqr(a) - D * sqr(b);
			ls++;
			if(t == 1) break;
			else if(t > 0){ n2 = a; d2 = b; }
			else { n1 = a; d1 = b; }
		}
		if(ls > maxls) maxls = ls, ans = D;
	}
	printf("Time spent: %.3lfs\n", ((double)(clock() - ini))/CLOCKS_PER_SEC);
	printf("Answer: %d\n", ans);
	return 0;
}

