#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using std::cerr;using std::cout;using std::cin;using std::endl;
typedef long long ll;
ll fib[46]={};
ll collected[46];

void build(){
    int i;
    fib[1]=fib[2]=1;
    for(i=3;i<=46;i++){
        fib[i]=fib[i-1]+fib[i-2];
    }
    // cout<<fib[44];
}

int main(){
    int i,t,cnt,c,j;
    ll n=0;
    build();
    cin>>t;
    for(i=1;i<=t;i++){
        cin>>n;
        cnt=0;
        c=45;
        cout<<n<<"=";
        while(n>0&&c>=0){
          c--;
          if(n>=fib[c]){
            cnt++;
            collected[cnt]=fib[c];
            n-=fib[c];
          }
        }
        for (j=cnt;j>1;j--){
          cout<<collected[j]<<"+";
        }
        cout<<collected[1]<<endl;
    }
    // for (i=1;i<=44;i++){
    //   cout<<fib[i]<<endl;
    // }
}
