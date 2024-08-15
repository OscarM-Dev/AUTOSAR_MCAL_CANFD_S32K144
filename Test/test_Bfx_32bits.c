/**
 * @file test_Bfx_32bits.c
 * @brief This file contains the definition and declaration of the unit test cases for Bfx_32bits.h
 * 
 * The test cases are the following: 60
 * 
 * Bfx_SetBit_u32u8: 2
 * 
 *  test__Bfx_SetBit_u32u8__bit30
 * 
 *  test__Bfx_SetBit_u32u8__bit20
 * 
 * Bfx_ClrBit_u32u8: 2
 * 
 *  test__Bfx_ClrBit_u32u8__bit25
 * 
 *  test__Bfx_ClrBit_u32u8__bit13
 * 
 * Bfx_GetBit_u32u8_u8: 2
 *  
 *  test__Bfx_GetBit_u32u8_u8__bit23
 *  
 *  test__Bfx_GetBit_u32u8_u8__bit27
 * 
 * Bfx_SetBits_u32u8u8u8: 2
 * 
 *  test__Bfx_SetBits_u32u8u8u8__Status_1
 * 
 *  test__Bfx_SetBits_u32u8u8u8__Status_0
 * 
 * Bfx_GetBits_u32u8u8_u32: 2
 * 
 *  test__Bfx_GetBits_u32u8u8_u32__5_bits_from_bit_10
 * 
 *  test__Bfx_GetBits_u32u8u8_u32__3_bits_from_bit_24
 * 
 * Bfx_SetBitMask_u32u32: 2
 * 
 *  test__Bfx_SetBitMask_u32u32__mask_1
 * 
 *  test__Bfx_SetBitMask_u32u32__mask_2
 * 
 * Bfx_ClrBitMask_u32u32: 2
 * 
 *  test__Bfx_ClrBitMask_u32u32__mask_1
 * 
 *  test__Bfx_ClrBitMask_u32u32__mask_2
 * 
 * Bfx_TstBitMask_u32u32_u8: 2
 * 
 *  test__Bfx_TstBitMask_u32u32_u8__True
 * 
 *  test__Bfx_TstBitMask_u32u32_u8__False
 * 
 * Bfx_TstBitLnMask_u32u32_u8: 2
 * 
 *  test__Bfx_TstBitLnMask_u32u32_u8__True
 * 
 *  test__Bfx_TstBitLnMask_u32u32_u8__False
 * 
 * Bfx_TstParityEven_u32_u8: 2
 * 
 *  test__Bfx_TstParityEven_u32_u8__Even
 * 
 *  test__Bfx_TstParityEven_u32_u8__Not_even
 * 
 * Bfx_ToggleBits_u32: 2
 * 
 *  test__Bfx_ToggleBits_u32_case_1
 * 
 *  test__Bfx_ToggleBits_u32_case_2
 * 
 * Bfx_ToggleBitMask_u32u32: 2
 * 
 *  test__Bfx_ToggleBitMask_u32u32__mask_1
 * 
 *  test__Bfx_ToggleBitMask_u32u32__mask_2
 * 
 * Bfx_ShiftBitRt_u32u8: 2
 * 
 *  test__Bfx_ShiftBitRt_u32u8__14_spaces
 * 
 *  test__Bfx_ShiftBitRt_u32u8__26_spaces
 * 
 * Bfx_ShiftBitLt_u32u8: 2
 * 
 *  test__Bfx_ShiftBitLt_u32u8__25_spaces
 * 
 *  test__Bfx_ShiftBitLt_u32u8__13_spaces
 * 
 * Bfx_RotBitRt_u32u8: 2
 * 
 *  test__Bfx_RotBitRt_u32u8__14_spaces
 * 
 *  test__Bfx_RotBitRt_u32u8__26_spaces
 * 
 * Bfx_RotBitLt_u32u8: 2
 * 
 *  test__Bfx_RotBitLt_u32u8__25_spaces
 * 
 *  test__Bfx_RotBitLt_u32u8__13_spaces
 * 
 * Bfx_CopyBit_u32u8u32u8: 2
 * 
 *  test__Bfx_CopyBit_u32u8u32u8__24_to_26
 * 
 *  test__Bfx_CopyBit_u32u8u32u8__15_to_17
 * 
 * Bfx_PutBit_u32u8u8: 2
 * 
 *  test__Bfx_PutBit_u32u8u8__Status_1
 * 
 *  test__Bfx_PutBit_u32u8u8__Status_0
 * 
 * Bfx_PutBitsMask_u32u32u32: 2
 * 
 *  test__Bfx_PutBitsMask_u32u32u32__case_1
 * 
 *  test__Bfx_PutBitsMask_u32u32u32__case_2
 * 
 * Bfx_PutBits_u32u8u8u32: 2
 * 
 *  test__Bfx_PutBits_u32u8u8u32__case_1
 * 
 *  test__Bfx_PutBits_u32u8u8u32__case_2
 * 
 * Bfx_ShiftBitSat_u32s8_u32: 3
 * 
 *  test__Bfx_ShiftBitSat_u32s8_u32__Right
 * 
 *  test__Bfx_ShiftBitSat_u32s8_u32__Left_no_sat
 * 
 *  test__Bfx_ShiftBitSat_u32s8_u32__Left_sat
 * 
 * Bfx_ShiftBitSat_s32s8_s32: 8
 * 
 *  test__Bfx_ShiftBitSat_s32s8_s32__Right
 * 
 *  test__Bfx_ShiftBitSat_s32s8_s32__Right_0
 * 
 *  test__Bfx_ShiftBitSat_s32s8_s32__Right_neg_1
 * 
 *  test__Bfx_ShiftBitSat_s32s8_s32__Left_no_sat
 * 
 *  test__Bfx_ShiftBitSat_s32s8_s32__Left_pos_sat_0
 * 
 *  test__Bfx_ShiftBitSat_s32s8_s32__Left_pos_sat_1
 * 
 *  test__Bfx_ShiftBitSat_s32s8_s32__Left_neg_sat_0
 * 
 *  test__Bfx_ShiftBitSat_s32s8_s32__Left_neg_sat_1
 * 
 * Bfx_CountLeadingOnes_u32: 3
 * 
 *  test__Bfx_CountLeadingOnes_u32__case_1
 * 
 *  test__Bfx_CountLeadingOnes_u32__case_2
 * 
 *  test__Bfx_CountLeadingOnes_u32__case_3
 * 
 * Bfx_CountLeadingSigns_s32: 3
 * 
 *  test__Bfx_CountLeadingSigns_s32__case_1
 * 
 *  test__Bfx_CountLeadingSigns_s32__case_2
 * 
 *  test__Bfx_CountLeadingSigns_s32__case_3
 * 
 * Bfx_CountLeadingZeros_u32: 3
 * 
 *  Bfx_CountLeadingZeros_u32__case_1
 * 
 *  Bfx_CountLeadingZeros_u32__case_2
 *  
 *  Bfx_CountLeadingZeros_u32__case_3
 */

