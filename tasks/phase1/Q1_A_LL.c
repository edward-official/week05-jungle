#include <stdio.h>
#include <stdlib.h>
#include "HeaderLinkedList.h"

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
