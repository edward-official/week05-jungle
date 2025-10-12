#include <stdio.h>
#include <stdlib.h>
#include "HeaderLinkedList.h"

int main() {
  LinkedList ll;
  int c, i, j;
  c = 1;

  // Initialize the linked list as an empty linked list
  ll.head = NULL;
  ll.size = 0;

  printf("1: Insert an integer to the linked list:\n");
  printf("2: Move all even integers to the back of the linked list:\n");
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
        moveEvenItemsToBack(&ll); // You need to code this function
        printf("The resulting linked list after moving even integers to the back of the linked list is: ");
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
