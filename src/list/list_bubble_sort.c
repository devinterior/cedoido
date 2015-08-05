/*
 * Orders a list using the bubble sort algorithm
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

#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "demo_list.h"

static void
bubble_sort(void *, size_t, size_t, int (*)(const void *, const void *));

void
list_bubble_sort(list_t *list, list_comp_t callback) {
  bubble_sort(list->data, list->curr, sizeof(char *), callback);
}

/* A free implementation of the insertion sort (bubble sort) algorithm. This
   implementation is generic and can be used on any kind of data type. The only
   constraint is that data must be put into an array. */
static void
bubble_sort(void *base, size_t nelem, size_t width, int (*comp)(const void *, const void *)) {
  unsigned char *p = (unsigned char *)base;
  register int j;
  void *key = malloc (width);
  if (! key) {
	return;
  }
  for (j = 1; j < nelem; ++j) {
	memcpy(key, p + (j * width), width);
	register int i = j - 1;
	while (i >= 0 && comp(p + (i * width), key) > 0) {
	  memcpy(p + ((i + 1) * width), p + (i * width), width);
	  --i;
	}
	memcpy(p + (i + 1) * width, key, width);
  }
  free(key);
}
