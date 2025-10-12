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

void testReverse_threeNodes(void) {
  pushBack(1);
  pushBack(2);
  pushBack(3);
  RecursiveReverse(&l.head);
  int exp[] = {3, 2, 1};
  assertSeq(exp, 3);
}

void testReverse_empty_and_single_areNoOp(void) {
  RecursiveReverse(&l.head);
  TEST_ASSERT_NULL(l.head);
  pushBack(42);
  RecursiveReverse(&l.head);
  int exp[] = {42};
  assertSeq(exp, 1);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(testReverse_threeNodes);
  RUN_TEST(testReverse_empty_and_single_areNoOp);
  return UNITY_END();
}
