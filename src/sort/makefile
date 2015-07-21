#
# Sort build makefile
#
# Copyright (C) 2015 - Ronaldo Faria Lima
#	
# This program is free software: you can redistribute it and/or modify it under
# the terms of the GNU General Public License as published by the Free Software
# Foundation, either version 3 of the License, or (at your option) any later
# version.
#	
# This program is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
# FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
# details.
#	
# You should have received a copy of the GNU General Public License along with
# this program.  If not, see <http://www.gnu.org/licenses/>.

OUTDIR=../../bin
OUT=$(OUTDIR)/sort
EXTSRCDIR=../list
EXTSRC=$(EXTSRCDIR)/list_add.c $(EXTSRCDIR)/list_create.c $(EXTSRCDIR)/list_delete.c $(EXTSRCDIR)/list_iter.c $(EXTSRCDIR)/list_sort.c
SRC=main.c $(EXTSRC)
OBJ=$(SRC:%.c=%.o) $(EXTSRC:%.c=%.o)
CFLAGS=$(DEBUG) -I ../../include

.PHONY: clean

all: $(OUTDIR) $(OUT) 

$(OUT): $(OBJ)
	$(CC) $(LDFLAGS) $^ -o $@

$(OUTDIR):
	mkdir $@

$(OBJ): $(SRC)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	\rm -f $(OBJ)
	\rm -f $(OUT)
