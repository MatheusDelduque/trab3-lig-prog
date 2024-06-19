#include "disciplina.h"

#include <iostream>

void Disciplina::mostrarDisciplina() const
{
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Período de Conclusão: " << periodoConclusao << std::endl;
    std::cout << "Créditos: " << creditos << std::endl;
    std::cout << "Nota Final: " << notaFinal << std::endl;
    std::cout << "-----------------------------\n";
    return;
}