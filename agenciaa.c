#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMIT 400

/** Aqui voce esta criando uma matriz de 400 por 400 para cada dado que quer salvar 
 *  Ou seja, imagina que vc tem o meu e o seu telefone salvo na lista, vai ficar assim: 
 * 
 * [0]['N','O','M','E'], pra simplificar aqui, vou considerar o char[400] como uma String, [0]['Nome'] {Por fins didaticos}
 * 
 * Entao vc teria: 
 * 
 * lista_todos_os_nomes[0][Lucas]
 * lista_todos_os_nomes[1][Henrique]
 * lista_todos_sobrenomes[0][Bento]
 * lista_todos_sobrenomes[1][Bauer]
 * lista_todos_numeros[0][0981789789]
 * lista_todos_numeros[1][9123123123]
 * 
 * Ve como é confuso? Vai ter que sempre manter as 3 diferentes listas sincronizadas... é lento o acesso aos dados, etc.
 * 
 * 
 * Idealmente, seria melhor ter sua database assim:
 * 
 * [0]['Lucas', 'Bento', '0981789789']
 * [1]['Henrique, 'Bauer', '9123123123']
 * ...
 * 
 * Concorda? 
 * 
 * Olha esse material aqui: https://www.programiz.com/c-programming/c-structures
 * 
 * */

char lista_todos_nomes[LIMIT][LIMIT];
char lista_todos_sobrenomes[LIMIT][LIMIT];
char lista_todos_numeros[LIMIT][LIMIT];

/**
 * Manter um indice global é um pouco arriscado vai contrar principios de programacao funcional,
 * nao funcionaria se vc melhorar seu sistema para salvar os dados em disco, por exemplo. 
 * Mas por enquanto, vamos deixar assim, depois te explico como melhorar.
*/
int indice = 0;


void printaosnomes();  //'Printa' não né? haha - printNomes() ?
void printaossobrenomes();
void printaosnumeros();
void alterasnomecontato();
void alterasobrenomecontato();
void alteranumerocontato();
void exibemenucontato();  //exibeMenuContanto - Camelcase é bem melhor de ler 
int exibemenu(); //exibeMenu()....
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
void alteranomecontato(int i){
    char novonome[LIMIT];
    printf("Digite o novo nome: ");
    scanf("%s", novonome);
    strcpy(lista_todos_nomes[i], novonome);
}
void alterasobrenomecontato(int i){
    char novosobrenome[LIMIT];
    printf("Digite o novo sobrenome: ");
    scanf("%s", novosobrenome);
    strcpy(lista_todos_sobrenomes[i], novosobrenome);
}
void alteranumerocontato(int i){
    char novonumero[LIMIT];
    printf("Digite o novo numero: ");
    scanf("%s", novonumero);
    strcpy(lista_todos_nomes[i], novonumero);
}
void exibemenucontato(){
    int i;
    char nomeescolhido[LIMIT];
    char sobrenomeescolhido[LIMIT];
    int numerodigitado = 0;
    int numerodigitado2 = 0;
    char escolhanumerocelular[LIMIT];
    printf("Vamos editar o contato!!!");
    printf("\n");
    printf("Digite 1 se voce quiser procurar o contato pelo nome ou digite 2 se quiser procurar pelo numero: ");
    scanf("%d",&numerodigitado);
    if(numerodigitado == 1){
        printf("Digite o nome da pessoa: ");
        scanf("%s",nomeescolhido);
        for(i = 0; i < indice; i++){
            if(strcmp(nomeescolhido,lista_todos_nomes[i]) == 0){
                printf("Nome encontrado");
                printf("\n");
                printf("Digite o sobrenome dela: ");
                scanf("%s",sobrenomeescolhido);
                printf("\n");
                if(strcmp(sobrenomeescolhido,lista_todos_sobrenomes[i]) == 0){
                    printf("Digite o que voce quer alterar no(a) %s %s: ",nomeescolhido,sobrenomeescolhido);
                    printf("\n");
                    printf("Digite 1 para alterar o nome, digite 2 para alterar o sobrenome, digite 3 para alterar o numero");
                    scanf("%d",&numerodigitado2);
                    switch (numerodigitado2)
                    {
                    case 1:
                        alteranomecontato(i);
                        break;
                    case 2:
                        alterasobrenomecontato(i);
                    case 3:
                        alteranumerocontato(i);
                    default:
                        break;
                    }
                }
            }
        }
    }
    else if(numerodigitado == 2){
        printf("Digite o numero do celular: ");
        scanf("%s",escolhanumerocelular);
        for(i = 0; i < indice; i++){
            if(strcmp(escolhanumerocelular,lista_todos_numeros[i]) == 0){
                printf("Numero Encontrado");
                printf("\n");
                printf("Digite o oq  voce quer mudar no(a) %s %s: ",lista_todos_nomes[i],lista_todos_sobrenomes[i]);
                printf("Digite 1 para alterar o nome, digite 2 para alterar o sobrenome, digite 3 para alterar o numero: ");
                scanf("%d",&numerodigitado2);
                 switch (numerodigitado2)
                    {
                    case 1:
                        alteranomecontato(i);
                        break;
                    case 2:
                        alterasobrenomecontato(i);
                    case 3:
                        alteranumerocontato(i);
                    default:
                        break;
                    }
            }
        }
    }else{
        printf("Opcao invalida");
        printf("\n");
        printf("Tente novamente");
    }
}
int exibemenu(){
    int numerodigitado = 0;
    printf("Bem vindo a sua agenda\n");
    printf("------------------------------------\n");
    printf("Digite 9 se voce quiser encerrar o sistema\nDigite 1 se quiser adicionar um contato\nDigite 2 se voce quiser editar um contato\nDigite 3 se voce quiser apagar um contato\nDigite 4 se voce quiser buscar um contato\nDigite 5 para ver tudo: ");
    scanf("%d",&numerodigitado);
    return numerodigitado;
}
int main(){
    int retorno = exibemenu();
    while (retorno != 0){
        switch (retorno)
        {
        case 9:
            printf("Voce encerrou o sistema");
            return 0;
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
            break;
        case 2:
            exibemenucontato();
        case 5:
/**
 * Imagina vc querendo saber o numero de alguem, da forma que esta mostrando os dados, vai ser:
 * 
 * Nomes:
 * Lucas
 * Henrique
 * Sobrenomes:
 * Bento
 * Bauer
 * Numeros:
 * 0981789789
 * 9123123123
 * 
 * Normalmente os apps listam os dados mais claramente, correto? 
 * 
 * Por exemplo: 
 * 
 * Contatos
 * 
 *  0 - Nome: Lucas Bento 
 *      Telefone: 0981789789
 * 
 *  1 - Henrique Bauer 
 *      Telefone: 9123123123
 *  Melhor? 
 * 
 * Obs: Vc pode até usar o indice como a chave para editar um contato. AO inves de pedir nome, sobrenome. 
 * Vc tem uma opcao no menu que é Buscar, por exemplo, ai vc lista os nomes que match a sua pesquisa. 
 * 
 *  
 * 
*/   
                
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
        default:
            break;
        }
        retorno = exibemenu();
    }
    
    return 0;
}
