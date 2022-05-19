-   1 byte = 8bits (1 byte = 1 bit)
-   Bits are stored in the order of least significant bit to most significant bit. They are either 0 or 1.

---

# Binary operators

-   Bitwise Operators:

            -   &: AND
            -   |: OR
            -   ^: XOR
            -   ~: NOT
            -   <<: Left Shift
            -   \>>: Right Shift

-   Logical Operators:

            -   &&: AND
            -   ||: OR
            -   !: NOT

-   Assignment Operators:

            -   =: Assignment
            -   +=: Addition Assignment
            -   -=: Subtraction Assignment
            -   \*=: Multiplication Assignment
            -   /=: Division Assignment
            -   %=: Modulus Assignment
            -   &=: Bitwise AND Assignment
            -   |=: Bitwise OR Assignment
            -   ^=: Bitwise XOR Assignment
            -   <<=: Left Shift Assignment
            -   >> =: Right Shift Assignment

-   Relational Operators:

            -   ==: Equal
            -   !=: Not Equal
            -   <: Less Than
            -   > : Greater Than
            -   <=: Less Than or Equal
            -   > =: Greater Than or Equal

-   Arithmetic Operators:

            -   +: Addition
            -   -: Subtraction
            -   \*: Multiplication
            -   /: Division
            -   %: Modulus

---

# Unary Operators

-   Unary Operators:

            -   +: Positive
            -   -: Negative
            -   !: Logical NOT
            -   ~: Bitwise NOT
            -   &: Address of
            -   \*: Dereference

---

# Ternary Operator

-   Ternary Operator:

            -   condition ? expr1 : expr2

---

-   `&` or `|` work on integer performing the operator on each corresponding bits.
-   However `&&` or `||` work on boolean values (any non zero value is true) to produce boolean results.

> Example :

        2  |   1  = 3
        2  ||  1  = true
        2   &  1  =  0
        2  &&  1  = true

---

# Bitwise Operators

## Left Shift <<

-   shifts bits to the left

-   **_A << x is also equal to multiplication by pow(2, x)._**
-   `1 << x` is equal to `pow(2, x)`.

-   Syntax: `A << x`

---

ATTENTION:

-   **_Takes two numbers, left shifts the bits of the first operand, the second operand decides the number of places to shift._**
    > `(1<<3 = 1*pow(2,3))`
    >
    > -   `(x<<y)` is equivalent to multiplying `x` with `2^y` (2 raised to power y).
-   Example: N = 22 (00010110 in binary)

                    N is left shifted by 2.
                    N = N << 2
                    N = N*(2^2) = 22*(2^2) = 22*4 = 88
                    N = 88 (01011000 in binary)

    >

                - N << 1 -> N*2
                - N << 2 -> N*4
                - N << 3 -> N*8
                - N << 4 -> N*16
                - N << 5 -> N*32
                - N << 6 -> N*64
                - N << 7 -> N*128
                - N << 8 -> N*256
                - N << 9 -> N*512
                - N << 10 -> N*1024

---

What does A « x mean :  
`A << x` implies shifting the bits of A to the left by x positions. The first x bits are lost this way. The last x bits have 0.  
Example : lets say

        A = 29 ( 11101 ) and x = 2,
        so A << 2 means
                0 0 1 1 1 0 1 << 2
                =============  ------> this sequence of digit shifts to the left by 2 positions
            ----------------
                1 1 1 0 1 0 0  = 116

## Right Shift >>

-   shifts bits to the right

-   **x >> y is equivalent to dividing `x` with `2^y`.**

    > Example: N=32 (100000 in binary)

                    N is right shifted by 2.
                    N = N >> 2
                    N = N/(2^2) = 32/(2^2) = 16
                    N = 16 (10000 in binary)

    > ATTENTION:  
    > (1>>3 = 1/pow(2,3))

                - N >> 1 -> N/2
                - N >> 2 -> N/4
                - N >> 3 -> N/8
                - N >> 4 -> N/16
                - N >> 5 -> N/32
                - N >> 6 -> N/64
                - N >> 7 -> N/128
                - N >> 8 -> N/256
                - N >> 9 -> N/512
                - N >> 10 -> N/1024

-   `1 >> x` is equal to `pow(2, x)`.

> Syntax : `A >> x`

-   **_Takes two numbers, right shifts the bits of the first operand, the second operand decides the number of places to shift_**

> **What does A » x mean :**  
> A >> x implies shifting the bits of A to the right by x positions. The last x bits are lost this way.

