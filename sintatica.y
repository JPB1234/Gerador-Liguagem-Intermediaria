%{
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>

#define YYSTYPE atributos

using namespace std;

struct atributos
{
	string label;
	string traducao;
	string tipo;
};


typedef struct
{
	string nomeVal;
	string tempName;
	string tipoVal;

} TIPO_SIMBOLO;


vector<atributos> tabela_de_temporarias;
int escopo = 0;
std::vector<std::list<TIPO_SIMBOLO>> pilha_de_simbolos;

list<TIPO_SIMBOLO> novaTabela()
{
	std::list<TIPO_SIMBOLO> nova_tabela;
	return nova_tabela;
}

void printVals(){ 

	for (const std::list<TIPO_SIMBOLO>& lista : pilha_de_simbolos) {
		for (const TIPO_SIMBOLO& index : lista) {
			if (index.tipoVal == "bool") {
				if (empty(index.tempName)) {
					cout << "\t" << "int" << " " << index.nomeVal << ";" << endl;
				} else {
					cout << "\t" << "int" << " " << index.tempName << ";" << endl;
				}
			} else {
				if (empty(index.tempName)) {
					cout << "\t" << index.tipoVal << " " << index.nomeVal << ";" << endl;
				} else {
					cout << "\t" << index.tipoVal << " " << index.tempName << ";" << endl;
				}
			}
		}
}
	
}

int contador = 0;
string genLabel(){

	stringstream ss;
	ss <<"temp" << contador++;
	return ss.str(); 
}




int yylex(void);
void yyerror(string);
%}



%token TK_INT TK_FLOAT TK_CHAR TK_STRING TK_BOOLEAN
%token TK_MAIN TK_ID TK_TIPO_INT TK_TIPO_FLOAT TK_TIPO_CHAR TK_TIPO_STRING TK_TIPO_BOOLEAN
%token TK_OPERADORES
%token TK_CONV_FLOAT TK_CONV_INT
%token TK_AND TK_OR
%token TK_REL_IGUALD TK_REL_MAIOR TK_REL_MENOR TK_REL_DIF
%token TK_IF TK_ELSE TK_FOR TK_WHILE
%token TK_FIM TK_ERROR 

%start S


%left '+'
%left '-'
%right '*'
%right '/'

%left TK_OR
%left TK_AND
%right '>'
%right '<'
%right TK_REL_IGUALD
%right TK_REL_MAIOR
%right TK_REL_MENOR
%right TK_REL_DIF




%%

S 			: TK_TIPO_INT TK_MAIN '(' ')' BLOCO
			{
				cout << "/*Compilador FOCA*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\nint main(void)\n{\n" << endl; 
				printVals();
				cout << $5.traducao << "\t\n	return 0;\n}" << endl; 	
				
				}
			;

BLOCO		: '{' INICIO COMANDOS '}'
			{
		
				$$.traducao = $3.traducao;
				
				
			
			}
			;
INICIO		:{
				std::list<TIPO_SIMBOLO> newTabela;
				TIPO_SIMBOLO teste;
				if(!pilha_de_simbolos.empty())
				{
					escopo++;
				}
			
				pilha_de_simbolos.push_back(newTabela);
				
				

			}
FIM   		:{
				pilha_de_simbolos.pop_back();
			}

COMANDOS	: COMANDO COMANDOS
			{
				$$.traducao = $1.traducao + $2.traducao;

				
			}
			|
			{
				$$.traducao = "";
			}
			;

