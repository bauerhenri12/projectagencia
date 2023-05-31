#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMIT 400
char lista_todos_nomes[LIMIT][LIMIT];
char lista_todos_sobrenomes[LIMIT][LIMIT];
char lista_todos_numeros[LIMIT][LIMIT];
int indice = 0;
void adicionacontato(){
    char nome[LIMIT];
    char sobrenome[LIMIT];
    char numerocell[LIMIT];
    printf("Digite o nome:");
    scanf("%s",nome);
    fflush(stdin);
    printf("Digite o sobrenome:");
    scanf("%s",sobrenome);
    fflush(stdin);
    printf("Digite o numero do celular sem () e -:");
    scanf("%s",numerocell);
    fflush(stdin);
    strcpy(lista_todos_nomes[indice], nome);
    strcpy(lista_todos_sobrenomes[indice], sobrenome);
    strcpy(lista_todos_numeros[indice], numerocell);
    indice++;
}
void printaosnomes(){
    int i;
    for (i = 0; i <= indice; i++)
    {
        printf(lista_todos_nomes[i]);
        printf("\n");
    }
}
void printaossobrenomes(){
    int i;
    for (i = 0; i <= indice; i++)
    {
        printf(lista_todos_sobrenomes[i]);
        printf("\n");
    }
}
void printaosnumeros(){
    int i;
    for (i = 0; i <= indice; i++)
    {
        printf(lista_todos_numeros[i]);
        printf("\n");
    }
}
int exibemenu(){
    int numerodigitado = 0;
    printf("Bem vindo a sua agenda\n");
    printf("------------------------------------\n");
    printf("Digite 0 se voce quiser encerrar o sistema\nDigite 1 se quiser adicionar um contato\nDigite 2 se voce quiser apagar um contato\nDigite 3 se voce quiser editar um contato\nDigite 4 se voce quiser buscar um contato: ");
    scanf("%d",&numerodigitado);
        
    return numerodigitado;
}
int main(){
    int retorno = exibemenu();
    while (retorno != 0){
        switch (retorno)
        {
        case 0:
            printf("Voce encerrou o sistema\n");
            break;
        
        case 1:
            adicionacontato();
            printf("Nomes");
            printf("\n");
            printaosnomes();
            printf("\n");
            printf("Sobrenomes");
            printf("\n");
            printaossobrenomes();
            printf("\n");
            printf("Numeros");
            printf("\n");
            printaosnumeros();
            printf("\n");
            printf("Cadastro feito!");
            printf("\n");
            printf("sdfd");

        default:
            break;
        }
        retorno = exibemenu();
    }
    return 0;
}