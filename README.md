# Totem de Autoatendimento Rodoviário

Este é um sistema interativo de simulação de um **Totem de Autoatendimento para uma Rodoviária**, desenvolvido inteiramente na linguagem **C**. O programa permite ao utilizador identificar-se, escolher passagens para diferentes destinos, acumular bilhetes no carrinho de compras, aplicar cupões de desconto e obter um recibo detalhado no final da operação.

O projeto foi construído com foco especial em **robustez e validação de dados**, garantindo que entradas inválidas (como letras onde deveriam estar números ou campos em branco) sejam tratadas de forma segura, sem bloquear a execução do programa.

## Funcionalidades

- **Identificação do Passageiro:** Validação rigorosa para garantir que o nome introduzido não esteja em branco ou contenha apenas espaços.
- **Menu Interativo de Destinos:**
  - Cod. 1: São Paulo — R$ 51,90
  - Cod. 2: Rio de Janeiro — R$ 84,90
  - Cod. 3: Belo Horizonte — R$ 64,90
- **Carrinho Acumulativo:** O utilizador pode selecionar o mesmo destino várias vezes e o sistema acumulará a quantidade e o subtotal corretamente.
- **Tratamento de Erros Robusto:** Utilização das funções de conversão segura `strtol` para evitar falhas críticas quando o utilizador digita caracteres inválidos.
- **Sistema de Cupões de Desconto:** Suporte para os cupões `DESC10` (10% de desconto) e `DESC20` (20% de desconto), com opção de cancelamento/saída rápida.
- **Recibo Detalhado:** Exibição limpa das passagens adquiridas, subtotal, valor exato do desconto aplicado e o total final a pagar.

## Tecnologias Utilizadas

- **Linguagem de Programação:** C (compatível com C99 ou superior)
- **Bibliotecas Padrão:** `<stdio.h>`, `<stdlib.h>` e `<string.h>`

## Como Executar o Projeto

### Pré-requisitos
É necessário ter um compilador de C instalado no teu sistema (como o **GCC**).

### Passos para compilação e execução:

1. Abre o teu terminal (ou Git Bash) na pasta onde o ficheiro `main.c` está localizado.
2. Compile o código com o seguinte comando:
   ```bash
   gcc main.c -o totem