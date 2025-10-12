#include <stdio.h>
#include <stdlib.h>
#include "HeaderLinkedList.h"

int main() {
  int c = -1, i;
  LinkedList ll;
  LinkedList resultFrontList, resultBackList;

  // Initialize the linked list as an empty linked list
  ll.head = NULL;
  ll.size = 0;

  // Initialize the front linked list as an empty linked list
  resultFrontList.head = NULL;
  resultFrontList.size = 0;

  // Initialize the back linked list as an empty linked list
  resultBackList.head = NULL;
  resultBackList.size = 0;

  printf("1: Insert an integer to the linked list:\n");
  printf("2: Split the linked list into two linked lists, frontList and backList:\n");
  printf("0: Quit:\n");

  while (c != 0) {
    printf("Please input your choice(1/2/0): ");
    scanf("%d", &c);

    switch (c) {
    case 1:
      printf("Input an integer that you want to add to the linked list: ");
      scanf("%d", &i);
      insertNode(&ll, ll.size, i);
      printf("The resulting linked list is: ");
      printList(&ll);
      break;
    case 2:
      printf("The resulting linked lists after splitting the given linked list are:\n");
      frontBackSplitLinkedList(&ll, &resultFrontList, &resultBackList); // You need to code this function
      printf("Front linked list: ");
      printList(&resultFrontList);
      printf("Back linked list: ");
      printList(&resultBackList);
      printf("\n");
      removeAllItems(&ll);
      removeAllItems(&resultFrontList);
      removeAllItems(&resultBackList);
      break;
    case 0:
      removeAllItems(&ll);
      removeAllItems(&resultFrontList);
      removeAllItems(&resultBackList);
      break;
    default:
      printf("Choice unknown;\n");
      break;
    }
  }

  return 0;
}
