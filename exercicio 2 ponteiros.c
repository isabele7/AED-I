/*Faça um programa que use uma estrutura do
tipo CD e faça a leitura de 10 cds (use um vetor
de estrutura do tipo cd). A estrutura CD deve
conter os seguintes campos:
Nome da banda
Data do lançamento do cd: dia, mês e ano
Data da contratação da empresa: dia, mês e ano
Valor do cd
Número de membros da banda
Produtora do cd
*/

#include <stdio.h> 

struct Data {
  int dia;
  int mês;
  int ano;
}

struct CD {
  char nome[50];
  struct Data Lancamento;
  struct Data Contratacao;
  float valor;
  int membros;
  char produtora[50];
}

int main(){
  int i,n;
  struct CD Bandas*;
  scanf("%d",&n);
  for(i=0,i<n;i++){
    scanf(“%d”,&Bandas[i].membros);
    scanf(“%f”,&Bandas[i].valor);
    scanf(“%s”,&Bandas[i].nome);
    scanf(“%s”,&Bandas[i].produtora);
    scanf(“%d”,&Bandas[i].Lançamento.dia);
    scanf(“%d”,&Bandas[i].Lançamento.mes);
    scanf(“%d”,&Bandas[i].Lançamento.ano);
    scanf(“%d”,&Bandas[i].Contratacao.dia);
    scanf(“%d”,&Bandas[i].Contratacao.mes);
    scanf(“%d”,&Bandas[i].Contratacao.ano);
  }
  
}
    
  
  
