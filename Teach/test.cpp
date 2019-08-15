#include <cstring>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main(){
  string str;
  cin>>str;
  str.erase(1,3);
  string::iterator it=str.begin();
  it=it++;
  cout<<*it<<endl;
  system("pause");
}
