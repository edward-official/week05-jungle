#include "../tasks/phase1/HeaderLinkedList.h"
#include "../unity/unity.h"

static LinkedList a, b;

void setUp(void) {
  a.head = NULL;
  a.size = 0;
  b.head = NULL;
  b.size = 0;
}
void tearDown(void) {
  removeAllItems(&a);
  removeAllItems(&b);
}

static void pushBack(LinkedList *l, int v) { insertNode(l, l->size, v); }
static void assertListSeq(LinkedList *l, const int *exp, int n) {
  ListNode *cur = l->head;
  for (int i = 0; i < n; ++i) {
    TEST_ASSERT_NOT_NULL(cur);
    TEST_ASSERT_EQUAL_INT(exp[i], cur->item);
    cur = cur->next;
  }
}

void testInterleave_minLenNodesMoveFromBtoA(void) {
  pushBack(&a, 1);
  pushBack(&a, 3);
  pushBack(&a, 5);
  pushBack(&b, 2);
  pushBack(&b, 4);
  pushBack(&b, 6);
  pushBack(&b, 8);

  alternateMergeLinkedList(&a, &b);

  const int expA[] = {1, 2, 3, 4, 5, 6};
  assertListSeq(&a, expA, 6);
  const int expB[] = {8};
  assertListSeq(&b, expB, 1);
}

void testNoOp_ifEitherListEmpty(void) {
  pushBack(&b, 10);
  alternateMergeLinkedList(&a, &b);
  const int expB[] = {10};
  assertListSeq(&b, expB, 1);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(testInterleave_minLenNodesMoveFromBtoA);
  RUN_TEST(testNoOp_ifEitherListEmpty);
  return UNITY_END();
}
