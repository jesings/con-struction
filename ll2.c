#include <stdlib.h>
#include <stdio.h>
#include "node.h"
#include "ll2.h"
#include "bastrlib.h"
const int STRING_LEN = 10;

unsigned char* rand_string(int length, unsigned char* charset){   
    int i = 0;
    for(;i<length;i++){
        unsigned char aynrand = (unsigned char) (rand()%95) + 32;
        charset[i]=aynrand;
    }
    charset[i] = 0;
    return charset;
}

struct node* add_rand(struct node* head, int i) {
  unsigned char* chargo = malloc((STRING_LEN+1)*sizeof(char));
  return add(head, rand_string(STRING_LEN,chargo), i);
}

struct node* add_literal(struct node* head, unsigned char* str, int i) {
  unsigned char* chargo = malloc(bastrlen(str) * sizeof(char));
  return add(head, bastrcpy(chargo, str), i);
}

struct node* add(struct node* head, unsigned char* str, int i) {
  struct node* n = malloc(sizeof(struct node));
  n->cargo = str;
  n->next = NULL;
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

struct node* destruct(struct node* head) {
  if(head)
    for (struct node* i = head -> next; i; i = i->next) {
      free(head->cargo);
      free(head);
      head = i;
    }
  return NULL;
}

int print_ll(struct node* head) {
  if (head) {
    printf("%s->\n", head->cargo);
    print_ll(head->next);
  } else
    printf("\n");
  return 0;
}
