// Copyright (c) 2016, Pei Xingxin
// Filename:  1083_Moving_Tables.cc
// Description:  移桌子，奇数偶数
// Created:  12/31/2016 22:47:13
// Author:  michaelpei (Pei Xingxin), xingxinpei@gmail.com
#include <stdio.h>
#include <algorithm>

const int kMax = 201;

int test_num = 0;
int table_num = 0;
int dp[kMax];

int CalcIndex(int src) {
  if (src & 1) {
    src = (src + 1) >> 1;
  } else {
    src >>= 1;
  }
  return src;
}

int main() {
  scanf("%d", &test_num);
  while (test_num--) {
    scanf("%d", &table_num);
    memset(dp, 0, sizeof(dp));
    while (table_num--) {
      int src = 0, dest = 0;
      scanf("%d%d", &src, &dest);
      if (src > dest) std::swap(src, dest);
      src = CalcIndex(src);
      dest = CalcIndex(dest);
      for (int i = src; i <= dest; i++) {
        dp[i]++;
      }
    }
    int max = 0;
    for (int i = 0; i < kMax; ++i) {
      max = std::max(max, dp[i]);
    }
    printf("%d\n", max * 10);
  }
  return 0;
}
