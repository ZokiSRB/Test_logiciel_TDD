#include <CUnit/Basic.h>
#include "../Fonction/LIFO.h"

void test_lifo_initialisation(void) {
    Lifo pile;
    lifo_initialiser(&pile);
    
    CU_ASSERT_TRUE(lifo_est_vide(&pile));
    CU_ASSERT_FALSE(lifo_est_pleine(&pile));
    CU_ASSERT_EQUAL(lifo_taille(&pile), 0);
}

void test_lifo_empiler(void) {
    Lifo pile;
    lifo_initialiser(&pile);
    
    CU_ASSERT_EQUAL(lifo_empiler(&pile, 10), 1);
    CU_ASSERT_FALSE(lifo_est_vide(&pile));
    CU_ASSERT_EQUAL(lifo_taille(&pile), 1);
}

void test_lifo_depiler(void) {
    Lifo pile;
    lifo_initialiser(&pile);
    int element;
    
    lifo_empiler(&pile, 20);
    CU_ASSERT_EQUAL(lifo_depiler(&pile, &element), 1);
    CU_ASSERT_EQUAL(element, 20);
    CU_ASSERT_TRUE(lifo_est_vide(&pile));
}

void test_lifo_ordre(void) {
    Lifo pile;
    lifo_initialiser(&pile);
    int element;
    
    lifo_empiler(&pile, 1);
    lifo_empiler(&pile, 2);
    lifo_empiler(&pile, 3);
    
    CU_ASSERT_EQUAL(lifo_depiler(&pile, &element), 1);
    CU_ASSERT_EQUAL(element, 3);
    
    CU_ASSERT_EQUAL(lifo_depiler(&pile, &element), 1);
    CU_ASSERT_EQUAL(element, 2);
}

void test_lifo_pleine(void) {
    Lifo pile;
    lifo_initialiser(&pile);
    
    for (int i = 0; i < MAX_SIZE; i++) {
        CU_ASSERT_EQUAL(lifo_empiler(&pile, i), 1);
    }
    
    CU_ASSERT_TRUE(lifo_est_pleine(&pile));
    CU_ASSERT_EQUAL(lifo_empiler(&pile, 100), 0);
}

int main() {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("Suite_LIFO", NULL, NULL);
    
    CU_add_test(suite, "test_initialisation", test_lifo_initialisation);
    CU_add_test(suite, "test_empiler", test_lifo_empiler);
    CU_add_test(suite, "test_depiler", test_lifo_depiler);
    CU_add_test(suite, "test_ordre", test_lifo_ordre);
    CU_add_test(suite, "test_lifo_pleine", test_lifo_pleine);
    
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}