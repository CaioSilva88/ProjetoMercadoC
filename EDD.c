#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <locale.h> 
#include<windows.h>
#include<ctype.h>
#define _GNU_SOURCE
#define SIZE 30

int i=0, tamanho=0, c=0, somapreco, j=0, quantd=0, aux2, k, contcarrinho;
char master[10] = "Caioallan";
char senham[5] = "12345";
char master2[10], senham2[10];


 FILE *fp;
    struct Pessoa {
   
    char log[SIZE],sen[SIZE];
    char login[100];
    char newuser[100]; 
    char snewuser[100]; 
    char resp[1];
    char senha[100]; 
    char frases[100];
    char nomes[100];
    char senhass[100];
};


    struct Pessoa pessoa[100];
   
      struct aux {
   
    char log[SIZE],sen[SIZE];
    char login[100]; 
    char newuser[100]; 
    char snewuser[100]; 
    char resp[1];
    char senha[100]; 
    char frases[100];
    char nomes[100];
    char senhass[100];
};


   struct aux auxiliar[100];
   
    struct ElementoDaPilha {
    char nome[100];
    char descricao[100];
    int topo;
    int capa;
    float *pElem;
    int quantidadeDeElementosNaPilha;
    int preco;
    int peso;
};

   struct ElementoDaPilha itens[5];
   
   struct Pilha {
    struct ElementoDaPilha itens[5];
    int topo;
    int capa;
    float *pElem;
    int quantidadeDeElementosNaPilha;
};


struct Pilha pilha[10];

 struct Carrinho {
    struct ElementoDaPilha itens[50];
    int topo;
    int capa;
    float *pElem;
    int quantidadeDeElementosNaPilha;
};


struct Carrinho carrinho[50];


void criarpilha( struct Pilha *p, int c ){ 
   p->topo = -1;
   p->capa = c;
   p->pElem = (float*) malloc (c * sizeof(float));
}


int estavazia ( struct Pilha *p ){
   if( p-> topo == -1 )
      return 1;  
   else
      return 0;   
}


int estacheia ( struct Pilha *p ){
    if (p->topo == p-> capa - 1)
        return 1;
    else
        return 0;
}


void empilhar ( struct Pilha *p, float v){
    p->topo++;
    p->pElem [p->topo] = v;
}


float desempilhar ( struct Pilha *p ){
   float aux = p->pElem [p->topo];
     p->pElem [p->topo] = 0;
      p->topo--;
      aux2=aux;
   return aux;
}


float retornatopo ( struct Pilha *p ){
   return p->pElem [p->topo];
}


float retornabase ( struct Pilha *p ){
   return p->pElem [0];
}


int vazia(int proxTopo)
 {
 return proxTopo == 0;
}


float inserir_dapilha_vetor ( struct Pilha *p,int vet[],int tam){ 
    int pivt,i;
    for(i=0;i<tam;i++){
   pivt= p->pElem [i];
   vet[i]=pivt;
}
}


float imprimir ( struct Pilha *p,int vet[],int tam){
    int pivt,i;
    printf("\nElementos da prateleira: \n");
    for(i=0;i<tam;i++){
        pivt=p->pElem[i];
        if (pivt>0 && pivt<100)
   printf("%d ",pivt);}
}


float imprimir2 ( struct Pilha *p,int vet[],int tam){ 
    int pivt,i;
    printf("\nElementos do carrinho: \n");
    for(i=0;i<tam;i++){
        pivt=p->pElem[i];
        
   printf("%d ",pivt);}
}

int elgondcont1;

struct Fila {

    int capacidade;
    float *dados;
    int primeiro;
    int ultimo;
    int nItens;
};


void criarFila( struct Fila *f, int c ) {

    f->capacidade = c;
    f->dados = (float*) malloc (f->capacidade * sizeof(float));
    f->primeiro = 0;
    f->ultimo = -1;
    f->nItens = 0;
}


void inserir(struct Fila *f, int v) {

    if(f->ultimo == f->capacidade-1)
        f->ultimo = -1;

    f->ultimo++;
    f->dados[f->ultimo] = v; 
    f->nItens++; 
}


