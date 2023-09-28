#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e6 + 10;
int a[N];
ll tot = 0; //逆序对数量

void prt(int *arr, int n) {
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

void Merge(int *arr, int left, int mid, int right) {
  int i = left, j = mid + 1, k = 0;
  int brr[right - left + 1]; //辅助数组
  while (i <= mid || j <= right) {
    int x = (i <= mid) ? arr[i] : INT_MAX;
    int y = (j <= right) ? arr[j] : INT_MAX;
    if (x <= y) {
      brr[k++] = x;
      i++;
    } else {
      brr[k++] = y;
      j++;
      tot += mid - i + 1;  //统计逆序对
    }
  }
  for (i = 0; i < k; i++)
    arr[left + i] = brr[i];//辅助数组拷贝回原数组
}

void Merge_Sort(int *arr, int left, int right) {
  if (left >= right)
    return;
  int mid = left + (right - left) / 2; //左右半段分界点
  Merge_Sort(arr, left, mid);          //递归对左半段进行合并排序
  Merge_Sort(arr, mid + 1, right);     //递归对右半段进行合并排序
  Merge(arr, left, mid, right);        //合并
}

int main(int argc, char *argv[]) {
  int n = 10;
  for (int i = 0; i < n; i++)
    a[i] = i;
  // shuffle
  random_shuffle(a, a + n); //随机打乱
   
  //随机打乱后的结果
  prt(a, n);

  //合并排序
  Merge_Sort(a, 0, n - 1);

  //排序后结果
  prt(a, n);

  //逆序对数量
  printf("inverse pairs: %lld\n", tot);

  return 0;
}
