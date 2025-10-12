#include <stdio.h>
#include <stdlib.h>
#include "HeaderLinkedList.h"

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