COMANDO 	: E ';'
			| BLOCO
			| TK_TIPO_INT TK_ID ';'
			{
				cout << "Teste de escopo" << endl;
				for (const std::list<TIPO_SIMBOLO>& lista : pilha_de_simbolos) {
					for (const TIPO_SIMBOLO& index : lista) {
						cout <<"llllllll" << endl;
						cout << $2.label << endl;
						if(index.nomeVal == $2.label){
							yyerror("Variavel já declarada (TK_TIPO_INT)");
						}
					}
				}
				cout << "Fim do teste de escopo" << endl;
				TIPO_SIMBOLO valor;
				valor.nomeVal = $2.label;
				valor.tempName = genLabel();
				valor.tipoVal = "int";
				

				$$.traducao = "";
				pilha_de_simbolos[escopo].push_back(valor);
			}

			|TK_TIPO_FLOAT TK_ID ';'
			{
				for(const TIPO_SIMBOLO& index : pilha_de_simbolos[escopo]){
					
					if(index.nomeVal == $2.label){
						yyerror("Variavel já declarada (TK_TIPO_FLOAT)");
					}
				}

				TIPO_SIMBOLO valor;
				valor.nomeVal = $2.label;
				valor.tempName = genLabel();
				valor.tipoVal = "float";

				$$.traducao = "";
				pilha_de_simbolos[escopo].push_back(valor);
			}
			|TK_TIPO_CHAR TK_ID ';'
			{
				for(const TIPO_SIMBOLO& index : pilha_de_simbolos[escopo]){
					
					if(index.nomeVal == $2.label){
						yyerror("Variavel já declarada (TK_TIPO_CHAR)");
					}
				}

				TIPO_SIMBOLO valor;
				valor.nomeVal = $2.label;
				valor.tempName = genLabel();
				valor.tipoVal = "char";

				$$.traducao = "";
				pilha_de_simbolos[escopo].push_back(valor);
			}
			|TK_TIPO_BOOLEAN TK_ID ';'
			{
				for(const TIPO_SIMBOLO& index : pilha_de_simbolos[escopo]){
					
					if(index.nomeVal == $2.label){
						yyerror("Variavel já declarada (TK_TIPO_BOOLEAN)");
					}
				}

				TIPO_SIMBOLO valor;
				valor.nomeVal = $2.label;
				valor.tempName = genLabel();
				valor.tipoVal = "bool";

				$$.traducao = "";
				pilha_de_simbolos[escopo].push_back(valor);
			}
			|TK_TIPO_STRING TK_ID ';'
			{
				for(const TIPO_SIMBOLO& index : pilha_de_simbolos[escopo]){
					
					if(index.nomeVal == $2.label){
						yyerror("Variavel já declarada (TK_TIPO_STRING)");
					}
				}

				TIPO_SIMBOLO valor;
				valor.nomeVal = $2.label;
				valor.tempName = genLabel();
				valor.tipoVal = "string";

				$$.traducao = "";
				pilha_de_simbolos[escopo].push_back(valor);
			}
			|TK_IF '(' E ')' '{'  E  '}' ';'
			{

			}

			|TK_IF '(' E ')' '{' E '}' TK_ELSE '{' E '}' ';'
			{

			}

			;		
			
			// Operadoções aritmeticas
E 			: E '*' E
			{
				int convTest = 0;
				if($1.tipo != $3.tipo){
					if($1.tipo == "float" && $3.tipo == "int"){
						$3.tipo = "float";
						convTest = 1;

					}
					else if($3.tipo == "float" && $1.tipo == "int"){
						$1.tipo = "float";
						convTest = 2;
					}
					else{yyerror("Variaveis de tipos diferentes (Operação '*')");}
				}

				$$.tipo = $3.tipo;
				string label = genLabel();
				if(convTest == 1){
					$$.traducao = $3.traducao + "\t" + label +" = "+ $1.label +" * " + "(float)" +$3.label + ";\n";
				}
				else if(convTest == 2){
					$$.traducao = $3.traducao + "\t" + label +" = "+ "(float)" + $1.label +" * "+$3.label + ";\n";
				}
				else{
					$$.traducao = $3.traducao + "\t" + label +" = " + $1.label +" * "+$3.label + ";\n";
				}
				$$.label = label;

				TIPO_SIMBOLO valor;
				valor.nomeVal = $$.label;
				valor.tipoVal = $$.tipo;

				
				pilha_de_simbolos[escopo].push_back(valor);
			}
