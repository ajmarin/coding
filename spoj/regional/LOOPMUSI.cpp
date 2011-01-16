#include <cstdio>
int i,n,peak;
int notes[10000];
int main(){
	while(scanf("%d",&n)){
		if(n==0) break;
		peak = 0;
		for(i = 0; i < n; i++) scanf("%d",&notes[i]);
		for(i = 1; i < n-1; i++){
			if(notes[i] > notes[i+1] && notes[i] > notes[i-1]) peak++;
			else if(notes[i] < notes[i+1] && notes[i] < notes[i-1]) peak++;
		}
		if(notes[0] > notes[n-1] && notes[0] > notes[1]) peak++;
		else if(notes[0] < notes[n-1] && notes[0] < notes[1]) peak++;
		if(notes[n-1] > notes[n-2] && notes[n-1] > notes[0]) peak++;
		else if(notes[n-1] < notes[n-2] && notes[n-1] < notes[0]) peak++;
		printf("%d\n",peak);
	}
}
