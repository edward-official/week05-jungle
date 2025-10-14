#include<stdio.h>
#include<stdlib.h>
typedef struct _node {
  int data;
  struct _node* next;
} Node;

int fibonacci(int n) {
  if(n <= 0) return -1;
  else if(n == 1 || n == 2) return 1;
  int *pFibonacciArray = malloc(sizeof(int) * (n + 1));
  pFibonacciArray[1] = 1;
  pFibonacciArray[2] = 1;
  for(int index=3; index<=n; n++) pFibonacciArray[n] = pFibonacciArray[n-1] + pFibonacciArray[n-2];
  return pFibonacciArray[n];
}
int q2() {
  int *arr = (int*)malloc(5 * sizeof(int));
  for(int index=0; index<5; index++) arr[index] = index * index;
  printf("%d\n", arr[3]);
  return 0;
}
int q3_updater(int *pArray, int nArray) {
  for(int index=0; index<nArray; index++) pArray[index] += 1;
}
int q3_main() {
  int pArray[5] = {1,2,3,4,5};
  q3_updater(pArray, 5);
  for(int t=0; t<5; t++) printf("%d\n", pArray[t]);
  return 0;
}

void test1();
void test2();

#define N_ELEMENTS 5
void main() {
  // q3_main();
  int sum = 0;
  int elements[N_ELEMENTS] = {1,2,3,4,5};
  for(int t=0; t<N_ELEMENTS; t++) sum += elements[t];
  printf("%d\n", sum);
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