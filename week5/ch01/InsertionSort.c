#include<stdio.h>

typedef int ElementType;

void
InsertionSort(ElementType A[], int N)
{
int j, P;

ElementType Tmp;
    for (P = 1; P < N; P++)
    {
	 Tmp = A[P];
     for (j = P; j > 0 && A[j - 1] > Tmp; j--)//for循环，通过j--逐步向左进行比较并使Tmp与之交换直到A[j-1]<Tmp
     A[j] = A[j - 1];
     A[j] = Tmp;
    }
}

int main()
{
    int A[10] = { 2,4,7,6,1,8,0,9,3,5 };
    InsertionSort(A, 10);
    for (int i = 0; i < 10; i++)
        printf("%d\n", A[i]);
    return 0;
}
