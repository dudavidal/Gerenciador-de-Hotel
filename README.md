# Sistema de Gestão de Hotéis – Fork de Desenvolvimento Independente

Este repositório é um **fork do projeto original de Gustavo Pavanelli**, com o objetivo de **continuar e finalizar o desenvolvimento do sistema que eu havia começado em grupo**, porém com alterações e melhorias independentes do repositório principal.

O sistema de organização e desenvolvimento das funcionalidades seguiu a base criada por Pavanelli, mas as demais partes foram **reestruturadas e finalizadas por mim**.

---

## Identificação de Membros e Artefatos Construídos

### Membros

### Membros

- **Maria Eduarda Vidal Macedo de Brito**  
  Desenvolvimento dos mecanismos de segurança, gestão de usuários, infraestrutura de dados e todas as demais classes e funcionalidades do sistema. Todo o restante do sistema, além das bases de domínio e entidades, foi desenvolvido independentemente.

- **Gustavo Nascimento Pavanelli** – [GitHub](https://github.com/PavanelliGustavo)  
  Responsável pelas bases de domínio e entidades utilizadas como referência para o início do projeto.

---

### Artefatos de Arquitetura (Módulos)

- **Subsistema de Autenticação (MAA e MSA):**  
  Implementação completa do fluxo de login, desde a interface de captura de credenciais até a validação segura e controle de sessão.

- **Módulo de Acesso e Integração (MAI):**  
  Hub central que gerencia a navegação inicial e roteia o usuário para os demais subsistemas.

- **Subsistema Pessoal (MAP e MSP):**  
  Módulos que permitem ao gerente gerenciar seu próprio perfil, incluindo a lógica de edição segura de dados cadastrais.

---

### Artefatos de Infraestrutura

- **Containers de Dados:**  
  Criação e configuração das estruturas de armazenamento (banco de dados) utilizadas por todo o sistema.

---

### Artefatos de Domínio (Classes Básicas)

- **Maria Eduarda:**  
  Implementação das classes: `Capacidade`, `Data` e `Telefone`.

- **Gustavo Pavanelli:**  
  Implementação das classes: `Cartão`, `Código`, `Dinheiro`, `E-mail`, `Endereço`, `Nome`, `Número`, `Ramal` e `Senha`.

---

💡 **Observação:** Este repositório busca ser uma versão completa e funcional do projeto, mantendo a referência à base original, mas com desenvolvimento independente e melhorias aplicadas pela autora deste fork.
