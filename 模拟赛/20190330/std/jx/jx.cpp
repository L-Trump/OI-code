#include<iostream>
#include<cstdio>
#include<cstdlib>
#define INF 100000000
using namespace std;
int f[1000010][4][2];
int n,num[1000010];
int main()
{
	freopen("jx.in","r",stdin);
	freopen("jx.out","w",stdout);
	int i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)  scanf("%d",&num[i]);
	for(j=0;j<=3;j++)  f[1][j][0]=f[1][j][1]=-INF;
    f[1][0][0]=0;f[1][1][1]=num[1];
	f[1][0][1]=-INF;f[1][1][0]=-INF;
	for(i=2;i<=n;i++)
	{
        for(j=0;j<=3;j++)
        {
            f[i][j][0]=f[i][j][1]=-INF;
        }
        f[i-1][0][0]=0;f[i-1][0][1]=-INF;
        for(j=1;j<=3;j++)
        {
			if(f[i-1][j][0]!=-INF)  f[i][j][0]=max(f[i-1][j][0],f[i][j][0]);
            if(f[i-1][j][1]!=-INF)  f[i][j][0]=max(f[i][j][0],f[i-1][j][1]);
            if(f[i-1][j][1]!=-INF)  f[i][j][1]=max(f[i][j][1],f[i-1][j][1]+num[i]);
            if(f[i-1][j-1][0]!=-INF)  f[i][j][1]=max(f[i][j][1],f[i-1][j-1][0]+num[i]);
            if(f[i-1][j-1][1]!=-INF)  f[i][j][1]=max(f[i][j][1],f[i-1][j-1][1]+num[i]);
			//f[i][j][1]=max(f[i-1][j][1]+num[i],max(f[i-1][j-1][0]+num[i],f[i-1][j-1][1]+num[i]));
		}    
	}
	cout<<max(f[n][3][0],f[n][3][1])<<endl;
	//for(i=1;i<=n;i++)  cout<<f[i][1][0]<<" "<<f[i][1][1]<<endl;
//	system("pause");
	return 0;
}
