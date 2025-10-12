#include "../tasks/phase1/HeaderLinkedList.h"
#include "../unity/unity.h"

static LinkedList ll;

void setUp(void) {
  ll.head = NULL;
  ll.size = 0;
}
void tearDown(void) {
  removeAllItems(&ll);
}


// ==================== Helpers ====================

static void listToArray(LinkedList *l, int *out, int *n) {
  *n = l->size;
  ListNode *cur = l->head;
  for (int i = 0; i < *n; ++i) {
    out[i] = cur->item;
    cur = cur->next;
  }
}
static void assertListEquals(LinkedList *l, const int *expect, int n) {
  TEST_ASSERT_EQUAL_INT(n, l->size);
  ListNode *cur = l->head;
  for (int i = 0; i < n; ++i) {
    TEST_ASSERT_NOT_NULL(cur);
    TEST_ASSERT_EQUAL_INT(expect[i], cur->item);
    cur = cur->next;
  }
}


// ==================== Test Code ====================

void testInsertIntoEmptyReturnsIndex0(void) {
  int idx = insertSortedLL(&ll, 5);
  TEST_ASSERT_EQUAL_INT(0, idx);
  const int exp[] = {5};
  assertListEquals(&ll, exp, 1);
}

void testInsertSmallerThanHeadGoesToFront(void) {
  insertSortedLL(&ll, 5);                 // [5]
  int idx = insertSortedLL(&ll, 1);       // [1,5]
  TEST_ASSERT_EQUAL_INT(0, idx);
  const int exp[] = {1,5};
  assertListEquals(&ll, exp, 2);
}

void testInsertGreaterThanAllGoesToTail(void) {
  insertSortedLL(&ll, 2);                 // [2]
  insertSortedLL(&ll, 4);                 // [2,4]
  int idx = insertSortedLL(&ll, 7);       // [2,4,7]
  TEST_ASSERT_EQUAL_INT(2, idx);
  const int exp[] = {2,4,7};
  assertListEquals(&ll, exp, 3);
}

void testInsertInTheMiddleReturnsMiddleIndex(void) {
  insertSortedLL(&ll, 1);                 // [1]
  insertSortedLL(&ll, 5);                 // [1,5]
  int idx = insertSortedLL(&ll, 3);       // [1,3,5]
  TEST_ASSERT_EQUAL_INT(1, idx);
  const int exp[] = {1,3,5};
  assertListEquals(&ll, exp, 3);
}

void testInsertingDuplicatesKeepsSortedAndIncrementsSize(void) {
  insertSortedLL(&ll, 5);                 // [5]
  int i1 = insertSortedLL(&ll, 5);        // [5,5]
  int i2 = insertSortedLL(&ll, 5);        // [5,5,5]
  TEST_ASSERT_EQUAL_INT(1, i1);
  TEST_ASSERT_EQUAL_INT(2, i2);
  const int exp[] = {5,5,5};
  assertListEquals(&ll, exp, 3);
}

void testNegativeValuesAreSortedWithPositives(void) {
  insertSortedLL(&ll, 0);                 // [0]
  insertSortedLL(&ll, -2);                // [-2,0]
  insertSortedLL(&ll, -3);                // [-3,-2,0]
  insertSortedLL(&ll, 1);                 // [-3,-2,0,1]
  const int exp[] = {-3,-2,0,1};
  assertListEquals(&ll, exp, 4);
}

void testNullListPointerReturnsMinus1(void) {
  TEST_ASSERT_EQUAL_INT(-1, insertSortedLL(NULL, 10));
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(testInsertIntoEmptyReturnsIndex0);
  RUN_TEST(testInsertSmallerThanHeadGoesToFront);
  RUN_TEST(testInsertGreaterThanAllGoesToTail);
  RUN_TEST(testInsertInTheMiddleReturnsMiddleIndex);
  RUN_TEST(testInsertingDuplicatesKeepsSortedAndIncrementsSize);
  RUN_TEST(testNegativeValuesAreSortedWithPositives);
  RUN_TEST(testNullListPointerReturnsMinus1);
  return UNITY_END();
}
