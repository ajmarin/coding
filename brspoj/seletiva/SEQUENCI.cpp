#include <cstdio>
#include <cstring> 
bool p[32][1001];
bool native[1001];
int nums[30];
const char *aseq = "This is an A-sequence.";
const char *notaseq = "This is not an A-sequence.";
int main(void){
	int i, j, n;
	bool seq = 1;
	for(int cnum = 1; scanf("%d",&n)!=EOF; cnum++){
		seq = 1;
		memset(p,0,sizeof(p));
		memset(native,0,sizeof(native));
		for(i = 0; i < n; i++){
			scanf("%d",&nums[i]);
			p[i][nums[i]] = native[nums[i]] = 1;
			if(i && nums[i] <= nums[i-1]) seq = 0;
		}
		for(i = 1; seq && i < n; i++)
			for(j = 1; j < 1001-nums[i]; j++)
				if(p[i-1][j]){
					int x = j+nums[i];
					if(native[x]){ seq = 0; break; }
					p[i][j] = p[i][x] = 1;
				}

		printf("Case #%d:",cnum);
		for(i = 0; i < n; i++) printf(" %d",nums[i]);
		putc(10,stdout);
		if(seq) puts(aseq);
		else puts(notaseq);
	}
	return 0;
}

