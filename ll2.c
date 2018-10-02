#include <stdlib.h>
#include <stdio.h>

struct node {
  unsigned char* cargo;
  struct node* next;
};

struct node* add(struct node* head, char* str, int i) {
  struct node* n = malloc(sizeof(struct node));
  n->cargo = str;
  if (i) {
    struct node* tmp = head;
    for (; --i && tmp->next; tmp = tmp->next);
    n->next = tmp->next;
    tmp->next = n;
  } else {
    n->next = head;
    head = n;
  }
  return head;
}

int main() {
  struct node* llist = malloc(sizeof(struct node));
  char a[] = "aaa";
  char b[] = "bbb";
  llist->cargo = a;
  llist = add(llist, b, 0);
  printf("[%s, %s]", llist->cargo, llist->next->cargo);
}