int remover( struct Fila *f ) { 

    int temp = f->dados[f->primeiro++]; 

    if(f->primeiro == f->capacidade)
        f->primeiro = 0;

    f->nItens--;  
    return temp;
}

int estaVazia( struct Fila *f ) { 

    return (f->nItens==0);
}

int estaCheia( struct Fila *f ) { 

    return (f->nItens == f->capacidade);
}

void mostrarFila(struct Fila *f){

    int cont, i;

    for ( cont=0, i= f->primeiro; cont < f->nItens; cont++){

        printf("%.0f|",f->dados[i++]);

        if (i == f->capacidade)
            i=0;

    }
    printf("\n\n");
}





int main (){
    char *result;
    char Linha[100];
    int vet[5], count, blabla;
    blabla=1;
    char *pA ;
    
    HANDLE hConsole;
    setlocale(LC_ALL, "Portuguese");
    
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    system ("color 0F");
   
    
    for(i=0;i<10;i++){
criarpilha(&pilha[i], 5);
}


strcpy(itens[1].nome,"Toddynho");
strcpy(itens[2].nome,"Amstel");
strcpy(itens[3].nome,"Trakinas");
strcpy(itens[4].nome,"Torcida");
strcpy(itens[5].nome,"Corote");

strcpy(itens[1].descricao,"'Achocolatado'");
strcpy(itens[2].descricao,"'Cerveja'");
strcpy(itens[3].descricao,"'Bolacha'");
strcpy(itens[4].descricao,"'Salgadinho'");
strcpy(itens[5].descricao,"'Cachaça'");

itens[1].peso=100;
itens[2].peso=350;
itens[3].peso=300;
itens[4].peso=150;
itens[5].peso=500;

itens[1].preco=3;
itens[2].preco=3;
itens[3].preco=5;
itens[4].preco=10;
itens[5].preco=2;



menu:
printf("\n\t\t----------------Menu---------------");
printf("\n\n\t1.Abastecer Prateleiras");
printf("\n\n\t2.Adicionar ao carrinho");
printf("\n\n\t3.Caixa/PDV");
printf("\n\n\t0.Sair\n\n\tOpção digitada: ");


int op;
scanf("%i", &op);
switch (op){

case 1:
    
    system("CLS");
    volte:
    printf("\n\n\tOps! Somente o Usuario Master pode abastecer as prateleiras\n\n");
    printf("\n\tUsuario master: ");
    scanf("%s",&master2);

    if(strcmp(master2,"Caioallan")==0){
        
        h:
            printf("\nDigite a senha do usuario master: ");
    scanf("%s", &senham2);
        
        if(strcmp(senham2,"12345")==0){
            
            system("CLS");
            k = 6;
        SetConsoleTextAttribute(hConsole, k);
            printf("\n Bem-vindo, Caioallan");
            k = 7;
        SetConsoleTextAttribute(hConsole, k);
            
            goto w;
            
        }else if(strcmp(senham2,"12345")!=0){
            goto h;
        }
        
        
        
        
    }else if(strcmp(master,"Caioallan")!=0){
        goto volte;
    }
    
    w:
                qualpilhaa:
                    printf("\n\tQual prateleira deseja abastecer?  ");
                    int qualpilha;
                    scanf("%d",&qualpilha);
                    if (qualpilha>10){
                    printf("\nPILHA INEXISTENTE!");
                    goto qualpilhaa;}
                    else{if( estacheia( &pilha ) == 1 )
                    
                    printf("\nPILHA CHEIA! \n");
                else {
                	system("CLS");
                    printf("\nInsira o número do produto a ser empilhado (1 - 5):\n\n\t1 - Toddynho\n\t2 - Amstel\n\t3 - Trakinas\n\t4 - Torcida\n\t5 - Corote\n\n\tProduto digitado: ");
                    int itemid;
                    scanf("%d",&itemid);
                    empilhar (&pilha[qualpilha-1], itemid); }
                    inserir_dapilha_vetor(pilha,vet,5);
                        imprimir(&pilha[qualpilha-1],vet,5);
                        printf("\n\n\nDeseja continuar abastecendo? (s/n)  ");
                        scanf("%s",pessoa[0].resp);
                        if(strcmp(pessoa[0].resp,"s")==0){
                            goto qualpilhaa;}
                            else{
                            	system("CLS");
                                goto menu;
                            }}
                           break;
   
   
    case 2:
    criarpilha(&carrinho, 50);
    
	carrinho:
    printf("\n\nDeseja pegar o item de qual prateleira (1 - 10)?  ");
            
                    scanf("%d",&qualpilha);
                    if (qualpilha>10){
                    printf("\nPILHA INEXISTENTE!");
                    goto carrinho;
                }
                    else{
                        for(contcarrinho=0; contcarrinho<40; contcarrinho++){
                        desempilhar (&pilha[qualpilha-1]);
                        inserir_dapilha_vetor(pilha,vet,5);
                        imprimir(&pilha[qualpilha-1],vet,5);
                        
                        quantd++;
                        
                        empilhar (&carrinho[contcarrinho],aux2);
                        inserir_dapilha_vetor(carrinho,vet,40);
                        printf("\n");
                        imprimir2(&carrinho[contcarrinho],vet,quantd);
                        
                    printf("\n\n\nDeseja continuar pegando itens da prateleira? (s/n)  ");
                        scanf("%s",pessoa[0].resp);
                        if(strcmp(pessoa[0].resp,"s")==0){
                            goto carrinho;
                        }
                        else
                        system("CLS");
                        goto cont;
                    
                    }
                    
                    }
                    break;
                   case 3:
                   	goto y;
                   		break;
cont:
    fp = fopen("USUARIOS.DAT","r");
   
    FILE *fps; 
fps = fopen("SENHAS.DAT","r");


while ((fgets(Linha, 100, fp) != NULL)){
strcpy(pessoa[c].nomes,(Linha));
c++;
tamanho++;
}

c=0;
while ((fscanf(fps,"%s\n",pessoa[i].sen))!= EOF){

strcpy(pessoa[c].senhass,(pessoa[i].sen));
c++;
}

 
fflush(stdin);

log:
    printf("LOGIN: ");
    scanf("%100[^\n]%*c",pessoa[0].login);
 
  fclose(fp);    
  fclose(fps);
 
    fp = fopen("USUARIOS.DAT","r"); 
   

fps = fopen("SENHAS.DAT","r");

i=0;

while (fscanf(fp,"%100[^\n]%*c",pessoa[i].log)!= EOF){

          
          if (strcmp(pessoa[i].log,pessoa[0].login)==0){
                        senn:
                             
                        printf("\nSenha: ");

                        scanf("%s",pessoa[0].senha);
                     
   
            if (strcmp(pessoa[i].senhass,pessoa[0].senha)==0){
            	 k = 10;
        SetConsoleTextAttribute(hConsole, k);
                        printf("\n\nLOGADO\n\n");
                         k = 7;
        SetConsoleTextAttribute(hConsole, k);
                        system("\n\npause");
                        system("CLS");
                        k = 6;
        SetConsoleTextAttribute(hConsole, k);
                        printf("\nBem Vindo, %s",pessoa[i].log);
                        k = 7;
        SetConsoleTextAttribute(hConsole, k);
                        printf("\n\n");
                        goto passo2;
                        }
                else{
   					k = 4;
            SetConsoleTextAttribute(hConsole, k);
                    printf("\nSenha incorreta\n");
                    k = 7;
            SetConsoleTextAttribute(hConsole, k);

                    goto senn;
                    } 
            } 
            i++;
            count++;
    } 
   
printf("\nLOGIN INEXISTENTE!\n\n");
fclose(fp);
fp = fopen("USUARIOS.DAT","r");
goto log;

passo2:
    // ORDENACAO COMECA AGORA
for(j=1; j<tamanho; j++) {
        for (i=0; i<tamanho-1; i++) {
     if (strcmp(pessoa[i].nomes, pessoa[i+1].nomes) > 0) {
        
         strcpy(auxiliar[0].nomes,pessoa[i].nomes);
         strcpy(pessoa[i].nomes,pessoa[i+1].nomes);
         strcpy(pessoa[i+1].nomes,auxiliar[0].nomes);
        
         strcpy(auxiliar[0].senhass,pessoa[i].senhass);
         strcpy(pessoa[i].senhass,pessoa[i+1].senhass);
         strcpy(pessoa[i+1].senhass,auxiliar[0].senhass);
					}
				}		
			}

 fclose(fp);    
  fp = fopen("USUARIOS.DAT","w");
 
  fprintf(fp,"%s",pessoa[0].nomes);
for(i=1;i<tamanho;i++){
    fprintf(fp,"%s",pessoa[i].nomes);
}


fclose(fps);
 fps = fopen("SENHAS.DAT","w");
 
fprintf(fps,"%s",pessoa[0].senhass);
for(i=1;i<tamanho;i++){
    fprintf(fps,"\n%s",pessoa[i].senhass);
}

//printf("\nUsuarios Ordenados\n");
for (i=0;i<tamanho;i++){
   // printf("vetor posicao %d: %s %s\n",i,pessoa[i].nomes,pessoa[i].senhass);
}
    
    
    cadastrar:

  fclose(fp);
    fp = fopen("USUARIOS.DAT","a");
printf("\n\nDeseja cadastrar um Usuario? (s/n)  ");
scanf("%s",pessoa[0].resp);
//y:
if(strcmp(pessoa[0].resp,"s")==0){
    fflush(stdin);
    printf("\n\nInsira o nome do usuario que deseja cadastrar, por favor: ");
     fgets(pessoa[i+1].newuser, 100, stdin);
  
    pA = pessoa[i+1].newuser;
       strcpy(pessoa[tamanho].nomes,pessoa[i+1].newuser); 
    goto saida2;

   
    
    char *p =(char *) malloc(sizeof(char));
    if (p==NULL){
       
        printf("malloc devolveu NULL");
    }
   

    saida2:
    fclose(fp);
    fp = fopen("USUARIOS.DAT","a");
    fprintf(fp,"%s",pessoa[i+1].newuser);
   

    printf("\n\nInsira a senha de %s: ",pessoa[i+1].newuser);
    fgets(pessoa[i+1].snewuser, 100, stdin);
    printf("%s",pessoa[i+1].snewuser);
    fclose(fps);
    fps = fopen("SENHAS.DAT","a");
    strcpy(Linha,pessoa[i+1].snewuser);
    fprintf(fps,"\n%s",Linha);
    printf("%s",Linha);
    tamanho++;
    strcpy(pessoa[tamanho].senhass,(pessoa[i+1].snewuser));    
   
   
    goto saida3;

saida1:
    goto passo2;
    getch();
    return 0;
}else if(strcmp(pessoa[0].resp,"s")!=0){
	
	goto menu;
	
} 
y:

saida3:

     k = 10;
        SetConsoleTextAttribute(hConsole, k);
    printf("\n\n Concluido!\n\n");
     k = 7;
        SetConsoleTextAttribute(hConsole, k);
    system("\n\npause");
    system("CLS");
    
    
    
   
   
   
   
   
    int opcao, capafila=50;
    int valor;
    struct Fila umaFila;

    
    criarFila(&umaFila, capafila);
for(i=0;i<quantd;i++){
    desempilhar (&carrinho[contcarrinho]);
    if (estaCheia(&umaFila)){
						k = 4;
            SetConsoleTextAttribute(hConsole, k);
                    printf("\nFila Cheia!!!\n\n");
						k = 7;
            SetConsoleTextAttribute(hConsole, k);
						
                }
                else {
                
                    inserir(&umaFila,aux2);} }
                    printf("\nConteudo da fila: ");
                    mostrarFila(&umaFila);                          
                    
 
   for(i=0;i<quantd;i++)
                    {valor = remover(&umaFila);
                        
                    printf("\n\nItem %d: \n\n",i+1);
                    printf("Nome: %s\n",itens[valor].nome);
                    printf("Descricao: %s\n",itens[valor].descricao);
                    printf("Peso: %dg\n",itens[valor].peso);
                    printf("Preco: %d reais\n",itens[valor].preco);
                    
                    somapreco=somapreco+itens[valor].preco;
                    
                    }
                    printf("\nPreco total a pagar: %d reais\n\n",somapreco);
                    
                system("pause");
				system("CLS");    
                goto menu;

   
}
  
  
}





