%{
%}

%s q1 q2 DEAD

%%
<INITIAL>0 BEGIN q1;
<INITIAL>1 BEGIN INITIAL;
<INITIAL>[^01\n] BEGIN DEAD;
<INITIAL>\n BEGIN INITIAL; {printf("Not Accepted\n");}

<q1>0 BEGIN q2;
<q1>1 BEGIN INITIAL;
<q1>[^01\n] BEGIN DEAD;
<q1>\n BEGIN INITIAL; {printf("Not Accepted\n");}

<q2>0 BEGIN q2;
<q2>1 BEGIN INITIAL;
<q2>[^01\n] BEGIN DEAD;
<q2>\n BEGIN INITIAL; {printf("Accepted\n");}

<DEAD>[^\n] BEGIN DEAD;
<DEAD>\n BEGIN INITIAL; {printf("Invalid\n");}

%%
int yywrap(){}
int main()
{
    printf("Enter string\n");
    yylex();
}