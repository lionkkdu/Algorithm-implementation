// 我们用简单的公式来描述一下堆的定义就是：

// 进行堆排序必须了解 堆的定义才能 理解堆排序	

// 大顶堆：arr[i] >= arr[2i+1] && arr[i] >= arr[2i+2]  

// 小顶堆：arr[i] <= arr[2i+1] && arr[i] <= arr[2i+2]  

// 分类 -------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- O(nlogn)
// 最优时间复杂度 ---- O(nlogn)
// 平均时间复杂度 ---- O(nlogn)
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 不稳定

// 在数据量尤其巨大的时候它比快速排序的时间复杂度更稳定的低，所以std::sort处理最大数据量的时候使用堆排序

#include <stdio.h> 
#include <iostream>

void HeapAjust(int a[], int i, int size)
{
	int l_child = 2*i + 1;
	int r_child = 2*i + 2;
	int max = i; 				// 选出当前节点与其左右孩子中最大的值
	if (l_child < size && a[l_child] > a[max])
		max = l_child;
	if (r_child < size && a[r_child] > a[max])
		max = r_child;
	if (max != i)
	{
		swap(a[i], a[max]);		// 把当前结点和它的最大(直接)子节点进行交换
		HeapAjust(a, i, size);	// 递归调用，继续从当前结点向下进行堆调整
	}

}

int BuildHeap(int a[], int n)
{
	int heap_size = n;
	for(int i = heap_size/2 - 1; i > 0; i--)   //堆排序是从二叉树最下面第一个非叶子节点开始的，这就是其计算的公式
		HeapAjust(a, i, heap_size);						

	return heap_size;
}


void HeapSort(int a[], n)
{
	int heap_size = BuildHeap(a, n);	//从小到大排序，所以建立一个最大堆，(如果从大到小排序，可以建立一个最小堆)
	// 每次递归调用完成之后，就有一个元素排序完成，所以heap的大小减小 1，直到小于1，排序完成
	while(heap_size > 1) 
	{
		swap(a[0], a[--heap_size]);
		HeapAjust(a, 0, heap_size);
	}
}


int main()
{
    int A[] = { 5, 2, 9, 4, 7, 6, 1, 3, 8 };// 从小到大堆排序
    int n = sizeof(A) / sizeof(int);
    HeapSort(A, n);
    printf("堆排序结果：");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}