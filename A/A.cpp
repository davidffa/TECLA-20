#include <bits/stdc++.h>

using namespace std;

void solve() {
  double v, a, f, p;
  cin >> v >> a >> f >> p;

  cout << fixed << setprecision(2);

  cout << v - (a + f * p) << '\n';
}

int main() {
  solve();

  return 0;
}