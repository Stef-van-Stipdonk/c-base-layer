// list.h

/*
 * This header expects the following macros to be defined by the user before
 * inclusion:
 * - LIST_T: The type of elements in the list.
 * - (Optional) LIST_PREFIX: A prefix to be used for the generated function
 * names.
 *
 * Example:
 * #define LIST_T int
 * #define LIST_PREFIX int_list_
 * #include "list.h"
 */

#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

#define LIST_IMPL(word) LIST_COMB1(LIST_PREFIX, word)
#define LIST_COMB1(pre, word) LIST_COMB2(pre, word)
#define LIST_COMB2(pre, word) pre##word

#ifndef LIST_T
#define LIST_T int
#pragma message(                                                               \
    "LIST_T is not defined, using int as default for editing. Remember to define LIST_T before including this header.")
#endif

#ifndef LIST_NAME
#define LIST_NAME LIST_COMB1(LIST_COMB1(list, _), LIST_T)
#endif

#ifndef LIST_PREFIX
#define LIST_PREFIX LIST_COMB1(LIST_NAME, _)
#endif

#ifndef LIST_LINKAGE
#define LIST_LINKAGE static inline
#endif

typedef struct LIST_NAME LIST_NAME;
struct LIST_NAME {
  LIST_T *items;
  size_t count;
  size_t capacity;
};

#define LIST_push LIST_IMPL(push)

#ifdef LIST_DECLS_ONLY

LIST_LINKAGE
void LIST_push(LIST_NAME *array, LIST_T item);

#else

LIST_LINKAGE void LIST_push(LIST_NAME *array, LIST_T item) {
  if (array->count >= array->capacity) {
    size_t old_cap = array->capacity;
    size_t new_cap = old_cap ? old_cap * 2 : 4;
    size_t new_size = new_cap * sizeof(LIST_T);
    array->items = realloc(array->items, new_size);
    array->capacity = new_cap;
  }
  array->items[array->count++] = item;
}

#endif

#undef LIST_T
#undef LIST_PREFIX
#undef LIST_NAME
#undef LIST_LINKAGE
#undef LIST_push
#ifdef LIST_DECLS_ONLY
#undef LIST_DECLS_ONLY
#endif

#endif // LIST_H
