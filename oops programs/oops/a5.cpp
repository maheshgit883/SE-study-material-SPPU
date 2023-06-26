/* ASSIGNMENT NUMBER A-5
To create a simple calculator for addition, subtraction, multiplication and division using switch...case statement in C++ programming. 

BATCH:SA1
ROLL NO:
DATE:
*/

# include <iostream>
using namespace std;
int main()
{
    char o;
    float num1,num2;
    cout << "Enter operator either + or - or * or /: ";
    cin >> o;
    cout << "Enter two operands: ";
    cin >> num1 >> num2;
    switch(o) {
        case '+':
            cout << num1+num2 <<"\n";
            break;
        case '-':
            cout << num1-num2 <<"\n";
            break;
        case '*':
            cout << num1*num2 <<"\n";
            break;
        case '/':
            cout << num1/num2 <<"\n";
            break;
        default:
            /* If operator is other than +, -, * or /, error message is shown */
            cout << "Error! operator is not correct" <<"\n";
            break;
    }
    return 0;
}

/*
OUTPUT
gescoe@gescoe:~/Desktop/OOPL$ g++ a5.cpp
gescoe@gescoe:~/Desktop/OOPL$ ./a.out
Enter operator either + or - or * or /: +
Enter two operands: 10
5
15
gescoe@gescoe:~/Desktop/OOPL$ ./a.out
Enter operator either + or - or * or /: -
Enter two operands: 10 5
5
gescoe@gescoe:~/Desktop/OOPL$ ./a.out
Enter operator either + or - or * or /: *
Enter two operands: 10 5
50
gescoe@gescoe:~/Desktop/OOPL$ ./a.out
Enter operator either + or - or * or /: /  
Enter two operands: 10 3
3.33333

*/