E 			: E '/' E
			{
				int convTest = 0;
				if($1.tipo != $3.tipo){
					if($1.tipo == "float" && $3.tipo == "int"){
						$3.tipo = "float";
						convTest = 1;

					}
					else if($3.tipo == "float" && $1.tipo == "int"){
						$1.tipo = "float";
						convTest = 2;
					}
					else{yyerror("Variaveis de tipos diferentes (Operação '/')");}
				}

				
				$$.tipo = $3.tipo;
				string label = genLabel();
				if(convTest == 1){
					$$.traducao =  $3.traducao + "\t" + label +" = "+ $1.label +" / " + "(float)" +$3.label + ";\n";
				}
				else if(convTest == 2){
					$$.traducao =  $3.traducao + "\t" + label +" = "+ "(float)" + $1.label +" / "+$3.label + ";\n";
				}
				else{
					$$.traducao = $3.traducao + "\t" + label +" = " + $1.label +" / "+$3.label + ";\n";
				}
				$$.label = label;

				TIPO_SIMBOLO valor;
				valor.nomeVal = $$.label;
				valor.tipoVal = $$.tipo;

				
				pilha_de_simbolos[escopo].push_back(valor);
			}
E 			: E '+' E
			{
				int convTest = 0;
				if($1.tipo != $3.tipo){
					if($1.tipo == "float" && $3.tipo == "int"){
						$3.tipo = "float";
						convTest = 1;

					}
					else if($3.tipo == "float" && $1.tipo == "int"){
						$1.tipo = "float";
						convTest = 2;
					}
					else{yyerror("Variaveis de tipos diferentes (Operação '+')");}
				}

				
				$$.tipo = $3.tipo;
				string label = genLabel();
				if(convTest == 1){
					$$.traducao =  $3.traducao + "\t" + label +" = "+ $1.label +" + " + "(float)" +$3.label + ";\n";
				}
				else if(convTest == 2){
					$$.traducao = $3.traducao + "\t" + label +" = "+ "(float)" + $1.label +" + "+$3.label + ";\n";
				}
				else{
					$$.traducao =  $3.traducao + "\t" + label +" = " + $1.label +" + "+$3.label + ";\n";
				}
				$$.label = label;

				TIPO_SIMBOLO valor;
				valor.nomeVal = $$.label;
				valor.tipoVal = $$.tipo;

				
				pilha_de_simbolos[escopo].push_back(valor);
				
			}
E 			: E '-' E
			{
				int convTest = 0;
				if($1.tipo != $3.tipo){
					if($1.tipo == "float" && $3.tipo == "int"){
						$3.tipo = "float";
						convTest = 1;

					}
					else if($3.tipo == "float" && $1.tipo == "int"){
						$1.tipo = "float";
						convTest = 2;
					}
					else{yyerror("Variaveis de tipos diferentes (Operação '-')");}
				}

				
				$$.tipo = $3.tipo;
				string label = genLabel();
				if(convTest == 1){
					$$.traducao =  $3.traducao + "\t" + label +" = "+ $1.label +" - "+ "(float)" +$3.label + ";\n";
				}
				else if(convTest == 2){
					$$.traducao =  $3.traducao + "\t" + label +" = "+ "(float)" + $1.label +" - "+$3.label + ";\n";
				}
				else{
					$$.traducao =  $3.traducao + "\t" + label +" = " + $1.label +" - "+$3.label + ";\n";
				}
				$$.label = label;

				TIPO_SIMBOLO valor;
				valor.nomeVal = $$.label;
				valor.tipoVal = $$.tipo;

				
				pilha_de_simbolos[escopo].push_back(valor);
			}

			//Operações relacionais
