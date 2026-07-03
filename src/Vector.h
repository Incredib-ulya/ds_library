#pragma once
#include <iostream>
#include <stdexcept>


template <typename T>
class Vector {
private:
    T *arr;
    int capacity, current_size; 

public:
   
    Vector()
    {
        capacity = 1;
        current_size = 0;
        arr = new T[capacity];
    }
    ~Vector() 
    {
        delete[] arr;
    }

    void push_back(T data) 
    {
        if (current_size == capacity)
        { std::cout << " [Memory Alert] Array is full! Resizing from " 
                      << capacity << " to " << (capacity * 2) << "...\n";
            T* temp = new T[capacity * 2];
            for(int i = 0; i<current_size; i++){
                temp[i] = arr [i];
            }
            delete[] arr;
            arr = temp;
            capacity = 2*(capacity);
        }    
        arr[current_size] = data;
        current_size ++; 
    }
    T& operator[](int index)
    {
        if(index >= current_size){
           throw std::out_of_range("[Critical Error] Index out of bounds!");
        }

        return arr[index];
    }

    int size() 
    {
      return current_size;
    }

    void pop_back()
    {
      if (current_size == 0)
      {
        return;
      }

      current_size--;
    }

    void print() 
    {
        std::cout << "\nFinal Vector Contents: [ ";
        for (int i = 0; i < current_size; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << "]\n";
    }
    
};