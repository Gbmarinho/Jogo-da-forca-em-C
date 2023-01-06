#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <Windows.h>
#include <iostream>
#include <time.h>

using namespace std;

void limpaTela(){
    system("CLS");
}

string palavra_aleatoria(){
    string palavras[15] = {"abacaxi", "manga", "morango", "cachorro", "macaco", "tubarao", "uva", "sushi", "pizza", "hamster",
    "gato", "malzahar", "raposa", "naruto", "luffy"};

    int indice_aleatorio = rand() % 15;
    string palavra = palavras[indice_aleatorio];
    return palavra;
}

int tamanho_da_palavra(string palavra){
    return palavra.size();
}

string retorna_palavra_mascara(int tamPalavra){
     string palavra_mascara;

    int cont = 0, i;
    for(i=0;i<tamPalavra;i++){
        palavra_mascara += "_";
    }
    //printf("%s", palavra_mascara.c_str());
    return palavra_mascara;
}
void jogarSozinho(){
    string palavra = palavra_aleatoria();

    int tamPalavra = tamanho_da_palavra(palavra);

    string palavra_mascara = retorna_palavra_mascara(tamPalavra);


    int tentativas = 0, max_tentativas = tamPalavra+5;
    int cont = 0;
    char letra;
    string letras_arriscadas = "";
    string arrisca_palavra;
    bool ja_digitada;


    while(palavra != palavra_mascara && max_tentativas - tentativas > 0){
        limpaTela();
        if(ja_digitada == true){
            printf("Letra ja foi digitada, tente outra letra diferente\n");
        }
        ja_digitada = false;
        printf("Palavra: %s (Tamanho: %d)", palavra_mascara.c_str(), tamPalavra);
        printf("\nTentativas restantes: %d", (max_tentativas - tentativas));
        printf("\nLetras arriscadas: %s\n", letras_arriscadas.c_str());
        printf("Digite uma letra (ou digite 1 para arriscar a palavra): ");
        scanf("%c", &letra);
        if(letra == '1'){
            fflush(stdin);
            printf("\nEscreva a palavra: ");
            cin >> arrisca_palavra;
            if(arrisca_palavra == palavra){
                palavra_mascara = arrisca_palavra;
            }else{
                tentativas = max_tentativas;
            }
            fflush(stdin);

        }
        for(cont=0; cont<tentativas*2;cont++){
            if(letras_arriscadas[cont]==letra){
                ja_digitada = true;
            }
        }
        if(ja_digitada == false){
            letras_arriscadas += letra;
            letras_arriscadas += " ";
            for(cont=0;cont<tamPalavra;cont++){
                if(palavra[cont] == letra){
                    palavra_mascara[cont] = palavra[cont];
                }
            }
            tentativas = tentativas +1;
        }


        fflush(stdin);
    }
    if(palavra_mascara == palavra){
        limpaTela();
        printf("Parabans voce ganhou!!");
        Sleep(2000);
    }else{
        limpaTela();
        printf("Que pena, voce perdeu");
        Sleep(2000);
    }

}

void jogarDupla(){
    limpaTela();
    string palavra;
    printf("Bem vindo ao jogo em dupla!");
    printf("\nUm dos dois irá digitar uma palavra para o outro tentar acertar.");
    printf("\nDigite uma palavra: ");
    cin >> palavra;
    fflush(stdin);
    int tamPalavra = tamanho_da_palavra(palavra);

    string palavra_mascara = retorna_palavra_mascara(tamPalavra);


    int tentativas = 0, max_tentativas = tamPalavra+5;
    int cont = 0;
    char letra;
    string letras_arriscadas = "";
    string arrisca_palavra;
    bool ja_digitada;


    while(palavra != palavra_mascara && max_tentativas - tentativas > 0){
        limpaTela();
        if(ja_digitada == true){
            printf("Letra ja foi digitada, tente outra letra diferente\n");
        }
        ja_digitada = false;
        printf("Palavra: %s (Tamanho: %d)", palavra_mascara.c_str(), tamPalavra);
        printf("\nTentativas restantes: %d", (max_tentativas - tentativas));
        printf("\nLetras arriscadas: %s\n", letras_arriscadas.c_str());
        printf("Digite uma letra (ou digite 1 para arriscar a palavra): ");
        scanf("%c", &letra);
        if(letra == '1'){
            fflush(stdin);
            printf("\nEscreva a palavra: ");
            cin >> arrisca_palavra;
            if(arrisca_palavra == palavra){
                palavra_mascara = arrisca_palavra;
            }else{
                tentativas = max_tentativas;
            }
            fflush(stdin);

        }
        for(cont=0; cont<tentativas*2;cont++){
            if(letras_arriscadas[cont]==letra){
                ja_digitada = true;
            }
        }
        if(ja_digitada == false){
            letras_arriscadas += letra;
            letras_arriscadas += " ";
            for(cont=0;cont<tamPalavra;cont++){
                if(palavra[cont] == letra){
                    palavra_mascara[cont] = palavra[cont];
                }
            }
            tentativas = tentativas +1;
        }


        fflush(stdin);
    }
    if(palavra_mascara == palavra){
        limpaTela();
        printf("Parabans voce ganhou!!");
        Sleep(2000);
    }else{
        limpaTela();
        printf("Que pena, voce perdeu");
        Sleep(2000);
    }

}

void menuInicial(){

    //Opção escolhida pelo usuário
    int opcao = 0;

    //Enquanto o jogador não digita uma opcao válida, mostra o menu novamente
    while(opcao < 1 || opcao > 4){
        limpaTela();
        printf("Bem vindo ao Jogo");
        printf("\n1 - Jogar Sozinho");
        printf("\n2 - Jogar em Dupla");
        printf("\n3 - Sobre");
        printf("\n4 - Sair");
        printf("\nEscolha uma opcao e tecle ENTER:");

        //Faz a leitura da opcao
        scanf("%d", &opcao);

        fflush(stdin);
        //Faz algo de acordo com a opcao escolhida
        switch(opcao){
            case 1:
                //Inicia o jogo
                jogarSozinho();
                menuInicial();
                break;
            case 2:
                jogarDupla();
                menuInicial();
                break;
            case 3:
                //Mostra informacoes do Jogo
                printf("Informacoes do jogo:");
                limpaTela();
                printf("Jogo desenvolvido por Gabriel em 2023");
                printf("\n1 - Voltar");
                printf("\n2 - Sair");
                printf("\nEscolha uma opcao e tecle ENTER:");
                scanf("%d", &opcao);
                if(opcao == 1){
                    menuInicial();
                }

                break;
            case 4:
                limpaTela();
                printf("Ate mais!");
                break;
        }
    }

}

int main(){
    //Para gerar números realmente aleatórios
    srand((unsigned)time(NULL));

    menuInicial();
    return 0;
}
