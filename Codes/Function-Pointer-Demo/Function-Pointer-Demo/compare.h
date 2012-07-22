#ifndef __COMPARE_H__
#define __COMPARE_H__

#include "list.h"

extern int smallest(list_t list);
// REQUIRES: list is not empty
// EFFECTS: returns smallest element in list

extern int largest(list_t list);
// REQUIRES: list is not empty
// EFFECTS: returns largest element in list

#endif