//Headers
#include "unity.h"
#include "Bfx_32bits.h"

//this function is required by Ceedling to run any code before the test cases.
void setUp( void ) {

}

//this function is required by Ceedling to run any code after the test cases.
void tearDown( void ) {

}

//Test cases for Bfx_SetBit_u32u8

/**
 * @brief This function tests the set of a bit in position 30 of the input data. 
 * 
 */
void test__Bfx_SetBit_u32u8__bit30( void ) {
    //local data.
    uint32 Data = 0;

    Bfx_SetBit_u32u8( &Data, 30 );
    TEST_ASSERT_EQUAL_HEX32( 0x40000000 , Data );//Testing.
}

/**
 * @brief This function tests the set of a bit in position 20 of the input data. 
 * 
 */
void test__Bfx_SetBit_u32u8__bit20( void ) {
    //local data.
    uint32 Data = 2;

    Bfx_SetBit_u32u8( &Data, 20 );
    TEST_ASSERT_EQUAL_HEX32( 0x00100002 , Data );//Testing.
}

//Test cases for Bfx_ClrBit_u32u8

/**
 * @brief This function tests the clear of a bit in position 25 of the input data. 
 * 
 */
void test__Bfx_ClrBit_u32u8__bit25( void ) {
    //local data
    uint32 Data = 0xFFFFFFFF;

    Bfx_ClrBit_u32u8( &Data, 25 );
    TEST_ASSERT_EQUAL_HEX32( 0xFDFFFFFF , Data );//Testing.
}

