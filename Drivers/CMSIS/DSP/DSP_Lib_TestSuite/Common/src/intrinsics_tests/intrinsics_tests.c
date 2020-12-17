#include "jtest.h"
#include "ref.h"
#include "arr_desc.h"
#include "intrinsics_templates.h"
#include "intrinsics_test_data.h"
#include "type_abbrev.h"

INTRINSICS_TEST_TEMPLATE_ELT2( __QADD8, q31 );
INTRINSICS_TEST_TEMPLATE_ELT2( __QSUB8, q31 );
INTRINSICS_TEST_TEMPLATE_ELT2( __QADD16, q31 );
INTRINSICS_TEST_TEMPLATE_ELT2( __SHADD16, q31 );
INTRINSICS_TEST_TEMPLATE_ELT2( __QSUB16, q31 );
INTRINSICS_TEST_TEMPLATE_ELT2( __SHSUB16, q31 );
INTRINSICS_TEST_TEMPLATE_ELT2( __QASX, q31 );
INTRINSICS_TEST_TEMPLATE_ELT2( __SHASX, q31 );
INTRINSICS_TEST_TEMPLATE_ELT2( __QSAX, q31 );
INTRINSICS_TEST_TEMPLATE_ELT2( __SHSAX, q31 );
INTRINSICS_TEST_TEMPLATE_ELT2( __SMUSDX, q31 );
INTRINSICS_TEST_TEMPLATE_ELT2( __SMUADX, q31 );
INTRINSICS_TEST_TEMPLATE_ELT2( __QADD, q31 );
INTRINSICS_TEST_TEMPLATE_ELT2( __QSUB, q31 );
INTRINSICS_TEST_TEMPLATE_ELT3( __SMLAD, q31 );
INTRINSICS_TEST_TEMPLATE_ELT3( __SMLADX, q31 );
INTRINSICS_TEST_TEMPLATE_ELT3( __SMLSDX, q31 );
INTRINSICS_TEST_TEMPLATE_ELT4( __SMLALD, q31, q63 );
INTRINSICS_TEST_TEMPLATE_ELT4( __SMLALDX, q31, q63 );
INTRINSICS_TEST_TEMPLATE_ELT2( __SMUAD, q31 );
INTRINSICS_TEST_TEMPLATE_ELT2( __SMUSD, q31 );
INTRINSICS_TEST_TEMPLATE_ELT1( __SXTB16, q31 );

/*--------------------------------------------------------------------------------*/
/* Collect all tests in a group */
/*--------------------------------------------------------------------------------*/

JTEST_DEFINE_GROUP( intrinsics_tests )
{
    /*
      To skip a test, comment it out.
    */
    JTEST_TEST_CALL( __QADD8_test );
    JTEST_TEST_CALL( __QSUB8_test );
    JTEST_TEST_CALL( __QADD16_test );
    JTEST_TEST_CALL( __SHADD16_test );
    JTEST_TEST_CALL( __QSUB16_test );
    JTEST_TEST_CALL( __SHSUB16_test );
    JTEST_TEST_CALL( __QASX_test );
    JTEST_TEST_CALL( __SHASX_test );
    JTEST_TEST_CALL( __QSAX_test );
    JTEST_TEST_CALL( __SHSAX_test );
    JTEST_TEST_CALL( __SMUSDX_test );
    JTEST_TEST_CALL( __SMUADX_test );
    JTEST_TEST_CALL( __QADD_test );
    JTEST_TEST_CALL( __QSUB_test );
    JTEST_TEST_CALL( __SMLAD_test );
    JTEST_TEST_CALL( __SMLADX_test );
    JTEST_TEST_CALL( __SMLSDX_test );
    JTEST_TEST_CALL( __SMLALD_test );
    JTEST_TEST_CALL( __SMLALDX_test );
    JTEST_TEST_CALL( __SMUAD_test );
    JTEST_TEST_CALL( __SMUSD_test );
    JTEST_TEST_CALL( __SXTB16_test );
}
