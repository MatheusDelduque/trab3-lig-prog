#include <iostream>
#include <vector>
#include "historico.h"

int main()
{
    std::string nomeArquivo = "historico.txt";
    Historico historico(8, nomeArquivo); // Define um histórico com tamanho máximo de 10 disciplinas
    int opcao;

    do
    {
        std::cout << "Menu de Opções:" << std::endl;
        std::cout << "1. Mostrar todo o histórico" << std::endl;
        std::cout << "2. Adicionar uma disciplina" << std::endl;
        std::cout << "3. Adicionar um lote de disciplinas" << std::endl;
        std::cout << "4. Remover uma disciplina" << std::endl;
        std::cout << "5. Buscar disciplinas por período" << std::endl;
        std::cout << "6. Editar a nota de uma disciplina" << std::endl;
        std::cout << "7. Calcular CRA" << std::endl;
        std::cout << "8. Sair" << std::endl;
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;
        std::cout << std::endl;

        switch (opcao)
        {
        case 1:
            std::cout << "Histórico:" << std::endl;
            std::cout << std::endl;
            std::cout << historico;
            break;
        case 2:
        {
            Disciplina disciplina;
            std::cin >> disciplina;
            historico += disciplina;
            break;
        }
        case 3:
        {
            int quantidadeDisciplinas;
            std::cout << "Quantas disciplinas deseja adicionar? ";
            std::cin >> quantidadeDisciplinas;
            std::cout << std::endl;
            std::vector<Disciplina> listaDisciplinas;
            for (int i = 0; i < quantidadeDisciplinas; ++i)
            {
                Disciplina disciplina;
                std::cin >> disciplina;
                listaDisciplinas.push_back(disciplina);
            }
            historico += listaDisciplinas;
            break;
        }
        case 4:
        {
            std::string disciplina;
            std::cout << "Digite o nome da disciplina a ser removida: ";
            std::cin >> disciplina;
            std::cout << std::endl;
            historico -= disciplina;
            break;
        }
        case 5:
        {
            double periodo;
            std::cout << "Digite o período a ser buscado (ex: 2023.1): ";
            std::cin >> periodo;
            std::cout << std::endl;
            std::vector<Disciplina> resultado = historico(periodo);
            if (resultado.empty())
            {
                std::cout << "Nenhuma disciplina encontrada para o período " << periodo << std::endl;
                std::cout << std::endl;
            }
            else
            {
                std::cout << "Disciplinas do período " << periodo << ":" << std::endl;
                std::cout << std::endl;
                for (const auto &disciplina : resultado)
                {
                    std::cout << disciplina << std::endl;
                    std::cout << std::endl;
                }
            }
            break;
        }
        case 6:
        {
            std::string nome;
            double novaNota;
            std::cout << "Digite o nome da disciplina a ter a nota editada: ";
            std::cin >> nome;
            std::cout << std::endl;
            std::cout << "Digite a nova nota: ";
            std::cin >> novaNota;
            std::cout << std::endl;
            historico[nome] = novaNota;
            if (historico[nome] == -1)
            {
                std::cerr << "Erro: disciplina não encontrada." << std::endl;
                std::cout << std::endl;
            }
            break;
        }
        case 7:
        {
            double cra;
            historico >> cra;
            std::cout << "O CRA é: " << cra << std::endl;
            std::cout << std::endl;
            break;
        }
        case 8:
            std::cout << "Saindo..." << std::endl;
            std::cout << std::endl;
            historico.salvarDisciplinas(nomeArquivo);
            break;
        default:
            std::cout << "Opção inválida! Tente novamente." << std::endl;
            std::cout << std::endl;
            break;
        }

    } while (opcao != 8);

    return 0;
}
