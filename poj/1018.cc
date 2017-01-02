// Copyright (c) 2016, Pei Xingxin
// Filename:  1018.cc
// Description:  带宽，价格问题
// Created:  12/28/2016 21:12:51
// Author:  michaelpei (Pei Xingxin), xingxinpei@gmail.com

// 设d[i][j]表示选好了前i种设备时最小带宽为j的最小总价。。
// 状态转移方程：d[i][min(j, bw[k])] = d[i-1][j] + p[k], k = 1, 2, ..., mi。。
// This problem could be solved by Greedy algorithm too

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

const int kMaxNum = 110;
const int kMaxWidth = 10010;
const int INF = 0x3f3f3f3f;

int test_num = 0;
int device_num = 0;
int bind[kMaxNum];
int price[kMaxNum];
int dp[kMaxNum][kMaxWidth];
int max_bind = -1;

void clear() {
  device_num = 0;
  max_bind = -1;
  memset(dp, 0x3f, sizeof(dp));
}

int main() {
  scanf("%d", &test_num);
  // printf("the test_num is %d\n", test_num);
  while (test_num--) {
    clear();
    scanf("%d", &device_num);
    // printf("the device_num is %d\n", device_num);

    for (int i = 1; i <= device_num; ++i) {
      int maker_num = 0;
      scanf("%d", &maker_num);
      for (int j = 1; j <= maker_num; ++j) {
        scanf("%d%d", bind + j, price + j);
        max_bind = std::max(max_bind, bind[j]);
      }
      if (i == 1) {
        for (int j = 1; j <= maker_num; ++j) {
          dp[1][bind[j]] = std::min(dp[1][bind[j]], price[j]);
        }
        continue;
      }
      for (int j = 0; j <= kMaxWidth; ++j) {
        if (dp[i - 1][j] != INF) {
          for (int k = 1; k <= maker_num; ++k) {
            if (dp[i-1][j] + price[k] < dp[i][std::min(j, bind[k])]) {
              dp[i][std::min(j, bind[k])] = dp[i-1][j] + price[k];
            }
          }
        }
      }
    }
    double Max = -1;
    for (int i = 0; i <= max_bind; ++i) {
      if (dp[device_num][i] != INF) {
        Max = std::max(Max, (double)i / dp[device_num][i]);
      }
    }
    printf("%.3f\n", Max);
  }
  return 0;
}
