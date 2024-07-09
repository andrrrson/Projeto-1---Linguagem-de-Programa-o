#include "Astronauta.h"

Astronauta::Astronauta(string cpf, string nome, int idade) {
        this->cpf = cpf;
        this->nome = nome;
        this->idade = idade;
        this->disponivel = 1;
        this->vivo = 1;
    }
};