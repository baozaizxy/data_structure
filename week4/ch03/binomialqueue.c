#include<stdio.h>
#include<malloc.h>

struct BinNode;
typedef struct BinNode *Position;

struct Collection;
typedef struct Collection* BinQueue;

BinNode Initialize(int MaxElements);
int DeleteMin(BinNode H);
BinNode  CombineTrees(BinNode T1 ,BinNode T2);


struct BinNode    //节点
{
	int Element;//数据
	Position  LeftChild;//儿子
	Position  NextSibling;//兄弟
};

int MaxTrees = 10;

struct Collection
{
	int CurrentSize; //节点数目
	BinQueue TheTrees[MaxTrees]; 
};
//二项队列类型声明

/* Return the result of merging equal-sized Tl and T2 */

int Capacity = 20;

Position
CombineTrees(Position T1, Position T2)
{
	if (T1->Element > T2->Element)
		return CombineTrees(T2, T1);
	T2->NextSibling = T1->LeftChild;
	T1->LeftChild = T2;
	return T1;
}
		//合并同样大小的两棵二项树的例程
		/* Merge two binomial queues */
		/* Not optimized for early termination */ 
        // Hl contains meroed result dya
BinQueue
Merge(BinQueue H1, BinQueue H2)
{
	Position T1, T2, Carry = NULL;
	int i, j;

	if (H1->CurrentSize + H2->CurrentSize > Capacity)
		printf("Merge would exceed capacity");
	H1->CurrentSize += H2->CurrentSize;
	for (i = 0, j = 1; j <= H1->CurrentSize; i++, j *= 2)
	{
		T1 = H1->TheTrees[i]; T2 = H2->TheTrees[i];
		switch (!!T1 + 2 * !!T2 + 4 * !!Carry)
		{
		case 0: /* No trees */
		case 1: /* only H1 */
			break;
		case 2: /* Only H2 */
			H1->TheTrees[i] = T2;
			H2->TheTrees[i] = NULL;
			break;
		case 4: /* only Carry */
			H1->TheTrees[i] = Carry;
			Carry = NULL;
			break;
		case 3 :/* H1 and H2 */
				Carry = CombineTrees(T1, T2);
				H1->TheTrees[i] = H2->TheTrees[i] = NULL;
				break;
			case 5:/* Hl and Carry */
				Carry = CombineTrees(T1, Carry);
				H1->TheTrees[i] = NULL;
				break;
			case 6: /* H2 and Carry */
				Carry = CombineTrees(T2, Carry);
				H2->TheTrees[i] = NULL;
				break;
			case 7: /* All three */
				H1->TheTrees[i] = Carry;
				Carry = CombineTrees(T1, T2);
				H2->TheTrees[i] = NULL;
				break;
		}
	}
	return H1;
}
	//合并两个优先队列的例程



Position
DeleteMin(BinQueue H)
{
	int i, j;
	int MinTree;   /* The tree with the minimum item */
	BinQueue DeletedQueue;
	Position DeletedTree;
	Position OldRoot;
	Position MinItem;

	if (IsEmpty( H))
	{
		printf("Empty binomial queue");
		return NULL;
	}

	for (i = 0; i < MaxTrees; i++)
	{
		if (H->TheTrees[i]
			&&
			H->TheTrees[i]->Element < MinItem)
		{
			/* Update minimum */
			MinItem = H->TheTrees[i]->Element;
			MinTree = i;
		}
	}

	DeletedTree = H->TheTrees[MinTree];
	OldRoot = DeletedTree;
	DeletedTree = DeletedTree->LeftChild;
	free(OldRoot);

	//DeletedQueue = Initialize();
	DeletedQueue->CurrentSize = (1 << MinTree) - 1;
	for (j = MinTree - 1; j >= 0; j--)
	{
		DeletedQueue->TheTrees[j] = DeletedTree;
		DeletedTree = DeletedTree->NextSibling;
		DeletedQueue->TheTrees[j]->NextSibling = NULL;
	}
	H->TheTrees[MinTree] = NULL;
	H->CurrentSize -= DeletedQueue->CurrentSize + 1;
	Merge(H, DeletedQueue);
	return MinItem;
}
	//二项队列的DeleteMin

int IsEmpty(BinQueue H)
{
	if (H->CurrentSize == 0)
		return 1;
}

int main()
{
  return 0;
}
