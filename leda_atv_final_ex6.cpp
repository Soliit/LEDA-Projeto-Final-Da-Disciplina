#include <iostream>
#include <string>

using namespace std;

// ADS LEDA (17/12/2022) - PROJETO FINAL DA DISCIPLINA
//- DUPLA: Daniel Alves Freitas (PT3020037) | Eduardo Brandão Ferrari
//(PT3020312)

// EXERCÍCIO 6 - DESAFIO) - SOLUÇÃO:

// STRUCT - ARMAZENA OS DADOS DO VINHO
struct vinhos {
  string nome_vinho;
  string pais_origem;
  string especie_uva;
  string safra;
};

// STRUCT - ARMAZENA OS DADOS DO VINHO DE OCASIÃO ESPECIAL
struct vinhos_esp {
  string nome_vinho;
  string pais_origem;
  string especie_uva;
  string safra;
};

// STRUCT - ARMAZENA O NÓ DO VINHO NA FILA
struct Noh_vinho {
  vinhos *vinho;
  Noh_vinho *proximo;
};

// STRUCT - ARMAZENA O NÓ DO VINHO DE OCASIÃO ESPECIAL NA FILA
struct Noh_vinho_esp {
  vinhos_esp *vinho;
  Noh_vinho_esp *proximo;
};

// FUNÇÃO - VERIFICA SE A FILA ESTÁ VAZIA
int esta_vazia(Noh_vinho *&inicio) {
  if (inicio == NULL) {
    cout << "\n- A adega está vazia!";
    return 1;
  } else {
    return 0;
  }
}

// FUNÇÃO - VERIFICA SE A FILA POSSUI AO MENOS 5 NÓS
int possui_cinco(int qtd) {
  if (qtd < 5) {
    cout << "\n- A adega não possui 5 ou mais vinhos!";
    return 1;
  } else {
    return 0;
  }
}

// FUNÇÃO - ADICIONA OS DADOS DE UM NOVO VINHO À FILA
void enfileirar(Noh_vinho *&inicio, Noh_vinho *&fim, string vinho,
                string origem, string uva, string safra) {

  vinhos *dados_vinho = (vinhos *)calloc(1, sizeof(vinhos));
  Noh_vinho *novo = (Noh_vinho *)calloc(1, sizeof(Noh_vinho));

  dados_vinho->nome_vinho = vinho;
  dados_vinho->pais_origem = origem;
  dados_vinho->especie_uva = uva;
  dados_vinho->safra = safra;

  novo->vinho = dados_vinho;

  novo->proximo = NULL;
  if (inicio == NULL) {
    inicio = novo;
    fim = novo;
  } else {
    fim->proximo = novo;
    fim = novo;
  }

  cout << "\n- Vinho Guardado!";
}

// FUNÇÃO - RETIRA E INFORMA O VINHO MAIS ANTIGO DA FILA
string desenfileirar(Noh_vinho *&inicio, Noh_vinho *&fim) {

  string vinho_retirado;

  Noh_vinho *aux = inicio;
  vinho_retirado = inicio->vinho->nome_vinho;
  inicio = inicio->proximo;
  free(aux);

  return vinho_retirado;
}

// FUNÇÃO - LISTA TODOS OS VINHOS JÁ COLOCADOS NA ADEGA
void listar(Noh_vinho *&inicio) {

  Noh_vinho *tmp = (Noh_vinho *)calloc(1, sizeof(Noh_vinho));

  tmp = inicio;

  cout << "\n- Listagem de todos os Vinhos";

  while (tmp != NULL) {
    cout << "\n____________________________________";
    cout << "\n| Nome: "           << tmp->vinho->nome_vinho;
    cout << "\n| País de Origem: " << tmp->vinho->pais_origem;
    cout << "\n| Espécie de Uva: " << tmp->vinho->especie_uva;
    cout << "\n| Safra: "          << tmp->vinho->safra;
    tmp = tmp->proximo;
  }
}

// FUNÇÃO - LISTA OS 5 VINHOS MAIS ANTIGOS DA ADEGA
void listar_mais_antigos(Noh_vinho *&inicio) {

  Noh_vinho *tmp = (Noh_vinho *)calloc(1, sizeof(Noh_vinho));

  tmp = inicio;
  int count = 0;

  cout << "\n- Listagem dos cinco vinhos mais antigos:";

  cout << "\n\n------------------------------------";
  cout << "\n| - Aquisição Mais Antiga: ▼";

  while (tmp != NULL && count < 5) {
    cout << "\n____________________________________";
    cout << "\n| Nome: "           << tmp->vinho->nome_vinho;
    cout << "\n| País de Origem: " << tmp->vinho->pais_origem;
    cout << "\n| Espécie de Uva: " << tmp->vinho->especie_uva;
    cout << "\n| Safra: "          << tmp->vinho->safra;
    tmp = tmp->proximo;

    count += 1;
  }
}

