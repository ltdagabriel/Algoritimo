#include<stdio.h>
#include <stdlib.h>
int ano_bissexto(int x);
int dias_semana(int dd,int mm,int aaa);
long int anos_dia_semana(int aaa);

int main(){
    int dd,mm,aaa,x,s;
    printf("Digite uma data ex.17/04/1997\n");
    scanf("%d/%d/%d",&dd,&mm,&aaa);
    char *nome_mm [] = {
        "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho","Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"}
         ,*nome_s [] ={"Domingo","Segunda-Feira","Terca-Feira","Quarta-Feira","Quinta-Feira","Sexta-Feira","Sabado"};
    x=ano_bissexto(aaa);
    s=dias_semana(dd,mm,aaa);
    if (mm<1 || mm>12 || dd>31 || (mm==4 && dd>30) || (mm==6 && dd>30) || (mm==9 && dd>30) || (mm==11 && dd>30) )  /* Testa se o mes e' valido */
        printf("Erro!\n data inexistente\n");
    else if((mm==2 && dd>28 && x!=1) || (mm==2 &&dd>29))/*Teste se fevereiro tem 28 dias*/
        printf("Erro!\n data inexistente\n");
    else
        printf("%d de %s de %d,%s",dd,nome_mm[mm-1],aaa,nome_s[s-1]);

return 0;
}
int ano_bissexto(int x){
    int y,z,t,r;
    y=x%400;
	t=x%100;
    z=x%4;
    if(y==0)
        r=1;
    else if (z==0 && t!=0)
        r=1;
    else
        r=0;
    return (r);
}
int dias_semana(int dd,int mm,int aaa){
    int y,dias=0,i;
    long int z;
    y=ano_bissexto(aaa);
    int meses[]={0,31,(28+y),31,30,31,30,31,31,30,31,30,31};
        for(i=1;mm>=i;i++)
            dias=dias+meses[i-1];
    z=anos_dia_semana(aaa);
    dias=(dias+dd);
        if(aaa>2000){
            dias=dias+z;
        }
        else{
            dias=7-((-dias+z+1)%7);
        }
    dias=dias%7;
    if (dias==0)
        dias=7;
    return (dias);
}
long int anos_dia_semana(int aaa){
    int x,i;
    long int y=0;
    if (aaa>2000){
        for(i=2000;aaa-1>i;i++){
            x=ano_bissexto(i);
            y=y+365+x;
        }

    }
    else{
        for(i=2000;aaa<i;aaa++){
            x=ano_bissexto(aaa);
            y=y+365+x;
        }
    }
    return (y);
}
