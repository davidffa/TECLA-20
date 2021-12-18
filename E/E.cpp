#include <bits/stdc++.h>

using namespace std;

#define CAP 500

int matrix[CAP][CAP];
bool vis[CAP][CAP];

int n, l, a;

int dirs[4][2] = {
    {0, 1},   // norte
    {0, -1},  // sul
    {1, 0},   // este
    {-1, 0}   // oeste
};

void dfs(int r, int c, int *size) {
  if (vis[r][c])  // se o vértice já tiver sido visitado retorna
    return;

  vis[r][c] = true;

  ++(*size);  // aumenta o tamanho da ilha

  int r0, c0;

  for (int i = 0; i < 4; ++i) {
    r0 = r + dirs[i][0], c0 = c + dirs[i][1];

    // verifica se o elemento adjacente está dentro dos limites da matriz e se a ilha tem dono
    if (r0 >= 0 && r0 < a && c0 >= 0 && c0 < l && matrix[r0][c0] != 0)
      dfs(r0, c0, size);
  }
}

void dump_vis() {
  int i, j;

  for (i = 0; i < a; ++i) {
    for (j = 0; j < l; ++j) {
      cout << (vis[i][j] ? '*' : '-');
    }
    cout << '\n';
  }
}

void solve() {
  memset(vis, false, sizeof(vis));  // seta a matriz inteira dos visitados como falso

  cin >> n >> l >> a;

  int i, j;

  for (i = 0; i < a; ++i) {
    for (j = 0; j < l; ++j) {
      cin >> matrix[i][j];
    }
  }

  int size;
  // quantidade de ilhas <-> maior ilha (vetor de tamanho n+1 pois o index é o número do milionario)
  vector<pair<int, int>> islands(n + 1);

  for (i = 0; i < a; ++i) {
    for (j = 0; j < l; ++j) {
      if (matrix[i][j] != 0 && !vis[i][j]) {
        ++islands[matrix[i][j]].first;  // aumenta a qtd de ilhas do milionário
        size = 0;
        dfs(i, j, &size);
        islands[matrix[i][j]].second = max(islands[matrix[i][j]].second, size);

        // Tira o comentário para ver como o dfs funciona
        // dump_vis();
        // cout << "--------------------------\n";
      }
    }
  }

  for (i = CAP * CAP; i; --i) {
    for (j = 1; j <= n; ++j) {
      if (islands[j].first == i) {
        cout << j << ' ' << islands[j].first << ' ' << islands[j].second << '\n';
      }
    }
  }
}

int main() {
  solve();

  return 0;
}