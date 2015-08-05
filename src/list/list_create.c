/*
 * Creates a list
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
#include "demo_list.h"
#include "demo_instr.h"

list_t *
list_create (void) {
  list_t *list = (list_t *)malloc(sizeof (list_t));
  if (list) {
	memset (list, 0x0, sizeof(list_t));
  }
#ifndef NDEBUG
  else {
	DBGPRINT("Failed to get memory for list creation: %s - %d", __FILE__, __LINE__);
  }
#endif
  return list;
}
