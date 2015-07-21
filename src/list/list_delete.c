/*
 * Deletes the entire list
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

#include <assert.h>
#include "demo_list.h"

void
list_delete(list_t *list) {
  assert(list != NULL);
  if (list->size == 0x0l) {
	return;
  }
  char **p = list->data;
  do {
	if (! *p) {
	  break;
	}
	free (*p);
	*p = 0x0;
	++p;
	list->curr--;
  } while (list->curr);
  list->size = 0x0;
  free (list->data);
  free (list);
}
