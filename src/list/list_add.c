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

/*
 * Esta rotina adiciona um elemento à lista. Nesta implementação, o elemento é
 * uma cadeia de caracteres. Porém, poder-se-ia implementar uma rotina mais
 * geral que trata-se tipos arbitrários, através do uso de pointers para void
 * para o elemento.
 *
 * Esta rotina baseia-se no princípio de que sempre redimensionaremos a lista
 * quando necessário. Da primeira vez que é executada, a lista está vazia e não
 * tem memória alocada. Neste cenário, realloc, a função de alocação que usei da
 * lib STDC, irá funcionar como um malloc comum. Porém, nas chamadas
 * subsequentes, a arena de memória apontada por list->data será redimensionada.
 */
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
	/*
	 * Observe o deslocamento de newbuf para a inicialização por memset. Como
	 * partimos da suposição que a lista sempre será redimensionada, é
	 * necessário inicializar a memória somente dos novos itens e não dos itens
	 * existentes. Por este motivo, calcula-se o deslocamento da lista com
	 * relação ao que já foi usado e, ainda, o tamanho desta arena nova.
	 *
	 * Quando for executada da primeira vez, curr = 0 e com isso TODA a lista
	 * será inicializada. Deixamos para adicionar o elemnto à lista depois de
	 * realizada esta inicialização.
	 */
	memset (newbuf + list->curr, 0x0, list->size - list->curr);
	list->data = newbuf;
  }
  list->data[list->curr] = elem;
  list->curr++;
  return 0;
}
