#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll mod=1e9+7, inv3=333333336;
const int maxk=51;

ll fact[maxk], stirling[maxk][maxk];
int K;

struct matrix {
    ll a[4][4][maxk];
};

matrix multiply(matrix &a, matrix &b) {
    matrix c={};
    for (int i=0; i<4; i++)
        for (int t=0; t<4; t++)
            for (int j=0; j<4; j++)
                for (int p=0; p<=K; p++) {
                    if (!a.a[i][t][p]) continue;
                    for (int q=0; p+q<=K; q++) {
                        if (!b.a[t][j][q]) continue;
                        c.a[i][j][p+q] = (c.a[i][j][p+q]+a.a[i][t][p]*b.a[t][j][q])%mod;
                    }
                }
    return c;
}

matrix power(matrix a, ll n) {
    matrix ans={};
    for (int i=0; i<4; i++)
        ans.a[i][i][0] = 1;

    while (n) {
        if (n & 1)
            ans = multiply(ans, a);
        a = multiply(a, a);
        n >>= 1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    fact[0] = 1;
    stirling[0][0] = 1;
    for (int i=1; i<=50; i++) {
        fact[i] = fact[i-1]*i%mod;
        for (int j=1; j<=i; j++)
            stirling[i][j] = (stirling[i-1][j-1]+j*stirling[i-1][j])%mod;
    }

    int T;
    cin>>T;
    while (T--) {
        ll n;
        cin>>n>>K;

        matrix base={};
        base.a[0][0][0] = 1;
        for (int d=1; d<=3; d++) {
            base.a[d][0][0] = inv3;
            for (int last=1; last<=3; last++) {
                base.a[d][last][0] = inv3;
                if (d == last)
                    base.a[d][last][0] = (base.a[d][last][0]+1)%mod;
                if (last < d)
                    base.a[d][last][1] = inv3;
            }
        }

        matrix ans = power(base, n);
        ll result=0;
        for (int p=0; p<=K; p++) {
            ll coefficient=0;
            for (int d=1; d<=3; d++)
                coefficient = (coefficient+ans.a[d][0][p])%mod;
            result = (result+stirling[K][p]*fact[p]%mod*coefficient)%mod;
        }

        cout<<result<<'\n';
    }
}