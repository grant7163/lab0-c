#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "harness.h"
#include "queue.h"

/*
 * Create empty queue.
 * Return NULL if could not allocate space.
 */
queue_t *q_new()
{
    queue_t *q = malloc(sizeof(queue_t));
<<<<<<< HEAD
    /* TODO: What if malloc returned NULL? */
    q->head = NULL;
    return q;
=======

    /* What if malloc returned NULL? */
    if (q) {
        q->head = NULL;
        q->tail = NULL;
        q->size = 0;

        return q;
    }
    return NULL;
>>>>>>> Queue implement update
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
<<<<<<< HEAD
    /* TODO: How about freeing the list elements and the strings? */
    /* Free queue structure */
    free(q);
=======
    /* How about freeing the list elements and the strings? */
    if (q) {
        list_ele_t *temp = q->head;

        while (q->head) {
            /* Free queue structure */
            free(q->head->value);
            temp = q->head->next;
            free(q->head);
            q->head = temp;
        }
        /* Free queue structure */
        free(q);
    }
>>>>>>> Queue implement update
}

/*
 * Attempt to insert element at head of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_head(queue_t *q, char *s)
{
<<<<<<< HEAD
    list_ele_t *newh;
    /* TODO: What should you do if the q is NULL? */
    newh = malloc(sizeof(list_ele_t));
    /* Don't forget to allocate space for the string and copy it */
    /* What if either call to malloc returns NULL? */
    newh->next = q->head;
    q->head = newh;
    return true;
=======
    /* What should you do if the q is NULL? */
    if (q) {
        list_ele_t *newh = malloc(sizeof(list_ele_t));

        /* What if malloc returned NULL? */
        if (newh) {
            /* Don't forget to allocate space for the string and copy it */
            /* What if either call to malloc returns NULL? */
            newh->value = (char *) malloc(sizeof(char) * (strlen(s) + 1));

            if (newh->value) {
                strcpy(newh->value, s);

                if (q->size) {
                    newh->next = q->head;
                    q->head = newh;
                } else {
                    newh->next = q->head;
                    q->head = newh;
                    q->tail = newh;
                }

                q->size += 1;
                return true;
            }

            free(newh);
            newh = NULL;
        }
    }

    return false;
>>>>>>> Queue implement update
}

/*
 * Attempt to insert element at tail of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_tail(queue_t *q, char *s)
{
    /* TODO: You need to write the complete code for this function */
    /* Remember: It should operate in O(1) time */
<<<<<<< HEAD
    /* TODO: Remove the above comment when you are about to implement. */
=======
    if (q) {
        list_ele_t *newh = malloc(sizeof(list_ele_t));

        if (newh) {
            newh->value = (char *) malloc(sizeof(char) * (strlen(s) + 1));

            if (newh->value) {
                strcpy(newh->value, s);

                if (q->size) {
                    newh->next = NULL;
                    q->tail->next = newh;
                } else {
                    newh->next = q->head;
                    q->head = newh;
                }

                q->tail = newh;
                q->size += 1;
                return true;
            }

            free(newh);
            newh = NULL;
        }
    }

>>>>>>> Queue implement update
    return false;
}

/*
 * Attempt to remove element from head of queue.
 * Return true if successful.
 * Return false if queue is NULL or empty.
 * If sp is non-NULL and an element is removed, copy the removed string to *sp
 * (up to a maximum of bufsize-1 characters, plus a null terminator.)
 * The space used by the list element and the string should be freed.
 */
bool q_remove_head(queue_t *q, char *sp, size_t bufsize)
{
<<<<<<< HEAD
    /* TODO: You need to fix up this code. */
    /* TODO: Remove the above comment when you are about to implement. */
    q->head = q->head->next;
    return true;
=======
    /* You need to fix up this code. */
<<<<<<< HEAD
    if (q && q->head) {
        if (sp) {
=======
    if (q != NULL && q->head != NULL) {
        if (sp != NULL) {
>>>>>>> Modify q_remove_head and q_reverse function
            strncpy(sp, q->head->value, bufsize - 1);
            sp[bufsize - 1] = '\0';
        }

        list_ele_t *temp = q->head;
        q->head = q->head->next;
        free(temp->value);
        free(temp);
        q->size--;

        return true;
    }

    return false;
>>>>>>> Queue implement update
}

/*
 * Return number of elements in queue.
 * Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    /* TODO: You need to write the code for this function */
    /* Remember: It should operate in O(1) time */
<<<<<<< HEAD
    /* TODO: Remove the above comment when you are about to implement. */
    return 0;
=======
    return q ? q->size : 0;
>>>>>>> Queue implement update
}

/*
 * Reverse elements in queue
 * No effect if q is NULL or empty
 * This function should not allocate or free any list elements
 * (e.g., by calling q_insert_head, q_insert_tail, or q_remove_head).
 * It should rearrange the existing ones.
 */
void q_reverse(queue_t *q)
{
<<<<<<< HEAD
    /* TODO: You need to write the code for this function */
    /* TODO: Remove the above comment when you are about to implement. */
=======
    /* You need to write the code for this function */
    if (q && q->head) {
        list_ele_t *current;
        list_ele_t *previous = NULL;
        q->tail = q->head;

        while (current) {
            current = q->head->next;
            q->head->next = previous;
            previous = q->head;
            q->head = current;
        }

        q->head = previous;
    }
>>>>>>> Queue implement update
}

/*
 * Sort elements of queue in ascending order
 * No effect if q is NULL or empty. In addition, if q has only one
 * element, do nothing.
 */
void q_sort(queue_t *q)
{
    /* TODO: You need to write the code for this function */
    /* TODO: Remove the above comment when you are about to implement. */
=======
    /* You need to write the code for this function */
<<<<<<< HEAD
    if (q && q->head) {
        list_ele_t *current;
=======
    if (q != NULL && q->head != NULL) {
        list_ele_t *current = q->head;
>>>>>>> Modify q_remove_head and q_reverse function
        list_ele_t *previous = NULL;
        q->tail = q->head;

        while (current) {
            current = q->head->next;
            q->head->next = previous;
            previous = q->head;
            q->head = current;
        }

        q->head = previous;
    }
>>>>>>> Queue implement update
}

/*
 * Sort elements of queue in ascending order
 * No effect if q is NULL or empty. In addition, if q has only one
 * element, do nothing.
 */
void q_sort(queue_t *q)
{
    /* TODO: You need to write the code for this function */
    /* TODO: Remove the above comment when you are about to implement. */
}

