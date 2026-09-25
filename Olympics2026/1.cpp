#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a1, a2, a3, b1, b2, b3, c1, c2, c3;
    cin>>a1>>a2>>a3;
    cin>>b1>>b2>>b3;
    cin>>c1>>c2>>c3;

    int a = a1+2*a2+a3,
    b = b1+2*b2+b3,
    c = c1+2*c2+c3;

    int ans=1, mx=a;
    if (b > mx) ans=2, mx=b;
    if (c > mx) ans=3, mx=c;

    cout<<ans<<'\n';
}
