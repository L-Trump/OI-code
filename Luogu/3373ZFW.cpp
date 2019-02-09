#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define NMAX 100000
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cin; using std::cout; using std::cerr; using std::endl; using std::string;
typedef long long ll;
int p;
struct zfwNode{
    int v;
    ll add;
    //std::vector<std::pair<int,int>> change;
    zfwNode(){
      v=0;
    }
}zfw[4*NMAX];
int M;
void buildZFW(int n){
    for(M=1;M<n;M<<=1);
    rep(i,M+1,M+n)  cin>>zfw[i].v;
    per(i,M-1,1) zfw[i].v=zfw[i<<1].v+zfw[i<<1|1].v;
}
ll qSum(int x, int y){
    int L=M+x-1,R=M+y+1;
    ll Lans=0,Rans=0;
    while(L^R^1){
      if(~L&1) Lans+=zfw[L^1].v;
      if(R&1) Rans+=zfw[R^1].v;
      L=L>>1;R=R>>1;
    }
    return Lans+Rans;
}

void zfwPlus(int x, int y,ll k){
    for(x+=M-1,y+=M+1;x^y^1;x>>=1,y>>=1){
        if(~x&1) zfw[x^1].add=(zfw[x^1].add+(k % p))%p;
        if(y&1) zfw[y^1].add=(zfw[y^1].add+(k % p))%p;
    }
}


void Fopt(int opt){
    int x,y,k;
    switch (opt) {
      case 3:
        cin>>x>>y;
        cout<<qSum(x,y)<<endl;
      break;
      case 2:
        cin>>x>>y>>k;
        //zfwPlus(x,y,k);
      break;
    }
    return;
}

int main(){
    int n,m,opt;
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin>>n>>m>>p;
    buildZFW(n);
    rep(i,1,m){
        cin>>opt;
        Fopt(opt);
    }
    return 0;
}
