#include <iostream>

using namespace std;

//ADS LEDA (17/12/2022) - PROJETO FINAL DA DISCIPLINA
//- DUPLA: Daniel Alves Freitas (PT3020037) | Eduardo Brandão Ferrari (PT3020312)

//EXERCÍCIO 1) - SOLUÇÃO:

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

//FUNÇÃO MAIN
int main() {

  int ask, teste, num;
  struct Stack *p;
  bool pilha_nao_vazia = false;

  p->max_items = 5;
  p->qty = 0;

  while (ask != 0) {
    printf("\n\n__________________________________________________________\n"
               "|________________________M_E_N_U___________________|- □ x|\n"
               "| [1] - Retornar a quantidade de elementos              ||\n"
               "| [2] - Verificar se a pilha está cheia                 ||\n"
               "| [3] - Verificar se a pilha está vazia                 ||\n"
               "| [4] - Verificar se um elemento está presente na pilha ||\n"
               "| [5] - Exibir os elementos presentes na pilha          ||\n"
               "| [6] - Empilhar (inserir) um novo elemento na pilha    ||\n"
               "| [7] - Desempilhar (retirar) um elemento da pilha      ||\n"
               "|                                                       ||\n"
               "| [0] - Sair                                            ||\n"
               "----------------------------------------------------------\n\n");

    printf("- Escolha uma operação: ");
    scanf("%d", &ask);

    switch (ask) {
    //------------------------------------------------------------------//
    case 0:
      printf("\n- Operações Finalizadas!");
      break;
    //------------------------------------------------------------------//
    case 1:
      printf("\n- Quantidade de elementos: %d", exibir_qtd(p));
      break;
    //------------------------------------------------------------------//
    case 2:
      if (verifica_cheia(p) == 0)
        printf("\n- A pilha NÃO está cheia!");
      else
        printf("\n- A pilha está cheia!");
      break;
    //------------------------------------------------------------------//
    case 3:
      if (verifica_vazia(p) == 0)
        printf("\n- A pilha NÃO está vazia!");
      else
        printf("\n- A pilha está vazia!");
      break;
    //------------------------------------------------------------------//
    case 4:
      if (verifica_vazia(p) == 1) {
        printf("\n- A pilha está vazia!");
      } else {
        printf("\n- Digite N a ser buscado: ");
        scanf("%d", &num);

        if (buscar(p, num) == 0)
          printf("\n- Elemento NÃO encontrado!");
        else
          printf("\n- Encontrado! Este elemento está presente na pilha!");
      }
      break;
    //------------------------------------------------------------------//
    case 5:
      if (verifica_vazia(p) == 1) {
        printf("\n- A pilha está vazia!");
      } else
        exibir_todos(p);
      break;
    //------------------------------------------------------------------//
    case 6:
      if (verifica_cheia(p) == 1) {
        printf("\n- A pilha está cheia! Desempilhe primeiro");
      } else {
        printf("\n- Digite N a ser empilhado: ");
        scanf("%d", &num);
        empilha(p, num);
      }
      break;
    //------------------------------------------------------------------//
    case 7:
      if (verifica_vazia(p) == 1) {
        printf("\n- A pilha está vazia!");
      } else {
        desempilha(p);
      }
      break;
    //------------------------------------------------------------------//
    }
  }

  return 0;
}
