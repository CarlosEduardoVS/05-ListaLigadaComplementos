#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

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
	// se a lista ja possuir elementos
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
	NO* novo = (NO*)malloc(sizeof(NO));// aloca memoria dinamicamente para o novo elemento

	if (novo == NULL)
	{ /*identifica erro na alocacao de memoria*/
		return;
	}

	cout << "Digite o numero: ";
	cin >> novo->valor;
	novo->prox = NULL;


	NO* N1 = NULL;
	NO* Guardaoprimeiro = primeiro;


	NO* verificacao = posicaoElemento(novo->valor);
	if (verificacao == NULL)

	{

		while (Guardaoprimeiro != NULL && Guardaoprimeiro->valor < novo->valor)
		{
			N1 = Guardaoprimeiro;
			Guardaoprimeiro = Guardaoprimeiro->prox;
		}
		if (N1 == NULL)
		{
			novo->prox = primeiro;
			primeiro = novo;
		}
		else
		{
			N1->prox = novo;
			novo->prox = Guardaoprimeiro;
		}

		cout << "O numero foi adicionado." << endl;

	}

	else

	{

		cout << "Esse numero ja ta na lista." << endl;

	}



}

void excluirElemento()
{
	if (primeiro != NULL)
	{
		int numeroExcluir;
		cout << "Insira o elemento a ser excluido: ";
		cin >> numeroExcluir;

		NO* resultadoBusca = posicaoElemento(numeroExcluir);

		if (resultadoBusca == NULL)
		{
			cout << "Este numero nao existe na lista. \n";
		}
		else
		{
			if (resultadoBusca == primeiro)
			{
				primeiro = resultadoBusca->prox;
			}
			else
			{
				NO* ajuda = primeiro;
				while (ajuda->prox != resultadoBusca) {
					ajuda = ajuda->prox;
				}
				ajuda->prox = resultadoBusca->prox;
			}
			free(resultadoBusca);
			cout << "Excluido com sucesso. \n";
		}

	}
	else
	{
		cout << "Tem nada \n";
		return;
	}
}

void buscarElemento()
{

	if (primeiro != NULL)
	{
		int numeroBuscar;
		cout << "Digite um numero para a busca.\n";
		cin >> numeroBuscar;

		NO* resultadoBusca = posicaoElemento(numeroBuscar);

		if (resultadoBusca == NULL)
		{
			cout << "Este numero nao existe na lista.\n";
		}
		else
		{
			cout << "O Valor digitado foi encontrado: " << resultadoBusca->valor << "\n";
		}
	}
	else
	{
		cout << "Tem nada \n";
		return;
	}
}



// retorna um ponteiro para o elemento buscado
// ou NULL se o elemento não estiver na lista
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

