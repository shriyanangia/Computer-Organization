#include <stdio.h>
#include <check.h>
#include "trie.h"

START_TEST(test1Insert)
{
  struct TrieNode* r = trieNode_new();  
  ck_assert(r != NULL);
  ck_assert(trieNode_getWord(r) == NULL); 
  trieNode_free(r);
}
END_TEST

START_TEST(test2Insert)
{
  struct TrieNode* r = trieNode_new();  
  trieNode_insert(r, "a");
  const struct TrieNode* x = trieNode_getChild(r, 2);
  const char* w = trieNode_getWord(x);
  ck_assert(w != NULL);
  ck_assert(strncmp(w, "a", MAX_WORD_LENGTH) == 0);
  trieNode_free(r);
}
END_TEST

START_TEST(test3Insert)
{
  struct TrieNode* r = trieNode_new();  
  trieNode_insert(r, "ab");
  const struct TrieNode* x = trieNode_getChild(r, 2);
  const struct TrieNode* y = trieNode_getChild(x, 2);
  const char* wx = trieNode_getWord(x);
  const char* wy = trieNode_getWord(y);
  ck_assert(wx == NULL);
  ck_assert(wy != NULL);
  ck_assert(strncmp(wy, "ab", MAX_WORD_LENGTH) == 0);
  trieNode_free(r);
}
END_TEST

START_TEST(test4Insert)
{
  struct TrieNode* r = trieNode_new();  
  trieNode_insert(r, "joke");
  const struct TrieNode* r5 = trieNode_getChild(r, 5);
  ck_assert(r5 != NULL);
  const char* cx = trieNode_getWord(r5);
  ck_assert(cx == NULL);

  const struct TrieNode* r56 = trieNode_getChild(r5, 6);
  ck_assert(r56 != NULL);
  cx = trieNode_getWord(r56);
  ck_assert(cx == NULL);

  const struct TrieNode* r565 = trieNode_getChild(r56, 5);
  ck_assert(r565 != NULL);
  cx = trieNode_getWord(r565);
  ck_assert(cx == NULL);

  const struct TrieNode* r5653 = trieNode_getChild(r565, 3);
  ck_assert(r5653 != NULL);
  cx = trieNode_getWord(r5653);
  ck_assert(cx != NULL);
  ck_assert(strncmp(cx, "joke", MAX_WORD_LENGTH) == 0);

  trieNode_free(r);
}
END_TEST

START_TEST(test5Insert)
{
  struct TrieNode* r = trieNode_new();  
  trieNode_insert(r, "az");
  trieNode_insert(r, "dk");
  trieNode_insert(r, "ak");
  trieNode_insert(r, "akz");
  const struct TrieNode* r2 = trieNode_getChild(r, 2);
  const struct TrieNode* r29 = trieNode_getChild(r2, 9);
  const char * cx = trieNode_getWord(r29);
  ck_assert(strncmp(cx, "az", MAX_WORD_LENGTH) == 0);
  const struct TrieNode* r25 = trieNode_getChild(r2, 5);
  cx = trieNode_getWord(r25);
  ck_assert(strncmp(cx, "ak", MAX_WORD_LENGTH) == 0);
  const struct TrieNode* r259 = trieNode_getChild(r25, 9);
  cx = trieNode_getWord(r259);
  ck_assert(strncmp(cx, "akz", MAX_WORD_LENGTH) == 0);
  const struct TrieNode* r3 = trieNode_getChild(r, 3);
  const struct TrieNode* r35 = trieNode_getChild(r3, 5);
  cx = trieNode_getWord(r35);
  ck_assert(strncmp(cx, "dk", MAX_WORD_LENGTH) == 0);
  trieNode_free(r);
}
END_TEST

START_TEST(test1Search)
{
  struct TrieNode* r = trieNode_new();  
  trieNode_insert(r, "az");
  {
    int code[2] = {2,3};
    const struct TrieNode* found = trieNode_search(r, code, 2);
    // implementations may represent failed search by
    // either NULL or by a TrieNode whose word is NULL
    ck_assert( found == NULL || trieNode_getWord(found) == NULL );
  }
  {
    int code[2] = {2,9};
    struct TrieNode* found = trieNode_search(r, code, 2);
    ck_assert( found != NULL );
    const char* foundw = trieNode_getWord(found);
    ck_assert(strncmp(foundw, "az", MAX_WORD_LENGTH) == 0);
  }
  trieNode_free(r);
}
END_TEST

