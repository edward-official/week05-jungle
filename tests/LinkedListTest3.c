#include "../tasks/phase1/HeaderLinkedList.h"
#include "../unity/unity.h"

static LinkedList l;

void setUp(void) {
  l.head = NULL;
  l.size = 0;
}
void tearDown(void) { removeAllItems(&l); }

static void pushBack(int v) { insertNode(&l, l.size, v); }
static void assertList(const int *exp, int n) {
  ListNode *c = l.head;
  for (int i = 0; i < n; ++i) {
    TEST_ASSERT_NOT_NULL(c);
    TEST_ASSERT_EQUAL_INT(exp[i], c->item);
    c = c->next;
  }
}

void testMoveOdds_keepsEvensFrontAndOrder(void) {
  int init[] = {1, 2, 3, 4, 5};
  for (int i = 0; i < 5; i++)
    pushBack(init[i]);
  moveOddItemsToBack(&l);
  int exp[] = {2, 4, 1, 3, 5};
  assertList(exp, 5);
}

void testNoChange_whenListEmptyOrSingle(void) {
  moveOddItemsToBack(&l);
  TEST_ASSERT_NULL(l.head);
  pushBack(7);
  moveOddItemsToBack(&l);
  int exp[] = {7};
  assertList(exp, 1);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(testMoveOdds_keepsEvensFrontAndOrder);
  RUN_TEST(testNoChange_whenListEmptyOrSingle);
  return UNITY_END();
}
