#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cin; using std::cout; using std::cerr; using std::endl; using std::string;
typedef long long ll;
int n,m;
struct node{
    int v,in,min,max;
    bool vis;
    std::vector<node*> edge,fa;
    node(){
      min=max=in=v=0;
      vis=0;
    }
} a[100005];
inline void creatEdge(int u, int v){
    a[u].edge.push_back(&a[v]);
    a[v].fa.push_back(&a[u]);
    a[v].in++;
}
struct cmp{
    bool operator()(node* a,node* b){
      return a->in>b->in;
    }
};
std::queue<node*> Q;
// void bfs(){
//     std::queue<node*> q;
//     std::priority_queue<node*,std::vector<node*>,cmp> qt;
//     node* root;
//     rep(i,1,n) qt.push(&a[i]);
//     while(!qt.empty()){
//       root=qt.top();qt.pop();
//       if(root->vis) continue;
//       q.push(root);
//       root->vis=1;
//       while(!q.empty()){
//         root=q.front();q.pop();
//         Q.push(root);
//         rep(i,0,(int)root->edge.size()-1)
//           if(!root->edge[i]->vis){
//             q.push(root->edge[i]);
//             root->edge[i]->vis=1;
//           }
//       }
//    }
// }
void bfs(){
    std::queue<node*> q;
    std::priority_queue<node*,std::vector<node*>,cmp> qt;
    node* root;
    rep(i,1,n) qt.push(&a[i]);
    while(!qt.empty()){
      root=qt.top();qt.pop();
      if(root->vis) continue;
      root->vis=1;
      Q.push(root);
      rep(i,0,(int)root->edge.size()-1){
        root->edge[i]->in--;
        qt.push(root->edge[i]);
      }
    }
}
int main(){
    //freopen("triangle.in", "r", stdin);
    //freopen("triangle.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    int u,v;
    cin>>n>>m;
    rep(i,1,n){
      cin>>a[i].v;
      a[i].min=a[i].max=a[i].v;
    }
    rep(i,1,m){
      cin>>u>>v;
      creatEdge(u,v);
    }
    bfs();
    std::queue<node*> q;
    q=Q;
    node* root;
    int ans=0;
    // cout<<q.size()<<endl;
    while(!q.empty()){
      root=q.front();q.pop();

      // cout<<root->v<<endl;

      if(root->fa.size()==0){
        root->max=root->min=root->v;
        continue;
      }
      root->max=root->min=root->v;
      // root->ia=0;
      rep(i,0,(int)root->fa.size()-1){
        root->max=std::max(root->max,root->fa[i]->max);
        root->min=std::min(root->min,root->fa[i]->min);
        ans=std::max(std::max(ans,root->fa[i]->max-root->v),root->v-root->fa[i]->min);

      }
    }
    // cout<<endl;
    cout<<(ans>0?ans:0)<<endl;
    return 0;
}
