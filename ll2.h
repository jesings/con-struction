struct node* add(struct node* head, unsigned char* str, int i);
struct node* add_rand(struct node* head, int i);
struct node* add_literal(struct node* head, unsigned char* str, int i);
struct node* remove_node(struct node* head, int i);
struct node* destruct(struct node* head);
int print_ll(struct node* head);
unsigned char* rand_string(int length, unsigned char* charset);
