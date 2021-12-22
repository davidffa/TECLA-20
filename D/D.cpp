#include <bits/stdc++.h>

using namespace std;

#define mxN 20

int ans;
int n, m;
bool used[mxN];

void findSums(int sum, vector<pair<int, int>> &vec) {
  if (sum == 0) {
    int s = 0;
    for (int i = 0; i < mxN; ++i) {
      if (used[i]) s += vec[i].second;
    }
    ans = max(ans, s);

    return;
  }

  for (int i = 0; i < n; ++i) {
    if (sum - vec[i].first >= 0 && !used[i]) {
      used[i] = true;
      findSums(sum - vec[i].first, vec);
      used[i] = false;
    }
  }
}

void solve() {
  memset(used, false, sizeof(used));

  ans = 0;
  cin >> n >> m;

  int i, q, v;
  vector<pair<int, int>> vec;

  for (i = 0; i < n; ++i) {
    cin >> q >> v;
    vec.push_back(make_pair(q, v));
  }

  sort(vec.begin(), vec.end());
  findSums(m, vec);

  cout << ans << '\n';
}

int main() {
  solve();

  return 0;
}