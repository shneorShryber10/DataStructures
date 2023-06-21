#include <stdio.h>
#include "ADTDefs.h"
#include "HashMap.h"
#include "SingelyLinkList.h"


int main()
{
	HashMap_t* map;
	size_t size = 9;
	ADTErr err;
	

	map = MapCreate(size);

	err = MapInsert(map, 12345, 1);
	err = MapInsert(map, 133465, 2);
	err = MapInsert(map, 1234665, 3);
	err = MapInsert(map, 12364665, 3);
	err = MapInsert(map, 12348, 4);
	err = MapInsert(map, 12349, 5);
	err = MapInsert(map, 12359, 6);
	err = MapInsert(map, 12369, 7);

	err = MapInsert(map, 12369, NULL);

	/*PrintHashMap(NULL);*/
	PrintHashMap(map);
	int TheDeleteNum,index;

	err = GetItem(map, 12349, &index);

	printf("\n the item that found is: %d\n", index);

	err = MapRemove(map, 12359, &TheDeleteNum);
	PrintHashMap(map);
	printf("\nthe key we jast delete is: %d\n", TheDeleteNum);

	MapDestroi(map);

}