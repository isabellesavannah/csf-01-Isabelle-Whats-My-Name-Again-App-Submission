#include <stdio.h>
#include <ctype.h>
#include <string.h>
int calculateLifePathNumber(char number[]) {
    int sum = 0;
    for (int i = 0; i < strlen(number); i++) {
        // Convert to number
        int digit = number[i] - '0';
        sum += digit;
    }
    while (sum > 9 && sum != 11 && sum != 22 && sum != 33) {
        int tempSum = 0;
        // Calculate the sum of digits of the current sum
        while (sum > 0) {
            tempSum += sum % 10;
            sum /= 10;
        }
        sum = tempSum;
    }
    return sum;
}
int main()
{
        char input[100];
        char firstName[50];
        char lastName[50];
        char number[10];
        int isValid; 

    printf("What is your first name and mothers maiden name? ");
    scanf("%[^\n]", input);

     for (int i = 0; input[i] != '\0'; i++) {
        input[i] = tolower(input[i]);
    }

    // get firstname
    int space_index = 0;
    while (input[space_index] != ' ' && input[space_index] != '\0') {
        firstName[space_index] = input[space_index];
        space_index++;
    }
    firstName[space_index] = '\0'; 

    // Cap first letter of firstname
    if (islower(firstName[0])) {
        firstName[0] = toupper(firstName[0]);
    }

    // Find the space, separate first and last name
    int i = space_index + 1;
    int j = 0;
    while (input[i] != '\0') {
        lastName[j] = input[i];
        i++;
        j++;
    }
    lastName[j] = '\0'; 

    // Cap first letter of the last name
    if (islower(lastName[0])) {
        lastName[0] = toupper(lastName[0]);
    }

    printf("Hi %s!\n", firstName);
    
    printf("Your name backwards is: ");
    for (int i = strlen(lastName) - 1; i >= 0; i--) {
        printf("%c", lastName[i]);
    }
    printf(" ");
   
    for (int i = strlen(firstName) - 1; i >= 0; i--) {
        printf("%c", firstName[i]);
    }
    printf("\n");
    do {
        printf("Anywho, to get to know you better what is your birthday? enter it as such mmddyyyy. for example Sept 28th 1996 would be 09281996: ");
        scanf("%s", number);

        // validate they entered 8 nums
        isValid = 1;
        if (strlen(number) != 8) {
            isValid = 0;
        }
        for (int i = 0; number[i] != '\0'; i++) {
            if (!isdigit(number[i])) {
                isValid = 0;
                break;
            }
        }

        //invalid reprompt
        if (!isValid) {
            printf("Erm, wrong format, remember mmddyyyy. Try again: \n");
        }
    } while (!isValid);

    int lifePathNumber = calculateLifePathNumber(number);

    
    printf("Your life path number is: %d\n", lifePathNumber);
    printf("Heres a link to learn about your life path number, https://www.thecut.com/article/life-path-number.html ");
    
    

    return 0;
}