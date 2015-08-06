#
# CPF Validation demo
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
OUT=$(OUTDIR)/cpfcheck
SRC=main.c cpf.c
OBJ=$(SRC:%.c=%.o)
CFLAGS=-I ../../include
ifneq ($(DEBUG), 1)
	CFLAGS:=$(CFLAGS) -DNDEBUG
	MESSAGE="produção"
else
	MESSAGE="depuração"
	CFLAGS:=$(CFLAGS) -g
endif

.PHONY: clean

all: $(OUTDIR) $(OUT)
	@echo "\tFeito!"

$(OUT): $(OBJ)
	@$(CC) $(LDFLAGS) $^ -o $@
	@echo "\tLigando..."

$(OUTDIR):
	@echo "\tCriando $@"
	@mkdir $@

$(OBJ): $(SRC)

%.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@
	@echo "\tCompilando $< para $(MESSAGE)"

clean:
	@echo "Limpando..."
	@\rm -f $(OBJ)
	@\rm -f $(OUT)
	@echo "Feito!"
