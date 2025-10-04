/* A linked list implementation */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;          /* data stored in the node*/
    struct node *next;  /* pointer to the next node*/
};

struct node *add_to_list(struct node *list, int n);
struct node *read_numbers(void);
struct node *search_list(struct node *list, int n);
struct node *delete_from_list(struct node *list, int n);
struct node *insert_into_ordered_list(struct node *list, struct node *new_node);

/*
* *add_to_list: Add a node to the linked list. 
*               If malloc returns NULL exit.
*/
struct node *add_to_list(struct node *list, int n) 
{
    struct node *new_node;

    new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Error: malloc failed in add_to_list\n");
        exit(EXIT_FAILURE);
    }

    new_node->value = n;
    new_node->next = list;
    return new_node;
}

// Double pointer version
// struct node *add_to_list(struct node **list, int n) 
// {
//     struct node *new_node;

//     new_node = malloc(sizeof(struct node));
//     if (new_node == NULL) {
//         printf("Error: malloc failed in add_to_list\n");
//         exit(EXIT_FAILURE);
//     }

//     new_node->value = n;
//     new_node->next = *list;
//     *list = new_node;
// }

/*
* *read_numbers: User enters a series of numbers to build
*                a linked list.
*/
// struct node *read_numbers(void) 
// {
//     struct node *first = NULL;
//     int n;

//     printf("Enter a series of integers (0 to terminate): ");
//     for (;;) {
//         scanf("%d", &n);
//         if (n == 0) {
//             return first;
//         }
//         first = add_to_list(first, n);
//     }
// }

/*
* *search_list: Searches the linked list for node with value n.
*               If n is found return the node else Null.
*/
struct node *search_list(struct node *list, int n)
{
    struct node *p;

    for (p = list; p != NULL; p = p->next) {
        if (p->value == n) {
            return p;
        }
    }
    return NULL;
}

/*
* *delete_from_list: Removes a node from a linked list
*/
struct node *delete_from_list(struct node *list, int n) 
{
    struct node *cur, *prev;

    for (cur = list, prev = NULL;
         cur != NULL && cur->value != n;
         prev = cur, cur = cur->next);
    
    if (cur == NULL) return list;   /* n was not found*/
    
    if (prev == NULL) {
        list = list->next;          /* n is in the first node */
    } else {
        prev->next = cur->next;     /* n is in some other node */
    }
    free(cur);
    return list;
}

struct node *insert_into_ordered_list(struct node *list, struct node *new_node)
    {
        struct node *cur = list, *prev = NULL;
        while (cur->value <= new_node->value) {
            prev = cur;
            cur = cur->next;
        }
        prev->next = new_node;
        new_node->next = cur;
        return list;
    }

struct node *read_numbers(void) 
{
    struct node *first = NULL;
    struct node *temp;
    int n;

    printf("Enter a series of integers (0 to terminate): ");
    for (;;) {
        scanf("%d", &n);
        if (n == 0) {
            return first;
        }
        temp->value = n;
        temp->next = NULL;
        first = insert_into_ordered_list(first, temp);
    }
}

int main(void) 
{

    struct node *llist = read_numbers();
    struct node temp = {3, NULL};

    llist = insert_into_ordered_list(llist, &temp);

    while (llist) {
        printf("%d\n", llist->value);
        llist = llist->next;
    }

    return 0;
}