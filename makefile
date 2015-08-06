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

OUTPUT=bin

all: splash $(OUTPUT)
	@echo "Compilando lists..."
	@cd src/list && $(MAKE)
	@echo "Compilando sort..."
	@cd src/sort && $(MAKE)
	@echo "Compilando bubble..."
	@cd src/bubble && $(MAKE)
	@echo "Compilando cpfcheck..."
	@cd src/cpfcheck && $(MAKE)

	@echo "\nMódulos compilados no diretório bin.\n"

$(OUTPUT):
	@echo "Criando diretório de saída..."
	@mkdir $@
	@echo "Diretório criado."

clean: splash
	@cd src/list && $(MAKE) clean
	@cd src/sort && $(MAKE) clean
	@cd src/bubble && $(MAKE) clean
	@cd src/cpfcheck && $(MAKE) clean
	@rmdir $(OUTPUT)

splash:
	@echo "DEV INTERIOR C É DOIDO"
	@echo "Compilação do código-fonte de exemplo"
	@echo "Autor: Ronaldo F. Lima <ronaldo@nineteen.com.br>"
	@echo "----"
