/* "general use" stack
 *
 * Caller takes care of memory management.  Neither push or pop cares.  They
 * only receive pointers.
 *
 * Usefull only to: LIFO pointers
 */

#ifndef ESTRUCTURAS_VOIDPTR_STACK_H
#define ESTRUCTURAS_VOIDPTR_STACK_H

void stack_create(void *&top);

/* push the already allocated pointer to the top of the stack */
void stack_push(void *&top, void *elem);

/* pop top element of the stack.  Free the space it takes yourself after use. */
void *stack_pop(void *&top);

/* returns 1 if empty, 0 otherwise. */
int stack_isempty(void *top);

void *stack_top(void *top);


#endif /* ESTRUCTURAS_VOIDPTR_STACK_H */
