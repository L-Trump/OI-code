#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define rep(i, l, r) for(int i = (l); i <= (r); ++i)
#define per(i, l, r) for(int i = (l); i >= (r); --i)
using std::cin; using std::cout; using std::cerr; using std::endl; using std::string;
typedef long long ll;
int c[150]={};
string a,b;
int n=0,lena,lenb;
char ch,cha,chb;
int main(){
    //freopen("triangle.in", "r", stdin);
    //freopen("triangle.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    cout.tie(0);
    cin>>n;
    rep(i,1,26){
      cin>>ch;
      c[ch-'a']=i;
    }
    rep(i,1,n){
      a=b="";
      cin>>a>>b;
      lena=a.length();
      lenb=b.length();
      if(a==b){cout<<"="<<endl;continue;}
      rep(j,0,std::max(lena,lenb)-1){
        cha=a[j];chb=b[j];
        if(j>lena-1){cout<<"<"<<endl;break;}
        if(j>lenb-1){cout<<">"<<endl;break;}
        if(c[cha-'a']>c[chb-'a']){cout<<">"<<endl;break;}
        if(c[cha-'a']<c[chb-'a']){cout<<"<"<<endl;break;}
      };
    }
    return 0;
}
