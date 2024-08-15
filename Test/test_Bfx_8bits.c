/**
 * @file test_Bfx_8bits.c
 * @brief This file contains the definition and declaration of the unit test cases for Bfx_8bits.h
 * 
 * The test cases are the following: 60
 * 
 * Bfx_SetBit_u8u8: 2
 * 
 *  test__Bfx_SetBit_u8u8__bit4
 * 
 *  test__Bfx_SetBit_u8u8__bit7
 * 
 * Bfx_ClrBit_u8u8: 2
 * 
 *  test__Bfx_ClrBit_u8u8__bit5
 * 
 *  test__Bfx_ClrBit_u8u8__bit3
 * 
 * Bfx_GetBit_u8u8_u8: 2
 *  
 *  test__Bfx_GetBit_u8u8_u8__bit3
 *  
 *  test__Bfx_GetBit_u8u8_u8__bit7
 * 
 * Bfx_SetBits_u8u8u8u8: 2
 * 
 *  test__Bfx_SetBits_u8u8u8u8__Status_1
 * 
 *  test__Bfx_SetBits_u8u8u8u8__Status_0
 * 
 * Bfx_GetBits_u8u8u8_u8: 2
 * 
 *  test__Bfx_GetBits_u8u8u8_u8__5_bits_from_bit_0
 * 
 *  test__Bfx_GetBits_u8u8u8_u8__3_bits_from_bit_4
 * 
 * Bfx_SetBitMask_u8u8: 2
 * 
 *  test__Bfx_SetBitMask_u8u8__mask_1
 * 
 *  test__Bfx_SetBitMask_u8u8__mask_2
 * 
 * Bfx_ClrBitMask_u8u8: 2
 * 
 *  test__Bfx_ClrBitMask_u8u8__mask_1
 * 
 *  test__Bfx_ClrBitMask_u8u8__mask_2
 * 
 * Bfx_TstBitMask_u8u8_u8: 2
 * 
 *  test__Bfx_TstBitMask_u8u8_u8__True
 * 
 *  test__Bfx_TstBitMask_u8u8_u8__False
 * 
 * Bfx_TstBitLnMask_u8u8_u8: 2
 * 
 *  test__Bfx_TstBitLnMask_u8u8_u8__True
 * 
 *  test__Bfx_TstBitLnMask_u8u8_u8__False
 * 
 * Bfx_TstParityEven_u8_u8: 2
 * 
 *  test__Bfx_TstParityEven_u8_u8__Even
 * 
 *  test__Bfx_TstParityEven_u8_u8__Not_even
 * 
 * Bfx_ToggleBits_u8: 2
 * 
 *  test__Bfx_ToggleBits_u8_case_1
 * 
 *  test__Bfx_ToggleBits_u8_case_2
 * 
 * Bfx_ToggleBitMask_u8u8: 2
 * 
 *  test__Bfx_ToggleBitMask_u8u8__mask_1
 * 
 *  test__Bfx_ToggleBitMask_u8u8__mask_2
 * 
 * Bfx_ShiftBitRt_u8u8: 2
 * 
 *  test__Bfx_ShiftBitRt_u8u8__4_spaces
 * 
 *  test__Bfx_ShiftBitRt_u8u8__6_spaces
 * 
 * Bfx_ShiftBitLt_u8u8: 2
 * 
 *  test__Bfx_ShiftBitLt_u8u8__5_spaces
 * 
 *  test__Bfx_ShiftBitLt_u8u8__3_spaces
 * 
 * Bfx_RotBitRt_u8u8: 2
 * 
 *  test__Bfx_RotBitRt_u8u8__4_spaces
 * 
 *  test__Bfx_RotBitRt_u8u8__6_spaces
 * 
 * Bfx_RotBitLt_u8u8: 2
 * 
 *  test__Bfx_RotBitLt_u8u8__5_spaces
 * 
 *  test__Bfx_RotBitLt_u8u8__3_spaces
 * 
 * Bfx_CopyBit_u8u8u8u8: 2
 * 
 *  test__Bfx_CopyBit_u8u8u8u8__4_to_6
 * 
 *  test__Bfx_CopyBit_u8u8u8u8__5_to_7
 * 
 * Bfx_PutBit_u8u8u8: 2
 * 
 *  test__Bfx_PutBit_u8u8u8__Status_1
 * 
 *  test__Bfx_PutBit_u8u8u8__Status_0
 * 
 * Bfx_PutBitsMask_u8u8u8: 2
 * 
 *  test__Bfx_PutBitsMask_u8u8u8__case_1
 * 
 *  test__Bfx_PutBitsMask_u8u8u8__case_2
 * 
 * Bfx_PutBits_u8u8u8u8: 2
 * 
 *  test__Bfx_PutBits_u8u8u8u8__case_1
 * 
 *  test__Bfx_PutBits_u8u8u8u8__case_2
 * 
 * Bfx_ShiftBitSat_u8s8_u8: 3
 * 
 *  test__Bfx_ShiftBitSat_u8s8_u8__Right
 * 
 *  test__Bfx_ShiftBitSat_u8s8_u8__Left_no_sat
 * 
 *  test__Bfx_ShiftBitSat_u8s8_u8__Left_sat
 * 
 * Bfx_ShiftBitSat_s8s8_s8: 8
 * 
 *  test__Bfx_ShiftBitSat_s8s8_s8__Right
 * 
 *  test__Bfx_ShiftBitSat_s8s8_s8__Right_0
 * 
 *  test__Bfx_ShiftBitSat_s8s8_s8__Right_neg_1
 * 
 *  test__Bfx_ShiftBitSat_s8s8_s8__Left_no_sat
 * 
 *  test__Bfx_ShiftBitSat_s8s8_s8__Left_pos_sat_0
 * 
 *  test__Bfx_ShiftBitSat_s8s8_s8__Left_pos_sat_1
 * 
 *  test__Bfx_ShiftBitSat_s8s8_s8__Left_neg_sat_0
 * 
 *  test__Bfx_ShiftBitSat_s8s8_s8__Left_neg_sat_1
 * 
 * Bfx_CountLeadingOnes_u8: 3
 * 
 *  test__Bfx_CountLeadingOnes_u8__case_1
 * 
 *  test__Bfx_CountLeadingOnes_u8__case_2
 * 
 *  test__Bfx_CountLeadingOnes_u8__case_3
 * 
 * Bfx_CountLeadingSigns_s8: 3
 * 
 *  test__Bfx_CountLeadingSigns_s8__case_1
 * 
 *  test__Bfx_CountLeadingSigns_s8__case_2
 * 
 *  test__Bfx_CountLeadingSigns_s8__case_3
 * 
 * Bfx_CountLeadingZeros_u8: 3
 * 
 *  Bfx_CountLeadingZeros_u8__case_1
 * 
 *  Bfx_CountLeadingZeros_u8__case_2
 *  
 *  Bfx_CountLeadingZeros_u8__case_3
 */

