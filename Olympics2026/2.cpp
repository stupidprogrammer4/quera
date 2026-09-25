#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, h, c;
    cin>>n>>h>>c;

    ll len = min(n, h+c);
    ll rem = n-len;
    ll cnt = rem/(2*h);
    rem %= 2*h;
    ll last = rem/2;

    ll ans = len*len+cnt*h*h+last*last;
    cout<<ans<<'\n';
}