#include <stdio.h>
#include <stdlib.h>
#include "HeaderLinkedList.h"

int main() {
  LinkedList ll;
  int c, i, j;
  c = 1;

  ll.head = NULL;
  ll.size = 0;

  printf("1: Insert an integer to the linked list:\n");
  printf("2: Reversed the linked list:\n");
  printf("0: Quit:\n");

  while (c != 0) {
    printf("Please input your choice(1/2/0): ");
    scanf("%d", &c);

    switch (c) {
    case 1:
      printf("Input an integer that you want to add to the linked list: ");
      scanf("%d", &i);
      j = insertNode(&ll, ll.size, i);
      (void)j;
      printf("The resulting linked list is: ");
      printList(&ll);
      break;

    case 2:
      RecursiveReverse(&(ll.head));
      printf("The resulting linked list after reversed the given linked list is: ");
      printList(&ll);
      removeAllItems(&ll);
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
