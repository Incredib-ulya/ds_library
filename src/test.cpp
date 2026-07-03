#include <gtest/gtest.h>
#include "Vector.h" // Import your custom array!

// TEST 1: Prove that a brand new Vector starts at size 0.
TEST(VectorTest, StartsEmpty) {
    Vector<int> arr;
    
    // The QA Robot checks if arr.size() exactly equals 0.
    EXPECT_EQ(arr.size(), 0);
}

// TEST 2: Prove that push_back actually adds items and tracks size.
TEST(VectorTest, PushBackAddsElements) {
    Vector<int> arr;
    
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    
    // 1. Did the size increase to 3?
    EXPECT_EQ(arr.size(), 3);
    
    // 2. Did the brackets operator put them in the right order?
    EXPECT_EQ(arr[0], 10);
    EXPECT_EQ(arr[1], 20);
    EXPECT_EQ(arr[2], 30);
}