The following loop is supposed to delete all nodes from a linked list and release the memory that they occupy. Unfortunately, the loop is incorrect. Explain what's wrong with it and show how to fix the bug.

    ```C
    for (p = first; p != NULL; p = p->next)
        free(p);
    ```

    ```C
    void delete_all_nodes(struct node *list)
    {
        struct node *p, *temp;

        for (temp = p = list; p != NULL; p = temp){
            temp = p->next;
            free(p);
        }
    }
    ```

Solution: The original for loop is incorrect because after the first loop p loses
the pointer to the rest of struct's address space. One solution is to create a
temporary variable to store the next node before the memory is freed.
