#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMIT 400
char lista_todos_nomes[LIMIT][LIMIT];
char lista_todos_sobrenomes[LIMIT][LIMIT];
char lista_todos_numeros[LIMIT][LIMIT];

/**
* Entao, agora vamos substituir esas matrizes como uma struct pra definir a "classe", ou seja, vamos definir os dados que um contato vai ter:
*
* Ja sabemos que vc quer nome, sobrenome, numero. 
* Entao podemos tentar comecar com:
* 
* struct Contato {
*   char nome[50];
*   char sobrenome[50];
*   char telefone[20];
* }; 
*
* Viu ,simples, vc esta definindo uma "classe", um tipo. Vc esta dizendo que um Contato no seu sistema possui esses atributos.
* 
* Agora se eu quiser criar um novo contato posso fazer assim:
*
* ....
* contato novoContato; //Vc esta criando uma instancia de um tipo contato, e a variavel que guarda o seu ponteiro pra essa instancia e chamada: novoContato
*
* strcpy(novoContato.nome, "Henrique");
* strcpy(novoContato.sobrenome, "Bauer");
* strcpy(novoContato.telefone, "9987676776");
*
* Se eu quiser output no console: 
*
* printf("Nome : %s", novoContato.nome); //por ai vai...
* 
* Agora, pra guardar mais de um contanto, vc precisa declarar um array desses contatos, concorda? 
*
* La no link que te mandei -> https://www.programiz.com/c-programming/c-structures
* Tem como fazer isso, da uma olhada se consegue.
*
*
*. Se voce nao tiver tempo pra fazer isso aqui nao tem problema. Muito bem quanto as outras alteracoes! Well done! 
*/


int indice = 0;
void adicionacontato();
void alterasnomecontato();
void alterasobrenomecontato();
void alteranumerocontato();
void printnatela();
void exibemenuapagarcontato();
void buscacontato();
void exibemenualterarcontato();
int exibemenu();
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
void printnatela(){
    int i;
    for(i = 0; i < indice; i++)
    {
    printf("Nome: %s\n",lista_todos_nomes[i]);
    printf("Sobrenome: %s\n",lista_todos_sobrenomes[i]);
    printf("Numero: %s\n",lista_todos_numeros[i]);
    printf("----------------------------------\n");
    }
}
void exibemenuapagarcontato(){
    char escolhausuario[LIMIT];
    int i;
    int numeroescolhido = 0;
    char nomeescolhido[LIMIT];
    char sobrenomeescolhido[LIMIT];
    char escolhanumerocelular[LIMIT];
    printf("Voce tem certeza que quer excluir um contato?");
    printf("S ou N");
    scanf("%c",escolhausuario);
    if(escolhausuario == 'S' || escolhausuario == 's'){
        printf("Vamos excluir o contato!");
        printf("\n");
        printf("Digite 1 para procurar o contato pelo nome ou digite 2 se voce quiser procurar pelo nome");
        scanf("%d",numeroescolhido);
        if(numeroescolhido == 1){
            printf("Digite o nome da pessoa:");
            scanf("%s",nomeescolhido);
            for(i = 0; i < indice; i++){
                if(strcmp(nomeescolhido,lista_todos_nomes[i]) == 0){
                    printf("Nome encotrado!");
                    printf("\n");
                    printf("Digite o sobrenome dela: ");
                    scanf("%s",sobrenomeescolhido);
                    printf("\n");
                    if(strcmp(sobrenomeescolhido,lista_todos_sobrenomes[i]) == 0){
                        //printf("Aqui esta o dados do(a): Nome:%s\nSobrenome:%s\nNumero:%s\n",nomeescolhidobusca,sobrenomeescolhidobusca,lista_todos_numeros[i]);
                        break;
                    }
                }
            }
        }
        else if(numeroescolhido == 2){
        printf("Digite o numero da pessoa:");
        scanf("%s",escolhanumerocelular);
        for(i = 0; i < indice; i++){
            if(strcmp(escolhanumerocelular,lista_todos_numeros[i]) == 0){
                printf("Numero encontrado!");
                printf("\n");
                //printf("Aqui esta o dados do(a): Nome:%s\nSobrenome:%s\nNumero:%s\n",lista_todos_nomes[i],lista_todos_sobrenomes[i],escolhanumerocelularbusca);
                break;
            }
        }
    }
    else{
        printf("Opcao invalida");
        printf("\n");
        printf("Tente novamente");
        printf("\n");
    }
    }
    else{
        printf("Tente outra opcao entao!");
    }
}
void buscacontato(){
    int i;
    char nomeescolhidobusca[LIMIT];
    char sobrenomeescolhidobusca[LIMIT];
    int numerodigitadobusca = 0;
    char escolhanumerocelularbusca[LIMIT];
    printf("Vamos buscar o contato desejado!");
    printf("\n");
    printf("Digite 1 se voce quiser buscar o contato pelo nome ou digite 2 se quiser procurar pelo numero: ");
    scanf("%d",&numerodigitadobusca);
    if(numerodigitadobusca == 1){
        printf("Digite o nome da pessoa:");
        scanf("%s",nomeescolhidobusca);
        for(i = 0; i < indice; i++){
            if(strcmp(nomeescolhidobusca,lista_todos_nomes[i]) == 0){
                printf("Nome encotrado!");
                printf("\n");
                printf("Digite o sobrenome dela: ");
                scanf("%s",sobrenomeescolhidobusca);
                printf("\n");
                if(strcmp(sobrenomeescolhidobusca,lista_todos_sobrenomes[i]) == 0){
                    printf("Aqui esta o dados do(a): Nome:%s\nSobrenome:%s\nNumero:%s\n",nomeescolhidobusca,sobrenomeescolhidobusca,lista_todos_numeros[i]);
                    break;
                }
            }
        }
    }
    else if(numerodigitadobusca == 2){
        printf("Digite o numero da pessoa:");
        scanf("%s",escolhanumerocelularbusca);
        for(i = 0; i < indice; i++){
            if(strcmp(escolhanumerocelularbusca,lista_todos_numeros[i]) == 0){
                printf("Numero encontrado!");
                printf("\n");
                printf("Aqui esta o dados do(a): Nome:%s\nSobrenome:%s\nNumero:%s\n",lista_todos_nomes[i],lista_todos_sobrenomes[i],escolhanumerocelularbusca);
                break;
            }
        }
    }
    else{
        printf("Opcao invalida");
        printf("\n");
        printf("Tente novamente");
        printf("\n");
    }
}
void exibemenualterarcontato(){
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
                printf("Digite 1 para alterar o nome, digite 2 para alterar o sobrenome, digite 3 para alterar o numero:  ");
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
        printf("\n");
    }
}
int exibemenu(){
    int numerodigitado = 0;
    printf("Bem vindo a sua agenda\n");
    printf("------------------------------------\n");
    system("cls");
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
            printf("Cadastro feito!");
            printf("\n");
            break;
        case 2:
            exibemenualterarcontato();
            break;
        case 3:
            exibemenuapagarcontato();
            break;
        case 4:
            buscacontato();
            break;
        case 5:
            printnatela();
        default:
            break;
        }
        retorno = exibemenu();
    }
    return 0;
}