E 			: E '>' E
			{
				int convTest = 0;
				if($1.tipo != $3.tipo){
					if($1.tipo == "float" && $3.tipo == "int"){
						$3.tipo = "float";
						convTest = 1;

					}
					else if($3.tipo == "float" && $1.tipo == "int"){
						$1.tipo = "float";
						convTest = 2;
					}
					else{
						yyerror("Variaveis de tipos diferentes, que nao suportao convercao (Operação '>')");
					}
				}

				
				string label = genLabel();
				
				if(convTest == 1){
					$$.traducao =  $3.traducao + "\t" + label +" = "+ $1.label +" > "+ "(float)" +$3.label + ";\n";
				}
				else if(convTest == 2){
					$$.traducao =  $3.traducao + "\t" + label +" = "+ "(float)" + $1.label +" > "+$3.label + ";\n";
				}
				else{
					$$.traducao =  $3.traducao + "\t" + label +" = " + $1.label +" > "+$3.label + ";\n";
				}

				$$.label = label;

				TIPO_SIMBOLO valor;
				valor.nomeVal = $$.label;
				valor.tipoVal = $$.tipo;
				$$.tipo = "bool";

				cout << valor.nomeVal << endl;
				cout << valor.tipoVal << endl;
				
				pilha_de_simbolos[escopo].push_back(valor);
			}

E 			: E '<' E
			{
				int convTest = 0;
				if($1.tipo != $3.tipo){
					if($1.tipo == "float" && $3.tipo == "int"){
						$3.tipo = "float";
						convTest = 1;

					}
					else if($3.tipo == "float" && $1.tipo == "int"){
						$1.tipo = "float";
						convTest = 2;
					}
					else{
						yyerror("Variaveis de tipos diferentes, que nao suportao convercao (Operação '<')");
					}
				}

				
	
				string label = genLabel();
				
				if(convTest == 1){
					$$.traducao =  $3.traducao + "\t" + label +" = "+ $1.label +" < "+ "(float)" +$3.label + ";\n";
				}
				else if(convTest == 2){
					$$.traducao =  $3.traducao + "\t" + label +" = "+ "(float)" + $1.label +" < "+$3.label + ";\n";
				}
				else{
					$$.traducao =  $3.traducao + "\t" + label +" = " + $1.label +" < "+$3.label + ";\n";
				}

				$$.label = label;

				TIPO_SIMBOLO valor;
				valor.nomeVal = $$.label;
				valor.tipoVal = $$.tipo;
				$$.tipo = "bool";

				cout << valor.nomeVal << endl;
				cout << valor.tipoVal << endl;
				
				pilha_de_simbolos[escopo].push_back(valor);
			}

			
E 			: E TK_REL_IGUALD E
			{
				int convTest = 0;
				if($1.tipo != $3.tipo){
					if($1.tipo == "float" && $3.tipo == "int"){
						$3.tipo = "float";
						convTest = 1;

					}
					else if($3.tipo == "float" && $1.tipo == "int"){
						$1.tipo = "float";
						convTest = 2;
					}
					else{
						yyerror("Variaveis de tipos diferentes, que nao suportao convercao (Operação '==')");
					}
				}

				
			
				string label = genLabel();
				
				if(convTest == 1){
					$$.traducao =  $3.traducao + "\t" + label +" = "+ $1.label +" == "+ "(float)" +$3.label + ";\n";
				}
				else if(convTest == 2){
					$$.traducao =  $3.traducao + "\t" + label +" = "+ "(float)" + $1.label +" == "+$3.label + ";\n";
				}
				else{
					$$.traducao =  $3.traducao + "\t" + label +" = " + $1.label +" == "+$3.label + ";\n";
				}

				$$.label = label;

				TIPO_SIMBOLO valor;
				valor.nomeVal = $$.label;
				valor.tipoVal = $$.tipo;
				$$.tipo = "bool";

				cout << valor.nomeVal << endl;
				cout << valor.tipoVal << endl;
				
				pilha_de_simbolos[escopo].push_back(valor);
			}
