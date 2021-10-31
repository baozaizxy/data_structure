#include<stdio.h>

const int NumSets = 15;
typedef int DisjSet[NumSets + 1]; 
typedef int SetType;
typedef int ElementType;

void Initialize(DisjSet S);
void SetUnion(DisjSet S, SetType Root1, SetType Root2);
SetType Find(ElementType X,DisjSet S);
	
	void
	Initialize(DisjSet S)
	{
		int i;
		for (i = NumSets; i > 0; i--)
			S[i] = 0;
	}
	/* Assumes Root1 and Root? are roots */
	/* union is a C keyword,so this routine */
	/* is named Setunion */
	void
	SetUnion(DisjSet S, SetType Root1, SetType Root2)
	{
		S[Root2] = Root1;
	}

	SetType
		Find(ElementType X, DisjSet S)
	{
		if (S[X] <= 0)
			return X;
		else
			return Find(S[X], S);
	}

	
	int main()
	{
		return 0;
	}
