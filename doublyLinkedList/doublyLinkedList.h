//typedef struct Node Node_t;
//
//typedef struct List List_t;
//
//struct List {
//
//
//	Node_t* head;
//	Node_t* tail;
//};
//
//// 1-2-3-4-5
//
//struct Node {
//
//
//	void* data;
//
//	Node_t* next;
//	Node_t* prev;
//
//};
#ifndef GENERIC_LINKED_LIST_H
#define GENERIC_LINKED_LIST_H

#define DEBUG

//typedef struct List  List;
//typedef struct ListItr;


typedef int(*CmpFunc)(void* data1, void* data2);
typedef int(*DoFunc) (void* data, void* params);

/* ASSUMPTION:
   All functions assume that initialized parameters are sent. */
List* ListCreate(void);
void        ListDestroy(List* list);

void      ListPushHead(List* list, void* data);
void 	    ListPushTail(List* list, void* data);

/* Do NOT send empty list to Pop functions!!! */
void* ListPopHead(List* list);
void* ListPopTail(List* list);

size_t      ListCountItems(List* list);
int	        ListIsEmpty(List* list);

/**************************************************************************/
/***********************List Iterator functions ***************************/
/**************************************************************************/
/* ListBegin returns the first item in the list or ListEnd for empty list. */
ListItr	    ListBegin(List* list);

/* ListEnd returns object that is out of list. */
ListItr	    ListEnd(List* list);

/* ASSUMPTION:
   The itr is not ListEnd in Next, and not ListBegin in Decrement.
   (In such cases the return value is undefined behavior - means NULL) */
ListItr	    ListNext(ListItr itr);   /* return iterator to next node. */
ListItr	    ListPrev(ListItr itr);	  /* return iterator to prev node. */


/* The itr is not ListEnd.
   (In such case the return value is undefined behavior - means NULL)    */
void* ListGetData(ListItr itr);


/* ListInsertBefore insert item before itr */
/* In case of failure, returns the input iterator */
ListItr	    ListInsertBefore(ListItr itr, void* data);
void* ListRemove(ListItr item);

/* The search DOES NOT include the to argument. */
/* In case of NOT FOUND returns the to iterator */
ListItr	    ListFindFirst(ListItr from, ListItr to, CmpFunc cmpFunc, void* data);
/* The search DOES NOT include the to argument. */
/* In case of success returns the to iterator.
              otherwise returns the iterator in wich the failure accured. */
ListItr	    ListForEach(ListItr from, ListItr to, DoFunc doFunc, void* params);


#ifdef DEBUG
/* ListPrint is only for debug (NOT part of the requirments). */
void        ListPrint(List* list, void(*print)(void*));
#endif /*_DEBUG*/

#endif /* GENERIC_LINKED_LIST_H */