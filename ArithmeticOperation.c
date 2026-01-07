<include stdio.h>
<include sdlib.h>
int main(){
int a, b, d;
printf("Enter two positive integers: ");
scanf(" %d, %d", &a, &b);
printf("Choose which arithmetic operation: *, -, /, +");
char operation;
scanf(" %c", operation);
if (operation == '*' || operation == '-' || operation == '/'  || operation == '+') {
    printf("Selected operation: %c\n", operation);
} else {
    printf("Error: Invalid operation chosen.\n");
}
d=result
    switch(operation) {
        case '+': 
            d=a+b
            printf("the result is: %d", d);
        break;
        case '-':
            d=a-b
            printf("the result is: %d", d);
        break;
        case '*':
            d=a*b
            printf("the result is: %d", d);
        break;
        case '/':
            d=a/b
            printf("the result is: %d", d);
        break;
    }}


