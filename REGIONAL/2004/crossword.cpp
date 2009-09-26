#include<cstdio>
#include<cstring>
#include<vector>
#define prc(c,it) for(typeof(c.begin())it=c.begin();it!=c.end();it++)
using namespace std;
int c,cnum,cnt[2050],eq,i,l,prev,rem,tmp,tp,w;
bool fnd;
vector< int > v;
int main(void){
	while(scanf("%d%d%d",&l,&c,&w) && l){
		printf("#%d\n",++cnum);
		memset(cnt,0,sizeof(cnt));
		v.clear();
		cnt[0] = 2000;
		tp = eq = rem = prev = 0;
		for(i = 0; i != w; i++)
			scanf("%d",&tmp),++cnt[tmp];
		if(l&1){
			while(cnt[(l>>1)]>1)
				cnt[(l>>1)]-=2, tp++, v.push_back((l+1)>>1), ++eq;
			if(cnt[(l>>1)]) { printf("0\n"); continue; }
		}
		for(i = 1; i < l; i++)
			while(cnt[i] && cnt[l-1-i]){
				++tp, --cnt[i], --cnt[l-1-i];
				v.push_back(i);
			}
		if(tp != c || (l&1 && tp-eq<c/2)) printf("0\n");			
		else {
			while(rem != c){
				if(l&1 && prev != ((l+1)>>1) && eq){
					prc(v,it) if((*it) == (l>>1)){ v.erase(it); break; }
					eq--, prev = ((l+1)>>1);
				}
				else prc(v,it){
					if((*it)+1 != prev)	prev=(*it)+1, fnd = 1;
					else if(l-(*it) != prev) prev=l-(*it), fnd = 1;
					if(fnd){ fnd = 0,v.erase(it); break; }
				}
				printf("%d %d\n",prev,++rem);
			}
		}
	}
}

