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
    passageiros.erase(remove_if(passageiros.begin(), passageiros.end(),
                                [&cpf](Astronauta* a) { return a->cpf == cpf; }),
                      passageiros.end());
}
