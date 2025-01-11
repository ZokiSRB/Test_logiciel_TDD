#include <CUnit/Basic.h>
#include "../Fonction/FIFO.h"

void test_fifo_initialisation(void) {
    Fifo file;
    fifo_initialiser(&file);
    
    CU_ASSERT_TRUE(fifo_est_vide(&file));
    CU_ASSERT_FALSE(fifo_est_pleine(&file));
    CU_ASSERT_EQUAL(fifo_taille(&file), 0);
}

void test_fifo_enfiler(void) {
    Fifo file;
    fifo_initialiser(&file);
    
    CU_ASSERT_EQUAL(fifo_enfiler(&file, 10), 1);
    CU_ASSERT_FALSE(fifo_est_vide(&file));
    CU_ASSERT_EQUAL(fifo_taille(&file), 1);
}

void test_fifo_defiler(void) {
    Fifo file;
    fifo_initialiser(&file);
    int element;
    
    fifo_enfiler(&file, 20);
    CU_ASSERT_EQUAL(fifo_defiler(&file, &element), 1);
    CU_ASSERT_EQUAL(element, 20);
    CU_ASSERT_TRUE(fifo_est_vide(&file));
}

void test_fifo_ordre(void) {
    Fifo file;
    fifo_initialiser(&file);
    int element;
    
    fifo_enfiler(&file, 1);
    fifo_enfiler(&file, 2);
    fifo_enfiler(&file, 3);
    
    CU_ASSERT_EQUAL(fifo_defiler(&file, &element), 1);
    CU_ASSERT_EQUAL(element, 1);
    
    CU_ASSERT_EQUAL(fifo_defiler(&file, &element), 1);
    CU_ASSERT_EQUAL(element, 2);
}

void test_fifo_pleine(void) {
    Fifo file;
    fifo_initialiser(&file);
    
    for (int i = 0; i < MAX_SIZE; i++) {
        CU_ASSERT_EQUAL(fifo_enfiler(&file, i), 1);
    }
    
    CU_ASSERT_TRUE(fifo_est_pleine(&file));
    CU_ASSERT_EQUAL(fifo_enfiler(&file, 100), 0);
}

int main() {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("Suite_FIFO", NULL, NULL);
    CU_add_test(suite, "test_initialisation", test_fifo_initialisation);
    CU_add_test(suite, "test_enfiler", test_fifo_enfiler);
    CU_add_test(suite, "test_defiler", test_fifo_defiler);
    CU_add_test(suite, "test_ordre", test_fifo_ordre);
    CU_add_test(suite, "test_fifo_pleine", test_fifo_pleine);
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}