//Headers
#include "unity.h"
#include "Bfx_8bits.h"

//this function is required by Ceedling to run any code before the test cases.
void setUp( void ) {

}

//this function is required by Ceedling to run any code after the test cases.
void tearDown( void ) {

}

//Test cases for Bfx_SetBit_u8u8

/**
 * @brief This function tests the set of a bit in position 4 of the input data. 
 * 
 */
void test__Bfx_SetBit_u8u8__bit4( void ) {
    //local data.
    uint8 Data = 0;

    Bfx_SetBit_u8u8( &Data, 4 );
    TEST_ASSERT_EQUAL_HEX8( 0x10 , Data );//Testing.
}

/**
 * @brief This function tests the set of a bit in position 7 of the input data. 
 * 
 */
void test__Bfx_SetBit_u8u8__bit7( void ) {
    //local data.
    uint8 Data = 2;

    Bfx_SetBit_u8u8( &Data, 7 );
    TEST_ASSERT_EQUAL_HEX8( 0x82 , Data );//Testing.
}

//Test cases for Bfx_ClrBit_u8u8

/**
 * @brief This function tests the clear of a bit in position 5 of the input data. 
 * 
 */
void test__Bfx_ClrBit_u8u8__bit5( void ) {
    //local data
    uint8 Data = 0xFF;

    Bfx_ClrBit_u8u8( &Data, 5 );
    TEST_ASSERT_EQUAL_HEX8( 0xDF , Data );//Testing.
}

