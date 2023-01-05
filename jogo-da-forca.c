#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void limpaTela(){
    system("CLS");
}

void menuInicial(){

    //Opção escolhida pelo usuário
    int opcao = 0;

    //Enquanto o jogador não digita uma opcao válida, mostra o menu novamente
    while(opcao < 1 || opcao > 3){
        limpaTela();
        printf("Bem vindo ao Jogo");
        printf("\n1 - Jogar Sozinho");
        printf("\n2 - Jogar em Dupla");
        printf("\n3 - Sobre");
        printf("\n4 - Sair");
        printf("\nEscolha uma opcao e tecle ENTER:");

        //Faz a leitura da opcao
        scanf("%d", &opcao);

        //Faz algo de acordo com a opcao escolhida
        switch(opcao){
            case 1:
                //Inicia o jogo
                if(jogar(1) == 1){
                    menuInicial();
                }
                break;
            case 2:
                //Inicia o jogo
                if(jogar(2) == 1){
                    menuInicial();
                }
                break;
            case 3:
                //Mostra informacoes do Jogo
                printf("Informacoes do jogo:");
                limpaTela();
                printf("Jogo desenvolvido por Gabriel em 2023");
                printf("\n1 - Voltar");
                printf("\n2 - Sair");
                scanf("%d", &opcao);
                if(opcao == 1){
                    menuInicial();
                }

                break;
            case 4:
                printf("Ate mais!");
                break;
        }
    }

}

int main(){
    menuInicial();
    return 0;
}