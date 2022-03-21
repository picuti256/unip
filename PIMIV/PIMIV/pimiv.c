#import <stdio.h>
#import <stdlib.h>
#import <string.h>
#import <locale.h>
#import <time.h>

#define SIZE 30

void main(){
    setlocale(LC_ALL, "Portuguese");
    int idade;
    char login1[SIZE],senha1[SIZE];
    char login[10] = "unip";
    char senha[10] = "unip123";
    char nome[SIZE],cpf[SIZE],telefone[SIZE],email[SIZE];
    char rua[SIZE],num[SIZE],bairro[SIZE],cidade[SIZE],estado[SIZE],cep[SIZE];
    int diaN,mesN, anoN;
    int respC;
    char comorbidades[SIZE];
    int logado;
    time_t t;
    time(&t);


    struct tm*data = localtime(&t);
    int anoA = data->tm_year+1900;
    int diaA = data->tm_mday;
    int mesA = data->tm_mon+1;

    printf("========CENTRO DE SAUDE==========\n\n");

    printf("LOGIN:");
    fflush(stdin);
    gets(login1);
        if(strcmp(login1,login)==0){
            printf("SENHA: ");
            fflush(stdin);
            gets(senha1);
            if(strcmp(senha1,senha)==0){
                logado=1;
            } else{
                printf("SENHA INCORRETA");
            }
        } else{
            printf("LOGIN INCORRETO");
        }

    if(logado==1){
        system("cls");
        FILE *ponteiroCadastro;
        ponteiroCadastro=fopen("cadastro.txt", "a");
        printf("CADASTRO PACIENTE COVID-19\n");
        printf("DATA %d/%d/%d\n", diaA,mesA,anoA);
        printf("NOME DO PACIENTE:");
        fflush(stdin);
        gets(nome);
        printf("CPF DO PACIENTE:");
        fflush(stdin);
        gets(cpf);

        printf("=DATA DE NASCIMENTO DO PACIENTE=\n");
        printf("DIA:");
        fflush(stdin);
        scanf("%d", &diaN);
        printf("MES:");
        fflush(stdin);
        scanf("%d", &mesN);
        printf("ANO(AAAA):");
        fflush(stdin);
        scanf("%d", &anoN);

        printf("\n=====INFORMAR ENDEREÇO DO PACIENTE===\n");
        printf("RUA:");
        fflush(stdin);
        gets(rua);
        printf("NUMERO:");
        fflush(stdin);
        gets(num);
        printf("BAIRRO:");
        fflush(stdin);
        gets(bairro);
        printf("CIDADE:");
        fflush(stdin);
        gets(cidade);
        printf("ESTADO:");
        fflush(stdin);
        gets(estado);
        printf("CEP:");
        fflush(stdin);
        gets(cep);

        printf("E-MAIL(CASO PACIENTE NÃO TENHA, COLOCAR N/P):");
        fflush(stdin);
        gets(email);
        printf("POSSUI COMORBIDADES?(1-SIM / 2-NÃO) ");
        fflush(stdin);
        scanf("%d", &respC);


        fprintf(ponteiroCadastro, "\nCADASTRO DO PACIENTE\n");
        fprintf(ponteiroCadastro, "Nome:%s", nome);
        fprintf(ponteiroCadastro, "\nCPF:%s", cpf);
        fprintf(ponteiroCadastro, "\nData de nascimento:%d/%d/%d", diaN,mesN,anoN);
        fprintf(ponteiroCadastro, "\nEndereço:%s, %s, %s, %s, %s", rua,num,bairro,cidade,estado);
        fprintf(ponteiroCadastro, "\nCEP:%s\n",cep);
        fprintf(ponteiroCadastro, "Data do Diagnostico:%d/%d/%d\n", diaA,mesA,anoA);
        fprintf(ponteiroCadastro, "Possui comorbidades?(1-sim 2-não) :%i\n", respC);
        if(respC==1){
            printf("QUAIS COMORBIDADES ELE POSSUI?");
            fflush(stdin);
            gets(comorbidades);
        }if(respC==2){
            strcpy(comorbidades, "Não Possui");
        }
        fclose(ponteiroCadastro);

        idade=anoA-anoN;

        if(idade>=65 || respC==1){
            FILE *ponteiroRisco;
            ponteiroRisco=fopen("risco.txt", "a");
            fprintf(ponteiroRisco,"=====PACIENTE EM GRUPO DE RISCO=======\n");
            fprintf(ponteiroRisco, "NOME:%s\n", nome);
            fprintf(ponteiroRisco, "CEP:%s\n", cep);
            fprintf(ponteiroRisco, "IDADE:%d\n", idade);
            fprintf(ponteiroRisco,"COMORBIDADES:%s", comorbidades);
            fclose(ponteiroRisco);
        }

        system("pause");

    }



}
