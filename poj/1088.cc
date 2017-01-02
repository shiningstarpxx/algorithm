// Copyright (c) 2017, Pei Xingxin
// Filename:  1088.cc
// Description:  滑雪，上下左右
// Created:  01/01/2017 17:38:08
// Author:  michaelpei (Pei Xingxin), xingxinpei@gmail.com
#include <stdio.h>
#include <algorithm>

int row = 0, column = 0;
const int kMax = 101;
int data[kMax][kMax];
int dp[kMax][kMax];

int DFS(int i, int j) {
  if (dp[i][j] != -1) return dp[i][j];
  int tmp_max = 0;
  if (j - 1 >= 0 && data[i][j] > data[i][j-1]) {
    tmp_max = std::max(tmp_max, DFS(i, j-1));
  }
  if (j + 1 < column && data[i][j] > data[i][j+1]) {
    tmp_max = std::max(tmp_max, DFS(i, j+1));
  }
  if (i - 1 >=0 && data[i][j] > data[i-1][j]) {
    tmp_max = std::max(tmp_max, DFS(i-1, j));
  }
  if (i + 1 < row && data[i][j] > data[i+1][j]) {
    tmp_max = std::max(tmp_max, DFS(i+1, j));
  }
  return dp[i][j] = tmp_max + 1;
}

int main() {
  scanf("%d%d", &row, &column);
  memset(dp, -1, sizeof(dp));

  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < column; ++j) {
      scanf("%d", &data[i][j]);
    }
  }

  int g_max = 0;
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < column; ++j) {
        dp[i][j] = DFS(i, j);
        g_max = std::max(g_max, dp[i][j]);
    }
  }
  printf("%d\n", g_max);
}
