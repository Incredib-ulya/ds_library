#include <iostream>
#include <stdexcept>
#include "Vector.h"

// Linear Search
template <typename T>
int linear_search(Vector<T>& arr, T target) {
    for(int i = 0; i<arr.size(); i++){
        if (arr[i]==target)
        {
            return i;
        }   
    }
    return -1;
}
// Binary search
template <typename T>
int binary_search(Vector<T>& arr, T target) {
    int left = 0;
    int right = arr.size() - 1;


    while (left <= right) {
        
        // Find the exact middle index
        int mid = left + (right - left) / 2; 

        // CONDITION 1: We found the exact target!
        if (arr[mid] == target) {
            return mid; 
        }
       
        if (arr[mid] < target) {
            left = mid + 1;
        } 
        
           else {
            right = mid - 1;
        }
    }

    // If the while loop finishes and we never hit Condition 1, it's not here.
    return -1;
}

// Sorting Techniques

// Merge Sort
template <typename T>
void merge(Vector<T>& arr, int left, int mid, int right){
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    T* leftArray = new T[leftSize];
    T* rightArray = new T[rightSize];

    for (int i = 0; i < leftSize; i++)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < rightSize; j++)
        rightArray[j] = arr[mid + 1 + j];

    int i = 0; // Left finger
    int j = 0; // Right finger
    int k = left; // Main array finger (where we put the winner)
    
    while (i < leftSize && j < rightSize) {
       
        if (leftArray[i] < rightArray[j] || leftArray[i] == rightArray[j]) {
            arr[k] = leftArray[i]; // Put left package in the main box
            i++; // Move left finger down
        }

        else {
            arr[k] = rightArray[j]; // Put right package in the main box
            j++; // Move right finger down
        }
        k++; // Move the main box finger forward
    }

    while (i < leftSize) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }

    delete[] leftArray;
    delete[] rightArray;
}

template <typename T>
void merge_sort_engine(Vector<T>& arr, int left, int right){
  if (left >= right) {
        return;
    }

  int mid = left + (right - left) / 2;
  merge_sort_engine(arr, left, mid);
  merge_sort_engine(arr, mid + 1, right);
  merge(arr, left, mid, right);
  
}

template <typename T>
void merge_sort(Vector<T>& arr) {
    if (arr.size() == 0) return;

    int start = 0;
    int end = arr.size() - 1;

    merge_sort_engine(arr, start, end); 
}

// Quick Sort
template <typename T>
int partition(Vector<T>& arr, int left, int right) {
 T pivot = arr[right];
 int i = left - 1;

 for (int j = left; j < right; j++) {
    if (arr[j] < pivot) {
        i++;
        T temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
}
T temp = arr[i + 1];
    arr[i + 1] = arr[right];
    arr[right] = temp;

    return i + 1;
}
  

template <typename T>
void quick_sort_engine(Vector<T>& arr, int left, int right) {
    if (left >= right) return;
        
    int pivot_index = partition(arr, left, right);

    quick_sort_engine(arr, left, pivot_index - 1);

    quick_sort_engine(arr, pivot_index + 1, right);
}

template <typename T>
void quick_sort(Vector<T>& arr) {
    if (arr.size() == 0) return;
    quick_sort_engine(arr, 0, arr.size() - 1);
}

struct Package 
{
    std::string studentName;
    int weight;
    
    // A default constructor (Required so your Vector can build empty boxes)
    Package() {
        studentName = "Empty";
        weight = 0;
    }
    
    // A quick constructor to make creating packages easy
    Package(std::string name, int w) {
        studentName = name;
        weight = w;
    }

    // Teach C++ how to use the '==' symbol for Packages!
    bool operator==(const Package& other) const {
        return (studentName == other.studentName) && (weight == other.weight);
    }

    // Teach C++ how to use the '<' symbol for Packages!
    bool operator<(const Package& other) const {
        return weight < other.weight;
    }
};
 
int main() 
{
    Vector<Package> myLocker;
    myLocker.push_back(Package("Atulya", 5));
    myLocker.push_back(Package("Arush", 15));
    myLocker.push_back(Package("Rohan", 22));
    myLocker.push_back(Package("Aravind", 11));
    myLocker.push_back(Package("Karan", 30));

    for (int i = 0; i < myLocker.size(); i++)
    {
        std:: cout  << "Name: "<< myLocker[i].studentName 
        << " | Weight: " << myLocker[i].weight << std::endl;
    }

//  int index = linear_search(myLocker, Package("Aravind", 11));

//  int Index = binary_search(myLocker, Package("Arush", 15));
    
//     std::cout << "Found Arush's package at index: " << Index << std::endl;

//  std::cout << "Found at index: " << index << std::endl;

//  merge_sort(myLocker);
//  for (int i = 0; i < myLocker.size(); i++) {
//         std::cout << myLocker[i].studentName << " | Weight: " << myLocker[i].weight << std::endl;
//     }
 quick_sort(myLocker);   
 for (int i = 0; i < myLocker.size(); i++) {
        std::cout << myLocker[i].studentName << " | Weight: " << myLocker[i].weight << std::endl;
    }
    
    return 0;
}