/**
 * @brief This function tests the clear of a bit in position 13 of the input data. 
 * 
 */
void test__Bfx_ClrBit_u32u8__bit13( void ) {
    //local data
    uint32 Data = 0xFFFFFFFF;

    Bfx_ClrBit_u32u8( &Data, 13 );
    TEST_ASSERT_EQUAL_HEX32( 0xFFFFDFFF , Data );//Testing.
}

//Test cases for Bfx_GetBit_u32u8_u8

/**
 * @brief This function tests the get of a bit in position 23 of the input data. 
 *
 */
void test__Bfx_GetBit_u32u8_u8__bit23( void ) {
    //local data
    boolean Result = FALSE;

    Result = Bfx_GetBit_u32u8_u8( 0xCC7455D3, 23 );
    TEST_ASSERT_EQUAL_UINT8( FALSE , Result );//Testing.
}

/**
 * @brief This function tests the get of a bit in position 27 of the input data. 
 *
 */
void test__Bfx_GetBit_u32u8_u8__bit27( void ) {
    //local data
    boolean Result = FALSE;

    Result = Bfx_GetBit_u32u8_u8( 0xD8F34500, 27 );
    TEST_ASSERT_EQUAL_UINT8( TRUE , Result );//Testing.
}

//Test cases for Bfx_SetBits_u32u8u8u8

/**
 * @brief This function tests the set of multiple bits to status = 1;
 *
 */
void test__Bfx_SetBits_u32u8u8u8__Status_1( void ) {
    //local data 
    uint32 Data = 0x34003200;

    Bfx_SetBits_u32u8u8u8( &Data, 16, 4, 1 );
    TEST_ASSERT_EQUAL_HEX32( 0x340F3200, Data );//Testing.
}

/**
 * @brief This function tests the set of multiple bits to status = 0;
 *
 */
void test__Bfx_SetBits_u32u8u8u8__Status_0( void ) {
    //local data 
    uint32 Data = 0x7FFF3534;

    Bfx_SetBits_u32u8u8u8( &Data, 28, 2, 0 );
    TEST_ASSERT_EQUAL_HEX32( 0x4FFF3534 , Data );//Testing.
}

//Test cases for Bfx_GetBits_u32u8u8_u32

/**
 * @brief This function tests the get of 5 bits from bit 10 of input data.
 *
 */
void test__Bfx_GetBits_u32u8u8_u32__5_bits_from_bit_10( void ) {
    //local data
    uint32 result = 0;

    result = Bfx_GetBits_u32u8u8_u32( 0xF8002653, 10, 5 );
    TEST_ASSERT_EQUAL_HEX32( 0x09 , result );//Testing.
}

/**
 * @brief This function tests the get of 3 bits from bit 24 of input data.
 *
 */
void test__Bfx_GetBits_u32u8u8_u32__3_bits_from_bit_24( void ) {
    //local data
    uint32 result = 0;

    result = Bfx_GetBits_u32u8u8_u32( 0xC5D11045, 24, 3 );
    TEST_ASSERT_EQUAL_HEX32( 0x05 , result );//Testing.
}

//Test cases for Bfx_SetBitMask_u32u32

/**
 * @brief This function tests the setmask applied to input data.
 *
 */
void test__Bfx_SetBitMask_u32u32__mask_1( void ) {
    //local data.
    uint32 Data = 0xE4000000;

    Bfx_SetBitMask_u32u32( &Data, 0X18000002 );
    TEST_ASSERT_EQUAL_HEX32( 0xFC000002 , Data );//Testing.
}

/**
 * @brief This function tests the setmask applied to input data.
 *
 */
void test__Bfx_SetBitMask_u32u32__mask_2( void ) {
    //local data.
    uint32 Data = 0xD2000000;

    Bfx_SetBitMask_u32u32( &Data, 0X2C007000 );
    TEST_ASSERT_EQUAL_HEX32( 0xFE007000 , Data );//Testing.
}

