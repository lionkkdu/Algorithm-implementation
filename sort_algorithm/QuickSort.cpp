// 快排  

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



