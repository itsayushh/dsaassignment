%{
    int positive_no = 0, negative_no = 0;  // counters for positive and negative numbers
%}

/* Rules for identifying and counting positive and negative numbers */
%%
    ^[-][0-9]+  { 
        negative_no++; 
        printf("Negative number: %s\n", yytext); 
    } // negative number

    [0-9]+  { 
        positive_no++; 
        printf("Positive number: %s\n", yytext); 
    } // positive number
%%

/*** Use code section ***/
int yywrap() {
    return 1;  // End of input, no more files to process
}

int main() {
    printf("Enter numbers (Ctrl+D to end input):\n");
    yylex();  // Start lexical analysis
    // Output the count of positive and negative numbers
    printf("Number of positive numbers: %d\n", positive_no);
    printf("Number of negative numbers: %d\n", negative_no);
    return 0;
}
