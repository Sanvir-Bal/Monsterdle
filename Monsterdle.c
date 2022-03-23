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

NODE monsterdle[297];

int main()
{
    readFile();
    for(int i = 0; i < 297; i++){
        printf("Name: %s\n", monsterdle[i].name);
        printf("CR: %d\n", monsterdle[i].challengeRating);
        printf("Type: %s\n", monsterdle[i].type);
        printf("Size: %s\n", monsterdle[i].size);
        printf("AC: %d\n", monsterdle[i].armorClass);
        printf("HP: %d\n", monsterdle[i].hitPoints);
        printf("Alignment: %s\n", monsterdle[i].alignment);
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
