struct node* add(struct node* head, unsigned char* str, int i);
struct node* add_rand(struct node* head, int i);
struct node* make_literal(unsigned char* str);
struct node* make_rand();
struct node* insert_front(struct node* head, struct node* to_insert);
struct node* add_literal(struct node* head, unsigned char* str, int i);
struct node* remove_node(struct node* head, int i);
struct node* free_list(struct node* head);

void print_list(struct node* head);
unsigned char* rand_string(int length, unsigned char* charset);
