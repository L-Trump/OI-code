#include <iostream>
using std::cin;using std::cerr;using std::endl;using std::cout;
int L,R,N,add_value;
long long t[400005]={},lazy[400005]={};
int a[100005]={};
void build(int idx,int l,int r){
    int mid;
    if(l==r){
        t[idx]=a[l];
        return;
    }
    mid=(l+r)/2;
    build(2*idx,l,mid);
    build(2*idx+1,mid+1,r);
    t[idx]=t[idx*2]+t[idx*2+1];
}

void lazydown(int idx,int l,int r){
    int mid;
    int lson=2*idx,rson=2*idx+1;
    lazy[lson]+=lazy[idx];
    lazy[rson]+=lazy[idx];
    mid=(l+r)/2;
    t[lson]+=lazy[idx]*(mid-l+1);
    t[rson]+=lazy[idx]*(r-mid);
    lazy[idx]=0;
}

long long query(int idx,int l,int r){
    int mid;
    if (r<L ||l>R)
        return 0;
    if (l>=L && r<=R){
        return t[idx];
    }
    //if (lazy[idx]!=0)
    lazydown(idx,l,r);
    mid=(l+r)/2;
    return query(idx*2,l,mid)+query(idx*2+1,mid+1,r);
}

void printt(){
    int i;
    for(i=1;i<=4*N;i++){
        cerr<<t[i]<<" ";
    }
    cerr<<endl;
}

void ADD(int idx,int l,int r){
    int mid;
    if (l==r && l>=L && r<=R) {
        t[idx]+=add_value;
        return;
    }
    if (l>=L && r<=R){
        t[idx]+=add_value*(r-l+1);
        lazy[idx]+=add_value;
        return;
    }
    if (r<L || l>R){
        return;
    }
    //if (lazy[idx]!=0)
    lazydown(idx,l,r);
    mid=(l+r)/2;
    ADD(idx*2,l,mid);
    ADD(idx*2+1,mid+1,r);
    t[idx]=t[idx*2]+t[idx*2+1];
}

int main(){
    int n,m,i,cao;
    cin>>n>>m;
    N=n;
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,1,n);
    for(i=1;i<=m;i++){
        cin>>cao;
        if(cao==1){
            cin>>L>>R>>add_value;
            ADD(1,1,n);
          //  printt();
        }
        if(cao==2){
            cin>>L>>R;
            cout<<query(1,1,n)<<endl;
        }
    }
}
