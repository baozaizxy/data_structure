#include<stdio.h>
#include<malloc.h>

#ifndef _Squared_H

typedef unsigned int Index;
typedef Index Position;

Index Hash(const char *Key, int TableSize);

struct Squ;
typedef struct Squ *Squared;

Squared InitializeTable(int TableSize);
void DestroyTable(Squared H);
Position Find(char* Key, Squared H);
void Insert(char* Key, Squared H);
char* Retrieve(Position P);
Squared Rehash(Squared H);
#endif

int MinTableSize = 20;

enum KindOfEntry {Legitimate,Empty,Deleted};

struct HashEntry
{
	char *Element;
	enum KindOfEntry Info;
};

typedef struct HashEntry Cell;

struct Squ
{
	int TableSize;
	Cell* TheCells;
};

Index Hash(const char *Key, int TableSize)
{
	Index HashVal = 0;
	while (*Key != '\0')
		HashVal = (HashVal << 5) + *Key++;
	return HashVal % TableSize;
};

Squared
InitializeTable(int TableSize)
{
	Squared H;
	int i;
	if (TableSize < MinTableSize)
	{
		printf("Table size too small");
		return NULL;
	}

	H =(Squared) malloc(sizeof(struct Squ));
	if (H == NULL)
		printf("out of space!");

	//H->TableSize = NextPrime(TableSize);

	H->TheCells = (Cell*)malloc(sizeof(Cell) * H->TableSize);
	if (H->TheCells == NULL)
		printf("out of space!");
	for (i = 0; i < H->TableSize; i++)
		H->TheCells[i].Info = Empty;
	return H;
};


Position
Find(char* Key, Squared H)
{
	Position CurrentPos;
	int CollisitionNum;

	CollisitionNum = 0;
	CurrentPos = Hash( Key, H->TableSize);
	while (H->TheCells[CurrentPos].Info != Empty && H->TheCells[CurrentPos].Element == Key)
	{
		CurrentPos += 2 * ++CollisitionNum - 1;
		if (CurrentPos >= H->TableSize)
			CurrentPos -= H->TableSize;
	}
	return CurrentPos;
};

void
Insert(char* Key, Squared H)
{
	Position Pos;
	Pos = Find(Key, H);
	if (H->TheCells[Pos].Info != Legitimate)
	{
		H->TheCells[Pos].Info = Legitimate;
		H->TheCells[Pos].Element = Key;

	}
};

Squared  Rehash(Squared  H)
{
	int i, OldSize;
	Cell* OldCells;

	OldCells = H->TheCells;
	OldSize = H->TableSize;

	H = InitializeTable(2 * OldSize);
	for (i = 0; i < OldSize; i++)
		if (OldCells[i].Info == Legitimate)
			Insert(OldCells[i].Element, H);
	free(OldCells);
	return H;
};

void DestroyTable(Squared H)
{
	free(H->TheCells);
	free(H);
};

int main()
{
	return 0;
};
