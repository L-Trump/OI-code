#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define NMAX 500000
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cin; using std::cout; using std::cerr; using std::endl; using std::string;
typedef long long ll;
typedef unsigned int uint;

struct node{
    int rank,h;
    std::vector<node*> edge;
    node(){
      rank=h=0;
    }
} c[NMAX+5];

void createEdge(node *a, node *b){
    a->edge.push_back(b);
}
int cnt=0;
int zfwNode[4*NMAX+5],first[2*NMAX+5],zfwRank[4*NMAX+5];
bool v[NMAX+5]={};
void dfs(node* p){
    zfwNode[++cnt]=p->h;
    zfwRank[cnt]=p->rank;
    first[p->rank]=cnt;
    for(uint i=0;i<p->edge.size();i++){
        if(!v[p->edge[i]->rank]){
            v[p->edge[i]->rank]=true;
            p->edge[i]->h=p->h+1;
            dfs(p->edge[i]);
            zfwNode[++cnt]=p->h;
            zfwRank[cnt]=p->rank;
            v[p->edge[i]->rank]=false;
        }
    }
    return;
}

void printdfs(){
    rep(i,1,cnt) cerr<<zfwNode[i]<<" ";
    cerr<<endl;
}
int M;
void zfwBuild(){
    for(M=1;M<cnt;M<<=1);
    rep(i,1,cnt) zfwNode[M+i]=zfwNode[i];
    per(i,M-1,1) zfwNode[i]=std::min(zfwNode[i<<1],zfwNode[i<<1|1]);
}

int qMin(int l, int r){
    if(l>r) std::swap(l,r);
    int Lans=l,Rans=r;
    for(l+=M-1,r+=M+1;l^r^1;l>>=1,r>>=1){
      if(~l&1) Lans=zfwNode[Lans]<zfwNode[l^1]?Lans:l^1;
      if(r&1) Rans=zfwNode[Rans]<zfwNode[r^1]?Rans:r^1;
    }
    return zfwNode[Lans]<zfwNode[Rans]?zfwRank[Lans]:zfwRank[Rans];
}

int main(){
    int n,m,s,a,b;
    //freopen("triangle.in", "r", stdin);
    //freopen("triangle.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin>>n>>m>>s;
    rep(i,1,n) c[i].rank=i;
    rep(i,1,n-1){
        cin>>a>>b;
        createEdge(&c[a],&c[b]);
        createEdge(&c[b],&c[a]);
    }
    c[s].h=1;
    v[s]=true;
    dfs(&c[s]);
    rep(i,1,m){
      cin>>a>>b;
      cout<<qMin(first[a],first[b])<<endl;
    }
    //printdfs();
    return 0;
}