//Test cases for Bfx_ClrBitMask_u32u32

/**
 * @brief This function tests the clearmask applied to input data.
 *
 */
void test__Bfx_ClrBitMask_u32u32__mask_1( void ) {
    //local data.
    uint32 Data = 0xE4560000;

    Bfx_ClrBitMask_u32u32( &Data, 0x60120000 );
    TEST_ASSERT_EQUAL_HEX32( 0x84440000 , Data );//Testing.   
}

/**
 * @brief This function tests the clearmask applied to input data.
 *
 */
void test__Bfx_ClrBitMask_u32u32__mask_2( void ) {
    //local data.
    uint32 Data = 0xD2740026;

    Bfx_ClrBitMask_u32u32( &Data, 0x12140004 );
    TEST_ASSERT_EQUAL_HEX32( 0xC0600022 , Data );//Testing.   
}

//Test cases for Bfx_TstBitMask_u32u32_u8

/**
 * @brief This function tests if all the bits set in mask are set in input data.
 *
 */
void test__Bfx_TstBitMask_u32u32_u8__True( void ) {
    //local data.
    boolean result = FALSE;

    result = Bfx_TstBitMask_u32u32_u8( 0xF5000000, 0xF5000000 );
    TEST_ASSERT_EQUAL_UINT8( TRUE , result );//Testing. 
}

/**
 * @brief This function tests if all the bits set in mask are set in input data.
 *
 */
void test__Bfx_TstBitMask_u32u32_u8__False( void ) {
    //local data.
    boolean result = FALSE;

    result = Bfx_TstBitMask_u32u32_u8( 0xD3000014, 0xFF340000 );
    TEST_ASSERT_EQUAL_UINT8( FALSE , result );//Testing. 
}

//Test cases for Bfx_TstBitLnMask_u32u32_u8

/**
 * @brief This function tests if at least 1 bit set in mask is set in input data.
 *
 */
void test__Bfx_TstBitLnMask_u32u32_u8__True( void ) {
    //local data.
    boolean result = FALSE;

    result = Bfx_TstBitLnMask_u32u32_u8( 0xF3002456, 0x01504200 );
    TEST_ASSERT_EQUAL_UINT8( TRUE , result );//Testing.
}

/**
 * @brief This function tests if at least 1 bit set in mask is set in input data.
 *
 */
void test__Bfx_TstBitLnMask_u32u32_u8__False( void ) {
    //local data.
    boolean result = FALSE;

    result = Bfx_TstBitLnMask_u32u32_u8( 0xE8000000, 0x12000000 );
    TEST_ASSERT_EQUAL_UINT8( FALSE , result );//Testing.
}


//Test cases for Bfx_TstParityEven_u32_u8

/**
 * @brief This function tests if the number of bits set in input data is even.
 *
 */
void test__Bfx_TstParityEven_u32_u8__Even( void ) {
    //local data
    boolean result = FALSE;

    result = Bfx_TstParityEven_u32_u8( 0xEE00CC00 );
    TEST_ASSERT_EQUAL_UINT8( TRUE , result );//Testing.
}

/**
 * @brief This function tests if the number of bits set in input data is even.
 *
 */
void test__Bfx_TstParityEven_u32_u8__Not_even( void ) {
    //local data
    boolean result = FALSE;

    result = Bfx_TstParityEven_u32_u8( 0xE5E5E500 );
    TEST_ASSERT_EQUAL_UINT8( FALSE , result );//Testing.
}

//Test cases for Bfx_ToggleBits_u32

/**
 * @brief This function tests the toggle of all the bits of input data.
 *
 */
void test__Bfx_ToggleBits_u32_case_1( void ) {
    //local data
    uint32 Data = 0;

    Bfx_ToggleBits_u32( &Data ); 
    TEST_ASSERT_EQUAL_HEX32( 0xFFFFFFFF , Data );//Testing.
}

/**
 * @brief This function tests the toggle of all the bits of input data.
 *
 */
