#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <iostream>
#include <string>

struct Disciplina {
    std::string nome;
    double periodo;
    int creditos;
    double nota;

    bool operator<(const Disciplina& novaDisciplina) const;
    bool operator==(const Disciplina& novaDisciplina) const;
    
    friend std::istream& operator>>(std::istream& is, Disciplina& disciplina);
    friend std::ostream& operator<<(std::ostream& os, const Disciplina& disciplina);
};

#endif // DISCIPLINA_H