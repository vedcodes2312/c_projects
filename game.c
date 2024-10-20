#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void playRound();
char getComputerChoice();
char getUserChoice();
void determineWinner(char userChoice, char computerChoice);

int main() {
    char userChoice;
    do{
        userChoice = getUserChoice();
        
        if(userChoice != 'Q'){
            char computerChoice = getComputerChoice();
            
            printf("You Chose : %c\n", userChoice);
            printf("Computer Chose : %c\n", computerChoice);
            
            determineWinner(userChoice, computerChoice);
        }
    } while(userChoice != 'Q');
    
    printf("Thank you for Playing!\n");
    return 0;
}

char getUserChoice(){
    char choice;
    printf("Choose [R - Rock, P - Paper, S - Scissors | Q - Quit the Game]\n>");
    scanf(" %c", &choice);
    return choice;
}

char getComputerChoice(){
    srand(time(0));
    int randomNumber = rand() % 3;
    
    switch(randomNumber){
        case 0: return 'R';
        case 1: return 'P';
        case 2: return 'S';
    }
    return 'R';
}


void determineWinner(char userChoice, char computerChoice){
    
    if(userChoice == computerChoice){
        printf("It is a TIE !!\n");
    }else if((userChoice == 'R' && computerChoice == 'S') || (userChoice == 'P' && computerChoice == 'R') || (userChoice == 'S' && computerChoice == 'P')){
        printf("You WIN !!\n");
    } else
{
        printf("Computer WIN !!\n");
    }
}