void test__Bfx_ToggleBits_u32_case_2( void ) {
    //local data
    uint32 Data = 0xE4E4E4E4;

    Bfx_ToggleBits_u32( &Data ); 
    TEST_ASSERT_EQUAL_HEX32( 0x1B1B1B1B , Data );//Testing.
}

//Test cases for Bfx_ToggleBitMask_u32u32

/**
 * @brief This function tests the togglemask applied to input data.
 *
 */
void test__Bfx_ToggleBitMask_u32u32__mask_1( void ) {
    //local data.
    uint32 Data = 0xD2D2D2D2;

    Bfx_SetBitMask_u32u32( &Data, 0x08080808 );
    TEST_ASSERT_EQUAL_HEX32( 0xDADADADA , Data );//Testing.
}

/**
 * @brief This function tests the togglemask applied to input data.
 *
 */
void test__Bfx_ToggleBitMask_u32u32__mask_2( void ) {
    //local data.
    uint32 Data = 0xC5C5C5C5;

    Bfx_SetBitMask_u32u32( &Data, 0x18181818 );
    TEST_ASSERT_EQUAL_HEX32( 0xDDDDDDDD , Data );//Testing.
}

//Test cases for Bfx_ShiftBitRt_u32u8

/**
 * @brief This function tests the shift to the right of 14 spaces of input data.
 *
 */
void test__Bfx_ShiftBitRt_u32u8__14_spaces( void ) {
    //local data.
    uint32 Data = 0xB4002553;

    Bfx_ShiftBitRt_u32u8( &Data, 14 );
    TEST_ASSERT_EQUAL_HEX32( 0x0002D000 , Data );//Testing.
}

/**
 * @brief This function tests the shift to the right of 26 spaces of input data.
 *
 */
void test__Bfx_ShiftBitRt_u32u8__26_spaces( void ) {
    //local data.
    uint32 Data = 0xC5470010;

    Bfx_ShiftBitRt_u32u8( &Data, 26 );
    TEST_ASSERT_EQUAL_HEX32( 0x00000031 , Data );//Testing.
}

//Test cases for Bfx_ShiftBitLt_u32u8

/**
 * @brief This function tests the shift to the left of 25 spaces of input data.
 *
 */
void test__Bfx_ShiftBitLt_u32u8__25_spaces( void ) {
    //local data.
    uint32 Data = 0x000000B4;

    Bfx_ShiftBitLt_u32u8( &Data, 25 );
    TEST_ASSERT_EQUAL_HEX32( 0x68000000 , Data );//Testing.
}

/**
 * @brief This function tests the shift to the left of 13 spaces of input data.
 *
 */
void test__Bfx_ShiftBitLt_u32u8__13_spaces( void ) {
    //local data.
    uint32 Data = 0x000000C5;

    Bfx_ShiftBitLt_u32u8( &Data, 13 );
    TEST_ASSERT_EQUAL_HEX32( 0x0018A000 , Data );//Testing.
}


//Test cases for Bfx_RotBitRt_u32u8

/**
 * @brief This function tests the rotate to the right of 14 spaces of input data.
 *
 */
void test__Bfx_RotBitRt_u32u8__14_spaces( void ) {
    //local data.
    uint32 Data = 0xB4002553;

    Bfx_RotBitRt_u32u8( &Data, 14 );
    TEST_ASSERT_EQUAL_HEX32( 0x954ED000 , Data );//Testing.
}

/**
 * @brief This function tests the rotate to the right of 26 spaces of input data.
 *
 */
void test__Bfx_RotBitRt_u32u8__26_spaces( void ) {
    //local data.
    uint32 Data = 0xC5470010;

    Bfx_RotBitRt_u32u8( &Data, 26 );
    TEST_ASSERT_EQUAL_HEX32( 0x51C00431 , Data );//Testing.
}

//Test cases for Bfx_RotBitLt_u32u8

/**
 * @brief This function tests the rotate to the left of 25 spaces of input data.
 *
 */
void test__Bfx_RotBitLt_u32u8__25_spaces( void ) {
    //local data.
    uint32 Data = 0x520024B4;

    Bfx_RotBitLt_u32u8( &Data, 25 );
    TEST_ASSERT_EQUAL_HEX32( 0x68A40049 , Data );//Testing.
}

