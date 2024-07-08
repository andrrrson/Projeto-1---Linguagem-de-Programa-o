#ifndef VOO_H
#define VOO_H

#include <vector>
#include <string>
#include "Astronauta.h"

class Voo {
public:
    int codigo;
    vector<Astronauta*> passageiros;
    string status; // "planejado", "em curso", "finalizado"
    int sucesso; // 1 ou 0

    Voo(int codigo);

    void adicionarPassageiro(Astronauta* astronauta);
    void removerPassageiro(const string& cpf);
};

#endif
