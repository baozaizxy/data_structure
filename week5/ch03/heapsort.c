#include<stdio.h>

#define LeftChild(i)(2 * (i)+1)

typedef int ElementType;//取别名

void
PercDown(ElementType A[], int i, int N)
{
  int Child;
  ElementType Tmp;
  for (Tmp = A[i]; LeftChild(i) < N; i = Child)
  {
	  Child = LeftChild(i);
	  if (Child != N - 1 && A[Child + 1] > A[Child])
		  Child++;
	  if (Tmp < A[Child])//父<子，进行上移
		  A[i] = A[Child];
	  else
		  break;
  }
		A[i] = Tmp;
}

void
Heapsort(int A[], int N)
{
	int i;
	for (i = N / 2; i >= 0; i--)/*BuildHeap */  /*N/2以后为叶子节点*/
		PercDown(A, i, N);
	for (i = N - 1; i > 0; i--)
	{
		Swap(&A[0], &A[i]);/* DeleteMax*/
	    PercDown(A, 0, i);
        }
}

void Swap(ElementType* a, ElementType* b)
{
	ElementType c = *a;
	*a = *b;
	*b = c;
}

int main()
{
	int A[10] = { 5,3,0,4,9,7,8,6,1,2 };
	Heapsort(A, 10);
	for (int i = 0; i < 10; i++)
		printf("%d\n", A[i]);
	return 0;
}