/**
 * @brief This function tests the clear of a bit in position 3 of the input data. 
 * 
 */
void test__Bfx_ClrBit_u8u8__bit3( void ) {
    //local data
    uint8 Data = 0xFF;

    Bfx_ClrBit_u8u8( &Data, 3 );
    TEST_ASSERT_EQUAL_HEX8( 0xF7 , Data );//Testing.
}

//Test cases for Bfx_GetBit_u8u8_u8

/**
 * @brief This function tests the get of a bit in position 3 of the input data. 
 *
 */
void test__Bfx_GetBit_u8u8_u8__bit3( void ) {
    //local data
    boolean Result = FALSE;

    Result = Bfx_GetBit_u8u8_u8( 0xC3, 3 );
    TEST_ASSERT_EQUAL_UINT8( FALSE , Result );//Testing.
}

/**
 * @brief This function tests the get of a bit in position 7 of the input data. 
 *
 */
void test__Bfx_GetBit_u8u8_u8__bit7( void ) {
    //local data
    boolean Result = FALSE;

    Result = Bfx_GetBit_u8u8_u8( 0xD2, 7 );
    TEST_ASSERT_EQUAL_UINT8( TRUE , Result );//Testing.
}

//Test cases for Bfx_SetBits_u8u8u8u8

/**
 * @brief This function tests the set of multiple bits to status = 1;
 *
 */
void test__Bfx_SetBits_u8u8u8u8__Status_1( void ) {
    //local data 
    uint8 Data = 0xF1;

    Bfx_SetBits_u8u8u8u8( &Data, 1, 3, 1 );
    TEST_ASSERT_EQUAL_HEX8( 0xFF , Data );//Testing.
}

/**
 * @brief This function tests the set of multiple bits to status = 0;
 *
 */
void test__Bfx_SetBits_u8u8u8u8__Status_0( void ) {
    //local data 
    uint8 Data = 0x7F;

    Bfx_SetBits_u8u8u8u8( &Data, 4, 3, 0 );
    TEST_ASSERT_EQUAL_HEX8( 0x0F , Data );//Testing.
}

//Test cases for Bfx_GetBits_u8u8u8_u8

/**
 * @brief This function tests the get of 5 bits from bit 0 of input data.
 *
 */
void test__Bfx_GetBits_u8u8u8_u8__5_bits_from_bit_0( void ) {
    //local data
    uint8 result = 0;

    result = Bfx_GetBits_u8u8u8_u8( 0xF8, 0, 5 );
    TEST_ASSERT_EQUAL_HEX8( 0x18 , result );//Testing.
}

/**
 * @brief This function tests the get of 3 bits from bit 4 of input data.
 *
 */
void test__Bfx_GetBits_u8u8u8_u8__3_bits_from_bit_4( void ) {
    //local data
    uint8 result = 0;

    result = Bfx_GetBits_u8u8u8_u8( 0xC5, 4, 3 );
    TEST_ASSERT_EQUAL_HEX8( 0x04 , result );//Testing.
}

//Test cases for Bfx_SetBitMask_u8u8

/**
 * @brief This function tests the setmask applied to input data.
 *
 */
void test__Bfx_SetBitMask_u8u8__mask_1( void ) {
    //local data.
    uint8 Data = 0xE4;

    Bfx_SetBitMask_u8u8( &Data, 0X18 );
    TEST_ASSERT_EQUAL_HEX8( 0xFC , Data );//Testing.
}

/**
 * @brief This function tests the setmask applied to input data.
 *
 */
