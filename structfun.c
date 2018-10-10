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
      root = insert_front(root,make_rand());
    }
    print_list(root);
    printf("destructing\n\n");
    printf("%d\n",*free_list(root));
    
    printf("All Star:\n");
    struct node* ll1 = NULL;
    int i = 0;
    ll1 = insert_front(ll1,make_literal("roll me"));
    ll1 = insert_front(ll1,make_literal("the world"));
    ll1 = insert_front(ll1,make_literal("told me"));
    ll1 = insert_front(ll1,make_literal("once"));
    ll1 = insert_front(ll1,make_literal("body"));
    ll1 = insert_front(ll1,make_literal("Some"));
    print_list(ll1);

    printf("de-structing All Star:\n");
    
    printf("%d\n",*free_list(ll1));
    printf("All Star destructed:\n\n");
    
    printf("\n");
    printf("And a free parody:\n");
    
    printf("Well, the structs start coming and they don't stop coming, pointers and adresses and my program isn't running but the error messages beg to differ judging by the syntax in the function definition \n");
    return 0;
}
