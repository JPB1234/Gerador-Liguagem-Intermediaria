%{
#include <string>

%}

ESPACO [ \t]
DIGITO [0-9]
LETRA [A-Za-z_]
BOOL ["true" "false"]

DELIM {ESPACO}+
INT {DIGITO}+
FLOAT {DIGITO}+("."{DIGITO}+)?
CHAR \'({LETRA}|{DIGITO}+)\'
STRING \"({LETRA}|{DIGITO}+)*\"
ID {LETRA}({LETRA}|{DIGITO}+)*





%%

"\n"		{}

{DELIM} 	{}

"main"		{return TK_MAIN;}

"int"		{return TK_TIPO_INT;}
"float"		{return TK_TIPO_FLOAT;}
"char"		{return TK_TIPO_CHAR;}
"string"	{return TK_TIPO_STRING;}



[(){}[\];,]	{ return *yytext; }


[+\-*/]		{ return *yytext; }


[< >]       {return *yytext;}

"<="        {return TK_REL_MENOR;}
">="        {return TK_REL_MAIOR;}
"=="        {return TK_REL_IGUALD;}
"!="        {return TK_REL_DIF;}

"||"        {return TK_OR;}
"&&"        {return TK_AND;}


"="         {return '=';}
"(float)"   {return TK_CONV_FLOAT;}


{INT}		{ yylval.traducao = yytext; return TK_INT; }
{FLOAT}		{ yylval.traducao = yytext; return TK_FLOAT; }
{CHAR}		{ yylval.traducao = yytext; return TK_CHAR; }
{STRING}	{ yylval.traducao = yytext; return TK_STRING; }

{ID}		{ yylval.label = yytext; return TK_ID; }

.			{ *yytext; }

%%
