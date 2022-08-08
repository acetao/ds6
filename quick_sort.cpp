#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10;
int arr[N];
int n;

void quick_sort(int* arr, int low, int high) {
	if (low > high) {
		return;
	}
	int i, j;
	i = low + rand() % (high - low + 1);//随机下标
	swap(arr[low], arr[i]);				//随机挑选的基准元素交换到最左边
	int pivot = arr[low];				//基准元素
	i = low, j = high;					//排序区间[low..high]
	while (i < j) {
		while (i < j && arr[j] > pivot)	//右侧大于基准元素的，跳过
			j--;
		while (i < j && arr[i] <= pivot)//左侧小于等于基准元素的，跳过
			i++;
		if (i < j) {
			swap(arr[i], arr[j]);		//左侧大的交换到右侧，右侧小的交换到左侧
		}
	}
	swap(arr[low], arr[i]);			//基准元素归位到位置i
	quick_sort(arr, low, i - 1);	//左半区间
	quick_sort(arr, i + 1, high);	//右半区间
}

void printArray(int* arr, int n) {
	for (int i = 0; i < n; ++i) {
		printf("%d", arr[i]);
		if (i < n - 1)printf(" ");
	}
	printf("\n");
}

int main() {
	scanf("%d", &n);				//9
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);		//4 7 8 6 2 9 3 5 1
	}
	quick_sort(arr, 0, n - 1);		//初始调用
	printArray(arr, n);				//打印排序后数组
	return 0;
}
