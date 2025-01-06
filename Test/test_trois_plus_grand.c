#include <CUnit/Basic.h>
#include "../Fonction/trois_plus_grand.h"

void test_trois_plus_grand(void) {
    int liste_test[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int taille = 10;
    int resultat[3]; 
    trois_plus_grand(liste_test, taille, resultat);

    CU_ASSERT_EQUAL(resultat[0], 10);
    CU_ASSERT_EQUAL(resultat[1], 9);
    CU_ASSERT_EQUAL(resultat[2], 8);
    
}
int main(){
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("Suite_trois_plus_grand", NULL, NULL);
    CU_add_test(suite, "test_trois_plus_grand", test_trois_plus_grand);
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}