# LEDA-Projeto-Final-Da-Disciplina
Projeto Final de LEDA (IFSP) - Resolução dos exercícios propostos no formato de programas C++. E demais informações sobre o desenvolvimento, ideias adotadas, instruções e contribuições da dupla.

# Como faço para compilar e testar esses códigos?
- 1° Alternativa:

Instale o compilador "MinGW-w64" em seu computador, baixe os arquivos dos códgos que deseja usar, abra um terminal, execute o comando gcc "caminho_do_arquivo" -o "nome_do_arquivo". Após isso execute o arquivo final criado pelo terminal da sua máquina, ou até mesmo no terminal de algum outro programa, como o do VScode.

- 2° Alternativa

Copie os códigos e os repasse para um compilador online (Você só poderá executá-los um por um, não cole todos os códigos no mesmo trecho de texto). Seguindo, compile e rode o código ao apertar o botão "Run".

Compiladores Online:
- https://replit.com/
- https://www.programiz.com/cpp-programming/online-compiler/ (Mais prático para C e C++)

# Exercicio 1 - stackers_ex1.h
- Descrição: 

Escreva uma biblioteca que implemente uma solução do tipo pilha para as seguintes estruturas:
...

Em seguida, implemente métodos para:
- Retornar a quantidade de elementos contidos na pilha
- Verificar se a pilha está cheia
- Verificar se a pilha está vazia
- Verificar se um elemento está presente na pilha
- Exibir os elementos presentes na pilha
- Empilhar (inserir) um novo elemento na pilha
- Desempilhar (retirar) um elemento da pilha

# Exercicio 2 - solucao_ex2.h
- Descrição:

Escreva uma biblioteca que implemente uma solução do tipo fila para as seguintes estruturas:
...

Em seguida, implemente métodos para:
- Retornar a quantidade de elementos contidos na fila
- Verificar se a fila está cheia
- Verificar se a fila  está vazia
- Verificar se um elemento está presente na fila
- Exibir os elementos presentes na fila
- Inserir um elemento na fila
- Retirar um elemento da fila

# Exercicio 3 - leda_projeto_final_ex3.cpp
- Descrição:

Escreva um programa que crie duas pilhas sequenciais numéricas ordenadas crescentemente a partir do topo. Transfira os elementos dessas pilhas para uma terceira pilha, inicialmente vazia, de modo que ela fique ordenada decrescentemente com o maior valor no topo.

# Exercicio 4 - leda_projeto_final_ex4.cpp
- Descrição:

Escreva uma função que receba três filas, duas já preenchidas em ordem crescente e preencha a última com os valores das duas primeiras em ordem crescente

# Exercicio 5 - leda_projeto_final_ex5.c
- Descrição:

Escreva um programa que cadastre em uma pilha vários números. A entrada deles será finalizada com a digitação de um número menor ou igual a 0 (zero). Posteriormente, o programa deve gerar duas filas, a primeira com números pares e a segunda com os números ímpares. A saída do programa deve apresentar a pilha digitada e as filas geradas. Caso alguma das filas seja vazia, deve-se mostrar uma mensagem.

# Exercicio 6 - leda_projeto_final_ex6.cpp
- Descrição:

Projeto 01: Adega de vinhos

Imagine um colecionador de vinhos que compra vinhos recentes e os guarda em uma adega para envelhecerem, e que cada ocasião especial abre sempre a sua última aquisição (para poupar os mais antigos). Construa um programa que:

- Permita incluir novos vinhos na adega;
- Informe qual vinho deve ser aberto sem uma ocasião especial, retirando da adega o vinho adicionado mais antigamente (independentemente de sua safra);
- Permite criar estruturas para o armazenamento de vinhos para ocasiões especiais;
- Informe qual vinho deve ser aberto em uma ocasião especial;
- Relacione as cinco aquisições mais antigas;
- Relacione as cinco aquisições mais recentes.
- As informações básicas que o registro de vinhos deve conter são: nome do produto, país de origem, tipo de uva e safra.
