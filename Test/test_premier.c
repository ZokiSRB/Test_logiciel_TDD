#include <CUnit/Basic.h>
#include "../Fonction/premier.h"

void test_premier(void) {
    int nb_liste[] = {1, 3, 2, 43, 10};
    int resultat[5];
    for (int i = 0; i < 5; i++) {
        resultat[i] = est_premier(nb_liste[i]);
    }
    CU_ASSERT_EQUAL(resultat[0], 0);  
    CU_ASSERT_EQUAL(resultat[1], 1);  
    CU_ASSERT_EQUAL(resultat[2], 1);  
    CU_ASSERT_EQUAL(resultat[3], 1);  
    CU_ASSERT_EQUAL(resultat[4], 0);  

}

int main(){
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("Suite_premier", NULL, NULL);
    CU_add_test(suite, "test_premier", test_premier);
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}
