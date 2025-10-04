Suppose that f and p are declared as follows:

    ```C
    struct {
        union {
            char a, b;
            int c;
        } d;
        int e[5];
    } f, *p = &f;
    ```

Which of the following statements are legal?

    ```C
    (a) p->b = ' ';
    (b) p->e[3] = 10;
    (c) (*p).d.a = '*';
    (d) p->d->c = 20;
    ```

Solution:
(b) and (c) are legal.
(a) is not legal because d must be referenced before b: p->d.b = ' ';
(d) is not legal because d is a union object not a pointer to a union: p->d.c = 20;
