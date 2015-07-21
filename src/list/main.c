/*
 * Main module of the list test application
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

#include "demo_list.h"

static void
show_item(const char *);

int main(void) {
  int i;
  list_t *list = list_create();
  for(i=0; i<10; ++i) {
	char *buf = (char *)malloc(BUFSIZ);
	if (!buf) {
	  return -1;
	}
	sprintf(buf, "item %d", i + 1);
	list_add(list, buf);
  }
  list_iter (list, show_item);
  list_delete(list);
  return 0;
}

/* Will be used as a callback function on list_iter call */
static void
show_item (const char *p) {
  printf ("Item [%s]\n", p);
}
