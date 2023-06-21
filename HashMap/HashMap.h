#pragma once

#ifndef _HASHMAP_h__
#define _HASHMAP_h__

#include "HashMap.h"

typedef struct HashMap HashMap_t;

HashMap_t* MapCreate(size_t size);

ADTErr MapInsert(HashMap_t* map, size_t key, int item);

void PrintHashMap(HashMap_t* map);

ADTErr MapRemove(HashMap_t* map, size_t key, int* item);

void MapDestroi(HashMap_t* map);

ADTErr GetItem(HashMap_t* map, size_t key, int* item);







#endif // ! _HASHMAP_h__