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

// 堆排序由于对数据的读取没有任何规律性，跳动读取，所以对cpu不友好
// 之所以这么说是因为cpu读取数据是从cache中读取的，而cache中的数据(
//   一般认为读取数据遵从两个原则：temporal locality,也就是不久前读取过的一个数据，在之后很可能还会被读取一遍
//   另一个叫spatial locality，也就是说读取一个数据，在它周围内存地址存储的数据也很有可能被读取到
// 	)是根据局部性原理来缓存的，
// 局部性原理就是读取常用数据和其地址周围的数据到cache中，判断cpu会使用这些读取过来的数据，而
// 堆排序对数据的读取方式会导致需要使用的数据内存地址相差较远没有关联性，所以常常需要去内存中读取，
// 加大了数据读取的开销，

// 但是快排使用分而治之的原来，会在一小部分内存地址之间进行读取，相对有堆排序而言，从cache中读取数据的成本要低很多

// 大顶堆结构就是  父节点一定比子节点数值大，但是子节点中左节点和右节点的大小无从得知

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
	// 堆排序是从二叉树最下面第一个非叶子节点开始的，这就是其计算的公式
	// 索引逐渐变小，会向二叉树的顶层移动,最后判断定点是不是二叉树的最大值
	for(int i = heap_size/2 - 1; i > 0; i--)   
		HeapAjust(a, i, heap_size);	 // 这个方法调整二叉树的结构，让以i为定点的区域二叉树形成大顶堆结构

	return heap_size;
}


void HeapSort(int a[], n)
{
	int heap_size = BuildHeap(a, n);	//从小到大排序，所以建立一个最大堆，(如果从大到小排序，可以建立一个最小堆)
	// 每次递归调用完成之后，就有一个元素排序完成，所以heap的大小减小 1，直到小于1，排序完成
	while(heap_size > 1) 
	{
		// 将顶部的最大值放到最下面，heap_size减小1，将其排除在调整范围之外，视为已经调整的好的序列
		swap(a[0], a[--heap_size]);
		// 调整之后大顶推的数据大小发生了混乱，所以继续递归调整堆的结构并排序
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