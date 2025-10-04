#include <stdio.h>
#include <stdlib.h>
#define True 1
#define False 0

typedef struct _listnode {
  int item;
  struct _listnode *next;
} ListNode;
typedef struct _linkedlist {
  int size;
  ListNode *head;
} LinkedList;


int insertSortedLL(LinkedList *ll, int item);
void printList(LinkedList *ll);
void removeAllItems(LinkedList *ll);
ListNode *findNode(LinkedList *ll, int index);
int insertNode(LinkedList *ll, int index, int value);
int removeNode(LinkedList *ll, int index);


int main() {
  LinkedList linkedList;
  int choice, element, index;
  choice = 1;

  // Initialize the linked list as an empty linked list
  linkedList.head = NULL;
  linkedList.size = 0;

  printf("1: Insert an integer to the sorted linked list:\n");
  printf("2: Print the index of the most recent input value:\n");
  printf("3: Print sorted linked list:\n");
  printf("0: Quit:");

  while (choice != 0) {
    printf("\nPlease input your choice(1/2/3/0): ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Input an integer that you want to add to the linked list: ");
      scanf("%d", &element);
      index = insertSortedLL(&linkedList, element);
      printf("The resulting linked list is: ");
      printList(&linkedList);
      break;
    case 2:
      printf("The value %d was added at index %d\n", element, index);
      break;
    case 3:
      printf("The resulting sorted linked list is: ");
      printList(&linkedList);
      removeAllItems(&linkedList);
      break;
    case 0:
      removeAllItems(&linkedList);
      break;
    default:
      printf("Choice unknown;\n");
      break;
    }
  }
  return 0;
}


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