#ifndef DOMINIOS_HPP_INCLUDED
#define DOMINIOS_HPP_INCLUDED

#include <string>
#include <stdexcept>
#include <cctype>

using namespace std;

/**
 * @class Numero
 * @brief Representa um número de quarto entre 001 e 999.
 *
 * @details O número deve estar no intervalo de 1 a 999.
 */
class Numero {
    private:
        int valor;

        /**
         * @brief Valida o número de quarto.
         * @param valor Inteiro a ser validado.
         * @throws invalid_argument se o valor não estiver entre 1 e 999.
         */
        void validar(int valor);

    public:
        /**
         * @brief Construtor padrão. Inicializa com valor 1.
         */
        Numero();

        /**
         * @brief Construtor parametrizado.
         * @param valor Valor inicial do número (1-999).
         */
        Numero(int valor);

        /**
         * @brief Destrutor.
         */
        ~Numero();

        /**
         * @brief Define um novo valor para o número.
         * @param novoValor Novo valor a ser atribuído.
         */
        void setValor(int novoValor);

        /**
         * @brief Retorna o valor do número.
         * @return Valor inteiro do número.
         */
        int getValor() const { return valor; }
};

/**
 * @class Senha
 * @brief Representa uma senha de 5 caracteres com requisitos específicos.
 *
 * @details A senha deve conter exatamente 5 caracteres com:
 * - Pelo menos uma letra maiúscula
 * - Pelo menos uma letra minúscula
 * - Pelo menos um dígito
 * - Pelo menos um caractere especial (!\"#$%&?)
 * - Letras não podem ser seguidas por letras
 * - Dígitos não podem ser seguidos por dígitos
 */
class Senha {
    private:
        string valor;

        /**
         * @brief Valida a senha segundo as regras especificadas.
         * @param valor String a ser validada.
         * @throws invalid_argument se a senha não atender aos requisitos.
         */
        void validar(string valor);

    public:
        /**
         * @brief Construtor padrão. Inicializa com string vazia.
         */
        Senha();

        /**
         * @brief Construtor parametrizado.
         * @param valor Senha inicial.
         */
        Senha(string valor);

        /**
         * @brief Destrutor.
         */
        ~Senha();

        /**
         * @brief Define uma nova senha.
         * @param novoValor Nova senha a ser atribuída.
         */
        void setValor(string novoValor);

        /**
         * @brief Retorna a senha.
         * @return String contendo a senha.
         */
        string getValor() const { return valor; }
};

/**
 * @class Endereco
 * @brief Representa um endereço com 5 a 30 caracteres.
 *
 * @details O endereço deve:
 * - Conter entre 5 e 30 caracteres
 * - Usar apenas letras, dígitos e caracteres especiais (., , espaço)
 * - Não começar ou terminar com caracteres especiais
 * - Seguir regras específicas de sequência
 */
class Endereco {
    private:
        string valor;

        /**
         * @brief Valida o endereço segundo as regras especificadas.
         * @param valor String a ser validada.
         * @throws invalid_argument se o endereço não for válido.
         */
        void validar(string valor);

    public:
        /**
         * @brief Construtor padrão. Inicializa com string vazia.
         */
        Endereco();

        /**
         * @brief Construtor parametrizado.
         * @param valor Endereço inicial.
         */
        Endereco(string valor);

        /**
         * @brief Destrutor.
         */
        ~Endereco();

        /**
         * @brief Define um novo endereço.
         * @param novoValor Novo endereço a ser atribuído.
         */
        void setValor(string novoValor);

        /**
         * @brief Retorna o endereço.
         * @return String contendo o endereço.
         */
        string getValor() const { return valor; }
};

/**
 * @class Dinheiro
 * @brief Representa um valor monetário entre 0,01 e 1.000.000,00.
 *
 * @details O valor é armazenado internamente em centavos (inteiro) e
 * formatado com pontos de milhar e vírgula decimal na saída.
 * Formato de entrada: "1.234.567,89"
 */
class Dinheiro {
    private:
        int valor; // Valor em centavos

        /**
         * @brief Valida o formato e valor monetário.
         * @param valor String no formato brasileiro (pontos de milhar, vírgula decimal).
         * @throws invalid_argument se o formato ou valor for inválido.
         */
        void validar(string valor);

    public:
        /**
         * @brief Construtor padrão. Inicializa com 0,01.
         */
        Dinheiro();

        /**
         * @brief Construtor parametrizado.
         * @param valor Valor monetário no formato string.
         */
        Dinheiro(string valor);

