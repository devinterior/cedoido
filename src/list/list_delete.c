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

#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "demo_list.h"
#include "demo_instr.h"

/*
 * A lista é uma estrutura que contém dentro de si um vetor de
 * ponteiros. Observe que há um comportamento hierárquico na limpeza da lista:
 * primeiro passeamos na lista desalocando cada item do vetor e, por fim,
 * desalocamos o vetor e a lista propriamente dita. Como cada item da lista é
 * alocado dinamicamente, essa ação é requerida para evitar vazamentos de
 * memória.
 */
void
list_delete(list_t *list) {
  assert(list != NULL);
  if (list->size == 0x0l) {
	DBGPRINT("Empty list @ %s - %d\n", __FILE__, __LINE__);
	return;
  }
  char **p = list->data;
  do {
	free (*p);
	*p = 0x0;
	++p;
	list->curr--;
  } while (list->curr && *p);
  list->size = 0x0;
  free (list->data);
  free (list);
}
