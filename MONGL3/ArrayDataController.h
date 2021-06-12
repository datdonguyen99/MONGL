//
//  ArrayDataController.h
//  KTLT ASS 3
//
//  Created by Nhân Nguyễn on 17/05/2021.
//

// Students can remove the final initial return of the functions

#ifndef ArrayDataController_h
#define ArrayDataController_h

#include "dataStructure.h"
#include <iterator>
#include <string>
#include <vector>

// Functions used to manage Array
void print(Array &array) {
  if (!array.size) {
    std::cout << "Array is empty" << endl;
    return;
  }
  std::cout << "[";
  for (int i = 0; i < array.size; i++) {
    std::cout << array.arr[i].ID << " ";
  }
  std::cout << "]" << endl;
}

void initArray(Array &array, int cap) {
  // Init a new array with capacity equals to cap
  // TODO
  array.arr = new Soldier[cap];
  array.capacity = cap;
  array.size = 0;
}

void ensureCapacity(Array &array, int newCap) {
  // Extend the capacity of the array
  // TODO
  array.capacity = newCap;
  Soldier *temp = new Soldier[newCap];
  for (int i = 0; i < array.size; i++) {
    temp[i] = array.arr[i];
  }
  delete[] array.arr;
  array.arr = temp;
}

bool insertAt(Array &array, Soldier element, int pos) {
  // Insert element into a pos in the array
  // Return true if insert successfully, false otherwise
  // TODO
  if (array.arr == nullptr) {
    return false;
  }
  if (array.capacity == 0) {
    ensureCapacity(array, 5);
  }

  if (pos >= 0 && pos <= array.size) {
    if ((float)array.size / (float)array.capacity > 0.75) {
      int multiplicand = (pos >= array.capacity) ? pos : array.size;
      ensureCapacity(array, multiplicand * 1.5);
    }

    for (int i = array.size; i > pos; i--) {
      array.arr[i] = array.arr[i - 1];
    }

    array.arr[pos] = element;
    array.size++;
    return true;
  }
  return false;
}

bool removeAt(Array &array, int idx) {
  // Remove element at index idx in the array
  // Return true if remove successfully, false otherwise
  // TODO
  if (idx >= 0 && idx < array.size) {
    for (int i = idx; i < array.size - 1; i++) {
      array.arr[i] = array.arr[i + 1];
    }
    array.size--;
    return true;
  }
  return false;
}

bool removeFirstItemWithHP(Array &array, int HP) {
  // Remove the first element with HP equals to HP
  // Return true if remove successfully, false otherwise
  // TODO
  for (int i = 0; i < array.size; i++) {
    if (array.arr[i].HP == HP) {
      for (int j = i; j < array.size - 1; j++) {
        array.arr[j] = array.arr[j + 1];
      }
      array.size--;
      return true;
    }
  }
  return false;
}

// void ensureCapacity(Array &array, int newCap) {
//   // Extend the capacity of the array
//   // TODO
// }

// int indexOf(Array &array, Soldier soldier) {
//   // Find index of soldier (start from 0)
//   // Return -1 if the soldier does not exist
//   // TODO

//   return -2;
// }

int size(Array &array) {
  // Return size of the array
  // TODO
  return array.size;
  // return -1;
}

bool empty(Array &array) {
  // Check whether the array is empty
  // TODO
  if (size(array) == 0) {
    return true;
  }
  return false;
}

string getIDAt(Array &array, int pos) {
  // Get ID of the Soldier at pos
  // TODO
  if (empty(array)) {
    return "-1";
  }
  if (pos >= 0 && pos < size(array)) {
    return array.arr[pos].ID;
  }
  return "-1";
}

int getHPAt(Array &array, int pos) {
  // Get HP of the Soldier at pos
  // TODO
  if (empty(array)) {
    return -1;
  }
  if (pos >= 0 && pos < size(array)) {
    return array.arr[pos].HP;
  }
  return -1;
}

int getisSpecialAt(Array &array, int pos) {
  // Get HP of the Soldier at pos
  // TODO

  if (empty(array)) {
    return -1;
  }
  if (pos >= 0 && pos < size(array)) {
    return array.arr[pos].isSpecial;
  }
  return -1;
}

bool setHPAt(Array &array, int HP, int pos) {
  // Set value of HP at pos
  // TODO
  // Return true if set successfully, false otherwise
  if (empty(array)) {
    return false;
  }
  if (pos >= 0 && pos < size(array)) {
    array.arr[pos].HP = HP;
    return true;
  }
  return false;
}

void clear(Array &array) {
  // Delete all of the elements in array
  // TODO
  array.size = 0;
  array.capacity = 0;
  delete[] array.arr;
  array.arr = nullptr;
}

int indexOf(Array &array, Soldier soldier) {
  // Find index of soldier (start from 0)
  // Return -1 if the soldier does not exist
  // TODO
  for (int i = 0; i < array.size; i++) {
    if (getIDAt(array, i) == soldier.ID && getHPAt(array, i) == soldier.HP &&
        getisSpecialAt(array, i) == soldier.isSpecial) {
      return i;
    }
  }
  return -1;
}

bool contains(Array &array, Soldier soldier) {
  // Check if array contains soldier
  // TODO
  if (indexOf(array, soldier) != -1) {
    return true;
  }
  return false;
}

// You can write your own functions here

// End your own functions

#endif /* ArrayDataController_h */
