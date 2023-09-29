#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10;
int arr[N];
int n;

//插入排序
void insertion_sort(int *arr, int n) {
  int i, j, tmp;
  for (i = 1; i < n; i++) { //从第二个数开始
    tmp = arr[i];           //暂存待插入的数于tmp中
    j = i - 1;              //从当前位置i的左边开始搜索插入位置
    while (j >= 0 && tmp < arr[j]) { //待插入的数小于前面的数
      arr[j + 1] = arr[j];           //前面的数后移一个位置
      j--;                           //继续搜索比待插入数tmp大的数
    }
    arr[j + 1] = tmp; //待插入的数归位
  }
}
//打印数组的工具函数
void printArray(int *arr, int n) {
  for (int i = 0; i < n; ++i) {
    printf("%d", arr[i]);
    if (i < n - 1)
      printf(" ");
  }
  printf("\n");
}

int main() {
  scanf("%d", &n); // 9
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]); // 4 7 8 6 2 9 3 5 1
  }
  insertion_sort(arr, n); //执行插入排序
  printArray(arr, n);     //打印排序后数组
  return 0;
}
