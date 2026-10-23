#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot)
{
  if(head == NULL) {
    smaller = NULL;
    larger = NULL;
    return;
  }

  Node* next = head->next;

  if(head->val > pivot) {
    larger = head;
    llpivot(next, smaller, larger->next, pivot);
  }
  else {
    smaller = head;
    llpivot(next, smaller->next, larger, pivot);
  }

  head = NULL;
}

//Code Plan

//Base Cases => 1) check if head is currently NULL, then set smaller and larger, currently poitning at the last
// node, to NULL, and return
//Recursive Cases => save head value into a temp var and check if head value is > pivot. If it is, set larger = head, then call the recursive call,
//shifting head to head->next and larger to larger->next in the arguments. else, set smaller equal to head, then
//call the recursive call, shifting head to head->next and smaller to smaller->next in the arguments.