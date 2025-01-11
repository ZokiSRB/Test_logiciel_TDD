#include <CUnit/Basic.h>
#include "../Fonction/premier.h"

void test_premier(void) {
    int nb_liste[] = {1, 3, 2, 43, 10};
    premier(nb_liste);
    CU_ASSERT_EQUAL(nb_liste[0], 0);
    CU_ASSERT_EQUAL(nb_liste[1], 1);
    CU_ASSERT_EQUAL(nb_liste[2], 1);
    CU_ASSERT_EQUAL(nb_liste[3], 1);
    CU_ASSERT_EQUAL(nb_liste[4], 0);

}

int main(){
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("Suite_", NULL, NULL);
    CU_add_test(suite, "test_", test_premier);
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}