/**
 * @brief This function tests the rotate to the left of 13 spaces of input data.
 *
 */
void test__Bfx_RotBitLt_u32u8__13_spaces( void ) {
    //local data.
    uint32 Data = 0x102000C5;

    Bfx_RotBitLt_u32u8( &Data, 13 );
    TEST_ASSERT_EQUAL_HEX32( 0x0018A204 , Data );//Testing.
}

//Test cases for Bfx_CopyBit_u32u8u32u8

/**
 * @brief This function tests the copy and paste from position 24 to position 26.
 *
 */
void test__Bfx_CopyBit_u32u8u32u8__24_to_26( void ) {
    //local data
    uint32 dest_data = 0xB4000020;

    Bfx_CopyBit_u32u8u32u8( &dest_data, 26, 0xFC000000, 24 );
    TEST_ASSERT_EQUAL_HEX32( 0xB0000020 , dest_data );//Testing.
}

/**
 * @brief This function tests the copy and paste from position 15 to position 17.
 *
 */
void test__Bfx_CopyBit_u32u8u32u8__15_to_17( void ) {
    //local data
    uint32 dest_data = 0xE4000000;

    Bfx_CopyBit_u32u8u32u8( &dest_data, 17, 0x0000F200, 15 );
    TEST_ASSERT_EQUAL_HEX32( 0xE4020000 , dest_data );//Testing.
}


//Test cases for Bfx_PutBit_u32u8u8

/**
 * @brief This function tests the put of a bit with status = 1.
 *
 */
void test__Bfx_PutBit_u32u8u8__Status_1( void ) {
    //local data 
    uint32 Data = 0xB1000000;

    Bfx_PutBit_u32u8u8( &Data, 27, 1 );
    TEST_ASSERT_EQUAL_HEX32( 0xB9000000 , Data );//Testing.
}

/**
 * @brief This function tests the put of a bit with status = 0.
 *
 */
void test__Bfx_PutBit_u32u8u8__Status_0( void ) {
    //local data 
    uint32 Data = 0xD5000000;

    Bfx_PutBit_u32u8u8( &Data, 28, 0 );
    TEST_ASSERT_EQUAL_HEX32( 0xC5000000 , Data );//Testing.
}


//Test cases for Bfx_PutBitsMask_u32u32u32

/**
 * @brief This function tests the pattern/mask applied to input data.
 *
 */
void test__Bfx_PutBitsMask_u32u32u32__case_1( void ) {
    //local data.
    uint32 Data = 0xD2000000;

    Bfx_PutBitsMask_u32u32u32( &Data, 0x76000000, 0x0F000000 );
    TEST_ASSERT_EQUAL_HEX32( 0xD6000000 , Data );//Testing.   
}

/**
 * @brief This function tests the pattern/mask applied to input data.
 *
 */
void test__Bfx_PutBitsMask_u32u32u32__case_2( void ) {
    //local data.
    uint32 Data = 0xA4000000;

    Bfx_PutBitsMask_u32u32u32( &Data, 0xC5000000, 0xD2000000 );
    TEST_ASSERT_EQUAL_HEX32( 0xE4000000 , Data );//Testing.   
}

//Test cases for Bfx_PutBits_u32u8u8u32

/**
 * @brief This function tests the pattern applied to input data.
 *
 */
void test__Bfx_PutBits_u32u8u8u32__case_1( void ) {
    //local data 
    uint32 Data = 0xA5000000;

    Bfx_PutBits_u32u8u8u32( &Data, 27, 4, 0x000000F1 );
    TEST_ASSERT_EQUAL_HEX32( 0x8D000000 , Data );//Testing. 
}

/**
 * @brief This function tests the pattern applied to input data.
 *
 */
void test__Bfx_PutBits_u32u8u8u32__case_2( void ) {
    //local data 
    uint32 Data = 0xC5000000;

    Bfx_PutBits_u32u8u8u32( &Data, 26, 6, 0x000000E4 );
    TEST_ASSERT_EQUAL_HEX32( 0x91000000 , Data );//Testing. 
}

