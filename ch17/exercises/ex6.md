Modify the delete_from_list function so that it uses only one pointer variable instead of two (cur and prev)

```C
struct node *delete_from_list(struct node **list, int n)
{
    struct node *cur = *list;
    while (cur) {
        if (cur->value == n) {
            *list = cur->next;
            free(cur);
            break;
        }
        list = &cur->next;
        cur = cur->next;
    }
    return *list;
}
```
