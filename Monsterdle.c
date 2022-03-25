//Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>
#include <unistd.h>
#include<time.h>
//Definitons
#define NODE struct creature
//Customer Creature
struct creature{
    char name[100];
    int challengeRating;
    char type[50];
    char size[20];
    int sizeNumber;
    int armorClass;
    int hitPoints;
    char alignment[50];
};

//Function Prototypes
void readFile(void);
void checkGuess(char *guess);
int checkSize(int i);

NODE monsterdle[295];
NODE answer;

int main()
{
    readFile();
    time_t t;
    srand((unsigned) time(&t));
    int monster = rand() % 295;
    answer = monsterdle[monster];
    int counter = 0;
    char guess[100];
    int j;
    while(counter < 6){
        printf("What is your guess?\n");
        gets(guess);
        int i = 0;
        while(i < 296){
            if(i == 295){
                printf("Sorry that is an invalid guess. Please input a new guess\n");
                gets(guess);
                i = 0;
            }
            else if(strcmp(guess, monsterdle[i].name) == 0){
                i = 300;
            }
            i++;
        }
        j = 0;
        if(strcmp(guess, answer.name) == 0){
            printf("You Win!\n");
            counter = 7;
            break;
        }
        else{
            counter++;
            checkGuess(guess);
        }
    }
    if(counter == 6){
        printf("You Lose!\n");
        printf("The Answer Was: %s\n", answer.name);
        printf("CR: %d\n", answer.challengeRating);
        printf("Type: %s\n", answer.type);
        printf("Size: %s\n", answer.size);
        printf("AC: %d\n", answer.armorClass);
        printf("HP: %d\n", answer.hitPoints);
        printf("Alignment: %s\n", answer.alignment);
    }
}

void checkGuess(char *guess){
    int guessIndex;
    for(int i = 0; i < 295; i++){
        if(strcmp(guess, monsterdle[i].name) == 0){
            guessIndex = i;
            i = 295;
        }
    }
    printf("Name: %s ", monsterdle[guessIndex].name);
    if(strcmp(monsterdle[guessIndex].name, answer.name) == 0){
        printf("Correct\n");
    }
    else{
        printf("Incorrect\n");
    }
    printf("CR: %d ", monsterdle[guessIndex].challengeRating);
    if(monsterdle[guessIndex].challengeRating == answer.challengeRating){
        printf("Correct\n");
    }
    else if(monsterdle[guessIndex].challengeRating >= answer.challengeRating){
        printf("Lower\n");
    }
    else{
        printf("Higher\n");
    }
    printf("Type: %s ", monsterdle[guessIndex].type);
    if(strcmp(monsterdle[guessIndex].type, answer.type) == 0){
        printf("Correct\n");
    }
    else{
        printf("Incorrect\n");
    }
    printf("Size: %s ", monsterdle[guessIndex].size);
    if(monsterdle[guessIndex].sizeNumber == answer.sizeNumber){
        printf("Correct\n");
    }
    else if(monsterdle[guessIndex].sizeNumber >= answer.sizeNumber){
        printf("Lower\n");
    }
    else{
        printf("Higher\n");
    }
    printf("AC: %d ", monsterdle[guessIndex].armorClass);
    if(monsterdle[guessIndex].armorClass == answer.armorClass){
        printf("Correct\n");
    }
    else if(monsterdle[guessIndex].armorClass >= answer.armorClass){
        printf("Lower\n");
    }
    else{
        printf("Higher\n");
    }
    printf("HP: %d ", monsterdle[guessIndex].hitPoints);
    if(monsterdle[guessIndex].hitPoints == answer.hitPoints){
        printf("Correct\n");
    }
    else if(monsterdle[guessIndex].hitPoints >= answer.hitPoints){
        printf("Lower\n");
    }
    else{
        printf("Higher\n");
    }
    printf("Alignment: %s ", monsterdle[guessIndex].alignment);
    if(strcmp(monsterdle[guessIndex].alignment, answer.alignment) == 0){
        printf("Correct\n");
    }
    else{
        printf("Incorrect\n");
    }
}

void readFile(){
    int flag = 1;
    char tempName[50];
    int i = 0;
    FILE *fp;
    fp = fopen("Monsterdle.txt", "r");
    fseek(fp, 0, SEEK_SET );
    while(fscanf(fp, "%s", tempName) == 1){
        switch(flag){
            case 1:
                strcpy(monsterdle[i].name, tempName);
                int j = 0;
                while(monsterdle[i].name[j] != '\0'){
                    if(monsterdle[i].name[j] == '-'){
                        monsterdle[i].name[j] = ' ';
                    }
                    j++;
                }
                break;
            case 2:
                monsterdle[i].challengeRating = atoi(tempName);
                break;
            case 3:
                strcpy(monsterdle[i].type, tempName);
                break;
            case 4:
                strcpy(monsterdle[i].size, tempName);
                monsterdle[i].sizeNumber = checkSize(i);
                break;
            case 5:
                monsterdle[i].armorClass = atoi(tempName);
                break;
            case 6:
                monsterdle[i].hitPoints = atoi(tempName);
                break;
            case 7:
                strcpy(monsterdle[i].alignment, tempName);
                int k = 0;
                while(monsterdle[i].alignment[k] != '\0'){
                    if(monsterdle[i].alignment[k] == '-'){
                        monsterdle[i].alignment[k] = ' ';
                    }
                    k++;
                }
                break;
            default: break;
        }
        flag++;
        if(flag == 8){
            flag = 1;
            i++;
        }
    }
    fclose(fp);
}

int checkSize(int i){
        if(strcmp(monsterdle[i].size, "Tiny") == 0){
            return 1;
        }
        else if(strcmp(monsterdle[i].size, "Small") == 0){
            return 2;
        }
        else if(strcmp(monsterdle[i].size, "Medium") == 0){
            return 3;
        }
        else if(strcmp(monsterdle[i].size, "Large") == 0){
            return 4;
        }
        else if(strcmp(monsterdle[i].size, "Huge") == 0){
            return 5;
        }
        else if(strcmp(monsterdle[i].size, "Gargantuan") == 0){
            return 6;
        }
}