E 			: E TK_REL_DIF E
			{
				int convTest = 0;
				if($1.tipo != $3.tipo){
					if($1.tipo == "float" && $3.tipo == "int"){
						$3.tipo = "float";
						convTest = 1;

					}
					else if($3.tipo == "float" && $1.tipo == "int"){
						$1.tipo = "float";
						convTest = 2;
					}
					else{
						yyerror("Variaveis de tipos diferentes, que nao suportao convercao (Operação '!=')");
					}
				}

				
				
				string label = genLabel();
				
				if(convTest == 1){
					$$.traducao =  $3.traducao + "\t" + label +" = "+ $1.label +" != "+ "(float)" +$3.label + ";\n";
				}
				else if(convTest == 2){
					$$.traducao =  $3.traducao + "\t" + label +" = "+ "(float)" + $1.label +" != "+$3.label + ";\n";
				}
				else{
					$$.traducao =  $3.traducao + "\t" + label +" = " + $1.label +" != "+$3.label + ";\n";
				}

				$$.label = label;

				TIPO_SIMBOLO valor;
				valor.nomeVal = $$.label;
				valor.tipoVal = $$.tipo;
				$$.tipo = "bool";

				cout << valor.nomeVal << endl;
				cout << valor.tipoVal << endl;
				
				pilha_de_simbolos[escopo].push_back(valor);
			}
E 			: E TK_REL_MAIOR E
			{
				int convTest = 0;
				if($1.tipo != $3.tipo){
					if($1.tipo == "float" && $3.tipo == "int"){
						$3.tipo = "float";
						convTest = 1;

					}
					else if($3.tipo == "float" && $1.tipo == "int"){
						$1.tipo = "float";
						convTest = 2;
					}
					else{
						yyerror("Variaveis de tipos diferentes, que nao suportao convercao (Operação '>=')");
					}
				}

				
			
				string label = genLabel();
				
				if(convTest == 1){
					$$.traducao =  $3.traducao + "\t" + label +" = "+ $1.label +" >= "+ "(float)" +$3.label + ";\n";
				}
				else if(convTest == 2){
					$$.traducao =  $3.traducao + "\t" + label +" = "+ "(float)" + $1.label +" >= "+$3.label + ";\n";
				}
				else{
					$$.traducao =  $3.traducao + "\t" + label +" = " + $1.label +" >= "+$3.label + ";\n";
				}

				$$.label = label;

				TIPO_SIMBOLO valor;
				valor.nomeVal = $$.label;
				valor.tipoVal = $$.tipo;
				$$.tipo = "bool";
				

				cout << valor.nomeVal << endl;
				cout << valor.tipoVal << endl;
				
				pilha_de_simbolos[escopo].push_back(valor);
			}
E 			: E TK_REL_MENOR E
			{
				int convTest = 0;
				if($1.tipo != $3.tipo){
					if($1.tipo == "float" && $3.tipo == "int"){
						$3.tipo = "float";
						convTest = 1;

					}
					else if($3.tipo == "float" && $1.tipo == "int"){
						$1.tipo = "float";
						convTest = 2;
					}
					else{
						yyerror("Variaveis de tipos diferentes, que nao suportao convercao (Operação '<=')");
					}
				}

				
				
				string label = genLabel();
				
				if(convTest == 1){
					$$.traducao =  $3.traducao + "\t" + label +" = "+ $1.label +" <= "+ "(float)" +$3.label + ";\n";
				}
				else if(convTest == 2){
					$$.traducao =  $3.traducao + "\t" + label +" = "+ "(float)" + $1.label +" <= "+$3.label + ";\n";
				}
				else{
					$$.traducao =  $3.traducao + "\t" + label +" = " + $1.label +" <= "+$3.label + ";\n";
				}

				$$.label = label;

				TIPO_SIMBOLO valor;
				valor.nomeVal = $$.label;
				valor.tipoVal = $$.tipo;
				$$.tipo = "bool";

				cout << valor.nomeVal << endl;
				cout << valor.tipoVal << endl;
				
				pilha_de_simbolos[escopo].push_back(valor);
			}
			
			//Operação de logica
