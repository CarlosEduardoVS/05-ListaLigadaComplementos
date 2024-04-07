#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;
NO* N = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------

int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista j� possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite um numero: ";
	cin >> novo->valor;
	novo->prox = NULL;

	NO* verificacao = posicaoElemento(novo->valor);

	if (verificacao == NULL)
	{
		if (primeiro == NULL)
		{
			primeiro = novo;
			N = novo;
		}
		else
		{
			N->prox = novo;
			N = novo;
		}
		cout << "Inserido com sucesso.\n";
	}
	else
	{
		cout << "Esse numero ja ta na lista.\n";
	}


}

void excluirElemento()
{
	if (primeiro == NULL) {
		cout << "Tem nada.\n";
	}
	else {
		int Vaisair;
		cout << "Digite o numero para busca.\n: ";
		cin >> Vaisair;

		NO* busca = posicaoElemento(Vaisair);

		if (busca == NULL) {
			cout << "O numero nao esta na lista";
		}
		else {
			if (busca == primeiro) {
				primeiro = busca->prox;

			}
			else {
				NO* aux = primeiro;
				while (aux->prox != busca) {
					aux = aux->prox;
				}
				aux->prox = busca->prox;
			}
			cout << "O numero foi excluido.\n";
		}
		free(busca);


	}

}

void buscarElemento()
{
	if (primeiro == NULL) {
		cout << "Tem nada.\n";
	}
	else {
		int Numerobuscar;
		cout << "Digite o elemento a ser buscado: ";
		cin >> Numerobuscar;
		NO* numero = posicaoElemento(Numerobuscar);

		if (numero == NULL) {
			cout << "O numero nao faz parte da lista.\n";
		}
		else {
			cout << "Esse e o numero que foi buscado: " << numero->valor;
		}
	}
}

NO* posicaoElemento(int numero)
{
	NO* aux = primeiro;
	while (aux != NULL) {
		if (aux->valor == numero)
		{
			break;
		}
		aux = aux->prox;
	}
	return aux;
}