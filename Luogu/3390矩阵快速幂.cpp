#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define NMAX 100
#define MOD 1000000007
using std::cin; using std::cout; using std::cerr; using std::endl; using std::string;
typedef long long ll;
struct Mat{
    ll v[NMAX+5][NMAX+5];
    int height,width;
    Mat(int h, int w){
      height=h;
      width=w;
      memset(v,0,sizeof(v));
    }
    Mat(){
      height=0;
      width=0;
      memset(v,0,sizeof(v));
    }
};

Mat mult(Mat a,Mat b){
    int i,j,k;
    int h=a.height, w=b.width;
    Mat c(h,w);
    for (i=1;i<=h;i++){
      for (j=1;j<=w;j++){
        for (k=1;k<=a.width;k++){
          c.v[i][j]=c.v[i][j]%MOD+a.v[i][k]*b.v[k][j]%MOD;
        }
      }
    }
    return c;
}

void outMat(Mat p){
    int i,j,h=p.height,w=p.width;
    for (i=1;i<=h;i++){
      for (j=1;j<=w;j++){
        cout<<p.v[i][j] % MOD<<" ";
      }
      cout<<endl;
    }
}

int main(){
    int i,j,n;
    ll k;
    // freopen("3390.1.in", "r", stdin);
    // freopen("3390.1.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin>>n>>k;
    Mat base(n,n);
    Mat ans(n,n);
    for (i=1;i<=n;i++){
      for (j=1;j<=n;j++){
        cin>>base.v[i][j];
      }
    }
    for (i=1;i<=n;i++){
      ans.v[i][i]=1;
    }
    // outMat(base);
    // outMat(mult(ans,base));
    // outMat(ans);
    // outMat(base);
    while(k>0){
      if(k&1) ans=mult(ans,base);
      base=mult(base,base);
      k>>=1;
    }
    outMat(ans);
    return 0;
}
