Implementação do Algoritmo de Huffman

O objetivo deste projeto é implementar um programa em linguagem C que utilize o Algoritmo de Huffman para compressão de dados. O Algoritmo de Huffman é um método eficiente de compressão que cria uma árvore binária baseada nas frequências dos caracteres em um texto, gerando uma codificação de comprimento variável onde os caracteres mais frequentes têm códigos mais curtos. Esta técnica é amplamente utilizada em diversas aplicações de compressão de dados.

Funcionalidades:

Adicionar Caracteres e Frequências:

Comando: add <caractere> <frequência>
Permite ao usuário informar a frequência de um caractere específico. Se o caractere já foi informado, sua frequência é atualizada.
Calcular Códigos de Huffman:

Comando: calc
Calcula os códigos de Huffman com base nos caracteres e frequências informados até o momento.
Imprimir Tabela de Códigos:

Comando: print
Exibe a tabela de códigos de Huffman calculados, mostrando cada caractere, sua frequência e seu código binário correspondente.
Codificar uma String:

Comando: cod <string>
Codifica uma string fornecida pelo usuário utilizando os códigos de Huffman gerados. Além da sequência de 0's e 1's resultante, o programa também informa as taxas de compactação em relação à codificação com 8 bits e ao número mínimo de bits necessários para representar todos os caracteres.
Decodificar uma Sequência de Bits:

Comando: dec <bits>
Decodifica uma sequência de bits fornecida pelo usuário, retornando a string original baseada na árvore de Huffman gerada.
Limpar Tabela de Frequências:

Comando: clear
Limpa a tabela de frequências, permitindo que o usuário recomece a entrada de novos caracteres e frequências.
Sair do Programa:

Comando: exit
Encerra a execução do programa.

Exemplo de Utilização:
-> add A 3
-> add C 2
-> add B 1
-> add D 1
-> calc
-> print
A com frequencia 3 codificado como 0
B com frequencia 1 codificado como 100
C com frequencia 2 codificado como 11
D com frequencia 1 codificado como 101
-> dec 0100011111010
ABACCDA
-> exit

Para compilar e executar o programa, siga os passos abaixo:

Compilação:

Utilize o comando "make" ou "make all" para compilar o programa. Certifique-se de que o Makefile está configurado corretamente para compilar os arquivos main.c e huffman.c com as devidas dependências.

Execução:

Após a compilação bem-sucedida, execute o programa gerado com o comando "make run".

Contribuições para melhorias e correções são bem-vindas. Sinta-se à vontade para criar pull requests ou abrir issues no repositório do projeto.

Esse projeto demonstra a eficiência do Algoritmo de Huffman na compressão de dados e fornece uma aplicação prática e interativa para explorar essa técnica fundamental de ciência da computação.