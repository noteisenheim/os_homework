#include <stdio.h>
#include <stdlib.h>

struct n
{
	int value;
	struct n *next;
};

struct ll
{
	struct n *head;
};

typedef struct ll linked_list;
typedef struct n node;

void print_list(linked_list *list);
void insert_node(linked_list *list, node *n, int inserted);
void delete_node(linked_list *list, node *n);

node* create_node(int val)
{
	node *n = malloc(sizeof(int) + sizeof(node*));
	n->value = val;
	n->next = NULL;
	return n;
}

int main()
{
	linked_list *a;
	node *node1, *node2, *node3, *node4;

	node1 = create_node(5);
	node2 = create_node(3);
	node3 = create_node(7);
	node4 = create_node(1);

	a = malloc(sizeof(node*));

	a->head = node1;

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;

	printf("The original list: ");
	print_list(a);
	printf("\n");

	printf("Inserting the value 13 after the 2nd node: ");
	insert_node(a, node2, 13);
	print_list(a);
	printf("\n");

	printf("Deleting the node coming after the 2nd node: ");
	delete_node(a, node2);
	print_list(a);

	return 0;
}

void print_list(linked_list *list)
{
	node *n = list->head;
	while(n->next != NULL)
	{
		printf("%d ", n->value);
		n = n->next;
	}
	printf("%d ", n->value);
}

void insert_node(linked_list *list, node *n, int inserted)
{
	node *ins = create_node(inserted);
	ins->next = n->next;
	n->next = ins;
}

void delete_node(linked_list *list, node *n)
{
	node *temp = n->next;
	n->next = temp->next;
	temp->next = NULL;
}