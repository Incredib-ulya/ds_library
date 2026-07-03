# Tell CMake the minimum version required
cmake_minimum_required(VERSION 3.10)

# Name your project
project(DataStructuresLib)

# Force the compiler to use modern C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Tell CMake to compile our main.cpp file into an executable called 'ds_runner'
add_executable(ds_runner src/main.cpp)

# ==========================================
# 5. GOOGLE TEST (THE QA ROBOT)
# ==========================================
# Tell CMake to download GTest straight from Google's GitHub!
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
# Windows specific fix to prevent compiler crashes
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# 6. CREATE THE TEST PROGRAM
# We will build a second, separate program just for running tests!
# (We will uncomment these lines as soon as we create our test.cpp file)
 add_executable(run_tests src/test.cpp)
 target_link_libraries(run_tests gtest_main)