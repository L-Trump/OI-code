#include <iostream>
#include <cstdio>
#include <queue>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
using namespace std;
bool isS[1<<20];
int n,m,k;
int sz[50];
int fin;
int cnt;

void sIn(){
    queue<int> q;
    queue<int> qt;
    int root,ch;
    q.push(0);
    while(!q.empty()){
      cnt++;
      while(!q.empty()){
        root=q.front();q.pop();
        rep(i,1,m){
            ch=(1<<sz[i])-1;
            for(;ch<=(1<<k)-1;ch<<=1){
                if(!isS[root^ch]){
                    if(root^ch==fin){
                        cout<<cnt<<endl;
                        return;
                    }
                    qt.push(root^ch);
                    isS[root^ch]=true;
                }
            }
        }
      }
      swap(q,qt);
    }
    cout<<-1<<endl;
}
int main(){
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    freopen("password.in","r",stdin);
    freopen("password.out","w",stdout);
    int t;
    cin>>n>>k>>m;
    rep(i,1,k){
        cin>>t;
        fin+=1<<(t-1);
    }
    rep(i,1,m) cin>>sz[i];
    sIn();
}
