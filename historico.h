#ifndef HISTORICO_H
#define HISTORICO_H

#include "disciplina.h"
#include <vector>
#include <ostream>

class Historico {
private:
    std::vector<Disciplina> disciplinas;
    unsigned int tamanhoMaximo;

public:
    Historico(int max);
    void adicionarDisciplina(const Disciplina& novaDisciplina);
    void mostrarHistorico() const;
    friend std::ostream& operator<<(std::ostream& os, const Historico& historico);
    
};

#endif