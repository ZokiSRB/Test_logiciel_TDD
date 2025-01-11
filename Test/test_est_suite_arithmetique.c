#include <CUnit/Basic.h>
#include "../Fonction/est_suite_arithmetique.h"

void test_est_suite_arithmetique(void) {
    int liste_test[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int liste_test_faux[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11};
    int taille = 10;
    int resultat = est_suite_arithmetique(liste_test, taille);
    int resultat_faux = est_suite_arithmetique(liste_test_faux, taille);

    int liste_test_unique[] = {1};
    int resultat_unique = est_suite_arithmetique(liste_test_unique, 1);
    CU_ASSERT_EQUAL(resultat_unique, 1);

    int liste_test_vide[] = {};
    int resultat_vide = est_suite_arithmetique(liste_test_vide, 0);
    CU_ASSERT_EQUAL(resultat_vide, 1);

    int liste_test_2[] = {4,3,2,1};
    int resultat_decroi = est_suite_arithmetique(liste_test_2, 4);
    CU_ASSERT_EQUAL(resultat_decroi, 1);

    CU_ASSERT_EQUAL(resultat, 1);
    CU_ASSERT_EQUAL(resultat_faux, 0);


}

int main(){
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("Suite_est_suite_arithmetique", NULL, NULL);
    CU_add_test(suite, "test_est_suite_arithmetique", test_est_suite_arithmetique);
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}