#include "historico.h"
#include <iostream>

Historico::Historico(int max) : tamanhoMaximo(max) {}

void Historico::adicionarDisciplina(const Disciplina& novaDisciplina) {
    if (disciplinas.size() < tamanhoMaximo) {
        disciplinas.push_back(novaDisciplina);
        std::cout << "Disciplina adicionada com sucesso.\n";
    } else {
        std::cout << "Limite de disciplinas atingido.\n";
    }
}

void Historico::mostrarHistorico() const {
    for (const auto& disciplina : disciplinas) {
        std::cout << "Nome: " << disciplina.nome << std::endl;
        std::cout << "Período de Conclusão: " << disciplina.periodoConclusao << std::endl;
        std::cout << "Créditos: " << disciplina.creditos << std::endl;
        std::cout << "Nota Final: " << disciplina.notaFinal << std::endl;
        std::cout << "-----------------------------\n";
    }
}

std::ostream& operator<<(std::ostream& os, const Historico& historico) {
    for (const auto& disciplina : historico.disciplinas) {
        os << "Nome: " << disciplina.nome << std::endl;
        os << "Período de Conclusão: " << disciplina.periodoConclusao << std::endl;
        os << "Créditos: " << disciplina.creditos << std::endl;
        os << "Nota Final: " << disciplina.notaFinal << std::endl;
        os << "-----------------------------\n";
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, const Disciplina& disciplina) {
    os << "Nome: " << disciplina.nome << std::endl;
    os << "Período de Conclusão: " << disciplina.periodoConclusao << std::endl;
    os << "Créditos: " << disciplina.creditos << std::endl;
    os << "Nota Final: " << disciplina.notaFinal << std::endl;
    return os;
}

