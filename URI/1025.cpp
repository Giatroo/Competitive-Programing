#include <bits/stdc++.h>
typedef long long int ll;
typedef long double lld;
#define fora(i, n) for (ll i = 0; i < n; i++)
#define forai(i, n) for (ll i = 1; i <= n; i++)
#define ford(i, n) for (ll i = n-1; i >= 0; i--)
#define fordi(i, n) for (ll i = n; i >= 0; i--)
#define forita(it, c) for(auto it = c.begin(); it != c.end(); it++)
#define foritd(it, c) for(auto it = c.rbegin(); it != c.rend(); it++)
#define f first
#define s second
#define sortvector(v) sort(v.begin(), v.end())
#define sortvectorby(v, f) sort(v.begin(), v.end(), f)
#define pb push_back
#define mk make_pair
#define cout1(a) cout << (a)
#define cout2(a, b) cout << (a) << " " << (b)
#define cout3(a, b, c) cout << (a) << " " << (b) << " " << (c)
#define cout1e(a) cout1(a) << endl
#define cout2e(a, b) cout2(a, b) << endl
#define cout3e(a, b, c) cout3(a, b, c) << endl
#define get1(a) cin >> (a)
#define get2(a, b) cin >> (a) >> (b)
#define get3(a, b, c) cin >> (a) >> (b) >> (c)
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) > (b) ? (a) : (b)

using namespace std;

ll n, q;
vector<ll> v;
ll a, b, t;

ll bs(ll l, ll r, ll x) {
  ll m;
  while (l <= r) {
    m = l + (r - l) / 2;
    if (v[m] >= x) r = m - 1;
    else l = m + 1;
  }

  if (l <= n && v[l] == x) return l;
  return -1;
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  get2(n, q);
  t = 1;
  while (n * q != 0) {
    v.clear();
    v.pb(0);
    fora(i, n) { get1(a); v.pb(a); }
    sortvector(v);
    cout << "CASE# " << t++ << ":" << endl;
    fora(i, q) {
      get1(a);
      if ((b = bs(1, n, a)) == -1)
        cout << a << " not found" << endl;
      else cout << a << " found at " << b << endl;
    }

    get2(n, q);
  }

  return 0;
}
