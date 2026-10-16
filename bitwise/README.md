# Bitwise Operations  

Bitwise operations are fundamental low-level operations that directly manipulate individual bits (binary digits) within an integer number. Understanding bitwise operations is crucial for optimizing code, working with flags, manipulating data at the lowest level, and solving certain algorithmic problems efficiently.  

****

### What are Bits?  
Before diving into bitwise operations, it's essential to understand what "bits" are.  

* A **bit** (binary digit) is the smallest unit of data in a computer, representing a `0` or `1`.  

* Numbers in a computer are stored in their binary representation. For example, the decimal number `5` is `101` in binary (assuming enough bits to store it, typically 8, 16, 32, or 64 bits like `00000101`).  

Bitwise operations perform their calculations on these individual 0s and 1s of the binary representation of numbers.  

**Why Use Bitwise Operations?**  

Bitwise operations offer several advantages and are used in various scenarios:  

* **Efficiency:** They are often much faster than arithmetic operations for certain tasks because they operate directly on the hardware level.  

* **Memory Optimization:** Useful for packing multiple boolean flags or small pieces of data into a single integer, saving memory.  

* **Control and Manipulation:** Perfect for setting, clearing, toggling, or checking specific bits within a number.  

* **Cryptography and Hashing:** Used in various algorithms for security and data integrity.  

* **Low-Level Programming:** Essential for device drivers, embedded systems, and network protocols.  

* **Algorithmic Problem Solving:** Many competitive programming problems can be efficiently solved or optimized using bitwise logic (e.g., subset generation, power of 2 checks, even/odd checks).  

### Common Bitwise Operators  
Here are the most common bitwise operators:  

* `&` (AND): Returns `1` if both bits are `1`, otherwise `0`.  
    * Example: `5 (0101) & 3 (0011) = 1 (0001)`  

* `|` (OR): Returns `1` if at least one of the bits is `1`, otherwise `0`.
    * Example: `5 (0101) | 3 (0011) = 7 (0111)`  

* `^` (XOR - Exclusive OR): Returns `1` if the bits are different, otherwise `0`.  
    * Example: `5 (0101) ^ 3 (0011) = 6 (0110)`

* `~` (NOT - Bitwise Complement): Inverts all bits (`0` becomes `1`, `1` becomes `0`). This is typically a unary operator.

    * Important Note: The result depends on the number of bits used to represent the integer (e.g., 32-bit vs. 64-bit). It often results in a negative number due to two's complement representation.

    * Example (on 8 bits): `~5 (~00000101) = 11111010` (which is -6 in two's complement)    

* `<<` (Left Shift): Shifts bits to the left by a specified number of positions. Vacated positions are filled with `0s`. This is equivalent to multiplying by powers of 2.
    * Example: `5 (0101) << 1 = 10 (1010)`
    * Example: `5 (0101) << 2 = 20 (10100)`

* `>>` (Right Shift): Shifts bits to the right by a specified number of positions.
    * For **unsigned numbers**, vacated positions are filled with `0`s (logical right shift).

    * For **signed numbers**, the behavior depends on the language:

        * **Arithmetic Right Shift:** Vacated positions are filled with the most significant bit (sign bit) to preserve the sign. 
        
        * **Logical Right Shift:** Vacated positions are filled with `0`s, regardless of the sign.

    * Right shifting is equivalent to integer division by powers of 2.

    * Example (logical right shift): `10 (00001010) >> 1 = 5 (00000101)`

    * Example (arithmetic right shift for negative number in 8-bit): `-6 (11111010) >> 1 = -3 (11111101)`  

### Common Bit Manipulation Techniques / Patterns
* **Checking if a bit is set:** `(number & (1 << position))`

* **Setting a bit:** `(number | (1 << position))`

* **Clearing a bit:** `(number & ~(1 << position))`

* **Toggling a bit:** `(number ^ (1 << position))`

* **Checking if a number is even/odd:** `(number & 1)` (returns 0 for even, 1 for odd)

* **Checking if a number is a power of 2:** `(number > 0 && (number & (number - 1)) == 0)`

* **Swapping two numbers without a temporary variable:** `a = a ^ b; b = a ^ b; a = a ^ b;`

* **Counting set bits (popcount):** Various algorithms exist, including Brian Kernighan's algorithm.

* **Finding the only unique number in an array where others appear twice:** XOR all numbers.

### Applications
You'll find bitwise operations applied in:

* **Permissions and Flags:** Representing multiple boolean states in a single integer (e.g., `READ` | `WRITE` | `EXECUTE`).

* **Color Representation:** In graphics, colors are often represented as integers where different bits represent Red, Green, Blue, and Alpha components.

* **Network Protocols:** Manipulating headers, checksums.

* **Compression Algorithms:** Packing data efficiently.

* **Game Development:** For various low-level optimizations and state management.

### Problems And Solutions  

