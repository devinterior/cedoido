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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "demo_list.h"

#define OPTION_REVERSE 0x1 /* 0000 0001 */
#define OPTION_HELP    0x2 /* 0000 0010 */
#define OPTION_LICENSE 0x4 /* 0000 0100 */

const static char license_text[] =
  "This program is free software: you can redistribute it and/or modify it under\n" \
  "the terms of the GNU General Public License as published by the Free Software\n" \
  "Foundation, either version 3 of the License, or (at your option) any later\n" \
  "version.\n\n"														\
  "This program is distributed in the hope that it will be useful, but WITHOUT\n" \
  "ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS\n" \
  "FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more\n" \
  "details.\n\n"														\
  "You should have received a copy of the GNU General Public License along with\n" \
  "this program.  If not, see <http://www.gnu.org/licenses/>.\n";

static unsigned
get_commandline_options(int, char **);

static list_t *
create_list(FILE *input);

static void
show_item(const char *);

static int
sort_callback (const void *, const void *);

static int
reverse_sort_callback (const void *, const void *);

int
main(int argc, char **argv) {
  int (*callback)(const void *, const void *) = sort_callback;
  unsigned options = get_commandline_options(argc, argv);
  if ((options & OPTION_HELP) == OPTION_HELP) {
	printf("Usage: sort [-l][-h][-r]\n"			\
		   "\t-l: Show software license\n"		\
		   "\t-h: Show this helo screen\n"		\
		   "\t-r: Reverses the ordering\n");
	return 0;
  } else if ((options & OPTION_REVERSE) == OPTION_REVERSE) {
	callback = reverse_sort_callback;
  } else if ((options & OPTION_LICENSE) == OPTION_LICENSE) {
	printf (license_text);
	return 0;
  }
  int i;
  list_t *list = create_list(stdin);
  if (!list) {
	perror("Error creating data list\n");
	return -1;
  }
  list_sort(list, callback);
  list_iter (list, show_item);
  list_delete (list);
  return 0;
}

static unsigned
get_commandline_options(int argc, char **argv) {
  unsigned options = 0x0;
  register int i;
  for (i = 0; i < argc; ++i) {
	char *p = argv[i];
	if (!strcmp(p, "-r")) {
	  options |= OPTION_REVERSE;
	} else if (!strcmp(p, "-l")) {
	  options |= OPTION_LICENSE;
	} else if (!strcmp(p, "-h")) {
	  options |= OPTION_HELP;
	}
  }
  return options;
}

static list_t *
create_list(FILE *input) {
  list_t *list = list_create();
  char buf[BUFSIZ];
  while(fgets(buf, BUFSIZ, input)) {
	size_t len = strlen(buf);
	char *read_buf = (char *)malloc (len + 1);
	if (! read_buf) {
	  list_delete(list);
	  return NULL;
	}
	strcpy (read_buf, buf);
	/* Deletes the trailing \n */
	read_buf[len - 1] = '\0';
	if (list_add(list, read_buf)) {
	  list_delete(list);
	  return NULL;
	}
  }
  return list;
}

/* Will be used as a callback function on list_iter call */
static void
show_item (const char *p) {
  printf ("Item [%s]\n", p);
}

static int
sort_callback (const void *pa, const void *pb) {
  const char **a = (const char **)pa;
  const char **b = (const char **)pb;
  return strcmp (*a, *b);
}

static int
reverse_sort_callback (const void *pa, const void *pb) {
  const char **a = (const char **)pa;
  const char **b = (const char **)pb;
  return strcmp (*b, *a);
}
