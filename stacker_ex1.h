#include <iostream>
#include <stdlib.h>

using namespace std;

//ADS LEDA (17/12/2022) - PROJETO FINAL DA DISCIPLINA
//- DUPLA: Daniel Alves Freitas (PT3020037) | Eduardo Brandão Ferrari (PT3020312)

//EXERCÍCIO 1 - BIBLIOTECA) - SOLUÇÃO:

// STRUCTS DE BASE
struct Node {
  int number;
  struct Node *next;
};

struct Stack {
  struct Node *top;
  int max_items;
  int qty;
};

// FUNÇÃO - EXIBIR QUANTIDADE DE ELEMENTOS DA PILHA
int exibir_qtd(struct Stack *&pilha) { return pilha->qty; }

// FUNÇÃO - VERIFICA SE A PILHA ESTÁ CHEIA
int verifica_cheia(struct Stack *&pilha) {

  if (pilha->qty == pilha->max_items) {
    return 1;
  } else
    return 0;
}

// FUNÇÃO - VERIFICA SE A PILHA ESTÁ VAZIA
int verifica_vazia(struct Stack *&pilha) {

  if (pilha->qty == 0) {
    return 1;
  } else
    return 0;
}

// FUNÇÃO - BUSCA UM ELEMENTO NA PILHA
int buscar(struct Stack *&pilha, int num) {

  int count = 0;
  int achou = 0;
  struct Node *tmp = pilha->top;

  while (count < pilha->qty) {
    if (num == tmp->number) {
      achou = 1;
      break;
    }
    count++;
  }

  return achou;
}

// FUNÇÃO - EXIBE TODOS OS ELEMENTOS DA PILHA
void exibir_todos(struct Stack *&pilha) {

  int count = 0;
  struct Node *tmp = pilha->top;

  printf("\n- Todos os Elementos Armazenados na Pilha:");

  while (count < pilha->qty) {
    printf("\n- [%d]", tmp->number);
    tmp = tmp->next;

    count++;
  }
}

// FUNÇÃO - EMPILHA ELEMENTOS
void empilha(struct Stack *&pilha, int num) {

  if (pilha) {
    struct Node *novo = (struct Node *)calloc(1, sizeof(struct Node));

    novo->number = num;
    novo->next = pilha->top;
    pilha->top = novo;

    pilha->qty++;

    printf("\n- Valor empilhado!");
  }
}

// FUNÇÃO - DESEMPILHA ELEMENTOS
void desempilha(struct Stack *&pilha) {

  int retirado;

  if (pilha) {
    struct Node *tmp = pilha->top;

    if (tmp) {
      pilha->top = pilha->top->next;
      retirado = tmp->number;
      free(tmp);

      pilha->qty--;
    }

    printf("\n- Elemento Desempilhado! (Elemento: %d)", retirado);
  }
}