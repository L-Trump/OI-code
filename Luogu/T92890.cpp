#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cin; using std::cout; using std::cerr; using std::endl; using std::string;
typedef long long ll;
struct node{
    int l,r,ia;
    void correct(){
      if(l<r) std::swap(l,r);
    }
    node(){
      l=r=0;
    }
    node(int _l, int _r){
      l=_l;r=_r;
      correct();
    }
    bool operator<(const node &b) const{
      return this->l<b.l;
    }
};
struct cmp{
    bool operator()(node &a, node &b){
      return a.l-a.r<b.l-b.r;
    }
};
int cnt=0;
int main(){
    int n,c,x,y;
    std::priority_queue<node> q;
    //freopen("triangle.in", "r", stdin);
    //freopen("triangle.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin>>n>>c;
    rep(i,1,n){
      cin>>x>>y;
      q.push(node(x,y));
    }
    node root,t;
    std::priority_queue<node,std::vector<node>,cmp> qt;
    //cout<<q.size()<<endl;
    bool flag=0;
    while(q.size()>1){
      root=q.top();q.pop();
      //cout<<q.size()<<endl;

      if(root.l-root.r<=c) continue;
      t=q.top(); q.pop();
      // cout<<root.l<<" "<<root.r<<" "<<t.l<<" "<<t.r<<endl;
      if(root.l-t.l>c){
        cout<<-1<<endl;
        flag=1;
        break;
      }
      while(root.l-t.l<=c&&!q.empty()){
        qt.push(t);
        t=q.top();q.pop();
        // else break;
      }
      if(root.l-t.l<=c) qt.push(t); else q.push(t);
      t=qt.top();qt.pop();
      t.l=root.r;
      t.correct();
      cnt++;
      q.push(t);
      while(!qt.empty()){
        q.push(qt.top());qt.pop();
      }
    }
    if(!flag)cout<<(q.top().l-q.top().r<=c?cnt:-1)<<endl;
    return 0;
}
