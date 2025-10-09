#include<stdio.h>
#include<stdlib.h>
typedef struct _node {
  int data;
  struct _node* next;
} Node;

void test1();
void test2();

void main() {
  test2();
  return;
}

void test1() {
  Node* node1 = malloc(sizeof(Node));
  Node* node2 = malloc(sizeof(Node));
  
  node1->data = 3;
  node2->data = 4;
  node1->next = node2;
  
  printf("%d\n", node1->data);
  printf("%d\n", node1->next->data);
  
  free(node1);
  free(node2);
  return;
}
void test2() {
  int a = 4;
  printf("%d\n", a /2);
  return;
}

/*
정수형 char, short, int, long
char => '6'
string => "6"
char* myString = "hello world\n";
*/
/*
a= 4
print(f"{a}\n")
*/