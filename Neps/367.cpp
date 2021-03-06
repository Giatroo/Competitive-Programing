#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double lld;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

#define fr(i, n) for (ll i = 0; i < n; i++)
#define frr(i, n) for (ll i = 1; i <= n; i++)
#define frit(it, c) for(auto it = c.begin(); it != c.end(); it++)

#define sortvector(v) sort(v.begin(), v.end())
#define sortvectorby(v, f) sort(v.begin(), v.end(), f)

#define pb push_back
#define mk make_pair
#define f first
#define s second

#define debug(x) #x << " = " << x << " "

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;
const ll M = 1000000007;
// ===================================================== //

int r, k;
int dp[112][123][21];

int f(int ini, int cursum, int curk) {
  int sum = 0;

  // cout << debug(ini) << debug(cursum) << debug(curk) << endl;

  if (curk == k-1) {
    if (cursum == r) return 1;
    else return 0;
  }

  int dpm = dp[ini][cursum][curk];
  if (dpm != -1) return dpm;

  for (int i = ini+1; i <= r-((k-1-curk)*ini); i++) {
    sum += f(i, cursum+i, curk+1);
  }

  return dp[ini][cursum][curk] = sum;
}

int main(int argc, char const *argv[]) { fastio;
  cin >> r >> k;

  fr (i, r+1) fr (j, r+1) fr (a, k+1) dp[i][j][a] = -1;

  int sum = 0;
  for (int i = 1; i <= r; i++) {
    sum += f(i, i, 0);
  }

  cout << sum << endl;


  return 0;
}