// FUNÇÃO - LISTA OS 5 VINHOS MAIS NOVOS DA ADEGA
void listar_mais_novos(Noh_vinho *&inicio, int qtd) {

  Noh_vinho *tmp = (Noh_vinho *)calloc(1, sizeof(Noh_vinho));

  tmp = inicio;
  int i_ultimos_cinco, count = 0;

  i_ultimos_cinco = qtd - 5;

  cout << "\n- Listagem dos cinco vinhos mais novos:";

  while (tmp != NULL && count < qtd) {
    if (count >= i_ultimos_cinco) {
      cout << "\n____________________________________";
      cout << "\n| Nome: "           <<  tmp->vinho->nome_vinho;
      cout << "\n| País de Origem: " << tmp->vinho->pais_origem;
      cout << "\n| Espécie de Uva: " << tmp->vinho->especie_uva;
      cout << "\n| Safra: "          << tmp->vinho->safra;
    } else {
      count += 1;
    }
    tmp = tmp->proximo;
  }

  cout << "\n------------------------------------";
  cout << "\n| - Aquisição Mais Nova: ▲";
  cout << "\n------------------------------------";
}

// FUNÇÃO - MARCA E INFORMA O VINHO NA FILA COMO RETIRADO EM UMA OCASIÃO
// ESPECIAL
string desinfileirar_ocasiao(Noh_vinho *&inicio, Noh_vinho *&fim) {

  string nome_vinho_retirado;

  if (inicio == NULL) {
    printf("\nAdega Vazia!");
  } else {
    fim->vinho->nome_vinho = fim->vinho->nome_vinho + (" (Ocasião Especial)");
    nome_vinho_retirado = fim->vinho->nome_vinho;
    cout << "\n- Vinho Aberto: " << nome_vinho_retirado;
  }

  return nome_vinho_retirado;
}

// FUNÇÃO - ADICIONA OS DADOS DE UM VINHO DE OCASIÃO ESPECIAL A OUTRA FILA
void enfileirar_ocasiao(Noh_vinho_esp *&inicio, Noh_vinho_esp *&fim,
                        string nome_vinho_esp) {

  vinhos_esp *dados_vinho = (vinhos_esp *)calloc(1, sizeof(vinhos_esp));
  Noh_vinho_esp *novo = (Noh_vinho_esp *)calloc(1, sizeof(Noh_vinho_esp));

  dados_vinho->nome_vinho = nome_vinho_esp;

  novo->vinho = dados_vinho;

  novo->proximo = NULL;
  if (inicio == NULL) {
    inicio = novo;
    fim = novo;
  } else {
    fim->proximo = novo;
    fim = novo;
  }
}

// FUNÇÃO - MAIN
int main() {

  Noh_vinho *inicio = NULL;
  Noh_vinho *fim = NULL;

  Noh_vinho_esp *inicio_esp = NULL;
  Noh_vinho_esp *fim_esp = NULL;

  string vinho, origem, uva, safra;
  string vinho_removido;

  Noh_vinho_esp *tmp_esp;

  int op, ask, qtd = 0;

  while (op != 0) {
    cout << "\n\n____________________________________\n"
            "|_______________ADEGA________|- □ x|\n"
            "|⚬[1] - Guardar um vinho novo     ||\n"
            "|⚬[2] - Abrir um vinho            ||\n"
            "|⚬[3] - Listar todos os vinhos    ||\n"
            "|⚬[4] - 5 Aquisições mais antigas ||\n"
            "|⚬[5] - 5 Aquisições mais novas   ||\n"
            "------------------------------------\n\n";

    cout << "- Escolha uma operação: ";
    cin >> op;

    switch (op) {
    //----------------------------------------------------------------//
    case 1:
      cout << "\n- Digite o nome do vinho a ser guardado: ";
      cin >> vinho;
      cout << "- Digite o país de origem: ";
      cin >> origem;
      cout << "- Digite o nome da espécie de uva: ";
      cin >> uva;
      cout << "- Digite o ano da safra: ";
      cin >> safra;

      enfileirar(inicio, fim, vinho, origem, uva, safra);

      qtd += 1;
      break;
    //----------------------------------------------------------------//
    case 2:
      if (esta_vazia(inicio) == 1) {
        break;
      } else {
        cout << "\n- É uma ocasião especial? [1] Sim | [0] Não: ";
        cin >> ask;

        if (ask == 1) {
          vinho_removido = desinfileirar_ocasiao(inicio, fim);
          enfileirar_ocasiao(inicio_esp, fim_esp, vinho_removido);
        }
        if (ask == 0) {
          cout << "\nVinho Aberto: " << desenfileirar(inicio, fim);
          qtd -= 1;
        }
      }
      break;
    //----------------------------------------------------------------//
    case 3:
      if (esta_vazia(inicio) == 1)
        break;
      else
        listar(inicio);
      break;
    case 4:
      if (esta_vazia(inicio) == 1) {
        break;
      } else {
        if (possui_cinco(qtd) == 1) {
          break;
        } else {
          listar_mais_antigos(inicio);
        }
      }
      break;
    //----------------------------------------------------------------//
    case 5:
      if (esta_vazia(inicio) == 1) {
        break;
      } else {
        if (possui_cinco(qtd) == 1) {
          break;
        } else {
          listar_mais_novos(inicio, qtd);
        }
      }
      break;
    //----------------------------------------------------------------//
    default:
      printf("\n- Opção Inválida!");
      break;
    }
  }
}
