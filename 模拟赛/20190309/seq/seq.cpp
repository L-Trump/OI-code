#include <iostream>
#include <cstdio>
#include <cstring>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define MOD 1000000007
using namespace std;
typedef long long ll;
struct Mat{
    ll cont[5][5];
    int w,h;
    Mat operator*(const Mat &b) const{
        Mat c;
        c.h=this->h;
        c.w=b.w;
        rep(i,1,c.h)
            rep(j,1,c.w){
                rep(k,1,this->w)
                    c.cont[i][j]+=(this->cont[i][k]*b.cont[k][j])%MOD;
                c.cont[i][j]%=MOD;
            }
        return c;
    }
    Mat(){
        w=h=0;
        memset(cont,0,sizeof(cont));
    }
};
Mat change;
Mat qPow(Mat base, int q){
    Mat ans;
    ans.w=ans.h=base.h;
    rep(i,1,base.h) ans.cont[i][i]=1;
    if(q==0) return ans;
    while(q>0){
        if(q&1) ans=ans*base;
        base=base*base;
        q>>=1;
    }
    return ans;
}
int main(){
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    freopen("seq.in","r",stdin);
    freopen("seq.out","w",stdout);
    Mat e;
    int n,T;
    e.w=1;e.h=3;
    e.cont[1][1]=e.cont[2][1]=e.cont[3][1]=1;
    change.w=change.h=3;
    change.cont[1][2]=change.cont[2][3]=change.cont[3][1]=change.cont[3][3]=1;
    cin>>T;
    rep(i,1,T){
        Mat t;
        cin>>n;
        if(n==1||n==2||n==3) {cout<<1<<endl;continue;}
        t=qPow(change,n-3)*e;
        cout<<t.cont[3][1]%MOD<<endl;
    }
}
