#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para exibir as opções do jogo
void exibir_opcoes() {
    printf("Escolha uma opção:\n");
    printf("1 - Pedra\n");
    printf("2 - Papel\n");
    printf("3 - Tesoura\n");
}

// Função para converter a escolha numérica em texto
const char* obter_nome_opcao(int escolha) {
    switch (escolha) {
        case 1: return "Pedra";
        case 2: return "Papel";
        case 3: return "Tesoura";
        default: return "Inválida";
    }
}

// Função para determinar o vencedor
void determinar_vencedor(int escolha_usuario, int escolha_computador) {
    printf("\nVocê escolheu: %s\n", obter_nome_opcao(escolha_usuario));
    printf("O computador escolheu: %s\n", obter_nome_opcao(escolha_computador));

    if (escolha_usuario == escolha_computador) {
        printf("Empate!\n");
    } else if ((escolha_usuario == 1 && escolha_computador == 3) || // Pedra vence Tesoura
               (escolha_usuario == 2 && escolha_computador == 1) || // Papel vence Pedra
               (escolha_usuario == 3 && escolha_computador == 2)) { // Tesoura vence Papel
        printf("Você venceu!\n");
    } else {
        printf("O computador venceu!\n");
    }
}

int main() {
    int escolha_usuario, escolha_computador;

    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    printf("Bem-vindo ao Jokenpô!\n");

    do {
        // Exibe as opções para o usuário
        exibir_opcoes();

        // Lê a escolha do usuário
        printf("Sua escolha: ");
        scanf("%d", &escolha_usuario);

        // Valida a escolha do usuário
        if (escolha_usuario < 1 || escolha_usuario > 3) {
            printf("Opção inválida! Tente novamente.\n\n");
            continue;
        }

        // Gera a escolha do computador (1 a 3)
        escolha_computador = rand() % 3 + 1;

        // Determina o vencedor
        determinar_vencedor(escolha_usuario, escolha_computador);

        // Pergunta se o usuário deseja jogar novamente
        printf("\nDeseja jogar novamente? (1 - Sim, 0 - Não): ");
        scanf("%d", &escolha_usuario);

    } while (escolha_usuario == 1);

    printf("Obrigado por jogar! Até mais!\n");

 
    return 0;

    
}