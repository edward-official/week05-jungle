#include <stdio.h>
#include <stdlib.h>
typedef struct _listnode {
  int item;
  struct _listnode *next;
} ListNode; // You should not change the definition of ListNode
typedef struct _linkedlist {
  int size;
  ListNode *head;
} LinkedList; // You should not change the definition of LinkedList


void alternateMergeLinkedList(LinkedList *ll1, LinkedList *ll2);
void printList(LinkedList *ll);
void removeAllItems(LinkedList *ll);
ListNode *findNode(LinkedList *ll, int index);
int insertNode(LinkedList *ll, int index, int value);
int removeNode(LinkedList *ll, int index);


int main() {
  LinkedList ll1, ll2;
  int c, i, j;
  c = 1;

  ll1.head = NULL;
  ll1.size = 0;

  ll2.head = NULL;
  ll2.size = 0;

  printf("1: Insert an integer to the linked list 1:\n");
  printf("2: Insert an integer to the linked list 2:\n");
  printf("3: Create the alternate merged linked list:\n");
  printf("0: Quit:\n");

  while (c != 0) {
    printf("Please input your choice(1/2/3/0): ");
    scanf("%d", &c);

    switch (c) {
    case 1:
      printf("Input an integer that you want to add to the linked list 1: ");
      scanf("%d", &i);
      j = insertNode(&ll1, ll1.size, i);
      printf("Linked list 1: ");
      printList(&ll1);
      break;
    case 2:
      printf("Input an integer that you want to add to the linked list 2: ");
      scanf("%d", &i);
      j = insertNode(&ll2, ll2.size, i);
      printf("Linked list 2: ");
      printList(&ll2);
      break;
    case 3:
      printf("The resulting linked lists after merging the given linked list are:\n");
      alternateMergeLinkedList(&ll1, &ll2);
      printf("The resulting linked list 1: ");
      printList(&ll1);
      printf("The resulting linked list 2: ");
      printList(&ll2);
      break;
    case 0:
      removeAllItems(&ll1);
      removeAllItems(&ll2);
      break;
    default:
      printf("Choice unknown;\n");
      break;
    }
  }
  return 0;
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

  if (ll->head == NULL || index == 0) {
    cur = ll->head;
    ll->head = malloc(sizeof(ListNode));
    ll->head->item = value;
    ll->head->next = cur;
    ll->size++;
    return 0;
  }

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

  if (ll == NULL || index < 0 || index >= ll->size)
    return -1;

  if (index == 0) {
    cur = ll->head->next;
    free(ll->head);
    ll->head = cur;
    ll->size--;
    return 0;
  }

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