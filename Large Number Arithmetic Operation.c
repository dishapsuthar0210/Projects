/*
 * CS:APP Data Lab
 *
 * <DISHA SUTHAR>
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 */

/* Instructions to Students:

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code
  must conform to the following style:

  long Funct(long arg1, long arg2, ...) {
      // brief description of how your implementation works
      long var1 = Expr1;
      ...
      long varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. (Long) integer constants 0 through 255 (0xFFL), inclusive. You are
      not allowed to use big constants such as 0xffffffffL.
  2. Function arguments and local variables (no global variables).
  3. Local variables of type int and long
  4. Unary integer operations ! ~
     - Their arguments can have types int or long
     - Note that ! always returns int, even if the argument is long
  5. Binary integer operations & ^ | + << >>
     - Their arguments can have types int or long
  6. Casting from int to long and from long to int

  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting other than between int and long.
  7. Use any data type other than int or long.  This implies that you
     cannot use arrays, structs, or unions.

  You may assume that your machine:
  1. Uses 2s complement representations for int and long.
  2. Data type int is 32 bits, long is 64.
  3. Performs right shifts arithmetically.
  4. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31 (int) or 63 (long)

EXAMPLES OF ACCEPTABLE CODING STYLE:
  //
  // pow2plus1 - returns 2^x + 1, where 0 <= x <= 63
  //
  long pow2plus1(long x) {
     // exploit ability of shifts to compute powers of 2
     // Note that the 'L' indicates a long constant
     return (1L << x) + 1L;
  }

  //
  // pow2plus4 - returns 2^x + 4, where 0 <= x <= 63
  //
  long pow2plus4(long x) {
     // exploit ability of shifts to compute powers of 2
     long result = (1L << x);
     result += 4L;
     return result;
  }

NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

CAUTION:
  Do not add an #include of <stdio.h> (or any other C library header)
  to this file.  C library headers almost always contain constructs
  that dlc does not understand.  For debugging, you can use printf,
  which is declared for you just below.  It is normally bad practice
  to declare C library functions by hand, but in this case it's less
  trouble than any alternative.

  dlc will consider each call to printf to be a violation of the
  coding style (function calls, after all, are not allowed) so you
  must remove all your debugging printf's again before submitting your
  code or testing it with dlc or the BDD checker.  */

extern int printf(const char *, ...);

/* Edit the functions below.  Good luck!  */
// 2
/*
 * copyLSB - set all bits of result to least significant bit of x
 *   Examples:
 *     copyLSB(5L) = 0xFFFFFFFFFFFFFFFFL,
 *     copyLSB(6L) = 0x0000000000000000L
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
long copyLSB(long x) {
    
    
    /* here first I did the bitwise and with 1L so that we got last bit. Then we will shift it by 63 so our LSB will be our MSB now.
     Now if our LSB was 1 then we need all 1's which can be achieved by arithmetic right shift by 63 times and if our LSB was 0 then 
     it can be achieved by arithmetic rightshift of 0L. Here I took 3 operators for doing this. */
   
    return (((x & 1L) << 63)>>63);

}
/*
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 63 (most significant)
 *   Examples: allOddBits(0xFFFFFFFDFFFFFFFDL) = 0L,
 *             allOddBits(0xAAAAAAAAAAAAAAAAL) = 1L
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 14
 *   Rating: 2
 */
