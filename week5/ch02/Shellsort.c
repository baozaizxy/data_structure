#include<stdio.h>

typedef int ElementType;

//缩小增量排序
void
Shellsort(ElementType A[], int N)
{
	int i, j, Increment;
	ElementType Tmp;
	for (Increment = N / 2; Increment > 0; Increment /= 2)
		for (i = Increment; i < N; i++)
		{
			Tmp = A[i];
			for (j = i; j >= Increment; j -= Increment)
				if (Tmp < A[j - Increment])
					A[j] = A[j - Increment];//将A[i]与A[i-hk]、A[i-2hk]....排序
				else
					break;
	        A[j] = Tmp;
        }
}

int main()
{
	int A[10] = { 2,4,7,6,1,8,0,9,3,5 };
	Shellsort(A, 10);
	for (int i = 0; i < 10; i++)
		printf("%d\n", A[i]);
	return 0;
}
