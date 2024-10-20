#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

void generateQuestion(int *num1, int *num2, char *operation);

int getCorrectAnswer(int num1, int num2, char operation);

int main() {
    
    int num1;
    int num2;
    int correctAnswer;
    int userAnswer;
    
    char operation;
    char userInput[10];
    int score = 0;
    int totalQuestions = 0;
    
    srand(time(0));
    
    printf("Welcome to the Math Quiz Game!\n\n");
    printf("Reply with q to Quit\nReply with s to Skip\n\n");
    
    while(1){
        generateQuestion(&num1, &num2, &operation);
        correctAnswer = getCorrectAnswer(num1, num2, operation);
        
        printf("What is %d %c %d? ",num1,operation, num2);
        scanf("%s", &userInput);
        
        if(tolower(userInput[0]) == 'q'){
            break;
        }
        
        if(tolower(userInput[0]) == 's'){
            printf("Skipped!\tAnswer was = %d\n", correctAnswer);
            continue;
        }
        
        userAnswer = atoi(userInput);
        
        if(userAnswer == correctAnswer){
            printf("Correct!\n");
            score++;
        }else{
            printf("Wrong!\tAnswer was = %d\n", correctAnswer);
        }
        totalQuestions++;
    }
    
    printf("You got %d out of %d Questions Correct.\nScore = %d %%",score,totalQuestions, (score * 100)/totalQuestions);
    return 0;
}

void generateQuestion(int *num1, int *num2, char *operation){
    int randomOperation = rand() % 4;
    
    *num1 = rand() % 100;
    *num2 = rand() % 100;
    
    switch(randomOperation){
        case 0: *operation = '+';
                break;
        case 1: *operation = '-';
                break;
        case 2: *operation = '*';
                break;
        case 3: *operation = '/';
                if(*num2 == 0){
                    *num2 = 1;
                }
                break;
    }
}

int getCorrectAnswer(int num1, int num2, char operation){
    switch(operation){
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': return num1 / num2;
        default: return 0;
    }
}
    
