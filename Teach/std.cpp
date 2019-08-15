#include <cstring>
#include <iostream>
#include <list>
#include <cstdio>
using namespace std;
typedef unsigned short int usi;
typedef unsigned long long ull;
typedef pair<usi,ull> puu;
puu hashf(string s){
    usi x=0;
    ull b=0;
    for(string::iterator i=s.begin();i!=s.end();i++)
      if(*i>='a' && *i<='z') {x=x*26+*i-'a';b=b*26+*i-'a';}
      else if(*i>='A'&& *i<='z') {x=x*26+*i-'A';b=b*26+*i-'A';}
    return make_pair(x,b);
}
list<ull> a[70005];
int main(){
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int n,m;
    string str;
    puu t;
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin>>n>>m;
    //getchar();
    getline(cin,str);
    for(int i=1;i<=n;i++){
      getline(cin,str);
      t=hashf(str);
      a[t.first].push_back(t.second);
    }
    for(int i=1;i<=m;i++){
      getline(cin,str);
      t=hashf(str);
      //cout<<a[t.first].count(t.second)<<endl;
      int cnt=0;
      for(list<ull>::iterator j=a[t.first].begin();j!=a[t.first].end();j++)
        if(*j==t.second) cnt++;
      cout<<cnt<<endl;
    }
    return 0;
}
