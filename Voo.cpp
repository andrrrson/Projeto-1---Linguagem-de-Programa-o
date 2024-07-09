#include "Voo.h"
#include <algorithm>
#include <iostream>

Voo::Voo(int codigo) : codigo(codigo), status("planejado"), sucesso(0) {}

void Voo::adicionarPassageiro(Astronauta* astronauta) {
    if (astronauta->vivo == 1) {
        passageiros.push_back(astronauta);
    } else {
        cout << "Erro: Não é possível adicionar um astronauta morto ao voo." << endl;
    }
}

void Voo::removerPassageiro(const string& cpf) {
        for (auto it = passageiros.begin(); it != passageiros.end(); ++it) {
            if ((*it)->cpf == cpf) {
                passageiros.erase(it);
                break;
            }
        }
    }

