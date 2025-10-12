#ifndef LinkedListHeader
#define LinkedListHeader

typedef struct _listnode {
  int item;
  struct _listnode *next;
} ListNode;

typedef struct _linkedlist {
  int size;
  ListNode *head;
} LinkedList;

int insertSortedLL(LinkedList *ll, int item);
void alternateMergeLinkedList(LinkedList *linkedList1, LinkedList *linkedList2);
void moveOddItemsToBack(LinkedList *ll);
void moveEvenItemsToBack(LinkedList *linkedList);
void frontBackSplitLinkedList(LinkedList *linkedList, LinkedList *linkedList1, LinkedList *linkedList2);
int moveMaxToFront(ListNode **pHead);
void RecursiveReverse(ListNode **ptrHead);

void printList(LinkedList *ll);
void removeAllItems(LinkedList *ll);
ListNode *findNode(LinkedList *ll, int index);
int insertNode(LinkedList *ll, int index, int value);
int removeNode(LinkedList *ll, int index);

#endif
