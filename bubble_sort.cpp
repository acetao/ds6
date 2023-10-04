#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

const int N = 1e7 + 10;
int arr[N];

// 冒泡排序
void bubble_sort(int *arr, int n) {
  for (int i = 0; i < n - 1; ++i) {
    int flag = 1; // 标记一趟排序是否发生了交换
    for (int j = 0; j < n - 1 - i; j++) {
      if (arr[j] > arr[j + 1]) { // 前大后小，需要交换
        int t = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = t;
        flag = 0; // 发生了交换，标记flag=0
      }
    }
    if (flag == 1) // 一趟排序结束，没有发生交换，说明序列有序
      break;       // 不用再进行下一趟排序了，结束
  }
}
// 打印数组的工具函数
void printArray(int *arr, int n) {
  for (int i = 0; i < n; ++i) {
    printf("%d", arr[i]);
    if (i < n - 1)
      printf(" ");
  }
  printf("\n");
}

int main() {
  int n;
  scanf("%d", &n); // 9
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]); // 4 7 8 6 2 9 3 5 1
  }
  bubble_sort(arr, n); // 执行冒泡排序
  printArray(arr, n);  // 打印排序后数组
  return 0;
}
