#include<stdio.h>
#include<malloc.h>

//优先队列左式堆
#ifndef _LeftHeap_H

struct LeftHeap; 
typedef struct LeftHeap *PriorityQueue;

/* Minimal set of priority queue operations */
/* Note that nodes wi11 be shared among several */
/* leftist heaps after a merge; the user must */
/* make sure to not use the old leftist heaps */

PriorityQueue Initialize(void);
int FindMin(PriorityQueue H); 
int IsEmpty(PriorityQueue H);
PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2);

#define Insert(X, H)(H = Insert1((X),H)
/* DeleteMin macro is left as an exercise */
PriorityQueue Insert1( int  X, PriorityQueue H );
PriorityQueue DeleteMin1(PriorityQueue H);

#endif

/* Place in implementation file */


struct LeftHeap
{
int* Element; //树的数组
int Data;     //任一节点的数据
PriorityQueue Left; //左子
PriorityQueue Right; //右子
int Np1;  //任一节点的零路径长
};

PriorityQueue root;

int FindMin(PriorityQueue H)
{
	root->Data = H->Element[1];
	return root->Data;
}

//合并左式堆的驱动例程
PriorityQueue
Merge(PriorityQueue H1, PriorityQueue H2)
{
	if (H1 == NULL)
		return H2;
	if (H2 == NULL)
		return H1;
	if (H1->Element < H2->Element)
		return Merge1(H1, H2);
	else
		return Merge1(H2, H1);
};

//合并左式堆的实际例程
static PriorityQueue
Merge1(PriorityQueue H1, PriorityQueue H2)
{
	if (H1->Left = NULL)  //single node
		H1->Left = H2;
	/* Hl->Right is already NULL,H1->Npl is already 0 */
	else
	{
		H1->Right = Merge(H1->Right, H2);
		if (H1->Left->Np1 < H1->Right->Np1)
			SwapChildren(H1);
		H1->Np1 = H1->Right->Np1 + 1;
	}
	return H1;
}

PriorityQueue
SwapChildren(PriorityQueue H)
{
	PriorityQueue M;
	M = H->Left;
	H->Left = H->Right;
	H->Right = M;
}


PriorityQueue
Insert1(int* X, PriorityQueue H)
{
	PriorityQueue SingleNode;
	SingleNode = (PriorityQueue)malloc(sizeof(struct LeftHeap));
	if (SingleNode == NULL)
		printf("Out of space!!!");
	else
	{
		SingleNode->Element = X; SingleNode->Np1 = 0;
		SingleNode->Left = SingleNode->Right = NULL;
		H = Merge(SingleNode, H);
	}
	return H;
};

//左式堆的插入例程
/* DeleteMinl returns the new tree; */
/* To get the minimum, use FindMin */
/* This is for convenience */

/*void DeleteMin()
{
	if(IsEmpty( ) )
	throw UnderflowException();

	Leftistheap *oldRoot = root;
	root = Merge(root->left, root->right);
	delete oldRoot;

}*/


PriorityQueue
DeleteMin1(PriorityQueue H)
{
	PriorityQueue LeftHeap,RightHeap;
	if (IsEmpty(H))
	{
		printf("Priority queue is empty");
		return H;
	}

	LeftHeap = H->Left;
	RightHeap = H->Right;
	free(H);
	return Merge(LeftHeap, RightHeap);
}
//左式堆的DeleteMin例程

void MakeEmpty()
{
	RecliamMemory(root);
	root = NULL;
}

int IsEmpty(PriorityQueue H)
{
	if (root == NULL)
		return H->Np1   = -1;
	else
		return H->Np1  != -1;
}

//清空子树
void RecliamMemory(PriorityQueue H)
{
	if (H != NULL)
	{
		RecliamMemory(H->Left );
		RecliamMemory(H->Right );
		delete H;
	}
}

int main()
{
	return 0;
}
