// 插入排序
#include <iostream>
// #include <>

int main()
{
	int a[] = {6, 5, 3, 1, 8, 7, 2, 4 };
	int n = sizeof(a) / sizeof(int);
	InsertionSort(a, n);
	printf("插入排序的计算结果");
	for(int i = 0; i < n ; i++)
	{
		printf("%d",i );
	}
	system("pause");
	return 0 ;
}

void InsertionSort(int a, int n)
{
	for(int i = 1; i < n; i ++)
	{
		int get = a[i];   // 每次循环有手牌固定
		int j = i - 1;	// 每次循环右手牌前一个值
		while( j >=0; a[j] > get)
		{
			a[j + 1 ] = a[i];
			j -- ;
		}
		a[j + 1] = get;
	}
}