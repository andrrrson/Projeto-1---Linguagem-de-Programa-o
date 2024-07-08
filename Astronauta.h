#ifndef ASTRONAUTA_H
#define ASTRONAUTA_H

#include <string>
using namespace std;

class Astronauta {
public:
    string cpf;
    string nome;
    int idade;
    int disponivel; // 1 ou 0
    int vivo; // 1 ou 0

    Astronauta(string cpf, string nome, int idade);
};

#endif