long allOddBits(long x) {
    
    /* Here first we generate the pattern of alternative 1's and 0's. we generate this pattern by shifting A and 
    then will do bitwwise OR with same number. Due to this alternative pattern we set 1's in odd position and now we will do bitwise and with 
    our pattern and number then all odd positions's bits are extracted. here we donot care about even positions.
    finally if we got 101010..in our answer then we do XOR with our pattern then we got 0 as result and will do its ! but if any odd bit is 0 then
    chech_odd & x and check_odd will be two different number that's why their XOR result gives us 1 and when we do ! it gives 0 as an answer.
    here I used 11 operators.
    */
    long check_odd_bits=10L ;//A
    check_odd_bits=(check_odd_bits<<4)|check_odd_bits; //AA
    check_odd_bits=(check_odd_bits<<8)|check_odd_bits; //AAAA
    check_odd_bits=(check_odd_bits<<16)|check_odd_bits; //AAAAAAAA
    check_odd_bits=(check_odd_bits<<32)|check_odd_bits; //AAAAAAAAAAAAAAAA
    return !(check_odd_bits^(check_odd_bits & x));

    
}
/*
 * isNotEqual - return 0 if x == y, and 1 otherwise
 *   Examples: isNotEqual(5L, 5L) = 0L, isNotEqual(4L, 5L) = 1L
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
long isNotEqual(long x, long y) {
    
    /* Here the logic is very simple, we just used bitwise XOR property. As we know x XOR y= x'*y+x*y' means on same number
    XOR will return 0 and on two different number XOR will return 1. If x and y are equal then it will return 1 and as per our answer we will ! two times so 
    we can get true or false accordingly. here I used 3 operators for doing this stuff. 
    */
    
    return !(!(x^y));
}
/*
 * dividePower2 - Compute x/(2^n), for 0 <= n <= 62
 *  Round toward zero
 *   Examples: dividePower2(15L,1L) = 7L, dividePower2(-33L,4L) = -2L
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
long dividePower2(long x, long n) {

    /*
    If we have 64 bits then last n bits are for remainder and rest of 64-n bits are indicating the quotient.
    there are three case:
    i)  positive number:shift by n
    ii) negative number:convert into 1's complement,
                        shift by n, convert back into 2's complement
    iii)0x8000000000000000:shift by n
    all the above three cases can be handled by using masking bits accordingly (i.e. c)*/

    long int sign = x>>63;
    long int generator_for_deviation=!!(x^(1L<<63));
    generator_for_deviation=generator_for_deviation<<63>>63;
    long int deviation=sign & generator_for_deviation;
    return ((x+deviation)>>n)+(~(deviation)+1);      //shifting by n
}
// 3
/*
 * remainderPower2 - Compute x%(2^n), for 0 <= n <= 30
 *   Negative arguments should yield negative remainders
 *   Examples: remainderPower2(15L,2L) = 3, remainderPower2(-35L,3L) = -3L
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
long remainderPower2(long x, long n) {
    
/*  THIS IS MY FIRST LOGIC FOR THIS FUNCTION
     long int sign=x>>63;
     sign=sign<<n;
     long int y=(1L<<n)+~0;
     long int result=(y&x)|sign;
     y=!!(y&x);
     y=y<<63>>63;
     result=result&y;
     return result; */


    /*  Last n bits indicate the remainder R.
    Here the logic is split in three cases. 
    1) positive number , not divisible
    2) negative number , divisible
    3) negative number , not divisible
    our remainder will be last n bits of our actual number.
    In first case we need all 0's before our remainder , in second case we need all 0's as an answer and in third case we need all 1's before our remainder
    this logic is implimented here using 10 operators only. In above code the logic is more or less same but some things are different and number of operatoras are 
    more.
     */
    long result,sign;
    sign=x>>63; // to extract the MSb sign which decides the number is positive or negative
    long allone = ~0L; //FFFFFFFFFFFFFFFF
    
    result=x & ((1L<<n)+(allone));
    sign=(sign<<n) | result;
    return sign & ((allone) + !result);
}
/*
 * rotateLeft - Rotate x to the left by n
 *   Can assume that 0 <= n <= 63
 *   Examples:
 *      rotateLeft(0x8765432187654321L,4L) = 0x7654321876543218L
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3
 */
long rotateLeft(long x, long n) {
    

    /* here we just save our first n bits and then shift the number to the left side and then do bitwise OR with our saved first n bits.
    
    */
    long int m;
    
    m=(1L<<(n))+(~0L);      
    return (x<<n) | ((x>>(64+ ~n+1))&m); 
    
}
/*
 * bitMask - Generate a mask consisting of all 1's
 *   between lowbit and highbit
 *   Examples: bitMask(5L,3L) = 0x38L
 *   Assume 0 <= lowbit < 64, and 0 <= highbit < 64
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
long bitMask(long highbit, long lowbit) {
    //done
    /* here the logic is that first count the no of 1's to be generated then save it in one variable let say q.
       if highbit is smaller than low bit then after shifting variable s by 63 it will gives us all 1's whose ~ will give 0 and in the end result
       it will give us 0 sp on invalid case our logic is performed well. If highbit is gretaer than lowerbit then our s>>63 will give us 0's. After that we will shift to the 
       left and then q times we will do arithmetic right shift so desired no of 1's will be generated at first places then we will do logical right shift to actual position.


    */
    long s,q;
    s=highbit + (~lowbit+1L);
    q=s;
    
    s=s>>63;  //indicates the number is positive or negative based on MSB
    long p = ~s;  //if no is positive then gives all 1's else gives 0L
    s=!s;    
    s=s<<63;
    s=s>>q;
    s=s>>(63+(~highbit+1));
    
    long a = 1L;
    
    a = a << highbit << 1;

    return (s + a) & p;  //p is used to handle invalid case..
    
}
/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5L) = 0L, isPower2(8L) = 1L, isPower2(0) = 0L
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
long isPower2(long x) {
    
    /* here we used one property that if x is in power of 2 then x & (x-1) will give us 0's. we also handled some special cases like all 0's and negative numbers 
    and accordingly we do some operations . Here I used 12 operators for this function.
    */
    long y=1L;
    y=y<<63;
    y=y^x;
    return !((x & (x+ ~0L))) & !!x & !!y;
    
}
// 4
/*
 * allAsciiDigits - return 1 if each byte b in x satisfies
 *   0x30 <= b <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: allAsciiDigits(0x3031323536373839L) = 1L.
 *            allAsciiDigits(0x4031323536373839L) = 0L.
 *            allAsciiDigits(0x0031323536373839L) = 0L.
 *   Legal ops: ! ~ & ^ | << >>
 *   Max ops: 30
 *   Rating: 4
 */
