/** Solutions to problem set 3
 * 
 */

/** 1) Assuming y is equal to 10, what is x equal to after this code:int x = *( &y );.  Explain what ishappening in this code.
 * 
 * x == y
 * Expanded:
 * x = *( &y );
 * x = *( the address of y )
 * x = the value at (the address of y)
 * x = y
 */


/** 2) What is the minimum number of bits required to store n distinct code values?  For example, how manybits would be required to store 8 values.  Justify your answer.
 * 
 * log(base 2)n
 * If n = 1000, we need log2 1000 == 10 bits
 * 10 bits provides 1024 distinct values.
 */

/** 3) Simplify the following:
 * • log2(xy) − log2(x^2) + 4 * log2(y) 
 *   -> log2(y/x) + log2(y^4)
 *   -> log2(y^5/x)
 * • log2(8x)^(1/3)
 *   -> (1/3) * log2(8x)
 *   -> (1/3) * (log2(8) + log2(x))
 *   -> 1 + (1/3) * log2(x)
 * • log3(9x^4) − log3((3x)^2)
 *   -> log3(9) + log3(x^4) - log3(9x^2)
 *   -> 2 + 4 * log3(x) - (log3(9) + 2 * log3(x))
 *   -> 2 + 4 * log3(x) - 2 - 2 * log3(x)
 *   -> 2 * log3(x)
 * 
 */

/** 4) Solve for x: log2(x/2) = 5
 *   -> 2^(log2(x/2)) = 2^5
 *   -> x/2 = 32
 *   -> x = 64
 * 
 */

/** 5) Evaluate: 3∑x=0 (5 + √(4^x))
 *   -> 6 + 7 + 9 + 13 = 35
 * 
 */

/** 6) Solve the following: 5∑n=0 (−n)
 *   -> -0 + -1 + -2 + -3 + -4 + -5 = -15
 * 
 *   This is equal to -(n * (n+1))/2
 * 
 */

/** 7) Prove that: x∑i=1 i=((x+1)x)/2
 *   -> Refer to the above problem, this is a demonstration of unrolling the summation.
 *   
 * To prove by induction:
 *   -> Check the base case: n = 1, verify that ((1 + 1) * 1)/2 = 1
 *   -> State the induction hypothesis: (x-1)∑i=1 i=(((x-1) + 1)(x-1))/2 == ((x-1)x)/2
 *   -> Thus x∑i=1 i = ((x-1)∑i=1) + x = ((x-1)x)/2 + x = (x^2 - x + 2x)/2 = (x(x+1))/2
 * 
 */

/** 8) Rewrite the following expression into its closed form (i.e.  without the sigma): 4∑i=1 (2 + i^2)
 * 
 * (2 + 1^2) + (2 + 2^2) + (2 + 3^2) + (2 + 4^2) 
 * 
 */

/** 9) Explain the different ways you can analyze various algorithms (hint:  look at the class slides).
 * 
 * Empirical Analysis (requires implementation, and relies on hardware), 
 * Mathematical Model (Independent of hardware / software)
 * 
 */


/** Optional */

/** 1) Explain the difference between the following three declarations of a pointer.
 * 
 * const int* ptr; -> yields a nonconstant pointer to a constant int
 * int* const ptrl -> yields a constant pointer to a nonconstant int
 * const int* const ptr; -> yields a constant pointer to a constant int
 */

/** 2) Explain the difference between Direct Proof, Proof by Contradiction, and Proof by Mathematical Induction.
 * 
 * Direct Proof: Logical Explanation, can be written in English, and represents a logical explanation of why something is true.
 * 
 * Proof by Contradiction: Assume the theorem is false, then find contradicting examples from this assumption.
 * 
 * Proof by Mathematical Induction: Involves establishing a base case, then working down from n to the base case. If a theorem holds for n = c, and n-1, then it holds for n.
 * 
 */

/** 3) Based on the given data, please clasify each of the following as linear, exponential, logarithmic, ornone of the above.  If it is none of the above, try to reason what type of curve it may be.
 * 
 * f(0) = 4, f(1) = 6, f(2) = 9 -> exponential
 * f(0) = 6, f(10) = 8, f(20) = 10 -> linear
 * f(0) = 80, f(0.1) = 60, f(0.2) = 45 -> exponential
 * f(0) = 10, f(1) = 20, f(2) = 35 -> None
 * f(0) = 1, f(3) = 6, f(5) = 120 -> Factorial
 */


int main(void) {
    int nc = 2;
    const int c = 42;
    
    const int* c_int_pointer; // Non-Constant pointer doesn't require initialization.
    int* const int_c_pointer = &nc; // Must initialize and cannot use c.
    const int* const c_int_c_pointer = &c;

}