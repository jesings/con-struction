#include <stdlib.h>
#include <stdio.h>
#include "node.h"
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

struct node* remove_node(struct node* head, int i) {
  struct node* trash;
  if (i) {
    struct node* tmp = head;
    for (; --i; tmp = tmp->next);
    trash = tmp->next;
    tmp->next = tmp->next->next;
  } else {
    trash = head;
    head = head->next;
  }
  free(trash->cargo);
  free(trash);
  return head;
}

int destruct(struct node* head) {
  if(head)
    for (struct node* i = head -> next; i; i = i->next) {
      free(head->cargo);
      free(head);
      head = i;
    }
  return 0;
}

int print_ll(struct node* head) {
  if (!head)
    printf("\n");
  else {
    printf("%s->\n", head->cargo);
    print_ll(head->next);
  }
}
//int main() {
//  struct node* llist = malloc(sizeof(struct node));
//  char a[] = "aaa";
//  char b[] = "bbb";
//  llist->cargo = a;
//  llist = add(llist, b, 0);
//  print_ll(llist);
//}
