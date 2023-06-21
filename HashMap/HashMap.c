#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "ADTDefs.h"
#include "singelyLinkList.h"
#include "HashMap.h"

struct HashMap
{
	Pair_t** dataTable;
	size_t tableSize;// Fixed size
	size_t numOfitem; // 
	size_t tableBucket;
};



HashMap_t* MapCreate(size_t size)
{
	assert(size > 0);

	HashMap_t* map = calloc(1, sizeof(HashMap_t));
	if (!map)
	{
		return NULL;
	}

	map->dataTable = (Pair_t**)calloc(size, sizeof(Pair_t*));

	if (!map->dataTable)
	{
		free(map);
		return NULL;
	}
	map->tableSize = size;

	return map;

}

ADTErr MapInsert(HashMap_t* map, size_t key, int item)
{ 
	assert(map);

	int pos = key % map->tableSize;

	Pair_t* pair = calloc(1, sizeof(Pair_t));
	if (pair == NULL)
	{
		return ERR_ALLOCATION_FAILED;
	}

	pair->data = item;
	pair->key = key;

	if (!map->dataTable[pos])
	{
		if ((float)(map->tableBucket + 1) / map->tableSize > 0.7)
		{
			return ERR_OVERFLOW;
		}
		++map->tableBucket;
	}
	else
	{
		Pair_t* temp = map->dataTable[pos];

		while (temp)
		{
			if (temp->key == key) {

				return ERR_BLABLABLA;// dup
			}
			temp = temp->next;
		}
		
	}
	map->dataTable[pos] = ListInsertHead(map->dataTable[pos], pair);
	map->numOfitem++;

	return ERR_OK;
}

void PrintHashMap(HashMap_t* map)
{										
	assert(map);

	size_t size = map->tableSize;
	int num = 1;
	for (int i = 0; i < size; i++)
	{
		if (map->dataTable[i])
		{
			printf("\n\tindex %d is:\n------------------------------ ", num++);
			PrintList(map->dataTable[i]);
		}
	}
}
ADTErr MapRemove(HashMap_t* map, size_t key, int* item)
{
	assert(map || item);
	

	Pair_t* temp;

	int pos = key % map->tableSize;

	int size = map->tableSize;


	map->dataTable[pos] = ListRemovByKey(map->dataTable[pos], key, &temp);

	if (!temp || temp->key != key)
	{
		return ERR_BLABLABLA;
	}
	*item = temp->data;

	free(temp);

	--map->numOfitem;

	if (!map->dataTable[pos])
	{
		--map->tableBucket;
	}
	return ERR_OK;
}
void MapDestroi(HashMap_t* map)
{
	if (!map)
	{
		return;
	}

	for (int i = 0; i < map->tableSize; i++)
	{
		Pair_t* temp;

		while (map->dataTable[i])
		{
			temp = map->dataTable[i]->next;
			free(map->dataTable[i]);
			map->dataTable[i] = temp;
		}
	}
	free(map->dataTable);
	free(map);

}


ADTErr GetItem(HashMap_t* map, size_t key, int* item)
{
	assert(map && item);

	int pos = key % map->tableSize;

	Pair_t* temp = map->dataTable[pos];

	if (!temp)
	{
		return ERR_BLABLABLA;//wrong index
	}

	Pair_t* curPairSearch = temp;
	while (curPairSearch)
	{
		if (curPairSearch->key == key) {
			*item = curPairSearch->data;
			return ERR_OK;
		}
		curPairSearch = curPairSearch->next;
	}


	return ERR_BLABLABLA;//not found;

}
