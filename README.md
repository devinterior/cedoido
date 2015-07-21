# C é Doido

Este código-fonte é o material de apoio da palestra "C é doido", ministrada por
Ronaldo F. Lima no Dev Interior.

Todo o código foi escrito em STD C e deve compilar na grande maioria dos
compiladores que suportam o último padrão da linguagem.

Para compilar o código é necessário ter instalado no seu sistema:

- GNU Make ou Make
- Compilador C
- Assembler (normalmente acompanha o compilador C)
- Linker

Todo o código foi testado no Mac OS X, mas a compilação será a mesma em sistemas
unix e linux.

## Compilando o código

Para compilar o código:

`make`

Todo o código compilado estará disponível no diretório `bin`.

Para reiniciar a compilação:

`make clean`

## Organização do Código

Seguiu-se a organização padrão de códigos escritos em C:

- diretório src: contém os arquivos .c e alguns makefiles, dependendo do módulo
  sendo compilado
- diretório include: contém os header files necessários para a correta
  compilação dos exemplos
- diretório bin: contém os binários, fruto da compilação. Este diretório é
gerado automaticamente pelo makefile

## Licença

O código em questão está sob a licença GPL e pode ser copiado, modificado e
utilizado de acordo com os termos da licença.
