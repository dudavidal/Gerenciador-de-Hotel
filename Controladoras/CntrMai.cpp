#include <iostream>
#include <string>
#include <limits>

#include "CntrIUAutenticacao.hpp"
#include "LNAutenticacao.hpp"
#include "ContainerGerente.hpp"

#include "CntrAprPessoal.hpp"     // IU pessoal (nome, email, senha)
#include "CntrServPessoal.hpp"    // serviço pessoal

using namespace std;

int main() {
    // ----- Container -----
    ContainerGerente* container = ContainerGerente::getInstancia();

    // ----- Serviços -----
    ILNAutenticacao* servicoAut = new LNAutenticacao(container);
    CntrServPessoal servicoPessoal;   // CRUD do gerente

    // ----- Interfaces (IU) -----
    CntrIUAutenticacao ctrlAut;
    CntrAprPessoal ctrlAprPessoal;

    ctrlAut.setCntrLNAutenticacao(servicoAut);
    ctrlAprPessoal.setCntrLNPessoal(&servicoPessoal);

    while (true) {
        cout << "\n=== Sistema Hoteleiro ===\n";
        cout << "1 - Acessar conta\n";
        cout << "2 - Criar conta\n";
        cout << "0 - Sair\n";
        cout << "Opcao: ";

        int opcao;
        cin >> opcao;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (opcao == 0) {
            cout << "Encerrando...\n";
            break;
        }

        // === CRIAR GERENTE ======================================================
        if (opcao == 2) {
            cout << "\nCriando gerente...\n";

            string nomeStr, emailStr, senhaStr;

            cout << "Nome: ";
            getline(cin, nomeStr);

            cout << "Email: ";
            getline(cin, emailStr);

            cout << "Senha: ";
            getline(cin, senhaStr);

            try {
                Gerente g;
                g.setNome(Nome(nomeStr));
                g.setEmail(EMAIL(emailStr));
                g.setSenha(Senha(senhaStr));

                if (servicoPessoal.criar(g))
                    cout << "Gerente criado com sucesso!\n";
                else
                    cout << "Erro: já existe um gerente com esse email.\n";
            }
            catch (invalid_argument &e) {
                cout << "Erro ao cadastrar: " << e.what() << "\n";
            }

            continue;
        }

        // === LOGIN ==============================================================
        if (opcao == 1) {
            string emailStr, senhaStr;

            cout << "Email: ";
            getline(cin, emailStr);

            cout << "Senha: ";
            getline(cin, senhaStr);

            try {
                EMAIL email(emailStr);
                Senha senha;
                senha.setValor(senhaStr);

                if (ctrlAut.autenticar(&email, &senha)) {
                    cout << "\nAutenticado com sucesso!\n";

                    // === MENU APÓS LOGIN ======================================
                    while (true) {
                        cout << "\n=== Menu do Gerente ===\n";
                        cout << "1 - Gerenciar dados pessoais\n";
                        cout << "2 - Gerenciar reservas\n";
                        cout << "0 - Sair da conta\n";
                        cout << "Opcao: ";

                        int acao;
                        cin >> acao;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        if (acao == 0) {
                            cout << "Saindo da conta...\n";
                            break;
                        }

                        if (acao == 1) {
                            ctrlAprPessoal.executar(email);
                        }

                        // --- 2 → Reservas (futuro) ---------------------------------
                        if (acao == 2) {
                            cout << "Módulo de reservas ainda não implementado.\n";
                        }
                    }
                }
                else {
                    cout << "Falha na autenticacao.\n";
                }
            }
            catch (invalid_argument &e) {
                cout << "Erro: " << e.what() << "\n";
            }
        }
    }

    delete servicoAut;
    return 0;
}
