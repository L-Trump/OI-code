#include <iostream>
#include <cstdio>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define NMAX 1000000
#define INF 9223372036854775800
using namespace std;
typedef long long ll;
int m[NMAX+5]={};
int n,M;
ll zkwMin[4*NMAX+5]={};
ll zkwMax[4*NMAX+5]={};
ll qMin(int l, int r){
    ll lans=INF,rans=INF;
    for(l+=M-1,r+=M+1;l^r^1;l>>=1,r>>=1){
        if(~l&1) lans=min(lans,zfwMin[l^1]);
        if(r&1) rans=min(rans,zfwMin[r^1]);
    }
    return min(lans,rans);
}
ll qMax(int l, int r){
    ll lans=-INF,rans=-INF;
    for(l+=M-1,r+=M+1;l^r^1;l>>=1,r>>=1){
        if(~l&1) lans=max(lans,zfwMax[l^1]);
        if(r&1) rans=max(rans,zfwMax[r^1]);
    }
    return max(lans,rans);
}
void buildZkw(){
    for(int i=M;i>0;i--){
        zkwMin[i]=min(zkwMin[i>>1],zkwMin[i>>1|1]);
        zkwMax[i]=max(zkwMax[i>>1],zkwMax[i>>1|1]);
    }
}
void readm(){
    cin>>n;
    for(M=1;M<=n;M<<=1);
    rep(i,1,n){
        cin>>m[i];
        zkwMin[M+i]=zkwMin[M+i-1]+m[i];
        zkwMax[M+i]=zkwMax[M+i-1]+m[i];
    }
}
ll ans=-INF;
void tryit(){
    ll max1,min1,max2,min2,max3,min3,ans1,ans2,ans3;
    rep(i,1,n-2){
        rep(j,i+1,n-1){
            max1=qMax(1,i);
            min1=min(qMin(1,i),0);
            max2=qMax(i+1,j);
            min2=qMin(i,j);
            max3=qMax(j+1,n);
            min3=qMin(j,n);

            ans=max(ans,qMax(1,i)-qMin(1,i)+qMax(i+1,j)-qMin)
        }
    }
}
int main(){
    //freopen("jx.in","r",stdin);
    //freopen("jx.out","w",stdout);

}
