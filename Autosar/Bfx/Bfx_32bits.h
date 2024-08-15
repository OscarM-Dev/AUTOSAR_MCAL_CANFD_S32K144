/**
 * @file Bfx_32bits.h
 * @brief This header contains the declaration and definition of the funcions related to 32 bit data bitwise manipulation
 * according to the AUTOSAR standard. 
 * 
 */

#ifndef BFX_32BITS_H
#define BFX_32BITS_H

//Headers.
#include "Std_Types.h"

/**
 * @brief This function sets a bit in a given position of the input data. 
 * 
 * @param[in] Data Pointer to input data.
 * @param[in] BitPn Bit position.
 * 
 * @note The operation is done by pointer dereference.
 * @note The max BitPn value is 31.
 */
static inline void Bfx_SetBit_u32u8( uint32* Data, uint8 BitPn ) {
    *Data |= ( 1 << BitPn ); 
}

/**
 * @brief This function clears a bit in a given position of the input data. 
 * 
 * @param[in] Data Pointer to input data.
 * @param[in] BitPn Bit position.
 * 
 * @note The operation is done by pointer dereference.
 * @note The max BitPn value is 31.
 */
static inline void Bfx_ClrBit_u32u8( uint32* Data, uint8 BitPn ) {
    *Data &= ~( 1 << BitPn );
}

/**
 * @brief This function returns a bit in a given position of the input data. 
 * 
 * @param[in] Data Input data.
 * @param[in] BitPn Bit position.
 * @retval Result It indicates the value of the bit of interest.
 * 
 * @note The max BitPn value is 31
 */
static inline boolean Bfx_GetBit_u32u8_u8( uint32 Data, uint8 BitPn ) {
    //local data.
    boolean Result = FALSE;
    
    Result = ( Data & ( 1 << BitPn ) ) != 0;
    return Result;
}

/**
 * @brief This function sets each bit of a group of bits from BitStartPn for the length BitLn 
 * to Status Value (0 or 1) from an input data.
 * 
 * @param[in] Data Pointer to input data.
 * @param[in] BitStartPn Start bit position.
 * @param[in] BitLn Bit field length.
 * @param[in] Status Status value.
 * 
 * @note The operation is done by pointer dereference.
 * @note The max BitStartPn value is 31.
 * @note The max BitLn value is 32.
 * @note The max BitLn + BitStartPn value is 32.
 */
static inline void Bfx_SetBits_u32u8u8u8( uint32* Data, uint8 BitStartPn, uint8 BitLn, uint8 Status ) {
    //local data.
    uint32 mask = 0;

    //Creating bit mask.
    mask = ( ( 1 << BitLn ) - 1 ) << BitStartPn;

    //Applying mask according to status value.
    if ( Status == 1 ) {
        *Data |= mask;
    }

    else {
        *Data &= ~mask;
    }
}

/**
 * @brief This function returns a group of bits from BitStartPn for the length BitLn from an input data.
 * 
 * @param[in] Data Input data.
 * @param[in] BitStartPn Start bit position.
 * @param[in] BitLn Bit field length.
 * @retval result It has the group of bits of interest.
 * 
 * @note The max BitStartPn value is 31.
 * @note The max BitLn value is 32.
 * @note The max BitLn + BitStartPn value is 32. 
 */
static inline uint32 Bfx_GetBits_u32u8u8_u32( uint32 Data, uint8 BitStartPn, uint8 BitLn ) {
    //local data.
    uint32 mask = 0;
    uint32 result = 0;

    mask = ( ( 1 << BitLn ) - 1 ) << BitStartPn;//Creating mask for obtaining bits of interest.
    result = ( Data & mask ) >> BitStartPn;//Applying mask.    
    return result;
}

/**
 * @brief This function sets (1) the bits corresponding to the mask bits (1) in the input data and the remaining bits
 * retain their original values.
 * 
 * @param[in] Data Pointer to input data.
 * @param[in] Mask Mask used to set bits.
 * 
 * @note The operation is done by pointer dereference.
 * @note The mask indicates which bits are going to be set on the input data.
 * 
 */
