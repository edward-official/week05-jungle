#include <stdio.h>
#include <stdlib.h>
#define True 1
#define False 0
typedef struct _listnode {
  int item;
  struct _listnode *next;
} ListNode;      // You should not change the definition of ListNode
typedef struct _linkedlist {
  int size;
  ListNode *head;
} LinkedList;      // You should not change the definition of LinkedList


void moveOddItemsToBack(LinkedList *ll);
void printList(LinkedList *ll);
void removeAllItems(LinkedList *ll);
ListNode *findNode(LinkedList *ll, int index);
int insertNode(LinkedList *ll, int index, int value);
int removeNode(LinkedList *ll, int index);


int main() {
  LinkedList ll;
  int c, i, j;
  c = 1;

  // Initialize the linked list as an empty linked list
  ll.head = NULL;
  ll.size = 0;

  printf("1: Insert an integer to the linked list:\n");
  printf("2: Move all odd integers to the back of the linked list:\n");
  printf("0: Quit:\n");

  while (c != 0) {
    printf("Please input your choice(1/2/0): ");
    scanf("%d", &c);

    switch (c) {
      case 1:
        printf("Input an integer that you want to add to the linked list: ");
        scanf("%d", &i);
        j = insertNode(&ll, ll.size, i);
        printf("The resulting linked list is: ");
        printList(&ll);
        break;
      case 2:
        moveOddItemsToBack(&ll); // You need to code this function
        printf("The resulting linked list after moving odd integers to the back of the linked list is: ");
        printList(&ll);
        break;
      case 0:
        removeAllItems(&ll);
        break;
      default:
        printf("Choice unknown;\n");
        break;
    }
  }
  return 0;
}

void moveOddItemsToBack(LinkedList *linkedList) {
	if(linkedList == NULL || linkedList->head == NULL) return;
	ListNode *pLeft = NULL;
	ListNode *pTarget = linkedList->head;
	ListNode *pTail = linkedList->head;
	while(pTail->next) pTail = pTail->next;
	ListNode *pLastTarget = pTail;
	/*
	if(target is even number) just update pLeft, pTarget
	else if(target is odd number) {
		SPECIAL CASE 1. if the target is last node
			- no need to move the node since it's already at the end
			- due to the loop condition, at each loop, the target node is visited for the first time
			- it means that if the target is the last node, the target node is the only odd element in the entire list
			- that also means that we don't have to do anything and just terminate the loop
		SPECIAL CASE 2. if pLeft is null
			- it means we have to update the header as well
		GENERAL CASE. update pTarget, pTail (pLeft stays the same)
			- pTail->next = pTarget
			- pTarget = pTarget->next
			- pTail->next = NULL
			- pTail = pTarget
	}
	*/
	int isLastNodeReached = False;
	while(!isLastNodeReached) {
		if(pTarget==pLastTarget) isLastNodeReached = True;
		if(pTarget->item % 2 == 0) {
			pLeft = pTarget;
			pTarget = pTarget->next;
		}
		else {
			if(pTarget->next == NULL) break;
			else {
				pTail->next = pTarget;
				if(!pLeft) linkedList->head = pTarget->next;
				else pLeft->next = pTarget->next;
				pTarget->next = NULL;
				pTail = pTarget; // update pTail
				if(!pLeft) pTarget = linkedList->head; // update pTarget
				else pTarget = pLeft->next; // update pTarget
			}
		}
	}
}
void printList(LinkedList *ll) {
  ListNode *cur;
  if (ll == NULL)
    return;

  cur = ll->head;

  if (cur == NULL)
    printf("Empty");
  while (cur != NULL) {
    printf("%d ", cur->item);
    cur = cur->next;
  }
  printf("\n");
}
void removeAllItems(LinkedList *ll) {
  ListNode *cur = ll->head;
  ListNode *tmp;

  while (cur != NULL) {
    tmp = cur->next;
    free(cur);
    cur = tmp;
  }
  ll->head = NULL;
  ll->size = 0;
}
ListNode *findNode(LinkedList *ll, int index) {
  ListNode *temp;

  if (ll == NULL || index < 0 || index >= ll->size)
    return NULL;

  temp = ll->head;

  if (temp == NULL || index < 0)
    return NULL;

  while (index > 0) {
    temp = temp->next;
    if (temp == NULL)
      return NULL;
    index--;
  }

  return temp;
}
int insertNode(LinkedList *ll, int index, int value) {
  ListNode *pre, *cur;

  if (ll == NULL || index < 0 || index > ll->size + 1)
    return -1;

  // If empty list or inserting first node, need to update head pointer
  if (ll->head == NULL || index == 0) {
    cur = ll->head;
    ll->head = malloc(sizeof(ListNode));
    ll->head->item = value;
    ll->head->next = cur;
    ll->size++;
    return 0;
  }

  // Find the nodes before and at the target position
  // Create a new node and reconnect the links
  if ((pre = findNode(ll, index - 1)) != NULL) {
    cur = pre->next;
    pre->next = malloc(sizeof(ListNode));
    pre->next->item = value;
    pre->next->next = cur;
    ll->size++;
    return 0;
  }

  return -1;
}
int removeNode(LinkedList *ll, int index) {
  ListNode *pre, *cur;

  // Highest index we can remove is size-1
  if (ll == NULL || index < 0 || index >= ll->size)
    return -1;

  // If removing first node, need to update head pointer
  if (index == 0) {
    cur = ll->head->next;
    free(ll->head);
    ll->head = cur;
    ll->size--;
    return 0;
  }

  // Find the nodes before and after the target position
  // Free the target node and reconnect the links
  if ((pre = findNode(ll, index - 1)) != NULL) {
    if (pre->next == NULL)
      return -1;

    cur = pre->next;
    pre->next = cur->next;
    free(cur);
    ll->size--;
    return 0;
  }

  return -1;
}
