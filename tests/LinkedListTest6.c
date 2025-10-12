#include "../tasks/phase1/HeaderLinkedList.h"
#include "../unity/unity.h"

static LinkedList l;

void setUp(void) {
  l.head = NULL;
  l.size = 0;
}
void tearDown(void) { removeAllItems(&l); }

static void pushBack(int v) { insertNode(&l, l.size, v); }
static void assertSeq(const int *exp, int n) {
  ListNode *c = l.head;
  for (int i = 0; i < n; i++) {
    TEST_ASSERT_NOT_NULL(c);
    TEST_ASSERT_EQUAL_INT(exp[i], c->item);
    c = c->next;
  }
}

void testMoveMax_movesWhenHeadIsNotMax(void) {
  int init[] = {3, 1, 5, 2};
  for (int i = 0; i < 4; i++)
    pushBack(init[i]);
  moveMaxToFront(&l.head);
  int exp[] = {5, 3, 1, 2};
  assertSeq(exp, 4);
}

void testNoChange_whenHeadAlreadyMax(void) {
  int init[] = {9, 1, 5};
  for (int i = 0; i < 3; i++)
    pushBack(init[i]);
  moveMaxToFront(&l.head);
  int exp[] = {9, 1, 5};
  assertSeq(exp, 3);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(testMoveMax_movesWhenHeadIsNotMax);
  RUN_TEST(testNoChange_whenHeadAlreadyMax);
  return UNITY_END();
}
