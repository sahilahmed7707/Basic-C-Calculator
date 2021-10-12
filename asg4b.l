%{

%}

%s q1 q2 q3 DEAD

%%

<INITIAL>1 BEGIN q1;

<INITIAL>0 BEGIN q2;

<INITIAL>[^01\n] BEGIN DEAD;

<INITIAL>\n BEGIN INITIAL; {printf("Accepted\n");}

<q1>1 BEGIN INITIAL;

<q1>0 BEGIN q3;

<q1>[^01\n] BEGIN DEAD;

<q1>\n BEGIN INITIAL; {printf("Not Accepted\n");}

<q2>1 BEGIN q3;

<q2>0 BEGIN INITIAL;

<q2>[^01\n] BEGIN DEAD;

<q2>\n BEGIN INITIAL; {printf("Not Accepted\n");}  

<q3>1 BEGIN q2;

<q3>0 BEGIN q1;

<q3>[^01\n] BEGIN DEAD;

<q3>\n BEGIN INITIAL; {printf("Not Accepted\n");}  

<DEAD>[^\n] BEGIN DEAD;

<DEAD>\n BEGIN INITIAL; {printf("Invalid\n");}  

%%
int yywrap(){}
int main()

{

   printf("Enter String\n");

   yylex();

   return 0;

}