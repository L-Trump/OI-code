#include <iostream>
#define NMAX 100000
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cin; using std::cout; using std::endl;
typedef long long ll;
struct zfwNode{
    ll v,add;
    zfwNode(){
      v=add=0;
    }
}zfw[4*NMAX+5];
int M;
void buildZFW(int n){
    for(M=1;M<n;M<<=1);
    rep(i,M+1,M+n)  cin>>zfw[i].v;
    per(i,M-1,1) zfw[i].v=zfw[i<<1].v+zfw[i<<1|1].v;
}

ll qSum(int x, int y){
    int lc=0,rc=0,len=1;
    ll ans=0;
    for(x+=M-1,y+=M+1;x^y^1;x>>=1,y>>=1,len<<=1){
      if(~x&1) {ans+=zfw[x^1].v+zfw[x^1].add*len;lc+=len;}
      if(y&1) {ans+=zfw[y^1].v+zfw[y^1].add*len;rc+=len;}
      ans+=zfw[x>>1].add*lc;
      ans+=zfw[y>>1].add*rc;
    }
    for(x>>=1,lc+=rc;x;x>>=1) ans+=zfw[x].add*lc;
    return ans;
}

void zfwPlus(int x, int y,ll k){
    int len=1,lc=0,rc=0;
    for(x+=M-1,y+=M+1;x^y^1;x>>=1,y>>=1,len<<=1){
        if(~x&1) {zfw[x^1].add+=k;lc+=len;}
        if(y&1) {zfw[y^1].add+=k;rc+=len;}
        zfw[x>>1].v+=lc*k;
        zfw[y>>1].v+=rc*k;
    }
    for(x>>=1,lc+=rc;x;x>>=1) zfw[x].v+=lc*k;
}

inline void Fopt(int opt){
    int x,y;ll k;
    cin>>x>>y;
    if(opt==2){
        cout<<qSum(x,y)<<endl;
    } else {
        cin>>k;
        zfwPlus(x,y,k);
    }
    return;
}

int main(){
    int n,m,opt;
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin>>n>>m;
    buildZFW(n);
    rep(i,1,m){
        cin>>opt;
        Fopt(opt);
    }
    return 0;
}