E 			: E TK_OR E
			{
				int convTest = 0;
				if($1.tipo != $3.tipo){
					if($1.tipo == "float" && $3.tipo == "int"){
						$3.tipo = "float";
						convTest = 1;

					}
					else if($3.tipo == "float" && $1.tipo == "int"){
						$1.tipo = "float";
						convTest = 2;
					}
					else{yyerror("Variaveis de tipos diferentes (Operação '||')");}
				}
				
		
				string label = genLabel();
				if(convTest == 1){
					$$.traducao =  $3.traducao + "\t" + label +" = "+ $1.label +" || " + "(float)" +$3.label + ";\n";
				}
				else if(convTest == 2){
					$$.traducao =  $3.traducao + "\t" + label +" = "+ "(float)" + $1.label +" || "+$3.label + ";\n";
				}
				else{
					$$.traducao =  $3.traducao + "\t" + label +" = " + $1.label +" || "+$3.label + ";\n";
				}
				$$.label = label;

				TIPO_SIMBOLO valor;
				valor.nomeVal = $$.label;
				valor.tipoVal = $$.tipo;

				
				pilha_de_simbolos[escopo].push_back(valor);
			}

E 			: E TK_AND E
			{
				int convTest = 0;
				if($1.tipo != $3.tipo){
					if($1.tipo == "float" && $3.tipo == "int"){
						$3.tipo = "float";
						convTest = 1;

					}
					else if($3.tipo == "float" && $1.tipo == "int"){
						$1.tipo = "float";
						convTest = 2;
					}
					else{yyerror("Variaveis de tipos diferentes (Operação '&&')");}
				}

				
				
				string label = genLabel();
				if(convTest == 1){
					$$.traducao =  $3.traducao + "\t" + label +" = "+ $1.label +" && " + "(float)" +$3.label + ";\n";
				}
				else if(convTest == 2){
					$$.traducao =  $3.traducao + "\t" + label +" = "+ "(float)" + $1.label +" && "+$3.label + ";\n";
				}
				else{
					$$.traducao =  $3.traducao + "\t" + label +" = " + $1.label +" && "+$3.label + ";\n";
				}
				$$.label = label;

				TIPO_SIMBOLO valor;
				valor.nomeVal = $$.label;
				valor.tipoVal = $$.tipo;

			}

			//Atribuição
			| TK_ID '=' E
			{
				bool missing = false;
				TIPO_SIMBOLO val;
				
				
				for (const std::list<TIPO_SIMBOLO>& lista : pilha_de_simbolos) {
					for (const TIPO_SIMBOLO& index : lista) {
						if(index.nomeVal == $$.label){
						val = index;
						missing = true;

						}
					}
				}
				if(!missing){
					yyerror("Variavel não declarada");
				}
				$1.label = val.tempName;
				$1.tipo = val.tipoVal;
				
				cout << $1.tipo << endl;
				cout << val.tempName << endl;
				cout << $3.tipo << endl;


				if($1.tipo != $3.tipo){
					if($$.tipo == "float" && $3.tipo == "int"){
						$3.tipo = "float";
						$$.traducao =  $3.traducao + "\t"+ $$.label + " = " + "(float)" +$3.label + ";\n";
					}
					else{
						yyerror("Variaveis de tipos diferentes (Operação '=') ");
					}
				}
				else
				{

					$$.traducao =  $3.traducao + "\t"+ $1.label + " = " + $3.label + ";\n";
				}
				
			}
			| TK_CONV_FLOAT TK_INT
			{
				$$.tipo = "float";
				string label = genLabel();
				$$.traducao = "\t" +label+ " = "  + "(float)" + $2.traducao + ";\n";
				$$.label = label;

				/*coloca na lista a temporaria*/

				TIPO_SIMBOLO valor;
				valor.nomeVal = $$.label;
				valor.tipoVal = "float";

				
				pilha_de_simbolos[escopo].push_back(valor);
			}
			| TK_CONV_FLOAT TK_INT
			{
				$$.tipo = "int";
				string label = genLabel();
				$$.traducao = "\t" +label+ " = "  + "(int)" + $2.traducao + ";\n";
				$$.label = label;

				/*coloca na lista a temporaria*/

				TIPO_SIMBOLO valor;
				valor.nomeVal = $$.label;
				valor.tipoVal = "int";

				
				pilha_de_simbolos[escopo].push_back(valor);
			}
			| TK_INT
			{
				$$.tipo = "int";
				string label = genLabel();
				$$.traducao = "\t"+label+ " = "  + $1.traducao + ";\n";
				$$.label = label;

				/*coloca na lista a temporaria*/

				TIPO_SIMBOLO valor;
				valor.nomeVal = $$.label;
				valor.tipoVal = "int";

				
				pilha_de_simbolos[escopo].push_back(valor);
			}
			| TK_FLOAT
			{
				$$.tipo = "float";
				string label = genLabel();
				$$.traducao = "\t"+label+ " = "  + $1.traducao + ";\n";
				$$.label = label;

				/*coloca na lista a temporaria*/

				TIPO_SIMBOLO valor;
				valor.nomeVal = $$.label;
				valor.tipoVal = "float";

				
				pilha_de_simbolos[escopo].push_back(valor);

		

			}
			| TK_CHAR
			{
				$$.tipo = "char";
				string label = genLabel();
				$$.traducao = "\t" +label+ " = "  + $1.traducao + ";\n";
				$$.label = label;

				/*coloca na lista a temporaria*/

				TIPO_SIMBOLO valor;
				valor.nomeVal = $$.label;
				valor.tipoVal = "char";

				
				pilha_de_simbolos[escopo].push_back(valor);

			}
			| TK_STRING
			{
				$$.tipo = "string";
				string label = genLabel();
				$$.traducao = "\t" +label+ " = "  + $1.traducao + ";\n";
				$$.label = label;

				/* Erro de double free quando se é colocado a tabela de simbolos aqui*/
				

	
			}
			| TK_BOOLEAN
			{
				$$.tipo = "bool";
				string label = genLabel();

				if($1.traducao == "true"){
					$1.traducao = "1";
				}
				else{
					$1.traducao = "0";
				}
				$$.traducao = "\t" +label+ " = "  + $1.traducao + ";\n";
				$$.label = label;

				TIPO_SIMBOLO valor;

				valor.nomeVal = $$.label;
				valor.tipoVal = "bool";

				
				pilha_de_simbolos[escopo].push_back(valor);
	
			}

			| TK_ID
			{
				bool missing = false;
				TIPO_SIMBOLO val;
				
				for (const std::list<TIPO_SIMBOLO>& lista : pilha_de_simbolos) {
					for (const TIPO_SIMBOLO& index : lista) {
						if(index.nomeVal == $$.label){
						val = index;
						missing = true;

						}
					}
				}
				if(!missing){
					yyerror("Variavel não declarada");
				}
				$$.label = val.tempName;
				$$.tipo = val.tipoVal;
				$1.label = val.tempName;
				
				
				$$.traducao = "\t" + $$.label +" = " + $1.label + ";\n";
			}
			;

%%

#include "lex.yy.c"

int yyparse();

int main( int argc, char* argv[] )
{
	
	yyparse();
	
	return 0;
}

void yyerror( string MSG )
{
	cout << MSG << endl;
	exit (0);
}				
