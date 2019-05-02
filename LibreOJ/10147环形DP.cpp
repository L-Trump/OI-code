#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
#define INF 1000000009
using std::cin; using std::cout; using std::cerr; using std::endl; using std::string;
typedef long long ll;
int a[205];
ll fmin[205][205]; //f[i][j]意为从第i个数开始往后环状取j个数（算上第i个数）进行合并的最值
ll fmax[205][205];
ll pre[405]; //前缀和
int main(){
    int n;
    //freopen("triangle.in", "r", stdin);
    //freopen("triangle.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin>>n;
    rep(i,1,n) cin>>a[i];
    rep(i,1,n) pre[i]=pre[i-1]+a[i];
    rep(i,1,n) pre[n+i]=pre[n+i-1]+a[i];
    rep(j,2,n)
      rep(i,1,n){
        //if(i+j-1>2*n) continue;
        fmin[i][j]=INF;
        rep(k,1,j-1){
          /*
            假设最后一次合并发生在i..i+k-1与i+k..i+j-1之间
            那么f[i][j]=min/max(f[i][k]+f[i+k][j-k]+i..i+j-1之间的所有数的和即当次合并所需积分)
            由于是环状，f[i][j]与f[i+n][j]意义相同（当i<=n时）所以第二项使用f[(i+k-1)%n+1][j-k]
          */
          fmin[i][j]=std::min(fmin[i][j], fmin[i][k]+fmin[(i+k-1)%n+1][j-k]+pre[i+j-1]-pre[i-1]);
          fmax[i][j]=std::max(fmax[i][j], fmax[i][k]+fmax[(i+k-1)%n+1][j-k]+pre[i+j-1]-pre[i-1]);
        }
      }
    ll MAXX=0,MINN=INF;
    rep(i,1,n){ //最后一次合并不确定，所以把每种情况都比较一下
      MAXX=std::max(MAXX,fmax[i][n]);
      MINN=std::min(MINN,fmin[i][n]);
    }
    cout<<MINN<<endl;
    cout<<MAXX<<endl;
    return 0;
}
