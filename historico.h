#ifndef HISTORICO_H
#define HISTORICO_H

#include <vector>
#include "disciplina.h"

class Historico
{
public:
    Historico(unsigned int max_size, const std::string &arquivo);
    void carregarDisciplinas(const std::string &nomeArquivo);
    void salvarDisciplinas(const std::string &nomeArquivo) const;

    int operator+=(const Disciplina &disciplina);
    int operator+=(const std::vector<Disciplina> &novasDisciplinas);
    int operator-=(const std::string &nomeDisciplina);
    std::vector<Disciplina> operator()(const double &periodo) const;
    double &operator[](const std::string &nomeDisciplina);
    void operator>>(double &cra) const;

    friend std::ostream &operator<<(std::ostream &os, const Historico &historico);

private:
    double notaNaoEncontrada;
    std::vector<Disciplina> disciplinas;
    unsigned int tamanhoMaximo;
};
#endif // HISTORICO_H