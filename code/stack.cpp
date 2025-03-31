#include <iostream>
#include <string>
typedef int ELementType;

typedef struct Stack_Node {
  ELementType data;
  struct Stack_Node *next;
}Stack_Node;

Stack_Node *Init(void) {
  Stack_Node *top = (Stack_Node *)malloc(sizeof(Stack_Node));
  top->next = NULL;
  return top;
}

bool push(Stack_Node *top, ELementType data) {

  Stack_Node *newNode = (Stack_Node *)malloc(sizeof(Stack_Node));
  if(!newNode) return false;

  newNode->data = data;
  newNode->next = top->next;
  top->next = newNode;
  return true;
}

bool pop(Stack_Node *top, ELementType *data) {
  Stack_Node *popNode;
  // ELementType data;
  if(top->next == NULL) return false;

  popNode = top->next;
  *data = popNode->data;
  top->next = popNode->next;
  free(popNode);
  return true;
}