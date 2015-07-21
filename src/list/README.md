# Rotinas LIST

As rotinas deste diretório são, na verdade, uma implementação simples de vetores
infinitos. O nome _lista_ é inapropriado. Como a intenção é demonstrar alguns
princípios da linguagem e como o algoritmo é utilizado como uma lista,
efetivamente, mantive assim o nome.

Estas rotinas criam uma tabela que acomoda uma string em cada elemento. À medida
em que novos elementos são adicionados, a tabela é redimensionada se necessário.

A tabela é redimensionada em pacotes de tamanho BUFSIZ, uma constante declarada
em stdio.h. Esta constante determina o tamanho ótimo de um buffer para a
plataforma no intuito de otimizar o I/O.

Assim, é uma boa ideia usar esta constante para os pacotes pois se o programa
for parar no swap do sistema operacional, a memória estará devidamente otimizada
em pacotes que permitirão a leitura e escrita de forma ótima.

## Patterns

Observe que as rotinas são orientadas ao objeto. Apesar da estrutura list_t não
ser opaca, as funçòes funcionam como se fossem métodos, com direito a um
construtor e um destrutor da classe.
