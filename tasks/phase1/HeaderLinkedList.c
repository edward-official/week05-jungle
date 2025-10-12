#include <stdio.h>
#include <stdlib.h>
#include "HeaderLinkedList.h"
#define True 1
#define False 0


int insertSortedLL(LinkedList *linkedList, int item) {
	if(!linkedList) return -1;
	
	ListNode *node = malloc(sizeof(ListNode));
	if(!node) return -1;
	node->item = item;
	node->next = NULL;
	
	if(linkedList->size == 0) {
		linkedList->head = node;
		linkedList->size++;
		return 0;
	}
	if(item < linkedList->head->item) {
		node->next = linkedList->head;
		linkedList->head = node;
		linkedList->size++;
		return 0;
	}
	ListNode *traversingNode = linkedList->head;
	int traversingIndex = 0;
	while(True) {
		if(!traversingNode->next) {
			traversingNode->next = node;
			linkedList->size++;
			return traversingIndex + 1;
		}
		else if(item < traversingNode->next->item) {
			node->next = traversingNode->next;
			traversingNode->next = node;
			linkedList->size++;
			return traversingIndex + 1;
		}
		traversingNode = traversingNode->next;
		traversingIndex++;
	}
}
void alternateMergeLinkedList(LinkedList *linkedList1, LinkedList *linkedList2) {
	if(linkedList1->size == 0 || linkedList2->size == 0) return;
	/*
	linkedList1: H 0 0 0 0 0 0 0
	linkedList2: H 0 0 0 0 0 0 0
	n_iteration = min(linkedList1->size, linkedList2->size)
	*/
	int n_iteration = 0;
	if(linkedList1->size > linkedList2->size) n_iteration = linkedList2->size;
	else n_iteration = linkedList1->size;
	linkedList1->size += n_iteration;
	linkedList2->size -= n_iteration;
	ListNode* appendingPosition1 = linkedList1->head;
	for(int i=0; i<n_iteration; i++) {
		ListNode* movingNode2 = linkedList2->head;
		linkedList2->head = linkedList2->head->next;
		movingNode2->next = appendingPosition1->next;
		appendingPosition1->next = movingNode2;
		appendingPosition1 = appendingPosition1->next->next;
	}
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
void moveEvenItemsToBack(LinkedList *linkedList) {
	if(!linkedList || !linkedList->head || linkedList->size < 2) return;
	// set up variables
	ListNode* pLeft = NULL;
	ListNode* pTarget = linkedList->head;
	ListNode* pTail = linkedList->head;
	while(pTail->next) pTail = pTail->next;
	ListNode* pLastTarget = pTail;
	// execute repositioning
	int isLastTargetVisited = False;
	while(!isLastTargetVisited) {
		if(pTarget==pLastTarget) isLastTargetVisited = True;
		/*
		TargetIsOddNumber {
			LeftIsNull
			LeftIsNotNull
		}
		TargetIsEvenNumber {
			TargetIsHeader
			TargetIsTail
		}
		*/
		
		if(pTarget->item%2 != 0) {
			if(!pLeft) {
				pLeft = linkedList->head;
				pTarget = pLeft->next;
			}
			else {
				pLeft = pLeft->next;
				pTarget = pLeft->next;
			}
		}
		else {
			if(!pLeft) {
				linkedList->head = linkedList->head->next;
				pTail->next = pTarget;
				pTail = pTarget;
				pTarget->next = NULL;
				pTarget = linkedList->head;
			}
			else if(!pTarget->next) break;
			else {
				pLeft->next = pTarget->next;
				pTail->next = pTarget;
				pTail = pTarget;
				pTarget->next = NULL;
				pTarget = pLeft->next;
			}
		}
	}
}
void frontBackSplitLinkedList(LinkedList *linkedList, LinkedList *linkedList1, LinkedList *linkedList2) {
  int size1 = (linkedList->size + 1) / 2;
	int traversingIndex = 0;
	ListNode* traversingPointer = linkedList->head;
	ListNode* pTail1 = NULL;
	ListNode* pTail2 = NULL;
	while(traversingIndex < linkedList->size) {
		// set up the node to append
		ListNode* pNode = malloc(sizeof(ListNode));
		pNode->item = traversingPointer->item;
		pNode->next = NULL;
		// append the node
		if(traversingIndex < size1) {
			if(!pTail1) linkedList1->head = pNode;
			else pTail1->next = pNode;
			pTail1 = pNode;
		}
		else {
			if(!pTail2) linkedList2->head = pNode;
			else pTail2->next = pNode;
			pTail2 = pNode;
		}
		// update the traversers
		traversingPointer = traversingPointer->next;
		traversingIndex++;
	}
}
int moveMaxToFront(ListNode **pHead) {
	ListNode* pFindLeft = (*pHead);
	ListNode* pTraverseLeft = (*pHead);
	// find max excluding the head element
	while(pTraverseLeft->next) {
		if(pFindLeft->next->item < pTraverseLeft->next->item) pFindLeft = pTraverseLeft;
		pTraverseLeft = pTraverseLeft->next;
	}
	if(pFindLeft->next->item < (*pHead)->item) return 0;
	// execute reposition
	ListNode* pMax = pFindLeft->next;
	pFindLeft->next = pMax->next;
	pMax->next = (*pHead);
	*pHead = pMax;
  return 0;
}
void RecursiveReverse(ListNode **ppHead) {
	if(!ppHead || !(*ppHead) || !(*ppHead)->next) return;
	ListNode* pLeft = *ppHead;
	ListNode* pRight = pLeft->next;
	*ppHead = pRight;
	RecursiveReverse(ppHead);
	pRight->next = pLeft;
	pLeft->next = NULL;
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