void test__Bfx_SetBitMask_u8u8__mask_2( void ) {
    //local data.
    uint8 Data = 0xD2;

    Bfx_SetBitMask_u8u8( &Data, 0X2C );
    TEST_ASSERT_EQUAL_HEX8( 0xFE , Data );//Testing.
}

//Test cases for Bfx_ClrBitMask_u8u8

/**
 * @brief This function tests the clearmask applied to input data.
 *
 */
void test__Bfx_ClrBitMask_u8u8__mask_1( void ) {
    //local data.
    uint8 Data = 0xE4;

    Bfx_ClrBitMask_u8u8( &Data, 0x60 );
    TEST_ASSERT_EQUAL_HEX8( 0x84 , Data );//Testing.   
}

/**
 * @brief This function tests the clearmask applied to input data.
 *
 */
void test__Bfx_ClrBitMask_u8u8__mask_2( void ) {
    //local data.
    uint8 Data = 0xD2;

    Bfx_ClrBitMask_u8u8( &Data, 0x12 );
    TEST_ASSERT_EQUAL_HEX8( 0xC0 , Data );//Testing.   
}

//Test cases for Bfx_TstBitMask_u8u8_u8

/**
 * @brief This function tests if all the bits set in mask are set in input data.
 *
 */
void test__Bfx_TstBitMask_u8u8_u8__True( void ) {
    //local data.
    boolean result = FALSE;

    result = Bfx_TstBitMask_u8u8_u8( 0xF5, 0xF5 );
    TEST_ASSERT_EQUAL_UINT8( TRUE , result );//Testing. 
}

/**
 * @brief This function tests if all the bits set in mask are set in input data.
 *
 */
void test__Bfx_TstBitMask_u8u8_u8__False( void ) {
    //local data.
    boolean result = FALSE;

    result = Bfx_TstBitMask_u8u8_u8( 0xD3, 0xFF );
    TEST_ASSERT_EQUAL_UINT8( FALSE , result );//Testing. 
}

//Test cases for Bfx_TstBitLnMask_u8u8_u8

/**
 * @brief This function tests if at least 1 the bit set in mask is set in input data.
 *
 */
void test__Bfx_TstBitLnMask_u8u8_u8__True( void ) {
    //local data.
    boolean result = FALSE;

    result = Bfx_TstBitLnMask_u8u8_u8( 0xF3, 0x01 );
    TEST_ASSERT_EQUAL_UINT8( TRUE , result );//Testing.
}

/**
 * @brief This function tests if at least 1 the bit set in mask is set in input data.
 *
 */
void test__Bfx_TstBitLnMask_u8u8_u8__False( void ) {
    //local data.
    boolean result = FALSE;

    result = Bfx_TstBitLnMask_u8u8_u8( 0xE8, 0x12 );
    TEST_ASSERT_EQUAL_UINT8( FALSE , result );//Testing.
}

//Test cases for Bfx_TstParityEven_u8_u8

/**
 * @brief This function tests if the number of bits set in input data is even.
 *
 */
void test__Bfx_TstParityEven_u8_u8__Even( void ) {
    //local data
    boolean result = FALSE;

    result = Bfx_TstParityEven_u8_u8( 0xEE );
    TEST_ASSERT_EQUAL_UINT8( TRUE , result );//Testing.
}

/**
 * @brief This function tests if the number of bits set in input data is even.
 *
 */
void test__Bfx_TstParityEven_u8_u8__Not_even( void ) {
    //local data
    boolean result = FALSE;

    result = Bfx_TstParityEven_u8_u8( 0xE5 );
    TEST_ASSERT_EQUAL_UINT8( FALSE , result );//Testing.
}

//Test cases for Bfx_ToggleBits_u8

/**
 * @brief This function tests the toggle of all the bits of input data.
 *
 */
void test__Bfx_ToggleBits_u8_case_1( void ) {
    //local data
    uint8 Data = 0;

    Bfx_ToggleBits_u8( &Data ); 
    TEST_ASSERT_EQUAL_HEX8( 0xFF , Data );//Testing.
}

