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
    int h,rank;
    bool v;
    node* father[33];
    std::vector<node*> edge;
    node(){
      h=0;
      v=false;
      rep(i,0,31) father[i]=NULL;
    }
} c[NMAX+5];

inline void createEdge(node *a, node *b){
    a->edge.push_back(b);
}

void dfs(node* root){
    rep(i,1,20){
        if(root->father[i-1]!=NULL) root->father[i]=root->father[i-1]->father[i-1];
        else root->father[i]=NULL;
    }
    rep(i,0,(int)root->edge.size()-1){
        if(!root->edge[i]->v){
            root->edge[i]->v=true;
            root->edge[i]->father[0]=root;
            root->edge[i]->h=root->h+1;
            dfs(root->edge[i]);
            root->edge[i]->v=false;
        }
    }
}

node* lca(node* a, node* b){
    int st=19;
    while(a->h<b->h) b=b->father[0];
    while(a->h>b->h) a=a->father[0];
    if(a==b) return a;
    while(a->father[0]!=b->father[0]){
        while(a->father[st]==0) st--;
        while(a->father[st]==b->father[st]) st--;
        a=a->father[st];b=b->father[st];
    }
    return a->father[0];
}

int main(){
    int n,m,s,a,b;
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    scanf("%d%d%d",&n,&m,&s);
    rep(i,1,n) c[i].rank=i;
    rep(i,1,n-1){
        scanf("%d%d",&a,&b);
        createEdge(&c[a],&c[b]);
        createEdge(&c[b],&c[a]);
    }
    c[s].h=1;
    c[s].father[0]=NULL;
    c[s].v=true;
    dfs(&c[s]);
    c[s].v=false;
    rep(i,1,m){
        scanf("%d%d",&a,&b);
        printf("%d\n",lca(&c[a],&c[b])->rank);
    }
    return 0;
}
