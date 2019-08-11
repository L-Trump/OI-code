#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cin; using std::cout; using std::cerr; using std::endl; using std::string;
typedef long long ll;
struct node{
    node* to;
    int val,x,y;
    node(){
      to=NULL;
      x=y=val=0;
    }
} map[10][10],temp[10][10];
node* bigger(node *a, node *b){
    if(a->val>b->val) return a; else return b;
}
int main(){
    int n,x,y,v;
    ll ans=0;
    //freopen("triangle.in", "r", stdin);
    //freopen("triangle.out", "w", stdout);
   std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin>>n;
    while(true){
      cin>>x>>y>>v;
      if(x==0) break;
      map[x][y].val=temp[x][y].val=v;
    }
    rep(i,1,n)
      rep(j,1,n){
        map[i][j].x=temp[i][j].x=i;
        map[i][j].y=temp[i][j].y=j;
      }
    // temp[][]=map[][];
    node* root=NULL;
    rep(i,1,n)
      rep(j,1,n){
        root=bigger(&temp[i-1][j],&temp[i][j-1]);
        temp[i][j].val+=root->val;
        temp[i][j].to=root;
      }
    ans+=temp[n][n].val;
    temp[1][1].to=NULL;
    root=&temp[n][n];
    while(root->to!=NULL){
      map[root->x][root->y].val=0;
      // printf("Clear map[%d][%d].val=0\n",root->x,root->y);
      root=root->to;
    }
    map[1][1].val=0;
    rep(i,1,n)
      rep(j,1,n){
        root=bigger(&map[i-1][j],&map[i][j-1]);
        map[i][j].val+=root->val;

      }
    ans+=map[n][n].val;
    cout<<ans<<endl;
    return 0;
}
