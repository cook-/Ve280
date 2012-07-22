#ifndef __LIST_H__
#define __LIST_H__

struct opaque_list;
typedef opaque_list *list_t;

extern bool list_isEmpty(list_t list);
   // EFFECTS: returns true if list is empty, false otherwise

list_t list_make();
   // EFFECTS: returns an empty list.

list_t list_make(int elt, list_t list);
   // EFFECTS: given the list (list) make a new list consisting of
   //          the new element followed by the elements of the
   //          original list. 

extern int list_first(list_t list);
   // REQUIRES: list is not empty
   // EFFECTS: returns the first element of list

extern list_t list_rest(list_t list);
   // REQUIRES: list is not empty
   // EFFECTS: returns the list containing all but the first element of list

extern void list_print(list_t list);
    // MODIFIES: cout
    // EFFECTS: prints list to cout.

#endif /* __LIST_H__ */