long allAsciiDigits(long x) {
 /* long a=0xFF;   
    long sign,sign2,r1,r2,r3,r4,r5,r6,r7,r8;
    // long b=0xffffffffffffffe2;
    long b=0x30;
    b = ~b + 1;
    
    long y=x & a;
    sign=0x39 + (~y+1);
    sign2=y+b;
    r1=!((sign | sign2)>>63);
    
    x=x>>8;
    y=x & a;
    sign=0x39 + (~y+1);
    sign2=y+b;
    r2=!((sign | sign2)>>63);
    
    x=x>>8;
    y=x & a;
    sign=0x39 + (~y+1);
    sign2=y+b;
    r3=!((sign | sign2)>>63);
    
    x=x>>8;
    y=x & a;
    sign=0x39 + (~y+1);
    sign2=y+b;
    r4=!((sign | sign2)>>63);

    x=x>>8;
    y=x & a;
    sign=0x39 + (~y+1);
    sign2=y+b;
    r5=!((sign | sign2)>>63);
    
    x=x>>8;
    y=x & a;
    sign=0x39 + (~y+1);
    sign2=y+b;
    r6=!((sign | sign2)>>63);
    
    x=x>>8;
    y=x & a;
    sign=0x39 + (~y+1);
    sign2=y+b;
    r7=!((sign | sign2)>>63);
    
    x=x>>8;
    y=x & a;
    sign=0x39 + (~y+1);
    sign2=y+b;
    r8=!((sign | sign2)>>63);
    
     return b;
    return r1 & r2 & r3 & r4 & r5 & r6 & r7 & r8;*/  
    //this is the code with + and it took 80 operators......


    //THIS IS ANOTHER LOGIC USING XOR BUT IT TOOKS LOTS OF OPERATOR

   /* long a=0xFF,y,x1,x2,x3,x4,x5,x6,x7,x8;
    long r1=57L, r2=56L,r3=55L,r4=54L,r5=53L,r6=52L,r7=51L,r8=50L,r9=49L,r10=48L;

    y=x&a;
    x1=!((y^r1)&(y^r2)&(y^r3)&(y^r4)&(y^r5)&(y^r6)&(y^r7)&(y^r8)&(y^r9)&(y^r10));

    x=x>>8;
    y=x&a;
    x2=!((y^r1)&(y^r2)&(y^r3)&(y^r4)&(y^r5)&(y^r6)&(y^r7)&(y^r8)&(y^r9)&(y^r10));

     x=x>>8;
    y=x&a;
    x3=!((y^r1)&(y^r2)&(y^r3)&(y^r4)&(y^r5)&(y^r6)&(y^r7)&(y^r8)&(y^r9)&(y^r10));

     x=x>>8;
    y=x&a;
    x4=!((y^r1)&(y^r2)&(y^r3)&(y^r4)&(y^r5)&(y^r6)&(y^r7)&(y^r8)&(y^r9)&(y^r10));

     x=x>>8;
    y=x&a;
    x5=!((y^r1)&(y^r2)&(y^r3)&(y^r4)&(y^r5)&(y^r6)&(y^r7)&(y^r8)&(y^r9)&(y^r10));

     x=x>>8;
    y=x&a;
    x6=!((y^r1)&(y^r2)&(y^r3)&(y^r4)&(y^r5)&(y^r6)&(y^r7)&(y^r8)&(y^r9)&(y^r10));

     x=x>>8;
    y=x&a;
    x7=!((y^r1)&(y^r2)&(y^r3)&(y^r4)&(y^r5)&(y^r6)&(y^r7)&(y^r8)&(y^r9)&(y^r10));

     x=x>>8;
    y=x&a;
    x8=!((y^r1)&(y^r2)&(y^r3)&(y^r4)&(y^r5)&(y^r6)&(y^r7)&(y^r8)&(y^r9)&(y^r10));

    return (x1&x2&x3&x4&x5&x6&x7&x8);



    THIS IS OPTIMISED LOGIC.......

         We first made a base mask of hex 1010101010101010 and using
         it made masks for hex F0 and 30. Then we checked whether
         any number has lower bits with values bigger than 9 by 
         checking for A and C in lower bits.
    */

    long main_mask = 0x10;
    main_mask = main_mask | (main_mask << 8);
    main_mask = main_mask | (main_mask << 16);
    main_mask = main_mask | (main_mask << 32);
    
    long mask_F0 = main_mask | (main_mask << 1) | (main_mask << 2) | (main_mask << 3);
    long mask_30 = main_mask | (main_mask << 1);

    long result = 0;
    result = result | (mask_30 ^ (x & mask_F0));

    long mask_08 = main_mask >> 1;
    long temp = mask_08 & x;
    long mask_06 = (mask_08 >> 1) | (mask_08 >> 2);
    result = result | (((temp >> 1) | (temp >> 2)) & (x & mask_06));
    return !result;
}
/*
 * trueThreeFourths - multiplies by 3/4 rounding toward 0,
 *   avoiding errors due to overflow
 *   Examples:
 *    trueThreeFourths(11L) = 8
 *    trueThreeFourths(-9L) = -6
 *    trueThreeFourths(4611686018427387904L) = 3458764513820540928L (no
 * overflow) Legal ops: ! ~ & ^ | + << >> Max ops: 20 Rating: 4
 */
