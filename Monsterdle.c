//Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>
#include <unistd.h>
//Definitons
#define NODE struct creature
//Customer Creature
struct creature{
    char name[100];
    int challengeRating;
    char type[50];
    char size[20];
    int armorClass;
    int hitPoints;
    char alignment[50];
};

//Function Prototypes
void readFile(void);

NODE monsterdle[295];

int main()
{
    readFile();
    for(int i = 0; i < 295; i++){
        printf("Name: %s\n", monsterdle[i].name);
        printf("CR: %d\n", monsterdle[i].challengeRating);
        printf("Type: %s\n", monsterdle[i].type);
        printf("Size: %s\n", monsterdle[i].size);
        printf("AC: %d\n", monsterdle[i].armorClass);
        printf("HP: %d\n", monsterdle[i].hitPoints);
        printf("Alignment: %s\n", monsterdle[i].alignment);
    }
    int monster = rand() % 295;
    printf("%d\n", monster);
    NODE answer = monsterdle[120];
    printf("Name: %s\n", answer.name);
    printf("CR: %d\n", answer.challengeRating);
    printf("Type: %s\n", answer.type);
    printf("Size: %s\n", answer.size);
    printf("AC: %d\n", answer.armorClass);
    printf("HP: %d\n", answer.hitPoints);
    printf("Alignment: %s\n", answer.alignment);
    int counter = 0;
    NODE guess;
    int guessIndex;
    while(counter < 6){
        printf("What is your guess?\n");
        scanf("%s", guess.name);
        if(strcmp(guess.name, answer.name) == 0){
            printf("You Win!\n");
            counter = 7;
            break;
        }
        else{
            counter++;
            for(int i = 0; i < 295; i++){
                if(strcmp(guess.name, monsterdle[i].name) == 0){
                    guessIndex = i;
                    //i = 295;
                }
            }
            printf("Name: %s\n", monsterdle[guessIndex].name);
            if(strcmp(monsterdle[guessIndex].name, answer.name) == 0){
                printf("Correct\n");
            }
            else{
                printf("Incorrect\n");
            }
            printf("CR: %d\n", monsterdle[guessIndex].challengeRating);
            if(monsterdle[guessIndex].challengeRating == answer.challengeRating){
                printf("Correct\n");
            }
            else if(monsterdle[guessIndex].challengeRating >= answer.challengeRating){
                printf("Lower\n");
            }
            else{
                printf("Higher\n");
            }
            printf("Type: %s\n", monsterdle[guessIndex].type);
            if(strcmp(monsterdle[guessIndex].type, answer.type) == 0){
                printf("Correct\n");
            }
            else{
                printf("Incorrect\n");
            }
            printf("Size: %s\n", monsterdle[guessIndex].size);
            if(strcmp(monsterdle[guessIndex].size, answer.size) == 0){
                printf("Correct\n");
            }
            else{
                printf("Incorrect\n");
            }
            printf("AC: %d\n", monsterdle[guessIndex].armorClass);
            if(monsterdle[guessIndex].armorClass == answer.armorClass){
                printf("Correct\n");
            }
            else if(monsterdle[guessIndex].armorClass >= answer.armorClass){
                printf("Lower\n");
            }
            else{
                printf("Higher\n");
            }
            printf("HP: %d\n", monsterdle[guessIndex].hitPoints);
            if(monsterdle[guessIndex].hitPoints == answer.hitPoints){
                printf("Correct\n");
            }
            else if(monsterdle[guessIndex].hitPoints >= answer.hitPoints){
                printf("Lower\n");
            }
            else{
                printf("Higher\n");
            }
            printf("Alignment: %s\n", monsterdle[guessIndex].alignment);
            if(strcmp(monsterdle[guessIndex].alignment, answer.alignment) == 0){
                printf("Correct\n");
            }
            else{
                printf("Incorrect\n");
            }
        }
    }
    if(counter == 6){
        printf("You Lose!\n");
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
                break;
            case 2:
                monsterdle[i].challengeRating = atoi(tempName);
                break;
            case 3:
                strcpy(monsterdle[i].type, tempName);
                break;
            case 4:
                strcpy(monsterdle[i].size, tempName);
                break;
            case 5:
                monsterdle[i].armorClass = atoi(tempName);
                break;
            case 6:
                monsterdle[i].hitPoints = atoi(tempName);
                break;
            case 7:
                strcpy(monsterdle[i].alignment, tempName);
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
