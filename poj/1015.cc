// Copyright (c) 2017, Pei Xingxin
// Filename:  1015.cc
// Description:
// Author:  michaelpei (Pei Xingxin), michaelpei@gmail.com
#include <algorithm>
#include <string>

using namespace std;

struct hp {
  int p, d, s, v;
} pre[210];

int path[25][810], dp[25][810];
int id[25], T;

int main() {
  T = 0;
  // n candidates, select m
  int n, m;
  while (scanf("%d%d", &n, &m)) {
    if (!n && !m) return 0;
    memset(path, 0, sizeof(path));
    memset(pre, 0, sizeof(pre));
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; ++i) {
      scanf("%d%d", &pre[i].p, &pre[i].d);
      pre[i].s = pre[i].p + pre[i].d;
      pre[i].v = pre[i].p - pre[i].d;
    }
    // 解决负数的问题
    int fix = m * 20;
    dp[0][fix] = 0;

    for (int i = 1; i <= m; ++i) {
      for (int k = 0; k <= fix * 2; ++k) {
        if (dp[i-1][k] >= 0) {
          for (int j = 1; j <= n; ++j) {
            // dp[i][d] 表示为i个人，差为d是时候，和为多少
            if (dp[i-1][k] + pre[j].s > dp[i][k+pre[j].v] &&
                Select(i - 1, k, j)) {
              dp[i][k+pre[j].v] = dp[i-1][k] + pre[j].s;
              path[i][k+pre[j].v] = j;
            }
          }
        }
      }
    }

    int k;
    for (k = 0; k <= fix; ++k) {
      if (dp[m][fix-k] >= 0 || dp[m][fix+k] >= 0) break;
    }
    int div = dp[m][fix-k] > dp[m][fix+k]?(fix-k):(fix+k);
    int P = (dp[m][div] + div - fix) /2;
    int D = (dp[m][div] - div + fix) /2;
    printf("Jury #%d\n", ++T);
    printf("Best jury has value %d for prosecution and valud %d for defence:\n", P, D);
    for (int i = 0, j = m, k = div; i < m; ++i) {
      id[i] = path[j][k];
      k -= pre[id[i]].v;
      --j;
    }
    sort(id, id+m);
    for (int i = 0; i < m; ++i) {
      printf(" %d", id[i]);
      printf(" \n\n");
    }
  }
  return 0;
}
