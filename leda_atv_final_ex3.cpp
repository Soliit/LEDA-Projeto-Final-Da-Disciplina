#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

// ADS LEDA (17/12/2022) - PROJETO FINAL DA DISCIPLINA
//- DUPLA: Daniel Alves Freitas (PT3020037) | Eduardo Brandão Ferrari
//(PT3020312)

// EXERCÍCIO 3) - SOLUÇÃO:

struct stack {
  int num[20];
  int qtd;
};

//FUNÇÃO - INICIALIZAR UMA PILHA
void init_pilha(struct stack *pilha) { memset(pilha, 0, sizeof(struct stack)); }

//FUNÇÃO - EMPILHAR NÚMEROS NA PILHA 1 E 2
void push_1_2(struct stack *pilha, int n) {

  if (pilha->qtd == 10) {
    cout << "\n- O número " << n << " não foi empilhado pois a pilha está cheia";
  }
  else {
    pilha->num[pilha->qtd++] = n;
  }
}

//FUNÇÃO - EMPILHAR NÚMEROS NA PILHA 3
void push_3(struct stack *pilha, int n){
  pilha->num[pilha->qtd++] = n;
}

//FUNÇÃO - EMPILHAR AS PILHAS 1 E 2 NA PILHA 3
void push_pilha_3(struct stack *pilhaFinal, struct stack *pilhaInicial){
    
  int i = 0;

    for(i = 0; i < pilhaInicial->qtd; i++){
      push_3(pilhaFinal, pilhaInicial->num[i]);
    }   
}

//FUNÇÃO - LISTAR OS NÚMEROS DA PILHA 1
void listar_1(struct stack *pilha) {

  int i = 0;

  if (!pilha->qtd) {
    cout << "\n- A pilha 1 está vazia!";
    return;
  }

  cout << "\n\n- Pilha 1:\n\n";

  for (i = pilha->qtd - 1; i >= 0; i--) {
    cout << "| - [ " << pilha->num[i] << " ]\n";
  }
}

//FUNÇÃO - LISTAR OS NÚMEROS DA PILHA 2
void listar_2(struct stack *pilha) {

  int i = 0;

  if (!pilha->qtd) {
    cout << "\n- A pilha 2 está vazia!";
    return;
  }

  cout << "\n\n- Pilha 2:\n\n";

  for (i = pilha->qtd - 1; i >= 0; i--) {
    cout << "| - [ " << pilha->num[i] << " ]\n";
  }
}

//FUNÇÃO - LISTAR OS NÚMEROS DA PILHA 3
void listar_3(struct stack *pilha) {

  int i = 0;

  if (!pilha->qtd) {
    cout << "\n- A pilha 3 está vazia!";
    return;
  }

  cout << "\n\n- Pilha 3:\n\n";

  for (i = pilha->qtd - 1; i >= 0; i--) {
    cout << "| - [ " << pilha->num[i] << " ]\n";
  }
}

//FUNÇÃO - ORGANIZAR AS PILHAS 1 E 2 EM ORDEM CRESCENTE
void sort_asc(struct stack *pilha) {

  int tmp = 0;
  int i = 0;
  int j = 0;

  for (i = 0; i < pilha->qtd; i++) {
    for (j = i + 1; j < pilha->qtd; j++) {
      if (pilha->num[i] < pilha->num[j]) {
        tmp = pilha->num[i];
        pilha->num[i] = pilha->num[j];
        pilha->num[j] = tmp;
      }
    }
  }
}

//FUNÇÃO - ORGANIZAR A PILHA 3 EM ORDEM DESCRESCENTE
void sort_dec(struct stack *pilha) {

  int tmp = 0;
  int i = 0;
  int j = 0;

  for (i = 0; i < pilha->qtd; i++) {
    for (j = i + 1; j < pilha->qtd; j++) {
      if (pilha->num[i] > pilha->num[j]) {
        tmp = pilha->num[i];
        pilha->num[i] = pilha->num[j];
        pilha->num[j] = tmp;
      }
    }
  }
}

//FUNÇÃO - MAIN
int main() {

  struct stack pilha_1;
  struct stack pilha_2;
  struct stack pilha_3;

  init_pilha(&pilha_1);
  init_pilha(&pilha_2);
  init_pilha(&pilha_3);

  push_1_2(&pilha_1, rand() % 100);
  push_1_2(&pilha_2, rand() % 100);
  
  push_1_2(&pilha_1, rand() % 100);
  push_1_2(&pilha_2, rand() % 100);
  
  push_1_2(&pilha_1, rand() % 100);
  push_1_2(&pilha_2, rand() % 100);
  
  push_1_2(&pilha_1, rand() % 100);
  push_1_2(&pilha_2, rand() % 100);
  
  push_1_2(&pilha_1, rand() % 100);
  push_1_2(&pilha_2, rand() % 100);
  
  push_1_2(&pilha_1, rand() % 100);
  push_1_2(&pilha_2, rand() % 100);
  
  push_1_2(&pilha_1, rand() % 100);
  push_1_2(&pilha_2, rand() % 100);
  
  push_1_2(&pilha_1, rand() % 100);
  push_1_2(&pilha_2, rand() % 100);
  
  push_1_2(&pilha_1, rand() % 100);
  push_1_2(&pilha_2, rand() % 100);
  
  push_1_2(&pilha_1, rand() % 100);
  push_1_2(&pilha_2, rand() % 100);

  sort_asc(&pilha_1);
  sort_asc(&pilha_2);

  listar_1(&pilha_1);
  listar_2(&pilha_2);

  push_pilha_3(&pilha_3, &pilha_1);
  push_pilha_3(&pilha_3, &pilha_2);

  sort_dec(&pilha_3);
  listar_3(&pilha_3);

  return 0;
}