        /**
         * @brief Destrutor.
         */
        ~Dinheiro();

        /**
         * @brief Define um novo valor monetário.
         * @param novoValor Novo valor em formato string.
         */
        void setValor(string novoValor);

        /**
         * @brief Retorna o valor monetário formatado.
         * @return String no formato brasileiro (ex: "1.234,56").
         */
        string getValor() const;
};

/**
 * @class Cartao
 * @brief Representa um número de cartão de crédito de 16 dígitos.
 *
 * @details O número do cartão deve:
 * - Conter exatamente 16 dígitos
 * - Passar na validação do Algoritmo de Luhn
 */
class Cartao {
    private:
        string valor;

        /**
         * @brief Valida o número do cartão usando o Algoritmo de Luhn.
         * @param valor String com 16 dígitos.
         * @throws invalid_argument se o número for inválido.
         */
        void validar(string valor);

    public:
        /**
         * @brief Construtor padrão. Inicializa com string vazia.
         */
        Cartao();

        /**
         * @brief Construtor parametrizado.
         * @param valor Número do cartão.
         */
        Cartao(string valor);

        /**
         * @brief Destrutor.
         */
        ~Cartao();

        /**
         * @brief Define um novo número de cartão.
         * @param valor Novo número do cartão.
         */
        void setValor(string valor);

        /**
         * @brief Retorna o número do cartão.
         * @return String com 16 dígitos.
         */
        string getValor() const { return valor; }
};

/**
 * @class Nome
 * @brief Representa um nome de pessoa com 5 a 20 caracteres.
 *
 * @details O nome deve:
 * - Conter entre 5 e 20 caracteres
 * - Começar com letra maiúscula
 * - Cada termo deve começar com letra maiúscula após espaço
 * - Não terminar com espaço
 * - Conter apenas letras e espaços
 */
class Nome {
    private:
        string valor;

        /**
         * @brief Valida o nome segundo as regras especificadas.
         * @param valor String a ser validada.
         * @throws invalid_argument se o nome não for válido.
         */
        void validar(string valor);

    public:
        /**
         * @brief Construtor padrão. Inicializa com string vazia.
         */
        Nome();

        /**
         * @brief Construtor parametrizado.
         * @param valor Nome inicial.
         */
        Nome(string valor);

        /**
         * @brief Destrutor.
         */
        ~Nome();

        /**
         * @brief Define um novo nome.
         * @param valor Novo nome a ser atribuído.
         */
        void setValor(string valor);

        /**
         * @brief Retorna o nome.
         * @return String contendo o nome.
         */
        string getValor() const { return valor; }
};

/**
 * @class Capacidade
 * @brief Representa a capacidade de pessoas em um quarto (1 a 4).
 *
 * @details A capacidade deve estar entre 1 e 4 pessoas.
 */
class Capacidade {
    private:
        unsigned short capacidade;
        static const unsigned short LIMITE_INFERIOR = 1;
        static const unsigned short LIMITE_SUPERIOR = 4;

        /**
         * @brief Valida a capacidade.
         * @param capacidade Valor a ser validado.
         * @throws out_of_range se a capacidade não estiver entre 1 e 4.
         */
        void validar(unsigned short capacidade) const;

    public:
        /**
         * @brief Construtor padrão. Inicializa com capacidade 1.
         */
        Capacidade();

        /**
         * @brief Construtor parametrizado.
         * @param capacidade Capacidade inicial (1-4).
         */
        Capacidade(unsigned short capacidade);

        /**
         * @brief Destrutor.
         */
        ~Capacidade();

        /**
         * @brief Define uma nova capacidade.
         * @param capacidade Nova capacidade a ser atribuída.
         */
        void setCapacidade(unsigned short capacidade);

        /**
         * @brief Retorna a capacidade.
         * @return Valor da capacidade.
         */
        unsigned short getCapacidade() const { return capacidade; }
};

/**
 * @class Data
 * @brief Representa uma data com dia, mês e ano.
 *
 * @details A data deve:
 * - Ter ano entre 2000 e 2999
 * - Mês representado por abreviação de 3 letras maiúsculas (JAN, FEV, etc.)
 * - Dia válido para o mês especificado
 * - Considerar anos bissextos
 */
class Data {
    private:
        unsigned short dia;
        string mes;
        unsigned short ano;

        static const unsigned short ANO_MIN = 2000;
        static const unsigned short ANO_MAX = 2999;

