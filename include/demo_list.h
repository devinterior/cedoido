/*
 * Declarations for the SORT demo
 *
 * Copyright (C) 2015 - Ronaldo Faria Lima
 *	
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *	
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *	
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef DEMO_LIST_H_
#define DEMO_LIST_H_

#include <stdio.h>

typedef struct {
  size_t curr;
  size_t size;
  char **data;
} list_t;

typedef void (*list_callback_t)(const char *);
typedef int (*list_comp_t)(const void *, const void *);

extern list_t *
list_create(void);

extern int
list_add(list_t *, char *);

extern void
list_delete (list_t *);

extern void
list_iter(list_t *, list_callback_t);

extern void
list_sort(list_t *, list_comp_t);

extern void
list_bubble_sort(list_t *, list_comp_t);

#endif
