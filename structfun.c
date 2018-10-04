#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "node.h"
#include "ll2.h"

int main(){
    srand(time(NULL));
    printf("random list:\n")
    struct node* root;
    root = add_rand(root,0);
    struct node* last = root;
    for(int i = 1 ;i<10;i++){
        struct node* new = add_rand(root,i);
        printf("%x\n",new);
        last = new;
    }
    last->next = NULL;
    print_ll(root);
    
    struct node* ll1;
    int i = 0;
    ll1 = add(root,"Some",i++);
    add(ll1,"body",i++);
    add(ll1,"once",i++);
    add(ll1,"told me",i++);
    add(ll1,"the world",i++);
    add(ll1,"was gonna",i++);
    add(ll1,"roll me",i++)->next = NULL;
    print_ll(ll1);
    
    return 0;
}