Example : Lets say

                A = 29 ( 11101 ) and x = 2,
                so A >> 2 means
                     0 0 1 1 1 0 1 >> 2
                               ====  -> is lost
                    ========== -----> this sequence of digit shifts to the right by 2 positions
                    ----------------
                     0 0 0 0 1 1 1 = 7

## Bitwise AND &

-   returns the bitwise AND of two numbers

> Syntax :
> `A & B`

Values for bit combinations:

|  a  |  b  | a & b |
| :-: | :-: | :---: |
|  0  |  0  |   0   |
|  0  |  1  |   0   |
|  1  |  0  |   0   |
|  1  |  1  |   1   |

In other words, a & b = 0 unless a = 1 and b = 1.

What does A & B mean :
A & B implies a & b for all corresponding bits of A and B.

So, lets say,

       A = 21 ( 10101 ) and B = 6  ( 110 )
       A & B =
                        1 0 1 0 1
                    &   0 0 1 1 0
                    ------------------
                        0 0 1 0 0  =  4.

**_x & 1 -> checks if a number is odd or not. (returns MSB of binary representation of x (0/1, if 0 then even, 1 means odd))_**

> Example from Code chef contest: `https://www.codechef.com/APRIL221D/problems/XORABC`

```cpp
    ll x, A;
    cin >> x;

    A = x & ~(x-1);
    // x & ~(x-1) checks for power of 2. If x is a power of 2 number then A==x
    // x&1 -> checks if a number is odd or not. (returns MSB of binary representation of x (0/1, if 0 then even, 1 means odd))

    if(x&1 || x==A) {
        cout << -1 << endl;
    } else {
        cout << A/2 << " " << x/2 << " " << (x-A)/2 << endl;
    }
```

## Bitwise OR |

-   performs bitwise OR operation on two numbers

> Syntax :
> `A | B`

Values for bit combinations:

|  a  |  b  | a \| b |
| :-: | :-: | :----: |
|  0  |  0  |   0    |
|  0  |  1  |   1    |
|  1  |  0  |   1    |
|  1  |  1  |   1    |

> In other words, a | b = 1 unless a = 0 and b = 0

What does A | B mean :
A | B implies a | b for all corresponding bits of A and B. So, lets say

       A = 21 ( 10101 ) and B = 6  ( 110 )
       A | B =
                        1 0 1 0 1
                    |   0 0 1 1 0
                    ------------------
                        1 0 1 1 1  =  23.

## Bitwise XOR ^

-   performs bitwise XOR operation on two numbers

> Syntax :
> `A ^ B`

Values for bit a, b :
|a|b|a ^ b|
|:--:|:--:|:--:|
|0|0|0|
|0|1|1|
|1|0|1|
|1|1|0|

In other words, a ^ b = 1 when a and b are different.

What does A ^ B mean :
A ^ B implies a ^ b for all corresponding bits of A and B. So, lets say

       A = 21 ( 10101 ) and B = 6  ( 110 )
       A ^ B =
                        1 0 1 0 1
                    ^   0 0 1 1 0
                    ------------------
                        1 0 0 1 1  =  19.

## Bitwise NOT ~

-   performs bitwise NOT operation on a number

> Syntax :
> `~A`

Values for bit a, b :
|a|a NOT b|
|:--:|:--:|
|0|1|
|1|0|

Its the inverse of the bit.

What does ~A mean
~A implies inverting every single bit in A. So, lets say

            A = 21 ( 10101 ) and A is a char ( 1 byte )
            ~A =
                0 0 0 1 0 1 0 1
              --------------------------
                1 1 1 0 1 0 1 0  = -22 ( Sign bit is 1 ).

## TRICKS WITH BITS

-   `x & (x-1)` will clear the lowest set bit of x
-   A = `x & ~(x-1)` extracts the lowest set bit of x (all others are clear). Pretty patterns when applied to a linear sequence. Check for power of 2, if x is power of 2 then answer A will be -1
-   `x & (x + (1 << n)) = x`, with the run of set bits (possibly length 0) starting at bit n cleared.
-   `x & ~(x + (1 << n)) =` the run of set bits (possibly length 0) in x, starting at bit n.
-   `x | (x + 1) = x `with the lowest cleared bit set.
-   `x | ~(x + 1) =` extracts the lowest cleared bit of x (all others are set).
-   `x | (x - (1 << n)) = x`, with the run of cleared bits (possibly length 0) starting at bit n set.
-   `x | ~(x - (1 << n)) =` the lowest run of cleared bits (possibly length 0) in x, starting at bit n are the only clear bits.

