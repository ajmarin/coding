/////////////////////////////////
// 00108 - Maximum Sum
/////////////////////////////////
#include <cstdio>
#include <algorithm>
 
using namespace std;
 
int main( void )
{
    int N;
    int t = 0;
    int a[100][100];
    int pr[100];
    int S = 1<<31, s = 0, k, l, x1 = 0,x2 = 0,y1 = 0,y2 = 0,j;
 
    scanf("%d",&N);
 
    for( int i = 0; i < N; i++)
        for( j = 0; j < N; j++)
            scanf("%d",&a[i][j]);
 
    for( int z = 0; z < N; z++)
    {
        for(int i = 0; i < N; i++) pr[i] = 0;
 
        for(int x = z; x < N; x++)
        {
            t = 0;
            s = 1<<31;
            j = 0;
            k = 0; l = 0;
            for(int i = 0; i < N; i++)
            {
                pr[i] = pr[i] + a[x][i];
                t = t + pr[i];
                if( t > s)
                {
                    s = t;
                    k = i;
                    l = j;
                }
                if( t < 0 )
                {
                    t = 0;
                    j = i + 1;
                }
            }
            if( s > S)
            {
                S = s;
                x1 = x;
                y1 = k;
                x2 = z;
                y2 = l;
            }
        }
    }
 
   	printf("%d\n",S); 
    return 0;
}

