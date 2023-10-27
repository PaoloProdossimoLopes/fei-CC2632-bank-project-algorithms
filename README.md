# Projeto 2
## Trabalho prático - Banco QuemPoupaTem
O novo banco QuemPoupaTem vai iniciar a sua operação em breve, mas não tem um sistema bancário estabelecido. Para desenvolver o sistema que controla os clientes, o banco decidiu contratar você.

O seu programa deve ser todo desenvolvido em C.

### Requisitos

O banco trabalha com dois tipos de conta:\

**Comum**:
- Cobra taxa de 5% a cada débito realizado
- Permite um saldo negativo de até (R$ 1.000,00)

**Plus**:
- Cobra taxa de 3% a cada débito realizado
- Permite um saldo negativo de até (R$ 5.000,00)

O sistema criado por você deve funcionar em loop infinito até que se deseje sair;
Um menu de opções deve ser sempre apresentado ao operador, contendo as seguintes operações:

1. Novo cliente
2. Apaga cliente
3. Listar clientes
4. Débito
5. Depósito
6. Extrato
7. Transferência Entre Contas
0. Sair

Cada opção deve ser implementada como uma função.\
O seu programa deve conseguir armazenar até 1000 clientes e as informações das últimas 100 operações (depósito, saque, transferência) realizada pelo cliente.

**IMPORTANTE: Não se esqueça de que o banco não pode perder as informações se o programa terminar, fechar, parar de funcionar, ou o computador desligar. Todos os dados devem ser salvos de maneira permanente utilizando arquivos binários.**

### Funções
**Opção 1 - Usada para criar novos clientes.**\
Dados solicitados:\
- Nome
- CPF
- Tipo de conta (são dois: comum e plus)
- Valor inicial da conta
- Senha do usuário

**Opção 2 - Apaga o cliente pelo CPF**

**Opção 3 - Listar todos os clientes**

**Opção 4 - Serve para debitar um valor da conta do cliente**\
Dados solicitados:
- CPF
- Senha
- Valor

*OBS: O débito somente pode ser feito se o CPF e a senha estiverem corretos.*

**Opção 5 - Deposita um valor na conta do cliente**\
Dados solicitados:
- CPF
- Valor

**Opção 6 - Extrato - gera um arquivo com o histórico de todas as operações realizadas na conta, com valores, incluindo as tarifas.**\
Dados solicitados:
- CPF
- Senha

O formato do extrato é livre, porém o arquivo de saída deve ser em formato txt e que possa ser aberto em qualquer editor de texto.\ 
Não é necessário armazenar as datas das transações\
O extrato só pode ser exibido se o CPF e senha estiverem corretos

**Opção 7 - Transferência - realiza a transferência de uma valor determinado de uma conta (Origem) para outra conta (Destino)**\
Dados solicitados:
- CPF (Origem)
- Senha (Origem)
- CPF (Destino)
- Valor

O transferência só pode ser realizada se o CPF e a senha da conta de origem estiverem corretos

### Limitações
- Não será permitido o uso de bibliotecas além do que já é oferecido no momento da instalação. O projeto receberá nota zero se utilizar bibliotecas não desenvolvidas por você;
- Caso seja detectado código copiado ou qualquer forma de plágio, a nota será zerada.
- O código deve ser comentado de forma a explicar a lógica desenvolvida ao longo do código e isto pode afetar a nota;
- O projeto pode ser desenvolvido em qualquer sistema operacional e com qualquer IDE ou editor de texto. Porém, para a avaliação, a compilação e execução serão realizadas no replit e será avaliado o funcionamento do programa no ambiente fornecido pelo serviço;
- Serão apenas aceitos projetos armazenados em serviços de versionamento de código como Github, Gitlab, Bitbucket, etc. e o histórico de commits será utilizado na avaliação do projeto. Não serão aceitos endereços do replit como entrega de código;
- O projeto pode ser desenvolvido em duplas. Podem ser feitas exceções para trios, mas somente após avisar o professor da disciplina e com a aceitação de todos os membros do trio.

### Critérios de avaliação
- Código organizado e bem escrito
- dividido em funções
- código formatado
- bons nomes de variáveis e funções
- uso correto dos tipos de variáveis

### Funcionamento:
- programa funciona corretamente
- erros são tratados
- usabilidade (se é possível entender como interagir com o programa)
- todas as funções pedidas estão presentes

#### Documentação:
- o código está comentado
- é possível entender a lógica a partir dos comentários no código

#### Pontuação para cada função que precisa ser implementada:
- Novo cliente - **1 ponto**
- Apaga cliente - **1 ponto**
- Listar clientes - **1 ponto**
- Débito - **1 ponto**
- Depósito - **1 ponto**
- Extrato - **2 ponto (1 ponto pelo armazenamento dos dados e 1 ponto pelo arquivo)**
- Transferência Entre Contas - **1 ponto**
- Salvar os dados em arquivo binário - **1 ponto**
- Carregar os dados de um arquivo binário - **1 ponto**

#### O que pode causar perda de pontos (os pontos apresentados serão descontados da nota final):
- Projeto não estruturado (todas as funções em apenas um arquivo, falta de uso de funções, somente variáveis globais) -  **5 pontos**
- Funções que não recebem parâmetros e usam apenas variáveis globais - **1 ponto para cada função**
- Uso incorreto dos tipos de variáveis e retornos de função - **1 ponto para cada função**
- Variáveis e funções com nomes que não explicam o funcionamento - **1 ponto para cada função**
- Loops desnecessários - **1 ponto para cada loop**
- Entrega de código com apenas 1 commit (além do inicial) no repositório - **5 pontos**
- Falta de uso de branches para fazer o código - **3 ponto**
- Falta do arquivo README.md no repositório explicando a proposta do projeto - **1 ponto**
- Apenas pessoas que fizeram commits receberão notas. Alunos sem commits receberão nota zero.
- Entrega do código direto no replit - **10 pontos**
- Código não compila ou não executa quando testado no replit - **5 pontos**
- Plágio (igual ao de outro grupo, mesmo sendo em períodos diferentes ou de semestre anterior) - **recebe nota zero**

### Entrega
É necessário entregar:
- endereço de um repositório público (Github, Gitlab, etc) com código fonte em C do projeto usando um sistema de versionamento de código (git, mercurial, etc).

Não é necessário entregar:
- Binário compilado;
- Documentação sobre como usar o programa.