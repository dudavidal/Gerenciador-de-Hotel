#include "CntrAprPessoal.hpp"
#include <iostream>
#include <limits>

using namespace std;

void CntrAprPessoal::criar() {
    cout << "\n=== Criar Gerente ===\n";

    string nome, email, senha;

    cout << "Nome: ";
    getline(cin, nome);

    cout << "Email: ";
    getline(cin, email);

    cout << "Senha: ";
    getline(cin, senha);

    try {
        Gerente g;
        g.setNome(Nome(nome));
        g.setEmail(EMAIL(email));
        g.setSenha(Senha(senha));

        if (cntrLNPessoal->criar(g)) {
            cout << "Gerente cadastrado com sucesso!\n";
        }
        else {
            cout << "Erro: já existe um gerente com esse email.\n";
        }
    }
    catch (exception &e) {
        cout << "Erro ao cadastrar: " << e.what() << endl;
    }
}

void CntrAprPessoal::executar(const EMAIL &emailBuscado) {
    int opcao = -1;

    while (opcao != 0) {
        cout << "\n====== Menu Pessoal ======\n";
        cout << "1 - Ler dados\n";
        cout << "2 - Editar\n";
        cout << "3 - Excluir\n";
        cout << "0 - Sair\n";
        cout << "Escolha: ";
        cin >> opcao;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // ======================================================================
        // 1 — LER DADOS
        // ======================================================================
        if (opcao == 1) {
            Gerente g;
            g.setEmail(emailBuscado);

            if (cntrLNPessoal->ler(g)) {
                cout << "\n--- Dados do gerente ---\n";
                cout << "Nome: " << g.getNome().getValor() << endl;
                cout << "Email: " << g.getEmail().getEmail() << endl;
                cout << "Senha: " << g.getSenha().getValor() << endl;
            } else {
                cout << "Gerente não encontrado.\n";
            }
        }

        // ======================================================================
        // 2 — EDITAR
        // ======================================================================
        else if (opcao == 2) {
            int opcEdit = -1;

            while (opcEdit != 0) {
                cout << "\n--- O que deseja editar? ---\n";
                cout << "1 - Nome\n";
                cout << "2 - Senha\n";
                cout << "0 - Voltar\n";
                cout << "Opcao: ";

                cin >> opcEdit;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (opcEdit == 1) {
                    string novoNome;
                    cout << "Novo nome: ";
                    getline(cin, novoNome);

                    try {
                        Gerente g;
                        g.setEmail(emailBuscado);
                        g.setNome(Nome(novoNome));

                        if (cntrLNPessoal->editar(g))
                            cout << "Nome atualizado com sucesso!\n";
                        else
                            cout << "Erro ao atualizar nome.\n";
                    }
                    catch (exception &e) {
                        cout << "Erro: " << e.what() << endl;
                    }
                }

                else if (opcEdit == 2) {
                    string novaSenha;
                    cout << "Nova senha: ";
                    getline(cin, novaSenha);

                    try {
                        Gerente g;
                        g.setEmail(emailBuscado);
                        g.setSenha(Senha(novaSenha));

                        if (cntrLNPessoal->editar(g))
                            cout << "Senha atualizada com sucesso!\n";
                        else
                            cout << "Erro ao atualizar senha.\n";
                    }
                    catch (exception &e) {
                        cout << "Erro: " << e.what() << endl;
                    }
                }
            }
        }

        // ======================================================================
        // 3 — EXCLUIR
        // ======================================================================
        else if (opcao == 3) {
            char confirmar;
            cout << "Tem certeza que deseja excluir sua conta? (S/N): ";
            cin >> confirmar;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (confirmar == 'S' || confirmar == 's') {
                if (cntrLNPessoal->excluir(emailBuscado))
                    cout << "Excluído com sucesso!\n";
                else
                    cout << "Erro ao excluir (gerente não existe)!\n";

                opcao = 0; // sai do menu pessoal
            }
            else {
                cout << "Exclusão cancelada.\n";
            }
        }
    }
}

