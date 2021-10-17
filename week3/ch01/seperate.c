#include<stdio.h>
#include<malloc.h>

#ifndef _Seperate_H    //#define的变体,即#ifdef，可以实现加入自己需要的模块(源文件)

typedef unsigned int Index;
Index Hash(const char* Key, int TableSize);

struct ListNode;     //声明结构体
typedef struct ListNode *Position;  //定义ListNode指针结构体Position

struct Sep;
typedef struct Sep *Seperate;

//hash table散列表
Seperate InitializeTable(int TableSize); //初始化
Position Find (char* Key, Seperate H);  //查找
char* Retrieve (Position P);  //取回
void Insert(char* Key, Seperate H);
void DestroyTable(Seperate H);
#endif

struct ListNode
{
	char* Element;
	Position Next;
};

typedef Position List;
//列表*TheList将是一个列表数组，等一下分配

struct Sep
{
	int TableSize;
	List *TheLists;
};

int MinTableSize = 20;

Index Hash(const char* Key, int TableSize)
{
	Index HashVal = 0;
	while (*Key != '\0')
		HashVal = (HashVal << 5) + *Key++;

	return HashVal % TableSize;
};

Seperate InitializeTable(int TableSize)
{
	Seperate H;
	int i;

	if (TableSize < MinTableSize)
	{
		printf("Table size too smal");
		return NULL;
	}

	H = (Seperate)malloc(sizeof(struct Sep));
	if (H == NULL)
		printf("out of space!");
	//H->TableSize = NextPrime(TableSize);  //生成素数减少冲突
	H->TheLists  = (List*)malloc(sizeof(List) * H->TableSize);
	if (H->TheLists == NULL)
		printf("out of space!");

	for (i = 0; i < H->TableSize; i++)
	{
		//H->TheLists[i] = (Seperate)malloc(sizeof(struct ListNode));
		if (H->TheLists[i] == NULL)
			printf("out of space!");
		else
			H->TheLists[i]->Next = NULL;
	}
	return H;
};

Position
Find(char* Key, Seperate H)
{
	Position P;
	List L;
	L == H->TheLists[Hash(Key, H->TableSize)];
	P = L->Next;
	while (P != NULL && P->Element  != Key)
		P = P->Next;
	return P;
};

void
Insert(char* Key, Seperate H)
{
	Position Pos, NewCell;
	List L;
	Pos = Find(Key, H);
	if (Pos == NULL)
	{
		NewCell = (Position )malloc(sizeof(struct ListNode));
		if (NewCell == NULL)
			printf("out of space!");
		else
		{
			L = H->TheLists[Hash(Key, H->TableSize)];
			NewCell->Next = L->Next;
			NewCell->Element   = Key;
			L->Next = NewCell;
		}
	}
};

void DestroyTable(Seperate  H)
{
	Position P2, P1;
	for (int i = 0; i < H->TableSize; i++)
		P1 = H->TheLists[i]->Next;
	while (P1 != NULL)
	{
		P2 = P1;
		P1 = P2 -> Next;
		free(P2);
	}
	free(H);
};

int main()
{
	return 0;
};