/**
 * @brief This function tests the toggle of all the bits of input data.
 *
 */
void test__Bfx_ToggleBits_u8_case_2( void ) {
    //local data
    uint8 Data = 0xE4;

    Bfx_ToggleBits_u8( &Data ); 
    TEST_ASSERT_EQUAL_HEX8( 0x1B , Data );//Testing.
}

//Test cases for Bfx_ToggleBitMask_u8u8

/**
 * @brief This function tests the togglemask applied to input data.
 *
 */
void test__Bfx_ToggleBitMask_u8u8__mask_1( void ) {
    //local data.
    uint8 Data = 0xD2;

    Bfx_SetBitMask_u8u8( &Data, 0x08 );
    TEST_ASSERT_EQUAL_HEX8( 0xDA , Data );//Testing.
}

/**
 * @brief This function tests the togglemask applied to input data.
 *
 */
void test__Bfx_ToggleBitMask_u8u8__mask_2( void ) {
    //local data.
    uint8 Data = 0xC5;

    Bfx_SetBitMask_u8u8( &Data, 0x18 );
    TEST_ASSERT_EQUAL_HEX8( 0xDD , Data );//Testing.
}

//Test cases for Bfx_ShiftBitRt_u8u8

/**
 * @brief This function tests the shift to the right of 4 spaces of input data.
 *
 */
void test__Bfx_ShiftBitRt_u8u8__4_spaces( void ) {
    //local data.
    uint8 Data = 0xB4;

    Bfx_ShiftBitRt_u8u8( &Data, 4 );
    TEST_ASSERT_EQUAL_HEX8( 0x0B , Data );//Testing.
}

/**
 * @brief This function tests the shift to the right of 6 spaces of input data.
 *
 */
void test__Bfx_ShiftBitRt_u8u8__6_spaces( void ) {
    //local data.
    uint8 Data = 0xC5;

    Bfx_ShiftBitRt_u8u8( &Data, 6 );
    TEST_ASSERT_EQUAL_HEX8( 0x03 , Data );//Testing.
}

//Test cases for Bfx_ShiftBitLt_u8u8

/**
 * @brief This function tests the shift to the left of 5 spaces of input data.
 *
 */
void test__Bfx_ShiftBitLt_u8u8__5_spaces( void ) {
    //local data.
    uint8 Data = 0xB4;

    Bfx_ShiftBitLt_u8u8( &Data, 5 );
    TEST_ASSERT_EQUAL_HEX8( 0x80 , Data );//Testing.
}

/**
 * @brief This function tests the shift to the left of 3 spaces of input data.
 *
 */
void test__Bfx_ShiftBitLt_u8u8__3_spaces( void ) {
    //local data.
    uint8 Data = 0xC5;

    Bfx_ShiftBitLt_u8u8( &Data, 3 );
    TEST_ASSERT_EQUAL_HEX8( 0x28 , Data );//Testing.
}

//Test cases for Bfx_RotBitRt_u8u8

/**
 * @brief This function tests the rotate to the right of 4 spaces of input data.
 *
 */
void test__Bfx_RotBitRt_u8u8__4_spaces( void ) {
    //local data.
    uint8 Data = 0xB4;

    Bfx_RotBitRt_u8u8( &Data, 4 );
    TEST_ASSERT_EQUAL_HEX8( 0x4B , Data );//Testing.
}

/**
 * @brief This function tests the rotate to the right of 6 spaces of input data.
 *
 */
void test__Bfx_RotBitRt_u8u8__6_spaces( void ) {
    //local data.
    uint8 Data = 0xC5;

    Bfx_RotBitRt_u8u8( &Data, 6 );
    TEST_ASSERT_EQUAL_HEX8( 0x17 , Data );//Testing.
}

//Test cases for Bfx_RotBitLt_u8u8

/**
 * @brief This function tests the rotate to the left of 5 spaces of input data.
 *
 */
