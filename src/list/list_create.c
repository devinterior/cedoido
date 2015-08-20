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

#include <stdlib.h>
#include <string.h>
#include "demo_list.h"
#include "demo_instr.h"

/*
 * Esta rotina cria uma lista. Observe que a lista é criada dinamicamente,
 * através da alocação de memória para o tipo list_t. Há um pattern aqui muito
 * comum em rotinas de alocação de memória: se a alocação falhar, a rotina
 * retorna um pointer nulo. Isso fica implícito no uso do malloc. Sempre que o
 * malloc falha, ele retorna NULL, que é uma macro que expande para (void *)0x0.
 */
list_t *
list_create (void) {
  list_t *list = (list_t *)malloc(sizeof (list_t));
  if (list) {
	/* 
	 * Observe o uso de memset neste contexto. malloc devolve a memória, mas sem
	 * inicialização do conteúdo. Ou seja, o que quer que malloc devolva, contém
	 * dados arbitrários. Assim, o memset é usado aqui para escrever na nova
	 * arena de memória um padrão. No caso, escolhi o número 0x0 para ser este
	 * padrão. Este é um pattern muito comum na inicialização de arenas de
	 * memória recém-criadas. 
	 */
	memset (list, 0x0, sizeof(list_t));
  }
#ifndef NDEBUG
  else {
	DBGPRINT("Failed to get memory for list creation: %s - %d", __FILE__, __LINE__);
  }
#endif
  return list;
}
