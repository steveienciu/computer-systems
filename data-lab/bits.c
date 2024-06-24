/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


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

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y)
{
	return ~(~(~x & y) & ~(x & ~y));
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void)
{
	int x = 0x1;

	return x << 31;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x)
{
	return !(~(x + 1) ^ x) & !!(x + 1);
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x)
{
	/* create initial mask */
	int mask = 0xaa;

	/* create 0xaaaaaaaa which is all odd bits toggled in mask */
	mask = mask | (mask << 8);
	mask = mask | (mask << 16);

	return !((x & mask) ^ mask);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x)
{
	return (~x + 1);
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x)
{
	/* set up for comparison */
	int min = 0x30, max = 0x39;
	/* test mininum comparison */
	int comp_min = ((x + (~min + 1)) >> 31) & 0x1;
	/* test maximum comparison */
	int comp_max = ((max + (~x + 1)) >> 31) & 0x1;

	return !(comp_min | comp_max);
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z)
{
	/* get the condition; either all ones or zeros */
	int condition = (!!x << 31) >> 31;

	/* pick between y and z */
	return ((condition & y) | (~condition & z));
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y)
{
	/* get negative of y to complete x - y */
	int negate = ~y + 1;
	/* create -1; used for moving everything down by 1 so can easily get proper answer for x = y */
	int negative_one = ~1 + 1;

	int result = (x + negate + negative_one) >> 31;

	return !!result;
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x)
{
	/* find sign of x */
	int x_sign = x >> 31;
	/* find -|x| */
	x = (x_sign & x) | (~x_sign & (~x + 1));

	return (x >> 31) + 1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x)
{
	int msb_position = 0;
    int mask = (0x1 << 31) >> 31;

    /* get the absolute value the integer */
    int sign = x >> 31;
    int x_abs = ((~sign & x) | (sign & (~x + 1))) << 1;

    msb_position = (!!(x_abs >> 16)) << 4;
    msb_position = msb_position | (!!(x_abs >> (msb_position + 8))) << 3;
    msb_position = msb_position | (!!(x_abs >> (msb_position + 4))) << 2;
    msb_position = msb_position | (!!(x_abs >> (msb_position + 2))) << 1;
    msb_position = msb_position | (!!(x_abs >> (msb_position + 1)));

    /* check if integer is -1 */
    int condition1 = (!(~x & mask) << 31) >> 31;
    /* check if integer is Tmin */
    int condition2 = ((!(x ^ (0x1 << 31))) << 31) >> 31;

     /* decide how many bits are needed using the two edge cases conditions */
     msb_position = (~condition1 & ~condition2 & (msb_position + 1)) | (condition1 & ~condition2 & msb_position) | (~condition1 & condition2 & 0x20);

     return msb_position;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf)
{
	/* have over 30 ops but i would only reach >30 if i did not handle edge cases */

    /* create masks for the three parts of float number */
    unsigned sign_mask = 0x1 << 31;
    unsigned exp_mask = 0xff << 23;
    unsigned frac_mask = ~((0xff << 24) | (0x1 << 23));

    /* extract the three parts */
    unsigned sign = sign_mask & uf;
    unsigned exp = exp_mask & uf;
    unsigned frac = frac_mask & uf;

    /* handle edge case NaN */
    if (!(exp ^ exp_mask)) {
         return uf;
    }

    /* get 2*f */
    if (!exp) {
         /* handle denormalized numbers or zero */
         frac <<= 1;
         /* handle case when denormalized number turns to normalized */
         if (frac & (0x1 << 23)) {
              exp = 0x1 << 23; /* turn on first exponent bit */
              frac ^= (0x1 << 23); /* turn off overflow frac bit */
         }
    }
    else {
         /* handle normalized numbers */
         exp += (0x1 << 23);
         /* edge case fo infinity; return infinity */
         if (!(exp ^ exp_mask)) {
              frac = 0;
         }
    }
	
	return sign | exp | frac;
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf)
{
	/* get exponent mask */
	unsigned exp_mask = 0xff << 23;

	/* extract exponent part of uf */
	unsigned exp = exp_mask & uf;

	/* handle case of nan and infinity */
	if (!(exp ^ exp_mask)) {
		return 0x1 << 31;
	}

	return uf;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x)
{
    int mask_max = 0x7f;
    int mask_min = 0x7e;
    int sign = x >> 31;
	
	/* is x greater than 127 */
    int greater = (mask_max + (~x + 1) >> 31) & ~sign;
	/* is x less than -126 */
    int less = ((x + mask_min) >> 31) & sign;

    if (greater) {
        return 0xff << 23;
    }
    else if (less) {
        return 0;
    }

    unsigned result = (x + mask_max) << 23;

    return result;
}
