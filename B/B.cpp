#include <bits/stdc++.h>

using namespace std;

void solve() {
  double i, h, r, t, t2;

  cin >> i >> h >> r;

  t = (10.0 / sqrt(i)) / (h / r);

  cin >> i >> h >> r;

  t2 = (10.0 / sqrt(i)) / (h / r);

  cout << (t <= t2 ? "alimento 1\n" : "alimento 2\n");
}

int main() {
  solve();

  return 0;
}