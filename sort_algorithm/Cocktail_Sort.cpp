/*
鸡尾酒排序，也叫定向冒泡排序，是冒泡排序的一种改进。此算法与冒泡排序的不同处在于从低到高然后从高到低，
而冒泡排序则仅从低到高去比较序列里的每个元素。他可以得到比冒泡排序稍微好一点的效能

以序列(2,3,4,5,1)为例，鸡尾酒排序只需要访问一次序列就可以完成排序，但如果使用冒泡排序则需要四次。
但是在乱数序列的状态下，鸡尾酒排序与冒泡排序的效率都很差劲
*/

void CocktailSort(vector<int>& A )
{	
	int l = 0;
	int r = A.size() - 1;
	while(l < r)
	{
		for(auto i = l; i < r; ++i)
		{
			if (vec[i] > vec[i+1])
				swap(vec[i], vec[i+1])
		}
		r--;
		for(auto i = r; i > l; --i)
		{
			if (vec[i] < vec[i-1])
				swap(vec[i], vec[i-1])
		}
		l++;
	}
}

int main()
{
    std::vector<int> A = { 6, 5, 3, 1, 8, 7, 2, 4 };   // 从小到大定向冒泡排序
    CocktailSort(&A);
    printf("鸡尾酒排序结果：");
    for (int i = 0; i < A.size(); i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}
