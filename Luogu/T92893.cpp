#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, l, r) for (int i = (l); i >= (r); --i)
using std::cin; using std::cout; using std::cerr; using std::endl; using std::string;
typedef long long ll;
int main(){
    int t,n,a[1005]={};
    //freopen("triangle.in", "r", stdin);
    //freopen("triangle.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin>>t;
    rep(nnnn,1,t){
      int cnt=0;
      std::memset(a,0,sizeof(a));
      cin>>n;
      rep(i,1,n) cin>>a[i];
      std::sort(a+1,a+n+1);
      rep(i,1,n-2){
        if(a[i]>0) break;
        if(a[i]==a[i+1]) continue;
        int j=i+1,k=n;
        while(a[j]==a[j+1]) j++;
        while(a[k]==a[k-1]) k--;
        while(j<k){
          if(a[i]+a[j]+a[k]==0&&a[i]!=a[j]&&a[j]!=a[k]){
            cnt++;j++;k--;
          } else
          if(a[i]+a[j]+a[k]<0) j++; else
          if(a[i]+a[j]+a[k]>0) k--;
          while(a[j]==a[j+1]) j++;
          while(a[k]==a[k-1]) k--;
        }
      }
      cout<<cnt<<endl;
    }
    return 0;
}