static inline void Bfx_SetBitMask_u32u32( uint32* Data, uint32 Mask ) {
    *Data |= Mask;//Applying mask.
}

/**
 * @brief This function clears the bits corresponding to the mask bits (1) in the input data and the remaining bits
 * retain their original values.
 * 
 * @param[in] Data Pointer to input data.
 * @param[in] Mask Mask used to clear bits.
 * 
 * @note The operation is done by pointer dereference.
 * @note The mask indicates which bits are going to be clear on the input data.
 * 
 */
static inline void Bfx_ClrBitMask_u32u32( uint32* Data, uint32 Mask ) {
    *Data &= ~Mask;//Applying mask.
}

/**
 * @brief This function indicates if all the bits set in Mask (1) are set (1) in the input data (true) or not (false).
 * 
 * @param[in] Data Input data.
 * @param[in] Mask Mask used to indicate bits of interest.
 * @retval result It indicates the result of the test.
 * 
 * @note The mask indicates which bits are going to be checked on the input data.
 * 
 */
static inline boolean Bfx_TstBitMask_u32u32_u8( uint32 Data, uint32 Mask ) {
    //local data.
    boolean result = 0;

    result = ( Data & Mask ) == Mask;//Checking if all bits of interest are set in input data.
    return result;
}

/**
 * @brief This function indicates if at least one bit of the bits set in Mask (1) 
 * is set (1) in the input data (true) or not (false).
 * 
 * @param[in] Data Input data.
 * @param[in] Mask Mask used to indicate bits of interest.
 * @retval result It indicates the result of the test.
 * 
 * @note The mask indicates which bits are going to be checked on the input data.
 * 
 */
static inline boolean Bfx_TstBitLnMask_u32u32_u8( uint32 Data, uint32 Mask ) {
    //local data.
    boolean result = 0;

    result = ( Data & Mask ) != 0;//Checking if at least 1 bit of interest is set in the input data.
    return result;
}

/**
 * @brief This function tests the number of bits set to 1. If this number is even, it shall return TRUE,
 * otherwise it returns FALSE.
 * 
 * @param[in] Data Input data.
 * @retval result It indicates the result of the test.
 * 
 */
static inline boolean Bfx_TstParityEven_u32_u8( uint32 Data ) {
    //local data.
    boolean result = 0;
    uint8 count = 0;

    //Counting the number of bits that are set to 1.
    for ( uint8 i = 0; i < 32; i++ ) {//Analizing bit by bit
        count += Data & 1;//Adds one if the LSB is one.
        Data >>= 1;//Shift right for analizing next bit.
    }
    result = ( count % 2 ) == 0; 
    return result;
}

/**
 * @brief This function inverts all the bits of the input data.
 * 
 * @param[in] Data Pointer to input data.
 * 
 * @note The operation is done by pointer dereference.
 */
static inline void Bfx_ToggleBits_u32( uint32* Data ) {
    *Data ^= 0xFFFFFFFF;//Applying mask.
}

/**
 * @brief This function inverts the bits corresponding to the mask bits (1) in the input data and the remaining bits
 * retain their original values.
 * 
 * @param[in] Data Pointer to input data.
 * @param[in] Mask Mask used to invert bits.
 * 
 * @note The operation is done by pointer dereference.
 * @note The mask indicates which bits are going to be invert on the input data.
 * 
 */
static inline void Bfx_ToggleBitMask_u32u32( uint32* Data, uint32 Mask ) {
    *Data ^= Mask;//Applying mask.
}

/**
 * @brief This function shifts to the right n spaces the input data.
 * 
 * @param[in] Data Pointer to input data.
 * @param[in] ShiftCnt Number of spaces to shift input data.
 * 
 * @note The operation is done by pointer dereference.
 * @note The max value of ShiftCnt is 31.
 * 
 */
