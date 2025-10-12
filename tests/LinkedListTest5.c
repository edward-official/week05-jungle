#include "../tasks/phase1/HeaderLinkedList.h"
#include "../unity/unity.h"

static LinkedList src, frontL, backL;

void setUp(void) {
  src.head = frontL.head = backL.head = NULL;
  src.size = frontL.size = backL.size = 0;
}
void tearDown(void) {
  removeAllItems(&src);
  removeAllItems(&frontL);
  removeAllItems(&backL);
}

static void pushBack(LinkedList *l, int v) { insertNode(l, l->size, v); }
static int copyToArrayByNext(LinkedList *l, int *out) {
  int n = 0;
  for (ListNode *c = l->head; c; c = c->next)
    out[n++] = c->item;
  return n;
}

void testSplit_oddCount_goesCeilHalfToFront(void) {
  int init[] = {1, 2, 3, 4, 5};
  for (int i = 0; i < 5; i++)
    pushBack(&src, init[i]);
  frontBackSplitLinkedList(&src, &frontL, &backL);
  int a[8], b[8];
  int na = copyToArrayByNext(&frontL, a), nb = copyToArrayByNext(&backL, b);
  int expA[] = {1, 2, 3}, expB[] = {4, 5};
  TEST_ASSERT_EQUAL_INT(3, na);
  for (int i = 0; i < na; i++)
    TEST_ASSERT_EQUAL_INT(expA[i], a[i]);
  TEST_ASSERT_EQUAL_INT(2, nb);
  for (int i = 0; i < nb; i++)
    TEST_ASSERT_EQUAL_INT(expB[i], b[i]);
}

void testSplit_evenCount_halfHalf(void) {
  int init[] = {10, 20, 30, 40};
  for (int i = 0; i < 4; i++)
    pushBack(&src, init[i]);
  frontBackSplitLinkedList(&src, &frontL, &backL);
  int a[8], b[8];
  int na = copyToArrayByNext(&frontL, a), nb = copyToArrayByNext(&backL, b);
  int expA[] = {10, 20}, expB[] = {30, 40};
  TEST_ASSERT_EQUAL_INT(2, na);
  for (int i = 0; i < na; i++)
    TEST_ASSERT_EQUAL_INT(expA[i], a[i]);
  TEST_ASSERT_EQUAL_INT(2, nb);
  for (int i = 0; i < nb; i++)
    TEST_ASSERT_EQUAL_INT(expB[i], b[i]);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(testSplit_oddCount_goesCeilHalfToFront);
  RUN_TEST(testSplit_evenCount_halfHalf);
  return UNITY_END();
}