        string letraMaiuscula(const string &mes) const;
        unsigned short mesParaIndice(const string &mes) const;
        bool ehBissexto(unsigned short ano) const;
        unsigned short diasNoMes(const string &mes, unsigned short ano) const;
        bool mesValido(const string &mes) const;
        void validar(unsigned short dia, const string &mes, unsigned short ano) const;

    public:
        Data();
        Data(unsigned short dia, const string &mes, unsigned short ano);
        ~Data();

        void setValor(unsigned short dia, const string &mes, unsigned short ano);

        unsigned short getDia() const { return dia; }
        string getMes() const { return mes; }
        unsigned short getAno() const { return ano; }
};

/**
 * @class Telefone
 * @brief Representa um número de telefone internacional.
 *
 * @details O telefone deve:
 * - Começar com '+'
 * - Conter exatamente 16 caracteres
 * - Ter apenas dígitos após o '+'
 * - Formato: +DDDDDDDDDDDDDDD (15 dígitos após o +)
 */
class Telefone {
    private:
        string telefone;

        bool validar(const string &telefone);

    public:
        Telefone();
        Telefone(const string &telefone);
        ~Telefone();

        void setTelefone(const string &telefone);
        string getTelefone() const { return telefone; }
};

/**
 * @class Codigo
 * @brief Representa um código alfanumérico de 10 caracteres.
 *
 * @details O código deve:
 * - Conter exatamente 10 caracteres
 * - Usar apenas letras minúsculas (a-z) e dígitos (0-9)
 */
class Codigo {
    private:
        string codigo;
        void validar(string& codigo);

    public:
        Codigo();
        Codigo(string& codigo);
        ~Codigo();

        void setCodigo(string& codigo);
        string getCodigo() const { return codigo; }
};

/**
 * @class EMAIL
 * @brief Representa um endereço de e-mail.
 *
 * @details O e-mail deve:
 * - Seguir o formato parte-local@dominio
 * - Parte local: até 64 caracteres
 * - Domínio: até 253 caracteres
 * - Usar apenas letras, dígitos, ponto e hífen
 * - Não começar ou terminar com caracteres especiais
 * - Não ter sequência de caracteres especiais
 * - Ser convertido para minúsculas
 */
class EMAIL {
    private:
        string email;
        static const int MAX_PARTE_LOCAL = 64;
        static const int MAX_DOMINIO = 253;

        /**
         * @brief Valida o e-mail segundo as regras especificadas.
         * @param email String a ser validada (será convertida para minúsculas).
         * @throws invalid_argument se o e-mail for inválido.
         */
        void validar(string& email);

    public:
        /**
         * @brief Construtor padrão. Inicializa com string vazia.
         */
        EMAIL();

        /**
         * @brief Construtor parametrizado.
         * @param email E-mail inicial.
         */
        EMAIL(string& email);

        /**
         * @brief Destrutor.
         */
        ~EMAIL();

        /**
         * @brief Define um novo e-mail.
         *
         * @details O e-mail deve:
         * - Seguir o formato parte-local@dominio
         * - Ser convertido para minúsculas
         * - Não ter sequência de caracteres especiais
         * - Não começar ou terminar com caracteres especiais
         *
         * @param email Novo e-mail a ser atribuído.
         * @throws invalid_argument se as regras acima não forem atendidas.
         */
        void setEmail(string& email);

        /**
         * @brief Retorna o e-mail.
         * @return String contendo o e-mail em minúsculas.
         */
        string getEmail() const { return email; }
};

/**
 * @class Ramal
 * @brief Representa um número de ramal telefônico (0 a 50).
 *
 * @details O ramal deve estar entre 0 e 50.
 */
class Ramal {
    private:
        int ramal;

        void validar(int& ramal);

    public:
        /**
         * @brief Construtor padrão. Inicializa com ramal 0.
         */
        Ramal();

        /**
         * @brief Construtor parametrizado.
         * @param ramal Número do ramal inicial.
         */
        Ramal(int& ramal);

        /**
         * @brief Destrutor.
         */
        ~Ramal();

        /**
         * @brief Define um novo número de ramal.
         *
         * @details O ramal deve estar no intervalo de 0 a 50.
         * @param ramal Novo valor do ramal.
         * @throws invalid_argument se o valor não estiver entre 0 e 50.
         */
        void setRamal(int& ramal);

        /**
         * @brief Retorna o número do ramal.
         * @return Valor inteiro do ramal.
         */
        int getRamal() const { return ramal; }
};

#endif // DOMINIOS_HPP_INCLUDED