long trueThreeFourths(long x) {
  
  /*  long sign,Q,R,difference,y,z,t;
    sign=x>>63;
    Q=y/4;
    R=y%4;
    y=Q*3;
    difference=((~sign)<<1)+1;
    z=~0L;
    t=!R;
    z=z+t;
    y=y+(difference & z);

    Here the I find one logical pattern. If we do first multiplication and then division then for high numbers overflow can take places.
    so first we have to divide the number by 4 and then multiply by 3 by using addition 3 times. Now if we do so we donot get exact answer bcz we are ignoring floating 
    points. So then I found one pattern , I made 3 cases for this.

    1) If number is positive and not divisible by 4 then add (remainder -1) in final answer after doing division and multiplication
    2)If number is negative and not divisible by 4 then add (remainder +1) in the final answer after doing division and multiplication
    3)If number is divisible by 4 irresepctive of positive or negative number then we add (remainder + 0) in the final answer.

    I do above logic using shifting and another operators.In above commented code logic is same but number of operators are exceed so then I optimized it.
    */
    


    long sign = x >> 63;
    long bias = 3L;
    bias = bias & sign;
    long quotient = ((x + bias) >> 2);
    long all_ones = ~0L;
    long remainder_deviation = ~sign << 1;
    remainder_deviation = remainder_deviation + 1L;
    sign = sign << 2;
    long mask = 3L;
    long divisible_check = mask;
    long res = mask & x;
    divisible_check = !(res);
    divisible_check = all_ones + divisible_check;
    long remainder = ((res | sign) & divisible_check);
    remainder_deviation = remainder_deviation & (divisible_check);

    return quotient + quotient + quotient + (remainder + remainder_deviation);
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5L) = 2, bitCount(7L) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Rating: 4
 */
long bitCount(long x) {
     /*
        We used a method of divide and conquer and added neighbouring
        bits and added their blocks together and then added those 
        blocks and merged them together as well until we reached
        64 bits.
    */
    
    long allOnes = ~0L;

    long mask2_33 = (0x33 << 8) | 0x33;
    mask2_33 = mask2_33 << 16 | mask2_33;
    mask2_33 = mask2_33 << 32 | mask2_33;
    
    long mask1_55 = (mask2_33 << 1) ^ mask2_33;
    
    long mask3_0F = (0x0f << 8) | 0x0f;  
    mask3_0F = mask3_0F << 16 | mask3_0F;
    mask3_0F = mask3_0F << 32 | mask3_0F;

    long mask4_FF = 0xff | (0xff << 16);  
    mask4_FF = mask4_FF << 32 | mask4_FF;

    long mask5_FF = 0xff | (0xff << 8); 
    mask5_FF = mask5_FF << 32 | mask5_FF;

    long mask6_F32 = 0L;
    mask6_F32 = ~(allOnes << 32);

    x = (x & mask1_55) + ((x >> 1) & mask1_55);
    x = (x & mask2_33) + ((x >> 2) & mask2_33);
    x = (x & mask3_0F) + ((x >> 4) & mask3_0F);
    x = (x & mask4_FF) + ((x >> 8) & mask4_FF);
    x = (x & mask5_FF) + ((x >> 16) & mask5_FF);
    x = (x & mask6_F32) + ((x >> 32) & mask6_F32);

    return x;
}
