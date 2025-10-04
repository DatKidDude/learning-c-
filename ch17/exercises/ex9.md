True of False: If x is a structure and a is a member of that structure, the (&x)->a is the same x.a. Justify your answer.

True

In the statement (&x)->a, x is a pointer to a. The -> dereferences a and expands to (&x).a.
The parantheses are necessary because -> has a higher precedence than (&) which would expand
to &(x->a).
