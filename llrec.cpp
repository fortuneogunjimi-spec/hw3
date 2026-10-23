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