static inline void Bfx_ShiftBitRt_u32u8( uint32* Data, uint8 ShiftCnt ) {
    *Data >>= ShiftCnt;
}

/**
 * @brief This function shifts to the left n spaces the input data.
 * 
 * @param[in] Data Pointer to input data.
 * @param[in] ShiftCnt Number of spaces to shift input data.
 * 
 * @note The operation is done by pointer dereference.
 * @note The max value of ShiftCnt is 31.
 * 
 */
static inline void Bfx_ShiftBitLt_u32u8( uint32* Data, uint8 ShiftCnt ) {
    *Data <<= ShiftCnt; 
}

/**
 * @brief This function shall rotate data to the right by ShiftCnt. The least significant bit is rotated to the
 * most significant bit location for every single bit shift cycle.
 * 
 * @param[in] Data Pointer to input data.
 * @param[in] ShiftCnt Number of spaces to shift input data.
 * 
 * @note The operation is done by pointer dereference.
 * @note The max value of ShiftCnt is 31.
 * 
 */
static inline void Bfx_RotBitRt_u32u8( uint32* Data, uint8 ShiftCnt ) {
    //local data.
    uint32 mask = 0;
    
    mask = *Data << ( 32 - ShiftCnt );//Mask for obtaining bits to rotate.
    *Data = ( *Data >> ShiftCnt ) | mask;//Rotating bits.
}

/**
 * @brief This function shall rotate data to the left by ShiftCnt. The most significant bit is rotated to the
 * least significant bit location for every single bit shift cycle..
 * 
 * @param[in] Data Pointer to input data.
 * @param[in] ShiftCnt Number of spaces to shift input data.
 * 
 * @note The operation is done by pointer dereference.
 * @note The max value of ShiftCnt is 31.
 * 
 */
static inline void Bfx_RotBitLt_u32u8( uint32* Data , uint8 ShiftCnt ) {
    //local data.
    uint32 mask = 0;
    
    mask = *Data >> ( 32 - ShiftCnt );//Mask for obtaining bits to rotate.
    *Data = ( *Data << ShiftCnt ) | mask;//Rotating bits.
}

/**
 * @brief This function copies a bit from source data from bit position and 
 * pastes it to destination data at bit position.
 * 
 * @param[in] DestinationData Pointer to destination data.
 * @param[in] DestinationPosition Destination position.
 * @param[in] SourceData Source data.
 * @param[in] SourcePosition Source position.
 * 
 * @note The operation is done by pointer dereference.
 * @note Maximum value for SourcePosition and DestinationPosition is 31.
 * 
 */
static inline void Bfx_CopyBit_u32u8u32u8( uint32* DestinationData, uint8 DestinationPosition, uint32 SourceData, uint8 SourcePosition ) {
    //local data 
    boolean bit = FALSE;
    
    bit = ( SourceData & ( 1 << SourcePosition ) ) != 0;//Obtaining bit to copy.
    *DestinationData &= ~( 1 << DestinationPosition );//Clearing destination position.
    *DestinationData |= ( bit << DestinationPosition );//Pasting bit copied.
}

/**
 * @brief This function sets or clears a bit (according to Status value) in a given position of the input data. 
 * 
 * @param[in] Data Pointer to input data.
 * @param[in] BitPn Bit position.
 * @param[in] Status Status value (TRUE or FALSE).
 * 
 * @note The operation is done by pointer dereference.
 * @note The max BitPn value is 31.
 */
static inline void Bfx_PutBit_u32u8u8( uint32* Data, uint8 BitPn, boolean Status ) {
    if ( Status == TRUE ) { //Setting bit.
        *Data |= ( 1 << BitPn ); 
    }

    else { //Clearing bit.
        *Data &= ~( 1 << BitPn );
    }
}

