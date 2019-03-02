#include <cstdio>
#include <cstring>
#include <algorithm>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using namespace std;
long long isW[25][25][25];
long long w(int a,int b,int c){
    if(a<=0||b<=0||c<=0) return 1;
    if(a>20||b>20||c>20) a=b=c=20;
    if (isW[a][b][c]!=-2) return isW[a][b][c];
    if (a<b&&b<c){
      isW[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
      return isW[a][b][c];
    }
    isW[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
    return isW[a][b][c];
}
int main(){
    int a=0,b=0,c=0;
    //freopen("triangle.in", "r", stdin);
    //freopen("triangle.out", "w", stdout);
    rep(i,1,21)rep(j,1,21)rep(k,1,21) isW[i][j][k]=-2;
    while(1){
      scanf("%d%d%d",&a,&b,&c);
      if(a==-1&&b==-1&&c==-1) return 0;
      printf("w(%d, %d, %d) = ",a,b,c);
      printf("%lld\n",w(a,b,c));
    }
    return 0;
}
