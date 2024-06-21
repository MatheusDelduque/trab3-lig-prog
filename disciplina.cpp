#include "disciplina.h"

// Sobrecarga de operador para comparar o nome e o período de duas disciplinas
bool Disciplina::operator<(const Disciplina &novaDisciplina) const
{
    if (periodo != novaDisciplina.periodo)
        return novaDisciplina.periodo < periodo;

    return nome < novaDisciplina.nome;
}

// Sobrecarga de operador para comparar o nome de duas disciplinas
bool Disciplina::operator==(const Disciplina &novaDisciplina) const
{
    return nome == novaDisciplina.nome;
}

// Operador para inserir uma disciplina
std::istream &operator>>(std::istream &is, Disciplina &disciplina)
{
    std::cout << "Digite o nome da disciplina: ";
    is >> disciplina.nome;
    std::cout << "Digite o período de conclusão (ex: 2023.1): ";
    is >> disciplina.periodo;
    std::cout << "Digite o número de créditos: ";
    is >> disciplina.creditos;
    std::cout << "Digite a nota final: ";
    is >> disciplina.nota;
    std::cout << std::endl;
    return is;
}

// Sobrecarga de operador para exibir uma disciplina
std::ostream &operator<<(std::ostream &os, const Disciplina &disciplina)
{
    os << "Disciplina: " << disciplina.nome << std::endl
       << "Período: " << disciplina.periodo << std::endl
       << "Créditos: " << disciplina.creditos << std::endl
       << "Nota: " << disciplina.nota << std::endl;
    return os;
}