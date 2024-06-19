#include "historico.h"
#include <iostream>

#include "historico.h"

int main() {
    Historico historico(5); // Definindo um histórico com limite de 5 disciplinas

    Disciplina d1 = {"Matemática", "2023.1", 4, 9.5};
    Disciplina d2 = {"Física", "2023.1", 3, 8.0};

    historico.adicionarDisciplina(d1);
    historico.adicionarDisciplina(d2);

    std::cout << historico;


    return 0;
}