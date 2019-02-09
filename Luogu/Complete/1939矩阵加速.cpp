#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define TMAX 100
#define mod 1000000007
using std::cin; using std::cout; using std::cerr; using std::endl; using std::string;
typedef long long ll;

struct Mat{
    ll v[6][6];
    int h,w;
    Mat(){
        memset(v, 0, sizeof(v));
        h=w=0;
    }
    Mat(int _h,int _w){
        memset(v, 0, sizeof(v));
        h=_h;w=_w;
    }
};


Mat mult(Mat a, Mat b){
    int h=a.h,w=b.w,k=a.w;
    int i,j,p;
    Mat c(h,w);
    for (i=1;i<=h;i++){
      for (j=1;j<=w;j++){
        for (p=1;p<=k;p++){
          c.v[i][j]+=a.v[i][p]*b.v[p][j]%mod;
          c.v[i][j]%=mod;
        }
      }
    }
    return c;
}

Mat qPow(Mat base, ll k){
    int i;
    Mat ans(3,3);
    for (i=1;i<=3;i++){
      ans.v[i][i]=1;
    }
    while(k>0){
      if(k&1) ans=mult(ans,base);
      base=mult(base,base);
      k>>=1;
    }
    return ans;
}

void outMat(Mat p){
    int i,j,h=p.h,w=p.w;
    for (i=1;i<=h;i++){
      for (j=1;j<=w;j++){
        cout<<p.v[i][j] % mod<<" ";
      }
      cout<<endl;
    }
}


int main(){
    int T,i,n;
    //freopen("triangle.in", "r", stdin);
    //freopen("triangle.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    Mat e(3,1), base(3,3),b(3,3);
    base.v[1][2]=base.v[2][3]=base.v[3][1]=base.v[3][3]=1;
    e.v[1][1]=e.v[2][1]=e.v[3][1]=1;
    b=base;
    cin>>T;
    for (i=1;i<=T;i++){
      cin>>n;
      if(n<=3){
        cout<<1<<endl;
        continue;
      }
      b=mult(qPow(base,n-3),e);
      cout<<b.v[3][1]%mod<<endl;
    }
    // outMat(qPow(base,2));
    return 0;
}
