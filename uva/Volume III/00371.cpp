/////////////////////////////////
// 00371 - Ackermann Functions
/////////////////////////////////
#include<cstdio>
#include<cstring>
#define SIZE 524288
unsigned short chain_size[SIZE],chain,max_chain,temp,head,tail;
unsigned int E,S,current,generator;
unsigned long long int k,queue[1500];
bool verify;
int main(void){
	memset(chain_size,0,sizeof(chain_size));
	while (scanf("%u %u",&S,&E) && S && E){
		if(S>E) S ^= E ^= S ^= E;
		for(max_chain = 0,current = S; current <= E; current++){
			chain = 0; k = current;
			verify = current < SIZE;
			if(k < SIZE && chain_size[k]) chain = chain_size[k];
			else {
				head = tail = 1;
				do {
					if(k < SIZE && chain_size[k])	chain += chain_size[k],	k = 1;
					else{
						chain++;
						if(k&1) k = 3*k+1;
						else k >>=1;
						if(verify)
							if(k < SIZE && !chain_size[k]){
								queue[tail++] = k;						
							} else queue[tail++] = 0;
					}
				} while(k!=1);
				if(verify){
					chain_size[current] = chain;
					for(; head != tail; head++) chain_size[queue[head]] = chain_size[current]-head;
				}
			}
			if(chain > max_chain) max_chain = chain, generator = current;			
		}
		printf("Between %u and %u, %u generates the longest sequence of %u values.\n",S,E,generator,max_chain);
	}
	return 0;
}
