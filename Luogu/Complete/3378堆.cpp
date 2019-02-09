#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define NMAX 1000000
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cin; using std::cout;  using std::endl; using std::string;
typedef long long ll;
int cnt=0;
int heap[NMAX+5]={};
inline void heapInsert(int k){
    heap[++cnt]=k;
    for(int p=cnt;heap[p>>1]>heap[p]&&p;p>>=1) std::swap(heap[p],heap[p>>1]);
    return;
}
inline int heapMin(){
    return heap[1];
}
void heapDel(){
    int now=1;
    heap[1]=heap[cnt--];
    while((now<<1)<=cnt){
      int nxt=now<<1;
      if(nxt+1<=cnt&&heap[nxt|1]<heap[nxt])nxt++;
      if(heap[nxt]<heap[now]) std::swap(heap[now],heap[nxt]);
      else break;
      now=nxt;
    }
    return;
}
int main(){
    int n,opt,k;
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin>>n;
    rep(i,1,n){
        cin>>opt;
        if(opt==1){
          cin>>k;
          heapInsert(k);
        }
        if(opt==2) cout<<heapMin()<<endl;
        if(opt==3) heapDel();
    }
    return 0;
}
