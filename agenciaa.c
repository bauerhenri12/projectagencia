#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMIT 400
char lista_todos_nomes[LIMIT][LIMIT];
char lista_todos_sobrenomes[LIMIT][LIMIT];
char lista_todos_numeros[LIMIT][LIMIT];
int indice = 0;
int verificacontato();
void adicionacontato();
void alterasnomecontato();
void alterasobrenomecontato();
void alteranumerocontato();
void printnatela();
void exibemenuapagarcontato();
void apagacontato();
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
    if(verificacontato(numerocell) == -1){
        strcpy(lista_todos_nomes[indice], nome);
        strcpy(lista_todos_sobrenomes[indice], sobrenome);
        strcpy(lista_todos_numeros[indice], numerocell);
        indice++;
    }
}
int verificacontato(char numerocell[LIMIT]){
    int i;
    for(i = 0; i < indice; i++){
        if(strcmp(numerocell,lista_todos_numeros[i]) == 0){
            printf("Numero ja esta cadastrado");
            printf("\n");
            return i;
        }
    }
    return -1;
}
void alteranomecontato(int i){
    char novonome[LIMIT];
    printf("Digite o novo nome: ");
    printf("\n");
    scanf("%s", novonome);
    strcpy(lista_todos_nomes[i], novonome);
    printf("Nome editado!!");
    printf("\n");
}
void alterasobrenomecontato(int i){
    char novosobrenome[LIMIT];
    printf("Digite o novo sobrenome: ");
    printf("\n");
    scanf("%s", novosobrenome);
    strcpy(lista_todos_sobrenomes[i], novosobrenome);
    printf("Sobrenome editado!!");
    printf("\n");
}
void alteranumerocontato(int i){
    char novonumero[LIMIT];
    printf("Digite o novo numero: ");
    printf("\n");
    scanf("%s", novonumero);
    strcpy(lista_todos_nomes[i], novonumero);
    printf("Numero editado!!");
    printf("\n");
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
    int i;
    int numeroescolhido = 0;
    char nomeescolhido[LIMIT];
    char sobrenomeescolhido[LIMIT];
    char escolhanumerocelular[LIMIT];
        printf("Vamos excluir o contato!");
        printf("\n");
        printf("Digite 1 para procurar o contato pelo nome ou digite 2 se voce quiser procurar pelo numero: ");
        scanf("%d",&numeroescolhido);
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
                        apagacontato(i);
                        break;
                    }
                    else if(strcmp(sobrenomeescolhido,lista_todos_sobrenomes[i]) != 0){
                    printf("Sobrenome nao encontrado");
                    printf("\n");
                    break;
                }
                }
                else if(strcmp(nomeescolhido,lista_todos_nomes[i]) != 0){
                    printf("Nome nao encontrado");
                    printf("\n");
                    break;
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
                apagacontato(i);
                break;
            }
            else if(strcmp(escolhanumerocelular,lista_todos_numeros[i]) != 0){
                    printf("Numero nao encontrado");
                    printf("\n");
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
void apagacontato(int i){
    int j;
    for(j = i; j <indice; j++){
        strcpy(lista_todos_nomes[j],lista_todos_nomes[j+1]);
        strcpy(lista_todos_sobrenomes[j],lista_todos_sobrenomes[j+1]);
        strcpy(lista_todos_numeros[j],lista_todos_numeros[j+1]);
    } 
    indice = indice - 1;
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
                else if(strcmp(sobrenomeescolhidobusca,lista_todos_sobrenomes[i]) != 0){
                printf("Sobrenome nao encontrado");
                printf("\n");
            }
            }
            else if(strcmp(nomeescolhidobusca,lista_todos_nomes[i]) != 0){
                printf("Nome nao encontrado");
                printf("\n");
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
            else if(strcmp(escolhanumerocelularbusca,lista_todos_numeros[i]) != 0){
                printf("Numero nao encontrado");
                printf("\n");
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
                        break;
                    case 3:
                        alteranumerocontato(i);
                    default:
                        break;
                    }
                }
                else if(strcmp(sobrenomeescolhido,lista_todos_sobrenomes[i]) != 0){
                    printf("Sobrenome nao encontrado");
                    printf("\n");
                }
            }
            else if(strcmp(nomeescolhido,lista_todos_nomes[i]) != 0){
                printf("Nome nao encontrado");
                printf("\n");
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
                        break;
                    case 3:
                        alteranumerocontato(i);
                    default:
                        break;
                    }
            }
            else if(strcmp(escolhanumerocelular,lista_todos_numeros[i]) != 0){
                printf("Numero nao encontrado");
                printf("\n");
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
    printf("Digite 9 se voce quiser encerrar o sistema\nDigite 1 se quiser adicionar um contato\nDigite 2 se voce quiser editar um contato\nDigite 3 se voce quiser apagar um contato\nDigite 4 se voce quiser buscar um contato\nDigite 5 para ver sua agenda: ");
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
            break;
        case 2:
            // perfumaria feita
            exibemenualterarcontato();
            break;
        case 3:
            //perfumaria feita
            exibemenuapagarcontato();
            break;
        case 4:
            //perfumaria feita
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