START_TEST(test2Search) 
{
  struct TrieNode* r = trieNode_new();
  trieNode_insert(r, "acre");
  trieNode_insert(r, "bard");
  trieNode_insert(r, "bare");
  trieNode_insert(r, "barf");
  trieNode_insert(r, "base");
  trieNode_insert(r, "cape");
  trieNode_insert(r, "card");
  trieNode_insert(r, "care");
  trieNode_insert(r, "case");
  
  struct TrieNode* found;
  {
    int code[7] = {2,2,7,3,10,10,10};
    found = trieNode_search(r, code, 7);
    ck_assert(strncmp(trieNode_getWord(found), "barf", MAX_WORD_LENGTH) == 0); 
  }
  {
    int code[1] = {10};
    found = trieNode_search(found, code, 1);
    ck_assert(strncmp(trieNode_getWord(found), "base", MAX_WORD_LENGTH) == 0); 
  }
  {
    int code[1] = {10};
    found = trieNode_search(found, code, 1);
    ck_assert(strncmp(trieNode_getWord(found), "cape", MAX_WORD_LENGTH) == 0); 
  }
  {
    int code[5] = {2,2,7,3,10};
    found = trieNode_search(r, code, 5);
    ck_assert(strncmp(trieNode_getWord(found), "bard", MAX_WORD_LENGTH) == 0); 
  }
  {
    int code[1] = {10};
    found = trieNode_search(found, code, 1);
    ck_assert(strncmp(trieNode_getWord(found), "bare", MAX_WORD_LENGTH) == 0); 
  }
  {
    int code[1] = {10};
    found = trieNode_search(found, code, 1);
    ck_assert(strncmp(trieNode_getWord(found), "barf", MAX_WORD_LENGTH) == 0); 
  }
  {
    int code[1] = {10};
    found = trieNode_search(found, code, 1);
    ck_assert(strncmp(trieNode_getWord(found), "base", MAX_WORD_LENGTH) == 0); 
  }
  {
    int code[1] = {10};
    found = trieNode_search(found, code, 1);
    ck_assert(strncmp(trieNode_getWord(found), "cape", MAX_WORD_LENGTH) == 0); 
  }
  {
    int code[10] = {2,2,7,3,10,10,10,10,10,10};
    found = trieNode_search(r, code, 10);
    ck_assert(strncmp(trieNode_getWord(found), "card", MAX_WORD_LENGTH) == 0); 
  }
  {
    int code[1] = {10};
    found = trieNode_search(found, code, 1);
    ck_assert(strncmp(trieNode_getWord(found), "care", MAX_WORD_LENGTH) == 0); 
  }
  {
    int code[1] = {10};
    found = trieNode_search(found, code, 1);
    ck_assert(strncmp(trieNode_getWord(found), "case", MAX_WORD_LENGTH) == 0); 
  }
  {
    int code[1] = {10};
    found = trieNode_search(found, code, 1);
    ck_assert(found == NULL || trieNode_getWord(found) == NULL); 
  }
  trieNode_free(r);
}

START_TEST(test3Search) 
{
  struct TrieNode* r = trieNode_new();
  trieNode_insert(r, "zorilla");
  trieNode_insert(r, "zorillas");
  trieNode_insert(r, "zorille");
  trieNode_insert(r, "zorilles");
  trieNode_insert(r, "zorillo");
  trieNode_insert(r, "zorillos");

  {
    int code[6] = {9,6,7,4,5,5};
    struct TrieNode* found = trieNode_search(r, code, 6);
    ck_assert(found == NULL || trieNode_getWord(found) == NULL); 
  }
  {
    int code[8] = {9,6,7,4,5,5,3,7};
    struct TrieNode* found = trieNode_search(r, code, 8);
    ck_assert(strncmp(trieNode_getWord(found), "zorilles", MAX_WORD_LENGTH) == 0); 
  }
  {
    int code[7] = {9,6,7,4,5,5,3};
    struct TrieNode* found = trieNode_search(r, code, 7);
    ck_assert(strncmp(trieNode_getWord(found), "zorille", MAX_WORD_LENGTH) == 0); 
  }
  {
    int code[8] = {9,6,7,4,5,5,2,7};
    struct TrieNode* found = trieNode_search(r, code, 8);
    ck_assert(strncmp(trieNode_getWord(found), "zorillas", MAX_WORD_LENGTH) == 0); 
  }
  {
    int code[7] = {9,6,7,4,5,5,2};
    struct TrieNode* found = trieNode_search(r, code, 7);
    ck_assert(strncmp(trieNode_getWord(found), "zorilla", MAX_WORD_LENGTH) == 0); 
  }
  {
    int code[8] = {9,6,7,4,5,5,6,7};
    struct TrieNode* found = trieNode_search(r, code, 8);
    ck_assert(strncmp(trieNode_getWord(found), "zorillos", MAX_WORD_LENGTH) == 0); 
  }
  {
    int code[7] = {9,6,7,4,5,5,6};
    struct TrieNode* found = trieNode_search(r, code, 7);
    ck_assert(strncmp(trieNode_getWord(found), "zorillo", MAX_WORD_LENGTH) == 0); 
  }
  trieNode_free(r);
}

Suite * insert_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Insert");

    // Core test case 
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test1Insert);
    tcase_add_test(tc_core, test2Insert);
    tcase_add_test(tc_core, test3Insert);
    tcase_add_test(tc_core, test4Insert);
    tcase_add_test(tc_core, test5Insert);
/*
    tcase_add_test(tc_core, test6Insert);
    tcase_add_test(tc_core, test7Insert);
    tcase_add_test(tc_core, test8Insert);
    tcase_add_test(tc_core, test9Insert);
    tcase_add_test(tc_core, test10Insert);
    tcase_add_test(tc_core, test11Insert);
*/

    suite_add_tcase(s, tc_core);

    return s;
}

Suite * search_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Search");

    // Core test case 
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test1Search);
    tcase_add_test(tc_core, test2Search);
    tcase_add_test(tc_core, test3Search);
/*
    tcase_add_test(tc_core, test4Search);
    tcase_add_test(tc_core, test5Search);
    tcase_add_test(tc_core, test6Search);
    tcase_add_test(tc_core, test7Search);
    tcase_add_test(tc_core, test8Search);
    tcase_add_test(tc_core, test9Search);
    tcase_add_test(tc_core, test10Search);
    tcase_add_test(tc_core, test11Search);
*/

    suite_add_tcase(s, tc_core);

    return s;
}



int main(void)
{
    // Insert
    {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = insert_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    printf("Insert: # of failed: %d\n", number_failed);
    }

    // Search
    {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = search_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    printf("Search: # of failed: %d\n", number_failed);
    }
}

