#include <iostream>
#include <cstdio>
using std::cin;using std::cout;using std::cerr;using std::endl;

struct node{
    long long lazy,sum;
    int left,right;
    node *ls,*rs;
    node(){
        lazy=sum=left=right=0;
        ls=rs=NULL;
    }
    node(int _left, int _right){
        lazy=sum=0;
        left=_left;
        right=_right;
        ls=rs=NULL;
    }
    int dis(){
        return right-left+1;
    }
};

node* root;
long long a[100005]={};

node* create(){
    return new node;
}

node* create(int l, int r){
    return new node(l,r);
}


void lazydown(node* p){
    long long lz=p->lazy;
    node *ls=p->ls, *rs=p->rs;
    p->lazy=0;
    ls->lazy+=lz;
    rs->lazy+=lz;
    ls->sum+=lz*ls->dis();
    rs->sum+=lz*rs->dis();
}

long long query(node* p,int L,int R){
    int l=p->left,r=p->right;
    node *ls=p->ls, *rs=p->rs;
    if(r<L || l>R) return 0;
    if(l>=L && r<=R){
        return p->sum;
    }
    lazydown(p);
    return query(ls,L,R)+query(rs,L,R);
}

void build(node* p){
    int l=p->left,r=p->right;
    if(l==r){
        p->sum=a[l];
        return;
    }
    int mid=(l+r)/2;
    p->ls=create(l,mid);
    p->rs=create(mid+1,r);
    build(p->ls);
    build(p->rs);
    p->sum=p->ls->sum+p->rs->sum;
}

void add(node* p, int L, int R, long long k){
    int l=p->left,r=p->right;
    node *ls=p->ls, *rs=p->rs;
    if (r<L || l>R) return;
    if (l>=L && r<=R){
        p->sum+=k*p->dis();
        p->lazy+=k;
        return;
    }
    lazydown(p);
    add(ls,L,R,k);
    add(rs,L,R,k);
    p->sum=ls->sum+rs->sum;
    return;
}

int main(){
    int n,m,i,opt,L,R;
    long long k;
    cin>>n>>m;
    root=create(1,n);
    for(i=1;i<=n;i++){
        cin>>a[i];
      //  a[i]%=p;
    }
    build(root);
    for(i=1;i<=m;i++){
        cin>>opt;
        if (opt==2){
            cin>>L>>R;
            cout<<query(root,L,R)<<endl;
        }
        if (opt==1){
            cin>>L>>R>>k;
            add(root,L,R,k);
        }
    }
}
