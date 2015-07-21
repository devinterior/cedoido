/*
 * Iterates through the entire list and call a callback for each found item
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
list_iter(list_t *list, list_callback_t callback) {
  assert(list != NULL);
  assert(callback != NULL);
  char **p = list->data;
  size_t n = 0;
  do {
	callback((const char *)*p);
	++p;
	++n;
  } while(n < list->curr);
}
