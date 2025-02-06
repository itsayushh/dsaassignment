%{
    int keyword_count = 0;
    int identifier_count = 0;
    int operator_count = 0;
    int separator_count = 0;
    int float_count = 0;
    int integer_count = 0;
%}
%%
    "while" | "if" | "else" { 
        keyword_count++; 
        printf("Keyword: %s\n", yytext); 
    }
    
    "int" | "float" { 
        keyword_count++; 
        printf("Data type: %s\n", yytext); 
    }
    
    [a-zA-Z_][a-zA-Z0-9_]* { 
        identifier_count++; 
        printf("Identifier: %s\n", yytext); 
    }
    
    "<=" | "==" | "=" | "++" | "-" | "*" | "+" { 
        operator_count++; 
        printf("Operator: %s\n", yytext); 
    }
    
    [(){}|,;] { 
        separator_count++; 
        printf("Separator: %s\n", yytext); 
    }
    
    [0-9]*"." [0-9]+ { 
        float_count++; 
        printf("Float: %s\n", yytext); 
    }
    
    [0-9]+ { 
        integer_count++; 
        printf("Integer: %s\n", yytext); 
    }
    
    . { /* Ignore any other character */ }

%%
int main() {
    printf("Enter code for token analysis (Ctrl+D to end input):\n");
    yylex();
    printf("\nTotal Keywords: %d\n", keyword_count);
    printf("Total Identifiers: %d\n", identifier_count);
    printf("Total Operators: %d\n", operator_count);
    printf("Total Separators: %d\n", separator_count);
    printf("Total Floats: %d\n", float_count);
    printf("Total Integers: %d\n", integer_count);
    return 0;
}
