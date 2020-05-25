// 快排  

// 分类 ------------ 内部比较排序
// 数据结构 --------- 数组
// 最差时间复杂度 ---- 每次选取的基准都是最大（或最小）的元素，导致每次只划分出了一个分区，需要进行n-1次划分才能结束递归，时间复杂度为O(n^2)
// 最优时间复杂度 ---- 每次选取的基准都是中位数，这样每次都均匀的划分出两个分区，只需要logn次划分就能结束递归，时间复杂度为O(nlogn)
// 平均时间复杂度 ---- O(nlogn)
// 所需辅助空间 ------ 主要是递归造成的栈空间的使用(用来保存left和right等局部变量)，取决于递归树的深度，一般为O(logn)，最差为O(n)       
// 稳定性 ---------- 不稳定

#include <iostream>
#include <assert>

int CalPoint(int a, int left, int right)
{
	int p_val = a[right];
	int tail = left - 1;
	for (int i = left; i < right, i ++)
	{
		if (a[i] < p_val)
		{
			swap(a[i], a[++tail]);
		}
	}
	swap(a[tail + 1], a[right]);

	return tail + 1;
}


void QuickSort(int a, int left, int right)
{
	if (left >= right) 
		return ;
	int p_idx = CalPoint(a, left, right);

	QuickSort(a, left, p_idx - 1);
	QuickSort(a, p_idx + 1, right);
}

// 非递归
void QuickSortNoRecursive(int a, int left, int right)
{
	assert(a);
	stack<int> s;
	s.push(left);
	s.push(right);
	while(!s.empty())
	{
		int r = s.top();
		s.pop();
		int l = s.top();
		s.pop();

		int p_idx = CalPoint(a, l, r);
		if(l < p_idx - 1)
		{
			s.push(l);
			s.push(p_idx - 1);
		}
		if(p_idx + 1 < r)
		{
			s.push(p_idx + 1);
			s.push(r);
		}
	}
}

int main()
{
	int a[] = {6, 5, 3, 1, 8, 7, 2, 4 };
	int n = sizeof(a) / sizeof(int);
	QuickSort(a, 0, n - 1);
	printf("插入排序的计算结果");
	for(int i = 0; i < n ; i++)
	{
		printf("%d",i );
	}
	system("pause");
	return 0 ;
}