//Test cases for Bfx_ShiftBitSat_u32s8_u32

/**
 * @brief This function tests the saturated shift of uint32 input data
 *
 */
void test__Bfx_ShiftBitSat_u32s8_u32__Right( void ) {
    //local data
    uint32 result = 0;

    result = Bfx_ShiftBitSat_u32s8_u32( -2, 0x000000F0 );
    TEST_ASSERT_EQUAL_HEX32( 0x0000003C , result );//Testing. 
}

/**
 * @brief This function tests the saturated shift of uint32 input data
 *
 */
void test__Bfx_ShiftBitSat_u32s8_u32__Left_no_sat( void ) {
    //local data
    uint32 result = 0;

    result = Bfx_ShiftBitSat_u32s8_u32( 3, 0x12000000 );
    TEST_ASSERT_EQUAL_HEX32( 0x90000000 , result );//Testing. 
}

/**
 * @brief This function tests the saturated shift of uint32 input data
 *
 */
void test__Bfx_ShiftBitSat_u32s8_u32__Left_sat( void ) {
    //local data
    uint32 result = 0;

    result = Bfx_ShiftBitSat_u32s8_u32( 5, 0x12000000 );
    TEST_ASSERT_EQUAL_HEX32( 0xFFFFFFFF , result );//Testing. 
}


//Test cases for Bfx_ShiftBitSat_s32s8_s32

/**
 * @brief This function tests the saturated shift of int32 input data
 *
 */
void test__Bfx_ShiftBitSat_s32s8_s32__Right( void ) {
    //local data.
    sint32 result = 0;

    result = Bfx_ShiftBitSat_s32s8_s32( -4, 0x70000000 );
    TEST_ASSERT_EQUAL_INT32( 0x07000000 , result );//Testing. 
}


/**
 * @brief This function tests the saturated shift of int32 input data
 *
 */
void test__Bfx_ShiftBitSat_s32s8_s32__Right_0( void ) {
    //local data.
    sint32 result = 0;

    result = Bfx_ShiftBitSat_s32s8_s32( -32, 0x00000014 );
    TEST_ASSERT_EQUAL_INT32( 0 , result );//Testing. 
}

/**
 * @brief This function tests the saturated shift of int32 input data
 *
 */
void test__Bfx_ShiftBitSat_s32s8_s32__Right_neg_1( void ) {
    //local data.
    sint32 result = 0;

    result = Bfx_ShiftBitSat_s32s8_s32( -32, 0xFFFFFFEC );
    TEST_ASSERT_EQUAL_INT32( -1 , result );//Testing. 
}

/**
 * @brief This function tests the saturated shift of int32 input data
 *
 */
void test__Bfx_ShiftBitSat_s32s8_s32__Left_no_sat( void ) {
    //local data.
    sint32 result = 0;

    result = Bfx_ShiftBitSat_s32s8_s32( 2, 0x10000000 );
    TEST_ASSERT_EQUAL_INT32( 0x40000000 , result );//Testing. 
}

/**
 * @brief This function tests the saturated shift of int32 input data
 *
 */
void test__Bfx_ShiftBitSat_s32s8_s32__Left_pos_sat_0( void ) {
    //local data.
    sint32 result = 0;

    result = Bfx_ShiftBitSat_s32s8_s32( 5, 0x50000000 );
    TEST_ASSERT_EQUAL_INT32( 2147483647 , result );//Testing. 
}

/**
 * @brief This function tests the saturated shift of int32 input data
 *
 */
void test__Bfx_ShiftBitSat_s32s8_s32__Left_pos_sat_1( void ) {
    //local data.
    sint32 result = 0;

    result = Bfx_ShiftBitSat_s32s8_s32( 31, 0x50000000 );
    TEST_ASSERT_EQUAL_INT32( 2147483647 , result );//Testing. 
}

/**
 * @brief This function tests the saturated shift of int32 input data
 *
 */
