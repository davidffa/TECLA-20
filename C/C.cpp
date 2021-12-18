#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, total = 0, arr[6];

  memset(arr, 0, sizeof(arr));

  while (cin >> n) {
    if (n == -1) break;

    total++;

    if (n >= 95)
      ++arr[5];
    else if (n >= 85)
      ++arr[4];
    else if (n >= 75)
      ++arr[3];
    else if (n >= 50)
      ++arr[2];
    else if (n >= 30)
      ++arr[1];
    else
      ++arr[0];
  }

  cout << total << '\n';

  cout << fixed << setprecision(1);

  for (int i = 0; i < 6; ++i) {
    cout << ((double)arr[i] / total * 100) << "%\n";
  }
}

int main() {
  solve();

  return 0;
}