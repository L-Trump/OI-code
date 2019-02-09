#include<bits/stdc++.h>
#define per(i,l,r) for (int i = (l); i >= (r); --i)
#define rep(i,l,r) for (int i = (l); i <= (r); ++i)

using namespace std;
int main()
{
    string s;
    char p = 0;
    int cnt = 0;
    cin >> s;
    rep(i,0,(int)s.size()-1){
        if (s[i] >= '0'&&s[i] <= '9') cnt++;
        else
        {
            p = s[i];
            break;
        }
    }
    int x = cnt;
    cnt--;
    while (s[cnt] == '0'&&cnt > 0) cnt--;
    per(i,cnt,0)
        cout << s[i];
    if (p == 0) return 0;
    else
        if (p == '%') { cout << p; return 0; }
        else cout << p;
    int m = s.size() - 1;
    while (s[x + 1] == '0'&&x < m - 1) x++;
    while (s[m] == '0'&&m > x + 1) m--;
    per(i,m,x+1)
        cout << s[i];
    return 0;
}
