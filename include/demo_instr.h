/*
 * Declarations for code instrumentation
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

#ifndef DEMO_INSTR_H_
#define DEMO_INSTR_H_

#include <stdio.h>

/*
 * Observe a compilação condicionada. A macro NDEBUG é usada pela biblioteca
 * STDC para evitar compilar instrumentação, em especial, pelo cabeçalho
 * assert.h. Neste caso, se não estiver definida a macro DBGPRINT torna-se
 * definida. Caso contrário, a macro expande para absolutamente nada. Este é um
 * truque muito interessante que usa o pré-processador C para gerar código de
 * forma condicionada.
 */
#ifndef NDEBUG
#define DBGPRINT(...) fprintf(stderr, __VA_ARGS__)
#else
#define DBGPRINT(...)
#endif

#endif
