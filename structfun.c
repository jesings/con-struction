#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "node.h"
#include "ll2.h"

int main(){
    srand(time(NULL));
    printf("random list:\n");
    struct node* root = NULL;
    for(int i = 0 ;i<10;i++){
      root = add_rand(root,i);
    }
    print_ll(root);
    printf("destructing\n\n");
    destruct(root);
    
    printf("All Star:\n");
    struct node* ll1 = NULL;
    int i = 0;
    ll1 = add_literal(ll1,"Some",i++);
    ll1 = add_literal(ll1,"body",i++);
    ll1 = add_literal(ll1,"once",i++);
    ll1 = add_literal(ll1,"told me",i++);
    ll1 = add_literal(ll1,"the world",i++);
    ll1 = add_literal(ll1,"was gonna",i++);
    ll1 = add_literal(ll1,"roll me",i++);
    print_ll(ll1);
    
    printf("All Star with every other beat removed:\n");
    remove_node(ll1,1);
    remove_node(ll1,2);
    remove_node(ll1,3);
    print_ll(ll1);

    printf("de-structing All Star:\n");
    destruct(ll1);
    printf("All Star destructed:\n\n");
    
    printf("\n");
    printf("And a free parody:\n");
    
    printf("Well, the structs start coming and they don't stop coming, pointers and adresses and my program isn't running but the error messages beg to differ judging by the syntax in the function definition \n");
    return 0;
}
