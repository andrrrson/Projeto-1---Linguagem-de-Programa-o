#include "SistemaDeGestao.h"
#include <iostream>
#include <algorithm>

SistemaDeGestao::~SistemaDeGestao() {
    for (auto& pair : astronautas) {
        delete pair.second;
    }
    for (auto& pair : voos) {
        delete pair.second;
    }
}

void SistemaDeGestao::cadastrarAstronauta(string cpf, string nome, int idade) {
    astronautas[cpf] = new Astronauta(cpf, nome, idade);
}

void SistemaDeGestao::cadastrarVoo(int codigo) {
    voos[codigo] = new Voo(codigo);
}

void SistemaDeGestao::adicionarAstronautaEmVoo(int codigoVoo, string cpf) {
    if (voos.find(codigoVoo) != voos.end() && astronautas.find(cpf) != astronautas.end()) {
        Voo* voo = voos[codigoVoo];
        Astronauta* astronauta = astronautas[cpf];
        if (voo->status == "planejado") {
            voo->adicionarPassageiro(astronauta);
        } else {
            cout << "Erro: Astronauta só pode ser adicionado se o voo estiver em planejamento." << endl;
        }
    } else {
        cout << "Erro: Voo ou astronauta não encontrado." << endl;
    }
}

void SistemaDeGestao::removerAstronautaDeVoo(int codigoVoo, string cpf) {
    if (voos.find(codigoVoo) != voos.end()) {
        Voo* voo = voos[codigoVoo];
        if (voo->status == "planejado") {
            voo->removerPassageiro(cpf);
        } else {
            cout << "Erro: Astronauta só pode ser removido se o voo estiver em planejamento." << endl;
        }
    } else {
        cout << "Erro: Voo não encontrado." << endl;
    }
}

void SistemaDeGestao::lancarVoo(int codigoVoo) {
    if (voos.find(codigoVoo) != voos.end()) {
        Voo* voo = voos[codigoVoo];
        if (voo->status == "planejado" && !voo->passageiros.empty() &&
            all_of(voo->passageiros.begin(), voo->passageiros.end(), [](Astronauta* a) { return a->disponivel == 1 && a->vivo == 1; })) {
            voo->status = "em curso";
            for (Astronauta* a : voo->passageiros) {
                a->disponivel = 0;
            }
        } else {
            cout << "Erro: O voo precisa ter pelo menos 1 astronauta disponível" << endl;
        }
    } else {
        cout << "Erro: Voo não encontrado." << endl;
    }
}

void SistemaDeGestao::explodirVoo(int codigoVoo) {
    if (voos.find(codigoVoo) != voos.end()) {
        Voo* voo = voos[codigoVoo];
        if (voo->status == "em curso") {
            voo->status = "finalizado";
            voo->sucesso = 0;
            for (Astronauta* a : voo->passageiros) {
                a->vivo = 0;
            }
        } else {
            cout << "Erro: Só é possível explodir um voo que esteja em curso." << endl;
        }
    } else {
        cout << "Erro: Voo não encontrado." << endl;
    }
}

void SistemaDeGestao::finalizarVooComSucesso(int codigoVoo) {
    if (voos.find(codigoVoo) != voos.end()) {
        Voo* voo = voos[codigoVoo];
        if (voo->status == "em curso") {
            voo->status = "finalizado";
            voo->sucesso = 1;
            for (Astronauta* a : voo->passageiros) {
                a->disponivel = 1;
            }
        } else {
            cout << "Erro: Só é possível finalizar com sucesso um voo que esteja em curso." << endl;
        }
    } else {
        cout << "Erro: Voo não encontrado." << endl;
        }
    }

void SistemaDeGestao::listarVoos() {
        cout << "Voos Planejados====>\n";
        for (auto& pair : voos) {
            Voo* voo = pair.second;
            if (voo->status == "planejado") {
                cout << "Voo " << voo->codigo << "\n";
                for (Astronauta* a : voo->passageiros) {
                    cout << "  " << a->cpf << " - " << a->nome << "\n";
                }
            }
        }

        cout << "Voos em Curso====>\n";
        for (auto& pair : voos) {
            Voo* voo = pair.second;
            if (voo->status == "em curso") {
                cout << "Voo " << voo->codigo << "\n";
                for (Astronauta* a : voo->passageiros) {
                    cout << "  " << a->cpf << " - " << a->nome << "\n";
                }
            }
        }

        cout << "Voos Finalizados====>\n";
        for (auto& pair : voos) {
            Voo* voo = pair.second;
            if (voo->status == "finalizado") {
                cout << "Voo " << voo->codigo << "\n";
                for (Astronauta* a : voo->passageiros) {
                    cout << "  " << a->cpf << " - " << a->nome << "\n";
                }
                cout << "  Sucesso: " << (voo->sucesso == 1 ? "Sim" : "Não") << "\n";
            }
        }
    }

void SistemaDeGestao::listarAstronautasMortos() {
    cout << "Astronautas Mortos:\n";
    for (auto& pair : astronautas) {
        Astronauta* a = pair.second;
        if (a->vivo == 0) {
            cout << a->cpf << " - " << a->nome << "\n";
            cout << "  Voos que participou:\n";
            for (auto& vooPair : voos) {
                Voo* voo = vooPair.second;
                if (find(voo->passageiros.begin(), voo->passageiros.end(), a) != voo->passageiros.end()) {
                    cout << "    Voo " << voo->codigo << " (" << voo->status << ")\n";
                }
            }
        }
    }
}