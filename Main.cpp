#include <iostream>
#include "SistemaDeGestao.h"

using namespace std;

int main() {
    SistemaDeGestao sistema;

    // Cadastro de astronautas
    int numAstronautas;
    cout << "Digite o número de astronautas: ";
    cin >> numAstronautas;

    for (int i = 1; i <= numAstronautas; ++i) {
        string cpf, nome;
        int idade;
        cout << "Digite o CPF do astronauta " << i << ": ";
        cin >> cpf;
        cin.ignore();
        cout << "Digite o nome do astronauta " << i << ": ";
        getline(cin, nome);
        cout << "Digite a idade do astronauta " << i << ": ";
        cin >> idade;
        cout << " - \n";
        sistema.cadastrarAstronauta(cpf, nome, idade);
    }

    // Cadastro de voos
    int numVoos;
    cout << "Digite o número de voos: ";
    cin >> numVoos;

    for (int i = 1; i <= numVoos; ++i) {
        int codigoVoo;
        cout << "Digite o código do voo " << i << ": ";
        cin >> codigoVoo;
        cout << " - \n";
        sistema.cadastrarVoo(codigoVoo);
    }

    // Opções
    int opcao;
    do {
        cout << "\nMenu de Operações:\n";
        cout << "1. Adicionar Astronauta em Voo\n";
        cout << "2. Remover Astronauta de Voo\n";
        cout << "3. Lançar Voo\n";
        cout << "4. Explodir Voo\n";
        cout << "5. Finalizar Voo com Sucesso\n";
        cout << "6. Listar Todos os Voos\n";
        cout << "7. Listar Astronautas Mortos\n";
        cout << "8. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        string cpf;
        int codigoVoo;

        switch (opcao) {
            case 1:
                cout << "Digite o código do voo: ";
                cin >> codigoVoo;
                cout << "Digite o CPF do astronauta: ";
                cin >> cpf;
                sistema.adicionarAstronautaEmVoo(codigoVoo, cpf);
                break;
            case 2:
                cout << "Digite o código do voo: ";
                cin >> codigoVoo;
                cout << "Digite o CPF do astronauta: ";
                cin >> cpf;
                sistema.removerAstronautaDeVoo(codigoVoo, cpf);
                break;
            case 3:
                cout << "Digite o código do voo a ser lançado: ";
                cin >> codigoVoo;
                sistema.lancarVoo(codigoVoo);
                break;
            case 4:
                cout << "Digite o código do voo a ser explodido: ";
                cin >> codigoVoo;
                sistema.explodirVoo(codigoVoo);
                break;
            case 5:
                cout << "Digite o código do voo a ser finalizado com sucesso: ";
                cin >> codigoVoo;
                sistema.finalizarVooComSucesso(codigoVoo);
                break;
            case 6:
                sistema.listarVoos();
                break;
            case 7:
                sistema.listarAstronautasMortos();
                break;
            case 8:
                cout << "Saindo...\n";
                break;
            default:
                cout << "Opção inválida! Tente novamente.\n";
        }
    } while (opcao != 8);

    return 0;
}
