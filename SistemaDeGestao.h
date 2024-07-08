#ifndef SISTEMA_DE_GESTAO_H
#define SISTEMA_DE_GESTAO_H

#include <map>
#include <string>
#include "Astronauta.h"
#include "Voo.h"

class SistemaDeGestao {
private:
    map<string, Astronauta*> astronautas;
    map<int, Voo*> voos;

public:
    ~SistemaDeGestao();

    void cadastrarAstronauta(string cpf, string nome, int idade);
    void cadastrarVoo(int codigo);
    void adicionarAstronautaEmVoo(int codigoVoo, string cpf);
    void removerAstronautaDeVoo(int codigoVoo, string cpf);
    void lancarVoo(int codigoVoo);
    void explodirVoo(int codigoVoo);
    void finalizarVooComSucesso(int codigoVoo);
    void listarVoos();
    void listarAstronautasMortos();
};

#endif
