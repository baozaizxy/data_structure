#include<stdio.h>
#include<malloc.h>

typedef int ElementType;

void
MSort(ElementType A[], ElementType TmpArray[],
	int Left, int Right)
{
	int Center;
	if (Left < Right)
	{
		Center = (Left + Right) / 2;
		MSort(A, TmpArray, Left, Center);
		MSort(A, TmpArray, Center + 1, Right);
		Merge(A, TmpArray, Left, Center + 1, Right);
	}
}
void
Mergesort(ElementType A[], int N)
{
	ElementType* TmpArray;
	TmpArray = (ElementType*)malloc(N * sizeof(ElementType));
	if (TmpArray != NULL)
	{
		MSort(A, TmpArray, 0, N - 1);
		free(TmpArray);
	}
	else
		printf("No space for tmp array!!!");
}

/*Lpos = start of left half, Rpos = start of right half */
void
Merge(ElementType A[], ElementType TmpArray[],
	int Lpos, int Rpos, int RightEnd)
{
	int i, LeftEnd, NumElements, TmpPos;
	LeftEnd = Rpos - 1;
	TmpPos = Lpos;
	NumElements = RightEnd - Lpos + 1;

	/*main loop*/
		while (Lpos <= LeftEnd && Rpos <= RightEnd)
			if (A[Lpos] <= A[Rpos])
				TmpArray[TmpPos++] = A[Lpos++];
			else
				TmpArray[TmpPos++] = A[Rpos++];
	while (Lpos <= LeftEnd) /* Copy rest of first half */
		TmpArray[TmpPos++] = A[Lpos++];
	while (Rpos <= RightEnd) /* Copy rest of second half */
		TmpArray[TmpPos++] = A[Rpos++];
     /*Copy TmpArray back*/
		for (i = 0; i < NumElements; i++, RightEnd--)
			A[RightEnd] = TmpArray[RightEnd];
}
int main()
{
	int A[10] = { 2,4,7,6,1,8,0,9,3,5 };
	Mergesort(A, 10);
	for (int i = 0; i < 10; i++)
		printf("%d\n", A[i]);
	return 0;
}
