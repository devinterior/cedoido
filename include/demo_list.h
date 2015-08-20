/*
 * Declarations for the SORT demo
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

#ifndef DEMO_LIST_H_
#define DEMO_LIST_H_

#include <stdio.h>

/*
 * O typedef é uma palavra reservada utilizada para criar sinônimos para tipos
 * de dados. Abaixo, por exemplo, list_t é um sinônimo para a estrutura
 * declarada antes.
 */
typedef struct {
  size_t curr;
  size_t size;
  char **data;
} list_t;

/*
 * A sintaxe da linguagem C não ajuda muito no entendimento da declaração de
 * tipos de dados que são ponteiros para funções. Veja os exemplos abaixo.
 */
typedef void (*list_callback_t)(const char *);
typedef int (*list_comp_t)(const void *, const void *);

/*
 * Aqui estão os protótipos das funções que são exportadas por este arquivo de
 * cabeçalho. Note o uso da palavra-chave extern. Isso indica ao compilador que
 * os símbolos estão definidos em outro lugar. Não há problema em não escrever
 * extern aqui. Porém, isso facilita o trabalho do compilador pois este não
 * precisará inferir que o símbolo foi apenas declarado e não definido.
 *
 * Observe que os nomes dos parâmetros foram omitidos. Na declaração dos
 * protótipos o que importa de verdade para o compilador são os tipos e as
 * posições dos parâmetros. O nome do parâmetro só é necessário na definição da
 * função.
 */
extern list_t *
list_create(void);

extern int
list_add(list_t *, char *);

extern void
list_delete (list_t *);

extern void
list_iter(list_t *, list_callback_t);

extern void
list_sort(list_t *, list_comp_t);

extern void
list_bubble_sort(list_t *, list_comp_t);

#endif
