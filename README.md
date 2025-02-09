# std::vector<bool> Potential Undefined Behavior

This repository demonstrates a potential issue with the `std::vector<bool>` specialization in C++.  While seemingly straightforward, this specialization can lead to undefined behavior under certain conditions, primarily due to space optimization techniques employed by some standard library implementations.

## Problem

The `std::vector<bool>` specialization often deviates from the standard `std::vector` behavior. Instead of storing each boolean as a full byte, it typically uses bit packing for memory efficiency. This optimization, however, introduces complexities that can manifest as undefined behavior when accessing or modifying elements.  The use of `[]` operator, especially for modification in conjunction with `push_back`, may trigger this.  The details are implementation-defined, making it difficult to predict the outcome across different compilers or standard library versions.

## Solution

The safest approach is to avoid using `std::vector<bool>` altogether. For boolean storage, consider alternatives like:

* `std::vector<char>`: Each boolean value can be stored as a `char`, guaranteeing consistent behavior.
* `std::vector<int>`: With bitwise operations, this allows efficient boolean storage for multiple booleans per `int`.
* `std::bitset`: A more dedicated container for boolean data, providing clearer behavior and avoiding potential undefined behavior.

If you absolutely must use `std::vector<bool>`, exercise extreme caution, avoid modifying the elements using `[]` operator, and be mindful of potential reallocations during `push_back` operations. Thorough testing on your target platform and compiler is crucial.
