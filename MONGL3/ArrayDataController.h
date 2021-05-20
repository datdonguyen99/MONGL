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
  std::cout << "]";
}

void initArray(Array &array, int cap) {
  // Init a new array with capacity equals to cap
  // TODO
}

bool insertAt(Array &array, Soldier element, int pos) {
  // Insert element into a pos in the array
  // Return true if insert successfully, false otherwise
  // TODO

  return false;
}

bool removeAt(Array &array, int idx) {
  // Remove element at index idx in the array
  // Return true if remove successfully, false otherwise
  // TODO

  return false;
}

bool removeFirstItemWithHP(Array &array, int HP) {
  // Remove the first element with HP equals to HP
  // Return true if remove successfully, false otherwise
  // TODO

  return false;
}

void ensureCapacity(Array &array, int newCap) {
  // Extend the capacity of the array
  // TODO
}

int indexOf(Array &array, Soldier soldier) {
  // Find index of soldier (start from 0)
  // Return -1 if the soldier does not exist
  // TODO

  return -2;
}

int size(Array &array) {
  // Return size of the array
  // TODO

  return -1;
}

bool empty(Array &array) {
  // Check whether the array is empty
  // TODO

  return false;
}

string getIDAt(Array &array, int pos) {
  // Get ID of the Soldier at pos
  // TODO

  return "";
}

int getHPAt(Array &array, int pos) {
  // Get HP of the Soldier at pos
  // TODO

  return -1;
}

bool setHPAt(Array &list, int HP, int pos) {
  // Set value of HP at pos
  // TODO
  // Return true if set successfully, false otherwise

  return false;
}

void clear(Array &array) {
  // Delete all of the elements in array
  // TODO
}

bool contains(Array &array, Soldier soldier) {
  // Check if array contains soldier
  // TODO

  return false;
}

// You can write your own functions here

// End your own functions

#endif /* ArrayDataController_h */
