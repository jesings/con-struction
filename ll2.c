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

struct node* remove(struct node* head, int i) {
  if (i) {
    struct node* tmp = head;
    for (; --i; tmp = tmp->next);
    struct node* trash = tmp->next;
    tmp->next = tmp->next->next;
  } else {
    struct node* trash = head;
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
  if (head)
    print("/n");
  else {
    printf("%s, ", head->cargo);
    print(head->next);
  }
}
int main() {
  struct node* llist = malloc(sizeof(struct node));
  char a[] = "aaa";
  char b[] = "bbb";
  llist->cargo = a;
  llist = add(llist, b, 0);
  print_ll(llist);
}