void test__Bfx_ShiftBitSat_s32s8_s32__Left_neg_sat_0( void ) {
    //local data.
    sint32 result = 0;

    result = Bfx_ShiftBitSat_s32s8_s32( 2, 0xC0FFFFFF );
    TEST_ASSERT_EQUAL_INT32( -2147483648  , result );//Testing. 
}

/**
 * @brief This function tests the saturated shift of int32 input data
 *
 */
void test__Bfx_ShiftBitSat_s32s8_s32__Left_neg_sat_1( void ) {
    //local data.
    sint32 result = 0;

    result = Bfx_ShiftBitSat_s32s8_s32( 31, 0xC0FFFFFF );
    TEST_ASSERT_EQUAL_INT32( -2147483648 , result );//Testing. 
}

//Test cases for Bfx_CountLeadingOnes_u32

/**
 * @brief This function tests the count of consecutive 1s from msb.
 *
 */
void test__Bfx_CountLeadingOnes_u32__case_1( void ) {
    //local data.
    uint8 count = 0;

    count = Bfx_CountLeadingOnes_u32( 0xF3000000 );
    TEST_ASSERT_EQUAL_UINT8( 4 , count );//Testing. 
}

/**
 * @brief This function tests the count of consecutive 1s from msb.
 *
 */
void test__Bfx_CountLeadingOnes_u32__case_2( void ) {
    //local data.
    uint8 count = 0;

    count = Bfx_CountLeadingOnes_u32( 0xC2000000 );
    TEST_ASSERT_EQUAL_UINT8( 2 , count );//Testing. 
}

/**
 * @brief This function tests the count of consecutive 1s from msb.
 *
 */
void test__Bfx_CountLeadingOnes_u32__case_3( void ) {
    //local data.
    uint8 count = 0;

    count = Bfx_CountLeadingOnes_u32( 0xFFFFFFFF );
    TEST_ASSERT_EQUAL_UINT8( 32 , count );//Testing. 
}

//Test cases for Bfx_CountLeadingSigns_s32

/**
 * @brief This function tests the count of consecutive sign bits from msb.
 *
 */
void test__Bfx_CountLeadingSigns_s32__case_1( void ) {
    //local data.
    uint8 count = 0;

    count = Bfx_CountLeadingSigns_s32( 0x01000000 );
    TEST_ASSERT_EQUAL_UINT8( 7 , count );//Testing.    
}

/**
 * @brief This function tests the count of consecutive sign bits from msb.
 *
 */
void test__Bfx_CountLeadingSigns_s32__case_2( void ) {
    //local data.
    uint8 count = 0;

    count = Bfx_CountLeadingSigns_s32( 0xECFFFFFF );
    TEST_ASSERT_EQUAL_UINT8( 3 , count );//Testing.    
}

/**
 * @brief This function tests the count of consecutive sign bits from msb.
 *
 */
void test__Bfx_CountLeadingSigns_s32__case_3( void ) {
    //local data.
    uint8 count = 0;

    count = Bfx_CountLeadingSigns_s32( 0 );
    TEST_ASSERT_EQUAL_UINT8( 32 , count );//Testing.    
}

//Test cases for Bfx_CountLeadingZeros_u32

/**
 * @brief This function tests the count of consecutive 0s from msb.
 *
 */
void test__Bfx_CountLeadingZeros_u32__case_1( void ) {
    //local data.
    uint8 count = 0;

    count = Bfx_CountLeadingZeros_u32( 0x02000000 );
    TEST_ASSERT_EQUAL_UINT8( 6 , count );//Testing. 
}

/**
 * @brief This function tests the count of consecutive 0s from msb.
 *
 */
void test__Bfx_CountLeadingZeros_u32__case_2( void ) {
    //local data.
    uint8 count = 0;

    count = Bfx_CountLeadingZeros_u32( 0x15000000 );
    TEST_ASSERT_EQUAL_UINT8( 3 , count );//Testing. 
}

/**
 * @brief This function tests the count of consecutive 0s from msb.
 *
 */
void test__Bfx_CountLeadingZeros_u32__case_3( void ) {
    //local data.
    uint8 count = 0;

    count = Bfx_CountLeadingZeros_u32( 0 );
    TEST_ASSERT_EQUAL_UINT8( 32 , count );//Testing. 
}