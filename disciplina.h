
#include <string>

#ifndef DISCIPLINA_H
#define DISCIPLINA_H

struct Disciplina {
    std::string nome;
    std::string periodoConclusao;
    int creditos;
    double notaFinal;
    void mostrarDisciplina() const;
    friend std::ostream& operator<<(std::ostream& os, const Disciplina& disciplina);
};

#endif