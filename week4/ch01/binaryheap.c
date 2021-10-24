#include<stdio.h>
#include<malloc.h>



//优先队列代码
struct BinaryHeap;
typedef struct BinaryHeap *PriorityQueue;

PriorityQueue Initialize(int MaxElements);
void Destroy(PriorityQueue H); 
void MakeEmpty(PriorityQueue H);
void Insert(int X, PriorityQueue H); 
int DeleteMin(PriorityQueue H); 
int FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
int IsFull(PriorityQueue H);

/* Place in implementation file */
struct BinaryHeap
{
	int Capacity;  //代表最大值的整数
	int Size;      //堆的大小 
	int *Elements;  //一个数组
};

int MinPQSize = 20;
int MinData = 10;

//优先队列的声明
PriorityQueue
Initialize(int MaxElements)
{
	PriorityQueue a;
	if (MaxElements < MinPQSize)
	{
		printf ("Priority queue size is too smal1");
	};
	a = (PriorityQueue)malloc(sizeof(struct BinaryHeap));
	if (a== NULL)
	{
		printf ("Out of space!!!");
	};
	/* Allocate the array plus one extra for sentinel */

	a->Elements = (int*)malloc((MaxElements + 1)*sizeof(PriorityQueue));
	if (a->Elements == NULL)
		printf ("Out of space!!!");
	a->Capacity = MaxElements;
	a->Size = 0;
	a->Elements[0] = MinData;
	return a;
}

void
Destroy(PriorityQueue H)
{
	free(H->Elements);
	free(H);

}

void MakeEmpty(PriorityQueue H)
{
	H->Size = 0;
}

//优先队列的声明
/* H->Element[ 0 ] is a sentinel */
void
Insert(int X, PriorityQueue H)
{
	int i;
	if (IsFull(H))
	{
		printf("Priority queue is ful1");
		return;
	}
	for (i = ++H->Size; H->Elements[i / 2] > X; i /= 2)
		H->Elements[i] = H->Elements[i / 2];
	H->Elements[i]= X;
}

int
FindMin(PriorityQueue H)
{
	return H->Elements[1];
}

int
DeleteMin (PriorityQueue H)
	{
		int i, Child;
		int MinElement, LastElement;
		if (IsEmpty(H))
			printf("Priority queue is empty");
		return H->Elements[0];
		MinElement = H->Elements[1];
		LastElement = H->Elements[H->Size--];
		for (i = 1; i*2 <= H->Size; i = Child)
		{
			/* Find smaller child */
			Child = i * 2;
			if (Child != H->Size && H->Elements[Child + 1]
				< H->Elements[Child])
				Child++;
			/* Percolate one level */
			if (LastElement > H->Elements[Child])
				H->Elements[i] = H->Elements[Child];
			else
				break;
		}
		H->Elements[i] = LastElement;
		return MinElement;
		//在二叉堆中执行DeleteMin的函数
	}

int
IsEmpty(PriorityQueue H)
{
	return H->Size == 0;
}

int
IsFull(PriorityQueue H)
{
	return H->Size  == H->Capacity;
}

int main()
{
  return 0;
}
