#include <stdlib.h>
#include <stdio.h>

// ADS LEDA (17/12/2022) - PROJETO FINAL DA DISCIPLINA
//- DUPLA: Daniel Alves Freitas (PT3020037) | Eduardo Brandão Ferrari (PT3020312)

// EXERCÍCIO 5) - SOLUÇÃO:

typedef struct noh {
  int dado;
  struct noh *prox;
} noh;

typedef struct fila {
  noh *inicio;
  noh *fim;
} fila;

typedef struct pilha {
  noh *topo;
  int qtd_elementos;
} pilha;

void exi_fila(fila *fila) {
  noh *ptr = fila->inicio;
  if (ptr == 0) {
    printf("Fila esta vazia\n");
  } else {
    while (ptr != 0) {
      printf("%d  ", ptr->dado);
      ptr = ptr->prox;
    }
  }
}

void exi_pilha(pilha *stack) {
  noh *ptr = stack->topo;
  while (ptr != 0) {
    printf("%d\n", ptr->dado);
    ptr = ptr->prox;
  }
}

void inicia_Pilha(pilha *stack) {stack->topo = 0;}

void push(int dado, pilha *stack) {
  noh *ptr;
  ptr = (struct noh *)calloc(1, sizeof(struct noh));

  if (ptr == 0) {
    printf("ERRO ALOCACAO");
  } else {
    ptr->dado = dado;
    ptr->prox = stack->topo;
    stack->topo = ptr;
    stack->qtd_elementos += 1;
  }
}

void inserir_fila(int dado, fila *f) {
  noh *ptr = (noh *)calloc(1, sizeof(struct noh));

  if (ptr == 0) {
    printf("ERRO ALOCACAO\n");
  } else {
    ptr->dado = dado;

    if (f->inicio == 0) {
      f->inicio = ptr;
    } else {
      f->fim->prox = ptr;
    }

    f->fim = ptr;
  }
}

int main(void) {

  pilha *STACK;
  STACK = (struct pilha *)calloc(1, sizeof(struct pilha));

  inicia_Pilha(STACK);

  fila *FILA_IMPAR;
  FILA_IMPAR = (struct fila *)calloc(1, sizeof(struct fila));

  fila *FILA_PAR;
  FILA_PAR = (struct fila *)calloc(1, sizeof(struct fila));

  int dado;

  while (1) {
    printf("Coloque um inteiro ou 0 para sair do programa: ");
    scanf("%d", &dado);
    if (dado > 0){
      push(dado, STACK);
      system("clear || cls");
      printf("\n");
      printf("Item colocado no programa com exito\n");
      printf("\n\n");

      if (dado % 2 == 0){
        inserir_fila(dado, FILA_PAR);
      }
      else {
        inserir_fila(dado, FILA_IMPAR);
      }
     } 
      else {
        printf("\nPilha inserida\n");
        exi_pilha(STACK);

        printf("\n\nFila Par\n");
        exi_fila(FILA_PAR);

        printf("\n\nFila Impar\n");
        exi_fila(FILA_IMPAR);

        break;
     }
  }
  return 0;
}
