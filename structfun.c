#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
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
struct node{
    struct node* next;
    unsigned char* cargo;
};
struct linked_list{
    struct node* head;
    struct node* tail;
};
int print_from_node(struct node* base){
    if(base){         
        printf("%s %s\n",base->cargo," ==> ");
        return print_from_node(base->next);
    }
    return 0;
}
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
    print_from_node(root);
    return 0;
}
