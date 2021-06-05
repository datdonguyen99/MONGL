//
//  SLLDataControler.h
//  KTLT ASS 3
//
//  Created by Nhân Nguyễn on 17/05/2021.
//

// Students can remove the final initial return of the functions

#ifndef SLLDataController_h
#define SLLDataController_h

#include "dataStructure.h"
#include <string>
#include <vector>

// Functions used to manage Singly Linked List
void print(SLinkedList &list) {
  if (!list.size) {
    std::cout << "List is empty" << endl;
    return;
  }
  SoldierNode *head = list.head;
  while (head) {
    std::cout << head->data.ID << "->";
    head = head->next;
  }
  std::cout << "NULL" << endl;
}

bool insertAt(SLinkedList &list, Soldier element, int pos) {
  // Insert element into a pos in the SLL
  // Return true if insert successfully, false otherwise
  // TODO

  if (list.head == nullptr) {
    if (pos == 0) {
      list.head = new SoldierNode(element, nullptr);
      list.size++;
      return true;
    }
    return false;
  } else {
    if (pos > list.size || pos < 0) {
      return false;
    }
    SoldierNode *newSoNode = new SoldierNode(element, nullptr);
    if (pos == 0) {
      newSoNode->next = list.head;
      list.head = newSoNode;
      list.size++;
      return true;
    }
    SoldierNode *curr = list.head;
    SoldierNode *prev = nullptr;
    int i = 0;
    while (i < pos) {
      prev = curr;
      curr = curr->next;
      i++;
    }
    newSoNode->next = curr;
    prev->next = newSoNode;
    list.size++;
    return true;
  }
  return false;
}

bool removeAt(SLinkedList &list, int idx) {
  // Remove element at index idx in the SLL
  // Return true if remove successfully, false otherwise
  // TODO
  if (list.head == nullptr) {
    return false;
  }
  if (idx < 0 || idx >= list.size) {
    return false;
  } else if (idx == 0) {
    SoldierNode *tem = list.head;
    list.head = list.head->next;
    delete tem;
    list.size--;
    return true;
  } else {
    SoldierNode *curr = list.head;
    SoldierNode *prev = nullptr;
    int i = 0;

    while (curr != nullptr) {
      if (i == idx) {
        prev->next = curr->next;
        delete curr;
        list.size--;
        return true;
      }
      prev = curr;
      curr = curr->next;
      i++;
    }
  }
  return false;
}

bool removeFirstItemWithHP(SLinkedList &list, int HP) {
  // Remove the first element with HP equals to HP
  // Return true if remove successfully, false otherwise
  // TODO

  if (list.head == nullptr) {
    return false;
  }
  SoldierNode *curr = list.head;
  SoldierNode *prev = nullptr;

  while (curr != nullptr) {
    if (curr->data.HP == HP) {
      if (prev == nullptr) {
        list.head = curr->next;
        delete curr;
        list.size--;
        return true;
      } else {
        prev->next = curr->next;
        delete curr;
        list.size--;
        return true;
      }
    }
    prev = curr;
    curr = curr->next;
  }
  return false;
}

int size(SLinkedList &list) {
  // Return size of the list
  // TODO
  return list.size;
  // return -1;
}

bool empty(SLinkedList &list) {
  // Check whether the list is empty
  // TODO
  if (size(list) == 0) {
    return true;
  }
  return false;
}

void clear(SLinkedList &list) {
  // Delete all of the elements in list
  // TODO
  if (list.head == nullptr) {
    return;
  }
  SoldierNode *curr = list.head;
  while (curr != nullptr) {
    SoldierNode *temp = curr->next;
    delete curr;
    curr = temp;
  }
  list.head = nullptr;
  list.size = 0;
}

string getIDAt(SLinkedList &list, int pos) {
  // Get ID of the Soldier at pos
  // TODO
  int i = 0;
  SoldierNode *head = list.head;
  SoldierNode *curr = head;
  if (pos < size(list)) {
    while (i < pos) {
      curr = curr->next;
      i++;
    }
    return curr->data.ID;
  }
  return "-1";
}

int getHPAt(SLinkedList &list, int pos) {
  // Get HP of the Soldier at pos
  // TODO
  int i = 0;
  SoldierNode *head = list.head;
  SoldierNode *curr = head;
  if (pos < size(list)) {
    while (i < pos) {
      curr = curr->next;
      i++;
    }
    return curr->data.HP;
  }
  return -1;
}

bool setHPAt(SLinkedList &list, int HP, int pos) {
  // Set value of HP at pos
  // TODO
  // Return true if set successfully, false otherwise
  int i = 0;
  SoldierNode *head = list.head;
  SoldierNode *curr = head;
  if (pos < size(list)) {
    while (i < pos) {
      curr = curr->next;
      i++;
    }
    curr->data.HP = HP;
    return true;
  }
  return false;
}

// You can write your own functions here
int getisSpecialAt(SLinkedList &list, int pos) {
  // Get isSpecial of the Soldier at pos
  int i = 0;
  SoldierNode *head = list.head;
  SoldierNode *curr = head;
  if (pos < size(list)) {
    while (i < pos) {
      curr = curr->next;
      i++;
    }
    return curr->data.isSpecial;
  }
  return -1;
}
// End your own functions
int indexOf(SLinkedList &list, Soldier soldier) {
  // Find index of soldier (start from 0)
  // Return -1 if the soldier does not exist
  // TODO
  int i = 0;
  SoldierNode *head = list.head;
  for (SoldierNode *curr = head; curr != nullptr; curr = curr->next) {
    if (getIDAt(list, i) == soldier.ID && getHPAt(list, i) == soldier.HP &&
        getisSpecialAt(list, i) == soldier.isSpecial) {
      return i;
    }
    i++;
  }
  return -1;
}

bool contains(SLinkedList &list, Soldier soldier) {
  // Check if array contains soldier
  // TODO
  if (indexOf(list, soldier) != -1) {
    return true;
  }
  return false;
}

#endif /* SLLDataControler_h */