void test__Bfx_RotBitLt_u8u8__5_spaces( void ) {
    //local data.
    uint8 Data = 0xB4;

    Bfx_RotBitLt_u8u8( &Data, 5 );
    TEST_ASSERT_EQUAL_HEX8( 0x96 , Data );//Testing.
}

/**
 * @brief This function tests the rotate to the left of 3 spaces of input data.
 *
 */
void test__Bfx_RotBitLt_u8u8__3_spaces( void ) {
    //local data.
    uint8 Data = 0xC5;

    Bfx_RotBitLt_u8u8( &Data, 3 );
    TEST_ASSERT_EQUAL_HEX8( 0x2E , Data );//Testing.
}

//Test cases for Bfx_CopyBit_u8u8u8u8

/**
 * @brief This function tests the copy and paste from position 4 to position 6.
 *
 */
void test__Bfx_CopyBit_u8u8u8u8__4_to_6( void ) {
    //local data
    uint8 dest_data = 0xB4;

    Bfx_CopyBit_u8u8u8u8( &dest_data, 6, 0xFC, 4 );
    TEST_ASSERT_EQUAL_HEX8( 0xF4 , dest_data );//Testing.
}

/**
 * @brief This function tests the copy and paste from position 5 to position 7.
 *
 */
void test__Bfx_CopyBit_u8u8u8u8__5_to_7( void ) {
    //local data
    uint8 dest_data = 0xE4;

    Bfx_CopyBit_u8u8u8u8( &dest_data, 7, 0x12, 5 );
    TEST_ASSERT_EQUAL_HEX8( 0x64 , dest_data );//Testing.
}

//Test cases for Bfx_PutBit_u8u8u8

/**
 * @brief This function test the put of a bit with status = 1.
 *
 */
void test__Bfx_PutBit_u8u8u8__Status_1( void ) {
    //local data 
    uint8 Data = 0xB1;

    Bfx_PutBit_u8u8u8( &Data, 3, 1 );
    TEST_ASSERT_EQUAL_HEX8( 0xB9 , Data );//Testing.
}

/**
 * @brief This function test the put of a bit with status = 0.
 *
 */
void test__Bfx_PutBit_u8u8u8__Status_0( void ) {
    //local data 
    uint8 Data = 0xD5;

    Bfx_PutBit_u8u8u8( &Data, 7, 0 );
    TEST_ASSERT_EQUAL_HEX8( 0x55 , Data );//Testing.
}

//Test cases for Bfx_PutBitsMask_u8u8u8

/**
 * @brief This function tests the pattern/mask applied to input data.
 *
 */
void test__Bfx_PutBitsMask_u8u8u8__case_1( void ) {
    //local data.
    uint8 Data = 0xD2;

    Bfx_PutBitsMask_u8u8u8( &Data, 0x76, 0xF );
    TEST_ASSERT_EQUAL_HEX8( 0xD6 , Data );//Testing.   
}

/**
 * @brief This function tests the pattern/mask applied to input data.
 *
 */
void test__Bfx_PutBitsMask_u8u8u8__case_2( void ) {
    //local data.
    uint8 Data = 0xA4;

    Bfx_PutBitsMask_u8u8u8( &Data, 0xC5, 0xD2 );
    TEST_ASSERT_EQUAL_HEX8( 0xE4 , Data );//Testing.   
}

//Test cases for Bfx_PutBits_u8u8u8u8

/**
 * @brief This function tests the pattern applied to input data.
 *
 */
void test__Bfx_PutBits_u8u8u8u8__case_1( void ) {
    //local data 
    uint8 Data = 0xA5;

    Bfx_PutBits_u8u8u8u8( &Data, 3, 4, 0xF1 );
    TEST_ASSERT_EQUAL_HEX8( 0x8D , Data );//Testing. 
}

/**
 * @brief This function tests the pattern applied to input data.
 *
 */
void test__Bfx_PutBits_u8u8u8u8__case_2( void ) {
    //local data 
    uint8 Data = 0xC5;

    Bfx_PutBits_u8u8u8u8( &Data, 2, 6, 0xE4 );
    TEST_ASSERT_EQUAL_HEX8( 0x91 , Data );//Testing. 
}

