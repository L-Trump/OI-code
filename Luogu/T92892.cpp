#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define MOD 1000000007
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cin; using std::cout; using std::cerr; using std::endl; using std::string;
using std::make_pair;
typedef long long ll;
ll fib[100006];
int n,m,M;
void initFib(){
    fib[1]=fib[2]=1;
    rep(i,3,100005) fib[i]=(fib[i-1]+fib[i-2])%MOD;
    rep(i,2,100005) fib[i]=(fib[i]+fib[i-1])%MOD;
}
struct node{
    int l,r;
    ll v;
    std::vector<int> add;
    node(){
      l=r=v=0;
    }
    int len(){
      return r-l+1;
    }
}a[400005];
ll fibVal(int x, int y){
    return ((fib[y]-fib[x-1])%MOD+MOD)%MOD;
}
void buildTree(){
     // cout<<fibVal(2,4)<<endl;
    cin>>n>>m;
    for(M=1;M<=n+1;M<<=1);
    // cout<<"M="<<M<<" n="<<n<<endl;
    rep(i,M+1,M+n){
      cin>>a[i].v;
      a[i].l=a[i].r=i-M;
    }
    // cout<<"Read over";
    per(i,M-1,1){
      a[i].v=(a[i<<1].v+a[i<<1|1].v)%MOD;
      a[i].l=a[i<<1].l;a[i].r=a[i<<1|1].r;
      if(a[i].l<1) a[i].l=1;
      if(a[i].r>n||a[i].r==0) a[i].r=n;
    }
    // cerr<<a[1].len()<<endl;
}
void ADD(int l, int r, int num){
    int len=r-l+1;
    int llen=num,rlen=len+num-1;
    // cout<<endl;
    // cout<<llen<<" "<<rlen<<endl;
    l--;r++;
    for(l=M+l,r=M+r;l^r^1;l>>=1,r>>=1){
      if(~l&1){
        a[l^1].v+=fibVal(llen,llen+a[l^1].len()-1);
        a[l^1].add.push_back(llen);
        // cerr<<"a"<<(l^1)<<" pushed add "<<llen<<endl;
        a[l^1].v%=MOD;
        a[l>>1].v=(a[l].v+a[l^1].v)%MOD;
        // cerr<<"a"<<(l^1)<<"="<<a[l^1].v<<endl;
        llen+=a[l^1].len();
        // cout<<"llen+"<<a[l^1].len()<<endl;
      }
      if(r&1){
        a[r^1].v+=fibVal(rlen-a[r^1].len()+1,rlen);
        a[r^1].add.push_back(rlen-a[r^1].len()+1);
        // cerr<<"a"<<(r^1)<<" pushed add "<<rlen-a[r^1].len()+1<<endl;
        a[r^1].v%=MOD;
        // cerr<<"a"<<(r^1)<<"="<<a[r^1].v<<endl;
        a[r>>1].v=(a[r].v+a[r^1].v)%MOD;
        rlen-=a[r^1].len();
        // cout<<"rrlen-"<<a[r^1].len()<<endl;
      }
      // if(llen>rlen) cerr<<"ERROR"<<endl;
    }
    // cout<<llen<<" "<<rlen<<endl;
    for(l>>=1;l>0;l>>=1) a[l>>1].v=(a[l].v+a[l^1].v)%MOD;
}
ll ques(int l, int r){
    int L=l,R=r;
    ll lans=0,rans=0;
    l--;r++;
    // cout<<l+M<<" "<<r+M<<endl;
    for(l+=M,r+=M;l^r^1;l>>=1,r>>=1){
      if(a[l].add.size()!=0)
        rep(i,0,(int)a[l].add.size()-1){
          if(L<=a[l].r){
            lans+=fibVal(a[l].add[i]+L-a[l].l,a[l].add[i]+a[l].len()-1);
            cout<<"dol"<<endl;
            lans%=MOD;
          }
        }
      if(a[r].add.size()!=0)
        rep(i,0,(int)a[r].add.size()-1){
          if(R>=a[r].l){
            rans+=fibVal(a[r].add[i],a[r].add[i]+R-a[r].l);
            rans%=MOD;
            cout<<"DoR"<<endl;
          }
        }
      if(~l&1) lans=(lans+a[l^1].v)%MOD;
      if(r&1) rans=(rans+a[r^1].v)%MOD;
    }
    for(l>>=1;l>0;l>>=1){
      if(a[l].add.size()!=0)
        rep(i,0,(int)a[l].add.size()-1){
            lans+=fibVal(a[l].add[i]+L-a[l].l,a[l].add[i]+R-a[l].l);
            lans%=MOD;
            // cout<<"well"<<endl;
        }
    }
    return (lans+rans)%MOD;
}
int main(){
    //freopen("triangle.in", "r", stdin);
    //freopen("triangle.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    initFib();
    int opt,l,r,num;
    buildTree();
    rep(i,1,m){
      cin>>opt;
      if(opt==1){
        cin>>l>>r;
        cout<<ques(l,r)<<endl;
      }
      if(opt==2){
        cin>>l>>r>>num;
        ADD(l,r,num);
      }
    }
    return 0;
}
