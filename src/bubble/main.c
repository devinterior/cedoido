/*
 * Main module of the bubble demo
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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "demo_list.h"

static void
show_item(const char *);

static int
sort_callback (const void *, const void *);

int
main(void) {
  int i;
  list_t *list = list_create();
  char buf[BUFSIZ];
  while(fgets(buf, BUFSIZ, stdin)) {
	size_t len = strlen(buf);
	char *read_buf = (char *)malloc (len + 1);
	if (! read_buf) {
	  return -1;
	}
	strcpy (read_buf, buf);
	/* Deletes the trailing \n */
	read_buf[len - 1] = '\0';
	if (list_add(list, read_buf)) {
	  return -1;
	}
  }
  list_bubble_sort(list, sort_callback);
  list_iter (list, show_item);
  list_delete (list);
  return 0;
}

/* Will be used as a callback function on list_iter call */
static void
show_item (const char *p) {
  printf ("Item [%s]\n", p);
}

static int
sort_callback (const void *pa, const void *pb) {
  const char **a = (const char **)pa;
  const char **b = (const char **)pb;
  return strcmp (*a, *b);
}
