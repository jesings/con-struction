#include <stdlib.h>
#include <stdio.h>
#include "node.h"
const int STRING_LEN = 10;

unsigned char* rand_string(int length, unsigned char* charset){   
    int i = 0;
    for(;i<length;i++){
        unsigned char aynrand = (unsigned char) (rand()%256);
        charset[i]=aynrand;
    }
    charset[i] = 0;
    return charset;
}

struct node* add_rand(struct node* head, int i) {
  struct node* n = malloc(sizeof(struct node));
  unsigned char* chargo = malloc((STRING_LEN+1)*sizeof(char));
  n->cargo = rand_string(STRING_LEN,chargo);
  if (i) {
    struct node* tmp = head;
    for (; --i && tmp->next; tmp = tmp->next);
    n->next = tmp->next;
    tmp->next = n;
    return tmp;
  } else {
    n->next = head;
    head = n;
  }
  return head;
}

struct node* add(struct node* head, unsigned char* str, int i) {
  struct node* n = malloc(sizeof(struct node));
  n->cargo = str;
  if (i) {
    struct node* tmp = head;
    for (; --i && tmp->next; tmp = tmp->next);
    n->next = tmp->next;
    tmp->next = n;
    return n;
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
