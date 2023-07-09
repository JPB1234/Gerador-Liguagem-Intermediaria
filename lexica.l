%{
#include <string>

%}

ESPACO [ \t]
DIGITO [0-9]
LETRA [A-Za-z_]
TRUE "true"
FALSE "false"

DELIM {ESPACO}+
INT {DIGITO}+
FLOAT {DIGITO}+("."{DIGITO}+)?
CHAR \'({LETRA}|{DIGITO}+)\'
STRING \"({LETRA}|{DIGITO}+)*\"
ID {LETRA}({LETRA}|{DIGITO}+)*
BOOLEAN ({TRUE}|{FALSE})





%%

"\n"		{}

{DELIM} 	{}

"main"		{return TK_MAIN;}

"int"		{return TK_TIPO_INT;}
"float"		{return TK_TIPO_FLOAT;}
"char"		{return TK_TIPO_CHAR;}
"string"	{return TK_TIPO_STRING;}
"bool"      {return TK_TIPO_BOOLEAN;}


  
"if"  		{return TK_IF;}
"else" 		{return TK_ELSE;}
"for"	    {return TK_FOR;}
"while"     {return TK_WHILE;}


"cout"      {return TK_COUT;}
"<<"        {return TK_ESPACOS;}


[(){}[\];,]	{ return *yytext; }


[+\-*/]		{ return *yytext; }


[< >]       {return *yytext; return TK_OPERADORES;}

"<="        {return TK_REL_MENOR;}
">="        {return TK_REL_MAIOR;}
"=="        {return TK_REL_IGUALD;}
"!="        {return TK_REL_DIF;}

"||"        {return TK_OR;}
"&&"        {return TK_AND;}


"="         {return '=';}
"(float)"   {return TK_CONV_FLOAT;}
"(int)"     {return TK_CONV_INT;}


{INT}		{ yylval.traducao = yytext; return TK_INT; }
{FLOAT}		{ yylval.traducao = yytext; return TK_FLOAT; }
{CHAR}		{ yylval.traducao = yytext; return TK_CHAR; }
{STRING}	{ yylval.traducao = yytext; return TK_STRING; }
{BOOLEAN}	{ yylval.traducao = yytext; return TK_BOOLEAN; }

{ID}		{ yylval.label = yytext; return TK_ID; }

.			{ *yytext; }

%%
