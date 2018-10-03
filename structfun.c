#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "node.h"
#include "ll2.h"
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
//struct linked_list{
//    struct node* head;
//    struct node* tail;
//};

struct node* malloc_node(struct node* myn){
    myn = malloc(sizeof(struct node));
    unsigned char* chargo = malloc((STRING_LEN+1)*sizeof(char));
    myn->cargo = rand_string(STRING_LEN,chargo);
    return myn;
}
int main(){
    srand(time(NULL));
    struct node* root = malloc_node(root);
    struct node* last = root;
    for(int i = 0 ;i<10;i++){
        struct node* new = malloc_node(new);
        last->next = new;
        last = new;
    }
    last->next = NULL;
    print_ll(root);
    return 0;
}
