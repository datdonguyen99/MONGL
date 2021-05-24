//
//  thirdBattle.h
//  KTLT ASS 3
//
//  Created by Nhân Nguyễn on 17/05/2021.
//
// Students can remove the final initial return of the functions

#ifndef thirdBattle_h
#define thirdBattle_h

#include "ArrayDataController.h"
#include "SLLDataController.h"
#include <ctype.h>
#include <iterator>
#include <string>
#include <vector>

//////////////////////////////////////////////////////
/// TASK 1
//////////////////////////////////////////////////////

bool push(Array &array, Soldier soldier) {
  // Return true if push successfully, false otherwise
  // TODO
  // insertAt(Array &array, Soldier element, int pos)
  if (empty(array)) {
    initArray(array, 2); // INIT SIZE OF DYNAMIC ARR RANDOMLY
  }
  if (insertAt(array, soldier, 0)) {
    return true;
  }
  return false;
}

bool pop(Array &array) {
  // Return true if pop successfully, false otherwise
  // TODO
  if (removeAt(array, 0)) {
    return true;
  }
  return false;
}

Soldier top(Array &array) {
  // TODO
  if (!empty(array)) {
    return array.arr[0];
  }
  return Soldier(); // return this if cannot get top
}

//////////////////////////////////////////////////////
/// TASK 2
//////////////////////////////////////////////////////

bool enqueue(SLinkedList &list, Soldier soldier) {
  // Return true if enqueue successfully, false otherwise
  // TODO
  if (insertAt(list, soldier, 0)) {
    return true;
  };
  return false;
}

bool dequeue(SLinkedList &list) {
  // Return true if dequeue successfully, false otherwise
  // TODO
  if (removeAt(list, size(list) - 1)) {
    return true;
  }
  return false;
}

Soldier front(SLinkedList &list) {
  // TODO
  if (!empty(list)) {
    SoldierNode *curr = list.head;
    for (;; curr = curr->next) {
      if (curr->next == nullptr)
        break;
    };
    return curr->data;
  }
  return Soldier(); // Return this if cannot get front
}

//////////////////////////////////////////////////////
/// TASK 3
//////////////////////////////////////////////////////

void reverse(SLinkedList &list) {
  // TODO
  SoldierNode *curr = list.head;
  SoldierNode *prev = nullptr;
  SoldierNode *nex = nullptr;

  while (curr != nullptr) {
    nex = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nex;
  }
  list.head = prev;
}

//////////////////////////////////////////////////////
/// TASK 4
//////////////////////////////////////////////////////

int toAsciiz(string &str) {
  char c = str[0];
  return (int)c;
}

SoldierNode *mergeSortHelper(SoldierNode *&head1, SoldierNode *&head2) {
  SoldierNode *resul = nullptr;
  if (head1 == nullptr) {
    return head2;
  }
  if (head2 == nullptr) {
    return head1;
  }
  if (head1->data.HP < head2->data.HP) {
    resul = head1;
    resul->next = mergeSortHelper(head1->next, head2);
  } else if (head1->data.HP >= head2->data.HP) {
    resul = head2;
    resul->next = mergeSortHelper(head1, head2->next);
  } else {
    if (head1->data.isSpecial < head2->data.isSpecial) {
      resul = head1;
      resul->next = mergeSortHelper(head1->next, head2);
    } else if (head1->data.isSpecial > head2->data.isSpecial) {
      resul = head2;
      resul->next = mergeSortHelper(head1, head2->next);
    } else {
      if (toAsciiz(head1->data.ID) < toAsciiz(head2->data.ID)) {
        resul = head1;
        resul->next = mergeSortHelper(head1->next, head2);
      } else {
        resul = head2;
        resul->next = mergeSortHelper(head1, head2->next);
      }
    }
  }
  return resul;
}

void SplitList(SoldierNode *&source, SoldierNode **front, SoldierNode **back) {
  SoldierNode *ptr1 = nullptr;
  SoldierNode *ptr2 = nullptr;
  ptr2 = source;
  ptr1 = source->next;

  while (ptr1 != nullptr) {
    ptr1 = ptr1->next;
    if (ptr1 != nullptr) {
      ptr2 = ptr2->next;
      ptr1 = ptr1->next;
    }
  }

  *front = source;
  *back = ptr2->next;
  ptr2->next = nullptr;
}

void MergeSort(SoldierNode **thead) {
  SoldierNode *head = *thead;
  SoldierNode *ptr1 = nullptr;
  SoldierNode *ptr2 = nullptr;

  if ((head == NULL) || (head->next == NULL)) {
    return;
  }

  SplitList(head, &ptr1, &ptr2);
  MergeSort(&ptr1);
  MergeSort(&ptr2);

  *thead = mergeSortHelper(ptr1, ptr2);
}

SLinkedList merge(SLinkedList &list1, SLinkedList &list2) {
  // TODO
  SoldierNode *temp = list1.head;
  while (temp->next != nullptr) {
    temp = temp->next;
  }
  temp->next = list2.head;

  if (list1.head != nullptr) {
    SoldierNode **thead = &list1.head;
    MergeSort(*&thead);
    return list1;
  }
  return SLinkedList();
}

// You can write your own functions here

// End your own functions

#endif /* thirdBattle_h */