//Test cases for Bfx_ShiftBitSat_u8s8_u8

/**
 * @brief This function tests the saturated shift of uint8 input data
 *
 */
void test__Bfx_ShiftBitSat_u8s8_u8__Right( void ) {
    //local data
    uint8 result = 0;

    result = Bfx_ShiftBitSat_u8s8_u8( -2, 0xF0 );
    TEST_ASSERT_EQUAL_HEX8( 0x3C , result );//Testing. 
}

/**
 * @brief This function tests the saturated shift of uint8 input data
 *
 */
void test__Bfx_ShiftBitSat_u8s8_u8__Left_no_sat( void ) {
    //local data
    uint8 result = 0;

    result = Bfx_ShiftBitSat_u8s8_u8( 3, 0x12 );
    TEST_ASSERT_EQUAL_HEX8( 0x90 , result );//Testing. 
}

/**
 * @brief This function tests the saturated shift of uint8 input data
 *
 */
void test__Bfx_ShiftBitSat_u8s8_u8__Left_sat( void ) {
    //local data
    uint8 result = 0;

    result = Bfx_ShiftBitSat_u8s8_u8( 5, 0x12 );
    TEST_ASSERT_EQUAL_HEX8( 0xFF , result );//Testing. 
}

//Test cases for Bfx_ShiftBitSat_s8s8_s8

/**
 * @brief This function tests the saturated shift of int8 input data
 *
 */
void test__Bfx_ShiftBitSat_s8s8_s8__Right( void ) {
    //local data.
    sint8 result = 0;

    result = Bfx_ShiftBitSat_s8s8_s8( -2, -20 );
    TEST_ASSERT_EQUAL_INT8( -5 , result );//Testing. 
}

/**
 * @brief This function tests the saturated shift of int8 input data
 *
 */
void test__Bfx_ShiftBitSat_s8s8_s8__Right_0( void ) {
    //local data.
    sint8 result = 0;

    result = Bfx_ShiftBitSat_s8s8_s8( -8, 20 );
    TEST_ASSERT_EQUAL_INT8( 0 , result );//Testing. 
}

/**
 * @brief This function tests the saturated shift of int8 input data
 *
 */
void test__Bfx_ShiftBitSat_s8s8_s8__Right_neg_1( void ) {
    //local data.
    sint8 result = 0;

    result = Bfx_ShiftBitSat_s8s8_s8( -8, -20 );
    TEST_ASSERT_EQUAL_INT8( -1 , result );//Testing. 
}

/**
 * @brief This function tests the saturated shift of int8 input data
 *
 */
void test__Bfx_ShiftBitSat_s8s8_s8__Left_no_sat( void ) {
    //local data.
    sint8 result = 0;

    result = Bfx_ShiftBitSat_s8s8_s8( 3, 10 );
    TEST_ASSERT_EQUAL_INT8( 80 , result );//Testing. 
}

/**
 * @brief This function tests the saturated shift of int8 input data
 *
 */
void test__Bfx_ShiftBitSat_s8s8_s8__Left_pos_sat_0( void ) {
    //local data.
    sint8 result = 0;

    result = Bfx_ShiftBitSat_s8s8_s8( 5, 5 );
    TEST_ASSERT_EQUAL_INT8( 127 , result );//Testing. 
}

/**
 * @brief This function tests the saturated shift of int8 input data
 *
 */
void test__Bfx_ShiftBitSat_s8s8_s8__Left_pos_sat_1( void ) {
    //local data.
    sint8 result = 0;

    result = Bfx_ShiftBitSat_s8s8_s8( 8, 5 );
    TEST_ASSERT_EQUAL_INT8( 127 , result );//Testing. 
}

/**
 * @brief This function tests the saturated shift of int8 input data
 *
 */
void test__Bfx_ShiftBitSat_s8s8_s8__Left_neg_sat_0( void ) {
    //local data.
    sint8 result = 0;

    result = Bfx_ShiftBitSat_s8s8_s8( 2, -64 );
    TEST_ASSERT_EQUAL_INT8( -128 , result );//Testing. 
}