---

-   `(n+i) = (n^i) + 2*(n&i)`
    So n + i = n ^ i implies n & i = 0
    finding values of i such that n & i = 0
    For n & i to be zero, i must unset all set-bits of n.
    total such combinations are 2^(count of unset bits in n)
    [Attempt this question](https://www.geeksforgeeks.org/equal-sum-xor/)

---

---

# GCC Inbuilt Functions

-   Number of 1-bits (set bits): `__builtin_popcount(x) `
-   Similarly you can use `__builtin_popcountl(x)` & `__builtin_popcountll(x)` for long and long long data types.

---

-   Check parity of x, returns true(1) if the number has odd parity and false(0) for even parity: `__builtin_parity(x)`
-   Similarly you can use `__builtin_parityl(x)` & `__builtin_parityll(x)` for long and long long data types.
-   Number of 0-bits (clear bits): `__builtin_parity(~x)`

---

-   Returns one plus the index of the least significant 1-bit of x, or if x is zero, returns zero.: `__builtin_ffs(x)`

---

-   Number of leading zeroes (clz = count leading zero’s): `__builtin_clz(x)`
-   Similarly you can use `__builtin_clzl(x)` & `__builtin_clzll(x)` for long and long long data types.

---

-   Number of trailing zeroes (ctz = count trailing zeros): `__builtin_ctz(x)`
-   Similarly you can use `__builtin_ctzl(x)` & `__builtin_ctzll(x)` for `long` and `long long` data types.

---

---

---

# Number Table (for reference)

| Decimal | Binary  |
| :-----: | :-----: |
|    0    |    0    |
|    1    |    1    |
|    2    |   10    |
|    3    |   11    |
|    4    |   100   |
|    5    |   101   |
|    6    |   110   |
|    7    |   111   |
|    8    |  1000   |
|    9    |  1001   |
|   10    |  1010   |
|   11    |  1011   |
|   12    |  1100   |
|   13    |  1101   |
|   14    |  1110   |
|   15    |  1111   |
|   16    |  10000  |
|   17    |  10001  |
|   18    |  10010  |
|   19    |  10011  |
|   20    |  10100  |
|   21    |  10101  |
|   22    |  10110  |
|   23    |  10111  |
|   24    |  11000  |
|   25    |  11001  |
|   26    |  11010  |
|   27    |  11011  |
|   28    |  11100  |
|   29    |  11101  |
|   30    |  11110  |
|   31    |  11111  |
|   32    | 100000  |
|   33    | 100001  |
|   34    | 100010  |
|   35    | 100011  |
|   36    | 100100  |
|   37    | 100101  |
|   38    | 100110  |
|   39    | 100111  |
|   40    | 101000  |
|   41    | 101001  |
|   42    | 101010  |
|   43    | 101011  |
|   44    | 101100  |
|   45    | 101101  |
|   46    | 101110  |
|   47    | 101111  |
|   48    | 110000  |
|   49    | 110001  |
|   50    | 110010  |
|   51    | 110011  |
|   52    | 110100  |
|   53    | 110101  |
|   54    | 110110  |
|   55    | 110111  |
|   56    | 111000  |
|   57    | 111001  |
|   58    | 111010  |
|   59    | 111011  |
|   60    | 111100  |
|   61    | 111101  |
|   62    | 111110  |
|   63    | 111111  |
|   64    | 1000000 |
|   65    | 1000001 |
|   66    | 1000010 |
|   67    | 1000011 |
|   68    | 1000100 |
|   69    | 1000101 |
|   70    | 1000110 |
|   71    | 1000111 |
|   72    | 1001000 |
|   73    | 1001001 |
|   74    | 1001010 |
|   75    | 1001011 |
|   76    | 1001100 |
|   77    | 1001101 |
|   78    | 1001110 |
|   79    | 1001111 |
|   80    | 1010000 |
|   81    | 1010001 |
|   82    | 1010010 |
|   83    | 1010011 |
|   84    | 1010100 |
|   85    | 1010101 |
|   86    | 1010110 |
|   87    | 1010111 |
|   88    | 1011000 |
|   89    | 1011001 |
|   90    | 1011010 |
|   91    | 1011011 |
|   92    | 1011100 |
|   93    | 1011101 |
|   94    | 1011110 |
|   95    | 1011111 |
|   96    | 1100000 |
|   97    | 1100001 |
|   98    | 1100010 |
|   99    | 1100011 |
|   100   | 1100100 |

---