/**
 * @brief This function puts all bits defined in Pattern and for which the corresponding Mask bit is set
 * to 1 in the input Data.
 * 
 * @param[in] Data Pointer to input data.
 * @param[in] Pattern Pattern to be set.
 * @param[in] Mask Mask value.
 * 
 * @note The operation is done by pointer dereference.
 * @note The mask indicates which bits are going to be put from the pattern on the input data.
 */
static inline void Bfx_PutBitsMask_u32u32u32( uint32* Data, uint32 Pattern, uint32 Mask ) {
    *Data &= ~Mask;//Clearing bits to put pattern.
    *Data |= ( Pattern & Mask );//Applying pattern with mask.
}

/**
 * @brief This function puts bits as mentioned in Pattern and BitLn to the input Data 
 * from the specified bit position.
 * 
 * @param[in] Data Pointer to input data.
 * @param[in] BitStartPn Start bit position.
 * @param[in] BitLn Bit field length.
 * @param[in] Pattern Pattern to be set.
 * 
 * @note BitLn indicates how many bits of the pattern are going to be put (right to left).
 * @note The max BitStartPn value is 31.
 * @note The max BitLn value is 32.
 * @note The max BitLn + BitStartPn value is 32. 
 */
static inline void Bfx_PutBits_u32u8u8u32( uint32* Data, uint8 BitStartPn, uint8 BitLn, uint32 Pattern ) {
    //local data.
    uint32 mask;

    mask = ( ( 1 << BitLn ) - 1 ) << BitStartPn;//Obtaining mask for applying pattern.
    *Data &= ~mask;//Clearing bits to put pattern.
    *Data |= ( Pattern << BitStartPn ) & mask;//Applying pattern with bitln bits in the specified position. 
}

/**
 * @brief This function does an arithmetic shift with saturation to unsigned 32 bit data.
 * 
 * @param[in] Data Input data.
 * @param[in] ShiftCnt Number of spaces to shift input data.
 * @retval result Shifted and saturated bit pattern.
 * 
 * @note If ShiftCnt > 0 --> the input data is shifted left n spaces.
 * @note If ShiftCnt < 0 --> the input data is shifted right |n| spaces.
 * @note The range of ShiftCnt values is -32 to 31.
 * @note A logical shift is performed. In this case the result is saturated to 0xFFFFFFFF, if the leading one bit is shifted out (overflow).
 */
static inline uint32 Bfx_ShiftBitSat_u32s8_u32( sint8 ShiftCnt, uint32 Data ) {
    //local data.
    uint32 result = 0;
    uint32 overflow_mask = 0;

    //Shift left
    if ( ShiftCnt > 0 ) {
        overflow_mask = 0xFFFFFFFF << ( 32 - ShiftCnt );//Mask for detecting overflow.
        
        //Checking overflow.
        if ( ( Data & overflow_mask ) != 0 ) {//Checking if at least 1 bit to be shift is 1.
             result = 0xFFFFFFFF;//Value saturated.
        }                      
            
        else {
            result = Data << ShiftCnt;//Shift left.
        }
    }

    //Shift right
    else {
        ShiftCnt = -ShiftCnt;
        result = Data >> ShiftCnt;//Shift right.
    }
    return result;
}

/**
 * @brief This function does an arithmetic shift with saturation to signed 32 bit data.
 * 
 * @param[in] Data Input data.
 * @param[in] ShiftCnt Number of spaces to shift input data.
 * @retval result Shifted and saturated bit pattern.
 * 
 * @note If ShiftCnt > 0 --> the input data is shifted left n spaces.
 * @note If ShiftCnt < 0 --> the input data is shifted right |n| spaces.
 * @note The range of ShiftCnt values is -32 to 31.
 * @note A logical shift is performed. In this case the result is saturated to 2147483647 or -2147483648 according
 * to the kind of overflow, if the leading one bit is shifted out (overflow).
 */
