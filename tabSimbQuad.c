typedef union {
char cadeia [20];
int i;
int indiceSimb;
int indiceQuadrupla;
} YYSTYPE;
#define NADA 9999
#define FRACASSO 9998
typedef enum {
ADD,
MUL
} Operador;
struct Quadrupla {
Operador op;
int operando1;
int operando2;
int operando3;
} quadrupla [ 100 ];
int prox = 0;/* próxima quadr.
disponivel*/
typedef enum {
Variavel,
Constante,
Temporario,
Procedimento,
Funcao
} Entidade;
typedef enum {
 Alocar,
 Referenciar
} AlocarOuReferenciar;
/* 
TabSimb: 1as 50 entradas psímbolos do
fonte
e últimas 50 p/ var. temps*/
struct TabSimb {
    char nome [20];
    Entidade entidade;
    int valor;
    int identificador;
} tabSimb [100];

int indSimb, indTemp;
int topTab = 0; /*inicio simbs*/ 
int topTemp = 50;/*inicio temps*/

void gera ( Operador codop,int end1,int end2,int end3)
{
    quadrupla [prox].op = codop;
    quadrupla [prox].operando1 = end1;
    quadrupla [prox].operando2 = end2;
    quadrupla [prox].operando3 = end3;
    prox++;
}

int buscaSimbTab (YYSTYPE simb, Entidade
vOUc, AlocarOuReferenciar aOUr){
int k;
for (k = 0;k < topTab; k++) {
 switch(vOUc) {
 case Variavel:
    if (strcmp(simb.cadeia, tabSimb[k].identificador)==0)
    return (k);
    break;
 case Funcao:
    if (strcmp(simb.cadeia, tabSimb[k].identificador)==0)
    return (k);
    break;
 case Procedimento:
     if (strcmp(simb.cadeia, tabSimb[k].identificador)==0)
     return (k);
    break;
 case Constante:
if (simb.i == tabSimb[k].valor)
 return(k);
break;
 default: break;
 }; // do switch
}; // do for
if (aOUr == Alocar || vOUc == Constante)
    return (FRACASSO);
else { // variável ausente, aborta !
 if (vOUc == Variavel){
 printf("\n simbolo ausente %s\n",simb.cadeia);
 exit(0);
 }; // do if Variavel
 }; // do else
}; // da funcao
void incluiSimbTab(YYSTYPE simb,Entidade
vOUc){
int retorno;
retorno = buscaSimbTab (simb, vOUc,
Alocar);
if (retorno == FRACASSO ) {//simb deve ser incluido
    if (vOUc == Constante)
        tabSimb [topTab].valor = simb.i;//vOUc eh Constante
    else//variável,função,procedimento
        strcpy (tabSimb [topTab].nome,simb.cadeia);
tabSimb [topTab].entidade = vOUc;
retorno = topTab;
topTab++;
 } // de FRACASSO,incluido novo simbolo
int temp () {
char nomeTemporaria[4];
strcpy(nomeTemporaria, "t");//prefixo
strcat(nomeTemporaria, itoa(topTemp50)); //sufixo
strcpy(tabSimb [topTemp].nome,nomeTemporaria);
tabSimb [topTemp].entidade = Temporario;
topTemp++;
return (topTemp-1);
};
