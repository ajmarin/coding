/////////////////////////////////
// 00380 - Call Forwarding
/////////////////////////////////
#include<cstdio>
#include<map>
using namespace std;
map < int , int > m;
int fw[100][100][3];
int deg[100], n[100];
bool v[100];
int make_call(int time, int target){
	int ret = n[target];
	for(int i = 0; i < deg[target]; i++)
		if(time >= fw[target][i][0] && time <= fw[target][i][1]){
			if(m.find(fw[target][i][2]) == m.end()) return fw[target][i][2];
			else {
				if(v[m[fw[target][i][2]]]) return 9999;
				else {
					v[m[fw[target][i][2]]] = 1;
					ret = make_call(time, m[fw[target][i][2]]);
				}
			}
		}
	return ret;
}			
int main(void){
	int a, dur, i, nums, src, t, tgt, time;
	puts("CALL FORWARDING OUTPUT");
	scanf("%d",&t);
	for(int s = 1; s <= t; s++){
		for(nums = i = 0; i < 200; i++) deg[i] = 0;
		m.clear();
		printf("SYSTEM %d\n",s);
		while(scanf("%4d",&src) && src){
			scanf("%d%d%d",&time,&dur,&tgt);
			if(m.find(src) == m.end()) m[src] = nums, n[nums++] = src;
			a = m[src];
			fw[a][deg[a]][0] = time;
			fw[a][deg[a]][1] = time+dur;
			fw[a][deg[a]][2] = tgt;			
			deg[a]++;
		}
		while(scanf("%d",&time) && time != 9000){
			scanf("%d",&tgt);
			if(m.find(tgt) == m.end()) {
				printf("AT %04d CALL TO %04d RINGS %04d\n",time,tgt,tgt);
				continue;
			}
			for(i = 0; i < nums; i++) v[i] = 0;
			int dest = make_call(time, m[tgt]);
			printf("AT %04d CALL TO %04d RINGS %04d\n",time,tgt,dest);
		}
	}
	puts("END OF OUTPUT");
	return 0;
}
	