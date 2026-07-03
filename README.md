🛠️ C++ Data Structures & Algorithms Library (ds_library)

A production-grade, generic Data Structures and Algorithms library written entirely from scratch in C++17.

Instead of relying on the C++ Standard Template Library (STL), this project was built from the ground up to demonstrate a deep, foundational understanding of how core computer science concepts actually work under the hood.

🧠 Key Learnings & Skills Demonstrated

By building this library without standard tools, I practically applied several advanced software engineering concepts:

Manual Memory Management: Handling raw pointers, heap allocation (new/delete), and preventing memory leaks.

Generic Programming: Utilizing C++ Templates (<typename T>) to make data structures work with any data type.

Algorithmic Complexity: Optimizing algorithms for Time and Space complexity (Big-O Notation).

Modern Tooling: Configuring cross-platform builds with CMake and writing automated Unit Tests using Google Test (GTest).

🚀 Features (Phase 1)

Vector<T> (Dynamic Array): Automatically resizes itself in heap memory when capacity is reached. Includes strict out-of-bounds checking.

Sorting Algorithms:

merge_sort: Stable $O(N \log N)$ sorting using the Divide and Conquer paradigm.

quick_sort: Highly optimized $O(N \log N)$ in-place sorting that minimizes memory overhead.

Search Algorithms:

linear_search: $O(N)$ sequential search fallback.

binary_search: $O(\log N)$ high-speed search for sorted datasets.

💡 Use Cases

Why use this custom library instead of std::vector?

Educational Reference: A clean, heavily-commented reference for computer science students learning how DSA is implemented under the hood.

Embedded Systems: Environments with strict memory constraints where the standard STL is too heavy or bloated.

Customization: A lightweight foundation that can easily be modified to use custom memory allocators.

💻 How to Use It in Your Code

Because this is a template library, you can simply include the header file in your project and start using it immediately:

#include <iostream>
#include "Vector.h"

int main() {
    // 1. Create a custom Vector
    Vector<int> myNumbers;

    // 2. Add data
    myNumbers.push_back(50);
    myNumbers.push_back(10);
    myNumbers.push_back(100);

    // 3. Sort and Search (using the algorithms built in this library)
    quick_sort(myNumbers);
    int foundIndex = binary_search(myNumbers, 100);
    
    std::cout << "Found 100 at index: " << foundIndex << std::endl;

    return 0;
}


⚙️ Build & Run the Tests

To verify the integrity of the code on your machine, you can run the automated Google Test suite.

Prerequisites: A modern C++ Compiler and CMake (3.10+).

# 1. Clone the repository
git clone [https://github.com/Incredib-ulya/ds_library.git](https://github.com/Incredib-ulya/ds_library.git)
cd ds_library

# 2. Configure the build environment
cmake -B build

# 3. Compile the code
cmake --build build

# 4. Run the automated QA tests
./build/run_tests
