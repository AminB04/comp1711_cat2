
//1
// #include <stdio.h>

// int main()
// {
//     printf (" Hello world \n. ");
//     return 0;
// }


//2
// #include <stdio.h>

// int main()
// {
//     float a;
//     float b;
//     float c;
//     printf ("Enter your first digit: \n ");
//     scanf ("%f", &a);
//     printf ("Enter your second digit: \n ");
//     scanf ("%f",&b);
//     c = a+b;
//     printf ("The sum of your 2 numbers is %f",c);

//     return 0;
// }


//3

// #include<stdio.h>
// int main() {
//     int intType;
//     float floatType;
//     double doubleType;
//     char charType;

//     // sizeof evaluates the size of a variable
//     printf("Size of int: %zu bytes\n", sizeof(intType));
//     printf("Size of float: %zu bytes\n", sizeof(floatType));
//     printf("Size of double: %zu bytes\n", sizeof(doubleType));
//     printf("Size of char: %zu byte\n", sizeof(charType));
    
//     return 0;
// }



//4


// #include <stdio.h>

// int main()
// {
//     float r;
//     float a;
//     printf ("What is the radius of your circle? \n");
//     scanf ("%f", & r);
//     a = 3.14*r*r;
//     printf ("The area of your circle is %f", a);
    
//     return 0;
// }


//5

// #include <stdio.h>

// int main()
// {
//     float a;
//     float b;
//     float c;
//     printf ("What do you want your first value to be? \n");
//     scanf ("%f", & a);
//     printf ("What do you want your second value to be? \n");
//     scanf ("%f", & b);
//     c = a;
//     a = b;
//     b = c;
//     printf ("Your first value is now %f and your second value is now %f", a, b);
//     return 0;
// }


//6

// #include <stdio.h>

// int main()
// {
//     int a;
//     printf ("Please enter a number:\n");
//     scanf ("%d", & a);
//     if (a % 2 == 0)
//         printf ("%d is an even number", a);
//     else
//         printf ("%d is an odd number", a);
    
//     return 0;
// }


//7

// #include <stdio.h>

// int main ()
// {
//     int a;
//     int b;
//     printf ("What is the temperature in fahrenheit?\n");
//     scanf ("%d", & a);
//     b = (a-32)*5/9;
//     printf ("The temperature is %d degrees celsius", b);
    
//     return 0;
// }


//8

// #include <stdio.h>

// int main ()
// {
//     int a;
//     int b;
//     printf ("Enter a number\n");
//     scanf("%d", & a);
//     int factorial(int a) ;{
//         b = a*factorial(a-1);
//     }
//     printf ("The factorial of %d is %d", a, b);
//     return 0;
// }
