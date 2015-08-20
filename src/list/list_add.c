/*
 * Adds a string to a list
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
#include <string.h>
#include <errno.h>
#include <assert.h>
#include "demo_list.h"
#include "demo_instr.h"

int
list_add(list_t *list, char *elem) {
  assert(list != NULL);
  assert(elem != NULL);
  DBGPRINT("In list_add, %s - %d\n", __FILE__,  __LINE__);
  if (list->curr >= list->size) {
	/* Resizes the list table */
	list->size += BUFSIZ;
	char **newbuf = (char **)realloc(list->data, list->size);
	if (!newbuf) {
	  /* No memory. Destroy everything and return an error status */
	  list_delete(list);
	  DBGPRINT("Low memory error in list_add, %s - %d\n", __FILE__,  __LINE__);
	  return ENOMEM;
	}
	/* Necessary in order to deallocate unused arenas later */
	memset (newbuf + list->curr, 0x0, list->size - list->curr);
	list->data = newbuf;
  }
  list->data[list->curr] = elem;
  list->curr++;
  return 0;
}
