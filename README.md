
# Organização por Células

## Descrição
Este código implementa um aplicativo de planilha simples usando a biblioteca Qt. Ele cria uma interface gráfica onde o usuário pode interagir com uma tabela e clicar em um botão para calcular a soma dos valores na tabela.

## Linguagem e Tipos de Código
- **Linguagem:** O código foi escrito em **Linguagem C++**

## Inclusões de bibliotecas:

```properties
#include "SpreadsheetApp.h"
#include <QTableWidgetItem>
```
- `SpreadsheetApp.h`: Este cabeçalho é responsável pela declaração da classe `SpreadsheetApp`, que provavelmente é uma classe que define o aplicativo da planilha. O arquivo de cabeçalho também inclui declarações de componentes da interface gráfica que são utilizados na implementação.
- `<QTableWidgetItem>`: Esta inclusão fornece a funcionalidade necessária para interagir com os itens de uma `QTableWidget`, que é um widget da Qt usado para exibir e editar tabelas.

Construtor `SpreadsheetApp::SpreadsheetApp`:

```properties
SpreadsheetApp::SpreadsheetApp(QWidget *parent)
    : QWidget(parent) {
    setupUi(this);  // Carrega a interface do arquivo .ui
    setupConnections();
}
```

- `SpreadsheetApp(QWidget *parent)`: Este é o construtor da classe `SpreadsheetApp`. Ele recebe um ponteiro para um `QWidget` que é o widget pai. Isso significa que esse widget será um componente dentro de um widget maior (por exemplo, uma janela principal de aplicativo).

- `setupUi(this);`: Esse método é responsável por configurar a interface gráfica carregada a partir de um arquivo `.ui` (provavelmente criado no Qt Designer). O método setupUi é gerado automaticamente pelo Qt a partir de um arquivo XML `.ui` que define a aparência da interface, como tabelas, botões, etc.

- `setupConnections();`: Este método é chamado logo após o carregamento da interface. Ele provavelmente configura as conexões entre os sinais (como cliques de botões) e os slots (funções que manipulam esses eventos).

Método `setupConnections`:

```properties
void SpreadsheetApp::setupConnections() {
    connect(sumButton, &QPushButton::clicked, this, &SpreadsheetApp::on_sumButton_clicked);
}
```

O método `setupConnections` configura a conexão entre um sinal e um slot:

- `connect()`: A função `connect` conecta um sinal de um widget a um slot de outro. O primeiro argumento `sumButton` é um ponteiro para o botão de soma na interface, o segundo argumento é o sinal `clicked` que é emitido quando o botão é clicado.
- Quando o botão é clicado, ele chama o slot `on_sumButton_clicked`, que é o método que vai somar os valores da tabela.

Método `on_sumButton_clicked`:

```properties
void SpreadsheetApp::on_sumButton_clicked() {
    double sum = 0;
    for (int row = 0; row < tableWidget->rowCount(); ++row) {
        for (int col = 0; col < tableWidget->columnCount(); ++col) {
            bool ok;
            double value = tableWidget->item(row, col) ? tableWidget->item(row, col)->text().toDouble(&ok) : 0;
            if (ok) sum += value;
        }
    }
    tableWidget->setItem(9, 9, new QTableWidgetItem(QString::number(sum)));
}
```

`double sum = 0;`: Inicializa a variável sum que será usada para armazenar a soma dos valores da tabela.

`for (int row = 0; row < tableWidget->rowCount(); ++row)`: Este loop percorre todas as linhas da tabela. `tableWidget` é um `QTableWidget` que representa a tabela da planilha.

`for (int col = 0; col < tableWidget->columnCount(); ++col)`: Este loop percorre todas as colunas da tabela.

`bool ok;`: A variável ok é usada para verificar se a conversão de texto para número foi bem-sucedida.

`double value = tableWidget->item(row, col) ? tableWidget->item(row, col)->text().toDouble(&ok) : 0;:`

- Aqui, o código tenta obter o valor de cada célula da tabela na posição (`row, col`).
- `tableWidget->item(row, col)` retorna o item da célula, ou nullptr se não houver item. Se o item existir, o código tenta converter o texto dessa célula para um número (`toDouble(&ok)`). Caso a célula não tenha valor numérico ou seja vazia, o valor é tratado como `0`.

`if (ok) sum += value;`: Se a conversão foi bem-sucedida (`ok` é `true`), o valor da célula é adicionado à soma total.

`tableWidget->setItem(9, 9, new QTableWidgetItem(QString::number(sum)));`: Após o cálculo da soma de todos os valores da tabela, o código insere o resultado na célula localizada na linha 9, coluna 9 (provavelmente a célula de resultado da soma) da tabela, como um novo item `QTableWidgetItem`. O valor da soma é convertido para uma string com `QString::number(sum)`.

## Objetivo e funcionalidade:

Este código implementa um aplicativo simples de planilha, onde o usuário pode inserir valores nas células de uma tabela. Quando o botão de soma é clicado, a aplicação calcula a soma de todos os valores numéricos presentes na tabela e exibe o resultado na célula (`9, 9`).

Descrição detalhada do fluxo:

- O aplicativo inicializa a interface gráfica a partir de um arquivo `.ui` e configura as conexões de sinal e slot.
- Quando o usuário clica no botão de soma (`sumButton`), o slot `on_sumButton_clicked` é chamado.
- O código percorre todas as células da tabela (`tableWidget`) e tenta somar os valores numéricos que encontram.
- Se a célula contiver um valor válido, ele é somado ao total.
- O resultado da soma é exibido na célula localizada na linha 9, coluna 9 da tabela.


## **Muito Obrigado pela sua atenção!**
