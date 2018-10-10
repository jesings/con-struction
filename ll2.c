#include <stdlib.h>
#include <stdio.h>
#include "node.h"
#include "bastrlib.h"

unsigned char* rand_string(int length, unsigned char* charset){   
    int i = 0;
    for(;i<length;i++){
        unsigned char aynrand = (unsigned char) (rand()%95) + 32;
        charset[i]=aynrand;
    }
    charset[i] = 0;
    return charset;
}

struct node* add(struct node* head, unsigned char* str, int i) {
  struct node* n = malloc(sizeof(struct node));
  bastrcpy(n->cargo,str);
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

struct node* add_rand(struct node* head, int i) {
  char chargo[11]; 
  return add(head, rand_string(10,chargo), i);
}

struct node* make_rand() {
  struct node* new = malloc(sizeof(struct node*));
  char chargo[11]; 
  bastrcpy(new->cargo,rand_string(10,chargo));
  return new;
}

struct node* make_literal(unsigned char* str) {
  struct node* new = malloc(sizeof(struct node*));
  char chargo[11]; 
  bastrcpy(new->cargo,str);
  return new;
}

struct node* add_literal(struct node* head, unsigned char* str, int i) {
  char chargo[11]; 
  return add(head, bastrcpy(chargo, str), i);
}

struct node* insert_front(struct node* head, struct node* to_insert){
    to_insert->next = head; 
    return to_insert;
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

struct node* free_list(struct node* head) {
    
  if(head)
    for (struct node* i = head -> next; i; i = i->next) {
      free(head);
      head = i;
    }
  return head;
}

void print_list(struct node* head) {
  if (head) {
    printf("%s->\n", head->cargo);
    print_list(head->next);
  } else
    printf("\n");
};
