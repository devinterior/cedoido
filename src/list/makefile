#
# Main module of the sort command
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
OUT=$(OUTDIR)/list_test
SRC=list_add.c list_iter.c list_create.c list_delete.c list_sort.c list_bubble_sort.c main.c
OBJ=$(SRC:%.c=$(OUTDIR)/%.o)
CFLAGS=-I ../../include
ifneq ($(DEBUG), 1)
	CFLAGS:=$(CFLAGS) -DNDEBUG
	MESSAGE="produção"
else
	MESSAGE="depuração"
	CFLAGS:=$(CFLAGS) -g
endif

.PHONY: clean

all: $(OUT)
	@echo "Feito!"

$(OUT): $(OBJ)
	@$(CC) $(LDFLAGS) $^ -o $@
	@echo "Ligando..."

$(OUTDIR):
	mkdir $@

$(OBJ): $(SRC)

$(OUTDIR)/%.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@
	@echo "\tCompilando $< para $(MESSAGE)"
clean:
	@echo "Limpando..."
	@\rm -f $(OBJ)
	@\rm -f $(OUT)
	@echo "Feito!"
