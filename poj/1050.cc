// Copyright (c) 2016, Pei Xingxin
// Filename:  1050.cc
// Description:  二维矩阵，最大子矩阵和
// 类似问题，最大子序列之和
// Created:  12/29/2016 19:53:48
// Author:  michaelpei (Pei Xingxin), xingxinpei@gmail.com
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

const static int kMax = 102;

int data[kMax][kMax];
int row[kMax];
int test_num = 0;

void Init() {
  scanf("%d", &test_num);
  memset(row, 0, sizeof(row));
  for (int i = 0; i < test_num; ++i) {
    for (int j = 0; j < test_num; ++j) {
      scanf("%d", &data[i][j]);
    }
  }
}

int DP(int* current_row, int array_size) {
  int max = 0;
  int sum = 0;
  for (int i = 0; i < array_size; ++i) {
    if (sum < 0) {
      sum = current_row[i];
    } else {
      sum += current_row[i];
      max = std::max(max, sum);
    }
  }
  return max;
}

int main() {
  Init();
  int max = 0;
  for (int i = 0; i < test_num; ++i) {
    memset(row, 0, sizeof(row));
    for (int j = i; j < test_num; ++j) {
      for (int k = 0; k < test_num; ++k) {
        row[k] += data[j][k];
      }
      max = std::max(max, DP(row, test_num));
    }
  }
  printf("%d\n", max);
  return 0;
}
