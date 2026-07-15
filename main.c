#include <stdio.h>   
#include <stdlib.h>
#include <string.h>

void quantidade (char destino [30], float preco, float *quant, float *total) {

    char charquant[10];
    int qcorreta;
    char *ptr_erro;

    printf("\nDestino escolhido, %s.", destino);
    printf("\nQuantas passagens voce gostaria?\n");

    do {
        printf("> ");
        fgets(charquant, 10, stdin);
        charquant[strcspn(charquant,"\n")] = '\0';

        long quanttemp = strtol(charquant,&ptr_erro, 10);
        qcorreta = 1;

        int espacos = 1;
        int i = 0;

        while (charquant[i] != '\0') {
            if (charquant[i] != ' ') {
                espacos = 0;
                break;
            }
            i++;
        }

        if (espacos || charquant[0] == '\0' || *ptr_erro != '\0' || quanttemp <= 0) {
            printf("Quantidade invalida. Digite um numero maior que zero.\n");
            qcorreta = 0;
        } else {
            *quant += (float)quanttemp;
        }
    } while (!qcorreta);

    *total = preco * (*quant);

    if (*quant == 1) {
        printf("%.0f passagem comprada com sucesso! Subtotal: R$%.2f\n", *quant, *total);
    }
    else {
        printf("%.0f passagens compradas com sucesso! Subtotal: R$%.2f\n", *quant, *total);
    }
}

int main(void) {
    int espacos, espacos2;
    int rodando_menu1 = 1, rodando_menu2 = 1, rodando_cupom = 1;
    float qtd_sp = 0, qtd_rj = 0, qtd_bh = 0;
    float tt_sp = 0, tt_rj = 0, tt_bh = 0;
    float total_geral, desc_total, total_final;
    float desc = 1;
    char nomepassageiro [30], opcao [10];
    char *ponteiro_erro;
    long lopcao;
    char cupom [10];


    printf("Ola passageiro, por favor, digite o seu nome para se identificar.\n");

    do {
        fgets(nomepassageiro, 30, stdin);
        nomepassageiro[strcspn(nomepassageiro,"\n")] = '\0';

        espacos = 1;
        int i = 0;

        while (nomepassageiro[i] != '\0') {
            if (nomepassageiro[i] != ' ') {
                espacos = 0;
                break;
            }
            i++;
        }
        if (espacos) {
            printf("Nome invalido, por favor, digite o seu nome.\n");
        }
    } while (espacos);

    printf("Ola %s, tudo bem?\n", nomepassageiro);

    do {
        printf("\n=== MENU DE DESTINOS ===");
        printf("\nCod. 1: Sao Paulo - R$51,90");
        printf("\nCod. 2: Rio de Janeiro - R$84,90");
        printf("\nCod. 3: Belo Horizonte - R$64,90");
        printf("\nCod. 0: Finalizar Atendimento e Pagar.\n");
        printf("Escolha uma opcao: ");

        fgets(opcao, 10, stdin);
        opcao[strcspn(opcao,"\n")] = '\0';

        espacos2 = 1;
        int i = 0;
        while (opcao[i] != '\0') {
            if (opcao[i] != ' ') {
                espacos2 = 0;
                break;
            }
            i++;
        }
        if (espacos2 || opcao[0] == '\0') {
            printf("Codigo invalido. Digite uma das opcoes do menu.\n");
            continue;
        }

        lopcao = strtol(opcao, &ponteiro_erro, 10);

        if (*ponteiro_erro != '\0') {
            printf("Codigo invalido. Por favor, digite apenas numeros.\n");
            continue;
        }

        switch (lopcao) {
            case 0:
                printf("\nFinalizando atendimento...\n");
                rodando_menu1 = 0;
                break;
            case 1:
                quantidade("Sao Paulo", 51.90, &qtd_sp , &tt_sp);
                break;
            case 2:
                quantidade("Rio de Janeiro", 84.90, &qtd_rj, &tt_rj);
                break;
            case 3:
                quantidade("Belo Horizonte", 64.90, &qtd_bh, &tt_bh);
                break;
            default:
                printf("Codigo invalido. Escolha uma opcao de 0 a 3.\n");
                break;
            }
    } while (rodando_menu1);

    printf("Voce possui algum cupom de desconto?\n");
    printf("Sim OU Nao\n");

    do {
        fgets(cupom, 10, stdin);
        cupom[strcspn(cupom,"\n")] = '\0';

        if ((strcmp(cupom, "Sim") != 0) && (strcmp(cupom,"SIM") != 0) && (strcmp(cupom, "Nao") != 0) && (strcmp(cupom, "NAO") != 0)) {
            printf("Digite Sim OU Nao.\n");
        }
        else if ((strcmp(cupom, "Sim") == 0) || (strcmp(cupom,"SIM") == 0)) {
            printf("Qual o seu cupom? (Ou digite \"Sair\", para prosseguir sem desconto)\n");

            do {
                fgets(cupom, 10, stdin);
                cupom[strcspn(cupom, "\n")] = '\0';

                if ((strcmp(cupom, "DESC10") == 0) || (strcmp(cupom, "Desc10") == 0)){
                    desc = 0.9;
                    printf("\n> Cupom %s aplicado! (10%% de desconto).\n", cupom);
                    rodando_cupom = 0;
                    rodando_menu2 = 0;
                }
                else if ((strcmp(cupom, "DESC20") == 0) || (strcmp(cupom, "Desc20") == 0)) {
                    desc = 0.8;
                    printf("\n> Cupom %s aplicado! (20%% de desconto).\n", cupom);
                    rodando_cupom = 0;
                    rodando_menu2 = 0;
                }
                else if ((strcmp(cupom, "Sair") == 0) || (strcmp(cupom, "SAIR") == 0)) {
                    rodando_cupom = 0;
                    rodando_menu2 = 0;
                }
                else {
                    printf("\n> Cupom invalido! Por favor, digite um cupom valido.\n(Ou digite \"Sair\", para prosseguir sem desconto)\n");
                }
            } while (rodando_cupom);
        }
        else if ((strcmp(cupom, "Nao") == 0) || (strcmp(cupom, "NAO") == 0)) {
            printf("\n> Prosseguindo sem desconto.\n");
            rodando_menu2 = 0;
        }
    } while (rodando_menu2);

    total_geral = tt_sp + tt_rj + tt_bh;
    total_final = total_geral * desc;
    desc_total = total_geral - total_final;


    printf("\n=========================================");
    printf("\n          RESUMO DA SUA COMPRA          ");
    printf("\n=========================================");
    printf("\nPassageiro: %s.", nomepassageiro);

    if (qtd_sp > 0) printf("\n- Sao Paulo: %.0f passagens | Total: R$%.2f", qtd_sp, tt_sp);
    if (qtd_rj > 0) printf("\n- Rio de Janeiro: %.0f passagens | Total: R$%.2f", qtd_rj, tt_rj);
    if (qtd_bh > 0) printf("\n- Belo Horizonte: %.0f passagens | Total: R$%.2f", qtd_bh, tt_bh);

    printf("\n-----------------------------------------");
    printf("\nTotal (s/ desconto): R$%.2f", total_geral);
    if (desc < 1) printf("\nDesconto:            R$%.2f", desc_total);
    if (desc < 1) printf("\nTotal (c/ desconto): R$%.2f", total_final);
    printf("\n=========================================\n");

    return 0;
}