#include "historico.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>

// Construtor da classe Historico, inicializa o tamanho máximo e carrega as disciplinas do arquivo
Historico::Historico(unsigned int max_size, const std::string &nomeArquivo) : tamanhoMaximo(max_size)
{
    carregarDisciplinas(nomeArquivo);
}

// Função para carregar disciplinas de um arquivo
void Historico::carregarDisciplinas(const std::string &nomeArquivo)
{
    // Verifica se o arquivo foi aberto com sucesso
    std::ifstream arquivo(nomeArquivo);
    if (arquivo.is_open())
    {
        // Le o arquivo linha por linha, sendo que cada atributo eh separado por virgulas
        std::string linha;
        while (std::getline(arquivo, linha))
        {
            std::istringstream iss(linha);
            Disciplina disciplina;
            std::getline(iss, disciplina.nome, ',');
            std::string periodo, creditos, nota;
            std::getline(iss, periodo, ',');
            std::getline(iss, creditos, ',');
            std::getline(iss, nota, ',');
            disciplina.periodo = std::stod(periodo);
            disciplina.creditos = std::stoi(creditos);
            disciplina.nota = std::stod(nota);
            disciplinas.push_back(disciplina);
        }
        arquivo.close();
    }
    else
    {
        std::cerr << "Erro ao abrir o arquivo " << nomeArquivo << std::endl;
    }
}

// Função para salvar disciplinas em um arquivo
void Historico::salvarDisciplinas(const std::string &nomeArquivo) const
{
    std::ofstream arquivo(nomeArquivo);
    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo.is_open())
    {
        // Escreve os dados da disciplina no arquivo, colocando cada disciplina em uma linha e separando atributos por virgulas
        for (const auto &disciplina : disciplinas)
        {
            arquivo << disciplina.nome << "," << disciplina.periodo << ","
                    << disciplina.creditos << "," << disciplina.nota << "\n";
        }
        arquivo.close();
    }
}

// Sobrecarga do operador para adicionar uma disciplina ao histórico
int Historico::operator+=(const Disciplina &novaDisciplina)
{
    unsigned int index = 0;
    // Verifica se o histórico atingiu o tamanho máximo

    std::cout << disciplinas.size() << std::endl;
    std::cout << tamanhoMaximo << std::endl;

    if (disciplinas.size() >= tamanhoMaximo)
    {
        std::cerr << "Erro: Historico cheio." << std::endl;
        std::cout << std::endl;
        return -1;
    }

    for (const auto &disciplina : disciplinas)
    {
        // Verifica se a nova disciplina já existe
        if (disciplina == novaDisciplina)
        {
            std::cerr << "Erro: Disciplina ja existente." << std::endl;
            std::cout << std::endl;
            return -1;
        }

        // Verifica se a nova disciplina deve ser inserida antes da existente
        if (disciplina < novaDisciplina)
        {
            std::cout << "Disciplina adicionada." << std::endl;
            disciplinas.insert(disciplinas.begin() + index + 1, novaDisciplina);
            break;
        }

        if (index == disciplinas.size() - 1)
        {
            std::cout << "Disciplina adicionada." << std::endl;
            disciplinas.insert(disciplinas.begin() + index + 1, novaDisciplina);
            break;
        }
        index++;
    }

    return disciplinas.size() - 1;
}

// Sobrecarga do operador para adicionar uma lista de disciplinas ao usuário
int Historico::operator+=(const std::vector<Disciplina> &novasDisciplinas)
{
    // Verifica se o usuário atingiu o tamanho máximo
    if (disciplinas.size() + novasDisciplinas.size() > tamanhoMaximo)
    {
        std::cerr << "Erro: Historico cheio." << std::endl;
        std::cout << std::endl;
        return -1;
    }
    for (const auto &novaDisciplina : novasDisciplinas)
    {
        unsigned int index = 0;
        for (const auto &disciplina : disciplinas)
        {
            {
                // Verifica se a nova disciplina já existe
                if (disciplina == novaDisciplina)
                {
                    std::cerr << "Erro: Disciplina ja existente." << std::endl;
                    std::cout << std::endl;
                    return -1;
                }

                // Verifica se a nova disciplina deve ser inserida antes da existente
                if (disciplina < novaDisciplina)
                {
                    std::cout << "Disciplina adicionada." << std::endl;
                    disciplinas.insert(disciplinas.begin() + index + 1, novaDisciplina);
                    break;
                }
                if (index == disciplinas.size() - 1)
                {
                    std::cout << "Disciplina adicionada." << std::endl;
                    disciplinas.insert(disciplinas.begin() + index + 1, novaDisciplina);
                    break;
                }
                index++;
            }
        }
    }

    return disciplinas.size() - novasDisciplinas.size();
}

// Sobrecarga do operador -= para remover uma disciplina do usuário
int Historico::operator-=(const std::string &nomeDisciplina)
{
    int index = 0;

    // Remove a disciplina do usuário
    for (const auto &disciplina : disciplinas)
    {

        if (disciplina.nome == nomeDisciplina)
        {

            disciplinas.erase(disciplinas.begin() + index);
            std::cout << "Disciplina removida." << std::endl;
            std::cout << std::endl;
            return index;
        }
        index++;
    }

    std::cerr << "Erro: Disciplina nao encontrada." << std::endl;
    std::cout << std::endl;
    return -1;
}

// Sobrecarga do operador () para buscar disciplinas por período
std::vector<Disciplina> Historico::operator()(const double &periodo) const
{
    std::vector<Disciplina> resultado;
    for (const auto &disciplina : disciplinas)
    {
        if (disciplina.periodo == periodo)
        {
            resultado.push_back(disciplina);
        }
    }
    return resultado;
}

// Sobrecarga do operador [] para buscar e alterar a nota de uma disciplina
double &Historico::operator[](const std::string &nomeDisciplina)
{
    notaNaoEncontrada = -1.0;

    // Busca a disciplina
    auto it = std::find_if(disciplinas.begin(), disciplinas.end(),
                           [&nomeDisciplina](const Disciplina &disciplina)
                           { return disciplina.nome == nomeDisciplina; });

    // Verifica se a disciplina foi encontrada
    if (it != disciplinas.end())
    {
        // Altera a nota
        return it->nota;
    }
    else
    {
        return notaNaoEncontrada;
    }
}

// Sobrecarga do operador >> para calcular o CRA
void Historico::operator>>(double &cra) const
{
    double somaNotasPonderadas = 0.0;
    int somaCreditos = 0;

    for (const auto &disciplina : disciplinas)
    {
        somaNotasPonderadas += disciplina.nota * disciplina.creditos;
        somaCreditos += disciplina.creditos;
    }

    if (somaCreditos > 0)
    {
        cra = somaNotasPonderadas / somaCreditos;
    }
    else
    {
        cra = 0.0;
    }
}

// Sobrecarga do operador << para exibir o historico
std::ostream &operator<<(std::ostream &os, const Historico &historico)
{
    for (const auto &disciplina : historico.disciplinas)
    {
        os << disciplina << std::endl;
    }
    return os;
}