static inline sint32 Bfx_ShiftBitSat_s32s8_s32( sint8 ShiftCnt, sint32 Data ) {
    //local data.
    sint32 result = 0;
    sint32 maxShiftableValue = 0;
    sint32 minShiftableValue = 0;
    
    //Shift left.
    if ( ShiftCnt > 0 ) {
        if ( ShiftCnt >= 31 ) { //A shift greater than 30 will result in an overflow
            //Checking kind of overflow.
            if ( Data > 0 ) {
                result =  2147483647;//Positive overflow.
            }    
            
            else {
                result = -2147483648;//Negative overflow.
            }
        }

        else {
            //Analizing if there would be an overflow.
            maxShiftableValue = 2147483647 >> ShiftCnt;
            minShiftableValue = ( -2147483648 >> ShiftCnt ) & ~( 0xFFFFFFFF << ShiftCnt );

            //Checking kind of overflow.
            if ( Data > maxShiftableValue ) {
                result =  2147483647; //Positive overflow.
            } 
            
            else if ( Data < minShiftableValue ) {
                result = -2147483648; //Negative overflow.
            }

            else { //Overflow is not present.
                result = Data << ShiftCnt;
            }
        }
    }

    //Shift Right.
    else {
        ShiftCnt = -ShiftCnt;
            
        //A shift of 32 will return 0 (positive) or -1 (negative).
        if ( ShiftCnt == 32 ) {
            if ( Data >= 0 ) {
                result = 0;
            }

            else {
                result = -1;
            }
        }

        else  {
            result = Data >> ShiftCnt;
        }
    }
    return result;
}

/**
 * @brief This function counts the number of consecutive ones in Data starting with the most 
 * significant bit and returns the result.
 * 
 * @param[in] Data Input data.
 * @retval count Number of consecutive 1s from MSB.
 *
 */
static inline uint8 Bfx_CountLeadingOnes_u32 ( uint32 Data ) {
    //local data.
    uint8 count = 0;
    uint32 mask = 0x80000000;//Mask for counting bits.
    
    for ( uint8 i = 0; i < 32; i++ ) {//Analizing bit by bit.
        if ( Data & mask ) {//Verifying if actual set bit in mask is also set in data -->another 1 detected.
            count++;
        } 
        
        else {//a 0 was detected.
            break;
        }

        mask >>= 1; //Shifting mask to the right.
    }
    return count;
}

/**
 * @brief This function counts the number of consecutive bits which have the same value as 
 * the sign bit in data (msb), starting with bit at position msb minus one and returns the result.
 * 
 * @param[in] Data Input data.
 * @retval count Number of consecutive bits.
 *
 */
static inline uint8 Bfx_CountLeadingSigns_s32( sint32 Data ) {
    //local data.
    uint8 count = 0;
    uint32 mask = 0x80000000;//Mask for counting bits.
    boolean signBit = FALSE;
    boolean actualBit = FALSE;

    //Determing the sign bit of data.
    if ( Data & mask ) {
        signBit = TRUE;//Negative sign bit.
    }
    
    for ( uint8 i = 0; i < 32; i++ ) {//Analizing bit by bit.
        actualBit = ( Data & mask ) != 0;//Obtaining actual bit.

        if ( actualBit == signBit ) {//same as sign bit.
            count++;
        } 
        
        else {//a diferent bit was detected.
            break;
        }

        mask >>= 1; //Shifting mask to the right.
    }
    return count;
}

/**
 * @brief This function counts the number of consecutive zeros in Data starting with the most 
 * significant bit and returns the result.
 * 
 * @param[in] Data Input data.
 * @retval count Number of consecutive 0s from MSB.
 *
 */
static inline uint8 Bfx_CountLeadingZeros_u32( uint32 Data ) {
    //local data.
    uint8 count = 0;
    uint32 mask = 0x80000000;//Mask for counting bits.
    
    for ( uint8 i = 0; i < 32; i++ ) {//Analizing bit by bit.
        if ( ( Data & mask ) == 0 ) {//a 0 was detected.
            count++;
        } 
        
        else {//a 1 was detected.
            break;
        }

        mask >>= 1; //Shifting mask to the right.
    }
    return count;
}

#endif