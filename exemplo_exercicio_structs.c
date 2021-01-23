//OBJETIVO
//Guardar os dados de 3 alunos, cada aluno é caracterizado com os seguintes parametros: name, age e roll_number
//UTILIZAÇÃO DE STRUCTS

#include <stdio.h>
#include <string.h>

typedef struct student //tipo de variavel = struct, nome da struct = student.
//Tendo em conta que queremos substituir o nome da struct por algo mais simples de reutilizar, acrescentamos "typedef"
{
    int id;
    char name[20];
    int age, roll_number;
}bolacha; //alcunha da struct student. Quando for para chamar a struct student, chamamos "bolacha"


void coise(struct student arr[]);//a funcao coise() é chamada aqui apenas para ser posta depois do main()

void main(){

    int i;
    bolacha arr[3]; //a struct passa a ser um array, porque eu quero guardar cada aluno numa posicao do array
    
    for (i=0; i < 3; i++)//ciclo para guardar no array os inputs da struct. Cada posicao no arr guarda 3 inputs. Isto porque a struct acarta 3 variaveis diferentes.
    {
        printf("Nome: ");
        scanf("%s", &arr[i].name);
        printf("Idade: ");
        scanf("%d", &arr[i].age);
        printf("Roll Number:");
        scanf("%d", &arr[i].roll_number);
    }    
    coise(arr); //chamar a funcao para dar print  
}

void coise(bolacha arr[]){ //funcao para printar os outputs

    int i;
    printf("////////////////Outputs/////////////");
    for (i=0; i < 3; i++)
    {
        printf("\nNome: %s", arr[i].name);
        printf("\nIdade: %d", arr[i].age);
        printf("\nRoll Number: %d", arr[i].roll_number);
    }

}
