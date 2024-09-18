/*! \file triceCheck.c
\brief trices for tool evaluation
\author thomas.hoehenleitner [at] seerose.net
*******************************************************************************/
#include <float.h>
#define TRICE_OFF 0 // Set this value to 1 to disable trice code generation in this file object.
#include "trice.h"

// The strings behind "//exp:" are the expected result for each line (-color=none)

static int32_t FloatToInt32(float f);
static int64_t DoubleToInt64(double f);
static void exampleOfManualSerialization(void);
static void exampleOfManualJSONencoding(void);
static void dynString(int n);

// clang-format off

//! TriceCheck performs trice code sequence n. TriceCheck writes out all types of trices with fixed values for testing
//! \details One trice has one subtrace, if param size max 2 bytes. 
//! Traces with more bytes as parameter consist of several subtraces.
//! Each trice line needs to have a commented // "string" with its expected output.
//! The ID values must be in file triceCheck.c, because it is compiled first and trice update runs later.
// This function is also called from Go for tests.
void TriceCheck(int n) {
    char* s = "AAAAAAAAAAAA";
    float  x = (float)1089.6082763671875; // 0x44883377
    double y = 518.0547492508867; // 0x4080307020601050  
    static int8_t b8[24] = { 0, -1, -2, 0x33, 4, 5, 6, 7, 8, 9, 10, 11, 0, -1, -2, 0x33, 4, 5, 6, 7, 8, 9, 10, 11 };
    static int16_t b16[] = { 0, -1, -2, 0x3344 };
    static int32_t b32[] = { 0, -1, -2, 0x33445555};
    static int64_t b64[4] = { 0, -1, -2, 0x3344555566666666 };
    char* sABCDE = "abcde 12345";
    uint32_t lenABCDE = strlen(sABCDE);
    char * five = "five";
    #if TRICE_CGO == 1
    char* A = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
    #endif // #if TRICE_CGO == 1

    unsigned anchorLine = __LINE__ + 20; // The offset value here must point to the first test line containing `anchorLine`.

    switch( n ){ 
        default:
        break; case __LINE__: trice16( iD(14000), "att: line %u\n", __LINE__ );
        // Lines ending with a comment starting with `//exp:` are executed during trhe automatic Go tests.
        break; case __LINE__: TRice( iD(14001), "Hello World!\n" );                                              //exp: time: 842,150_450default: Hello World!		
        // normal use cases
        break; case __LINE__: TRice( iD(14002), "info:This is a message without values and a 32-bit stamp.\n" ); //exp: time: 842,150_450default: info:This is a message without values and a 32-bit stamp.
        break; case __LINE__: Trice( iD(14003), "info:This is a message without values and a 16-bit stamp.\n" ); //exp: time:       5_654default: info:This is a message without values and a 16-bit stamp.
        break; case __LINE__: trice( iD(14004), "info:This is a message without values and without stamp.\n"  ); //exp: time:            default: info:This is a message without values and without stamp.
        break; case __LINE__: for( int i = 126; i < 130; i++ ){ dynString(i); }








        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:01
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:012
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:01234
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:012345
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:01234567
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:012345678
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789a
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789ab
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789abc
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789abcd
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789abcde
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789abcdef
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789abcdefg
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789abcdefgh
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789abcdefghi
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789abcdefghij
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789abcdefghijk
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789abcdefghijkl
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789abcdefghijklm
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789abcdefghijklmn
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789abcdefghijklmno
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789abcdefghijklmnop
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789abcdefghijklmnopq
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789abcdefghijklmnopqr
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789abcdefghijklmnopqrs
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789abcdefghijklmnopqrst
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789abcdefghijklmnopqrstu
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789abcdefghijklmnopqrstuv
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789abcdefghijklmnopqrstuvw
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789abcdefghijklmnopqrstuvwx
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789abcdefghijklmnopqrstuvwxy
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789abcdefghijklmnopqrstuvwxyz
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789abcdefghijklmnopqrstuvwxyzA
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789abcdefghijklmnopqrstuvwxyzAB
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789abcdefghijklmnopqrstuvwxyzABC
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789abcdefghijklmnopqrstuvwxyzABCD
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789abcdefghijklmnopqrstuvwxyzABCDE
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789abcdefghijklmnopqrstuvwxyzABCDEF
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789abcdefghijklmnopqrstuvwxyzABCDEFG
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789abcdefghijklmnopqrstuvwxyzABCDEFGH
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHI
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJ
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJK
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKL
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLM
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMN
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNO
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOP
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQ
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQR
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRS
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRST
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTU
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUV
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVW
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWX
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXY
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ.
        break; case __LINE__: dynString(__LINE__ - anchorLine); //exp: time:            default: wr:0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ.,

        break; case __LINE__: trice  ( iD(14005), "sig:trice16 with 1 to 12 pointer\n" );

        break; case __LINE__: trice16( iD(14006), "rd:trice16 %p\n", -1 );                                                                                            //exp: time:            default: rd:trice16 ffff      
        break; case __LINE__: trice16( iD(14007), "rd:trice16 %p, %p\n", -1, -2 );                                                                                    //exp: time:            default: rd:trice16 ffff, fffe      
        break; case __LINE__: trice16( iD(14008), "rd:trice16 %p, %p, %p\n", -1, -2, -3 );                                                                            //exp: time:            default: rd:trice16 ffff, fffe, fffd          
        break; case __LINE__: trice16( iD(14009), "rd:trice16 %p, %p, %p, %p\n", -1, -2, -3, -4 );                                                                    //exp: time:            default: rd:trice16 ffff, fffe, fffd, fffc            
        break; case __LINE__: trice16( iD(14010), "rd:trice16 %p, %p, %p, %p, %p\n", -1, -2, -3, -4, -5 );                                                            //exp: time:            default: rd:trice16 ffff, fffe, fffd, fffc, fffb       
        break; case __LINE__: trice16( iD(14011), "rd:trice16 %p, %p, %p, %p, %p, %p\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time:            default: rd:trice16 ffff, fffe, fffd, fffc, fffb, fffa              
        break; case __LINE__: trice16( iD(14012), "rd:trice16 %p, %p, %p, %p, %p, %p, %p\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time:            default: rd:trice16 ffff, fffe, fffd, fffc, fffb, fffa, fff9           
        break; case __LINE__: trice16( iD(14013), "rd:trice16 %p, %p, %p, %p, %p, %p, %p, %p\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time:            default: rd:trice16 ffff, fffe, fffd, fffc, fffb, fffa, fff9, fff8               
        break; case __LINE__: trice16( iD(14014), "rd:trice16 %p, %p, %p, %p, %p, %p, %p, %p, %p\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time:            default: rd:trice16 ffff, fffe, fffd, fffc, fffb, fffa, fff9, fff8, fff7              
        break; case __LINE__: trice16( iD(14015), "rd:trice16 %p, %p, %p, %p, %p, %p, %p, %p, %p, %p\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time:            default: rd:trice16 ffff, fffe, fffd, fffc, fffb, fffa, fff9, fff8, fff7, fff6                
        break; case __LINE__: trice16( iD(14016), "rd:trice16 %p, %p, %p, %p, %p, %p, %p, %p, %p, %p, %p\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time:            default: rd:trice16 ffff, fffe, fffd, fffc, fffb, fffa, fff9, fff8, fff7, fff6, fff5              
        break; case __LINE__: trice16( iD(14017), "rd:trice16 %p, %p, %p, %p, %p, %p, %p, %p, %p, %p, %p, %p\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time:            default: rd:trice16 ffff, fffe, fffd, fffc, fffb, fffa, fff9, fff8, fff7, fff6, fff5, fff4

        break; case __LINE__: trice8 ( iD(14018), "rd:trice8  %p, %p, %p, %p, %p, %p, %p, %p, %p, %p, %p, %p\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 );  //exp: time:            default: rd:trice8  ff, fe, fd, fc, fb, fa, f9, f8, f7, f6, f5, f4
        break; case __LINE__: trice32( iD(14019), "rd:trice32 %p, %p, %p, %p, %p, %p, %p, %p, %p, %p, %p, %p\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 );  //exp: time:            default: rd:trice32 ffffffff, fffffffe, fffffffd, fffffffc, fffffffb, fffffffa, fffffff9, fffffff8, fffffff7, fffffff6, fffffff5, fffffff4

        break; case __LINE__: trice  ( iD(14020), "sig:trice16 with 1 to 12 hex\n" );

        break; case __LINE__: trice16( iD(14021), "rd:trice16 %X\n", -1 );                                                                                             //exp: time:            default: rd:trice16 FFFF                 
        break; case __LINE__: trice16( iD(14022), "rd:trice16 %X, %X\n", -1, -2 );                                                                                     //exp: time:            default: rd:trice16 FFFF, FFFE             
        break; case __LINE__: trice16( iD(14023), "rd:trice16 %X, %X, %X\n", -1, -2, -3 );                                                                             //exp: time:            default: rd:trice16 FFFF, FFFE, FFFD            
        break; case __LINE__: trice16( iD(14024), "rd:trice16 %X, %X, %X, %X\n", -1, -2, -3, -4 );                                                                     //exp: time:            default: rd:trice16 FFFF, FFFE, FFFD, FFFC                  
        break; case __LINE__: trice16( iD(14025), "rd:trice16 %X, %X, %X, %X, %X\n", -1, -2, -3, -4, -5 );                                                             //exp: time:            default: rd:trice16 FFFF, FFFE, FFFD, FFFC, FFFB              
        break; case __LINE__: trice16( iD(14026), "rd:trice16 %X, %X, %X, %X, %X, %X\n", -1, -2, -3, -4, -5, -6 );                                                     //exp: time:            default: rd:trice16 FFFF, FFFE, FFFD, FFFC, FFFB, FFFA                     
        break; case __LINE__: trice16( iD(14027), "rd:trice16 %X, %X, %X, %X, %X, %X, %X\n", -1, -2, -3, -4, -5, -6, -7);                                              //exp: time:            default: rd:trice16 FFFF, FFFE, FFFD, FFFC, FFFB, FFFA, FFF9                
        break; case __LINE__: trice16( iD(14028), "rd:trice16 %X, %X, %X, %X, %X, %X, %X, %X\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                     //exp: time:            default: rd:trice16 FFFF, FFFE, FFFD, FFFC, FFFB, FFFA, FFF9, FFF8             
        break; case __LINE__: trice16( iD(14029), "rd:trice16 %X, %X, %X, %X, %X, %X, %X, %X, %X\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                             //exp: time:            default: rd:trice16 FFFF, FFFE, FFFD, FFFC, FFFB, FFFA, FFF9, FFF8, FFF7          
        break; case __LINE__: trice16( iD(14030), "rd:trice16 %X, %X, %X, %X, %X, %X, %X, %X, %X, %X\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                     //exp: time:            default: rd:trice16 FFFF, FFFE, FFFD, FFFC, FFFB, FFFA, FFF9, FFF8, FFF7, FFF6          
        break; case __LINE__: trice16( iD(14031), "rd:trice16 %X, %X, %X, %X, %X, %X, %X, %X, %X, %X, %X\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );           //exp: time:            default: rd:trice16 FFFF, FFFE, FFFD, FFFC, FFFB, FFFA, FFF9, FFF8, FFF7, FFF6, FFF5             
        break; case __LINE__: trice16( iD(14032), "rd:trice16 %X, %X, %X, %X, %X, %X, %X, %X, %X, %X, %X, %X\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 );  //exp: time:            default: rd:trice16 FFFF, FFFE, FFFD, FFFC, FFFB, FFFA, FFF9, FFF8, FFF7, FFF6, FFF5, FFF4

        break; case __LINE__: trice8 ( iD(14033), "rd:trice8  %X, %X, %X, %X, %X, %X, %X, %X, %X, %X, %X, %X\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 );  //exp: time:            default: rd:trice8  FF, FE, FD, FC, FB, FA, F9, F8, F7, F6, F5, F4
        break; case __LINE__: trice32( iD(14034), "rd:trice32 %X, %X, %X, %X, %X, %X, %X, %X, %X, %X, %X, %X\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 );  //exp: time:            default: rd:trice32 FFFFFFFF, FFFFFFFE, FFFFFFFD, FFFFFFFC, FFFFFFFB, FFFFFFFA, FFFFFFF9, FFFFFFF8, FFFFFFF7, FFFFFFF6, FFFFFFF5, FFFFFFF4

        break; case __LINE__: trice16( iD(14035), "att: line %u\n", __LINE__ );
    
        break; case __LINE__: 
        #if TRICE_DEFERRED_XTEA_ENCRYPT == 1 || TRICE_DIRECT_XTEA_ENCRYPT == 1
                trice( iD(14036), "--------------------------------------------------\n" );
                {
                    uint32_t by[8] = {1,2,3,4,5,6};
                    int count = (sizeof(by) + 7) & ~7; // only multiple of 8 encryptable
                    trice32( iD(14037), "msg: message = %08x %08x %08x %08x %08x %08x\n", by[0], by[1], by[2], by[3], by[4], by[5] );
                    trice32( iD(14038), "tim: pre TriceEncryption SysTick=%d\n", SYSTICKVAL );
                    XTEAEncrypt(by, count>>2);
                    trice32( iD(14039), "tim: post TriceEncryption SysTick=%d\n", SYSTICKVAL );
                    trice32( iD(14040), "att: TriceEncrypted =  %08x %08x %08x %08x %08x %08x\n", by[0], by[1], by[2], by[3], by[4], by[5] ); 
                    #if XTEA_DECRYPT == 1
                        trice16_1( iD(14041), "tim: pre TriceDecryption SysTick=%d\n", SYSTICKVAL );
                        XTEADecrypt(by, count>>2);
                        trice16_1( iD(14042), "tim: post TriceDecryption SysTick=%d\n", SYSTICKVAL );
                    #endif
                    trice32( iD(14043), "msg: messge = %08x %08x %08x %08x %08x %08x\n", by[0], by[1], by[2], by[3], by[4], by[5] );
                }
                trice( iD(14044), "--------------------------------------------------\n" );
        #endif

        break; case __LINE__: trice16( iD(14045), "att: line %u\n", __LINE__ );

        break; case __LINE__: trice( iD(14046), "dbg:Hi!\n" );                       //exp: time:            default: dbg:Hi!    
        break; case __LINE__: trice( iD(14047), "dbg:	Hi!\n" );                    //exp: time:            default: dbg:	Hi!

        break; case __LINE__: trice( iD(14048), "sig:Some time measurements\n" );
        break; case __LINE__: trice( iD(14049), "isr:trice isr message, SysTick is %6d\n", SYSTICKVAL);                //exp: time:            default: isr:trice isr message, SysTick is      0 
        break; case __LINE__: trice( iD(14050), "isr:trice isr message, SysTick is %6d\n", SYSTICKVAL);                //exp: time:            default: isr:trice isr message, SysTick is      0 
        break; case __LINE__: trice( iD(14051), "isr:trice isr message, SysTick is %6d\n", SYSTICKVAL);                //exp: time:            default: isr:trice isr message, SysTick is      0 
        break; case __LINE__: trice( iD(14052), "isr:trice isr message, SysTick is %6d\n", SYSTICKVAL);                //exp: time:            default: isr:trice isr message, SysTick is      0

        break; case __LINE__: trice_1( iD(14053), "isr:trice_1 isr message, SysTick is %6d\n", SYSTICKVAL);            //exp: time:            default: isr:trice_1 isr message, SysTick is      0 
        break; case __LINE__: trice_1( iD(14054), "isr:trice_1 isr message, SysTick is %6d\n", SYSTICKVAL);            //exp: time:            default: isr:trice_1 isr message, SysTick is      0 
        break; case __LINE__: trice_1( iD(14055), "isr:trice_1 isr message, SysTick is %6d\n", SYSTICKVAL);            //exp: time:            default: isr:trice_1 isr message, SysTick is      0 
        break; case __LINE__: trice_1( iD(14056), "isr:trice_1 isr message, SysTick is %6d\n", SYSTICKVAL);            //exp: time:            default: isr:trice_1 isr message, SysTick is      0

        break; case __LINE__: TRICE16_1( id(14057), "isr:TRICE16_1 isr message, SysTick is %6d\n", SYSTICKVAL);        //exp: time:            default: isr:TRICE16_1 isr message, SysTick is      0 
        break; case __LINE__: TRICE16_1( id(14058), "isr:TRICE16_1 isr message, SysTick is %6d\n", SYSTICKVAL);        //exp: time:            default: isr:TRICE16_1 isr message, SysTick is      0 
        break; case __LINE__: TRICE16_1( id(14059), "isr:TRICE16_1 isr message, SysTick is %6d\n", SYSTICKVAL);        //exp: time:            default: isr:TRICE16_1 isr message, SysTick is      0 
        break; case __LINE__: TRICE16_1( id(14060), "isr:TRICE16_1 isr message, SysTick is %6d\n", SYSTICKVAL);        //exp: time:            default: isr:TRICE16_1 isr message, SysTick is      0 

        break; case __LINE__: TRICE_1( id(14061), "isr:TRICE_1 isr message, SysTick is %6d\n", SYSTICKVAL);            //exp: time:            default: isr:TRICE_1 isr message, SysTick is      0 
        break; case __LINE__: TRICE_1( id(14062), "isr:TRICE_1 isr message, SysTick is %6d\n", SYSTICKVAL);            //exp: time:            default: isr:TRICE_1 isr message, SysTick is      0 
        break; case __LINE__: TRICE_1( id(14063), "isr:TRICE_1 isr message, SysTick is %6d\n", SYSTICKVAL);            //exp: time:            default: isr:TRICE_1 isr message, SysTick is      0 
        break; case __LINE__: TRICE_1( id(14064), "isr:TRICE_1 isr message, SysTick is %6d\n", SYSTICKVAL);            //exp: time:            default: isr:TRICE_1 isr message, SysTick is      0 

        break; case __LINE__: TRICE( id(14065), "isr:TRICE isr message, SysTick is %6d\n", SYSTICKVAL);                //exp: time:            default: isr:TRICE isr message, SysTick is      0 
        break; case __LINE__: TRICE( id(14066), "isr:TRICE isr message, SysTick is %6d\n", SYSTICKVAL);                //exp: time:            default: isr:TRICE isr message, SysTick is      0 
        break; case __LINE__: TRICE( id(14067), "isr:TRICE isr message, SysTick is %6d\n", SYSTICKVAL);                //exp: time:            default: isr:TRICE isr message, SysTick is      0 
        break; case __LINE__: TRICE( id(14068), "isr:TRICE isr message, SysTick is %6d\n", SYSTICKVAL);                //exp: time:            default: isr:TRICE isr message, SysTick is      0 

        break; case __LINE__: trice( iD(14069), "tim:trice START time message\n");                                     //exp: time:            default: tim:trice START time message
        break; case __LINE__: trice( iD(14070), "tim:trice STOP time message\n");                                      //exp: time:            default: tim:trice STOP time message
        break; case __LINE__: trice( iD(14071), "tim:trice START time message\n");                                     //exp: time:            default: tim:trice START time message
        break; case __LINE__: trice( iD(14072), "tim:trice STOP time message\n");                                      //exp: time:            default: tim:trice STOP time message 
        break; case __LINE__: trice( iD(14073), "tim:trice START time message\n");                                     //exp: time:            default: tim:trice START time message
        break; case __LINE__: trice64( iD(14074), "rd:trice64 %d, %d\n", 1, 2 );                                       //exp: time:            default: rd:trice64 1, 2   
        break; case __LINE__: trice( iD(14075), "tim:trice STOP time message\n");                                      //exp: time:            default: tim:trice STOP time message
        
        break; case __LINE__: TRICE( id(14076), "tim:TRICE START time message\n");                                     //exp: time:            default: tim:TRICE START time message
        break; case __LINE__: TRICE( id(14077), "tim:TRICE STOP time message\n");                                      //exp: time:            default: tim:TRICE STOP time message 
        break; case __LINE__: TRICE( id(14078), "tim:TRICE START time message\n");                                     //exp: time:            default: tim:TRICE START time message
        break; case __LINE__: TRICE( id(14079), "tim:TRICE STOP time message\n");                                      //exp: time:            default: tim:TRICE STOP time message 
        break; case __LINE__: TRICE( id(14080), "tim:TRICE START time message\n");                                     //exp: time:            default: tim:TRICE START time message
        break; case __LINE__: TRICE64( id(14081), "rd:TRICE64 %d, %d\n", 1, 2 );                                       //exp: time:            default: rd:TRICE64 1, 2    
        break; case __LINE__: TRICE( id(14082), "tim:TRICE STOP time message\n");                                      //exp: time:            default: tim:TRICE STOP time message 

        break; case __LINE__: trice  ( iD(14083), "tim:trice --------------------------------------------------\n");   //exp: time:            default: tim:trice --------------------------------------------------
        break; case __LINE__: trice  ( iD(14084), "tim:trice --------------------------------------------------\n");   //exp: time:            default: tim:trice --------------------------------------------------
        break; case __LINE__: trice64( iD(14085), "rd:trice64 %d, %d\n", 1, 2 );                                       //exp: time:            default: rd:trice64 1, 2
        break; case __LINE__: trice  ( iD(14086), "tim:trice --------------------------------------------------\n");   //exp: time:            default: tim:trice --------------------------------------------------
        break; case __LINE__: trice  ( iD(14087), "tim:trice --------------------------------------------------\n");   //exp: time:            default: tim:trice --------------------------------------------------
        break; case __LINE__: trice64( iD(14088), "rd:trice64 %d, %d\n", 1, 2 );                                       //exp: time:            default: rd:trice64 1, 2
        break; case __LINE__: trice32_1( iD(14089), "rd:trice32_1 %d\n", -1 );                                         //exp: time:            default: rd:trice32_1 -1
        break; case __LINE__: trice64_1( iD(14090), "rd:trice64_1 %d\n", -2 );                                         //exp: time:            default: rd:trice64_1 -2
        break; case __LINE__: trice32_2( iD(14091), "rd:trice32_2 %d,%d\n", -1, 2 );                                   //exp: time:            default: rd:trice32_2 -1,2
        break; case __LINE__: trice64_2( iD(14092), "rd:trice64_2 %d,%d\n", -1, 2 );                                   //exp: time:            default: rd:trice64_2 -1,2

        // special use cases
        break; case __LINE__: TRice64( iD(14093), "info:12 64-bit values %d, %u, %x, %X, %t, %e, %f, %g, %E, %F, %G, 0xb%08b and a 32-bit stamp.\n", -3, -4, -5, -6, 0, aDouble(-7.123456789), aDouble(-7.123456789), aDouble(-7.123456789), aDouble(-7.123456789), aDouble(-7.123456789), aDouble(-7.123456789), -8 ); //exp: time: 842,150_450default: info:12 64-bit values -3, 18446744073709551612, fffffffffffffffb, FFFFFFFFFFFFFFFA, false, -7.123457e+00, -7.123457, -7.123456789, -7.123457E+00, -7.123457, -7.123456789, 0xb1111111111111111111111111111111111111111111111111111111111111000 and a 32-bit stamp.
        break; case __LINE__: Trice64( iD(14094), "info:12 64-bit values %d, %u, %x, %X, %t, %e, %f, %g, %E, %F, %G, 0xb%08b and a 16-bit stamp.\n", -3, -4, -5, -6, 0, aDouble(-7.123456789), aDouble(-7.123456789), aDouble(-7.123456789), aDouble(-7.123456789), aDouble(-7.123456789), aDouble(-7.123456789), -8 ); //exp: time:       5_654default: info:12 64-bit values -3, 18446744073709551612, fffffffffffffffb, FFFFFFFFFFFFFFFA, false, -7.123457e+00, -7.123457, -7.123456789, -7.123457E+00, -7.123457, -7.123456789, 0xb1111111111111111111111111111111111111111111111111111111111111000 and a 16-bit stamp.
        break; case __LINE__: trice64( iD(14095), "info:12 64-bit values %d, %u, %x, %X, %t, %e, %f, %g, %E, %F, %G, 0xb%08b and without stamp.\n" , -3, -4, -5, -6, 0, aDouble(-7.123456789), aDouble(-7.123456789), aDouble(-7.123456789), aDouble(-7.123456789), aDouble(-7.123456789), aDouble(-7.123456789), -8 ); //exp: time:            default: info:12 64-bit values -3, 18446744073709551612, fffffffffffffffb, FFFFFFFFFFFFFFFA, false, -7.123457e+00, -7.123457, -7.123456789, -7.123457E+00, -7.123457, -7.123456789, 0xb1111111111111111111111111111111111111111111111111111111111111000 and without stamp.
        break; case __LINE__: TRice32( iD(14096), "info:12 32-bit values %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d and a 32-bit stamp.\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 );                //exp: time: 842,150_450default: info:12 32-bit values -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 and a 32-bit stamp.
        break; case __LINE__: Trice32( iD(14097), "info:12 32-bit values %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d and a 16-bit stamp.\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 );                //exp: time:       5_654default: info:12 32-bit values -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 and a 16-bit stamp.
        break; case __LINE__: trice32( iD(14098), "info:12 32-bit values %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d and without stamp.\n" , -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 );                //exp: time:            default: info:12 32-bit values -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 and without stamp.
        break; case __LINE__: TRice16( iD(14099), "info:12 16-bit values %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d and a 32-bit stamp.\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 );                //exp: time: 842,150_450default: info:12 16-bit values -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 and a 32-bit stamp.
        break; case __LINE__: Trice16( iD(14100), "info:12 16-bit values %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d and a 16-bit stamp.\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 );                //exp: time:       5_654default: info:12 16-bit values -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 and a 16-bit stamp.
        break; case __LINE__: trice16( iD(14101), "info:12 16-bit values %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d and without stamp.\n" , -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 );                //exp: time:            default: info:12 16-bit values -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 and without stamp.
        break; case __LINE__: TRice8 ( iD(14102), "info:12  8-bit values %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d and a 32-bit stamp.\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 );                //exp: time: 842,150_450default: info:12  8-bit values -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 and a 32-bit stamp.
        break; case __LINE__: Trice8 ( iD(14103), "info:12  8-bit values %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d and a 16-bit stamp.\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 );                //exp: time:       5_654default: info:12  8-bit values -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 and a 16-bit stamp.
        break; case __LINE__: trice8 ( iD(14104), "info:12  8-bit values %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d and without stamp.\n" , -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 );                //exp: time:            default: info:12  8-bit values -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 and without stamp.

        break; case __LINE__: trice16( iD(14105), "att: line %u\n", __LINE__ );

        break; case __LINE__: TRice16( iD(14106), "att: 0x8888 == %04xh\n", 0x8888 ); //exp: time: 842,150_450default: att: 0x8888 == 8888h
        break; case __LINE__: Trice16( iD(14107), "att: 0x8888 == %04xh\n", 0x8888 ); //exp: time:       5_654default: att: 0x8888 == 8888h
        break; case __LINE__: trice16( iD(14108), "att: 0x8888 == %04xh\n", 0x8888 ); //exp: time:            default: att: 0x8888 == 8888h


        break; case __LINE__: trice16( iD(14109), "att: line %u\n", __LINE__ );

        break; case __LINE__: trice8   ( iD(14110), "value=%x\n", 0x55 );             //exp: time:            default: value=55
        break; case __LINE__: trice8   ( iD(14111), "value=%x\n", 0x88 );             //exp: time:            default: value=88

        break; case __LINE__: trice( iD(14112), "att:mixed int & float & double & bits\n" );
        break; case __LINE__: TRice32( iD(14113), "rd:TRice32 int %d, float %f (%%f), %08x, %032b\n",       FloatToInt32(x),   aFloat(x),   aFloat(x),   aFloat(x) ); //exp: time: 842,150_450default: rd:TRice32 int 1089, float 1089.608276 (%f), 44883377, 01000100100010000011001101110111                                         
        break; case __LINE__: TRice32( iD(14114), "rd:TRice32 int %d, float %f (%%f), %08x, %032b\n",          (int32_t)(x),   aFloat(x),   aFloat(x),   aFloat(x) ); //exp: time: 842,150_450default: rd:TRice32 int 1089, float 1089.608276 (%f), 44883377, 01000100100010000011001101110111                                         
        break; case __LINE__: TRice32( iD(14115), "rd:TRice32 int %x, float %f (%%f), %08x, %032b\n",            0x44883377,   aFloat(x),   aFloat(x),   aFloat(x) ); //exp: time: 842,150_450default: rd:TRice32 int 44883377, float 1089.608276 (%f), 44883377, 01000100100010000011001101110111                                         
        break; case __LINE__: TRice32( iD(14116), "rd:TRice32 int %d, float %f (%%f), %08x, %032b\n",                     x,   aFloat(x),   aFloat(x),   aFloat(x) ); //exp: time: 842,150_450default: rd:TRice32 int 1089, float 1089.608276 (%f), 44883377, 01000100100010000011001101110111                                         
        break; case __LINE__: TRice32( iD(14117), "rd:TRice32 int %d, float %f (%%f), %08x, %032b\n",      FloatToInt32(-x),  aFloat(-x),  aFloat(-x),  aFloat(-x) ); //exp: time: 842,150_450default: rd:TRice32 int -1089, float -1089.608276 (%f), c4883377, 11000100100010000011001101110111                                       
        break; case __LINE__: TRice32( iD(14118), "rd:TRice32 int %d, float %f (%%f), %08x, %032b\n",         (int32_t)(-x),  aFloat(-x),  aFloat(-x),  aFloat(-x) ); //exp: time: 842,150_450default: rd:TRice32 int -1089, float -1089.608276 (%f), c4883377, 11000100100010000011001101110111                                       
        break; case __LINE__: TRice32( iD(14119), "rd:TRice32 int %X, float %f (%%f), %08x, %032b\n",           -0x44883377,  aFloat(-x),  aFloat(-x),  aFloat(-x) ); //exp: time: 842,150_450default: rd:TRice32 int BB77CC89, float -1089.608276 (%f), c4883377, 11000100100010000011001101110111                                        
        break; case __LINE__: TRice64( iD(14120), "rd:TRice64 int %d, double %f (%%f), %016x, %064b\n",    DoubleToInt64(y),  aDouble(y),  aDouble(y),  aDouble(y) ); //exp: time: 842,150_450default: rd:TRice64 int 518, double 518.054749 (%f), 4080307020601050, 0100000010000000001100000111000000100000011000000001000001010000   
        break; case __LINE__: TRice64( iD(14121), "rd:TRice64 int %d, double %f (%%f), %016x, %064b\n",        (int64_t)(y),  aDouble(y),  aDouble(y),  aDouble(y) ); //exp: time: 842,150_450default: rd:TRice64 int 518, double 518.054749 (%f), 4080307020601050, 0100000010000000001100000111000000100000011000000001000001010000   
        break; case __LINE__: TRice64( iD(14122), "rd:TRice64 int %d, double %f (%%f), %016x, %064b\n",                   y,  aDouble(y),  aDouble(y),  aDouble(y) ); //exp: time: 842,150_450default: rd:TRice64 int 518, double 518.054749 (%f), 4080307020601050, 0100000010000000001100000111000000100000011000000001000001010000   
        break; case __LINE__: TRice64( iD(14123), "rd:TRice64 int %d, double %f (%%f), %016x, %064b\n",   DoubleToInt64(-y), aDouble(-y), aDouble(-y), aDouble(-y) ); //exp: time: 842,150_450default: rd:TRice64 int -518, double -518.054749 (%f), c080307020601050, 1100000010000000001100000111000000100000011000000001000001010000
        break; case __LINE__: TRice64( iD(14124), "rd:TRice64 int %d, double %f (%%f), %016x, %064b\n",       (int64_t)(-y), aDouble(-y), aDouble(-y), aDouble(-y) ); //exp: time: 842,150_450default: rd:TRice64 int -518, double -518.054749 (%f), c080307020601050, 1100000010000000001100000111000000100000011000000001000001010000
        break; case __LINE__: TRice64( iD(14125), "rd:TRice64 int %X, double %f (%%f), %016x, %064b\n", -0x4080307020601050, aDouble(-y), aDouble(-y), aDouble(-y) ); //exp: time: 842,150_450default: rd:TRice64 int BF7FCF8FDF9FEFB0, double -518.054749 (%f), c080307020601050, 1100000010000000001100000111000000100000011000000001000001010000 

        break; case __LINE__: trice16( iD(14126), "att: line %u\n", __LINE__ );

        break; case __LINE__: triceS( iD(14127), "msg:With triceS:%s\n", sABCDE );               //exp: time:            default: msg:With triceS:abcde 12345
        break; case __LINE__: triceN( iD(14128), "sig:With triceN:%s\n", sABCDE, lenABCDE );     //exp: time:            default: sig:With triceN:abcde 12345
        break; case __LINE__: TriceS( iD(14129), "msg:With TriceS:%s\n", sABCDE );               //exp: time:       5_654default: msg:With TriceS:abcde 12345
        break; case __LINE__: TriceN( iD(14130), "sig:With TriceN:%s\n", sABCDE, lenABCDE );     //exp: time:       5_654default: sig:With TriceN:abcde 12345
        break; case __LINE__: TRiceS( iD(14131), "msg:With TRiceS:%s\n", sABCDE );               //exp: time: 842,150_450default: msg:With TRiceS:abcde 12345
        break; case __LINE__: TRiceN( iD(14132), "sig:With TRiceN:%s\n", sABCDE, lenABCDE );     //exp: time: 842,150_450default: sig:With TRiceN:abcde 12345

        break; case __LINE__: TRICE_S( id(14133), "msg:With TRICE_S:%s\n", sABCDE );             //exp: time:            default: msg:With TRICE_S:abcde 12345
        break; case __LINE__: TRICE_N( id(14134), "sig:With TRICE_N:%s\n", sABCDE, lenABCDE );   //exp: time:            default: sig:With TRICE_N:abcde 12345
        break; case __LINE__: TRICE_S( Id(14135), "msg:With TRICE_S:%s\n", sABCDE );             //exp: time:       5_654default: msg:With TRICE_S:abcde 12345
        break; case __LINE__: TRICE_N( Id(14136), "sig:With TRICE_N:%s\n", sABCDE, lenABCDE );   //exp: time:       5_654default: sig:With TRICE_N:abcde 12345
        break; case __LINE__: TRICE_S( ID(14137), "msg:With TRICE_S:%s\n", sABCDE );             //exp: time: 842,150_450default: msg:With TRICE_S:abcde 12345
        break; case __LINE__: TRICE_N( ID(14138), "sig:With TRICE_N:%s\n", sABCDE, lenABCDE );   //exp: time: 842,150_450default: sig:With TRICE_N:abcde 12345

        break; case __LINE__: TRICE8_B( ID(14139), "  %02x", sABCDE, lenABCDE );                 //exp: time: 842,150_450default:   61  62  63  64  65  20  31  32  33  34  35
        break; case __LINE__: trice( iD(14140), "\n" );
        break; case __LINE__: TRICE8_B( ID(14141), "BUF: %02x\n", sABCDE, lenABCDE );            //exp: time: 842,150_450default: BUF: 61 62 63 64 65 20 31 32 33 34 35
        break; case __LINE__: TRICE8_B( ID(14142), "%4d", sABCDE, lenABCDE );                    //exp: time: 842,150_450default:   97  98  99 100 101  32  49  50  51  52  53
        break; case __LINE__: trice( iD(14143), "\n" );
        break; case __LINE__: TRICE8_B( ID(14144), "  %02x", b8, sizeof(b8)/sizeof(int8_t) );    //exp: time: 842,150_450default:   00  ff  fe  33  04  05  06  07  08  09  0a  0b  00  ff  fe  33  04  05  06  07  08  09  0a  0b
        break; case __LINE__: trice( iD(14145), "\n" );

        break; case __LINE__: TRice8B( iD(14146), " %02x", b8,  sizeof(b8) /sizeof(int8_t) );    //exp: time: 842,150_450default:  00 ff fe 33 04 05 06 07 08 09 0a 0b 00 ff fe 33 04 05 06 07 08 09 0a 0b
        break; case __LINE__: trice( iD(14147), "\n" );
        break; case __LINE__: Trice8B( iD(14148), " %02x", b8,  sizeof(b8) /sizeof(int8_t) );    //exp: time:       5_654default:  00 ff fe 33 04 05 06 07 08 09 0a 0b 00 ff fe 33 04 05 06 07 08 09 0a 0b
        break; case __LINE__: trice( iD(14149), "\n" );
        break; case __LINE__: trice8B( iD(14150), " %02x", b8,  sizeof(b8) /sizeof(int8_t) );    //exp: time:            default:  00 ff fe 33 04 05 06 07 08 09 0a 0b 00 ff fe 33 04 05 06 07 08 09 0a 0b
        break; case __LINE__: trice( iD(14151), "\n" );

        break; case __LINE__: trice8B( iD(14152), "att: %02x\n", b8,  sizeof(b8) /sizeof(int8_t) );  //exp: time:            default: att: 00 ff fe 33 04 05 06 07 08 09 0a 0b 00 ff fe 33 04 05 06 07 08 09 0a 0b
        break; case __LINE__: trice8B( iD(14153), "rd: %02x", b8,  sizeof(b8) /sizeof(int8_t) );    //exp: time:            default: rd: 00 ff fe 33 04 05 06 07 08 09 0a 0b 00 ff fe 33 04 05 06 07 08 09 0a 0b
        break; case __LINE__: trice( iD(14154), "\n" );
        break; case __LINE__: trice8B( iD(14155), " %02x\n", b8,  sizeof(b8) /sizeof(int8_t) );      //exp: time:            default:  00 ff fe 33 04 05 06 07 08 09 0a 0b 00 ff fe 33 04 05 06 07 08 09 0a 0b

        break; case __LINE__: TRICE16_B( ID(14156), "  %04x", b16, sizeof(b16)/sizeof(int16_t) ); //exp: time: 842,150_450default:   0000  ffff  fffe  3344
        break; case __LINE__: trice( iD(14157), "\n" );
        break; case __LINE__: TRice16B( iD(14158), " %04x", b16, sizeof(b16) /sizeof(int16_t) );  //exp: time: 842,150_450default:  0000 ffff fffe 3344
        break; case __LINE__: trice( iD(14159), "\n" );
        break; case __LINE__: Trice16B( iD(14160), " %04x", b16, sizeof(b16) /sizeof(int16_t) );  //exp: time:       5_654default:  0000 ffff fffe 3344
        break; case __LINE__: trice( iD(14161), "\n" );
        break; case __LINE__: trice16B( iD(14162), " %04x", b16, sizeof(b16) /sizeof(int16_t) );  //exp: time:            default:  0000 ffff fffe 3344
        break; case __LINE__: trice( iD(14163), "\n" );
        break; case __LINE__: trice16B( iD(14164), "msg: %04x\n", b16, sizeof(b16) /sizeof(int16_t) );  //exp: time:            default: msg: 0000 ffff fffe 3344

        break; case __LINE__: TRICE32_B( ID(14165), " %08x", b32, sizeof(b32)/sizeof(int32_t) );  //exp: time: 842,150_450default:  00000000 ffffffff fffffffe 33445555
        break; case __LINE__: trice( iD(14166), "\n" );
        break; case __LINE__: TRice32B( iD(14167), " %08x", b32, sizeof(b32) /sizeof(int32_t)  ); //exp: time: 842,150_450default:  00000000 ffffffff fffffffe 33445555
        break; case __LINE__: trice( iD(14168), "\n" );
        break; case __LINE__: Trice32B( iD(14169), " %08x", b32, sizeof(b32) /sizeof(int32_t)  ); //exp: time:       5_654default:  00000000 ffffffff fffffffe 33445555
        break; case __LINE__: trice( iD(14170), "\n" );
        break; case __LINE__: trice32B( iD(14171), " %08x", b32, sizeof(b32) /sizeof(int32_t)  ); //exp: time:            default:  00000000 ffffffff fffffffe 33445555
        break; case __LINE__: trice( iD(14172), "\n" );
        break; case __LINE__: trice32B( iD(14173), "att: %08x\n", b32, sizeof(b32) /sizeof(int32_t)  ); //exp: time:            default: att: 00000000 ffffffff fffffffe 33445555

        break; case __LINE__: TRICE64_B( ID(14174), " %016x", b64, sizeof(b64)/sizeof(int64_t) );  //exp: time: 842,150_450default:  0000000000000000 ffffffffffffffff fffffffffffffffe 3344555566666666
        break; case __LINE__: trice( iD(14175), "\n" );
        break; case __LINE__: TRice64B( iD(14176), " %016x", b64, sizeof(b64) /sizeof(int64_t)  ); //exp: time: 842,150_450default:  0000000000000000 ffffffffffffffff fffffffffffffffe 3344555566666666
        break; case __LINE__: trice( iD(14177), "\n" );
        break; case __LINE__: Trice64B( iD(14178), " %016x", b64, sizeof(b64) /sizeof(int64_t)  ); //exp: time:       5_654default:  0000000000000000 ffffffffffffffff fffffffffffffffe 3344555566666666
        break; case __LINE__: trice( iD(14179), "\n" );
        break; case __LINE__: trice64B( iD(14180), " %016x", b64, sizeof(b64) /sizeof(int64_t)  ); //exp: time:            default:  0000000000000000 ffffffffffffffff fffffffffffffffe 3344555566666666
        break; case __LINE__: trice( iD(14181), "\n" );
        break; case __LINE__: trice64B( iD(14182), "SIG: %016x\n", b64, sizeof(b64) /sizeof(int64_t)  ); //exp: time:            default: SIG: 0000000000000000 ffffffffffffffff fffffffffffffffe 3344555566666666

        break; case __LINE__: TRICE8_F( ID(14183), "info:FunctionNameW", b8,  sizeof(b8) /sizeof(int8_t) );   //exp: time: 842,150_450default: info:FunctionNameW(00)(ff)(fe)(33)(04)(05)(06)(07)(08)(09)(0a)(0b)(00)(ff)(fe)(33)(04)(05)(06)(07)(08)(09)(0a)(0b)
        break; case __LINE__: TRice8F( iD(14184), "call:FunctionNameW", b8,  sizeof(b8) /sizeof(int8_t) );    //exp: time: 842,150_450default: call:FunctionNameW(00)(ff)(fe)(33)(04)(05)(06)(07)(08)(09)(0a)(0b)(00)(ff)(fe)(33)(04)(05)(06)(07)(08)(09)(0a)(0b)
        break; case __LINE__: Trice8F( iD(14185), "call:FunctionNameW", b8,  sizeof(b8) /sizeof(int8_t) );    //exp: time:       5_654default: call:FunctionNameW(00)(ff)(fe)(33)(04)(05)(06)(07)(08)(09)(0a)(0b)(00)(ff)(fe)(33)(04)(05)(06)(07)(08)(09)(0a)(0b)
        break; case __LINE__: trice8F( iD(14186), "call:FunctionNameW", b8,  sizeof(b8) /sizeof(int8_t) );    //exp: time:            default: call:FunctionNameW(00)(ff)(fe)(33)(04)(05)(06)(07)(08)(09)(0a)(0b)(00)(ff)(fe)(33)(04)(05)(06)(07)(08)(09)(0a)(0b)
        break; case __LINE__: TRICE16_F( ID(14187), "info:FunctionNameX", b16, sizeof(b16)/sizeof(int16_t) );  //exp: time: 842,150_450default: info:FunctionNameX(0000)(ffff)(fffe)(3344) 
        break; case __LINE__: TRice16F( iD(14188), "call:FunctionNameX", b16, sizeof(b16)/sizeof(int16_t) );  //exp: time: 842,150_450default: call:FunctionNameX(0000)(ffff)(fffe)(3344) 
        break; case __LINE__: Trice16F( iD(14189), "call:FunctionNameX", b16, sizeof(b16)/sizeof(int16_t) );  //exp: time:       5_654default: call:FunctionNameX(0000)(ffff)(fffe)(3344) 
        break; case __LINE__: trice16F( iD(14190), "call:FunctionNameX", b16, sizeof(b16)/sizeof(int16_t) );  //exp: time:            default: call:FunctionNameX(0000)(ffff)(fffe)(3344) 
        break; case __LINE__: TRICE32_F( ID(14191), "info:FunctionNameY", b32, sizeof(b32)/sizeof(int32_t) );  //exp: time: 842,150_450default: info:FunctionNameY(00000000)(ffffffff)(fffffffe)(33445555)
        break; case __LINE__: TRice32F( iD(14192), "call:FunctionNameY", b32, sizeof(b32)/sizeof(int32_t) );  //exp: time: 842,150_450default: call:FunctionNameY(00000000)(ffffffff)(fffffffe)(33445555)
        break; case __LINE__: Trice32F( iD(14193), "call:FunctionNameY", b32, sizeof(b32)/sizeof(int32_t) );  //exp: time:       5_654default: call:FunctionNameY(00000000)(ffffffff)(fffffffe)(33445555)
        break; case __LINE__: trice32F( iD(14194), "call:FunctionNameY", b32, sizeof(b32)/sizeof(int32_t) );  //exp: time:            default: call:FunctionNameY(00000000)(ffffffff)(fffffffe)(33445555)
        break; case __LINE__: TRICE64_F( ID(14195), "info:FunctionNameZ", b64, sizeof(b64)/sizeof(int64_t) );  //exp: time: 842,150_450default: info:FunctionNameZ(0000000000000000)(ffffffffffffffff)(fffffffffffffffe)(3344555566666666)
        break; case __LINE__: TRice64F( iD(14196), "call:FunctionNameZ", b64, sizeof(b64)/sizeof(int64_t) );  //exp: time: 842,150_450default: call:FunctionNameZ(0000000000000000)(ffffffffffffffff)(fffffffffffffffe)(3344555566666666)
        break; case __LINE__: Trice64F( iD(14197), "call:FunctionNameZ", b64, sizeof(b64)/sizeof(int64_t) );  //exp: time:       5_654default: call:FunctionNameZ(0000000000000000)(ffffffffffffffff)(fffffffffffffffe)(3344555566666666)
        break; case __LINE__: trice64F( iD(14198), "call:FunctionNameZ", b64, sizeof(b64)/sizeof(int64_t) );  //exp: time:            default: call:FunctionNameZ(0000000000000000)(ffffffffffffffff)(fffffffffffffffe)(3344555566666666)
        break; case __LINE__: TRiceS( iD(14199), "msg:Hi %s!\n", five );                 //exp: time: 842,150_450default: msg:Hi five!
        break; case __LINE__: TriceS( iD(14200), "msg:Hi %s!\n", five );                 //exp: time:       5_654default: msg:Hi five!
        break; case __LINE__: triceS( iD(14201), "msg:Hi %s!\n", five );                 //exp: time:            default: msg:Hi five!
        break; case __LINE__: TRiceN( iD(14202), "msg:Hi %s!\n", five, strlen(five) );   //exp: time: 842,150_450default: msg:Hi five!
        break; case __LINE__: TriceN( iD(14203), "msg:Hi %s!\n", five, strlen(five) );   //exp: time:       5_654default: msg:Hi five!
        break; case __LINE__: triceN( iD(14204), "msg:Hi %s!\n", five, strlen(five) );   //exp: time:            default: msg:Hi five!

        break; case __LINE__: TRICE_S( id(14205), "sig:TRICE_S=%s\n", s );            //exp: time:            default: sig:TRICE_S=AAAAAAAAAAAA
        break; case __LINE__: TRICE_N( id(14206), "sig:TRICE_N=%s\n", s, strlen(s) ); //exp: time:            default: sig:TRICE_N=AAAAAAAAAAAA
        break; case __LINE__: TRICE_S( Id(14207), "sig:TRICE_S=%s\n", s );            //exp: time:       5_654default: sig:TRICE_S=AAAAAAAAAAAA
        break; case __LINE__: TRICE_N( Id(14208), "sig:TRICE_N=%s\n", s, strlen(s) ); //exp: time:       5_654default: sig:TRICE_N=AAAAAAAAAAAA
        break; case __LINE__: TRICE_S( ID(14209), "sig:TRICE_S=%s\n", s );            //exp: time: 842,150_450default: sig:TRICE_S=AAAAAAAAAAAA
        break; case __LINE__: TRICE_N( ID(14210), "sig:TRICE_N=%s\n", s, strlen(s) ); //exp: time: 842,150_450default: sig:TRICE_N=AAAAAAAAAAAA
        break; case __LINE__: triceS( iD(14211), "sig:triceS=%s\n", s );              //exp: time:            default: sig:triceS=AAAAAAAAAAAA
        break; case __LINE__: triceN( iD(14212), "sig:triceN=%s\n", s, strlen(s) );   //exp: time:            default: sig:triceN=AAAAAAAAAAAA
        break; case __LINE__: TriceS( iD(14213), "sig:TriceS=%s\n", s );              //exp: time:       5_654default: sig:TriceS=AAAAAAAAAAAA
        break; case __LINE__: TriceN( iD(14214), "sig:TriceN=%s\n", s, strlen(s) );   //exp: time:       5_654default: sig:TriceN=AAAAAAAAAAAA
        break; case __LINE__: TRiceS( iD(14215), "sig:TRiceS=%s\n", s );              //exp: time: 842,150_450default: sig:TRiceS=AAAAAAAAAAAA
        break; case __LINE__: TRiceN( iD(14216), "sig:TRiceN=%s\n", s, strlen(s) );   //exp: time: 842,150_450default: sig:TRiceN=AAAAAAAAAAAA

        break; case __LINE__: trice16( iD(14217), "att: line %u\n", __LINE__ );

        break; case __LINE__: exampleOfManualJSONencoding(); //exp: time:       5_654default: att:MyStructEvaluationFunction(json:ExA{Apple:-1, Birn:2, Fisch:2.781000}
        break; case __LINE__: TRICE( Id(14218), "MSG:1/11 = %g\n", aFloat( 1.0/11 ) ); //exp: time:       5_654default: MSG:1/11 = 0.09090909
        break; case __LINE__: { //exp: time: 842,150_450default: msg:x = 5.934 = 5.934, 5.934
                              float a = (float)5.934;
                              float b = a + ((a > 0) ? 0.0005f : -0.0005f);
                              int c = (int)b;
                              int d = (int)(b * 1000) % 1000;
                              int e = (int)(1000 * (float)(a - c)); 
                              TRICE( ID(14219), "msg:x = %g = %d.%03d, %d.%03d\n", aFloat(a), c, d, c, e ); 
                              }

        break; case __LINE__: trice16( iD(14220), "att: line %u\n", __LINE__ );

        break; case __LINE__: TRice( iD(14221), "sig:Integer (indent, base, sign) - see https://yourbasic.org/golang/fmt-printf-reference-cheat-sheet/\n" );
        break; case __LINE__: TRice( iD(14222), "rd: 15 	%d 	Base 10\n", 15 );                                        //exp: time: 842,150_450default: rd: 15 	15 	Base 10                                   
        break; case __LINE__: TRice( iD(14223), "rd: +15 	%+d 	Always show sign\n", 15 );                           //exp: time: 842,150_450default: rd: +15 	+15 	Always show sign                          
        break; case __LINE__: TRice( iD(14224), "rd:   15	%4d 	Pad with spaces (width 4, right justified)\n", 15 ); //exp: time: 842,150_450default: rd:   15	  15 	Pad with spaces (width 4, right justified)
        break; case __LINE__: TRice( iD(14225), "rd:    15	%-4d	Pad with spaces (width 4, left justified)\n", 15 );  //exp: time: 842,150_450default: rd:    15	15  	Pad with spaces (width 4, left justified) 
        break; case __LINE__: TRice( iD(14226), "rd: 0015	%04d	Pad with zeroes (width 4)\n", 15 );                  //exp: time: 842,150_450default: rd: 0015	0015	Pad with zeroes (width 4)                 
        break; case __LINE__: TRice( iD(14227), "rd: 1111 	%b 	Base 2\n", 15 );                                         //exp: time: 842,150_450default: rd: 1111 	1111 	Base 2                                    
        break; case __LINE__: TRice( iD(14228), "rd: 17 	%o 	Base 8\n", 15 );                                         //exp: time: 842,150_450default: rd: 17 	17 	Base 8                                    
        break; case __LINE__: TRice( iD(14229), "rd: f 	%x 	Base 16, lowercase\n", 15 );                                 //exp: time: 842,150_450default: rd: f 	f 	Base 16, lowercase                        
        break; case __LINE__: TRice( iD(14230), "rd: F 	%X 	Base 16, uppercase\n", 15 );                                 //exp: time: 842,150_450default: rd: F 	F 	Base 16, uppercase                        
        break; case __LINE__: TRice( iD(14231), "rd: 0xf 	%#x 	Base 16, with leading 0x\n", 15 );                   //exp: time: 842,150_450default: rd: 0xf 	0xf 	Base 16, with leading 0x                  

        break; case __LINE__: trice16( iD(14232), "att: line %u\n", __LINE__ );

        break; case __LINE__: TRICE( ID(14233), "sig:Character (quoted, Unicode)\n" );
        break; case __LINE__: TRICE( ID(14234), "rd: A 	%c 	Character\n", 'A' );                                     //exp: time: 842,150_450default: rd: A 	A 	Character
        break; case __LINE__: TRICE( ID(14235), "rd: 'A' 	%q 	Quoted character\n", 'A' );                          //exp: time: 842,150_450default: rd: 'A' 	'A' 	Quoted character
    //  break; case __LINE__: TRICE( ID(14236), "rd: U+0041 	%U 	Unicode\n", 'A' );                        // todo: detect %U to avoid message triceType = TRICE0 ParamSpace = 4 not matching with bitWidth  0 and paramCount 0 - ignoring package
    //  break; case __LINE__: TRICE( ID(14237), "rd: U+0041 'A' 	%#U 	Unicode with character\n", 'A' ); // todo: detect %#U to avoid message triceType = TRICE0 ParamSpace = 4 not matching with bitWidth  0 and paramCount 0 - ignoring package

        break; case __LINE__: TRICE( ID(14238), "sig:Boolean (true/false)\n" );
        break; case __LINE__: TRICE( ID(14239), "rd:Use %%t to format a boolean as true (%t) or false (%t).\n", 1, 0 ); //exp: time: 842,150_450default: rd:Use %t to format a boolean as true (true) or false (false).

        break; case __LINE__: TRICE( ID(14240), "sig:Pointer (hex)\n" );
        break; case __LINE__: TRICE8 ( ID(14241), "rd:Use %%p to format a pointer in base 16 notation with leading 0x. (%p)\n", 0x84 );               //exp: time: 842,150_450default: rd:Use %p to format a pointer in base 16 notation with leading 0x. (84)              
        break; case __LINE__: TRICE16( ID(14242), "rd:Use %%p to format a pointer in base 16 notation with leading 0x. (%p)\n", 0x1234 );             //exp: time: 842,150_450default: rd:Use %p to format a pointer in base 16 notation with leading 0x. (1234)            
        break; case __LINE__: TRICE32( ID(14243), "rd:Use %%p to format a pointer in base 16 notation with leading 0x. (%p)\n", 0xaabbccdd );         //exp: time: 842,150_450default: rd:Use %p to format a pointer in base 16 notation with leading 0x. (aabbccdd)        
        break; case __LINE__: TRICE64( ID(14244), "rd:Use %%p to format a pointer in base 16 notation with leading 0x. (%p)\n", 0x1122334455667788 ); //exp: time: 842,150_450default: rd:Use %p to format a pointer in base 16 notation with leading 0x. (1122334455667788)
        break; case __LINE__: TRICE  ( ID(14245), "rd:Use %%p to format a pointer in base 16 notation with leading 0x. (%p)\n", 0xaabbccdd);          //exp: time: 842,150_450default: rd:Use %p to format a pointer in base 16 notation with leading 0x. (aabbccdd)        

        break; case __LINE__: trice16( iD(14246), "att: line %u\n", __LINE__ );

        break; case __LINE__: TRICE( ID(14247), "sig:Float (indent, precision, scientific notation)\n" );
        break; case __LINE__: TRICE( ID(14248), "rd: 1.234560e+02		%e 	%%e Scientific notation\n", aFloat(123.456) );                       //exp: time: 842,150_450default: rd: 1.234560e+02		1.234560e+02 	%e Scientific notation
        break; case __LINE__: TRICE( ID(14249), "rd: 123.456000		%f 	%%f Decimal point, no exponent\n", aFloat(123.456) );                    //exp: time: 842,150_450default: rd: 123.456000		123.456001 	%f Decimal point, no exponent
        break; case __LINE__: TRICE( ID(14250), "rd: 123.46			%.2f		%%.2f Default width, precision 2\n", aFloat(123.456) );          //exp: time: 842,150_450default: rd: 123.46			123.46		%.2f Default width, precision 2
        break; case __LINE__: TRICE( ID(14251), "rd: ␣␣123.46		%8.2f	%%8.2f Width 8, precision 2\n", aFloat(123.456) );                    //exp: time: 842,150_450default: rd: ␣␣123.46		  123.46	%8.2f Width 8, precision 2
        break; case __LINE__: TRICE( ID(14252), "rd: 123.456		%g		%%g Exponent as needed, necessary digits only\n", aFloat(123.456) ); //exp: time: 842,150_450default: rd: 123.456		123.456		%g Exponent as needed, necessary digits only

        break; case __LINE__: TRICE( ID(14253), "sig:Double (indent, precision, scientific notation)\n" );
        break; case __LINE__: TRICE64( ID(14254), "rd: 1.234560e+02		%e 	%%e Scientific notation\n", aDouble(123.456) );                       //exp: time: 842,150_450default: rd: 1.234560e+02		1.234560e+02 	%e Scientific notation
        break; case __LINE__: TRICE64( ID(14255), "rd: 123.456000		%f 	%%f Decimal point, no exponent\n", aDouble(123.456) );                //exp: time: 842,150_450default: rd: 123.456000		123.456000 	%f Decimal point, no exponent
        break; case __LINE__: TRICE64( ID(14256), "rd: 123.46			%.2f    	%%.2f Default width, precision 2\n", aDouble(123.456) );      //exp: time: 842,150_450default: rd: 123.46			123.46    	%.2f Default width, precision 2
        break; case __LINE__: TRICE64( ID(14257), "rd: ␣␣123.46		%8.2f 	%%8.2f Width 8, precision 2\n", aDouble(123.456) );                    //exp: time: 842,150_450default: rd: ␣␣123.46		  123.46 	%8.2f Width 8, precision 2
        break; case __LINE__: TRICE64( ID(14258), "rd: 123.456		%g		%%g Exponent as needed, necessary digits only\n", aDouble(123.456) ); //exp: time: 842,150_450default: rd: 123.456		123.456		%g Exponent as needed, necessary digits only

        break; case __LINE__: TRICE( ID(14259), "sig:String or byte slice (quote, indent, hex)\n" );
        break; case __LINE__: s = "café"; TRICE_S( ID(14260), "rd: café 			%s		Plain string\n", s );           //exp: time: 842,150_450default: rd: café 			café		Plain string
        break; case __LINE__: s = "café"; TRICE_S( ID(14261), "rd: ␣␣café 		%6s 		Width 6, right justify\n", s );  //exp: time: 842,150_450default: rd: ␣␣café 		  café 		Width 6, right justify
        break; case __LINE__: s = "café"; TRICE_S( ID(14262), "rd: café␣␣ 		%-6s 		Width 6, left justify\n", s );   //exp: time: 842,150_450default: rd: café␣␣ 		café   		Width 6, left justify
        break; case __LINE__: s = "café"; TRICE_S( ID(14263), "rd: \"café\" 		%q		Quoted string\n", s );          //exp: time: 842,150_450default: rd: \"café\" 		"café"		Quoted string
        break; case __LINE__: s = "café"; TRICE_S( ID(14264), "rd: 636166c3a9 		%x	Hex dump of byte values\n", s );    //exp: time: 842,150_450default: rd: 636166c3a9 		636166c3a9	Hex dump of byte values 
        break; case __LINE__: s = "café"; TRICE_S( ID(14265), "rd: 63 61 66 c3 a9 	% x	Hex dump with spaces\n", s );       //exp: time: 842,150_450default: rd: 63 61 66 c3 a9 	63 61 66 c3 a9	Hex dump with spaces

        break; case __LINE__: trice16( iD(14266), "att: line %u\n", __LINE__ );
        break; case __LINE__: exampleOfManualSerialization(); // ATTENTION: This occupies ~1024 bytes in one half buffer when double buffer ist used!

        // This was a CGO compiler issue:
        break; case __LINE__: TRice( iD(14267), "info:12 default bit width values %d, %u, %x, %X, %t, %e, %f, %g, %E, %F, %G, 0xb%08b and a 32-bit stamp.\n", -3, -4, -5, -6, 1, aFloat(-7.123456789), aFloat(-7.123456789), aFloat(-7.123456789), aFloat(-7.123456789), aFloat(-7.123456789), aFloat(-7.123456789), -8 ); //exp: time: 842,150_450default: info:12 default bit width values -3, 4294967292, fffffffb, FFFFFFFA, true, -7.123457e+00, -7.123457, -7.123457, -7.123457E+00, -7.123457, -7.123457, 0xb11111111111111111111111111111000 and a 32-bit stamp.
        break; case __LINE__: Trice( iD(14268), "info:12 default bit width values %d, %u, %x, %X, %t, %e, %f, %g, %E, %F, %G, 0xb%08b and a 16-bit stamp.\n", -3, -4, -5, -6, 1, aFloat(-7.123456789), aFloat(-7.123456789), aFloat(-7.123456789), aFloat(-7.123456789), aFloat(-7.123456789), aFloat(-7.123456789), -8 ); //exp: time:       5_654default: info:12 default bit width values -3, 4294967292, fffffffb, FFFFFFFA, true, -7.123457e+00, -7.123457, -7.123457, -7.123457E+00, -7.123457, -7.123457, 0xb11111111111111111111111111111000 and a 16-bit stamp.
        break; case __LINE__: trice( iD(14269), "info:12 default bit width values %d, %u, %x, %X, %t, %e, %f, %g, %E, %F, %G, 0xb%08b and without stamp.\n" , -3, -4, -5, -6, 1, aFloat(-7.123456789), aFloat(-7.123456789), aFloat(-7.123456789), aFloat(-7.123456789), aFloat(-7.123456789), aFloat(-7.123456789), -8 ); //exp: time:            default: info:12 default bit width values -3, 4294967292, fffffffb, FFFFFFFA, true, -7.123457e+00, -7.123457, -7.123457, -7.123457E+00, -7.123457, -7.123457, 0xb11111111111111111111111111111000 and without stamp.

        break; case __LINE__: trice16( iD(14270), "att: line %u\n", __LINE__ );

        break; case __LINE__: TRICE( ID(14271), "sig:Runtime generated strings\n" );
        break; case __LINE__: 
        {
            char* s0 = "AAAAAAAAAAAA";
            TRICE32( ID(14272), "dbg:len=%u:", strlen(s0) );
            TRICE_S( ID(14273), "sig:%s\n", s0 );
        }
        break; case __LINE__: 
        {
            char* s1 = "\
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABBBBBBBBCCCCCCCC\
";
                TRICE32( ID(14274), "dbg:len=%u:", strlen(s1) );
                TRICE_S( ID(14275), "sig:%s\n", s1 );
            }
        break; case __LINE__: 
        {
            char* s2 = "\
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\
BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB\
CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC\
DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD\
EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE\
";
            TRICE32( ID(14280), "dbg:len=%u: ", strlen(s2) );
            TRICE_S( ID(14284), "sig:%s\n", s2 );
        }
        break; case __LINE__: 
        {
            char* s3 = "\
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\
BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB\
CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC\
DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD\
EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE\
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\
BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB\
CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC\
";
            TRICE32( ID(14277), "dbg:len=%u: ", strlen(s3) );
            TRICE_S( ID(14281), "sig:%s\n", s3 );
        }
        break; case __LINE__:
        {
            char* s4 = "\
0123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789\
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\
BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB\
CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC\
DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD\
EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE\
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\
BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB\
CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC\
DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD\
EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE\
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\
BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB\
CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC\
DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD\
EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE\
";
            TRICE32( ID(14283), "dbg:len=%u: ", strlen(s4) );
            TRICE_S( ID(14278), "sig:%s\n", s4 );
        }


#if TRICE_CGO == 1

        break; case __LINE__: TRICE  ( ID(14285), "rd:%E (%%E)\n",  aFloat(-555555555.5555555555) ); //exp: time: 842,150_450default: rd:-5.555556E+08 (%E)
        break; case __LINE__: TRICE  ( ID(14286), "rd:%F (%%F)\n",  aFloat(-555555555.5555555555) ); //exp: time: 842,150_450default: rd:-555555584.000000 (%F)
        break; case __LINE__: TRICE  ( ID(14287), "rd:%G (%%G)\n",  aFloat(-555555555.5555555555) ); //exp: time: 842,150_450default: rd:-5.555556E+08 (%G)
        break; case __LINE__: TRICE64( ID(14288), "rd:%E (%%E)\n", aDouble(-555555555.5555555555) ); //exp: time: 842,150_450default: rd:-5.555556E+08 (%E)
        break; case __LINE__: TRICE64( ID(14289), "rd:%F (%%F)\n", aDouble(-555555555.5555555555) ); //exp: time: 842,150_450default: rd:-555555555.555556 (%F)
        break; case __LINE__: TRICE64( ID(14290), "rd:%G (%%G)\n", aDouble(-555555555.5555555555) ); //exp: time: 842,150_450default: rd:-5.555555555555556E+08 (%G)
        
        break; case __LINE__: TRICE  ( ID(14291), "rd:%e (%%e)\n",  aFloat(-555555555.5555555555) ); //exp: time: 842,150_450default: rd:-5.555556e+08 (%e)
        break; case __LINE__: TRICE  ( ID(14292), "rd:%f (%%f)\n",  aFloat(-555555555.5555555555) ); //exp: time: 842,150_450default: rd:-555555584.000000 (%f)
        break; case __LINE__: TRICE  ( ID(14293), "rd:%g (%%g)\n",  aFloat(-555555555.5555555555) ); //exp: time: 842,150_450default: rd:-5.555556e+08 (%g)
        break; case __LINE__: TRICE64( ID(14294), "rd:%e (%%e)\n", aDouble(-555555555.5555555555) ); //exp: time: 842,150_450default: rd:-5.555556e+08 (%e)
        break; case __LINE__: TRICE64( ID(14295), "rd:%f (%%f)\n", aDouble(-555555555.5555555555) ); //exp: time: 842,150_450default: rd:-555555555.555556 (%f)
        break; case __LINE__: TRICE64( ID(14296), "rd:%g (%%g)\n", aDouble(-555555555.5555555555) ); //exp: time: 842,150_450default: rd:-5.555555555555556e+08 (%g)

        break; case __LINE__: TRICE32( ID(14297), "msg:%u (%%u)\n", -1 ); //exp: time: 842,150_450default: msg:4294967295 (%u)
        break; case __LINE__: TRICE32( ID(14298), "msg:%b (%%b)\n", -1 ); //exp: time: 842,150_450default: msg:11111111111111111111111111111111 (%b)
        break; case __LINE__: TRICE32( ID(14299), "msg:%o (%%o)\n", -1 ); //exp: time: 842,150_450default: msg:37777777777 (%o)
        break; case __LINE__: TRICE32( ID(14300), "msg:%O (%%O)\n", -1 ); //exp: time: 842,150_450default: msg:0o37777777777 (%O)
        break; case __LINE__: TRICE32( ID(14301), "msg:%X (%%X)\n", -1 ); //exp: time: 842,150_450default: msg:FFFFFFFF (%X)
        break; case __LINE__: TRICE32( ID(14302), "msg:%x (%%x)\n", -1 ); //exp: time: 842,150_450default: msg:ffffffff (%x)
        break; case __LINE__: TRICE32( ID(14303), "msg:%d (%%d)\n", -1 ); //exp: time: 842,150_450default: msg:-1 (%d)
        break; case __LINE__: TRICE64( ID(14304), "msg:%u (%%u)\n", -1 ); //exp: time: 842,150_450default: msg:18446744073709551615 (%u)
        break; case __LINE__: TRICE64( ID(14305), "msg:%b (%%b)\n", -1 ); //exp: time: 842,150_450default: msg:1111111111111111111111111111111111111111111111111111111111111111 (%b)
        break; case __LINE__: TRICE64( ID(14306), "msg:%o (%%o)\n", -1 ); //exp: time: 842,150_450default: msg:1777777777777777777777 (%o)
        break; case __LINE__: TRICE64( ID(14307), "msg:%O (%%O)\n", -1 ); //exp: time: 842,150_450default: msg:0o1777777777777777777777 (%O)
        break; case __LINE__: TRICE64( ID(14308), "msg:%X (%%X)\n", -1 ); //exp: time: 842,150_450default: msg:FFFFFFFFFFFFFFFF (%X)
        break; case __LINE__: TRICE64( ID(14309), "msg:%x (%%x)\n", -1 ); //exp: time: 842,150_450default: msg:ffffffffffffffff (%x)

    /**/break; case __LINE__: TRice        ( iD(14310), "value=%d\n", -2  ); //exp: time: 842,150_450default: value=-2
    /**/break; case __LINE__: Trice        ( iD(14311), "value=%d\n", -2  ); //exp: time:       5_654default: value=-2
    /**/break; case __LINE__: trice        ( iD(14312), "value=%d\n", -2  ); //exp: time:            default: value=-2
        break; case __LINE__: TRice8       ( iD(14531), "value=%d\n", -2  ); //exp: time: 842,150_450default: value=-2
        break; case __LINE__: Trice8       ( iD(14563), "value=%d\n", -2  ); //exp: time:       5_654default: value=-2
        break; case __LINE__: trice8       ( iD(14315), "value=%d\n", -2  ); //exp: time:            default: value=-2
        break; case __LINE__: TRice16      ( iD(14537), "value=%d\n", -2  ); //exp: time: 842,150_450default: value=-2
        break; case __LINE__: Trice16      ( iD(14317), "value=%d\n", -2  ); //exp: time:       5_654default: value=-2
        break; case __LINE__: trice16      ( iD(14318), "value=%d\n", -2  ); //exp: time:            default: value=-2
        break; case __LINE__: TRice32      ( iD(14543), "value=%d\n", -2  ); //exp: time: 842,150_450default: value=-2
        break; case __LINE__: Trice32      ( iD(14542), "value=%d\n", -2  ); //exp: time:       5_654default: value=-2
        break; case __LINE__: trice32      ( iD(14541), "value=%d\n", -2  ); //exp: time:            default: value=-2
        break; case __LINE__: TRice64      ( iD(14322), "value=%d\n", -2  ); //exp: time: 842,150_450default: value=-2
        break; case __LINE__: Trice64      ( iD(14323), "value=%d\n", -2  ); //exp: time:       5_654default: value=-2
        break; case __LINE__: trice64      ( iD(14324), "value=%d\n", -2  ); //exp: time:            default: value=-2
        
        break; case __LINE__: TRice_1      ( iD(14325), "value=%d\n", -2  ); //exp: time: 842,150_450default: value=-2
        break; case __LINE__: Trice_1      ( iD(14326), "value=%d\n", -2  ); //exp: time:       5_654default: value=-2
        break; case __LINE__: trice_1      ( iD(14327), "value=%d\n", -2  ); //exp: time:            default: value=-2
        break; case __LINE__: TRice8_1     ( iD(14328), "value=%d\n", -2  ); //exp: time: 842,150_450default: value=-2
        break; case __LINE__: Trice8_1     ( iD(14533), "value=%d\n", -2  ); //exp: time:       5_654default: value=-2
        break; case __LINE__: trice8_1     ( iD(14532), "value=%d\n", -2  ); //exp: time:            default: value=-2
        break; case __LINE__: TRice16_1    ( iD(14331), "value=%d\n", -2  ); //exp: time: 842,150_450default: value=-2
        break; case __LINE__: Trice16_1    ( iD(14332), "value=%d\n", -2  ); //exp: time:       5_654default: value=-2
        break; case __LINE__: trice16_1    ( iD(14538), "value=%d\n", -2  ); //exp: time:            default: value=-2
        break; case __LINE__: TRice32_1    ( iD(14546), "value=%d\n", -2  ); //exp: time: 842,150_450default: value=-2
        break; case __LINE__: Trice32_1    ( iD(14335), "value=%d\n", -2  ); //exp: time:       5_654default: value=-2
        break; case __LINE__: trice32_1    ( iD(14336), "value=%d\n", -2  ); //exp: time:            default: value=-2
        break; case __LINE__: TRice64_1    ( iD(14337), "value=%d\n", -2  ); //exp: time: 842,150_450default: value=-2
        break; case __LINE__: Trice64_1    ( iD(14551), "value=%d\n", -2  ); //exp: time:       5_654default: value=-2
        break; case __LINE__: trice64_1    ( iD(14550), "value=%d\n", -2  ); //exp: time:            default: value=-2
        
        break; case __LINE__: TRice        ( iD(14340), "no value" ); //exp: time: 842,150_450default: no value
        break; case __LINE__: Trice        ( iD(14341), "no value" ); //exp: time:       5_654default: no value
        break; case __LINE__: trice        ( iD(14342), "no value" ); //exp: time:            default: no value
        break; case __LINE__: TRice8       ( iD(14343), "no value" ); //exp: time: 842,150_450default: no value
        break; case __LINE__: Trice8       ( iD(14344), "no value" ); //exp: time:       5_654default: no value
        break; case __LINE__: trice8       ( iD(14345), "no value" ); //exp: time:            default: no value
        break; case __LINE__: TRice16      ( iD(14346), "no value" ); //exp: time: 842,150_450default: no value
        break; case __LINE__: Trice16      ( iD(14347), "no value" ); //exp: time:       5_654default: no value
        break; case __LINE__: trice16      ( iD(14348), "no value" ); //exp: time:            default: no value
        break; case __LINE__: TRice32      ( iD(14349), "no value" ); //exp: time: 842,150_450default: no value
        break; case __LINE__: Trice32      ( iD(14350), "no value" ); //exp: time:       5_654default: no value
        break; case __LINE__: trice32      ( iD(14351), "no value" ); //exp: time:            default: no value
        break; case __LINE__: TRice64      ( iD(14352), "no value" ); //exp: time: 842,150_450default: no value
        break; case __LINE__: Trice64      ( iD(14353), "no value" ); //exp: time:       5_654default: no value
        break; case __LINE__: trice64      ( iD(14354), "no value" ); //exp: time:            default: no value
    
        break; case __LINE__: TRice_0      ( iD(14355), "no value" ); //exp: time: 842,150_450default: no value
        break; case __LINE__: Trice_0      ( iD(14356), "no value" ); //exp: time:       5_654default: no value
        break; case __LINE__: trice_0      ( iD(14357), "no value" ); //exp: time:            default: no value
        break; case __LINE__: TRice8_0     ( iD(14358), "no value" ); //exp: time: 842,150_450default: no value
        break; case __LINE__: Trice8_0     ( iD(14359), "no value" ); //exp: time:       5_654default: no value
        break; case __LINE__: trice8_0     ( iD(14360), "no value" ); //exp: time:            default: no value
        break; case __LINE__: TRice16_0    ( iD(14361), "no value" ); //exp: time: 842,150_450default: no value
        break; case __LINE__: Trice16_0    ( iD(14362), "no value" ); //exp: time:       5_654default: no value
        break; case __LINE__: trice16_0    ( iD(14363), "no value" ); //exp: time:            default: no value
        break; case __LINE__: TRice32_0    ( iD(14364), "no value" ); //exp: time: 842,150_450default: no value
        break; case __LINE__: Trice32_0    ( iD(14365), "no value" ); //exp: time:       5_654default: no value
        break; case __LINE__: trice32_0    ( iD(14366), "no value" ); //exp: time:            default: no value
        break; case __LINE__: TRice64_0    ( iD(14367), "no value" ); //exp: time: 842,150_450default: no value
        break; case __LINE__: Trice64_0    ( iD(14368), "no value" ); //exp: time:       5_654default: no value
        break; case __LINE__: trice64_0    ( iD(14369), "no value" ); //exp: time:            default: no value

        break; case __LINE__: TRice( iD(14370), "info:This is a message with one value %d and a 32-bit stamp.\n", -2  ); //exp: time: 842,150_450default: info:This is a message with one value -2 and a 32-bit stamp.
        break; case __LINE__: Trice( iD(14371), "info:This is a message with one value %d and a 16-bit stamp.\n", -2  ); //exp: time:       5_654default: info:This is a message with one value -2 and a 16-bit stamp.
        break; case __LINE__: trice( iD(14372), "info:This is a message with one value %d and without stamp.\n" , -2  ); //exp: time:            default: info:This is a message with one value -2 and without stamp.

        break; case __LINE__: TRICE( ID(14373), "info:This is a message without values and a 32-bit stamp.\n" );        //exp: time: 842,150_450default: info:This is a message without values and a 32-bit stamp.
        break; case __LINE__: TRICE( Id(14374), "info:This is a message without values and a 16-bit stamp.\n" );        //exp: time:       5_654default: info:This is a message without values and a 16-bit stamp.
        break; case __LINE__: TRICE( id(14375), "info:This is a message without values and without stamp.\n"  );        //exp: time:            default: info:This is a message without values and without stamp.

        break; case __LINE__: TRICE( ID(14376), "info:This is a message with one value %d and a 32-bit stamp.\n", -2  ); //exp: time: 842,150_450default: info:This is a message with one value -2 and a 32-bit stamp.
        break; case __LINE__: TRICE( Id(14377), "info:This is a message with one value %d and a 16-bit stamp.\n", -2  ); //exp: time:       5_654default: info:This is a message with one value -2 and a 16-bit stamp.
        break; case __LINE__: TRICE( id(14378), "info:This is a message with one value %d and without stamp.\n" , -2  ); //exp: time:            default: info:This is a message with one value -2 and without stamp.

        break; case __LINE__: TRICE( ID(14379), "info:12 values %d, %u, %x, %X, %t, %e, %f, %g, %E, %F, %G, 0xb%08b and a 32-bit stamp.\n", -3, -4, -5, -6, 1, aFloat(-7.123456789), aFloat(-7.123456789), aFloat(-7.123456789), aFloat(-7.123456789), aFloat(-7.123456789), aFloat(-7.123456789), -8 );   //exp: time: 842,150_450default: info:12 values -3, 4294967292, fffffffb, FFFFFFFA, true, -7.123457e+00, -7.123457, -7.123457, -7.123457E+00, -7.123457, -7.123457, 0xb11111111111111111111111111111000 and a 32-bit stamp.
        break; case __LINE__: TRICE( Id(14380), "info:12 values %d, %u, %x, %X, %t, %e, %f, %g, %E, %F, %G, 0xb%08b and a 16-bit stamp.\n", -3, -4, -5, -6, 1, aFloat(-7.123456789), aFloat(-7.123456789), aFloat(-7.123456789), aFloat(-7.123456789), aFloat(-7.123456789), aFloat(-7.123456789), -8 );   //exp: time:       5_654default: info:12 values -3, 4294967292, fffffffb, FFFFFFFA, true, -7.123457e+00, -7.123457, -7.123457, -7.123457E+00, -7.123457, -7.123457, 0xb11111111111111111111111111111000 and a 16-bit stamp.
        break; case __LINE__: TRICE( id(14381), "info:12 values %d, %u, %x, %X, %t, %e, %f, %g, %E, %F, %G, 0xb%08b and without stamp.\n" , -3, -4, -5, -6, 1, aFloat(-7.123456789), aFloat(-7.123456789), aFloat(-7.123456789), aFloat(-7.123456789), aFloat(-7.123456789), aFloat(-7.123456789), -8 );   //exp: time:            default: info:12 values -3, 4294967292, fffffffb, FFFFFFFA, true, -7.123457e+00, -7.123457, -7.123457, -7.123457E+00, -7.123457, -7.123457, 0xb11111111111111111111111111111000 and without stamp.

        break; case __LINE__: TRICE32( ID(14382), "info:12 values %d, %u, %x, %X, %t, %e, %f, %g, %E, %F, %G, 0xb%08b and a 32-bit stamp.\n", -3, -4, -5, -6, 1, aFloat(-7.123456789), aFloat(-7.123456789), aFloat(-7.123456789), aFloat(-7.123456789), aFloat(-7.123456789), aFloat(-7.123456789), -8 ); //exp: time: 842,150_450default: info:12 values -3, 4294967292, fffffffb, FFFFFFFA, true, -7.123457e+00, -7.123457, -7.123457, -7.123457E+00, -7.123457, -7.123457, 0xb11111111111111111111111111111000 and a 32-bit stamp.
        break; case __LINE__: TRICE32( Id(14383), "info:12 values %d, %u, %x, %X, %t, %e, %f, %g, %E, %F, %G, 0xb%08b and a 16-bit stamp.\n", -3, -4, -5, -6, 1, aFloat(-7.123456789), aFloat(-7.123456789), aFloat(-7.123456789), aFloat(-7.123456789), aFloat(-7.123456789), aFloat(-7.123456789), -8 ); //exp: time:       5_654default: info:12 values -3, 4294967292, fffffffb, FFFFFFFA, true, -7.123457e+00, -7.123457, -7.123457, -7.123457E+00, -7.123457, -7.123457, 0xb11111111111111111111111111111000 and a 16-bit stamp.
        break; case __LINE__: TRICE32( id(14384), "info:12 values %d, %u, %x, %X, %t, %e, %f, %g, %E, %F, %G, 0xb%08b and without stamp.\n" , -3, -4, -5, -6, 1, aFloat(-7.123456789), aFloat(-7.123456789), aFloat(-7.123456789), aFloat(-7.123456789), aFloat(-7.123456789), aFloat(-7.123456789), -8 ); //exp: time:            default: info:12 values -3, 4294967292, fffffffb, FFFFFFFA, true, -7.123457e+00, -7.123457, -7.123457, -7.123457E+00, -7.123457, -7.123457, 0xb11111111111111111111111111111000 and without stamp.

        break; case __LINE__: TRICE8   ( id(14387), "msg:value=%u\n", 200 ); //exp: time:            default: msg:value=200
        break; case __LINE__: TRICE8_1 ( id(14390), "msg:value=%u\n", 200 ); //exp: time:            default: msg:value=200
        break; case __LINE__: TRICE8   ( Id(14385), "msg:value=%u\n", 200 ); //exp: time:       5_654default: msg:value=200
        break; case __LINE__: TRICE8_1 ( Id(14388), "msg:value=%u\n", 200 ); //exp: time:       5_654default: msg:value=200
        break; case __LINE__: TRICE8   ( ID(14389), "msg:value=%u\n", 200 ); //exp: time: 842,150_450default: msg:value=200
        break; case __LINE__: TRICE8_1 ( ID(14386), "msg:value=%u\n", 200 ); //exp: time: 842,150_450default: msg:value=200
        break; case __LINE__: trice8   ( iD(14391), "msg:value=%u\n", 200 ); //exp: time:            default: msg:value=200
        break; case __LINE__: trice8_1 ( iD(14392), "msg:value=%u\n", 200 ); //exp: time:            default: msg:value=200
        break; case __LINE__: Trice8   ( iD(14393), "msg:value=%u\n", 200 ); //exp: time:       5_654default: msg:value=200
        break; case __LINE__: Trice8_1 ( iD(14394), "msg:value=%u\n", 200 ); //exp: time:       5_654default: msg:value=200
        break; case __LINE__: TRice8   ( iD(14395), "msg:value=%u\n", 200 ); //exp: time: 842,150_450default: msg:value=200
        break; case __LINE__: TRice8_1 ( iD(14396), "msg:value=%u\n", 200 ); //exp: time: 842,150_450default: msg:value=200

        break; case __LINE__: TRICE16  ( id(14401), "msg:value=%u\n", 200 ); //exp: time:            default: msg:value=200
        break; case __LINE__: TRICE16_1( id(14400), "msg:value=%u\n", 200 ); //exp: time:            default: msg:value=200
        break; case __LINE__: TRICE16  ( Id(14397), "msg:value=%u\n", 200 ); //exp: time:       5_654default: msg:value=200
        break; case __LINE__: TRICE16_1( Id(14402), "msg:value=%u\n", 200 ); //exp: time:       5_654default: msg:value=200
        break; case __LINE__: TRICE16  ( ID(14399), "msg:value=%u\n", 200 ); //exp: time: 842,150_450default: msg:value=200
        break; case __LINE__: TRICE16_1( ID(14398), "msg:value=%u\n", 200 ); //exp: time: 842,150_450default: msg:value=200
        break; case __LINE__: trice16  ( iD(14403), "msg:value=%u\n", 200 ); //exp: time:            default: msg:value=200
        break; case __LINE__: trice16_1( iD(14404), "msg:value=%u\n", 200 ); //exp: time:            default: msg:value=200
        break; case __LINE__: Trice16  ( iD(14405), "msg:value=%u\n", 200 ); //exp: time:       5_654default: msg:value=200
        break; case __LINE__: Trice16_1( iD(14406), "msg:value=%u\n", 200 ); //exp: time:       5_654default: msg:value=200
        break; case __LINE__: TRice16  ( iD(14407), "msg:value=%u\n", 200 ); //exp: time: 842,150_450default: msg:value=200
        break; case __LINE__: TRice16_1( iD(14408), "msg:value=%u\n", 200 ); //exp: time: 842,150_450default: msg:value=200

        break; case __LINE__: TRICE32  ( id(14411), "msg:value=%u\n", 200 ); //exp: time:            default: msg:value=200
        break; case __LINE__: TRICE32_1( id(14410), "msg:value=%u\n", 200 ); //exp: time:            default: msg:value=200
        break; case __LINE__: TRICE32  ( Id(14409), "msg:value=%u\n", 200 ); //exp: time:       5_654default: msg:value=200
        break; case __LINE__: TRICE32_1( Id(14414), "msg:value=%u\n", 200 ); //exp: time:       5_654default: msg:value=200
        break; case __LINE__: TRICE32  ( ID(14413), "msg:value=%u\n", 200 ); //exp: time: 842,150_450default: msg:value=200
        break; case __LINE__: TRICE32_1( ID(14412), "msg:value=%u\n", 200 ); //exp: time: 842,150_450default: msg:value=200
        break; case __LINE__: trice32  ( iD(14415), "msg:value=%u\n", 200 ); //exp: time:            default: msg:value=200
        break; case __LINE__: trice32_1( iD(14416), "msg:value=%u\n", 200 ); //exp: time:            default: msg:value=200
        break; case __LINE__: Trice32  ( iD(14417), "msg:value=%u\n", 200 ); //exp: time:       5_654default: msg:value=200
        break; case __LINE__: Trice32_1( iD(14418), "msg:value=%u\n", 200 ); //exp: time:       5_654default: msg:value=200
        break; case __LINE__: TRice32  ( iD(14419), "msg:value=%u\n", 200 ); //exp: time: 842,150_450default: msg:value=200
        break; case __LINE__: TRice32_1( iD(14420), "msg:value=%u\n", 200 ); //exp: time: 842,150_450default: msg:value=200

        break; case __LINE__: TRICE64  ( id(14423), "msg:value=%u\n", 200 ); //exp: time:            default: msg:value=200
        break; case __LINE__: TRICE64_1( id(14422), "msg:value=%u\n", 200 ); //exp: time:            default: msg:value=200
        break; case __LINE__: TRICE64  ( Id(14421), "msg:value=%u\n", 200 ); //exp: time:       5_654default: msg:value=200
        break; case __LINE__: TRICE64_1( Id(14424), "msg:value=%u\n", 200 ); //exp: time:       5_654default: msg:value=200
        break; case __LINE__: TRICE64  ( ID(14425), "msg:value=%u\n", 200 ); //exp: time: 842,150_450default: msg:value=200
        break; case __LINE__: TRICE64_1( ID(14426), "msg:value=%u\n", 200 ); //exp: time: 842,150_450default: msg:value=200
        break; case __LINE__: trice64  ( iD(14427), "msg:value=%u\n", 200 ); //exp: time:            default: msg:value=200
        break; case __LINE__: trice64_1( iD(14428), "msg:value=%u\n", 200 ); //exp: time:            default: msg:value=200
        break; case __LINE__: Trice64  ( iD(14429), "msg:value=%u\n", 200 ); //exp: time:       5_654default: msg:value=200
        break; case __LINE__: Trice64_1( iD(14430), "msg:value=%u\n", 200 ); //exp: time:       5_654default: msg:value=200
        break; case __LINE__: TRice64  ( iD(14431), "msg:value=%u\n", 200 ); //exp: time: 842,150_450default: msg:value=200
        break; case __LINE__: TRice64_1( iD(14432), "msg:value=%u\n", 200 ); //exp: time: 842,150_450default: msg:value=200

        // mixed 16-bit and 32-bit timestamp 

        break; case __LINE__: TRice8( iD(14433), "msg:value=%d\n", -1 );                                                                                            //exp: time: 842,150_450default: msg:value=-1
        break; case __LINE__: Trice8( iD(14434), "msg:value=%d, %d\n", -1, -2 );                                                                                    //exp: time:       5_654default: msg:value=-1, -2
        break; case __LINE__: trice8( iD(14435), "msg:value=%d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time:            default: msg:value=-1, -2, -3
        break; case __LINE__: TRice8( iD(14436), "msg:value=%d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time: 842,150_450default: msg:value=-1, -2, -3, -4
        break; case __LINE__: Trice8( iD(14437), "msg:value=%d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time:       5_654default: msg:value=-1, -2, -3, -4, -5
        break; case __LINE__: trice8( iD(14438), "msg:value=%d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time:            default: msg:value=-1, -2, -3, -4, -5, -6
        break; case __LINE__: TRice8( iD(14439), "msg:value=%d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7 );                                            //exp: time: 842,150_450default: msg:value=-1, -2, -3, -4, -5, -6, -7
        break; case __LINE__: Trice8( iD(14440), "msg:value=%d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time:       5_654default: msg:value=-1, -2, -3, -4, -5, -6, -7, -8 
        break; case __LINE__: trice8( iD(14441), "msg:value=%d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time:            default: msg:value=-1, -2, -3, -4, -5, -6, -7, -8, -9
        break; case __LINE__: TRice8( iD(14442), "msg:value=%d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10 );                   //exp: time: 842,150_450default: msg:value=-1, -2, -3, -4, -5, -6, -7, -8, -9, -10
        break; case __LINE__: Trice8( iD(14443), "msg:value=%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time:       5_654default: msg:value=-1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11
        break; case __LINE__: trice8( iD(14444), "msg:value=%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time:            default: msg:value=-1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12

        break; case __LINE__: TRice16( iD(14445), "msg:value=%d\n", -1 );                                                                                            //exp: time: 842,150_450default: msg:value=-1
        break; case __LINE__: Trice16( iD(14446), "msg:value=%d, %d\n", -1, -2 );                                                                                    //exp: time:       5_654default: msg:value=-1, -2
        break; case __LINE__: trice16( iD(14447), "msg:value=%d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time:            default: msg:value=-1, -2, -3
        break; case __LINE__: TRice16( iD(14448), "msg:value=%d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time: 842,150_450default: msg:value=-1, -2, -3, -4
        break; case __LINE__: Trice16( iD(14449), "msg:value=%d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time:       5_654default: msg:value=-1, -2, -3, -4, -5
        break; case __LINE__: trice16( iD(14450), "msg:value=%d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time:            default: msg:value=-1, -2, -3, -4, -5, -6
        break; case __LINE__: TRice16( iD(14451), "msg:value=%d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7 );                                            //exp: time: 842,150_450default: msg:value=-1, -2, -3, -4, -5, -6, -7
        break; case __LINE__: Trice16( iD(14452), "msg:value=%d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time:       5_654default: msg:value=-1, -2, -3, -4, -5, -6, -7, -8 
        break; case __LINE__: trice16( iD(14453), "msg:value=%d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time:            default: msg:value=-1, -2, -3, -4, -5, -6, -7, -8, -9
        break; case __LINE__: TRice16( iD(14454), "msg:value=%d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10 );                   //exp: time: 842,150_450default: msg:value=-1, -2, -3, -4, -5, -6, -7, -8, -9, -10
        break; case __LINE__: Trice16( iD(14455), "msg:value=%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time:       5_654default: msg:value=-1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11
        break; case __LINE__: trice16( iD(14456), "msg:value=%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time:            default: msg:value=-1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12

        break; case __LINE__: TRice32( iD(14457), "msg:value=%d\n", -1 );                                                                                            //exp: time: 842,150_450default: msg:value=-1
        break; case __LINE__: Trice32( iD(14458), "msg:value=%d, %d\n", -1, -2 );                                                                                    //exp: time:       5_654default: msg:value=-1, -2
        break; case __LINE__: trice32( iD(14459), "msg:value=%d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time:            default: msg:value=-1, -2, -3
        break; case __LINE__: TRice32( iD(14460), "msg:value=%d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time: 842,150_450default: msg:value=-1, -2, -3, -4
        break; case __LINE__: Trice32( iD(14461), "msg:value=%d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time:       5_654default: msg:value=-1, -2, -3, -4, -5
        break; case __LINE__: trice32( iD(14462), "msg:value=%d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time:            default: msg:value=-1, -2, -3, -4, -5, -6
        break; case __LINE__: TRice32( iD(14463), "msg:value=%d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7 );                                            //exp: time: 842,150_450default: msg:value=-1, -2, -3, -4, -5, -6, -7
        break; case __LINE__: Trice32( iD(14464), "msg:value=%d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time:       5_654default: msg:value=-1, -2, -3, -4, -5, -6, -7, -8 
        break; case __LINE__: trice32( iD(14465), "msg:value=%d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time:            default: msg:value=-1, -2, -3, -4, -5, -6, -7, -8, -9
        break; case __LINE__: TRice32( iD(14466), "msg:value=%d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10 );                   //exp: time: 842,150_450default: msg:value=-1, -2, -3, -4, -5, -6, -7, -8, -9, -10
        break; case __LINE__: Trice32( iD(14467), "msg:value=%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time:       5_654default: msg:value=-1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11
        break; case __LINE__: trice32( iD(14468), "msg:value=%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time:            default: msg:value=-1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12

        break; case __LINE__: TRice64( iD(14469), "msg:value=%d\n", -1 );                                                                                            //exp: time: 842,150_450default: msg:value=-1
        break; case __LINE__: Trice64( iD(14470), "msg:value=%d, %d\n", -1, -2 );                                                                                    //exp: time:       5_654default: msg:value=-1, -2
        break; case __LINE__: trice64( iD(14471), "msg:value=%d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time:            default: msg:value=-1, -2, -3
        break; case __LINE__: TRice64( iD(14472), "msg:value=%d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time: 842,150_450default: msg:value=-1, -2, -3, -4
        break; case __LINE__: Trice64( iD(14473), "msg:value=%d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time:       5_654default: msg:value=-1, -2, -3, -4, -5
        break; case __LINE__: trice64( iD(14474), "msg:value=%d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time:            default: msg:value=-1, -2, -3, -4, -5, -6
        break; case __LINE__: TRice64( iD(14475), "msg:value=%d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7 );                                            //exp: time: 842,150_450default: msg:value=-1, -2, -3, -4, -5, -6, -7
        break; case __LINE__: Trice64( iD(14476), "msg:value=%d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time:       5_654default: msg:value=-1, -2, -3, -4, -5, -6, -7, -8 
        break; case __LINE__: trice64( iD(14477), "msg:value=%d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time:            default: msg:value=-1, -2, -3, -4, -5, -6, -7, -8, -9
        break; case __LINE__: TRice64( iD(14478), "msg:value=%d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10 );                   //exp: time: 842,150_450default: msg:value=-1, -2, -3, -4, -5, -6, -7, -8, -9, -10
        break; case __LINE__: Trice64( iD(14479), "msg:value=%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time:       5_654default: msg:value=-1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11
        break; case __LINE__: trice64( iD(14480), "msg:value=%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time:            default: msg:value=-1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12

        break; case __LINE__: TRice8_1 ( iD(14481), "msg:value=%d\n", -1 );                                                                                            //exp: time: 842,150_450default: msg:value=-1
        break; case __LINE__: Trice8_2 ( iD(14482), "msg:value=%d, %d\n", -1, -2 );                                                                                    //exp: time:       5_654default: msg:value=-1, -2
        break; case __LINE__: trice8_3 ( iD(14483), "msg:value=%d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time:            default: msg:value=-1, -2, -3
        break; case __LINE__: TRice8_4 ( iD(14484), "msg:value=%d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time: 842,150_450default: msg:value=-1, -2, -3, -4
        break; case __LINE__: Trice8_5 ( iD(14485), "msg:value=%d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time:       5_654default: msg:value=-1, -2, -3, -4, -5
        break; case __LINE__: trice8_6 ( iD(14486), "msg:value=%d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time:            default: msg:value=-1, -2, -3, -4, -5, -6
        break; case __LINE__: TRice8_7 ( iD(14487), "msg:value=%d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7 );                                            //exp: time: 842,150_450default: msg:value=-1, -2, -3, -4, -5, -6, -7
        break; case __LINE__: Trice8_8 ( iD(14488), "msg:value=%d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time:       5_654default: msg:value=-1, -2, -3, -4, -5, -6, -7, -8 
        break; case __LINE__: trice8_9 ( iD(14489), "msg:value=%d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time:            default: msg:value=-1, -2, -3, -4, -5, -6, -7, -8, -9
        break; case __LINE__: TRice8_10( iD(14490), "msg:value=%d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10 );                   //exp: time: 842,150_450default: msg:value=-1, -2, -3, -4, -5, -6, -7, -8, -9, -10
        break; case __LINE__: Trice8_11( iD(14491), "msg:value=%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time:       5_654default: msg:value=-1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11
        break; case __LINE__: trice8_12( iD(14492), "msg:value=%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time:            default: msg:value=-1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12

        break; case __LINE__: TRice16_1 ( iD(14493), "msg:value=%d\n", -1 );                                                                                            //exp: time: 842,150_450default: msg:value=-1
        break; case __LINE__: Trice16_2 ( iD(14494), "msg:value=%d, %d\n", -1, -2 );                                                                                    //exp: time:       5_654default: msg:value=-1, -2
        break; case __LINE__: trice16_3 ( iD(14495), "msg:value=%d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time:            default: msg:value=-1, -2, -3
        break; case __LINE__: TRice16_4 ( iD(14496), "msg:value=%d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time: 842,150_450default: msg:value=-1, -2, -3, -4
        break; case __LINE__: Trice16_5 ( iD(14497), "msg:value=%d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time:       5_654default: msg:value=-1, -2, -3, -4, -5
        break; case __LINE__: trice16_6 ( iD(14498), "msg:value=%d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time:            default: msg:value=-1, -2, -3, -4, -5, -6
        break; case __LINE__: TRice16_7 ( iD(14499), "msg:value=%d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7 );                                            //exp: time: 842,150_450default: msg:value=-1, -2, -3, -4, -5, -6, -7
        break; case __LINE__: Trice16_8 ( iD(14500), "msg:value=%d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time:       5_654default: msg:value=-1, -2, -3, -4, -5, -6, -7, -8 
        break; case __LINE__: trice16_9 ( iD(14501), "msg:value=%d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time:            default: msg:value=-1, -2, -3, -4, -5, -6, -7, -8, -9
        break; case __LINE__: TRice16_10( iD(14502), "msg:value=%d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10 );                   //exp: time: 842,150_450default: msg:value=-1, -2, -3, -4, -5, -6, -7, -8, -9, -10
        break; case __LINE__: Trice16_11( iD(14503), "msg:value=%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time:       5_654default: msg:value=-1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11
        break; case __LINE__: trice16_12( iD(14504), "msg:value=%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time:            default: msg:value=-1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12

        break; case __LINE__: TRice32_1 ( iD(14505), "msg:value=%d\n", -1 );                                                                                            //exp: time: 842,150_450default: msg:value=-1
        break; case __LINE__: Trice32_2 ( iD(14506), "msg:value=%d, %d\n", -1, -2 );                                                                                    //exp: time:       5_654default: msg:value=-1, -2
        break; case __LINE__: trice32_3 ( iD(14507), "msg:value=%d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time:            default: msg:value=-1, -2, -3
        break; case __LINE__: TRice32_4 ( iD(14508), "msg:value=%d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time: 842,150_450default: msg:value=-1, -2, -3, -4
        break; case __LINE__: Trice32_5 ( iD(14509), "msg:value=%d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time:       5_654default: msg:value=-1, -2, -3, -4, -5
        break; case __LINE__: trice32_6 ( iD(14510), "msg:value=%d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time:            default: msg:value=-1, -2, -3, -4, -5, -6
        break; case __LINE__: TRice32_7 ( iD(14511), "msg:value=%d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7 );                                            //exp: time: 842,150_450default: msg:value=-1, -2, -3, -4, -5, -6, -7
        break; case __LINE__: Trice32_8 ( iD(14512), "msg:value=%d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time:       5_654default: msg:value=-1, -2, -3, -4, -5, -6, -7, -8 
        break; case __LINE__: trice32_9 ( iD(14513), "msg:value=%d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time:            default: msg:value=-1, -2, -3, -4, -5, -6, -7, -8, -9
        break; case __LINE__: TRice32_10( iD(14514), "msg:value=%d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10 );                   //exp: time: 842,150_450default: msg:value=-1, -2, -3, -4, -5, -6, -7, -8, -9, -10
        break; case __LINE__: Trice32_11( iD(14515), "msg:value=%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time:       5_654default: msg:value=-1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11
        break; case __LINE__: trice32_12( iD(14516), "msg:value=%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time:            default: msg:value=-1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12

        break; case __LINE__: TRice64_1 ( iD(14517), "msg:value=%d\n", -1 );                                                                                            //exp: time: 842,150_450default: msg:value=-1
        break; case __LINE__: Trice64_2 ( iD(14518), "msg:value=%d, %d\n", -1, -2 );                                                                                    //exp: time:       5_654default: msg:value=-1, -2
        break; case __LINE__: trice64_3 ( iD(14519), "msg:value=%d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time:            default: msg:value=-1, -2, -3
        break; case __LINE__: TRice64_4 ( iD(14520), "msg:value=%d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time: 842,150_450default: msg:value=-1, -2, -3, -4
        break; case __LINE__: Trice64_5 ( iD(14521), "msg:value=%d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time:       5_654default: msg:value=-1, -2, -3, -4, -5
        break; case __LINE__: trice64_6 ( iD(14522), "msg:value=%d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time:            default: msg:value=-1, -2, -3, -4, -5, -6
        break; case __LINE__: TRice64_7 ( iD(14523), "msg:value=%d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7 );                                            //exp: time: 842,150_450default: msg:value=-1, -2, -3, -4, -5, -6, -7
        break; case __LINE__: Trice64_8 ( iD(14524), "msg:value=%d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time:       5_654default: msg:value=-1, -2, -3, -4, -5, -6, -7, -8 
        break; case __LINE__: trice64_9 ( iD(14525), "msg:value=%d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time:            default: msg:value=-1, -2, -3, -4, -5, -6, -7, -8, -9
        break; case __LINE__: TRice64_10( iD(14526), "msg:value=%d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10 );                   //exp: time: 842,150_450default: msg:value=-1, -2, -3, -4, -5, -6, -7, -8, -9, -10
        break; case __LINE__: Trice64_11( iD(14527), "msg:value=%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time:       5_654default: msg:value=-1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11
        break; case __LINE__: trice64_12( iD(14528), "msg:value=%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time:            default: msg:value=-1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12

        // use cases for 8-bit data
        break; case __LINE__: trice8     ( iD(14559), "value=%d\n", -2  ); //exp: time:            default: value=-2
        break; case __LINE__: Trice8     ( iD(14530), "value=%d\n", -2  ); //exp: time:       5_654default: value=-2
        break; case __LINE__: TRice8     ( iD(14313), "value=%d\n", -2  ); //exp: time: 842,150_450default: value=-2
        break; case __LINE__: trice8_1   ( iD(14330), "value=%d\n", -2  ); //exp: time:            default: value=-2
        break; case __LINE__: Trice8_1   ( iD(14564), "value=%d\n", -2  ); //exp: time:       5_654default: value=-2
        break; case __LINE__: TRice8_1   ( iD(14534), "value=%d\n", -2  ); //exp: time: 842,150_450default: value=-2

        // use cases for 16-bit data
        break; case __LINE__: trice16    ( iD(14535), "value=%d\n", -2  ); //exp: time:            default: value=-2
        break; case __LINE__: Trice16    ( iD(14536), "value=%d\n", -2  ); //exp: time:       5_654default: value=-2
        break; case __LINE__: TRice16    ( iD(14316), "value=%d\n", -2  ); //exp: time: 842,150_450default: value=-2
        break; case __LINE__: trice16_1  ( iD(14333), "value=%d\n", -2  ); //exp: time:            default: value=-2
        break; case __LINE__: Trice16_1  ( iD(14539), "value=%d\n", -2  ); //exp: time:       5_654default: value=-2
        break; case __LINE__: TRice16_1  ( iD(14540), "value=%d\n", -2  ); //exp: time: 842,150_450default: value=-2

        // use cases for 32-bit data
        break; case __LINE__: trice32    ( iD(14321), "value=%d\n", -2  ); //exp: time:            default: value=-2
        break; case __LINE__: Trice32    ( iD(14320), "value=%d\n", -2  ); //exp: time:       5_654default: value=-2
        break; case __LINE__: TRice32    ( iD(14319), "value=%d\n", -2  ); //exp: time: 842,150_450default: value=-2
        break; case __LINE__: trice32_1  ( iD(14544), "value=%d\n", -2  ); //exp: time:            default: value=-2
        break; case __LINE__: Trice32_1  ( iD(14545), "value=%d\n", -2  ); //exp: time:       5_654default: value=-2
        break; case __LINE__: TRice32_1  ( iD(14334), "value=%d\n", -2  ); //exp: time: 842,150_450default: value=-2

        // use cases for 64-bit data
        break; case __LINE__: trice64    ( iD(14547), "value=%d\n", -2  ); //exp: time:            default: value=-2
        break; case __LINE__: Trice64    ( iD(14548), "value=%d\n", -2  ); //exp: time:       5_654default: value=-2
        break; case __LINE__: TRice64    ( iD(14549), "value=%d\n", -2  ); //exp: time: 842,150_450default: value=-2
        break; case __LINE__: trice64_1  ( iD(14339), "value=%d\n", -2  ); //exp: time:            default: value=-2
        break; case __LINE__: Trice64_1  ( iD(14338), "value=%d\n", -2  ); //exp: time:       5_654default: value=-2
        break; case __LINE__: TRice64_1  ( iD(14552), "value=%d\n", -2  ); //exp: time: 842,150_450default: value=-2

        // legacy use cases
        break; case __LINE__: TRICE      ( ID(14556), "value=%d\n", -2 ); //exp: time: 842,150_450default: value=-2
        break; case __LINE__: TRICE      ( id(14553), "value=%d\n", -2 ); //exp: time:            default: value=-2
        break; case __LINE__: TRICE      ( Id(14554), "value=%d\n", -2 ); //exp: time:       5_654default: value=-2
        break; case __LINE__: TRICE      ( ID(14555), "value=%d\n", -2 ); //exp: time: 842,150_450default: value=-2

        // default stamp
        break; case __LINE__: TRICE8     ( ID(14565), "value=%d\n", -2 ); //exp: time: 842,150_450default: value=-2
        break; case __LINE__: TRICE8_1   ( ID(14558), "value=%d\n", -2 ); //exp: time: 842,150_450default: value=-2

        // no stamp
        break; case __LINE__: trice8     ( iD(14529), "value=%d\n", -2 ); //exp: time:            default: value=-2
        break; case __LINE__: trice8_1   ( iD(14560), "value=%d\n", -2 ); //exp: time:            default: value=-2
        break; case __LINE__: TRICE8     ( id(14569), "value=%d\n", -2 ); //exp: time:            default: value=-2
        break; case __LINE__: TRICE8_1   ( id(14562), "value=%d\n", -2 ); //exp: time:            default: value=-2

        // 16-bit stamp:
        break; case __LINE__: Trice8     ( iD(14314), "value=%d\n", -2 ); //exp: time:       5_654default: value=-2
        break; case __LINE__: Trice8_1   ( iD(14329), "value=%d\n", -2 ); //exp: time:       5_654default: value=-2
        break; case __LINE__: TRICE8     ( Id(14561), "value=%d\n", -2 ); //exp: time:       5_654default: value=-2
        break; case __LINE__: TRICE8_1   ( Id(14566), "value=%d\n", -2 ); //exp: time:       5_654default: value=-2

        // 32-bit stamp:
        break; case __LINE__: TRice8     ( iD(14567), "value=%d\n", -2 ); //exp: time: 842,150_450default: value=-2
        break; case __LINE__: TRice8_1   ( iD(14568), "value=%d\n", -2 ); //exp: time: 842,150_450default: value=-2
        break; case __LINE__: TRICE8     ( ID(14557), "value=%d\n", -2 ); //exp: time: 842,150_450default: value=-2
        break; case __LINE__: TRICE8_1   ( ID(14570), "value=%d\n", -2 ); //exp: time: 842,150_450default: value=-2

        // channels
        break; case __LINE__: TRICE( id(14779), "FATAL:magenta+b:red\n" );           //exp: time:            default: FATAL:magenta+b:red
        break; case __LINE__: TRICE( id(14572), "CRITICAL:red+i:default+h\n" );      //exp: time:            default: CRITICAL:red+i:default+h
        break; case __LINE__: TRICE( id(14781), "EMERGENCY:red+i:blue\n" );          //exp: time:            default: EMERGENCY:red+i:blue
        break; case __LINE__: TRICE( id(14678), "ERROR:11:red\n" );                  //exp: time:            default: ERROR:11:red
        break; case __LINE__: TRICE( id(14575), "WARNING:11+i:red\n" );              //exp: time:            default: WARNING:11+i:red
        break; case __LINE__: TRICE( id(14576), "ATTENTION:11:green\n" );            //exp: time:            default: ATTENTION:11:green
        break; case __LINE__: TRICE( id(14577), "INFO:cyan+b:default+h\n" );         //exp: time:            default: INFO:cyan+b:default+h
        break; case __LINE__: TRICE( id(14578), "DEBUG:130+i\n" );                   //exp: time:            default: DEBUG:130+i
        break; case __LINE__: TRICE( id(14579), "TRACE:default+i:default+h\n" );     //exp: time:            default: TRACE:default+i:default+h
        break; case __LINE__: TRICE( id(14788), "TIME:blue+i:blue+h\n" );            //exp: time:            default: TIME:blue+i:blue+h
        break; case __LINE__: TRICE( id(14685), "MESSAGE:green+h:black\n" );         //exp: time:            default: MESSAGE:green+h:black
        break; case __LINE__: TRICE( id(14686), "READ:black+i:yellow+h\n" );         //exp: time:            default: READ:black+i:yellow+h
        break; case __LINE__: TRICE( id(14687), "WRITE:black+u:yellow+h\n" );        //exp: time:            default: WRITE:black+u:yellow+h
        break; case __LINE__: TRICE( id(14584), "RECEIVE:black+h:black\n" );         //exp: time:            default: RECEIVE:black+h:black
        break; case __LINE__: TRICE( id(14689), "TRANSMIT:black:black+h\n" );        //exp: time:            default: TRANSMIT:black:black+h
        break; case __LINE__: TRICE( id(14794), "DIAG:yellow+i:default+h\n" );       //exp: time:            default: DIAG:yellow+i:default+h
        break; case __LINE__: TRICE( id(14587), "INTERRUPT:magenta+i:default+h\n" ); //exp: time:            default: INTERRUPT:magenta+i:default+h
        break; case __LINE__: TRICE( id(14588), "SIGNAL:118+i\n" );                  //exp: time:            default: SIGNAL:118+i
        break; case __LINE__: TRICE( id(14693), "TEST:yellow+h:black\n" );           //exp: time:            default: TEST:yellow+h:black
        break; case __LINE__: TRICE( id(14798), "DEFAULT:off\n" );                   //exp: time:            default: DEFAULT:off
        break; case __LINE__: TRICE( id(14695), "NOTICE:blue:white+h\n" );           //exp: time:            default: NOTICE:blue:white+h
        break; case __LINE__: TRICE( id(14592), "ALERT:magenta:magenta+h\n" );       //exp: time:            default: ALERT:magenta:magenta+h
        break; case __LINE__: TRICE( id(14593), "ASSERT:yellow+i:blue\n" );          //exp: time:            default: ASSERT:yellow+i:blue
        break; case __LINE__: TRICE( id(14802), "ALARM:red+i:white+h\n" );           //exp: time:            default: ALARM:red+i:white+h
        break; case __LINE__: TRICE( id(14803), "CYCLE:blue+i:default+h\n" );        //exp: time:            default: CYCLE:blue+i:default+h
        break; case __LINE__: TRICE( id(14804), "VERBOSE:blue:default\n" );          //exp: time:            default: VERBOSE:blue:default
        break; case __LINE__: TRICE( id(14805), "fatal:magenta+b:red\n" );           //exp: time:            default: fatal:magenta+b:red
        break; case __LINE__: TRICE( id(14806), "critical:red+i:default+h\n" );      //exp: time:            default: critical:red+i:default+h
        break; case __LINE__: TRICE( id(14807), "emergency:red+i:blue\n" );          //exp: time:            default: emergency:red+i:blue
        break; case __LINE__: TRICE( id(14704), "error:11:red\n" );                  //exp: time:            default: error:11:red
        break; case __LINE__: TRICE( id(14601), "warning:11+i:red\n" );              //exp: time:            default: warning:11+i:red
        break; case __LINE__: TRICE( id(14706), "attention:11:green\n" );            //exp: time:            default: attention:11:green
        break; case __LINE__: TRICE( id(14707), "info:cyan+b:default+h\n" );         //exp: time:            default: info:cyan+b:default+h
        break; case __LINE__: TRICE( id(14708), "debug:130+i\n" );                   //exp: time:            default: debug:130+i
        break; case __LINE__: TRICE( id(14709), "trace:default+i:default+h\n" );     //exp: time:            default: trace:default+i:default+h
        break; case __LINE__: TRICE( id(14814), "time:blue+i:blue+h\n" );            //exp: time:            default: time:blue+i:blue+h
        break; case __LINE__: TRICE( id(14607), "message:green+h:black\n" );         //exp: time:            default: message:green+h:black
        break; case __LINE__: TRICE( id(14712), "read:black+i:yellow+h\n" );         //exp: time:            default: read:black+i:yellow+h
        break; case __LINE__: TRICE( id(14609), "write:black+u:yellow+h\n" );        //exp: time:            default: write:black+u:yellow+h
        break; case __LINE__: TRICE( id(14610), "receive:black+h:black\n" );         //exp: time:            default: receive:black+h:black
        break; case __LINE__: TRICE( id(14715), "transmit:black:black+h\n" );        //exp: time:            default: transmit:black:black+h
        break; case __LINE__: TRICE( id(14820), "diag:yellow+i:default+h\n" );       //exp: time:            default: diag:yellow+i:default+h
        break; case __LINE__: TRICE( id(14717), "interrupt:magenta+i:default+h\n" ); //exp: time:            default: interrupt:magenta+i:default+h
        break; case __LINE__: TRICE( id(14822), "signal:118+i\n" );                  //exp: time:            default: signal:118+i
        break; case __LINE__: TRICE( id(14719), "test:yellow+h:black\n" );           //exp: time:            default: test:yellow+h:black
        break; case __LINE__: TRICE( id(14616), "default:off\n" );                   //exp: time:            default: default:off
        break; case __LINE__: TRICE( id(14721), "notice:blue:white+h\n" );           //exp: time:            default: notice:blue:white+h
        break; case __LINE__: TRICE( id(14618), "alert:magenta:magenta+h\n" );       //exp: time:            default: alert:magenta:magenta+h
        break; case __LINE__: TRICE( id(14723), "assert:yellow+i:blue\n" );          //exp: time:            default: assert:yellow+i:blue
        break; case __LINE__: TRICE( id(14724), "alarm:red+i:white+h\n" );           //exp: time:            default: alarm:red+i:white+h
        break; case __LINE__: TRICE( id(14725), "cycle:blue+i:default+h\n" );        //exp: time:            default: cycle:blue+i:default+h
        break; case __LINE__: TRICE( id(14622), "verbose:blue:default\n" );          //exp: time:            default: verbose:blue:default
        
        break; case __LINE__: trice( iD(14623), "FATAL:magenta+b:red\n" );           //exp: time:            default: FATAL:magenta+b:red
        break; case __LINE__: trice( iD(14624), "CRITICAL:red+i:default+h\n" );      //exp: time:            default: CRITICAL:red+i:default+h
        break; case __LINE__: trice( iD(14625), "EMERGENCY:red+i:blue\n" );          //exp: time:            default: EMERGENCY:red+i:blue
        break; case __LINE__: trice( iD(14626), "ERROR:11:red\n" );                  //exp: time:            default: ERROR:11:red
        break; case __LINE__: trice( iD(14627), "WARNING:11+i:red\n" );              //exp: time:            default: WARNING:11+i:red
        break; case __LINE__: trice( iD(14628), "ATTENTION:11:green\n" );            //exp: time:            default: ATTENTION:11:green
        break; case __LINE__: trice( iD(14629), "INFO:cyan+b:default+h\n" );         //exp: time:            default: INFO:cyan+b:default+h
        break; case __LINE__: trice( iD(14630), "DEBUG:130+i\n" );                   //exp: time:            default: DEBUG:130+i
        break; case __LINE__: trice( iD(14631), "TRACE:default+i:default+h\n" );     //exp: time:            default: TRACE:default+i:default+h
        break; case __LINE__: trice( iD(14632), "TIME:blue+i:blue+h\n" );            //exp: time:            default: TIME:blue+i:blue+h
        break; case __LINE__: trice( iD(14633), "MESSAGE:green+h:black\n" );         //exp: time:            default: MESSAGE:green+h:black
        break; case __LINE__: trice( iD(14634), "READ:black+i:yellow+h\n" );         //exp: time:            default: READ:black+i:yellow+h
        break; case __LINE__: trice( iD(14635), "WRITE:black+u:yellow+h\n" );        //exp: time:            default: WRITE:black+u:yellow+h
        break; case __LINE__: trice( iD(14636), "RECEIVE:black+h:black\n" );         //exp: time:            default: RECEIVE:black+h:black
        break; case __LINE__: trice( iD(14637), "TRANSMIT:black:black+h\n" );        //exp: time:            default: TRANSMIT:black:black+h
        break; case __LINE__: trice( iD(14638), "DIAG:yellow+i:default+h\n" );       //exp: time:            default: DIAG:yellow+i:default+h
        break; case __LINE__: trice( iD(14639), "INTERRUPT:magenta+i:default+h\n" ); //exp: time:            default: INTERRUPT:magenta+i:default+h
        break; case __LINE__: trice( iD(14640), "SIGNAL:118+i\n" );                  //exp: time:            default: SIGNAL:118+i
        break; case __LINE__: trice( iD(14641), "TEST:yellow+h:black\n" );           //exp: time:            default: TEST:yellow+h:black
        break; case __LINE__: trice( iD(14642), "DEFAULT:off\n" );                   //exp: time:            default: DEFAULT:off
        break; case __LINE__: trice( iD(14643), "NOTICE:blue:white+h\n" );           //exp: time:            default: NOTICE:blue:white+h
        break; case __LINE__: trice( iD(14644), "ALERT:magenta:magenta+h\n" );       //exp: time:            default: ALERT:magenta:magenta+h
        break; case __LINE__: trice( iD(14645), "ASSERT:yellow+i:blue\n" );          //exp: time:            default: ASSERT:yellow+i:blue
        break; case __LINE__: trice( iD(14646), "ALARM:red+i:white+h\n" );           //exp: time:            default: ALARM:red+i:white+h
        break; case __LINE__: trice( iD(14647), "CYCLE:blue+i:default+h\n" );        //exp: time:            default: CYCLE:blue+i:default+h
        break; case __LINE__: trice( iD(14648), "VERBOSE:blue:default\n" );          //exp: time:            default: VERBOSE:blue:default
        break; case __LINE__: trice( iD(14649), "fatal:magenta+b:red\n" );           //exp: time:            default: fatal:magenta+b:red
        break; case __LINE__: trice( iD(14650), "critical:red+i:default+h\n" );      //exp: time:            default: critical:red+i:default+h
        break; case __LINE__: trice( iD(14651), "emergency:red+i:blue\n" );          //exp: time:            default: emergency:red+i:blue
        break; case __LINE__: trice( iD(14652), "error:11:red\n" );                  //exp: time:            default: error:11:red
        break; case __LINE__: trice( iD(14653), "warning:11+i:red\n" );              //exp: time:            default: warning:11+i:red
        break; case __LINE__: trice( iD(14654), "attention:11:green\n" );            //exp: time:            default: attention:11:green
        break; case __LINE__: trice( iD(14655), "info:cyan+b:default+h\n" );         //exp: time:            default: info:cyan+b:default+h
        break; case __LINE__: trice( iD(14656), "debug:130+i\n" );                   //exp: time:            default: debug:130+i
        break; case __LINE__: trice( iD(14657), "trace:default+i:default+h\n" );     //exp: time:            default: trace:default+i:default+h
        break; case __LINE__: trice( iD(14658), "time:blue+i:blue+h\n" );            //exp: time:            default: time:blue+i:blue+h
        break; case __LINE__: trice( iD(14659), "message:green+h:black\n" );         //exp: time:            default: message:green+h:black
        break; case __LINE__: trice( iD(14660), "read:black+i:yellow+h\n" );         //exp: time:            default: read:black+i:yellow+h
        break; case __LINE__: trice( iD(14661), "write:black+u:yellow+h\n" );        //exp: time:            default: write:black+u:yellow+h
        break; case __LINE__: trice( iD(14662), "receive:black+h:black\n" );         //exp: time:            default: receive:black+h:black
        break; case __LINE__: trice( iD(14663), "transmit:black:black+h\n" );        //exp: time:            default: transmit:black:black+h
        break; case __LINE__: trice( iD(14664), "diag:yellow+i:default+h\n" );       //exp: time:            default: diag:yellow+i:default+h
        break; case __LINE__: trice( iD(14665), "interrupt:magenta+i:default+h\n" ); //exp: time:            default: interrupt:magenta+i:default+h
        break; case __LINE__: trice( iD(14666), "signal:118+i\n" );                  //exp: time:            default: signal:118+i
        break; case __LINE__: trice( iD(14667), "test:yellow+h:black\n" );           //exp: time:            default: test:yellow+h:black
        break; case __LINE__: trice( iD(14668), "default:off\n" );                   //exp: time:            default: default:off
        break; case __LINE__: trice( iD(14669), "notice:blue:white+h\n" );           //exp: time:            default: notice:blue:white+h
        break; case __LINE__: trice( iD(14670), "alert:magenta:magenta+h\n" );       //exp: time:            default: alert:magenta:magenta+h
        break; case __LINE__: trice( iD(14671), "assert:yellow+i:blue\n" );          //exp: time:            default: assert:yellow+i:blue
        break; case __LINE__: trice( iD(14672), "alarm:red+i:white+h\n" );           //exp: time:            default: alarm:red+i:white+h
        break; case __LINE__: trice( iD(14673), "cycle:blue+i:default+h\n" );        //exp: time:            default: cycle:blue+i:default+h
        break; case __LINE__: trice( iD(14674), "verbose:blue:default\n" );          //exp: time:            default: verbose:blue:default

        break; case __LINE__: TRICE( Id(14571), "FATAL:magenta+b:red\n" );           //exp: time:       5_654default: FATAL:magenta+b:red
        break; case __LINE__: TRICE( Id(14780), "CRITICAL:red+i:default+h\n" );      //exp: time:       5_654default: CRITICAL:red+i:default+h
        break; case __LINE__: TRICE( Id(14677), "EMERGENCY:red+i:blue\n" );          //exp: time:       5_654default: EMERGENCY:red+i:blue
        break; case __LINE__: TRICE( Id(14782), "ERROR:11:red\n" );                  //exp: time:       5_654default: ERROR:11:red
        break; case __LINE__: TRICE( Id(14679), "WARNING:11+i:red\n" );              //exp: time:       5_654default: WARNING:11+i:red
        break; case __LINE__: TRICE( Id(14680), "ATTENTION:11:green\n" );            //exp: time:       5_654default: ATTENTION:11:green
        break; case __LINE__: TRICE( Id(14785), "INFO:cyan+b:default+h\n" );         //exp: time:       5_654default: INFO:cyan+b:default+h
        break; case __LINE__: TRICE( Id(14786), "DEBUG:130+i\n" );                   //exp: time:       5_654default: DEBUG:130+i
        break; case __LINE__: TRICE( Id(14683), "TRACE:default+i:default+h\n" );     //exp: time:       5_654default: TRACE:default+i:default+h
        break; case __LINE__: TRICE( Id(14684), "TIME:blue+i:blue+h\n" );            //exp: time:       5_654default: TIME:blue+i:blue+h
        break; case __LINE__: TRICE( Id(14789), "MESSAGE:green+h:black\n" );         //exp: time:       5_654default: MESSAGE:green+h:black
        break; case __LINE__: TRICE( Id(14582), "READ:black+i:yellow+h\n" );         //exp: time:       5_654default: READ:black+i:yellow+h
        break; case __LINE__: TRICE( Id(14583), "WRITE:black+u:yellow+h\n" );        //exp: time:       5_654default: WRITE:black+u:yellow+h
        break; case __LINE__: TRICE( Id(14792), "RECEIVE:black+h:black\n" );         //exp: time:       5_654default: RECEIVE:black+h:black
        break; case __LINE__: TRICE( Id(14793), "TRANSMIT:black:black+h\n" );        //exp: time:       5_654default: TRANSMIT:black:black+h
        break; case __LINE__: TRICE( Id(14586), "DIAG:yellow+i:default+h\n" );       //exp: time:       5_654default: DIAG:yellow+i:default+h
        break; case __LINE__: TRICE( Id(14691), "INTERRUPT:magenta+i:default+h\n" ); //exp: time:       5_654default: INTERRUPT:magenta+i:default+h
        break; case __LINE__: TRICE( Id(14796), "SIGNAL:118+i\n" );                  //exp: time:       5_654default: SIGNAL:118+i
        break; case __LINE__: TRICE( Id(14589), "TEST:yellow+h:black\n" );           //exp: time:       5_654default: TEST:yellow+h:black
        break; case __LINE__: TRICE( Id(14694), "DEFAULT:off\n" );                   //exp: time:       5_654default: DEFAULT:off
        break; case __LINE__: TRICE( Id(14799), "NOTICE:blue:white+h\n" );           //exp: time:       5_654default: NOTICE:blue:white+h
        break; case __LINE__: TRICE( Id(14800), "ALERT:magenta:magenta+h\n" );       //exp: time:       5_654default: ALERT:magenta:magenta+h
        break; case __LINE__: TRICE( Id(14801), "ASSERT:yellow+i:blue\n" );          //exp: time:       5_654default: ASSERT:yellow+i:blue
        break; case __LINE__: TRICE( Id(14594), "ALARM:red+i:white+h\n" );           //exp: time:       5_654default: ALARM:red+i:white+h
        break; case __LINE__: TRICE( Id(14699), "CYCLE:blue+i:default+h\n" );        //exp: time:       5_654default: CYCLE:blue+i:default+h
        break; case __LINE__: TRICE( Id(14700), "VERBOSE:blue:default\n" );          //exp: time:       5_654default: VERBOSE:blue:default
        break; case __LINE__: TRICE( Id(14597), "fatal:magenta+b:red\n" );           //exp: time:       5_654default: fatal:magenta+b:red
        break; case __LINE__: TRICE( Id(14702), "critical:red+i:default+h\n" );      //exp: time:       5_654default: critical:red+i:default+h
        break; case __LINE__: TRICE( Id(14599), "emergency:red+i:blue\n" );          //exp: time:       5_654default: emergency:red+i:blue
        break; case __LINE__: TRICE( Id(14808), "error:11:red\n" );                  //exp: time:       5_654default: error:11:red
        break; case __LINE__: TRICE( Id(14705), "warning:11+i:red\n" );              //exp: time:       5_654default: warning:11+i:red
        break; case __LINE__: TRICE( Id(14810), "attention:11:green\n" );            //exp: time:       5_654default: attention:11:green
        break; case __LINE__: TRICE( Id(14603), "info:cyan+b:default+h\n" );         //exp: time:       5_654default: info:cyan+b:default+h
        break; case __LINE__: TRICE( Id(14812), "debug:130+i\n" );                   //exp: time:       5_654default: debug:130+i
        break; case __LINE__: TRICE( Id(14813), "trace:default+i:default+h\n" );     //exp: time:       5_654default: trace:default+i:default+h
        break; case __LINE__: TRICE( Id(14606), "time:blue+i:blue+h\n" );            //exp: time:       5_654default: time:blue+i:blue+h
        break; case __LINE__: TRICE( Id(14815), "message:green+h:black\n" );         //exp: time:       5_654default: message:green+h:black
        break; case __LINE__: TRICE( Id(14816), "read:black+i:yellow+h\n" );         //exp: time:       5_654default: read:black+i:yellow+h
        break; case __LINE__: TRICE( Id(14713), "write:black+u:yellow+h\n" );        //exp: time:       5_654default: write:black+u:yellow+h
        break; case __LINE__: TRICE( Id(14714), "receive:black+h:black\n" );         //exp: time:       5_654default: receive:black+h:black
        break; case __LINE__: TRICE( Id(14819), "transmit:black:black+h\n" );        //exp: time:       5_654default: transmit:black:black+h
        break; case __LINE__: TRICE( Id(14716), "diag:yellow+i:default+h\n" );       //exp: time:       5_654default: diag:yellow+i:default+h
        break; case __LINE__: TRICE( Id(14821), "interrupt:magenta+i:default+h\n" ); //exp: time:       5_654default: interrupt:magenta+i:default+h
        break; case __LINE__: TRICE( Id(14718), "signal:118+i\n" );                  //exp: time:       5_654default: signal:118+i
        break; case __LINE__: TRICE( Id(14615), "test:yellow+h:black\n" );           //exp: time:       5_654default: test:yellow+h:black
        break; case __LINE__: TRICE( Id(14720), "default:off\n" );                   //exp: time:       5_654default: default:off
        break; case __LINE__: TRICE( Id(14825), "notice:blue:white+h\n" );           //exp: time:       5_654default: notice:blue:white+h
        break; case __LINE__: TRICE( Id(14826), "alert:magenta:magenta+h\n" );       //exp: time:       5_654default: alert:magenta:magenta+h
        break; case __LINE__: TRICE( Id(14619), "assert:yellow+i:blue\n" );          //exp: time:       5_654default: assert:yellow+i:blue
        break; case __LINE__: TRICE( Id(14828), "alarm:red+i:white+h\n" );           //exp: time:       5_654default: alarm:red+i:white+h
        break; case __LINE__: TRICE( Id(14621), "cycle:blue+i:default+h\n" );        //exp: time:       5_654default: cycle:blue+i:default+h
        break; case __LINE__: TRICE( Id(14830), "verbose:blue:default\n" );          //exp: time:       5_654default: verbose:blue:default

        break; case __LINE__: Trice( iD(14727), "FATAL:magenta+b:red\n" );           //exp: time:       5_654default: FATAL:magenta+b:red
        break; case __LINE__: Trice( iD(14728), "CRITICAL:red+i:default+h\n" );      //exp: time:       5_654default: CRITICAL:red+i:default+h
        break; case __LINE__: Trice( iD(14729), "EMERGENCY:red+i:blue\n" );          //exp: time:       5_654default: EMERGENCY:red+i:blue
        break; case __LINE__: Trice( iD(14730), "ERROR:11:red\n" );                  //exp: time:       5_654default: ERROR:11:red
        break; case __LINE__: Trice( iD(14731), "WARNING:11+i:red\n" );              //exp: time:       5_654default: WARNING:11+i:red
        break; case __LINE__: Trice( iD(14732), "ATTENTION:11:green\n" );            //exp: time:       5_654default: ATTENTION:11:green
        break; case __LINE__: Trice( iD(14733), "INFO:cyan+b:default+h\n" );         //exp: time:       5_654default: INFO:cyan+b:default+h
        break; case __LINE__: Trice( iD(14734), "DEBUG:130+i\n" );                   //exp: time:       5_654default: DEBUG:130+i
        break; case __LINE__: Trice( iD(14735), "TRACE:default+i:default+h\n" );     //exp: time:       5_654default: TRACE:default+i:default+h
        break; case __LINE__: Trice( iD(14736), "TIME:blue+i:blue+h\n" );            //exp: time:       5_654default: TIME:blue+i:blue+h
        break; case __LINE__: Trice( iD(14737), "MESSAGE:green+h:black\n" );         //exp: time:       5_654default: MESSAGE:green+h:black
        break; case __LINE__: Trice( iD(14738), "READ:black+i:yellow+h\n" );         //exp: time:       5_654default: READ:black+i:yellow+h
        break; case __LINE__: Trice( iD(14739), "WRITE:black+u:yellow+h\n" );        //exp: time:       5_654default: WRITE:black+u:yellow+h
        break; case __LINE__: Trice( iD(14740), "RECEIVE:black+h:black\n" );         //exp: time:       5_654default: RECEIVE:black+h:black
        break; case __LINE__: Trice( iD(14741), "TRANSMIT:black:black+h\n" );        //exp: time:       5_654default: TRANSMIT:black:black+h
        break; case __LINE__: Trice( iD(14742), "DIAG:yellow+i:default+h\n" );       //exp: time:       5_654default: DIAG:yellow+i:default+h
        break; case __LINE__: Trice( iD(14743), "INTERRUPT:magenta+i:default+h\n" ); //exp: time:       5_654default: INTERRUPT:magenta+i:default+h
        break; case __LINE__: Trice( iD(14744), "SIGNAL:118+i\n" );                  //exp: time:       5_654default: SIGNAL:118+i
        break; case __LINE__: Trice( iD(14745), "TEST:yellow+h:black\n" );           //exp: time:       5_654default: TEST:yellow+h:black
        break; case __LINE__: Trice( iD(14746), "DEFAULT:off\n" );                   //exp: time:       5_654default: DEFAULT:off
        break; case __LINE__: Trice( iD(14747), "NOTICE:blue:white+h\n" );           //exp: time:       5_654default: NOTICE:blue:white+h
        break; case __LINE__: Trice( iD(14748), "ALERT:magenta:magenta+h\n" );       //exp: time:       5_654default: ALERT:magenta:magenta+h
        break; case __LINE__: Trice( iD(14749), "ASSERT:yellow+i:blue\n" );          //exp: time:       5_654default: ASSERT:yellow+i:blue
        break; case __LINE__: Trice( iD(14750), "ALARM:red+i:white+h\n" );           //exp: time:       5_654default: ALARM:red+i:white+h
        break; case __LINE__: Trice( iD(14751), "CYCLE:blue+i:default+h\n" );        //exp: time:       5_654default: CYCLE:blue+i:default+h
        break; case __LINE__: Trice( iD(14752), "VERBOSE:blue:default\n" );          //exp: time:       5_654default: VERBOSE:blue:default
        break; case __LINE__: Trice( iD(14753), "fatal:magenta+b:red\n" );           //exp: time:       5_654default: fatal:magenta+b:red
        break; case __LINE__: Trice( iD(14754), "critical:red+i:default+h\n" );      //exp: time:       5_654default: critical:red+i:default+h
        break; case __LINE__: Trice( iD(14755), "emergency:red+i:blue\n" );          //exp: time:       5_654default: emergency:red+i:blue
        break; case __LINE__: Trice( iD(14756), "error:11:red\n" );                  //exp: time:       5_654default: error:11:red
        break; case __LINE__: Trice( iD(14757), "warning:11+i:red\n" );              //exp: time:       5_654default: warning:11+i:red
        break; case __LINE__: Trice( iD(14758), "attention:11:green\n" );            //exp: time:       5_654default: attention:11:green
        break; case __LINE__: Trice( iD(14759), "info:cyan+b:default+h\n" );         //exp: time:       5_654default: info:cyan+b:default+h
        break; case __LINE__: Trice( iD(14760), "debug:130+i\n" );                   //exp: time:       5_654default: debug:130+i
        break; case __LINE__: Trice( iD(14761), "trace:default+i:default+h\n" );     //exp: time:       5_654default: trace:default+i:default+h
        break; case __LINE__: Trice( iD(14762), "time:blue+i:blue+h\n" );            //exp: time:       5_654default: time:blue+i:blue+h
        break; case __LINE__: Trice( iD(14763), "message:green+h:black\n" );         //exp: time:       5_654default: message:green+h:black
        break; case __LINE__: Trice( iD(14764), "read:black+i:yellow+h\n" );         //exp: time:       5_654default: read:black+i:yellow+h
        break; case __LINE__: Trice( iD(14765), "write:black+u:yellow+h\n" );        //exp: time:       5_654default: write:black+u:yellow+h
        break; case __LINE__: Trice( iD(14766), "receive:black+h:black\n" );         //exp: time:       5_654default: receive:black+h:black
        break; case __LINE__: Trice( iD(14767), "transmit:black:black+h\n" );        //exp: time:       5_654default: transmit:black:black+h
        break; case __LINE__: Trice( iD(14768), "diag:yellow+i:default+h\n" );       //exp: time:       5_654default: diag:yellow+i:default+h
        break; case __LINE__: Trice( iD(14769), "interrupt:magenta+i:default+h\n" ); //exp: time:       5_654default: interrupt:magenta+i:default+h
        break; case __LINE__: Trice( iD(14770), "signal:118+i\n" );                  //exp: time:       5_654default: signal:118+i
        break; case __LINE__: Trice( iD(14771), "test:yellow+h:black\n" );           //exp: time:       5_654default: test:yellow+h:black
        break; case __LINE__: Trice( iD(14772), "default:off\n" );                   //exp: time:       5_654default: default:off
        break; case __LINE__: Trice( iD(14773), "notice:blue:white+h\n" );           //exp: time:       5_654default: notice:blue:white+h
        break; case __LINE__: Trice( iD(14774), "alert:magenta:magenta+h\n" );       //exp: time:       5_654default: alert:magenta:magenta+h
        break; case __LINE__: Trice( iD(14775), "assert:yellow+i:blue\n" );          //exp: time:       5_654default: assert:yellow+i:blue
        break; case __LINE__: Trice( iD(14776), "alarm:red+i:white+h\n" );           //exp: time:       5_654default: alarm:red+i:white+h
        break; case __LINE__: Trice( iD(14777), "cycle:blue+i:default+h\n" );        //exp: time:       5_654default: cycle:blue+i:default+h
        break; case __LINE__: Trice( iD(14778), "verbose:blue:default\n" );          //exp: time:       5_654default: verbose:blue:default

        break; case __LINE__: TRICE( ID(14675), "FATAL:magenta+b:red\n" );           //exp: time: 842,150_450default: FATAL:magenta+b:red
        break; case __LINE__: TRICE( ID(14676), "CRITICAL:red+i:default+h\n" );      //exp: time: 842,150_450default: CRITICAL:red+i:default+h
        break; case __LINE__: TRICE( ID(14573), "EMERGENCY:red+i:blue\n" );          //exp: time: 842,150_450default: EMERGENCY:red+i:blue
        break; case __LINE__: TRICE( ID(14574), "ERROR:11:red\n" );                  //exp: time: 842,150_450default: ERROR:11:red
        break; case __LINE__: TRICE( ID(14783), "WARNING:11+i:red\n" );              //exp: time: 842,150_450default: WARNING:11+i:red
        break; case __LINE__: TRICE( ID(14784), "ATTENTION:11:green\n" );            //exp: time: 842,150_450default: ATTENTION:11:green
        break; case __LINE__: TRICE( ID(14681), "INFO:cyan+b:default+h\n" );         //exp: time: 842,150_450default: INFO:cyan+b:default+h
        break; case __LINE__: TRICE( ID(14682), "DEBUG:130+i\n" );                   //exp: time: 842,150_450default: DEBUG:130+i
        break; case __LINE__: TRICE( ID(14787), "TRACE:default+i:default+h\n" );     //exp: time: 842,150_450default: TRACE:default+i:default+h
        break; case __LINE__: TRICE( ID(14580), "TIME:blue+i:blue+h\n" );            //exp: time: 842,150_450default: TIME:blue+i:blue+h
        break; case __LINE__: TRICE( ID(14581), "MESSAGE:green+h:black\n" );         //exp: time: 842,150_450default: MESSAGE:green+h:black
        break; case __LINE__: TRICE( ID(14790), "READ:black+i:yellow+h\n" );         //exp: time: 842,150_450default: READ:black+i:yellow+h
        break; case __LINE__: TRICE( ID(14791), "WRITE:black+u:yellow+h\n" );        //exp: time: 842,150_450default: WRITE:black+u:yellow+h
        break; case __LINE__: TRICE( ID(14688), "RECEIVE:black+h:black\n" );         //exp: time: 842,150_450default: RECEIVE:black+h:black
        break; case __LINE__: TRICE( ID(14585), "TRANSMIT:black:black+h\n" );        //exp: time: 842,150_450default: TRANSMIT:black:black+h
        break; case __LINE__: TRICE( ID(14690), "DIAG:yellow+i:default+h\n" );       //exp: time: 842,150_450default: DIAG:yellow+i:default+h
        break; case __LINE__: TRICE( ID(14795), "INTERRUPT:magenta+i:default+h\n" ); //exp: time: 842,150_450default: INTERRUPT:magenta+i:default+h
        break; case __LINE__: TRICE( ID(14692), "SIGNAL:118+i\n" );                  //exp: time: 842,150_450default: SIGNAL:118+i
        break; case __LINE__: TRICE( ID(14797), "TEST:yellow+h:black\n" );           //exp: time: 842,150_450default: TEST:yellow+h:black
        break; case __LINE__: TRICE( ID(14590), "DEFAULT:off\n" );                   //exp: time: 842,150_450default: DEFAULT:off
        break; case __LINE__: TRICE( ID(14591), "NOTICE:blue:white+h\n" );           //exp: time: 842,150_450default: NOTICE:blue:white+h
        break; case __LINE__: TRICE( ID(14696), "ALERT:magenta:magenta+h\n" );       //exp: time: 842,150_450default: ALERT:magenta:magenta+h
        break; case __LINE__: TRICE( ID(14697), "ASSERT:yellow+i:blue\n" );          //exp: time: 842,150_450default: ASSERT:yellow+i:blue
        break; case __LINE__: TRICE( ID(14698), "ALARM:red+i:white+h\n" );           //exp: time: 842,150_450default: ALARM:red+i:white+h
        break; case __LINE__: TRICE( ID(14595), "CYCLE:blue+i:default+h\n" );        //exp: time: 842,150_450default: CYCLE:blue+i:default+h
        break; case __LINE__: TRICE( ID(14596), "VERBOSE:blue:default\n" );          //exp: time: 842,150_450default: VERBOSE:blue:default
        break; case __LINE__: TRICE( ID(14701), "fatal:magenta+b:red\n" );           //exp: time: 842,150_450default: fatal:magenta+b:red
        break; case __LINE__: TRICE( ID(14598), "critical:red+i:default+h\n" );      //exp: time: 842,150_450default: critical:red+i:default+h
        break; case __LINE__: TRICE( ID(14703), "emergency:red+i:blue\n" );          //exp: time: 842,150_450default: emergency:red+i:blue
        break; case __LINE__: TRICE( ID(14600), "error:11:red\n" );                  //exp: time: 842,150_450default: error:11:red
        break; case __LINE__: TRICE( ID(14809), "warning:11+i:red\n" );              //exp: time: 842,150_450default: warning:11+i:red
        break; case __LINE__: TRICE( ID(14602), "attention:11:green\n" );            //exp: time: 842,150_450default: attention:11:green
        break; case __LINE__: TRICE( ID(14811), "info:cyan+b:default+h\n" );         //exp: time: 842,150_450default: info:cyan+b:default+h
        break; case __LINE__: TRICE( ID(14604), "debug:130+i\n" );                   //exp: time: 842,150_450default: debug:130+i
        break; case __LINE__: TRICE( ID(14605), "trace:default+i:default+h\n" );     //exp: time: 842,150_450default: trace:default+i:default+h
        break; case __LINE__: TRICE( ID(14710), "time:blue+i:blue+h\n" );            //exp: time: 842,150_450default: time:blue+i:blue+h
        break; case __LINE__: TRICE( ID(14711), "message:green+h:black\n" );         //exp: time: 842,150_450default: message:green+h:black
        break; case __LINE__: TRICE( ID(14608), "read:black+i:yellow+h\n" );         //exp: time: 842,150_450default: read:black+i:yellow+h
        break; case __LINE__: TRICE( ID(14817), "write:black+u:yellow+h\n" );        //exp: time: 842,150_450default: write:black+u:yellow+h
        break; case __LINE__: TRICE( ID(14818), "receive:black+h:black\n" );         //exp: time: 842,150_450default: receive:black+h:black
        break; case __LINE__: TRICE( ID(14611), "transmit:black:black+h\n" );        //exp: time: 842,150_450default: transmit:black:black+h
        break; case __LINE__: TRICE( ID(14612), "diag:yellow+i:default+h\n" );       //exp: time: 842,150_450default: diag:yellow+i:default+h
        break; case __LINE__: TRICE( ID(14613), "interrupt:magenta+i:default+h\n" ); //exp: time: 842,150_450default: interrupt:magenta+i:default+h
        break; case __LINE__: TRICE( ID(14614), "signal:118+i\n" );                  //exp: time: 842,150_450default: signal:118+i
        break; case __LINE__: TRICE( ID(14823), "test:yellow+h:black\n" );           //exp: time: 842,150_450default: test:yellow+h:black
        break; case __LINE__: TRICE( ID(14824), "default:off\n" );                   //exp: time: 842,150_450default: default:off
        break; case __LINE__: TRICE( ID(14617), "notice:blue:white+h\n" );           //exp: time: 842,150_450default: notice:blue:white+h
        break; case __LINE__: TRICE( ID(14722), "alert:magenta:magenta+h\n" );       //exp: time: 842,150_450default: alert:magenta:magenta+h
        break; case __LINE__: TRICE( ID(14827), "assert:yellow+i:blue\n" );          //exp: time: 842,150_450default: assert:yellow+i:blue
        break; case __LINE__: TRICE( ID(14620), "alarm:red+i:white+h\n" );           //exp: time: 842,150_450default: alarm:red+i:white+h
        break; case __LINE__: TRICE( ID(14829), "cycle:blue+i:default+h\n" );        //exp: time: 842,150_450default: cycle:blue+i:default+h
        break; case __LINE__: TRICE( ID(14726), "verbose:blue:default\n" );          //exp: time: 842,150_450default: verbose:blue:default
        
        break; case __LINE__: TRice( iD(14831), "FATAL:magenta+b:red\n" );           //exp: time: 842,150_450default: FATAL:magenta+b:red
        break; case __LINE__: TRice( iD(14832), "CRITICAL:red+i:default+h\n" );      //exp: time: 842,150_450default: CRITICAL:red+i:default+h
        break; case __LINE__: TRice( iD(14833), "EMERGENCY:red+i:blue\n" );          //exp: time: 842,150_450default: EMERGENCY:red+i:blue
        break; case __LINE__: TRice( iD(14834), "ERROR:11:red\n" );                  //exp: time: 842,150_450default: ERROR:11:red
        break; case __LINE__: TRice( iD(14835), "WARNING:11+i:red\n" );              //exp: time: 842,150_450default: WARNING:11+i:red
        break; case __LINE__: TRice( iD(14836), "ATTENTION:11:green\n" );            //exp: time: 842,150_450default: ATTENTION:11:green
        break; case __LINE__: TRice( iD(14837), "INFO:cyan+b:default+h\n" );         //exp: time: 842,150_450default: INFO:cyan+b:default+h
        break; case __LINE__: TRice( iD(14838), "DEBUG:130+i\n" );                   //exp: time: 842,150_450default: DEBUG:130+i
        break; case __LINE__: TRice( iD(14839), "TRACE:default+i:default+h\n" );     //exp: time: 842,150_450default: TRACE:default+i:default+h
        break; case __LINE__: TRice( iD(14840), "TIME:blue+i:blue+h\n" );            //exp: time: 842,150_450default: TIME:blue+i:blue+h
        break; case __LINE__: TRice( iD(14841), "MESSAGE:green+h:black\n" );         //exp: time: 842,150_450default: MESSAGE:green+h:black
        break; case __LINE__: TRice( iD(14842), "READ:black+i:yellow+h\n" );         //exp: time: 842,150_450default: READ:black+i:yellow+h
        break; case __LINE__: TRice( iD(14843), "WRITE:black+u:yellow+h\n" );        //exp: time: 842,150_450default: WRITE:black+u:yellow+h
        break; case __LINE__: TRice( iD(14844), "RECEIVE:black+h:black\n" );         //exp: time: 842,150_450default: RECEIVE:black+h:black
        break; case __LINE__: TRice( iD(14845), "TRANSMIT:black:black+h\n" );        //exp: time: 842,150_450default: TRANSMIT:black:black+h
        break; case __LINE__: TRice( iD(14846), "DIAG:yellow+i:default+h\n" );       //exp: time: 842,150_450default: DIAG:yellow+i:default+h
        break; case __LINE__: TRice( iD(14847), "INTERRUPT:magenta+i:default+h\n" ); //exp: time: 842,150_450default: INTERRUPT:magenta+i:default+h
        break; case __LINE__: TRice( iD(14848), "SIGNAL:118+i\n" );                  //exp: time: 842,150_450default: SIGNAL:118+i
        break; case __LINE__: TRice( iD(14849), "TEST:yellow+h:black\n" );           //exp: time: 842,150_450default: TEST:yellow+h:black
        break; case __LINE__: TRice( iD(14850), "DEFAULT:off\n" );                   //exp: time: 842,150_450default: DEFAULT:off
        break; case __LINE__: TRice( iD(14851), "NOTICE:blue:white+h\n" );           //exp: time: 842,150_450default: NOTICE:blue:white+h
        break; case __LINE__: TRice( iD(14852), "ALERT:magenta:magenta+h\n" );       //exp: time: 842,150_450default: ALERT:magenta:magenta+h
        break; case __LINE__: TRice( iD(14853), "ASSERT:yellow+i:blue\n" );          //exp: time: 842,150_450default: ASSERT:yellow+i:blue
        break; case __LINE__: TRice( iD(14854), "ALARM:red+i:white+h\n" );           //exp: time: 842,150_450default: ALARM:red+i:white+h
        break; case __LINE__: TRice( iD(14855), "CYCLE:blue+i:default+h\n" );        //exp: time: 842,150_450default: CYCLE:blue+i:default+h
        break; case __LINE__: TRice( iD(14856), "VERBOSE:blue:default\n" );          //exp: time: 842,150_450default: VERBOSE:blue:default
        break; case __LINE__: TRice( iD(14857), "fatal:magenta+b:red\n" );           //exp: time: 842,150_450default: fatal:magenta+b:red
        break; case __LINE__: TRice( iD(14858), "critical:red+i:default+h\n" );      //exp: time: 842,150_450default: critical:red+i:default+h
        break; case __LINE__: TRice( iD(14859), "emergency:red+i:blue\n" );          //exp: time: 842,150_450default: emergency:red+i:blue
        break; case __LINE__: TRice( iD(14860), "error:11:red\n" );                  //exp: time: 842,150_450default: error:11:red
        break; case __LINE__: TRice( iD(14861), "warning:11+i:red\n" );              //exp: time: 842,150_450default: warning:11+i:red
        break; case __LINE__: TRice( iD(14862), "attention:11:green\n" );            //exp: time: 842,150_450default: attention:11:green
        break; case __LINE__: TRice( iD(14863), "info:cyan+b:default+h\n" );         //exp: time: 842,150_450default: info:cyan+b:default+h
        break; case __LINE__: TRice( iD(14864), "debug:130+i\n" );                   //exp: time: 842,150_450default: debug:130+i
        break; case __LINE__: TRice( iD(14865), "trace:default+i:default+h\n" );     //exp: time: 842,150_450default: trace:default+i:default+h
        break; case __LINE__: TRice( iD(14866), "time:blue+i:blue+h\n" );            //exp: time: 842,150_450default: time:blue+i:blue+h
        break; case __LINE__: TRice( iD(14867), "message:green+h:black\n" );         //exp: time: 842,150_450default: message:green+h:black
        break; case __LINE__: TRice( iD(14868), "read:black+i:yellow+h\n" );         //exp: time: 842,150_450default: read:black+i:yellow+h
        break; case __LINE__: TRice( iD(14869), "write:black+u:yellow+h\n" );        //exp: time: 842,150_450default: write:black+u:yellow+h
        break; case __LINE__: TRice( iD(14870), "receive:black+h:black\n" );         //exp: time: 842,150_450default: receive:black+h:black
        break; case __LINE__: TRice( iD(14871), "transmit:black:black+h\n" );        //exp: time: 842,150_450default: transmit:black:black+h
        break; case __LINE__: TRice( iD(14872), "diag:yellow+i:default+h\n" );       //exp: time: 842,150_450default: diag:yellow+i:default+h
        break; case __LINE__: TRice( iD(14873), "interrupt:magenta+i:default+h\n" ); //exp: time: 842,150_450default: interrupt:magenta+i:default+h
        break; case __LINE__: TRice( iD(14874), "signal:118+i\n" );                  //exp: time: 842,150_450default: signal:118+i
        break; case __LINE__: TRice( iD(14875), "test:yellow+h:black\n" );           //exp: time: 842,150_450default: test:yellow+h:black
        break; case __LINE__: TRice( iD(14876), "default:off\n" );                   //exp: time: 842,150_450default: default:off
        break; case __LINE__: TRice( iD(14877), "notice:blue:white+h\n" );           //exp: time: 842,150_450default: notice:blue:white+h
        break; case __LINE__: TRice( iD(14878), "alert:magenta:magenta+h\n" );       //exp: time: 842,150_450default: alert:magenta:magenta+h
        break; case __LINE__: TRice( iD(14879), "assert:yellow+i:blue\n" );          //exp: time: 842,150_450default: assert:yellow+i:blue
        break; case __LINE__: TRice( iD(14880), "alarm:red+i:white+h\n" );           //exp: time: 842,150_450default: alarm:red+i:white+h
        break; case __LINE__: TRice( iD(14881), "cycle:blue+i:default+h\n" );        //exp: time: 842,150_450default: cycle:blue+i:default+h
        break; case __LINE__: TRice( iD(14882), "verbose:blue:default\n" );          //exp: time: 842,150_450default: verbose:blue:default

   
   
        break; case __LINE__: TRICE64( id(14883), "msg:%d (%%d)\n", -1 );            //exp: time:            default: msg:-1 (%d)

        break; case __LINE__: trice( iD(15032), "sig:TRICE8 with 1 to 12 values\n" );

        break; case __LINE__: TRICE( id(14897), "rd:TRICE %d\n", -1 );                                                                                            //exp: time:            default: rd:TRICE -1     
        break; case __LINE__: TRICE( id(16003), "rd:TRICE %d, %d\n", -1, -2 );                                                                                    //exp: time:            default: rd:TRICE -1, -2 
        break; case __LINE__: TRICE( id(14887), "rd:TRICE %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time:            default: rd:TRICE -1, -2, -3       
        break; case __LINE__: TRICE( id(14900), "rd:TRICE %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time:            default: rd:TRICE -1, -2, -3, -4      
        break; case __LINE__: TRICE( id(14913), "rd:TRICE %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time:            default: rd:TRICE -1, -2, -3, -4, -5        
        break; case __LINE__: TRICE( id(14914), "rd:TRICE %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time:            default: rd:TRICE -1, -2, -3, -4, -5, -6        
        break; case __LINE__: TRICE( id(16008), "rd:TRICE %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time:            default: rd:TRICE -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: TRICE( id(14904), "rd:TRICE %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time:            default: rd:TRICE -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: TRICE( id(14917), "rd:TRICE %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time:            default: rd:TRICE -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: TRICE( id(14894), "rd:TRICE %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time:            default: rd:TRICE -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: TRICE( id(14895), "rd:TRICE %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time:            default: rd:TRICE -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: TRICE( id(14920), "rd:TRICE %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time:            default: rd:TRICE -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    
        break; case __LINE__: TRICE( Id(14909), "rd:TRICE %d\n", -1 );                                                                                            //exp: time:       5_654default: rd:TRICE -1     
        break; case __LINE__: TRICE( Id(14910), "rd:TRICE %d, %d\n", -1, -2 );                                                                                    //exp: time:       5_654default: rd:TRICE -1, -2 
        break; case __LINE__: TRICE( Id(14899), "rd:TRICE %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time:       5_654default: rd:TRICE -1, -2, -3       
        break; case __LINE__: TRICE( Id(14912), "rd:TRICE %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time:       5_654default: rd:TRICE -1, -2, -3, -4      
        break; case __LINE__: TRICE( Id(14889), "rd:TRICE %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time:       5_654default: rd:TRICE -1, -2, -3, -4, -5        
        break; case __LINE__: TRICE( Id(16007), "rd:TRICE %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time:       5_654default: rd:TRICE -1, -2, -3, -4, -5, -6        
        break; case __LINE__: TRICE( Id(14891), "rd:TRICE %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time:       5_654default: rd:TRICE -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: TRICE( Id(14892), "rd:TRICE %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time:       5_654default: rd:TRICE -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: TRICE( Id(14893), "rd:TRICE %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time:       5_654default: rd:TRICE -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: TRICE( Id(14918), "rd:TRICE %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time:       5_654default: rd:TRICE -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: TRICE( Id(16012), "rd:TRICE %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time:       5_654default: rd:TRICE -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: TRICE( Id(16013), "rd:TRICE %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time:       5_654default: rd:TRICE -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    
        break; case __LINE__: TRICE( ID(14885), "rd:TRICE %d\n", -1 );                                                                                            //exp: time: 842,150_450default: rd:TRICE -1     
        break; case __LINE__: TRICE( ID(14886), "rd:TRICE %d, %d\n", -1, -2 );                                                                                    //exp: time: 842,150_450default: rd:TRICE -1, -2 
        break; case __LINE__: TRICE( ID(14911), "rd:TRICE %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time: 842,150_450default: rd:TRICE -1, -2, -3       
        break; case __LINE__: TRICE( ID(16005), "rd:TRICE %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time: 842,150_450default: rd:TRICE -1, -2, -3, -4      
        break; case __LINE__: TRICE( ID(16006), "rd:TRICE %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time: 842,150_450default: rd:TRICE -1, -2, -3, -4, -5        
        break; case __LINE__: TRICE( ID(14890), "rd:TRICE %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time: 842,150_450default: rd:TRICE -1, -2, -3, -4, -5, -6        
        break; case __LINE__: TRICE( ID(14903), "rd:TRICE %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time: 842,150_450default: rd:TRICE -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: TRICE( ID(14916), "rd:TRICE %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time: 842,150_450default: rd:TRICE -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: TRICE( ID(16010), "rd:TRICE %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time: 842,150_450default: rd:TRICE -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: TRICE( ID(14906), "rd:TRICE %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time: 842,150_450default: rd:TRICE -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: TRICE( ID(14907), "rd:TRICE %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time: 842,150_450default: rd:TRICE -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: TRICE( ID(14896), "rd:TRICE %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time: 842,150_450default: rd:TRICE -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    

        break; case __LINE__: trice( iD(14921), "sig:TRICE_n with 1 to 12 values\n" );

        break; case __LINE__: TRICE_1 ( id(14946), "rd:TRICE_1  %d\n", -1 );                                                                                            //exp: time:            default: rd:TRICE_1  -1     
        break; case __LINE__: TRICE_2 ( id(14923), "rd:TRICE_2  %d, %d\n", -1, -2 );                                                                                    //exp: time:            default: rd:TRICE_2  -1, -2 
        break; case __LINE__: TRICE_3 ( id(14948), "rd:TRICE_3  %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time:            default: rd:TRICE_3  -1, -2, -3       
        break; case __LINE__: TRICE_4 ( id(14937), "rd:TRICE_4  %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time:            default: rd:TRICE_4  -1, -2, -3, -4      
        break; case __LINE__: TRICE_5 ( id(14926), "rd:TRICE_5  %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time:            default: rd:TRICE_5  -1, -2, -3, -4, -5        
        break; case __LINE__: TRICE_6 ( id(14927), "rd:TRICE_6  %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time:            default: rd:TRICE_6  -1, -2, -3, -4, -5, -6        
        break; case __LINE__: TRICE_7 ( id(14940), "rd:TRICE_7  %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time:            default: rd:TRICE_7  -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: TRICE_8 ( id(14953), "rd:TRICE_8  %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time:            default: rd:TRICE_8  -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: TRICE_9 ( id(14930), "rd:TRICE_9  %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time:            default: rd:TRICE_9  -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: TRICE_10( id(14931), "rd:TRICE_10 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time:            default: rd:TRICE_10 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: TRICE_11( id(14932), "rd:TRICE_11 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time:            default: rd:TRICE_11 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: TRICE_12( id(14957), "rd:TRICE_12 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time:            default: rd:TRICE_12 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    
        break; case __LINE__: TRICE_1 ( Id(14934), "rd:TRICE_1  %d\n", -1 );                                                                                            //exp: time:       5_654default: rd:TRICE_1  -1     
        break; case __LINE__: TRICE_2 ( Id(14947), "rd:TRICE_2  %d, %d\n", -1, -2 );                                                                                    //exp: time:       5_654default: rd:TRICE_2  -1, -2 
        break; case __LINE__: TRICE_3 ( Id(14924), "rd:TRICE_3  %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time:       5_654default: rd:TRICE_3  -1, -2, -3       
        break; case __LINE__: TRICE_4 ( Id(14949), "rd:TRICE_4  %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time:       5_654default: rd:TRICE_4  -1, -2, -3, -4      
        break; case __LINE__: TRICE_5 ( Id(14938), "rd:TRICE_5  %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time:       5_654default: rd:TRICE_5  -1, -2, -3, -4, -5        
        break; case __LINE__: TRICE_6 ( Id(14939), "rd:TRICE_6  %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time:       5_654default: rd:TRICE_6  -1, -2, -3, -4, -5, -6        
        break; case __LINE__: TRICE_7 ( Id(14928), "rd:TRICE_7  %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time:       5_654default: rd:TRICE_7  -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: TRICE_8 ( Id(14941), "rd:TRICE_8  %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time:       5_654default: rd:TRICE_8  -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: TRICE_9 ( Id(14954), "rd:TRICE_9  %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time:       5_654default: rd:TRICE_9  -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: TRICE_10( Id(14943), "rd:TRICE_10 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time:       5_654default: rd:TRICE_10 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: TRICE_11( Id(14956), "rd:TRICE_11 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time:       5_654default: rd:TRICE_11 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: TRICE_12( Id(14945), "rd:TRICE_12 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time:       5_654default: rd:TRICE_12 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    
        break; case __LINE__: TRICE_1 ( ID(14922), "rd:TRICE_1  %d\n", -1 );                                                                                            //exp: time: 842,150_450default: rd:TRICE_1  -1     
        break; case __LINE__: TRICE_2 ( ID(14935), "rd:TRICE_2  %d, %d\n", -1, -2 );                                                                                    //exp: time: 842,150_450default: rd:TRICE_2  -1, -2 
        break; case __LINE__: TRICE_3 ( ID(14936), "rd:TRICE_3  %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time: 842,150_450default: rd:TRICE_3  -1, -2, -3       
        break; case __LINE__: TRICE_4 ( ID(14925), "rd:TRICE_4  %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time: 842,150_450default: rd:TRICE_4  -1, -2, -3, -4      
        break; case __LINE__: TRICE_5 ( ID(14950), "rd:TRICE_5  %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time: 842,150_450default: rd:TRICE_5  -1, -2, -3, -4, -5        
        break; case __LINE__: TRICE_6 ( ID(14951), "rd:TRICE_6  %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time: 842,150_450default: rd:TRICE_6  -1, -2, -3, -4, -5, -6        
        break; case __LINE__: TRICE_7 ( ID(14952), "rd:TRICE_7  %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time: 842,150_450default: rd:TRICE_7  -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: TRICE_8 ( ID(14929), "rd:TRICE_8  %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time: 842,150_450default: rd:TRICE_8  -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: TRICE_9 ( ID(14942), "rd:TRICE_9  %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time: 842,150_450default: rd:TRICE_9  -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: TRICE_10( ID(14955), "rd:TRICE_10 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time: 842,150_450default: rd:TRICE_10 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: TRICE_11( ID(14944), "rd:TRICE_11 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time: 842,150_450default: rd:TRICE_11 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: TRICE_12( ID(14933), "rd:TRICE_12 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time: 842,150_450default: rd:TRICE_12 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    

        break; case __LINE__: trice( iD(14958), "sig:trice with 1 to 12 values\n" );
        
        break; case __LINE__: trice( iD(14959), "rd:trice %d\n", -1 );                                                                                            //exp: time:            default: rd:trice -1     
        break; case __LINE__: trice( iD(14960), "rd:trice %d, %d\n", -1, -2 );                                                                                    //exp: time:            default: rd:trice -1, -2 
        break; case __LINE__: trice( iD(14961), "rd:trice %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time:            default: rd:trice -1, -2, -3       
        break; case __LINE__: trice( iD(14962), "rd:trice %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time:            default: rd:trice -1, -2, -3, -4      
        break; case __LINE__: trice( iD(14963), "rd:trice %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time:            default: rd:trice -1, -2, -3, -4, -5        
        break; case __LINE__: trice( iD(14964), "rd:trice %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time:            default: rd:trice -1, -2, -3, -4, -5, -6        
        break; case __LINE__: trice( iD(14965), "rd:trice %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time:            default: rd:trice -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: trice( iD(14966), "rd:trice %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time:            default: rd:trice -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: trice( iD(14967), "rd:trice %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time:            default: rd:trice -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: trice( iD(14968), "rd:trice %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time:            default: rd:trice -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: trice( iD(14969), "rd:trice %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time:            default: rd:trice -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: trice( iD(14970), "rd:trice %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time:            default: rd:trice -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    
        break; case __LINE__: Trice( iD(14971), "rd:Trice %d\n", -1 );                                                                                            //exp: time:       5_654default: rd:Trice -1     
        break; case __LINE__: Trice( iD(14972), "rd:Trice %d, %d\n", -1, -2 );                                                                                    //exp: time:       5_654default: rd:Trice -1, -2 
        break; case __LINE__: Trice( iD(14973), "rd:Trice %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time:       5_654default: rd:Trice -1, -2, -3       
        break; case __LINE__: Trice( iD(14974), "rd:Trice %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time:       5_654default: rd:Trice -1, -2, -3, -4      
        break; case __LINE__: Trice( iD(14975), "rd:Trice %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time:       5_654default: rd:Trice -1, -2, -3, -4, -5        
        break; case __LINE__: Trice( iD(14976), "rd:Trice %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time:       5_654default: rd:Trice -1, -2, -3, -4, -5, -6        
        break; case __LINE__: Trice( iD(14977), "rd:Trice %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time:       5_654default: rd:Trice -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: Trice( iD(14978), "rd:Trice %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time:       5_654default: rd:Trice -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: Trice( iD(14979), "rd:Trice %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time:       5_654default: rd:Trice -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: Trice( iD(14980), "rd:Trice %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time:       5_654default: rd:Trice -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: Trice( iD(14981), "rd:Trice %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time:       5_654default: rd:Trice -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: Trice( iD(14982), "rd:Trice %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time:       5_654default: rd:Trice -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    
        break; case __LINE__: TRice( iD(14983), "rd:TRice %d\n", -1 );                                                                                            //exp: time: 842,150_450default: rd:TRice -1     
        break; case __LINE__: TRice( iD(14984), "rd:TRice %d, %d\n", -1, -2 );                                                                                    //exp: time: 842,150_450default: rd:TRice -1, -2 
        break; case __LINE__: TRice( iD(14985), "rd:TRice %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time: 842,150_450default: rd:TRice -1, -2, -3       
        break; case __LINE__: TRice( iD(14986), "rd:TRice %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time: 842,150_450default: rd:TRice -1, -2, -3, -4      
        break; case __LINE__: TRice( iD(14987), "rd:TRice %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time: 842,150_450default: rd:TRice -1, -2, -3, -4, -5        
        break; case __LINE__: TRice( iD(14988), "rd:TRice %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time: 842,150_450default: rd:TRice -1, -2, -3, -4, -5, -6        
        break; case __LINE__: TRice( iD(14989), "rd:TRice %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time: 842,150_450default: rd:TRice -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: TRice( iD(14990), "rd:TRice %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time: 842,150_450default: rd:TRice -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: TRice( iD(14991), "rd:TRice %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time: 842,150_450default: rd:TRice -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: TRice( iD(14992), "rd:TRice %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time: 842,150_450default: rd:TRice -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: TRice( iD(14993), "rd:TRice %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time: 842,150_450default: rd:TRice -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: TRice( iD(14994), "rd:TRice %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time: 842,150_450default: rd:TRice -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    

        break; case __LINE__: TRICE( ID(14995), "sig:trice_n with 1 to 12 values\n" );

        break; case __LINE__: trice_1 ( iD(14996), "rd:trice_1  %d\n", -1 );                                                                                            //exp: time:            default: rd:trice_1  -1     
        break; case __LINE__: trice_2 ( iD(14997), "rd:trice_2  %d, %d\n", -1, -2 );                                                                                    //exp: time:            default: rd:trice_2  -1, -2 
        break; case __LINE__: trice_3 ( iD(14998), "rd:trice_3  %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time:            default: rd:trice_3  -1, -2, -3       
        break; case __LINE__: trice_4 ( iD(14999), "rd:trice_4  %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time:            default: rd:trice_4  -1, -2, -3, -4      
        break; case __LINE__: trice_5 ( iD(15000), "rd:trice_5  %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time:            default: rd:trice_5  -1, -2, -3, -4, -5        
        break; case __LINE__: trice_6 ( iD(15001), "rd:trice_6  %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time:            default: rd:trice_6  -1, -2, -3, -4, -5, -6        
        break; case __LINE__: trice_7 ( iD(15002), "rd:trice_7  %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time:            default: rd:trice_7  -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: trice_8 ( iD(15003), "rd:trice_8  %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time:            default: rd:trice_8  -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: trice_9 ( iD(15004), "rd:trice_9  %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time:            default: rd:trice_9  -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: trice_10( iD(15005), "rd:trice_10 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time:            default: rd:trice_10 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: trice_11( iD(15006), "rd:trice_11 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time:            default: rd:trice_11 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: trice_12( iD(15007), "rd:trice_12 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time:            default: rd:trice_12 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    
        break; case __LINE__: Trice_1 ( iD(15008), "rd:Trice_1  %d\n", -1 );                                                                                            //exp: time:       5_654default: rd:Trice_1  -1     
        break; case __LINE__: Trice_2 ( iD(15009), "rd:Trice_2  %d, %d\n", -1, -2 );                                                                                    //exp: time:       5_654default: rd:Trice_2  -1, -2 
        break; case __LINE__: Trice_3 ( iD(15010), "rd:Trice_3  %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time:       5_654default: rd:Trice_3  -1, -2, -3       
        break; case __LINE__: Trice_4 ( iD(15011), "rd:Trice_4  %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time:       5_654default: rd:Trice_4  -1, -2, -3, -4      
        break; case __LINE__: Trice_5 ( iD(15012), "rd:Trice_5  %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time:       5_654default: rd:Trice_5  -1, -2, -3, -4, -5        
        break; case __LINE__: Trice_6 ( iD(15013), "rd:Trice_6  %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time:       5_654default: rd:Trice_6  -1, -2, -3, -4, -5, -6        
        break; case __LINE__: Trice_7 ( iD(15014), "rd:Trice_7  %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time:       5_654default: rd:Trice_7  -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: Trice_8 ( iD(15015), "rd:Trice_8  %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time:       5_654default: rd:Trice_8  -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: Trice_9 ( iD(15016), "rd:Trice_9  %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time:       5_654default: rd:Trice_9  -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: Trice_10( iD(15017), "rd:Trice_10 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time:       5_654default: rd:Trice_10 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: Trice_11( iD(15018), "rd:Trice_11 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time:       5_654default: rd:Trice_11 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: Trice_12( iD(15019), "rd:Trice_12 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time:       5_654default: rd:Trice_12 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    
        break; case __LINE__: TRice_1 ( iD(15020), "rd:TRice_1  %d\n", -1 );                                                                                            //exp: time: 842,150_450default: rd:TRice_1  -1     
        break; case __LINE__: TRice_2 ( iD(15021), "rd:TRice_2  %d, %d\n", -1, -2 );                                                                                    //exp: time: 842,150_450default: rd:TRice_2  -1, -2 
        break; case __LINE__: TRice_3 ( iD(15022), "rd:TRice_3  %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time: 842,150_450default: rd:TRice_3  -1, -2, -3       
        break; case __LINE__: TRice_4 ( iD(15023), "rd:TRice_4  %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time: 842,150_450default: rd:TRice_4  -1, -2, -3, -4      
        break; case __LINE__: TRice_5 ( iD(15024), "rd:TRice_5  %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time: 842,150_450default: rd:TRice_5  -1, -2, -3, -4, -5        
        break; case __LINE__: TRice_6 ( iD(15025), "rd:TRice_6  %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time: 842,150_450default: rd:TRice_6  -1, -2, -3, -4, -5, -6        
        break; case __LINE__: TRice_7 ( iD(15026), "rd:TRice_7  %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time: 842,150_450default: rd:TRice_7  -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: TRice_8 ( iD(15027), "rd:TRice_8  %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time: 842,150_450default: rd:TRice_8  -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: TRice_9 ( iD(15028), "rd:TRice_9  %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time: 842,150_450default: rd:TRice_9  -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: TRice_10( iD(15029), "rd:TRice_10 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time: 842,150_450default: rd:TRice_10 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: TRice_11( iD(15030), "rd:TRice_11 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time: 842,150_450default: rd:TRice_11 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: TRice_12( iD(15031), "rd:TRice_12 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time: 842,150_450default: rd:TRice_12 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    

        break; case __LINE__: trice( iD(14884), "sig:TRICE8 with 1 to 12 values\n" );

        break; case __LINE__: TRICE8( id(15045), "rd:TRICE8 %d\n", -1 );                                                                                            //exp: time:            default: rd:TRICE8 -1     
        break; case __LINE__: TRICE8( id(15046), "rd:TRICE8 %d, %d\n", -1, -2 );                                                                                    //exp: time:            default: rd:TRICE8 -1, -2 
        break; case __LINE__: TRICE8( id(15035), "rd:TRICE8 %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time:            default: rd:TRICE8 -1, -2, -3       
        break; case __LINE__: TRICE8( id(15048), "rd:TRICE8 %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time:            default: rd:TRICE8 -1, -2, -3, -4      
        break; case __LINE__: TRICE8( id(15037), "rd:TRICE8 %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time:            default: rd:TRICE8 -1, -2, -3, -4, -5        
        break; case __LINE__: TRICE8( id(15050), "rd:TRICE8 %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time:            default: rd:TRICE8 -1, -2, -3, -4, -5, -6        
        break; case __LINE__: TRICE8( id(15063), "rd:TRICE8 %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time:            default: rd:TRICE8 -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: TRICE8( id(15040), "rd:TRICE8 %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time:            default: rd:TRICE8 -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: TRICE8( id(15041), "rd:TRICE8 %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time:            default: rd:TRICE8 -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: TRICE8( id(15066), "rd:TRICE8 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time:            default: rd:TRICE8 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: TRICE8( id(15043), "rd:TRICE8 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time:            default: rd:TRICE8 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: TRICE8( id(15056), "rd:TRICE8 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time:            default: rd:TRICE8 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    
        break; case __LINE__: TRICE8( Id(15057), "rd:TRICE8 %d\n", -1 );                                                                                            //exp: time:       5_654default: rd:TRICE8 -1     
        break; case __LINE__: TRICE8( Id(15034), "rd:TRICE8 %d, %d\n", -1, -2 );                                                                                    //exp: time:       5_654default: rd:TRICE8 -1, -2 
        break; case __LINE__: TRICE8( Id(15059), "rd:TRICE8 %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time:       5_654default: rd:TRICE8 -1, -2, -3       
        break; case __LINE__: TRICE8( Id(15036), "rd:TRICE8 %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time:       5_654default: rd:TRICE8 -1, -2, -3, -4      
        break; case __LINE__: TRICE8( Id(15061), "rd:TRICE8 %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time:       5_654default: rd:TRICE8 -1, -2, -3, -4, -5        
        break; case __LINE__: TRICE8( Id(15062), "rd:TRICE8 %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time:       5_654default: rd:TRICE8 -1, -2, -3, -4, -5, -6        
        break; case __LINE__: TRICE8( Id(15039), "rd:TRICE8 %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time:       5_654default: rd:TRICE8 -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: TRICE8( Id(15064), "rd:TRICE8 %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time:       5_654default: rd:TRICE8 -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: TRICE8( Id(15053), "rd:TRICE8 %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time:       5_654default: rd:TRICE8 -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: TRICE8( Id(15042), "rd:TRICE8 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time:       5_654default: rd:TRICE8 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: TRICE8( Id(15067), "rd:TRICE8 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time:       5_654default: rd:TRICE8 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: TRICE8( Id(15044), "rd:TRICE8 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time:       5_654default: rd:TRICE8 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    
        break; case __LINE__: TRICE8( ID(15033), "rd:TRICE8 %d\n", -1 );                                                                                            //exp: time: 842,150_450default: rd:TRICE8 -1     
        break; case __LINE__: TRICE8( ID(15058), "rd:TRICE8 %d, %d\n", -1, -2 );                                                                                    //exp: time: 842,150_450default: rd:TRICE8 -1, -2 
        break; case __LINE__: TRICE8( ID(15047), "rd:TRICE8 %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time: 842,150_450default: rd:TRICE8 -1, -2, -3       
        break; case __LINE__: TRICE8( ID(15060), "rd:TRICE8 %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time: 842,150_450default: rd:TRICE8 -1, -2, -3, -4      
        break; case __LINE__: TRICE8( ID(15049), "rd:TRICE8 %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time: 842,150_450default: rd:TRICE8 -1, -2, -3, -4, -5        
        break; case __LINE__: TRICE8( ID(15038), "rd:TRICE8 %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time: 842,150_450default: rd:TRICE8 -1, -2, -3, -4, -5, -6        
        break; case __LINE__: TRICE8( ID(15051), "rd:TRICE8 %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time: 842,150_450default: rd:TRICE8 -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: TRICE8( ID(15052), "rd:TRICE8 %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time: 842,150_450default: rd:TRICE8 -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: TRICE8( ID(15065), "rd:TRICE8 %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time: 842,150_450default: rd:TRICE8 -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: TRICE8( ID(15054), "rd:TRICE8 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time: 842,150_450default: rd:TRICE8 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: TRICE8( ID(15055), "rd:TRICE8 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time: 842,150_450default: rd:TRICE8 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: TRICE8( ID(15068), "rd:TRICE8 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time: 842,150_450default: rd:TRICE8 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    

        break; case __LINE__: trice( iD(15069), "sig:TRICE8_n with 1 to 12 values\n" );

        break; case __LINE__: TRICE8_1 ( id(15070), "rd:TRICE8_1  %d\n", -1 );                                                                                            //exp: time:            default: rd:TRICE8_1  -1     
        break; case __LINE__: TRICE8_2 ( id(15083), "rd:TRICE8_2  %d, %d\n", -1, -2 );                                                                                    //exp: time:            default: rd:TRICE8_2  -1, -2 
        break; case __LINE__: TRICE8_3 ( id(15096), "rd:TRICE8_3  %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time:            default: rd:TRICE8_3  -1, -2, -3       
        break; case __LINE__: TRICE8_4 ( id(15085), "rd:TRICE8_4  %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time:            default: rd:TRICE8_4  -1, -2, -3, -4      
        break; case __LINE__: TRICE8_5 ( id(15086), "rd:TRICE8_5  %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time:            default: rd:TRICE8_5  -1, -2, -3, -4, -5        
        break; case __LINE__: TRICE8_6 ( id(15087), "rd:TRICE8_6  %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time:            default: rd:TRICE8_6  -1, -2, -3, -4, -5, -6        
        break; case __LINE__: TRICE8_7 ( id(15088), "rd:TRICE8_7  %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time:            default: rd:TRICE8_7  -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: TRICE8_8 ( id(15077), "rd:TRICE8_8  %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time:            default: rd:TRICE8_8  -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: TRICE8_9 ( id(15102), "rd:TRICE8_9  %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time:            default: rd:TRICE8_9  -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: TRICE8_10( id(15103), "rd:TRICE8_10 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time:            default: rd:TRICE8_10 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: TRICE8_11( id(15092), "rd:TRICE8_11 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time:            default: rd:TRICE8_11 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: TRICE8_12( id(15093), "rd:TRICE8_12 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time:            default: rd:TRICE8_12 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    
        break; case __LINE__: TRICE8_1 ( Id(15082), "rd:TRICE8_1  %d\n", -1 );                                                                                            //exp: time:       5_654default: rd:TRICE8_1  -1     
        break; case __LINE__: TRICE8_2 ( Id(15095), "rd:TRICE8_2  %d, %d\n", -1, -2 );                                                                                    //exp: time:       5_654default: rd:TRICE8_2  -1, -2 
        break; case __LINE__: TRICE8_3 ( Id(15084), "rd:TRICE8_3  %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time:       5_654default: rd:TRICE8_3  -1, -2, -3       
        break; case __LINE__: TRICE8_4 ( Id(15073), "rd:TRICE8_4  %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time:       5_654default: rd:TRICE8_4  -1, -2, -3, -4      
        break; case __LINE__: TRICE8_5 ( Id(15074), "rd:TRICE8_5  %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time:       5_654default: rd:TRICE8_5  -1, -2, -3, -4, -5        
        break; case __LINE__: TRICE8_6 ( Id(15099), "rd:TRICE8_6  %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time:       5_654default: rd:TRICE8_6  -1, -2, -3, -4, -5, -6        
        break; case __LINE__: TRICE8_7 ( Id(15100), "rd:TRICE8_7  %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time:       5_654default: rd:TRICE8_7  -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: TRICE8_8 ( Id(15089), "rd:TRICE8_8  %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time:       5_654default: rd:TRICE8_8  -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: TRICE8_9 ( Id(15078), "rd:TRICE8_9  %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time:       5_654default: rd:TRICE8_9  -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: TRICE8_10( Id(15091), "rd:TRICE8_10 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time:       5_654default: rd:TRICE8_10 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: TRICE8_11( Id(15104), "rd:TRICE8_11 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time:       5_654default: rd:TRICE8_11 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: TRICE8_12( Id(15105), "rd:TRICE8_12 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time:       5_654default: rd:TRICE8_12 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    
        break; case __LINE__: TRICE8_1 ( ID(15094), "rd:TRICE8_1  %d\n", -1 );                                                                                            //exp: time: 842,150_450default: rd:TRICE8_1  -1     
        break; case __LINE__: TRICE8_2 ( ID(15071), "rd:TRICE8_2  %d, %d\n", -1, -2 );                                                                                    //exp: time: 842,150_450default: rd:TRICE8_2  -1, -2 
        break; case __LINE__: TRICE8_3 ( ID(15072), "rd:TRICE8_3  %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time: 842,150_450default: rd:TRICE8_3  -1, -2, -3       
        break; case __LINE__: TRICE8_4 ( ID(15097), "rd:TRICE8_4  %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time: 842,150_450default: rd:TRICE8_4  -1, -2, -3, -4      
        break; case __LINE__: TRICE8_5 ( ID(15098), "rd:TRICE8_5  %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time: 842,150_450default: rd:TRICE8_5  -1, -2, -3, -4, -5        
        break; case __LINE__: TRICE8_6 ( ID(15075), "rd:TRICE8_6  %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time: 842,150_450default: rd:TRICE8_6  -1, -2, -3, -4, -5, -6        
        break; case __LINE__: TRICE8_7 ( ID(15076), "rd:TRICE8_7  %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time: 842,150_450default: rd:TRICE8_7  -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: TRICE8_8 ( ID(15101), "rd:TRICE8_8  %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time: 842,150_450default: rd:TRICE8_8  -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: TRICE8_9 ( ID(15090), "rd:TRICE8_9  %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time: 842,150_450default: rd:TRICE8_9  -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: TRICE8_10( ID(15079), "rd:TRICE8_10 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time: 842,150_450default: rd:TRICE8_10 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: TRICE8_11( ID(15080), "rd:TRICE8_11 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time: 842,150_450default: rd:TRICE8_11 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: TRICE8_12( ID(15081), "rd:TRICE8_12 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time: 842,150_450default: rd:TRICE8_12 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    

        break; case __LINE__: trice( iD(15106), "sig:trice8 with 1 to 12 values\n" );
        
        break; case __LINE__: trice8( iD(15107), "rd:trice8 %d\n", -1 );                                                                                            //exp: time:            default: rd:trice8 -1     
        break; case __LINE__: trice8( iD(15108), "rd:trice8 %d, %d\n", -1, -2 );                                                                                    //exp: time:            default: rd:trice8 -1, -2 
        break; case __LINE__: trice8( iD(15109), "rd:trice8 %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time:            default: rd:trice8 -1, -2, -3       
        break; case __LINE__: trice8( iD(15110), "rd:trice8 %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time:            default: rd:trice8 -1, -2, -3, -4      
        break; case __LINE__: trice8( iD(15111), "rd:trice8 %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time:            default: rd:trice8 -1, -2, -3, -4, -5        
        break; case __LINE__: trice8( iD(15112), "rd:trice8 %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time:            default: rd:trice8 -1, -2, -3, -4, -5, -6        
        break; case __LINE__: trice8( iD(15113), "rd:trice8 %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time:            default: rd:trice8 -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: trice8( iD(15114), "rd:trice8 %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time:            default: rd:trice8 -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: trice8( iD(15115), "rd:trice8 %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time:            default: rd:trice8 -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: trice8( iD(15116), "rd:trice8 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time:            default: rd:trice8 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: trice8( iD(15117), "rd:trice8 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time:            default: rd:trice8 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: trice8( iD(15118), "rd:trice8 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time:            default: rd:trice8 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    
        break; case __LINE__: Trice8( iD(15119), "rd:Trice8 %d\n", -1 );                                                                                            //exp: time:       5_654default: rd:Trice8 -1     
        break; case __LINE__: Trice8( iD(15120), "rd:Trice8 %d, %d\n", -1, -2 );                                                                                    //exp: time:       5_654default: rd:Trice8 -1, -2 
        break; case __LINE__: Trice8( iD(15121), "rd:Trice8 %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time:       5_654default: rd:Trice8 -1, -2, -3       
        break; case __LINE__: Trice8( iD(15122), "rd:Trice8 %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time:       5_654default: rd:Trice8 -1, -2, -3, -4      
        break; case __LINE__: Trice8( iD(15123), "rd:Trice8 %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time:       5_654default: rd:Trice8 -1, -2, -3, -4, -5        
        break; case __LINE__: Trice8( iD(15124), "rd:Trice8 %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time:       5_654default: rd:Trice8 -1, -2, -3, -4, -5, -6        
        break; case __LINE__: Trice8( iD(15125), "rd:Trice8 %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time:       5_654default: rd:Trice8 -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: Trice8( iD(15126), "rd:Trice8 %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time:       5_654default: rd:Trice8 -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: Trice8( iD(15127), "rd:Trice8 %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time:       5_654default: rd:Trice8 -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: Trice8( iD(15128), "rd:Trice8 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time:       5_654default: rd:Trice8 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: Trice8( iD(15129), "rd:Trice8 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time:       5_654default: rd:Trice8 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: Trice8( iD(15130), "rd:Trice8 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time:       5_654default: rd:Trice8 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    
        break; case __LINE__: TRice8( iD(15131), "rd:TRice8 %d\n", -1 );                                                                                            //exp: time: 842,150_450default: rd:TRice8 -1     
        break; case __LINE__: TRice8( iD(15132), "rd:TRice8 %d, %d\n", -1, -2 );                                                                                    //exp: time: 842,150_450default: rd:TRice8 -1, -2 
        break; case __LINE__: TRice8( iD(15133), "rd:TRice8 %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time: 842,150_450default: rd:TRice8 -1, -2, -3       
        break; case __LINE__: TRice8( iD(15134), "rd:TRice8 %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time: 842,150_450default: rd:TRice8 -1, -2, -3, -4      
        break; case __LINE__: TRice8( iD(15135), "rd:TRice8 %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time: 842,150_450default: rd:TRice8 -1, -2, -3, -4, -5        
        break; case __LINE__: TRice8( iD(15136), "rd:TRice8 %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time: 842,150_450default: rd:TRice8 -1, -2, -3, -4, -5, -6        
        break; case __LINE__: TRice8( iD(15137), "rd:TRice8 %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time: 842,150_450default: rd:TRice8 -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: TRice8( iD(15138), "rd:TRice8 %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time: 842,150_450default: rd:TRice8 -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: TRice8( iD(15139), "rd:TRice8 %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time: 842,150_450default: rd:TRice8 -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: TRice8( iD(15140), "rd:TRice8 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time: 842,150_450default: rd:TRice8 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: TRice8( iD(15141), "rd:TRice8 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time: 842,150_450default: rd:TRice8 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: TRice8( iD(15142), "rd:TRice8 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time: 842,150_450default: rd:TRice8 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    

        break; case __LINE__: TRICE( ID(15143), "sig:trice8_n with 1 to 12 values\n" );

        break; case __LINE__: trice8_1 ( iD(15144), "rd:trice8_1  %d\n", -1 );                                                                                            //exp: time:            default: rd:trice8_1  -1     
        break; case __LINE__: trice8_2 ( iD(15145), "rd:trice8_2  %d, %d\n", -1, -2 );                                                                                    //exp: time:            default: rd:trice8_2  -1, -2 
        break; case __LINE__: trice8_3 ( iD(15146), "rd:trice8_3  %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time:            default: rd:trice8_3  -1, -2, -3       
        break; case __LINE__: trice8_4 ( iD(15147), "rd:trice8_4  %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time:            default: rd:trice8_4  -1, -2, -3, -4      
        break; case __LINE__: trice8_5 ( iD(15148), "rd:trice8_5  %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time:            default: rd:trice8_5  -1, -2, -3, -4, -5        
        break; case __LINE__: trice8_6 ( iD(15149), "rd:trice8_6  %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time:            default: rd:trice8_6  -1, -2, -3, -4, -5, -6        
        break; case __LINE__: trice8_7 ( iD(15150), "rd:trice8_7  %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time:            default: rd:trice8_7  -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: trice8_8 ( iD(15151), "rd:trice8_8  %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time:            default: rd:trice8_8  -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: trice8_9 ( iD(15152), "rd:trice8_9  %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time:            default: rd:trice8_9  -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: trice8_10( iD(15153), "rd:trice8_10 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time:            default: rd:trice8_10 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: trice8_11( iD(15154), "rd:trice8_11 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time:            default: rd:trice8_11 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: trice8_12( iD(15155), "rd:trice8_12 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time:            default: rd:trice8_12 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    
        break; case __LINE__: Trice8_1 ( iD(15156), "rd:Trice8_1  %d\n", -1 );                                                                                            //exp: time:       5_654default: rd:Trice8_1  -1     
        break; case __LINE__: Trice8_2 ( iD(15157), "rd:Trice8_2  %d, %d\n", -1, -2 );                                                                                    //exp: time:       5_654default: rd:Trice8_2  -1, -2 
        break; case __LINE__: Trice8_3 ( iD(15158), "rd:Trice8_3  %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time:       5_654default: rd:Trice8_3  -1, -2, -3       
        break; case __LINE__: Trice8_4 ( iD(15159), "rd:Trice8_4  %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time:       5_654default: rd:Trice8_4  -1, -2, -3, -4      
        break; case __LINE__: Trice8_5 ( iD(15160), "rd:Trice8_5  %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time:       5_654default: rd:Trice8_5  -1, -2, -3, -4, -5        
        break; case __LINE__: Trice8_6 ( iD(15161), "rd:Trice8_6  %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time:       5_654default: rd:Trice8_6  -1, -2, -3, -4, -5, -6        
        break; case __LINE__: Trice8_7 ( iD(15162), "rd:Trice8_7  %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time:       5_654default: rd:Trice8_7  -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: Trice8_8 ( iD(15163), "rd:Trice8_8  %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time:       5_654default: rd:Trice8_8  -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: Trice8_9 ( iD(15164), "rd:Trice8_9  %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time:       5_654default: rd:Trice8_9  -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: Trice8_10( iD(15165), "rd:Trice8_10 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time:       5_654default: rd:Trice8_10 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: Trice8_11( iD(15166), "rd:Trice8_11 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time:       5_654default: rd:Trice8_11 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: Trice8_12( iD(15167), "rd:Trice8_12 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time:       5_654default: rd:Trice8_12 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    
        break; case __LINE__: TRice8_1 ( iD(15168), "rd:TRice8_1  %d\n", -1 );                                                                                            //exp: time: 842,150_450default: rd:TRice8_1  -1     
        break; case __LINE__: TRice8_2 ( iD(15169), "rd:TRice8_2  %d, %d\n", -1, -2 );                                                                                    //exp: time: 842,150_450default: rd:TRice8_2  -1, -2 
        break; case __LINE__: TRice8_3 ( iD(15170), "rd:TRice8_3  %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time: 842,150_450default: rd:TRice8_3  -1, -2, -3       
        break; case __LINE__: TRice8_4 ( iD(15171), "rd:TRice8_4  %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time: 842,150_450default: rd:TRice8_4  -1, -2, -3, -4      
        break; case __LINE__: TRice8_5 ( iD(15172), "rd:TRice8_5  %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time: 842,150_450default: rd:TRice8_5  -1, -2, -3, -4, -5        
        break; case __LINE__: TRice8_6 ( iD(15173), "rd:TRice8_6  %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time: 842,150_450default: rd:TRice8_6  -1, -2, -3, -4, -5, -6        
        break; case __LINE__: TRice8_7 ( iD(15174), "rd:TRice8_7  %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time: 842,150_450default: rd:TRice8_7  -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: TRice8_8 ( iD(15175), "rd:TRice8_8  %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time: 842,150_450default: rd:TRice8_8  -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: TRice8_9 ( iD(15176), "rd:TRice8_9  %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time: 842,150_450default: rd:TRice8_9  -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: TRice8_10( iD(15177), "rd:TRice8_10 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time: 842,150_450default: rd:TRice8_10 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: TRice8_11( iD(15178), "rd:TRice8_11 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time: 842,150_450default: rd:TRice8_11 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: TRice8_12( iD(15179), "rd:TRice8_12 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time: 842,150_450default: rd:TRice8_12 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    

        break; case __LINE__: trice( iD(15180), "sig:TRICE16 with 1 to 12 values (line %d)\n", __LINE__ );

        break; case __LINE__: TRICE16( id(15193), "rd:TRICE16 %d\n", -1 );                                                                                            //exp: time:            default: rd:TRICE16 -1     
        break; case __LINE__: TRICE16( id(15182), "rd:TRICE16 %d, %d\n", -1, -2 );                                                                                    //exp: time:            default: rd:TRICE16 -1, -2 
        break; case __LINE__: TRICE16( id(15207), "rd:TRICE16 %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time:            default: rd:TRICE16 -1, -2, -3       
        break; case __LINE__: TRICE16( id(15184), "rd:TRICE16 %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time:            default: rd:TRICE16 -1, -2, -3, -4      
        break; case __LINE__: TRICE16( id(15197), "rd:TRICE16 %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time:            default: rd:TRICE16 -1, -2, -3, -4, -5        
        break; case __LINE__: TRICE16( id(15198), "rd:TRICE16 %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time:            default: rd:TRICE16 -1, -2, -3, -4, -5, -6        
        break; case __LINE__: TRICE16( id(15187), "rd:TRICE16 %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time:            default: rd:TRICE16 -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: TRICE16( id(15212), "rd:TRICE16 %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time:            default: rd:TRICE16 -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: TRICE16( id(15189), "rd:TRICE16 %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time:            default: rd:TRICE16 -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: TRICE16( id(15202), "rd:TRICE16 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time:            default: rd:TRICE16 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: TRICE16( id(15191), "rd:TRICE16 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time:            default: rd:TRICE16 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: TRICE16( id(15216), "rd:TRICE16 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time:            default: rd:TRICE16 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    
        break; case __LINE__: TRICE16( Id(15205), "rd:TRICE16 %d\n", -1 );                                                                                            //exp: time:       5_654default: rd:TRICE16 -1     
        break; case __LINE__: TRICE16( Id(15206), "rd:TRICE16 %d, %d\n", -1, -2 );                                                                                    //exp: time:       5_654default: rd:TRICE16 -1, -2 
        break; case __LINE__: TRICE16( Id(15195), "rd:TRICE16 %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time:       5_654default: rd:TRICE16 -1, -2, -3       
        break; case __LINE__: TRICE16( Id(15208), "rd:TRICE16 %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time:       5_654default: rd:TRICE16 -1, -2, -3, -4      
        break; case __LINE__: TRICE16( Id(15209), "rd:TRICE16 %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time:       5_654default: rd:TRICE16 -1, -2, -3, -4, -5        
        break; case __LINE__: TRICE16( Id(15186), "rd:TRICE16 %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time:       5_654default: rd:TRICE16 -1, -2, -3, -4, -5, -6        
        break; case __LINE__: TRICE16( Id(15211), "rd:TRICE16 %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time:       5_654default: rd:TRICE16 -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: TRICE16( Id(15200), "rd:TRICE16 %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time:       5_654default: rd:TRICE16 -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: TRICE16( Id(15201), "rd:TRICE16 %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time:       5_654default: rd:TRICE16 -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: TRICE16( Id(15214), "rd:TRICE16 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time:       5_654default: rd:TRICE16 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: TRICE16( Id(15215), "rd:TRICE16 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time:       5_654default: rd:TRICE16 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: TRICE16( Id(15192), "rd:TRICE16 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time:       5_654default: rd:TRICE16 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    
        break; case __LINE__: TRICE16( ID(15181), "rd:TRICE16 %d\n", -1 );                                                                                            //exp: time: 842,150_450default: rd:TRICE16 -1     
        break; case __LINE__: TRICE16( ID(15194), "rd:TRICE16 %d, %d\n", -1, -2 );                                                                                    //exp: time: 842,150_450default: rd:TRICE16 -1, -2 
        break; case __LINE__: TRICE16( ID(15183), "rd:TRICE16 %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time: 842,150_450default: rd:TRICE16 -1, -2, -3       
        break; case __LINE__: TRICE16( ID(15196), "rd:TRICE16 %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time: 842,150_450default: rd:TRICE16 -1, -2, -3, -4      
        break; case __LINE__: TRICE16( ID(15185), "rd:TRICE16 %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time: 842,150_450default: rd:TRICE16 -1, -2, -3, -4, -5        
        break; case __LINE__: TRICE16( ID(15210), "rd:TRICE16 %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time: 842,150_450default: rd:TRICE16 -1, -2, -3, -4, -5, -6        
        break; case __LINE__: TRICE16( ID(15199), "rd:TRICE16 %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time: 842,150_450default: rd:TRICE16 -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: TRICE16( ID(15188), "rd:TRICE16 %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time: 842,150_450default: rd:TRICE16 -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: TRICE16( ID(15213), "rd:TRICE16 %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time: 842,150_450default: rd:TRICE16 -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: TRICE16( ID(15190), "rd:TRICE16 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time: 842,150_450default: rd:TRICE16 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: TRICE16( ID(15203), "rd:TRICE16 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time: 842,150_450default: rd:TRICE16 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: TRICE16( ID(15204), "rd:TRICE16 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time: 842,150_450default: rd:TRICE16 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    

        break; case __LINE__: trice     ( iD(15217), "sig:TRICE16_n with 1 to 12 values (line %d)\n", __LINE__ );
        
        break; case __LINE__: TRICE16_1 ( id(15242), "rd:TRICE16_1  %d\n", -1 );                                                                                            //exp: time:            default: rd:TRICE16_1  -1     
        break; case __LINE__: TRICE16_2 ( id(15219), "rd:TRICE16_2  %d, %d\n", -1, -2 );                                                                                    //exp: time:            default: rd:TRICE16_2  -1, -2 
        break; case __LINE__: TRICE16_3 ( id(15220), "rd:TRICE16_3  %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time:            default: rd:TRICE16_3  -1, -2, -3       
        break; case __LINE__: TRICE16_4 ( id(15233), "rd:TRICE16_4  %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time:            default: rd:TRICE16_4  -1, -2, -3, -4      
        break; case __LINE__: TRICE16_5 ( id(15234), "rd:TRICE16_5  %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time:            default: rd:TRICE16_5  -1, -2, -3, -4, -5        
        break; case __LINE__: TRICE16_6 ( id(15247), "rd:TRICE16_6  %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time:            default: rd:TRICE16_6  -1, -2, -3, -4, -5, -6        
        break; case __LINE__: TRICE16_7 ( id(15236), "rd:TRICE16_7  %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time:            default: rd:TRICE16_7  -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: TRICE16_8 ( id(15237), "rd:TRICE16_8  %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time:            default: rd:TRICE16_8  -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: TRICE16_9 ( id(15238), "rd:TRICE16_9  %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time:            default: rd:TRICE16_9  -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: TRICE16_10( id(15251), "rd:TRICE16_10 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time:            default: rd:TRICE16_10 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: TRICE16_11( id(15240), "rd:TRICE16_11 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time:            default: rd:TRICE16_11 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: TRICE16_12( id(15229), "rd:TRICE16_12 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time:            default: rd:TRICE16_12 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    
        break; case __LINE__: TRICE16_1 ( Id(15230), "rd:TRICE16_1  %d\n", -1 );                                                                                            //exp: time:       5_654default: rd:TRICE16_1  -1     
        break; case __LINE__: TRICE16_2 ( Id(15243), "rd:TRICE16_2  %d, %d\n", -1, -2 );                                                                                    //exp: time:       5_654default: rd:TRICE16_2  -1, -2 
        break; case __LINE__: TRICE16_3 ( Id(15244), "rd:TRICE16_3  %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time:       5_654default: rd:TRICE16_3  -1, -2, -3       
        break; case __LINE__: TRICE16_4 ( Id(15245), "rd:TRICE16_4  %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time:       5_654default: rd:TRICE16_4  -1, -2, -3, -4      
        break; case __LINE__: TRICE16_5 ( Id(15222), "rd:TRICE16_5  %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time:       5_654default: rd:TRICE16_5  -1, -2, -3, -4, -5        
        break; case __LINE__: TRICE16_6 ( Id(15235), "rd:TRICE16_6  %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time:       5_654default: rd:TRICE16_6  -1, -2, -3, -4, -5, -6        
        break; case __LINE__: TRICE16_7 ( Id(15224), "rd:TRICE16_7  %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time:       5_654default: rd:TRICE16_7  -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: TRICE16_8 ( Id(15249), "rd:TRICE16_8  %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time:       5_654default: rd:TRICE16_8  -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: TRICE16_9 ( Id(15226), "rd:TRICE16_9  %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time:       5_654default: rd:TRICE16_9  -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: TRICE16_10( Id(15227), "rd:TRICE16_10 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time:       5_654default: rd:TRICE16_10 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: TRICE16_11( Id(15228), "rd:TRICE16_11 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time:       5_654default: rd:TRICE16_11 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: TRICE16_12( Id(15253), "rd:TRICE16_12 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time:       5_654default: rd:TRICE16_12 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    
        break; case __LINE__: TRICE16_1 ( ID(15218), "rd:TRICE16_1  %d\n", -1 );                                                                                            //exp: time: 842,150_450default: rd:TRICE16_1  -1     
        break; case __LINE__: TRICE16_2 ( ID(15231), "rd:TRICE16_2  %d, %d\n", -1, -2 );                                                                                    //exp: time: 842,150_450default: rd:TRICE16_2  -1, -2 
        break; case __LINE__: TRICE16_3 ( ID(15232), "rd:TRICE16_3  %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time: 842,150_450default: rd:TRICE16_3  -1, -2, -3       
        break; case __LINE__: TRICE16_4 ( ID(15221), "rd:TRICE16_4  %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time: 842,150_450default: rd:TRICE16_4  -1, -2, -3, -4      
        break; case __LINE__: TRICE16_5 ( ID(15246), "rd:TRICE16_5  %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time: 842,150_450default: rd:TRICE16_5  -1, -2, -3, -4, -5        
        break; case __LINE__: TRICE16_6 ( ID(15223), "rd:TRICE16_6  %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time: 842,150_450default: rd:TRICE16_6  -1, -2, -3, -4, -5, -6        
        break; case __LINE__: TRICE16_7 ( ID(15248), "rd:TRICE16_7  %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time: 842,150_450default: rd:TRICE16_7  -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: TRICE16_8 ( ID(15225), "rd:TRICE16_8  %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time: 842,150_450default: rd:TRICE16_8  -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: TRICE16_9 ( ID(15250), "rd:TRICE16_9  %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time: 842,150_450default: rd:TRICE16_9  -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: TRICE16_10( ID(15239), "rd:TRICE16_10 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time: 842,150_450default: rd:TRICE16_10 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: TRICE16_11( ID(15252), "rd:TRICE16_11 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time: 842,150_450default: rd:TRICE16_11 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: TRICE16_12( ID(15241), "rd:TRICE16_12 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time: 842,150_450default: rd:TRICE16_12 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    

        break; case __LINE__: trice( iD(15254), "sig:trice16 with 1 to 12 values (line %d)\n", __LINE__ );

        break; case __LINE__: trice16( iD(15255), "rd:trice16 %d\n", -1 );                                                                                            //exp: time:            default: rd:trice16 -1     
        break; case __LINE__: trice16( iD(15256), "rd:trice16 %d, %d\n", -1, -2 );                                                                                    //exp: time:            default: rd:trice16 -1, -2 
        break; case __LINE__: trice16( iD(15257), "rd:trice16 %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time:            default: rd:trice16 -1, -2, -3       
        break; case __LINE__: trice16( iD(15258), "rd:trice16 %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time:            default: rd:trice16 -1, -2, -3, -4      
        break; case __LINE__: trice16( iD(15259), "rd:trice16 %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time:            default: rd:trice16 -1, -2, -3, -4, -5        
        break; case __LINE__: trice16( iD(15260), "rd:trice16 %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time:            default: rd:trice16 -1, -2, -3, -4, -5, -6        
        break; case __LINE__: trice16( iD(15261), "rd:trice16 %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time:            default: rd:trice16 -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: trice16( iD(15262), "rd:trice16 %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time:            default: rd:trice16 -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: trice16( iD(15263), "rd:trice16 %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time:            default: rd:trice16 -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: trice16( iD(15264), "rd:trice16 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time:            default: rd:trice16 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: trice16( iD(15265), "rd:trice16 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time:            default: rd:trice16 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: trice16( iD(15266), "rd:trice16 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time:            default: rd:trice16 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    
        break; case __LINE__: Trice16( iD(15267), "rd:Trice16 %d\n", -1 );                                                                                            //exp: time:       5_654default: rd:Trice16 -1     
        break; case __LINE__: Trice16( iD(15268), "rd:Trice16 %d, %d\n", -1, -2 );                                                                                    //exp: time:       5_654default: rd:Trice16 -1, -2 
        break; case __LINE__: Trice16( iD(15269), "rd:Trice16 %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time:       5_654default: rd:Trice16 -1, -2, -3       
        break; case __LINE__: Trice16( iD(15270), "rd:Trice16 %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time:       5_654default: rd:Trice16 -1, -2, -3, -4      
        break; case __LINE__: Trice16( iD(15271), "rd:Trice16 %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time:       5_654default: rd:Trice16 -1, -2, -3, -4, -5        
        break; case __LINE__: Trice16( iD(15272), "rd:Trice16 %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time:       5_654default: rd:Trice16 -1, -2, -3, -4, -5, -6        
        break; case __LINE__: Trice16( iD(15273), "rd:Trice16 %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time:       5_654default: rd:Trice16 -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: Trice16( iD(15274), "rd:Trice16 %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time:       5_654default: rd:Trice16 -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: Trice16( iD(15275), "rd:Trice16 %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time:       5_654default: rd:Trice16 -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: Trice16( iD(15276), "rd:Trice16 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time:       5_654default: rd:Trice16 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: Trice16( iD(15277), "rd:Trice16 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time:       5_654default: rd:Trice16 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: Trice16( iD(15278), "rd:Trice16 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time:       5_654default: rd:Trice16 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    
        break; case __LINE__: TRice16( iD(15279), "rd:TRice16 %d\n", -1 );                                                                                            //exp: time: 842,150_450default: rd:TRice16 -1     
        break; case __LINE__: TRice16( iD(15280), "rd:TRice16 %d, %d\n", -1, -2 );                                                                                    //exp: time: 842,150_450default: rd:TRice16 -1, -2 
        break; case __LINE__: TRice16( iD(15281), "rd:TRice16 %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time: 842,150_450default: rd:TRice16 -1, -2, -3       
        break; case __LINE__: TRice16( iD(15282), "rd:TRice16 %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time: 842,150_450default: rd:TRice16 -1, -2, -3, -4      
        break; case __LINE__: TRice16( iD(15283), "rd:TRice16 %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time: 842,150_450default: rd:TRice16 -1, -2, -3, -4, -5        
        break; case __LINE__: TRice16( iD(15284), "rd:TRice16 %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time: 842,150_450default: rd:TRice16 -1, -2, -3, -4, -5, -6        
        break; case __LINE__: TRice16( iD(15285), "rd:TRice16 %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time: 842,150_450default: rd:TRice16 -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: TRice16( iD(15286), "rd:TRice16 %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time: 842,150_450default: rd:TRice16 -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: TRice16( iD(15287), "rd:TRice16 %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time: 842,150_450default: rd:TRice16 -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: TRice16( iD(15288), "rd:TRice16 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time: 842,150_450default: rd:TRice16 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: TRice16( iD(15289), "rd:TRice16 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time: 842,150_450default: rd:TRice16 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: TRice16( iD(15290), "rd:TRice16 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time: 842,150_450default: rd:TRice16 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    

        break; case __LINE__: trice     ( iD(15291), "sig:trice16_n with 1 to 12 values (line %d)\n", __LINE__ );
        
        break; case __LINE__: trice16_1 ( iD(15292), "rd:trice16_1  %d\n", -1 );                                                                                            //exp: time:            default: rd:trice16_1  -1     
        break; case __LINE__: trice16_2 ( iD(15293), "rd:trice16_2  %d, %d\n", -1, -2 );                                                                                    //exp: time:            default: rd:trice16_2  -1, -2 
        break; case __LINE__: trice16_3 ( iD(15294), "rd:trice16_3  %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time:            default: rd:trice16_3  -1, -2, -3       
        break; case __LINE__: trice16_4 ( iD(15295), "rd:trice16_4  %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time:            default: rd:trice16_4  -1, -2, -3, -4      
        break; case __LINE__: trice16_5 ( iD(15296), "rd:trice16_5  %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time:            default: rd:trice16_5  -1, -2, -3, -4, -5        
        break; case __LINE__: trice16_6 ( iD(15297), "rd:trice16_6  %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time:            default: rd:trice16_6  -1, -2, -3, -4, -5, -6        
        break; case __LINE__: trice16_7 ( iD(15298), "rd:trice16_7  %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time:            default: rd:trice16_7  -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: trice16_8 ( iD(15299), "rd:trice16_8  %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time:            default: rd:trice16_8  -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: trice16_9 ( iD(15300), "rd:trice16_9  %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time:            default: rd:trice16_9  -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: trice16_10( iD(15301), "rd:trice16_10 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time:            default: rd:trice16_10 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: trice16_11( iD(15302), "rd:trice16_11 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time:            default: rd:trice16_11 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: trice16_12( iD(15303), "rd:trice16_12 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time:            default: rd:trice16_12 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    
        break; case __LINE__: Trice16_1 ( iD(15304), "rd:Trice16_1  %d\n", -1 );                                                                                            //exp: time:       5_654default: rd:Trice16_1  -1     
        break; case __LINE__: Trice16_2 ( iD(15305), "rd:Trice16_2  %d, %d\n", -1, -2 );                                                                                    //exp: time:       5_654default: rd:Trice16_2  -1, -2 
        break; case __LINE__: Trice16_3 ( iD(15306), "rd:Trice16_3  %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time:       5_654default: rd:Trice16_3  -1, -2, -3       
        break; case __LINE__: Trice16_4 ( iD(15307), "rd:Trice16_4  %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time:       5_654default: rd:Trice16_4  -1, -2, -3, -4      
        break; case __LINE__: Trice16_5 ( iD(15308), "rd:Trice16_5  %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time:       5_654default: rd:Trice16_5  -1, -2, -3, -4, -5        
        break; case __LINE__: Trice16_6 ( iD(15309), "rd:Trice16_6  %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time:       5_654default: rd:Trice16_6  -1, -2, -3, -4, -5, -6        
        break; case __LINE__: Trice16_7 ( iD(15310), "rd:Trice16_7  %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time:       5_654default: rd:Trice16_7  -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: Trice16_8 ( iD(15311), "rd:Trice16_8  %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time:       5_654default: rd:Trice16_8  -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: Trice16_9 ( iD(15312), "rd:Trice16_9  %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time:       5_654default: rd:Trice16_9  -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: Trice16_10( iD(15313), "rd:Trice16_10 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time:       5_654default: rd:Trice16_10 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: Trice16_11( iD(15314), "rd:Trice16_11 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time:       5_654default: rd:Trice16_11 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: Trice16_12( iD(15315), "rd:Trice16_12 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time:       5_654default: rd:Trice16_12 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    
        break; case __LINE__: TRice16_1 ( iD(15316), "rd:TRice16_1  %d\n", -1 );                                                                                            //exp: time: 842,150_450default: rd:TRice16_1  -1     
        break; case __LINE__: TRice16_2 ( iD(15317), "rd:TRice16_2  %d, %d\n", -1, -2 );                                                                                    //exp: time: 842,150_450default: rd:TRice16_2  -1, -2 
        break; case __LINE__: TRice16_3 ( iD(15318), "rd:TRice16_3  %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time: 842,150_450default: rd:TRice16_3  -1, -2, -3       
        break; case __LINE__: TRice16_4 ( iD(15319), "rd:TRice16_4  %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time: 842,150_450default: rd:TRice16_4  -1, -2, -3, -4      
        break; case __LINE__: TRice16_5 ( iD(15320), "rd:TRice16_5  %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time: 842,150_450default: rd:TRice16_5  -1, -2, -3, -4, -5        
        break; case __LINE__: TRice16_6 ( iD(15321), "rd:TRice16_6  %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time: 842,150_450default: rd:TRice16_6  -1, -2, -3, -4, -5, -6        
        break; case __LINE__: TRice16_7 ( iD(15322), "rd:TRice16_7  %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time: 842,150_450default: rd:TRice16_7  -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: TRice16_8 ( iD(15323), "rd:TRice16_8  %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time: 842,150_450default: rd:TRice16_8  -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: TRice16_9 ( iD(15324), "rd:TRice16_9  %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time: 842,150_450default: rd:TRice16_9  -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: TRice16_10( iD(15325), "rd:TRice16_10 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time: 842,150_450default: rd:TRice16_10 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: TRice16_11( iD(15326), "rd:TRice16_11 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time: 842,150_450default: rd:TRice16_11 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: TRice16_12( iD(15327), "rd:TRice16_12 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time: 842,150_450default: rd:TRice16_12 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    

        break; case __LINE__: trice  ( iD(15328), "sig:TRICE32 with 1 to 12 values (line %d)\n", __LINE__ );

        break; case __LINE__: TRICE32( id(15353), "rd:TRICE32 %d\n", -1 );                                                                                            //exp: time:            default: rd:TRICE32 -1     
        break; case __LINE__: TRICE32( id(15354), "rd:TRICE32 %d, %d\n", -1, -2 );                                                                                    //exp: time:            default: rd:TRICE32 -1, -2 
        break; case __LINE__: TRICE32( id(15355), "rd:TRICE32 %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time:            default: rd:TRICE32 -1, -2, -3       
        break; case __LINE__: TRICE32( id(15344), "rd:TRICE32 %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time:            default: rd:TRICE32 -1, -2, -3, -4      
        break; case __LINE__: TRICE32( id(15357), "rd:TRICE32 %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time:            default: rd:TRICE32 -1, -2, -3, -4, -5        
        break; case __LINE__: TRICE32( id(15358), "rd:TRICE32 %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time:            default: rd:TRICE32 -1, -2, -3, -4, -5, -6        
        break; case __LINE__: TRICE32( id(15359), "rd:TRICE32 %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time:            default: rd:TRICE32 -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: TRICE32( id(15336), "rd:TRICE32 %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time:            default: rd:TRICE32 -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: TRICE32( id(15349), "rd:TRICE32 %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time:            default: rd:TRICE32 -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: TRICE32( id(15350), "rd:TRICE32 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time:            default: rd:TRICE32 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: TRICE32( id(15363), "rd:TRICE32 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time:            default: rd:TRICE32 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: TRICE32( id(15364), "rd:TRICE32 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time:            default: rd:TRICE32 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    
        break; case __LINE__: TRICE32( Id(15341), "rd:TRICE32 %d\n", -1 );                                                                                            //exp: time:       5_654default: rd:TRICE32 -1     
        break; case __LINE__: TRICE32( Id(15330), "rd:TRICE32 %d, %d\n", -1, -2 );                                                                                    //exp: time:       5_654default: rd:TRICE32 -1, -2 
        break; case __LINE__: TRICE32( Id(15331), "rd:TRICE32 %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time:       5_654default: rd:TRICE32 -1, -2, -3       
        break; case __LINE__: TRICE32( Id(15332), "rd:TRICE32 %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time:       5_654default: rd:TRICE32 -1, -2, -3, -4      
        break; case __LINE__: TRICE32( Id(15345), "rd:TRICE32 %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time:       5_654default: rd:TRICE32 -1, -2, -3, -4, -5        
        break; case __LINE__: TRICE32( Id(15346), "rd:TRICE32 %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time:       5_654default: rd:TRICE32 -1, -2, -3, -4, -5, -6        
        break; case __LINE__: TRICE32( Id(15335), "rd:TRICE32 %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time:       5_654default: rd:TRICE32 -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: TRICE32( Id(15348), "rd:TRICE32 %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time:       5_654default: rd:TRICE32 -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: TRICE32( Id(15337), "rd:TRICE32 %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time:       5_654default: rd:TRICE32 -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: TRICE32( Id(15338), "rd:TRICE32 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time:       5_654default: rd:TRICE32 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: TRICE32( Id(15351), "rd:TRICE32 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time:       5_654default: rd:TRICE32 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: TRICE32( Id(15340), "rd:TRICE32 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time:       5_654default: rd:TRICE32 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    
        break; case __LINE__: TRICE32( ID(15329), "rd:TRICE32 %d\n", -1 );                                                                                            //exp: time: 842,150_450default: rd:TRICE32 -1     
        break; case __LINE__: TRICE32( ID(15342), "rd:TRICE32 %d, %d\n", -1, -2 );                                                                                    //exp: time: 842,150_450default: rd:TRICE32 -1, -2 
        break; case __LINE__: TRICE32( ID(15343), "rd:TRICE32 %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time: 842,150_450default: rd:TRICE32 -1, -2, -3       
        break; case __LINE__: TRICE32( ID(15356), "rd:TRICE32 %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time: 842,150_450default: rd:TRICE32 -1, -2, -3, -4      
        break; case __LINE__: TRICE32( ID(15333), "rd:TRICE32 %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time: 842,150_450default: rd:TRICE32 -1, -2, -3, -4, -5        
        break; case __LINE__: TRICE32( ID(15334), "rd:TRICE32 %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time: 842,150_450default: rd:TRICE32 -1, -2, -3, -4, -5, -6        
        break; case __LINE__: TRICE32( ID(15347), "rd:TRICE32 %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time: 842,150_450default: rd:TRICE32 -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: TRICE32( ID(15360), "rd:TRICE32 %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time: 842,150_450default: rd:TRICE32 -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: TRICE32( ID(15361), "rd:TRICE32 %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time: 842,150_450default: rd:TRICE32 -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: TRICE32( ID(15362), "rd:TRICE32 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time: 842,150_450default: rd:TRICE32 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: TRICE32( ID(15339), "rd:TRICE32 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time: 842,150_450default: rd:TRICE32 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: TRICE32( ID(15352), "rd:TRICE32 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time: 842,150_450default: rd:TRICE32 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    

        break; case __LINE__: trice     ( iD(15365), "signal:TRICE32_n with 1 to 12 values (line %d)\n", __LINE__ );

        break; case __LINE__: TRICE32_1 ( id(15378), "rd:TRICE32_1  %d\n", -1 );                                                                                            //exp: time:            default: rd:TRICE32_1  -1     
        break; case __LINE__: TRICE32_2 ( id(15367), "rd:TRICE32_2  %d, %d\n", -1, -2 );                                                                                    //exp: time:            default: rd:TRICE32_2  -1, -2 
        break; case __LINE__: TRICE32_3 ( id(15368), "rd:TRICE32_3  %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time:            default: rd:TRICE32_3  -1, -2, -3       
        break; case __LINE__: TRICE32_4 ( id(15393), "rd:TRICE32_4  %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time:            default: rd:TRICE32_4  -1, -2, -3, -4      
        break; case __LINE__: TRICE32_5 ( id(15382), "rd:TRICE32_5  %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time:            default: rd:TRICE32_5  -1, -2, -3, -4, -5        
        break; case __LINE__: TRICE32_6 ( id(15395), "rd:TRICE32_6  %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time:            default: rd:TRICE32_6  -1, -2, -3, -4, -5, -6        
        break; case __LINE__: TRICE32_7 ( id(15396), "rd:TRICE32_7  %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time:            default: rd:TRICE32_7  -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: TRICE32_8 ( id(15397), "rd:TRICE32_8  %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time:            default: rd:TRICE32_8  -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: TRICE32_9 ( id(15386), "rd:TRICE32_9  %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time:            default: rd:TRICE32_9  -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: TRICE32_10( id(15387), "rd:TRICE32_10 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time:            default: rd:TRICE32_10 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: TRICE32_11( id(15376), "rd:TRICE32_11 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time:            default: rd:TRICE32_11 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: TRICE32_12( id(15389), "rd:TRICE32_12 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time:            default: rd:TRICE32_12 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    
        break; case __LINE__: TRICE32_1 ( Id(15366), "rd:TRICE32_1  %d\n", -1 );                                                                                            //exp: time:       5_654default: rd:TRICE32_1  -1     
        break; case __LINE__: TRICE32_2 ( Id(15379), "rd:TRICE32_2  %d, %d\n", -1, -2 );                                                                                    //exp: time:       5_654default: rd:TRICE32_2  -1, -2 
        break; case __LINE__: TRICE32_3 ( Id(15380), "rd:TRICE32_3  %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time:       5_654default: rd:TRICE32_3  -1, -2, -3       
        break; case __LINE__: TRICE32_4 ( Id(15381), "rd:TRICE32_4  %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time:       5_654default: rd:TRICE32_4  -1, -2, -3, -4      
        break; case __LINE__: TRICE32_5 ( Id(15370), "rd:TRICE32_5  %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time:       5_654default: rd:TRICE32_5  -1, -2, -3, -4, -5        
        break; case __LINE__: TRICE32_6 ( Id(15383), "rd:TRICE32_6  %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time:       5_654default: rd:TRICE32_6  -1, -2, -3, -4, -5, -6        
        break; case __LINE__: TRICE32_7 ( Id(15372), "rd:TRICE32_7  %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time:       5_654default: rd:TRICE32_7  -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: TRICE32_8 ( Id(15385), "rd:TRICE32_8  %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time:       5_654default: rd:TRICE32_8  -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: TRICE32_9 ( Id(15398), "rd:TRICE32_9  %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time:       5_654default: rd:TRICE32_9  -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: TRICE32_10( Id(15399), "rd:TRICE32_10 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time:       5_654default: rd:TRICE32_10 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: TRICE32_11( Id(15388), "rd:TRICE32_11 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time:       5_654default: rd:TRICE32_11 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: TRICE32_12( Id(15377), "rd:TRICE32_12 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time:       5_654default: rd:TRICE32_12 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    
        break; case __LINE__: TRICE32_1 ( ID(15390), "rd:TRICE32_1  %d\n", -1 );                                                                                            //exp: time: 842,150_450default: rd:TRICE32_1  -1     
        break; case __LINE__: TRICE32_2 ( ID(15391), "rd:TRICE32_2  %d, %d\n", -1, -2 );                                                                                    //exp: time: 842,150_450default: rd:TRICE32_2  -1, -2 
        break; case __LINE__: TRICE32_3 ( ID(15392), "rd:TRICE32_3  %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time: 842,150_450default: rd:TRICE32_3  -1, -2, -3       
        break; case __LINE__: TRICE32_4 ( ID(15369), "rd:TRICE32_4  %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time: 842,150_450default: rd:TRICE32_4  -1, -2, -3, -4      
        break; case __LINE__: TRICE32_5 ( ID(15394), "rd:TRICE32_5  %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time: 842,150_450default: rd:TRICE32_5  -1, -2, -3, -4, -5        
        break; case __LINE__: TRICE32_6 ( ID(15371), "rd:TRICE32_6  %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time: 842,150_450default: rd:TRICE32_6  -1, -2, -3, -4, -5, -6        
        break; case __LINE__: TRICE32_7 ( ID(15384), "rd:TRICE32_7  %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time: 842,150_450default: rd:TRICE32_7  -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: TRICE32_8 ( ID(15373), "rd:TRICE32_8  %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time: 842,150_450default: rd:TRICE32_8  -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: TRICE32_9 ( ID(15374), "rd:TRICE32_9  %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time: 842,150_450default: rd:TRICE32_9  -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: TRICE32_10( ID(15375), "rd:TRICE32_10 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time: 842,150_450default: rd:TRICE32_10 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: TRICE32_11( ID(15400), "rd:TRICE32_11 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time: 842,150_450default: rd:TRICE32_11 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: TRICE32_12( ID(15401), "rd:TRICE32_12 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time: 842,150_450default: rd:TRICE32_12 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    

        break; case __LINE__: trice  ( iD(15402), "sig:trice32 with 1 to 12 values (line %d)\n", __LINE__ );

        break; case __LINE__: trice32( iD(15403), "rd:trice32 %d\n", -1 );                                                                                            //exp: time:            default: rd:trice32 -1     
        break; case __LINE__: trice32( iD(15404), "rd:trice32 %d, %d\n", -1, -2 );                                                                                    //exp: time:            default: rd:trice32 -1, -2 
        break; case __LINE__: trice32( iD(15405), "rd:trice32 %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time:            default: rd:trice32 -1, -2, -3       
        break; case __LINE__: trice32( iD(15406), "rd:trice32 %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time:            default: rd:trice32 -1, -2, -3, -4      
        break; case __LINE__: trice32( iD(15407), "rd:trice32 %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time:            default: rd:trice32 -1, -2, -3, -4, -5        
        break; case __LINE__: trice32( iD(15408), "rd:trice32 %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time:            default: rd:trice32 -1, -2, -3, -4, -5, -6        
        break; case __LINE__: trice32( iD(15409), "rd:trice32 %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time:            default: rd:trice32 -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: trice32( iD(15410), "rd:trice32 %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time:            default: rd:trice32 -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: trice32( iD(15411), "rd:trice32 %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time:            default: rd:trice32 -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: trice32( iD(15412), "rd:trice32 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time:            default: rd:trice32 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: trice32( iD(15413), "rd:trice32 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time:            default: rd:trice32 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: trice32( iD(15414), "rd:trice32 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time:            default: rd:trice32 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    
        break; case __LINE__: Trice32( iD(15415), "rd:Trice32 %d\n", -1 );                                                                                            //exp: time:       5_654default: rd:Trice32 -1     
        break; case __LINE__: Trice32( iD(15416), "rd:Trice32 %d, %d\n", -1, -2 );                                                                                    //exp: time:       5_654default: rd:Trice32 -1, -2 
        break; case __LINE__: Trice32( iD(15417), "rd:Trice32 %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time:       5_654default: rd:Trice32 -1, -2, -3       
        break; case __LINE__: Trice32( iD(15418), "rd:Trice32 %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time:       5_654default: rd:Trice32 -1, -2, -3, -4      
        break; case __LINE__: Trice32( iD(15419), "rd:Trice32 %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time:       5_654default: rd:Trice32 -1, -2, -3, -4, -5        
        break; case __LINE__: Trice32( iD(15420), "rd:Trice32 %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time:       5_654default: rd:Trice32 -1, -2, -3, -4, -5, -6        
        break; case __LINE__: Trice32( iD(15421), "rd:Trice32 %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time:       5_654default: rd:Trice32 -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: Trice32( iD(15422), "rd:Trice32 %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time:       5_654default: rd:Trice32 -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: Trice32( iD(15423), "rd:Trice32 %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time:       5_654default: rd:Trice32 -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: Trice32( iD(15424), "rd:Trice32 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time:       5_654default: rd:Trice32 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: Trice32( iD(15425), "rd:Trice32 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time:       5_654default: rd:Trice32 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: Trice32( iD(15426), "rd:Trice32 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time:       5_654default: rd:Trice32 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    
        break; case __LINE__: TRice32( iD(15427), "rd:TRice32 %d\n", -1 );                                                                                            //exp: time: 842,150_450default: rd:TRice32 -1     
        break; case __LINE__: TRice32( iD(15428), "rd:TRice32 %d, %d\n", -1, -2 );                                                                                    //exp: time: 842,150_450default: rd:TRice32 -1, -2 
        break; case __LINE__: TRice32( iD(15429), "rd:TRice32 %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time: 842,150_450default: rd:TRice32 -1, -2, -3       
        break; case __LINE__: TRice32( iD(15430), "rd:TRice32 %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time: 842,150_450default: rd:TRice32 -1, -2, -3, -4      
        break; case __LINE__: TRice32( iD(15431), "rd:TRice32 %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time: 842,150_450default: rd:TRice32 -1, -2, -3, -4, -5        
        break; case __LINE__: TRice32( iD(15432), "rd:TRice32 %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time: 842,150_450default: rd:TRice32 -1, -2, -3, -4, -5, -6        
        break; case __LINE__: TRice32( iD(15433), "rd:TRice32 %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time: 842,150_450default: rd:TRice32 -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: TRice32( iD(15434), "rd:TRice32 %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time: 842,150_450default: rd:TRice32 -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: TRice32( iD(15435), "rd:TRice32 %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time: 842,150_450default: rd:TRice32 -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: TRice32( iD(15436), "rd:TRice32 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time: 842,150_450default: rd:TRice32 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: TRice32( iD(15437), "rd:TRice32 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time: 842,150_450default: rd:TRice32 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: TRice32( iD(15438), "rd:TRice32 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time: 842,150_450default: rd:TRice32 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    

        break; case __LINE__: trice     ( iD(15439), "signal:trice32_n with 1 to 12 values (line %d)\n", __LINE__ );

        break; case __LINE__: trice32_1 ( iD(15440), "rd:trice32_1  %d\n", -1 );                                                                                            //exp: time:            default: rd:trice32_1  -1     
        break; case __LINE__: trice32_2 ( iD(15441), "rd:trice32_2  %d, %d\n", -1, -2 );                                                                                    //exp: time:            default: rd:trice32_2  -1, -2 
        break; case __LINE__: trice32_3 ( iD(15442), "rd:trice32_3  %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time:            default: rd:trice32_3  -1, -2, -3       
        break; case __LINE__: trice32_4 ( iD(15443), "rd:trice32_4  %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time:            default: rd:trice32_4  -1, -2, -3, -4      
        break; case __LINE__: trice32_5 ( iD(15444), "rd:trice32_5  %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time:            default: rd:trice32_5  -1, -2, -3, -4, -5        
        break; case __LINE__: trice32_6 ( iD(15445), "rd:trice32_6  %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time:            default: rd:trice32_6  -1, -2, -3, -4, -5, -6        
        break; case __LINE__: trice32_7 ( iD(15446), "rd:trice32_7  %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time:            default: rd:trice32_7  -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: trice32_8 ( iD(15447), "rd:trice32_8  %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time:            default: rd:trice32_8  -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: trice32_9 ( iD(15448), "rd:trice32_9  %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time:            default: rd:trice32_9  -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: trice32_10( iD(15449), "rd:trice32_10 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time:            default: rd:trice32_10 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: trice32_11( iD(15450), "rd:trice32_11 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time:            default: rd:trice32_11 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: trice32_12( iD(15451), "rd:trice32_12 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time:            default: rd:trice32_12 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    
        break; case __LINE__: Trice32_1 ( iD(15452), "rd:Trice32_1  %d\n", -1 );                                                                                            //exp: time:       5_654default: rd:Trice32_1  -1     
        break; case __LINE__: Trice32_2 ( iD(15453), "rd:Trice32_2  %d, %d\n", -1, -2 );                                                                                    //exp: time:       5_654default: rd:Trice32_2  -1, -2 
        break; case __LINE__: Trice32_3 ( iD(15454), "rd:Trice32_3  %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time:       5_654default: rd:Trice32_3  -1, -2, -3       
        break; case __LINE__: Trice32_4 ( iD(15455), "rd:Trice32_4  %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time:       5_654default: rd:Trice32_4  -1, -2, -3, -4      
        break; case __LINE__: Trice32_5 ( iD(15456), "rd:Trice32_5  %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time:       5_654default: rd:Trice32_5  -1, -2, -3, -4, -5        
        break; case __LINE__: Trice32_6 ( iD(15457), "rd:Trice32_6  %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time:       5_654default: rd:Trice32_6  -1, -2, -3, -4, -5, -6        
        break; case __LINE__: Trice32_7 ( iD(15458), "rd:Trice32_7  %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time:       5_654default: rd:Trice32_7  -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: Trice32_8 ( iD(15459), "rd:Trice32_8  %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time:       5_654default: rd:Trice32_8  -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: Trice32_9 ( iD(15460), "rd:Trice32_9  %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time:       5_654default: rd:Trice32_9  -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: Trice32_10( iD(15461), "rd:Trice32_10 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time:       5_654default: rd:Trice32_10 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: Trice32_11( iD(15462), "rd:Trice32_11 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time:       5_654default: rd:Trice32_11 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: Trice32_12( iD(15463), "rd:Trice32_12 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time:       5_654default: rd:Trice32_12 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    
        break; case __LINE__: TRice32_1 ( iD(15464), "rd:TRice32_1  %d\n", -1 );                                                                                            //exp: time: 842,150_450default: rd:TRice32_1  -1     
        break; case __LINE__: TRice32_2 ( iD(15465), "rd:TRice32_2  %d, %d\n", -1, -2 );                                                                                    //exp: time: 842,150_450default: rd:TRice32_2  -1, -2 
        break; case __LINE__: TRice32_3 ( iD(15466), "rd:TRice32_3  %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time: 842,150_450default: rd:TRice32_3  -1, -2, -3       
        break; case __LINE__: TRice32_4 ( iD(15467), "rd:TRice32_4  %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time: 842,150_450default: rd:TRice32_4  -1, -2, -3, -4      
        break; case __LINE__: TRice32_5 ( iD(15468), "rd:TRice32_5  %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time: 842,150_450default: rd:TRice32_5  -1, -2, -3, -4, -5        
        break; case __LINE__: TRice32_6 ( iD(15469), "rd:TRice32_6  %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time: 842,150_450default: rd:TRice32_6  -1, -2, -3, -4, -5, -6        
        break; case __LINE__: TRice32_7 ( iD(15470), "rd:TRice32_7  %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time: 842,150_450default: rd:TRice32_7  -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: TRice32_8 ( iD(15471), "rd:TRice32_8  %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time: 842,150_450default: rd:TRice32_8  -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: TRice32_9 ( iD(15472), "rd:TRice32_9  %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time: 842,150_450default: rd:TRice32_9  -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: TRice32_10( iD(15473), "rd:TRice32_10 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time: 842,150_450default: rd:TRice32_10 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: TRice32_11( iD(15474), "rd:TRice32_11 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time: 842,150_450default: rd:TRice32_11 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: TRice32_12( iD(15475), "rd:TRice32_12 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time: 842,150_450default: rd:TRice32_12 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12

        break; case __LINE__: trice  ( iD(15476), "sig:TRICE64 with 1 to 12 values (line %d)\n", __LINE__ );

        break; case __LINE__: TRICE64( id(15477), "rd:TRICE64 %d\n", -1 );                                                                                            //exp: time:            default: rd:TRICE64 -1     
        break; case __LINE__: TRICE64( id(15478), "rd:TRICE64 %d, %d\n", -1, -2 );                                                                                    //exp: time:            default: rd:TRICE64 -1, -2 
        break; case __LINE__: TRICE64( id(15479), "rd:TRICE64 %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time:            default: rd:TRICE64 -1, -2, -3       
        break; case __LINE__: TRICE64( id(15492), "rd:TRICE64 %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time:            default: rd:TRICE64 -1, -2, -3, -4      
        break; case __LINE__: TRICE64( id(15481), "rd:TRICE64 %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time:            default: rd:TRICE64 -1, -2, -3, -4, -5        
        break; case __LINE__: TRICE64( id(15494), "rd:TRICE64 %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time:            default: rd:TRICE64 -1, -2, -3, -4, -5, -6        
        break; case __LINE__: TRICE64( id(15507), "rd:TRICE64 %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time:            default: rd:TRICE64 -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: TRICE64( id(15496), "rd:TRICE64 %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time:            default: rd:TRICE64 -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: TRICE64( id(15509), "rd:TRICE64 %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time:            default: rd:TRICE64 -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: TRICE64( id(15486), "rd:TRICE64 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time:            default: rd:TRICE64 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: TRICE64( id(15511), "rd:TRICE64 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time:            default: rd:TRICE64 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: TRICE64( id(15512), "rd:TRICE64 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time:            default: rd:TRICE64 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    
        break; case __LINE__: TRICE64( Id(15489), "rd:TRICE64 %d\n", -1 );                                                                                            //exp: time:       5_654default: rd:TRICE64 -1     
        break; case __LINE__: TRICE64( Id(15502), "rd:TRICE64 %d, %d\n", -1, -2 );                                                                                    //exp: time:       5_654default: rd:TRICE64 -1, -2 
        break; case __LINE__: TRICE64( Id(15491), "rd:TRICE64 %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time:       5_654default: rd:TRICE64 -1, -2, -3       
        break; case __LINE__: TRICE64( Id(15480), "rd:TRICE64 %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time:       5_654default: rd:TRICE64 -1, -2, -3, -4      
        break; case __LINE__: TRICE64( Id(15505), "rd:TRICE64 %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time:       5_654default: rd:TRICE64 -1, -2, -3, -4, -5        
        break; case __LINE__: TRICE64( Id(15482), "rd:TRICE64 %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time:       5_654default: rd:TRICE64 -1, -2, -3, -4, -5, -6        
        break; case __LINE__: TRICE64( Id(15483), "rd:TRICE64 %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time:       5_654default: rd:TRICE64 -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: TRICE64( Id(15484), "rd:TRICE64 %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time:       5_654default: rd:TRICE64 -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: TRICE64( Id(15497), "rd:TRICE64 %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time:       5_654default: rd:TRICE64 -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: TRICE64( Id(15510), "rd:TRICE64 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time:       5_654default: rd:TRICE64 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: TRICE64( Id(15499), "rd:TRICE64 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time:       5_654default: rd:TRICE64 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: TRICE64( Id(15488), "rd:TRICE64 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time:       5_654default: rd:TRICE64 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    
        break; case __LINE__: TRICE64( ID(15501), "rd:TRICE64 %d\n", -1 );                                                                                            //exp: time: 842,150_450default: rd:TRICE64 -1     
        break; case __LINE__: TRICE64( ID(15490), "rd:TRICE64 %d, %d\n", -1, -2 );                                                                                    //exp: time: 842,150_450default: rd:TRICE64 -1, -2 
        break; case __LINE__: TRICE64( ID(15503), "rd:TRICE64 %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time: 842,150_450default: rd:TRICE64 -1, -2, -3       
        break; case __LINE__: TRICE64( ID(15504), "rd:TRICE64 %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time: 842,150_450default: rd:TRICE64 -1, -2, -3, -4      
        break; case __LINE__: TRICE64( ID(15493), "rd:TRICE64 %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time: 842,150_450default: rd:TRICE64 -1, -2, -3, -4, -5        
        break; case __LINE__: TRICE64( ID(15506), "rd:TRICE64 %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time: 842,150_450default: rd:TRICE64 -1, -2, -3, -4, -5, -6        
        break; case __LINE__: TRICE64( ID(15495), "rd:TRICE64 %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time: 842,150_450default: rd:TRICE64 -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: TRICE64( ID(15508), "rd:TRICE64 %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time: 842,150_450default: rd:TRICE64 -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: TRICE64( ID(15485), "rd:TRICE64 %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time: 842,150_450default: rd:TRICE64 -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: TRICE64( ID(15498), "rd:TRICE64 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time: 842,150_450default: rd:TRICE64 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: TRICE64( ID(15487), "rd:TRICE64 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time: 842,150_450default: rd:TRICE64 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: TRICE64( ID(15500), "rd:TRICE64 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time: 842,150_450default: rd:TRICE64 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    

        break; case __LINE__: trice     ( iD(15513), "signal:TRICE64_n with 1 to 12 values (line %d)\n", __LINE__ );

        break; case __LINE__: TRICE64_1 ( id(15538), "rd:TRICE64_1  %d\n", -1 );                                                                                            //exp: time:            default: rd:TRICE64_1  -1     
        break; case __LINE__: TRICE64_2 ( id(15527), "rd:TRICE64_2  %d, %d\n", -1, -2 );                                                                                    //exp: time:            default: rd:TRICE64_2  -1, -2 
        break; case __LINE__: TRICE64_3 ( id(15528), "rd:TRICE64_3  %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time:            default: rd:TRICE64_3  -1, -2, -3       
        break; case __LINE__: TRICE64_4 ( id(15541), "rd:TRICE64_4  %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time:            default: rd:TRICE64_4  -1, -2, -3, -4      
        break; case __LINE__: TRICE64_5 ( id(15542), "rd:TRICE64_5  %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time:            default: rd:TRICE64_5  -1, -2, -3, -4, -5        
        break; case __LINE__: TRICE64_6 ( id(15531), "rd:TRICE64_6  %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time:            default: rd:TRICE64_6  -1, -2, -3, -4, -5, -6        
        break; case __LINE__: TRICE64_7 ( id(15520), "rd:TRICE64_7  %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time:            default: rd:TRICE64_7  -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: TRICE64_8 ( id(15545), "rd:TRICE64_8  %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time:            default: rd:TRICE64_8  -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: TRICE64_9 ( id(15534), "rd:TRICE64_9  %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time:            default: rd:TRICE64_9  -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: TRICE64_10( id(15535), "rd:TRICE64_10 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time:            default: rd:TRICE64_10 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: TRICE64_11( id(15524), "rd:TRICE64_11 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time:            default: rd:TRICE64_11 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: TRICE64_12( id(15537), "rd:TRICE64_12 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time:            default: rd:TRICE64_12 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    
        break; case __LINE__: TRICE64_1 ( Id(15526), "rd:TRICE64_1  %d\n", -1 );                                                                                            //exp: time:       5_654default: rd:TRICE64_1  -1     
        break; case __LINE__: TRICE64_2 ( Id(15515), "rd:TRICE64_2  %d, %d\n", -1, -2 );                                                                                    //exp: time:       5_654default: rd:TRICE64_2  -1, -2 
        break; case __LINE__: TRICE64_3 ( Id(15540), "rd:TRICE64_3  %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time:       5_654default: rd:TRICE64_3  -1, -2, -3       
        break; case __LINE__: TRICE64_4 ( Id(15529), "rd:TRICE64_4  %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time:       5_654default: rd:TRICE64_4  -1, -2, -3, -4      
        break; case __LINE__: TRICE64_5 ( Id(15530), "rd:TRICE64_5  %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time:       5_654default: rd:TRICE64_5  -1, -2, -3, -4, -5        
        break; case __LINE__: TRICE64_6 ( Id(15543), "rd:TRICE64_6  %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time:       5_654default: rd:TRICE64_6  -1, -2, -3, -4, -5, -6        
        break; case __LINE__: TRICE64_7 ( Id(15544), "rd:TRICE64_7  %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time:       5_654default: rd:TRICE64_7  -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: TRICE64_8 ( Id(15533), "rd:TRICE64_8  %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time:       5_654default: rd:TRICE64_8  -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: TRICE64_9 ( Id(15522), "rd:TRICE64_9  %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time:       5_654default: rd:TRICE64_9  -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: TRICE64_10( Id(15547), "rd:TRICE64_10 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time:       5_654default: rd:TRICE64_10 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: TRICE64_11( Id(15536), "rd:TRICE64_11 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time:       5_654default: rd:TRICE64_11 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: TRICE64_12( Id(15549), "rd:TRICE64_12 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time:       5_654default: rd:TRICE64_12 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    
        break; case __LINE__: TRICE64_1 ( ID(15514), "rd:TRICE64_1  %d\n", -1 );                                                                                            //exp: time: 842,150_450default: rd:TRICE64_1  -1     
        break; case __LINE__: TRICE64_2 ( ID(15539), "rd:TRICE64_2  %d, %d\n", -1, -2 );                                                                                    //exp: time: 842,150_450default: rd:TRICE64_2  -1, -2 
        break; case __LINE__: TRICE64_3 ( ID(15516), "rd:TRICE64_3  %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time: 842,150_450default: rd:TRICE64_3  -1, -2, -3       
        break; case __LINE__: TRICE64_4 ( ID(15517), "rd:TRICE64_4  %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time: 842,150_450default: rd:TRICE64_4  -1, -2, -3, -4      
        break; case __LINE__: TRICE64_5 ( ID(15518), "rd:TRICE64_5  %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time: 842,150_450default: rd:TRICE64_5  -1, -2, -3, -4, -5        
        break; case __LINE__: TRICE64_6 ( ID(15519), "rd:TRICE64_6  %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time: 842,150_450default: rd:TRICE64_6  -1, -2, -3, -4, -5, -6        
        break; case __LINE__: TRICE64_7 ( ID(15532), "rd:TRICE64_7  %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time: 842,150_450default: rd:TRICE64_7  -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: TRICE64_8 ( ID(15521), "rd:TRICE64_8  %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time: 842,150_450default: rd:TRICE64_8  -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: TRICE64_9 ( ID(15546), "rd:TRICE64_9  %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time: 842,150_450default: rd:TRICE64_9  -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: TRICE64_10( ID(15523), "rd:TRICE64_10 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time: 842,150_450default: rd:TRICE64_10 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: TRICE64_11( ID(15548), "rd:TRICE64_11 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time: 842,150_450default: rd:TRICE64_11 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: TRICE64_12( ID(15525), "rd:TRICE64_12 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time: 842,150_450default: rd:TRICE64_12 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    

        break; case __LINE__: trice  ( iD(15550), "sig:trice64 with 1 to 12 values (line %d)\n", __LINE__ );

        break; case __LINE__: trice64( iD(15551), "rd:trice64 %d\n", -1 );                                                                                            //exp: time:            default: rd:trice64 -1     
        break; case __LINE__: trice64( iD(15552), "rd:trice64 %d, %d\n", -1, -2 );                                                                                    //exp: time:            default: rd:trice64 -1, -2 
        break; case __LINE__: trice64( iD(15553), "rd:trice64 %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time:            default: rd:trice64 -1, -2, -3       
        break; case __LINE__: trice64( iD(15554), "rd:trice64 %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time:            default: rd:trice64 -1, -2, -3, -4      
        break; case __LINE__: trice64( iD(15555), "rd:trice64 %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time:            default: rd:trice64 -1, -2, -3, -4, -5        
        break; case __LINE__: trice64( iD(15556), "rd:trice64 %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time:            default: rd:trice64 -1, -2, -3, -4, -5, -6        
        break; case __LINE__: trice64( iD(15557), "rd:trice64 %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time:            default: rd:trice64 -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: trice64( iD(15558), "rd:trice64 %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time:            default: rd:trice64 -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: trice64( iD(15559), "rd:trice64 %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time:            default: rd:trice64 -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: trice64( iD(15560), "rd:trice64 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time:            default: rd:trice64 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: trice64( iD(15561), "rd:trice64 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time:            default: rd:trice64 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: trice64( iD(15562), "rd:trice64 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time:            default: rd:trice64 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    
        break; case __LINE__: Trice64( iD(15563), "rd:Trice64 %d\n", -1 );                                                                                            //exp: time:       5_654default: rd:Trice64 -1     
        break; case __LINE__: Trice64( iD(15564), "rd:Trice64 %d, %d\n", -1, -2 );                                                                                    //exp: time:       5_654default: rd:Trice64 -1, -2 
        break; case __LINE__: Trice64( iD(15565), "rd:Trice64 %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time:       5_654default: rd:Trice64 -1, -2, -3       
        break; case __LINE__: Trice64( iD(15566), "rd:Trice64 %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time:       5_654default: rd:Trice64 -1, -2, -3, -4      
        break; case __LINE__: Trice64( iD(15567), "rd:Trice64 %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time:       5_654default: rd:Trice64 -1, -2, -3, -4, -5        
        break; case __LINE__: Trice64( iD(15568), "rd:Trice64 %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time:       5_654default: rd:Trice64 -1, -2, -3, -4, -5, -6        
        break; case __LINE__: Trice64( iD(15569), "rd:Trice64 %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time:       5_654default: rd:Trice64 -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: Trice64( iD(15570), "rd:Trice64 %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time:       5_654default: rd:Trice64 -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: Trice64( iD(15571), "rd:Trice64 %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time:       5_654default: rd:Trice64 -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: Trice64( iD(15572), "rd:Trice64 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time:       5_654default: rd:Trice64 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: Trice64( iD(15573), "rd:Trice64 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time:       5_654default: rd:Trice64 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: Trice64( iD(15574), "rd:Trice64 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time:       5_654default: rd:Trice64 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    
        break; case __LINE__: TRice64( iD(15575), "rd:TRice64 %d\n", -1 );                                                                                            //exp: time: 842,150_450default: rd:TRice64 -1     
        break; case __LINE__: TRice64( iD(15576), "rd:TRice64 %d, %d\n", -1, -2 );                                                                                    //exp: time: 842,150_450default: rd:TRice64 -1, -2 
        break; case __LINE__: TRice64( iD(15577), "rd:TRice64 %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time: 842,150_450default: rd:TRice64 -1, -2, -3       
        break; case __LINE__: TRice64( iD(15578), "rd:TRice64 %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time: 842,150_450default: rd:TRice64 -1, -2, -3, -4      
        break; case __LINE__: TRice64( iD(15579), "rd:TRice64 %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time: 842,150_450default: rd:TRice64 -1, -2, -3, -4, -5        
        break; case __LINE__: TRice64( iD(15580), "rd:TRice64 %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time: 842,150_450default: rd:TRice64 -1, -2, -3, -4, -5, -6        
        break; case __LINE__: TRice64( iD(15581), "rd:TRice64 %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time: 842,150_450default: rd:TRice64 -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: TRice64( iD(15582), "rd:TRice64 %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time: 842,150_450default: rd:TRice64 -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: TRice64( iD(15583), "rd:TRice64 %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time: 842,150_450default: rd:TRice64 -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: TRice64( iD(15584), "rd:TRice64 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time: 842,150_450default: rd:TRice64 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: TRice64( iD(15585), "rd:TRice64 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time: 842,150_450default: rd:TRice64 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: TRice64( iD(15586), "rd:TRice64 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time: 842,150_450default: rd:TRice64 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    

        break; case __LINE__: trice     ( iD(15587), "signal:trice64_n with 1 to 12 values (line %d)\n", __LINE__ );

        break; case __LINE__: trice64_1 ( iD(15588), "rd:trice64_1  %d\n", -1 );                                                                                            //exp: time:            default: rd:trice64_1  -1     
        break; case __LINE__: trice64_2 ( iD(15589), "rd:trice64_2  %d, %d\n", -1, -2 );                                                                                    //exp: time:            default: rd:trice64_2  -1, -2 
        break; case __LINE__: trice64_3 ( iD(15590), "rd:trice64_3  %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time:            default: rd:trice64_3  -1, -2, -3       
        break; case __LINE__: trice64_4 ( iD(15591), "rd:trice64_4  %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time:            default: rd:trice64_4  -1, -2, -3, -4      
        break; case __LINE__: trice64_5 ( iD(15592), "rd:trice64_5  %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time:            default: rd:trice64_5  -1, -2, -3, -4, -5        
        break; case __LINE__: trice64_6 ( iD(15593), "rd:trice64_6  %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time:            default: rd:trice64_6  -1, -2, -3, -4, -5, -6        
        break; case __LINE__: trice64_7 ( iD(15594), "rd:trice64_7  %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time:            default: rd:trice64_7  -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: trice64_8 ( iD(15595), "rd:trice64_8  %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time:            default: rd:trice64_8  -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: trice64_9 ( iD(15596), "rd:trice64_9  %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time:            default: rd:trice64_9  -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: trice64_10( iD(15597), "rd:trice64_10 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time:            default: rd:trice64_10 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: trice64_11( iD(15598), "rd:trice64_11 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time:            default: rd:trice64_11 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: trice64_12( iD(15599), "rd:trice64_12 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time:            default: rd:trice64_12 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    
        break; case __LINE__: Trice64_1 ( iD(15600), "rd:Trice64_1  %d\n", -1 );                                                                                            //exp: time:       5_654default: rd:Trice64_1  -1     
        break; case __LINE__: Trice64_2 ( iD(15601), "rd:Trice64_2  %d, %d\n", -1, -2 );                                                                                    //exp: time:       5_654default: rd:Trice64_2  -1, -2 
        break; case __LINE__: Trice64_3 ( iD(15602), "rd:Trice64_3  %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time:       5_654default: rd:Trice64_3  -1, -2, -3       
        break; case __LINE__: Trice64_4 ( iD(15603), "rd:Trice64_4  %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time:       5_654default: rd:Trice64_4  -1, -2, -3, -4      
        break; case __LINE__: Trice64_5 ( iD(15604), "rd:Trice64_5  %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time:       5_654default: rd:Trice64_5  -1, -2, -3, -4, -5        
        break; case __LINE__: Trice64_6 ( iD(15605), "rd:Trice64_6  %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time:       5_654default: rd:Trice64_6  -1, -2, -3, -4, -5, -6        
        break; case __LINE__: Trice64_7 ( iD(15606), "rd:Trice64_7  %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time:       5_654default: rd:Trice64_7  -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: Trice64_8 ( iD(15607), "rd:Trice64_8  %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time:       5_654default: rd:Trice64_8  -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: Trice64_9 ( iD(15608), "rd:Trice64_9  %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time:       5_654default: rd:Trice64_9  -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: Trice64_10( iD(15609), "rd:Trice64_10 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time:       5_654default: rd:Trice64_10 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: Trice64_11( iD(15610), "rd:Trice64_11 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time:       5_654default: rd:Trice64_11 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: Trice64_12( iD(15611), "rd:Trice64_12 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time:       5_654default: rd:Trice64_12 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    
        break; case __LINE__: TRice64_1 ( iD(15612), "rd:TRice64_1  %d\n", -1 );                                                                                            //exp: time: 842,150_450default: rd:TRice64_1  -1     
        break; case __LINE__: TRice64_2 ( iD(15613), "rd:TRice64_2  %d, %d\n", -1, -2 );                                                                                    //exp: time: 842,150_450default: rd:TRice64_2  -1, -2 
        break; case __LINE__: TRice64_3 ( iD(15614), "rd:TRice64_3  %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time: 842,150_450default: rd:TRice64_3  -1, -2, -3       
        break; case __LINE__: TRice64_4 ( iD(15615), "rd:TRice64_4  %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time: 842,150_450default: rd:TRice64_4  -1, -2, -3, -4      
        break; case __LINE__: TRice64_5 ( iD(15616), "rd:TRice64_5  %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time: 842,150_450default: rd:TRice64_5  -1, -2, -3, -4, -5        
        break; case __LINE__: TRice64_6 ( iD(15617), "rd:TRice64_6  %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time: 842,150_450default: rd:TRice64_6  -1, -2, -3, -4, -5, -6        
        break; case __LINE__: TRice64_7 ( iD(15618), "rd:TRice64_7  %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time: 842,150_450default: rd:TRice64_7  -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: TRice64_8 ( iD(15619), "rd:TRice64_8  %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time: 842,150_450default: rd:TRice64_8  -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: TRice64_9 ( iD(15620), "rd:TRice64_9  %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time: 842,150_450default: rd:TRice64_9  -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: TRice64_10( iD(15621), "rd:TRice64_10 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time: 842,150_450default: rd:TRice64_10 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: TRice64_11( iD(15622), "rd:TRice64_11 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time: 842,150_450default: rd:TRice64_11 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: TRice32_12( iD(15623), "rd:TRice32_12 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time: 842,150_450default: rd:TRice32_12 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    

        break; case __LINE__: TRICE( ID(15624), "sig:Colors and ticks\n" );
        break; case __LINE__: TRICE( ID(15625), "--------------------------------------------------\n");
        break; case __LINE__: TRICE( ID(15628), "--------------------------------------------------\n");
        break; case __LINE__: TRICE( ID(15627), "dbg:12345 as 16bit is %016b\n", 12345);
        break; case __LINE__: TRICE( ID(15626), "--------------------------------------------------\n");
        break; case __LINE__: TRICE( ID(15629), "sig:This ASSERT error is just a demo and no real error:\n");
        break; case __LINE__: TRICE( ID(15630), "--------------------------------------------------\n");
      //break; case __LINE__: TRICE( ID(15631), "ERR:error       message, SysTick is %6u\n", SYSTICKVAL);
        break; case __LINE__: TRICE( ID(15632), "WRN:warning     message, SysTick is %6u\n", SYSTICKVAL);
        break; case __LINE__: TRICE( ID(15633), "ATT:attention   message, SysTick is %6u\n", SYSTICKVAL);
        break; case __LINE__: TRICE( ID(15634), "DIA:diagnostics message, SysTick is %6u\n", SYSTICKVAL);
        break; case __LINE__: TRICE( ID(15635), "TIM:timing      message, SysTick is %6u\n", SYSTICKVAL);
        break; case __LINE__: TRICE( ID(15636), "DBG:debug       message, SysTick is %6u\n", SYSTICKVAL);
        break; case __LINE__: TRICE( ID(15637), "SIG:signal      message, SysTick is %6u\n", SYSTICKVAL);
        break; case __LINE__: TRICE( ID(15638), "RD:read         message, SysTick is %6u\n", SYSTICKVAL);
        break; case __LINE__: TRICE( ID(15639), "WR:write        message, SysTick is %6u\n", SYSTICKVAL);
        break; case __LINE__: TRICE( ID(15640), "ISR:interrupt   message, SysTick is %6u\n", SYSTICKVAL);
        break; case __LINE__: TRICE( ID(15641), "MSG:normal      message, SysTick is %6u\n", SYSTICKVAL);
        break; case __LINE__: TRICE( ID(15642), "INFO:informal   message, SysTick is %6u\n", SYSTICKVAL);
        break; case __LINE__: TRICE( ID(15643), "time:TRICE32_1  message, SysTick is %6u\n", SYSTICKVAL);

        break; case __LINE__: TRICE( ID(15644), "sig:Various ranges and formats\n" );
        break; case __LINE__: TRICE8 ( ID(15645), "tst:TRICE8  %%03x -> %03x  %03x  %03x  %03x\n", 1, 0x7f, 0x80, 0xff);
        break; case __LINE__: TRICE8 ( ID(15646), "tst:TRICE8   %%4d -> %4d %4d %4d %4d\n", 1, 0x7f, 0x80, 0xff);
        break; case __LINE__: TRICE8 ( ID(15647), "tst:TRICE8   %%4u -> %4u %4u %4u %4u\n", 1, 0x7f, 0x80, 0xff);
        break; case __LINE__: TRICE8 ( ID(15648), "tst:TRICE8   %%4o -> %4o %4o %4o %4o\n", 1, 0x7f, 0x80, 0xff);
        break; case __LINE__: TRICE8 ( ID(15649), "tst:TRICE8   %%4O -> %4O %4O %4O %4O\n", 1, 0x7f, 0x80, 0xff);
        break; case __LINE__: TRICE8 ( ID(15650), "tst:TRICE8   %%4X -> %4X %4X %4X %4X\n", 1, 0x7f, 0x80, 0xff);
        break; case __LINE__: TRICE8 ( ID(15651), "tst:TRICE8   %%4x -> %4x %4x %4x %4x\n", 1, 0x7f, 0x80, 0xff);
        break; case __LINE__: TRICE8 ( ID(15652), "tst:TRICE8   %%8b -> %8b %8b %8b %8b\n", 1, 0x7f, 0x80, 0xff);
        break; case __LINE__: TRICE8 ( ID(15653), "tst:TRICE8  %%08b -> %08b %08b %08b %08b\n", 1, 0x7f, 0x80, 0xff);
        break; case __LINE__: TRICE16( ID(15654), "tst:TRICE16  %%05x ->   %05x   %05x   %05x   %05x\n", 1, 0x7fff, 0x8000, 0xffff);
        break; case __LINE__: TRICE16( ID(15655), "tst:TRICE16   %%6d ->  %6d  %6d  %6d  %6d\n",         1, 0x7fff, 0x8000, 0xffff);
        break; case __LINE__: TRICE16( ID(15656), "tst:TRICE16   %%7o -> %7o %7o %7o %7o\n",             1, 0x7fff, 0x8000, 0xffff);
        break; case __LINE__: TRICE32( ID(15657), "tst:TRICE32 %%09x ->      %09x      %09x       %09x     %09x\n", 1, 0x7fffffff, 0x80000000, 0xffffffff);
        break; case __LINE__: TRICE32( ID(15658), "tst:TRICE32 %%10d ->     %10d     %10d     %10d    %10x\n",      1, 0x7fffffff, 0x80000000, 0xffffffff);
        break; case __LINE__: TRICE32( ID(15659), "att:TRICE32 %40b\n", 0xAAAAAAAA);
        break; case __LINE__: TRICE64( ID(15660), "tst:TRICE64 %%09x ->      %09x      %09x       %09x     %09x\n", 1, 0x7fffffffffffffff, 0x8000000000000000, 0xffffffffffffffff);
        break; case __LINE__: TRICE64( ID(15661), "tst:TRICE64 %%10d ->     %10d     %10d     %10d    %10x\n",      1, 0x7fffffffffffffff, 0x8000000000000000, 0xffffffffffffffff);
        break; case __LINE__: TRICE64( ID(15662), "att:TRICE64 %70b\n", 0xAAAAAAAAAAAAAAAA);
        break; case __LINE__: TRICE( ID(15663), "sig:Legacy TRICE8\n" );
        break; case __LINE__: TRICE8_1( ID(15664), "tst:TRICE8_1 %02x\n", 0xA1);
        break; case __LINE__: TRICE8_2( ID(15665), "tst:TRICE8_2 %02x %02x\n", 0xA1, 0xA2);
        break; case __LINE__: TRICE8_3( ID(15666), "tst:TRICE8_3 %02x %02x %02x\n", 0xA1, 0xA2, 0xA3);
        break; case __LINE__: TRICE8_4( ID(15667), "tst:TRICE8_4 %02x %02x %02x %02x\n", 0xA1, 0xA2, 0xA3, 0xA4);
        break; case __LINE__: TRICE8_5( ID(15668), "tst:TRICE8_5 %02x %02x %02x %02x %02x\n", 0xA1, 0xA2, 0xA3, 0xA4, 0xA5 );
        break; case __LINE__: TRICE8_6( ID(15669), "tst:TRICE8_6 %02x %02x %02x %02x %02x %02x\n", 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6);
        break; case __LINE__: TRICE8_7( ID(15670), "tst:TRICE8_7 %02x %02x %02x %02x %02x %02x %02x\n", 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7);
        break; case __LINE__: TRICE8_8( ID(15671), "tst:TRICE8_8 %02X %02X %02X %02X %02x %02x %02x %02x\n", 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8); //exp: time: 842,150_450default: tst:TRICE8_8 A1 A2 A3 A4 a5 a6 a7 a8
        break; case __LINE__: TRICE8_1( ID(15672), "tst:TRICE8_1 %d\n",                      -1);
        break; case __LINE__: TRICE8_2( ID(15673), "tst:TRICE8_2 %d %d\n",                   -1, -2);
        break; case __LINE__: TRICE8_3( ID(15682), "tst:TRICE8_3 %d %d %d\n",                -1, -2, -3);
        break; case __LINE__: TRICE8_4( ID(15675), "tst:TRICE8_4 %d %d %d %d\n",             -1, -2, -3, -4);
        break; case __LINE__: TRICE8_5( ID(15676), "tst:TRICE8_5 %d %d %d %d %d\n",          -1, -2, -3, -4, -5);
        break; case __LINE__: TRICE8_6( ID(15685), "tst:TRICE8_6 %d %d %d %d %d %d\n",       -1, -2, -3, -4, -5, -6);
        break; case __LINE__: TRICE8_7( ID(15686), "tst:TRICE8_7 %d %d %d %d %d %d %d\n",    -1, -2, -3, -4, -5, -6, -7);
        break; case __LINE__: TRICE8_8( ID(15687), "tst:TRICE8_8 %d %d %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6, -7, -8);
        break; case __LINE__: TRICE8_1( ID(15680), "tst:TRICE8_1 %d\n", 1);
        break; case __LINE__: TRICE8_2( ID(15681), "tst:TRICE8_2 %d %d\n", 1, 2);
        break; case __LINE__: TRICE8_3( ID(15674), "tst:TRICE8_3 %d %d %d\n", 1, 2, 3);
        break; case __LINE__: TRICE8_4( ID(15683), "tst:TRICE8_4 %d %d %d %d\n", 1, 2, 3, 4);
        break; case __LINE__: TRICE8_5( ID(15684), "tst:TRICE8_5 %d %d %d %d %d\n", 1, 2, 3, 4, 5);
        break; case __LINE__: TRICE8_6( ID(15677), "tst:TRICE8_6 %d %d %d %d %d %d\n", 1, 2, 3, 4, 5, 6);
        break; case __LINE__: TRICE8_7( ID(15678), "tst:TRICE8_7 %d %d %d %d %d %d %d\n", 1, 2, 3, 4, 5, 6, 7);
        break; case __LINE__: TRICE8_8( ID(15679), "tst:TRICE8_8 %d %d %d %d %d %d %d %d\n", 1, 2, 3, 4, 5, 6, 7, 8);
        break; case __LINE__: TRICE8_1( ID(15688), "tst:TRICE8_1 %u\n", 201);
        break; case __LINE__: TRICE8_2( ID(15689), "tst:TRICE8_2 %u %u\n", 201, 202);
        break; case __LINE__: TRICE8_3( ID(15690), "tst:TRICE8_3 %u %u %u\n", 201, 202, 203);
        break; case __LINE__: TRICE8_4( ID(15691), "tst:TRICE8_4 %u %u %u %u\n", 201, 202, 203, 204);
        break; case __LINE__: TRICE8_5( ID(15692), "tst:TRICE8_5 %u %u %u %u %u\n", 201, 202, 203, 204, 205);
        break; case __LINE__: TRICE8_6( ID(15693), "tst:TRICE8_6 %u %u %u %u %u %u\n", 201, 202, 203, 204, 205, 206);
        break; case __LINE__: TRICE8_7( ID(15694), "tst:TRICE8_7 %u %u %u %u %u %u %u\n", 201, 202, 203, 204, 205, 206, 207);
        break; case __LINE__: TRICE8_8( ID(15695), "tst:TRICE8_8 %u %u %u %u %u %u %u %u\n", 201, 202, 203, 204, 205, 206, 207, 208);
        break; case __LINE__: TRICE8_8( ID(15696), "tst:TRICE8_1 %%d=%d, %%u=%u, 0x%%x=0x%x, 0x%%2x=0x%2x, 0x%%02x=0x%02x, 0x%%3x=0x%3x, 0x%%03x=0x%03x, %%b=%b\n", 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81);

        break; case __LINE__: TRICE    ( ID(15697), "sig:Legacy TRICE16-64\n" );
        break; case __LINE__: TRICE16_1( ID(15698), "tst:TRICE16_1 %d\n", -111);
        break; case __LINE__: TRICE16_2( ID(15699), "tst:TRICE16_2 %d %d\n", -111, -222);
        break; case __LINE__: TRICE16_3( ID(15700), "tst:TRICE16_3 %d %d %d\n", -111, -222, -333);
        break; case __LINE__: TRICE16_4( ID(15701), "tst:TRICE16_4 %d %d %d %d\n", -111, -222, -333, -444);
        break; case __LINE__: TRICE32_1( ID(15702), "tst:TRICE32_1 %08x\n", 0x0123cafe);
        break; case __LINE__: TRICE32_1( ID(15703), "tst:TRICE32_1 %d\n", -111);
        break; case __LINE__: TRICE32_2( ID(15704), "tst:TRICE32_2 %x %x\n", -111, -222);
        break; case __LINE__: TRICE32_2( ID(15705), "tst:TRICE32_2 %d %d\n", -111, -222);
        break; case __LINE__: TRICE32_3( ID(15706), "tst:TRICE32_3 %x %x %x\n", -111, -222, -333);
        break; case __LINE__: TRICE32_3( ID(15707), "tst:TRICE32_3 %d %d %d\n", -111, -222, -333);
        break; case __LINE__: TRICE32_4( ID(15708), "tst:TRICE32_4 %x %x %x %x\n", -111, -222, -333, -444);
        break; case __LINE__: TRICE32_4( ID(15709), "tst:TRICE32_4 %d %d %d %d\n", -111, -222, -333, -444);
        break; case __LINE__: TRICE64_1( ID(15710), "tst:TRICE64_1 %d\n", -111);
        break; case __LINE__: TRICE64_2( ID(15711), "tst:TRICE64_2 %d %d\n", -111, -222);
        break; case __LINE__: TRICE16_1( ID(15712), "tst:TRICE16_1 %u\n", 60001);
        break; case __LINE__: TRICE16_2( ID(15713), "tst:TRICE16_2 %u %u\n", 60001, 60002);
        break; case __LINE__: TRICE16_3( ID(15714), "tst:TRICE16_3 %u %u %u\n", 60001, 60002, 60003);
        break; case __LINE__: TRICE16_4( ID(15715), "tst:TRICE16_4 %u %u %u %u\n", 60001, 60002, 60003, 60004);
        break; case __LINE__: TRICE32_1( ID(15716), "tst:TRICE32_1 %u\n", 4000000001);
        break; case __LINE__: TRICE32_2( ID(15717), "tst:TRICE32_2 %u %u\n", 4000000001, 4000000002);
        break; case __LINE__: TRICE32_3( ID(15718), "tst:TRICE32_3 %u %u %u\n", 4000000001, 4000000002, 4000000003);
        break; case __LINE__: TRICE32_4( ID(15719), "tst:TRICE32_4 %u %u %u %u\n", 4000000001, 4000000002, 4000000003, 4000000004);
        break; case __LINE__: TRICE64_1( ID(15720), "tst:TRICE64_1 %x\n", -1);
        break; case __LINE__: TRICE64_2( ID(15721), "tst:TRICE64_2 %x %x\n", -1, -2);
        break; case __LINE__: TRICE64_1( ID(15722), "tst:TRICE64_1 %u\n", -1);
        break; case __LINE__: TRICE64_2( ID(15723), "tst:TRICE64_2 %u %u\n", -1, -2);

        break; case __LINE__: TRICE( ID(15724), "sig:colored single letters and several TRICE macros in one line\n" );
        break; case __LINE__: TRICE( ID(15725), "e:A");
        break; case __LINE__: TRICE( ID(15726), "w:B");
        break; case __LINE__: TRICE( ID(15745), "a:c");
        break; case __LINE__: TRICE( ID(15746), "wr:d");
        break; case __LINE__: TRICE( ID(15747), "rd:e\n");
        break; case __LINE__: TRICE( ID(15730), "diag:f");
        break; case __LINE__: TRICE( ID(15731), "d:G");
        break; case __LINE__: TRICE( ID(15732), "t:H");
        break; case __LINE__: TRICE( ID(15733), "time:i");
        break; case __LINE__: TRICE( ID(15734), "message:J");
        break; case __LINE__: TRICE( ID(15735), "dbg:k\n");
        break; case __LINE__: TRICE( ID(15736), "1");
        break; case __LINE__: TRICE( ID(15737), "2");
        break; case __LINE__: TRICE( ID(15738), "3");
        break; case __LINE__: TRICE( ID(15739), "4");
        break; case __LINE__: TRICE( ID(15740), "e:7");
        break; case __LINE__: TRICE( ID(15741), "m:12");
        break; case __LINE__: TRICE( ID(15742), "m:123\n");
        break; case __LINE__: TRICE( ID(15743), "e:A"); TRICE( ID(15744), "w:B"); TRICE( ID(15727), "a:c");
        break; case __LINE__: TRICE( ID(15728), "wr:d"); TRICE( ID(15729), "rd:e\n"); TRICE( ID(15748), "diag:f");

        break; case __LINE__: TRICE( ID(15749), "sig:TRICE8 with variable param count 1 to 12\n" );
        break; case __LINE__: TRICE8( ID(15750), "tst:TRICE8 %d\n", -1 );
        break; case __LINE__: TRICE8( ID(15751), "tst:TRICE8 %d %d\n", -1, -2 );
        break; case __LINE__: TRICE8( ID(15752), "tst:TRICE8 %d %d %d\n", -1, -2, -3 );
        break; case __LINE__: TRICE8( ID(15753), "tst:TRICE8 %d %d %d %d\n", -1, -2, -3, -4 );
        break; case __LINE__: TRICE8( ID(15754), "tst:TRICE8 %d %d %d %d %d\n", -1, -2, -3, -4, -5 );
        break; case __LINE__: TRICE8( ID(15755), "tst:TRICE8 %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6 );
        break; case __LINE__: TRICE8( ID(15756), "tst:TRICE8 %d %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6, -7 );
        break; case __LINE__: TRICE8( ID(15757), "tst:TRICE8 %d %d %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );
        break; case __LINE__: TRICE8( ID(15758), "tst:TRICE8 %d %d %d %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );
        break; case __LINE__: TRICE8( ID(15759), "tst:TRICE8 %d %d %d %d %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10 );
        break; case __LINE__: TRICE8( ID(15760), "tst:TRICE8 %d %d %d %d %d %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );
        break; case __LINE__: TRICE8( ID(15761), "tst:TRICE8 %d %d %d %d %d %d %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 );
        break; case __LINE__: TRICE8( ID(15762), "tst:TRICE8 %t %b %x %X %d %u %o %O %p\n", -3, -3, -3, -3, -3, -3, -3, -3, -3 );
        break; case __LINE__: TRICE8_1 ( ID(15763), "tst:TRICE8_1  %d\n", -1 );
        break; case __LINE__: TRICE8_2 ( ID(15764), "tst:TRICE8_2  %d %d\n", -1, -2 );
        break; case __LINE__: TRICE8_3 ( ID(15765), "tst:TRICE8_3  %d %d %d\n", -1, -2, -3 );
        break; case __LINE__: TRICE8_4 ( ID(15766), "tst:TRICE8_4  %d %d %d %d\n", -1, -2, -3, -4 );
        break; case __LINE__: TRICE8_5 ( ID(15767), "tst:TRICE8_5  %d %d %d %d %d\n", -1, -2, -3, -4, -5 );
        break; case __LINE__: TRICE8_6 ( ID(15768), "tst:TRICE8_6  %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6 );
        break; case __LINE__: TRICE8_7 ( ID(15769), "tst:TRICE8_7  %d %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6, -7 );
        break; case __LINE__: TRICE8_8 ( ID(15770), "tst:TRICE8_8  %d %d %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );
        break; case __LINE__: TRICE8_9 ( ID(15771), "tst:TRICE8_9  %d %d %d %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );
        break; case __LINE__: TRICE8_10( ID(15772), "tst:TRICE8_10 %d %d %d %d %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10 );
        break; case __LINE__: TRICE8_11( ID(15773), "tst:TRICE8_11 %d %d %d %d %d %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );
        break; case __LINE__: TRICE8_12( ID(15774), "tst:TRICE8_12 %d %d %d %d %d %d %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 );
        break; case __LINE__: TRICE8   ( ID(15775), "tst:TRICE8   %t %b %x %X %d %u %o %O %p\n", -3, -3, -3, -3, -3, -3, -3, -3, -3 );
        break; case __LINE__: TRICE8_9 ( ID(15776), "tst:TRICE8_9 %t %b %x %X %d %u %o %O %p\n", -3, -3, -3, -3, -3, -3, -3, -3, -3 );

        break; case __LINE__: TRICE( ID(15777), "sig:TRICE16 with variable param count 1 to 12\n" );
        break; case __LINE__: TRICE16( ID(15778), "tst:TRICE16 %d\n", -1 );
        break; case __LINE__: TRICE16( ID(15779), "tst:TRICE16 %d %d\n", -1, -2 );
        break; case __LINE__: TRICE16( ID(15780), "tst:TRICE16 %d %d %d\n", -1, -2, -3 );
        break; case __LINE__: TRICE16( ID(15781), "tst:TRICE16 %d %d %d %d\n", -1, -2, -3, -4 );
        break; case __LINE__: TRICE16( ID(15782), "tst:TRICE16 %d %d %d %d %d\n", -1, -2, -3, -4, -5 );
        break; case __LINE__: TRICE16( ID(15783), "tst:TRICE16 %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6 );
        break; case __LINE__: TRICE16( ID(15784), "tst:TRICE16 %d %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6, -7 );
        break; case __LINE__: TRICE16( ID(15785), "tst:TRICE16 %d %d %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );
        break; case __LINE__: TRICE16( ID(15786), "tst:TRICE16 %d %d %d %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );
        break; case __LINE__: TRICE16( ID(15787), "tst:TRICE16 %d %d %d %d %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10 );
        break; case __LINE__: TRICE16( ID(15788), "tst:TRICE16 %d %d %d %d %d %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );
        break; case __LINE__: TRICE16( ID(15789), "tst:TRICE16 %d %d %d %d %d %d %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 );
        break; case __LINE__: TRICE16( ID(15790), "tst:TRICE16 %t %b %x %X %d %u %o %O %p\n", 3, 3, 3, 3, 3, 3, 3, 3, 3 );
        break; case __LINE__: TRICE16_1 ( ID(15791), "tst:TRICE16_1  %d\n", -1 );
        break; case __LINE__: TRICE16_2 ( ID(15792), "tst:TRICE16_2  %d %d\n", -1, -2 );
        break; case __LINE__: TRICE16_3 ( ID(15793), "tst:TRICE16_3  %d %d %d\n", -1, -2, -3 );
        break; case __LINE__: TRICE16_4 ( ID(15794), "tst:TRICE16_4  %d %d %d %d\n", -1, -2, -3, -4 );
        break; case __LINE__: TRICE16_5 ( ID(15795), "tst:TRICE16_5  %d %d %d %d %d\n", -1, -2, -3, -4, -5 );
        break; case __LINE__: TRICE16_6 ( ID(15796), "tst:TRICE16_6  %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6 );
        break; case __LINE__: TRICE16_7 ( ID(15797), "tst:TRICE16_7  %d %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6, -7 );
        break; case __LINE__: TRICE16_8 ( ID(15798), "tst:TRICE16_8  %d %d %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );
        break; case __LINE__: TRICE16_9 ( ID(15799), "tst:TRICE16_9  %d %d %d %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );
        break; case __LINE__: TRICE16_10( ID(15800), "tst:TRICE16_10 %d %d %d %d %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10 );
        break; case __LINE__: TRICE16_11( ID(15801), "tst:TRICE16_11 %d %d %d %d %d %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );
        break; case __LINE__: TRICE16_12( ID(15802), "tst:TRICE16_12 %d %d %d %d %d %d %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 );
        break; case __LINE__: TRICE16_9 ( ID(15803), "tst:TRICE16 %t %b %x %X %d %u %o %O %p\n", 3, 3, 3, 3, 3, 3, 3, 3, 3 );

        break; case __LINE__: TRICE( ID(15804), "sig:TRICE32 with variable param count 1 to 12\n" );
        break; case __LINE__: TRICE32( ID(15805), "tst:TRICE32 %d\n", -1 );
        break; case __LINE__: TRICE32( ID(15806), "tst:TRICE32 %d %d\n", -1, -2 );
        break; case __LINE__: TRICE32( ID(15807), "tst:TRICE32 %d %d %d\n", -1, -2, -3 );
        break; case __LINE__: TRICE32( ID(15808), "tst:TRICE32 %d %d %d %d\n", -1, -2, -3, -4 );
        break; case __LINE__: TRICE32( ID(15809), "tst:TRICE32 %d %d %d %d %d\n", -1, -2, -3, -4, -5 );
        break; case __LINE__: TRICE32( ID(15810), "tst:TRICE32 %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6 );
        break; case __LINE__: TRICE32( ID(15811), "tst:TRICE32 %d %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6, -7 );
        break; case __LINE__: TRICE32( ID(15812), "tst:TRICE32 %d %d %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );
        break; case __LINE__: TRICE32( ID(15813), "tst:TRICE32 %d %d %d %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );
        break; case __LINE__: TRICE32( ID(15814), "tst:TRICE32 %d %d %d %d %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10 );
        break; case __LINE__: TRICE32( ID(15815), "tst:TRICE32 %d %d %d %d %d %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );
        break; case __LINE__: TRICE32( ID(15816), "tst:TRICE32 %d %d %d %d %d %d %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 );
        break; case __LINE__: TRICE32( ID(15817), "tst:TRICE32 %t %b %x %X %d %u %o %O %p %e %f %g\n", 3, 3, 3, 3, 3, 3, 3, 3, 3, aFloat(3.14159), aFloat(3.14159), aFloat(3.14159));
        break; case __LINE__: TRICE32_1 ( ID(15818), "tst:TRICE32_1  %d\n", -1 );
        break; case __LINE__: TRICE32_2 ( ID(15819), "tst:TRICE32_2  %d %d\n", -1, -2 );
        break; case __LINE__: TRICE32_3 ( ID(15820), "tst:TRICE32_3  %d %d %d\n", -1, -2, -3 );
        break; case __LINE__: TRICE32_4 ( ID(15821), "tst:TRICE32_4  %d %d %d %d\n", -1, -2, -3, -4 );
        break; case __LINE__: TRICE32_5 ( ID(15822), "tst:TRICE32_5  %d %d %d %d %d\n", -1, -2, -3, -4, -5 );
        break; case __LINE__: TRICE32_6 ( ID(15823), "tst:TRICE32_6  %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6 );
        break; case __LINE__: TRICE32_7 ( ID(15824), "tst:TRICE32_7  %d %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6, -7 );
        break; case __LINE__: TRICE32_8 ( ID(15825), "tst:TRICE32_8  %d %d %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );
        break; case __LINE__: TRICE32_9 ( ID(15826), "tst:TRICE32_9  %d %d %d %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );
        break; case __LINE__: TRICE32_10( ID(15827), "tst:TRICE32_10 %d %d %d %d %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10 );
        break; case __LINE__: TRICE32_11( ID(15828), "tst:TRICE32_11 %d %d %d %d %d %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );
        break; case __LINE__: TRICE32_12( ID(15829), "tst:TRICE32_12 %d %d %d %d %d %d %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 );
        break; case __LINE__: TRICE32   ( ID(15830), "tst:TRICE32    %t %b %x %X %d %u %o %O %p %e %f %g\n", 3, 3, 3, 3, 3, 3, 3, 3, 3, aFloat(3.14159), aFloat(3.14159), aFloat(3.14159));
        break; case __LINE__: TRICE32_12( ID(15831), "tst:TRICE32_12 %t %b %x %X %d %u %o %O %p %e %f %g\n", 3, 3, 3, 3, 3, 3, 3, 3, 3, aFloat(3.14159), aFloat(3.14159), aFloat(3.14159));

        break; case __LINE__: TRICE( ID(15832), "sig:TRICE64 with variable param count 1 to 12\n" );
        break; case __LINE__: TRICE64( ID(15833), "tst:TRICE64 %d\n", -1 );
        break; case __LINE__: TRICE64( ID(15834), "tst:TRICE64 %d %d\n", -1, -2 );
        break; case __LINE__: TRICE64( ID(15835), "tst:TRICE64 %d %d %d\n", -1, -2, -3 );
        break; case __LINE__: TRICE64( ID(15836), "tst:TRICE64 %d %d %d %d\n", -1, -2, -3, -4 );
        break; case __LINE__: TRICE64( ID(15837), "tst:TRICE64 %d %d %d %d %d\n", -1, -2, -3, -4, -5 );
        break; case __LINE__: TRICE64( ID(15838), "tst:TRICE64 %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6 );
        break; case __LINE__: TRICE64( ID(15839), "tst:TRICE64 %d %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6, -7 );
        break; case __LINE__: TRICE64( ID(15840), "tst:TRICE64 %d %d %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );
        break; case __LINE__: TRICE64( ID(15841), "tst:TRICE64 %d %d %d %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );
        break; case __LINE__: TRICE64( ID(15842), "tst:TRICE64 %d %d %d %d %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10 );
        break; case __LINE__: TRICE64( ID(15843), "tst:TRICE64 %d %d %d %d %d %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );
        break; case __LINE__: TRICE64( ID(15844), "tst:TRICE64 %d %d %d %d %d %d %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 );
        break; case __LINE__: TRICE64( ID(15845), "tst:TRICE64 %t %b %x %X %d %u %o %O %p %e %f %g\n", 3, 3, 3, 3, 3, 3, 3, 3, 3, aDouble(3.14159), aDouble(3.14159), aDouble(3.14159));
        break; case __LINE__: TRICE64_1 ( ID(15846), "tst:TRICE64_1  %d\n", -1 );
        break; case __LINE__: TRICE64_2 ( ID(15847), "tst:TRICE64_2  %d %d\n", -1, -2 );
        break; case __LINE__: TRICE64_3 ( ID(15848), "tst:TRICE64_3  %d %d %d\n", -1, -2, -3 );
        break; case __LINE__: TRICE64_4 ( ID(15849), "tst:TRICE64_4  %d %d %d %d\n", -1, -2, -3, -4 );
        break; case __LINE__: TRICE64_5 ( ID(15850), "tst:TRICE64_5  %d %d %d %d %d\n", -1, -2, -3, -4, -5 );
        break; case __LINE__: TRICE64_6 ( ID(15851), "tst:TRICE64_6  %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6 );
        break; case __LINE__: TRICE64_7 ( ID(15852), "tst:TRICE64_7  %d %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6, -7 );
        break; case __LINE__: TRICE64_8 ( ID(15853), "tst:TRICE64_8  %d %d %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );
        break; case __LINE__: TRICE64_9 ( ID(15854), "tst:TRICE64_9  %d %d %d %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );
        break; case __LINE__: TRICE64_10( ID(15855), "tst:TRICE64_10 %d %d %d %d %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10 );
        break; case __LINE__: TRICE64_11( ID(15856), "tst:TRICE64_11 %d %d %d %d %d %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );
        break; case __LINE__: TRICE64_12( ID(15857), "tst:TRICE64_12 %d %d %d %d %d %d %d %d %d %d %d %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 );
        break; case __LINE__: TRICE64_12( ID(15858), "tst:TRICE64_12 %t %b %x %X %d %u %o %O %p %e %f %g\n", 3, 3, 3, 3, 3, 3, 3, 3, 3, aDouble(3.14159), aDouble(3.14159), aDouble(3.14159));

        break; case __LINE__: TRICE( ID(15859), "att:positive and negative float in format variants\n");
        break; case __LINE__: TRICE( ID(15860), "rd:TRICE float %f (%%f)\n", aFloat(x) );
        break; case __LINE__: TRICE( ID(15866), "rd:TRICE float %9f (%%9f)\n", aFloat(x) );
        break; case __LINE__: TRICE( ID(15862), "rd:TRICE float %.9f (%%.9f)\n", aFloat(x) );
        break; case __LINE__: TRICE( ID(15863), "rd:TRICE float %9.f (%%9.f)\n", aFloat(x) );
        break; case __LINE__: TRICE( ID(15864), "rd:TRICE float %9.6f (%%9.6f)\n", aFloat(x) );
        break; case __LINE__: TRICE( ID(15865), "rd:TRICE float %f (%%f)\n", aFloat(-x) );
        break; case __LINE__: TRICE( ID(15861), "rd:TRICE float %9f (%%9f)\n", aFloat(-x) );
        break; case __LINE__: TRICE( ID(15867), "rd:TRICE float %.9f (%%.9f)\n", aFloat(-x) );
        break; case __LINE__: TRICE( ID(15868), "rd:TRICE float %9.f (%%9.f)\n", aFloat(-x) );
        break; case __LINE__: TRICE( ID(15869), "rd:TRICE float %9.6f (%%9.6f)\n", aFloat(-x) );
        break; case __LINE__: TRICE( ID(15875), "rd:TRICE float %+f (%%f)\n", aFloat(x) );
        break; case __LINE__: TRICE( ID(15876), "rd:TRICE float %+9f (%%9f)\n", aFloat(x) );
        break; case __LINE__: TRICE( ID(15877), "rd:TRICE float %+.9f (%%.9f)\n", aFloat(x) );
        break; case __LINE__: TRICE( ID(15873), "rd:TRICE float %+9.f (%%9.f)\n", aFloat(x) );
        break; case __LINE__: TRICE( ID(15874), "rd:TRICE float %+9.6f (%%9.6f)\n", aFloat(x) );
        break; case __LINE__: TRICE( ID(15870), "rd:TRICE float %+f (%%f)\n", aFloat(-x) );
        break; case __LINE__: TRICE( ID(15871), "rd:TRICE float %+9f (%%9f)\n", aFloat(-x) );
        break; case __LINE__: TRICE( ID(15872), "rd:TRICE float %+.9f (%%.9f)\n", aFloat(-x) );
        break; case __LINE__: TRICE( ID(15878), "rd:TRICE float %+9.f (%%9.f)\n", aFloat(-x) );
        break; case __LINE__: TRICE( ID(15879), "rd:TRICE float %+9.6f (%%9.6f)\n", aFloat(-x) );
        break; case __LINE__: TRICE( ID(15885), "rd:TRICE float %-f (%%f)\n", aFloat(x) );
        break; case __LINE__: TRICE( ID(15886), "rd:TRICE float %-9f (%%9f)\n", aFloat(x) );
        break; case __LINE__: TRICE( ID(15887), "rd:TRICE float %-.9f (%%.9f)\n", aFloat(x) );
        break; case __LINE__: TRICE( ID(15888), "rd:TRICE float %-9.f (%%9.f)\n", aFloat(x) );
        break; case __LINE__: TRICE( ID(15884), "rd:TRICE float %-9.6f (%%9.6f)\n", aFloat(x) );
        break; case __LINE__: TRICE( ID(15880), "rd:TRICE float %-f (%%f)\n", aFloat(-x) );
        break; case __LINE__: TRICE( ID(15881), "rd:TRICE float %-9f (%%9f)\n", aFloat(-x) );
        break; case __LINE__: TRICE( ID(15882), "rd:TRICE float %-.9f (%%.9f)\n", aFloat(-x) );
        break; case __LINE__: TRICE( ID(15883), "rd:TRICE float %-9.f (%%9.f)\n", aFloat(-x) );
        break; case __LINE__: TRICE( ID(15889), "rd:TRICE float %-9.6f (%%9.6f)\n", aFloat(-x) );
        break; case __LINE__: TRICE( ID(15890), "att:positive float & double in variants\n");
        break; case __LINE__: TRICE32_1( ID(15891), "rd:TRICE32_1 float %e (%%e)\n", aFloat(x) );
        break; case __LINE__: TRICE32_1( ID(15892), "rd:TRICE32_1 float %f (%%f)\n", aFloat(x) );
        break; case __LINE__: TRICE32_1( ID(15893), "rd:TRICE32_1 float %g (%%g)\n", aFloat(x) );
        break; case __LINE__: TRICE32_1( ID(15894), "rd:TRICE32_1 float %E (%%E)\n", aFloat(x) );
        break; case __LINE__: TRICE32_1( ID(15895), "rd:TRICE32_1 float %F (%%F)\n", aFloat(x) );
        break; case __LINE__: TRICE32_1( ID(15896), "rd:TRICE32_1 float %G (%%G)\n", aFloat(x) );
        break; case __LINE__: TRICE32  ( ID(15897), "rd:TRICE32 float %e (%%e)\n", aFloat(x) );
        break; case __LINE__: TRICE32  ( ID(15898), "rd:TRICE32 float %f (%%f)\n", aFloat(x) );
        break; case __LINE__: TRICE32  ( ID(15899), "rd:TRICE32 float %g (%%g)\n", aFloat(x) );
        break; case __LINE__: TRICE32  ( ID(15900), "rd:TRICE32 float %E (%%E)\n", aFloat(x) );
        break; case __LINE__: TRICE32  ( ID(15901), "rd:TRICE32 float %F (%%F)\n", aFloat(x) );
        break; case __LINE__: TRICE32  ( ID(15902), "rd:TRICE32 float %G (%%G)\n", aFloat(x) );
        break; case __LINE__: TRICE    ( ID(15903), "rd:TRICE float %e (%%e)\n", aFloat(x) );
        break; case __LINE__: TRICE    ( ID(15904), "rd:TRICE float %f (%%f)\n", aFloat(x) );
        break; case __LINE__: TRICE    ( ID(15924), "rd:TRICE float %g (%%g)\n", aFloat(x) );
        break; case __LINE__: TRICE    ( ID(15906), "rd:TRICE float %E (%%E)\n", aFloat(x) );
        break; case __LINE__: TRICE    ( ID(15907), "rd:TRICE float %F (%%F)\n", aFloat(x) );
        break; case __LINE__: TRICE    ( ID(15927), "rd:TRICE float %G (%%G)\n", aFloat(x) );
        break; case __LINE__: TRICE64  ( ID(15928), "rd:TRICE64 double %e (%%e), aDouble(y)\n", aDouble(y) );
        break; case __LINE__: TRICE64  ( ID(15910), "rd:TRICE64 double %f (%%f), aDouble(y)\n", aDouble(y) );
        break; case __LINE__: TRICE64  ( ID(15930), "rd:TRICE64 double %g (%%g), aDouble(y)\n", aDouble(y) );
        break; case __LINE__: TRICE64  ( ID(15931), "rd:TRICE64 double %E (%%E), aDouble(y)\n", aDouble(y) );
        break; case __LINE__: TRICE64  ( ID(15932), "rd:TRICE64 double %F (%%F), aDouble(y)\n", aDouble(y) );
        break; case __LINE__: TRICE64  ( ID(15914), "rd:TRICE64 double %G (%%G), aDouble(y)\n", aDouble(y) );
        break; case __LINE__: TRICE64_1( ID(15915), "rd:TRICE64_1 double %e (%%e), aDouble(y)\n", aDouble(y) );
        break; case __LINE__: TRICE64_1( ID(15916), "rd:TRICE64_1 double %f (%%f), aDouble(y)\n", aDouble(y) );
        break; case __LINE__: TRICE64_1( ID(15917), "rd:TRICE64_1 double %g (%%g), aDouble(y)\n", aDouble(y) );
        break; case __LINE__: TRICE64_1( ID(15918), "rd:TRICE64_1 double %E (%%E), aDouble(y)\n", aDouble(y) );
        break; case __LINE__: TRICE64_1( ID(15919), "rd:TRICE64_1 double %F (%%F), aDouble(y)\n", aDouble(y) );
        break; case __LINE__: TRICE64_1( ID(15920), "rd:TRICE64_1 double %G (%%G), aDouble(y)\n", aDouble(y) );
        break; case __LINE__: TRICE( ID(15921), "att:negative float & double\n" );
        break; case __LINE__: TRICE( ID(15922), "rd:TRICE float %e (%%e)\n", aFloat(-x) );
        break; case __LINE__: TRICE( ID(15923), "rd:TRICE float %f (%%f)\n", aFloat(-x) );
        break; case __LINE__: TRICE( ID(15905), "rd:TRICE float %g (%%g)\n", aFloat(-x) );
        break; case __LINE__: TRICE( ID(15925), "rd:TRICE float %E (%%E)\n", aFloat(-x) );
        break; case __LINE__: TRICE( ID(15926), "rd:TRICE float %F (%%F)\n", aFloat(-x) );
        break; case __LINE__: TRICE( ID(15908), "rd:TRICE float %G (%%G)\n", aFloat(-x) );
        break; case __LINE__: TRICE64( ID(15909), "rd:TRICE64 double %e (%%e), aDouble(y)\n", aDouble(-y) );
        break; case __LINE__: TRICE64( ID(15929), "rd:TRICE64 double %f (%%f), aDouble(y)\n", aDouble(-y) );
        break; case __LINE__: TRICE64( ID(15911), "rd:TRICE64 double %g (%%g), aDouble(y)\n", aDouble(-y) );
        break; case __LINE__: TRICE64( ID(15912), "rd:TRICE64 double %E (%%E), aDouble(y)\n", aDouble(-y) );
        break; case __LINE__: TRICE64( ID(15913), "rd:TRICE64 double %F (%%F), aDouble(y)\n", aDouble(-y) );
        break; case __LINE__: TRICE64( ID(15933), "rd:TRICE64 double %G (%%G), aDouble(y)\n", aDouble(-y) );

        break; case __LINE__: TRICE  ( ID(15934), "att:formatted float & double\n" );
        break; case __LINE__: TRICE32( ID(15935), "rd:TRICE32 float %12.6e (%%12.6e)\n", aFloat(x) );
        break; case __LINE__: TRICE32( ID(15936), "rd:TRICE32 float %12.6f (%%12.6f)\n", aFloat(x) );
        break; case __LINE__: TRICE32( ID(15937), "rd:TRICE32 float %12.6g (%%12.6g)\n", aFloat(x) );
        break; case __LINE__: TRICE32( ID(15938), "rd:TRICE32 float %12.6E (%%12.6E)\n", aFloat(x) );
        break; case __LINE__: TRICE32( ID(15939), "rd:TRICE32 float %12.6F (%%12.6F)\n", aFloat(x) );
        break; case __LINE__: TRICE32( ID(15940), "rd:TRICE32 float %12.6G (%%12.6G)\n", aFloat(x) );
        break; case __LINE__: TRICE64( ID(15941), "rd:TRICE64 double %12.6e (%%12.6e), aDouble(y)\n", aDouble(y) );
        break; case __LINE__: TRICE64( ID(15942), "rd:TRICE64 double %12.6f (%%12.6f), aDouble(y)\n", aDouble(y) );
        break; case __LINE__: TRICE64( ID(15943), "rd:TRICE64 double %12.6g (%%12.6g), aDouble(y)\n", aDouble(y) );
        break; case __LINE__: TRICE64( ID(15944), "rd:TRICE64 double %12.6E (%%12.6E), aDouble(y)\n", aDouble(y) );
        break; case __LINE__: TRICE64( ID(15945), "rd:TRICE64 double %12.6F (%%12.6F), aDouble(y)\n", aDouble(y) );
        break; case __LINE__: TRICE64( ID(15946), "rd:TRICE64 double %12.6G (%%12.6G), aDouble(y)\n", aDouble(y) );

        break; case __LINE__: TRICE ( ID(15947), "att:Various single arguments\n" );
        break; case __LINE__: TRICE8( ID(15948), "rd:TRICE8 line %t (%%t ,0)\n", 0 );
        break; case __LINE__: TRICE8( ID(15949), "rd:TRICE8 line %t (%%t ,2)\n", 2 );
        break; case __LINE__: TRICE8( ID(15950), "rd:TRICE8 line %u (%%u ,-1)\n", -1 );
        break; case __LINE__: TRICE8( ID(15951), "rd:TRICE8 line %b (%%b ,-1)\n", -1 );
        break; case __LINE__: TRICE8( ID(15952), "rd:TRICE8 line %o (%%o ,-1)\n", -1 );
        break; case __LINE__: TRICE8( ID(15953), "rd:TRICE8 line %O (%%O ,-1)\n", -1 );
        break; case __LINE__: TRICE8( ID(15954), "rd:TRICE8 line %X (%%X ,-1)\n", -1 );
        break; case __LINE__: TRICE8( ID(15955), "rd:TRICE8 line %x (%%x ,-1)\n", -1 );
        break; case __LINE__: TRICE8( ID(15956), "rd:TRICE8 line %d (%%d ,-1)\n", -1 );
        break; case __LINE__: TRICE16_1( ID(15957), "rd:TRICE16_1 line %t (%%t ,0)\n", 0 );
        break; case __LINE__: TRICE16_1( ID(15958), "rd:TRICE16_1 line %t (%%t ,2)\n", 2 );
        break; case __LINE__: TRICE16_1( ID(15959), "rd:TRICE16_1 line %u (%%u -1)\n", -1 );
        break; case __LINE__: TRICE16_1( ID(15960), "rd:TRICE16_1 line %b (%%b -1)\n", -1 );
        break; case __LINE__: TRICE16_1( ID(15961), "rd:TRICE16_1 line %o (%%o -1)\n", -1 );
        break; case __LINE__: TRICE16_1( ID(15962), "rd:TRICE16_1 line %x (%%x -1)\n", -1 );
        break; case __LINE__: TRICE16_1( ID(15963), "rd:TRICE16_1 line %d (%%d -1)\n", -1 );
        break; case __LINE__: TRICE( ID(15964), "rd:TRICE line %t (%%t -1)\n", 0 );
        break; case __LINE__: TRICE( ID(15965), "rd:TRICE line %t (%%t -1)\n", 2 );
        break; case __LINE__: TRICE( ID(15966), "rd:TRICE line %u (%%u)\n", -1 );
        break; case __LINE__: TRICE( ID(15967), "rd:TRICE line %b (%%b)\n", -2 );
        break; case __LINE__: TRICE( ID(15968), "rd:TRICE line %o (%%o)\n", -3 );
        break; case __LINE__: TRICE( ID(15969), "rd:TRICE line %x (%%x)\n", -4 );
        break; case __LINE__: TRICE( ID(15970), "rd:TRICE line %d (%%d)\n", -5 );

        break; case __LINE__: TRICE_N( ID(16000), "msg:%s\n", A, 0 );
        break; case __LINE__: TRICE_N( ID(15984), "msg:%s\n", A, 1 );
        break; case __LINE__: TRICE_N( ID(15990), "msg:%s\n", A, 2 );
        break; case __LINE__: TRICE_N( ID(15971), "msg:%s\n", A, 3 );
        break; case __LINE__: TRICE_N( ID(15972), "msg:%s\n", A, 4 );
        break; case __LINE__: TRICE_N( ID(15973), "msg:%s\n", A, 5 );
        break; case __LINE__: TRICE_N( ID(15974), "msg:%s\n", A, 6 );
        break; case __LINE__: TRICE_N( ID(15975), "msg:%s\n", A, 7 );
        break; case __LINE__: TRICE_N( ID(15976), "msg:%s\n", A, 8 );
        break; case __LINE__: TRICE_N( ID(15977), "msg:%s\n", A, 9 );
        break; case __LINE__: TRICE_N( ID(15978), "msg:%s\n", A, 10 );
        break; case __LINE__: TRICE_N( ID(15979), "msg:%s\n", A, 11 );
        break; case __LINE__: TRICE_N( ID(15980), "msg:%s\n", A, 12 );
        break; case __LINE__: TRICE_N( ID(15981), "msg:%s\n", A, 13 );
        break; case __LINE__: TRICE_N( ID(15982), "msg:%s\n", A, 14 );
        break; case __LINE__: TRICE_N( ID(15983), "msg:%s\n", A, 15 );
        break; case __LINE__: TRICE_N( ID(15988), "msg:%s\n", A, 16 );
        break; case __LINE__: TRICE_N( ID(15985), "msg:%s\n", A, 17 );
        break; case __LINE__: TRICE_N( ID(15986), "msg:%s\n", A, 18 );
        break; case __LINE__: TRICE_N( ID(15987), "msg:%s\n", A, 19 );
        break; case __LINE__: TRICE_N( ID(15995), "msg:%s\n", A, 120 );
        break; case __LINE__: TRICE_N( ID(15989), "msg:%s\n", A, 121 );
        break; case __LINE__: TRICE_N( ID(15998), "msg:%s\n", A, 122 );
        break; case __LINE__: TRICE_N( ID(15991), "msg:%s\n", A, 123 );
        break; case __LINE__: TRICE_N( ID(15992), "msg:%s\n", A, 124 );
        break; case __LINE__: TRICE_N( ID(15993), "msg:%s\n", A, 125 );
        break; case __LINE__: TRICE_N( ID(15994), "msg:%s\n", A, 126 );
        break; case __LINE__: TRICE_N( ID(15996), "msg:%s\n", A, 127 );
        break; case __LINE__: TRICE_N( ID(15999), "msg:%s\n", A, 128 );
        break; case __LINE__: TRICE_N( ID(15997), "msg:%s\n", A, 129 );


        break; case __LINE__: TRICE( ID(16001), "sig:TRICE with 1 to 12 values\n" );

        break; case __LINE__: TRICE( ID(16002), "rd:TRICE %d\n", -1 );                                                                                            //exp: time: 842,150_450default: rd:TRICE -1     
        break; case __LINE__: TRICE( ID(14898), "rd:TRICE %d, %d\n", -1, -2 );                                                                                    //exp: time: 842,150_450default: rd:TRICE -1, -2 
        break; case __LINE__: TRICE( ID(16004), "rd:TRICE %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time: 842,150_450default: rd:TRICE -1, -2, -3       
        break; case __LINE__: TRICE( ID(14888), "rd:TRICE %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time: 842,150_450default: rd:TRICE -1, -2, -3, -4      
        break; case __LINE__: TRICE( ID(14901), "rd:TRICE %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time: 842,150_450default: rd:TRICE -1, -2, -3, -4, -5        
        break; case __LINE__: TRICE( ID(14902), "rd:TRICE %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time: 842,150_450default: rd:TRICE -1, -2, -3, -4, -5, -6        
        break; case __LINE__: TRICE( ID(14915), "rd:TRICE %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time: 842,150_450default: rd:TRICE -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: TRICE( ID(16009), "rd:TRICE %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time: 842,150_450default: rd:TRICE -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: TRICE( ID(14905), "rd:TRICE %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time: 842,150_450default: rd:TRICE -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: TRICE( ID(16011), "rd:TRICE %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time: 842,150_450default: rd:TRICE -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: TRICE( ID(14919), "rd:TRICE %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time: 842,150_450default: rd:TRICE -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: TRICE( ID(14908), "rd:TRICE %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time: 842,150_450default: rd:TRICE -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    

        break; case __LINE__: TRICE( ID(16014), "sig:TRICE_n with 1 to 12 values\n" );		
        break; case __LINE__: TRICE( ID(16015), "rd:TRICE_1  %d\n", -1 );                                                                                            //exp: time: 842,150_450default: rd:TRICE_1  -1     
        break; case __LINE__: TRICE( ID(16016), "rd:TRICE_2  %d, %d\n", -1, -2 );                                                                                    //exp: time: 842,150_450default: rd:TRICE_2  -1, -2 
        break; case __LINE__: TRICE( ID(16017), "rd:TRICE_3  %d, %d, %d\n", -1, -2, -3 );                                                                            //exp: time: 842,150_450default: rd:TRICE_3  -1, -2, -3       
        break; case __LINE__: TRICE( ID(16018), "rd:TRICE_4  %d, %d, %d, %d\n", -1, -2, -3, -4 );                                                                    //exp: time: 842,150_450default: rd:TRICE_4  -1, -2, -3, -4      
        break; case __LINE__: TRICE( ID(16019), "rd:TRICE_5  %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5 );                                                            //exp: time: 842,150_450default: rd:TRICE_5  -1, -2, -3, -4, -5        
        break; case __LINE__: TRICE( ID(16020), "rd:TRICE_6  %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6 );                                                    //exp: time: 842,150_450default: rd:TRICE_6  -1, -2, -3, -4, -5, -6        
        break; case __LINE__: TRICE( ID(16021), "rd:TRICE_7  %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7);                                             //exp: time: 842,150_450default: rd:TRICE_7  -1, -2, -3, -4, -5, -6, -7      
        break; case __LINE__: TRICE( ID(16022), "rd:TRICE_8  %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8 );                                    //exp: time: 842,150_450default: rd:TRICE_8  -1, -2, -3, -4, -5, -6, -7, -8       
        break; case __LINE__: TRICE( ID(16023), "rd:TRICE_9  %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );                            //exp: time: 842,150_450default: rd:TRICE_9  -1, -2, -3, -4, -5, -6, -7, -8, -9   
        break; case __LINE__: TRICE( ID(16024), "rd:TRICE_10 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);                    //exp: time: 842,150_450default: rd:TRICE_10 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10    
        break; case __LINE__: TRICE( ID(16025), "rd:TRICE_11 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );          //exp: time: 842,150_450default: rd:TRICE_11 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11     
        break; case __LINE__: TRICE( ID(16026), "rd:TRICE_12 %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 ); //exp: time: 842,150_450default: rd:TRICE_12 -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12    


        break; case __LINE__: TRICE  ( ID(16027), "sig:TRICE16 with 1 to 12 pointer\n" );
        break; case __LINE__: TRICE16( ID(16028), "rd:TRICE16 %p\n", -1 );
        break; case __LINE__: TRICE16( ID(16029), "rd:TRICE16 %p, %p\n", -1, -2 );
        break; case __LINE__: TRICE16( ID(16030), "rd:TRICE16 %p, %p, %p\n", -1, -2, -3 );
        break; case __LINE__: TRICE16( ID(16031), "rd:TRICE16 %p, %p, %p, %p\n", -1, -2, -3, -4 );
        break; case __LINE__: TRICE16( ID(16032), "rd:TRICE16 %p, %p, %p, %p, %p\n", -1, -2, -3, -4, -5 );
        break; case __LINE__: TRICE16( ID(16033), "rd:TRICE16 %p, %p, %p, %p, %p, %p\n", -1, -2, -3, -4, -5, -6 );
        break; case __LINE__: TRICE16( ID(16034), "rd:TRICE16 %p, %p, %p, %p, %p, %p, %p\n", -1, -2, -3, -4, -5, -6, -7);
        break; case __LINE__: TRICE16( ID(16035), "rd:TRICE16 %p, %p, %p, %p, %p, %p, %p, %p\n", -1, -2, -3, -4, -5, -6, -7, -8 );
        break; case __LINE__: TRICE16( ID(16036), "rd:TRICE16 %p, %p, %p, %p, %p, %p, %p, %p, %p\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );
        break; case __LINE__: TRICE16( ID(16037), "rd:TRICE16 %p, %p, %p, %p, %p, %p, %p, %p, %p, %p\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);
        break; case __LINE__: TRICE16( ID(16038), "rd:TRICE16 %p, %p, %p, %p, %p, %p, %p, %p, %p, %p, %p\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );
        break; case __LINE__: TRICE16( ID(16039), "rd:TRICE16 %p, %p, %p, %p, %p, %p, %p, %p, %p, %p, %p, %p\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 );

        break; case __LINE__: TRICE  ( ID(16040), "sig:TRICE16 with 1 to 12 hex\n" );
        break; case __LINE__: TRICE16( ID(16041), "rd:TRICE16 %X\n", -1 );
        break; case __LINE__: TRICE16( ID(16042), "rd:TRICE16 %X, %X\n", -1, -2 );
        break; case __LINE__: TRICE16( ID(16043), "rd:TRICE16 %X, %X, %X\n", -1, -2, -3 );
        break; case __LINE__: TRICE16( ID(16044), "rd:TRICE16 %X, %X, %X, %X\n", -1, -2, -3, -4 );
        break; case __LINE__: TRICE16( ID(16045), "rd:TRICE16 %X, %X, %X, %X, %X\n", -1, -2, -3, -4, -5 );
        break; case __LINE__: TRICE16( ID(16046), "rd:TRICE16 %X, %X, %X, %X, %X, %X\n", -1, -2, -3, -4, -5, -6 );
        break; case __LINE__: TRICE16( ID(16047), "rd:TRICE16 %X, %X, %X, %X, %X, %X, %X\n", -1, -2, -3, -4, -5, -6, -7);
        break; case __LINE__: TRICE16( ID(16048), "rd:TRICE16 %X, %X, %X, %X, %X, %X, %X, %X\n", -1, -2, -3, -4, -5, -6, -7, -8 );
        break; case __LINE__: TRICE16( ID(16049), "rd:TRICE16 %X, %X, %X, %X, %X, %X, %X, %X, %X\n", -1, -2, -3, -4, -5, -6, -7, -8, -9 );
        break; case __LINE__: TRICE16( ID(16050), "rd:TRICE16 %X, %X, %X, %X, %X, %X, %X, %X, %X, %X\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10);
        break; case __LINE__: TRICE16( ID(16051), "rd:TRICE16 %X, %X, %X, %X, %X, %X, %X, %X, %X, %X, %X\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11 );
        break; case __LINE__: TRICE16( ID(16052), "rd:TRICE16 %X, %X, %X, %X, %X, %X, %X, %X, %X, %X, %X, %X\n", -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12 );


    #endif // #if TRICE_CGO == 1
    }
}

// clang-format on

static int32_t FloatToInt32(float f) {
	if (f >= 0) {
		return (int32_t)f;
	}
	return -(int32_t)-f;
}

static int64_t DoubleToInt64(double f) {
	if (f >= 0) {
		return (int64_t)f;
	}
	return -(int64_t)-f;
}

//! SCOPY is a helper macro for struct serialization.
#define SCOPY(element)                           \
	do {                                         \
		char* n = #element;                      \
		int size = sizeof(src->element);         \
		memcpy(p, &(src->element), size);        \
		p += size;                               \
		TRICE_S( ID(16053), "rd:sizeof(%8s)", n); \
		TRICE( ID(16054), " = %d\n", size);       \
	} while (0);

//! DCOPY is a helper macro for struct deserialization.
#define DCOPY(element)                           \
	do {                                         \
		char* n = #element;                      \
		int size = sizeof(dst->element);         \
		memcpy(&(dst->element), p, size);        \
		p += size;                               \
		TRICE_S( ID(16055), "rd:sizeof(%8s)", n); \
		TRICE( ID(16056), " = %d\n", size);       \
	} while (0);

typedef struct {
	float x;
	float y;
	uint8_t rgb[3];
	// float z; // it seems, that the compiler does not align this with -o3 & time !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
} Point_t; //!< Point_t is small struct type.

static int serializePoint(char* dst, const Point_t* src) {
	char* p = dst;

	SCOPY(x)
	SCOPY(y)
	SCOPY(rgb)

	return p - dst;
}

static int deserializePoint(Point_t* const dst, const char* src) {
	char const* p = src;

	DCOPY(x)
	DCOPY(y)
	DCOPY(rgb)

	return p - src;
}

typedef struct {
	float z;
	uint16_t u;
	int8_t s;
	char* addr;
	uint32_t x;
	int32_t y;
	char names[3][5];
	Point_t point[2];
	uint64_t bitmask;
} Tryout_t; //!<  Tryout_t is a struct example embedding an other struct.

static int serializeTryout(char* dst, const Tryout_t* src) {
	char* p = dst;

	SCOPY(z)
	SCOPY(u)
	SCOPY(s)
	SCOPY(addr)
	SCOPY(x)
	SCOPY(y)
	SCOPY(names)
	p += serializePoint(p, src->point);
	SCOPY(bitmask)

	return p - dst;
}

static int deserializeTryout(Tryout_t* const dst, const char* src) {
	char const* p = src;

	DCOPY(z)
	DCOPY(u)
	DCOPY(s)
	DCOPY(addr)
	DCOPY(x)
	DCOPY(y)
	DCOPY(names)
	p += deserializePoint(dst->point, p);
	DCOPY(bitmask)

	return p - src;
}

static void exampleOfManualSerialization(void) {
	Tryout_t tx;          // struct to transfer
	Tryout_t rx;          // "received" struct
	static char dst[100]; // serialized data
	char* src;            // "copy" - assume, data transferred now
	int len;              // serialized byte count

	/////////////////////////////////////////////////////////
	// fill tx with data
	tx.z = (float)123.456;
	tx.u = 44444;
	tx.addr = "Haus";
	tx.s = -2;
	tx.x = 0xaa55bb77;
	tx.y = -1000000;

	memcpy(tx.names[0], "aaa", strlen("aaa"));
	memcpy(tx.names[1], "bbbb", strlen("bbbb"));
	memcpy(tx.names[2], "ccccc", strlen("ccccc"));

	tx.point[0].x = 2.22;
	tx.point[0].y = -3.33;
	tx.point[0].rgb[0] = 0x44;
	tx.point[0].rgb[0] = 0x66;
	tx.point[0].rgb[0] = 0x88;

	tx.point[1].x = -66.66;
	tx.point[1].y = +5.5555;
	tx.point[1].rgb[0] = 0xee;
	tx.point[1].rgb[0] = 0xaa;
	tx.point[1].rgb[0] = 0xbb;

	tx.bitmask = 0xAAAA55550000FFFF;
	//
	////////////////////////////////////////////////////////

	len = serializeTryout(dst, &tx);
	TRICE( Id(16057), "inf: Tryout tx struct:");
	TRICE8_B( Id(16064), " %02x ", &tx, sizeof(tx));
	TRICE( Id(16059), "\n");

	TRICE( Id(16060), "inf: Tryout buffer:");
	TRICE8_B( Id(16058), " %02x ", dst, len); // lint !e670
	TRICE( Id(16062), "\n");

	src = dst; // "data transfer"

	len = deserializeTryout(&rx, src);
	TRICE( Id(16063), "inf: Tryout rx struct:");
	TRICE8_B( Id(16061), " %02x ", &rx, sizeof(rx));
	TRICE( Id(16065), "\n");

	TRICE( Id(16066), "inf:sizeOf(Trypout) = %d, buffer length = %d\n", sizeof(tx), len);
	TRICE8_F( Id(16067), "info:TryoutStructFunction", &tx, sizeof(tx));
	TRICE8_F( Id(16068), "info:TryoutBufferFunction", dst, len); // lint !e670
}

static void exampleOfManualJSONencoding(void) {
	typedef struct {
		int Apple, Birn;
		float Fish;
	} Ex_t;
	Ex_t Ex = {-1, 2, (float)2.781};
	TRICE( Id(16069), "att:MyStructEvaluationFunction(json:ExA{Apple:%d, Birn:%u, Fisch:%f}\n", Ex.Apple, Ex.Birn, aFloat(Ex.Fish));
}

static void dynString(int n) {
	char* s = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ.,0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ.,0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ.,0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ.,0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ.,";
	const size_t l = strlen(s);
	n = n < l ? n : l;
	// trice( iD(16070), "sig:%3d:", n ); - this gets overwritten in CGO_Test case, so we avoid it to keep testing simple.
	TRICE_N( id(16071), "wr:%s\n", s, n);
}
