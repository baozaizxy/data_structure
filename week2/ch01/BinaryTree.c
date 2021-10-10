#include<stdio.h>
#include<malloc.h>


#ifndef _BinaryTree_H

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *BinaryTree;

BinaryTree MakeEmpty(BinaryTree T);          //初始化
Position Find(int x, BinaryTree T);   //查找功能
Position FindMin(BinaryTree T);              //查找最小子
Position FindMax(BinaryTree T);              //查找最大子
BinaryTree Insert(int x, BinaryTree T);//插入操作
BinaryTree Delete(int x, BinaryTree T);//删除操作
int Retrieve (Position P);            

#endif/* _BinaryTree_H*/

struct TreeNode
{
	int Element;
	BinaryTree Left;
	BinaryTree Right;
};



//初始化进行创建
BinaryTree MakeEmpty(BinaryTree T )
{
	if(T !=NULL )
	{
		MakeEmpty(T->Left );
		MakeEmpty(T->Right );
		free(T);

	}
	return NULL;
};

//查找X的位置
Position Find(int X, BinaryTree T)
{
	if(T == NULL)
		return NULL;
	if(X<T->Element )
		return Find(X,T->Left );
	else
		if(X>T->Element )
			return Find(X,T->Right );
		else
			return T;
};

//寻找最小元位置
Position FindMin(BinaryTree T)
{
	if(T==NULL)
		return NULL;
	else
		if(T->Left ==NULL)
			return T;
		else
			return FindMin(T->Left );
};

//寻找最大元位置
Position FindMax(BinaryTree T)
{
	if(T !=NULL)
		while(T->Right !=NULL)
			T=T->Right;
	return T;
};
 
//插入操作
BinaryTree Insert( int X, BinaryTree T)
{
	if(T==NULL)
	{
		//创建并返回一个单节点树
		T = (BinaryTree)malloc ( sizeof(struct TreeNode));
		if(T==NULL)
			printf("Out of space!");
		else
		{
			T->Element  =X;
			T->Left =T->Right =NULL;
		}
	}
	else
	if(X<T->Element  )
		T->Left =Insert(X,T->Left );
	else
	if(X>T->Element  )
		T->Right  =Insert(X,T->Right );    //其他情况下的X已经存在于树中
	return T;
};

//删除操作
BinaryTree Delete(int X, BinaryTree T )
{
	Position TmpCell;
	if(T==NULL)
		printf("Element not found");
	else
	if(X<T->Element   )
		T->Left  =Delete(X,T->Left  );
	else
	if(X>T->Element )
		T->Right  =Delete(X,T->Left  );
	else
	if(T->Left  && T->Right  )
	{
		TmpCell=FindMin( T->Right  );
		T->Element  =TmpCell->Element ;
		T->Right  =Delete(T->Element  ,T->Right  );
	}
	else
	{
		TmpCell=T;
		if(T->Left ==NULL)
			T=T->Right ;
		else if (T->Right ==NULL)
			T=T->Left ;
		free(TmpCell);
	}
	return T;
};

int main()
{
	

	return 0;
};