/**
 * @brief This function tests the saturated shift of int8 input data
 *
 */
void test__Bfx_ShiftBitSat_s8s8_s8__Left_neg_sat_1( void ) {
    //local data.
    sint8 result = 0;

    result = Bfx_ShiftBitSat_s8s8_s8( 7, -1 );
    TEST_ASSERT_EQUAL_INT8( -128 , result );//Testing. 
}

//Test cases for Bfx_CountLeadingOnes_u8

/**
 * @brief This function tests the count of consecutive 1s from msb.
 *
 */
void test__Bfx_CountLeadingOnes_u8__case_1( void ) {
    //local data.
    uint8 count = 0;

    count = Bfx_CountLeadingOnes_u8( 0xF3 );
    TEST_ASSERT_EQUAL_UINT8( 4 , count );//Testing. 
}

/**
 * @brief This function tests the count of consecutive 1s from msb.
 *
 */
void test__Bfx_CountLeadingOnes_u8__case_2( void ) {
    //local data.
    uint8 count = 0;

    count = Bfx_CountLeadingOnes_u8( 0xC2 );
    TEST_ASSERT_EQUAL_UINT8( 2 , count );//Testing. 
}

/**
 * @brief This function tests the count of consecutive 1s from msb.
 *
 */
void test__Bfx_CountLeadingOnes_u8__case_3( void ) {
    //local data.
    uint8 count = 0;

    count = Bfx_CountLeadingOnes_u8( 0xFF );
    TEST_ASSERT_EQUAL_UINT8( 8 , count );//Testing. 
}

//Test cases for Bfx_CountLeadingSigns_s8

/**
 * @brief This function tests the count of consecutive sign bits from msb.
 *
 */
void test__Bfx_CountLeadingSigns_s8__case_1( void ) {
    //local data.
    uint8 count = 0;

    count = Bfx_CountLeadingSigns_s8( 1 );
    TEST_ASSERT_EQUAL_UINT8( 7 , count );//Testing.    
}

/**
 * @brief This function tests the count of consecutive sign bits from msb.
 *
 */
void test__Bfx_CountLeadingSigns_s8__case_2( void ) {
    //local data.
    uint8 count = 0;

    count = Bfx_CountLeadingSigns_s8( -20 );
    TEST_ASSERT_EQUAL_UINT8( 3 , count );//Testing.    
}

/**
 * @brief This function tests the count of consecutive sign bits from msb.
 *
 */
void test__Bfx_CountLeadingSigns_s8__case_3( void ) {
    //local data.
    uint8 count = 0;

    count = Bfx_CountLeadingSigns_s8( 0x00 );
    TEST_ASSERT_EQUAL_UINT8( 8 , count );//Testing.    
}

//Test cases for Bfx_CountLeadingZeros_u8

/**
 * @brief This function tests the count of consecutive 0s from msb.
 *
 */
void test__Bfx_CountLeadingZeros_u8__case_1( void ) {
    //local data.
    uint8 count = 0;

    count = Bfx_CountLeadingZeros_u8( 0x02 );
    TEST_ASSERT_EQUAL_UINT8( 6 , count );//Testing. 
}

/**
 * @brief This function tests the count of consecutive 0s from msb.
 *
 */
void test__Bfx_CountLeadingZeros_u8__case_2( void ) {
    //local data.
    uint8 count = 0;

    count = Bfx_CountLeadingZeros_u8( 0x15 );
    TEST_ASSERT_EQUAL_UINT8( 3 , count );//Testing. 
}

/**
 * @brief This function tests the count of consecutive 0s from msb.
 *
 */
void test__Bfx_CountLeadingZeros_u8__case_3( void ) {
    //local data.
    uint8 count = 0;

    count = Bfx_CountLeadingZeros_u8( 0x00 );
    TEST_ASSERT_EQUAL_UINT8( 8 , count );//Testing. 
}