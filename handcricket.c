#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void instructions();
void play_game(char name[], int ch);
void toss(char name[]);
int cbat_first();
int cbat_chase(int target);
int ubat_first();
int ubat_chase(int target);
void playgame(char name[], int c);
void playbowl(char name[], int c);

char name[20];

int main(){
    int x = 0;
    while (1) {
        printf("\n\n\n******************************\n");
        printf("Welcome to Cricket using C Programming\n");
        printf("\nMenu: \n1. Instructions \n2. Play Game \n3. Exit\n ");
        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                instructions();
                break;

            case 2:
                printf("\nGame is starting....");
                // clrscr();
                printf("\t\tEnter your name: ");
                scanf("%s", name);
                toss(name);
                break;

            case 3:
                printf("\nThank you for playing");
                exit(0);
                break;

            default:
                printf("\nInvalid choice");
                exit(0);
                break;
        }
    }

    return 0;
}

void instructions(){
    printf("***Instructions***\n");
    printf("1. The game is played by two teams.\n");
    printf("2. Book cricket will be plyed without a book XD!");
    printf("3. The one who scores more runs wins the game.\n");
    printf("4. The game will be played for 4 overs.\n");
    printf("5. The game will be played in two halves.\n");
    printf("6. The first half will be played by the team batting first.\n");
    printf("7. The second half will be played by the team batting second.\n");
    printf("8. Toss will be held\n");
    printf("9. There will be 3 wickets for each side.\n");
    printf("10. Good luck!\n");
}

void toss(char name[]){
    srand(time(0));
    // clrscr();
    printf("****Toss****\n");
    printf("%s, do you want to heads or tails?\n", name);
    printf("1. Heads\n2. Tails\n");
// if the user selects 1 and the random no is even then won the toss if random no is odd then lost the toss
    int choice, random;
    random = rand() % 100;
    int ch = random % 2;
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    if(choice == 1 && ch == 0 || choice == 2 && ch == 1){
        printf("\nYou won the toss");
        int chx;
        printf("\n%s, do you want to bat or bowl?\n", name);
        printf("1. Bat\n2. Bowl\n");
        scanf("%d", &chx);
        if (chx == 1){

            // 1 = batting first | 2 = batting second & bowling first
            playgame(name, 1);
        }
        else if (chx == 2){
            printf("\nYou have chosen to bowl");
            playgame(name, 2);
        }
        else{
            printf("\nInvalid choice");
        }
    }

    else{
        printf("\nYou lost the toss");
        int xd;
        xd = rand() % 2;
        if(xd == 0){
            printf("\nComputer won the toss");
            printf("\nComputer will bat first");
            playgame("Comp", 1);
        }
        else{
            printf("\nComputer won the toss");
            printf("\nComputer will bowl first");
            playgame("Comp", 2);
        }
    }
}

int ubat_first(){
    int ch, btscore = 0;
    int target = 0;
    int wick = 3;
    printf("\n%s, you have to bat\nGood Luck", name);
    while (wick > 0){
        srand(time(0));
        int rn = (rand() % (6 - 1 + 1)) + 1;
            // Batting

        printf("\n1. 1 run\n2. 2 runs\n3. 3 runs\n4. 4 runs\n5. 5 runs\n6. 6 runs\n7. Leave\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        if(rn != ch){
            // btscore = btscore + ch+1;
            if (ch == 1){
                btscore = btscore + 1;
            }
            else if (ch == 2){
                btscore = btscore + 2;
            }
            else if (ch == 3){
                btscore = btscore + 3;
            }
            else if (ch == 4){
                btscore = btscore + 4;
            }
            else if (ch == 5){
                btscore = btscore + 5;
            }
            else if (ch == 6){
                btscore = btscore + 6;
            }
            else if (ch == 7){
                btscore = btscore + 0;
            }
            else{
                printf("\nInvalid choice\n Dot ball");
            }
            printf("\n%s, your score is %d", name, btscore);
            printf("\n%s, you have %d wicket/s left", name, wick);
        }
        else{
            printf("\n%s, Thats a wicket!", name);
            wick = wick - 1;
            printf("\n%s, you have %d wicket/s left", name, wick);
            if(wick == 0){
                return btscore;
                printf("\nTotal runs : %d", btscore);
                break;

            }
        }

    }
}

int cbat_first() {
    int comp, cmpscore = 0;
    comp = rand() % 100;
    int cmpwick = 3;
    printf("\n%s, will bowl\nGood Luck", name);
    while (cmpwick > 0){
        srand(time(0));
        int cmp = (rand() % (6 - 1 + 1)) + 1;
        // Bowling
        int ch;
        printf("\nEnter your choice which you think computer will play (1-7): ");
        scanf("%d", &ch);
        if(cmp != ch){
            // cmpscore = cmpscore + ch+1;
            if(cmp==1){
                cmpscore = cmpscore + 1;
            }
            else if(cmp==2){
                cmpscore = cmpscore + 2;
            }
            else if(cmp==3){
                cmpscore = cmpscore + 3;
            }
            else if(cmp==4){
                cmpscore = cmpscore + 4;
            }
            else if(cmp==5){
                cmpscore = cmpscore + 5;
            }
            else if(cmp==6){
                cmpscore = cmpscore + 6;
            }
            else if(cmp==7){
                cmpscore = cmpscore + 0;
            }
            else{
                printf("\nInvalid choice\n Dot ball");
            }
            printf("\nComputer's score is %d", cmpscore);
            printf("\nComputer have %d wicket/s left", cmpwick);
        }
        else{
            printf("\n%sThats a wicket!", name);
            cmpwick = cmpwick - 1;
            printf("\nComputer's score is %d", cmpscore);
            printf("\nComputer have %d wicket/s left", cmpwick);
            if(cmpwick == 0){
                return cmpscore;
                printf("\nTotal runs : %d", cmpscore);
                break;

            }
        }
    }
}

int ubat_chase(int target){
    int ch, btscore = 0;
    int wick = 3;
    printf("\n%s, you have to bat\nGood Luck", name);
    while (wick > 0 && btscore < target){
        srand(time(0));
        int rn = (rand() % (6 - 1 + 1)) + 1;
            // Batting

        printf("\n1. 1 run\n2. 2 runs\n3. 3 runs\n4. 4 runs\n5. 5 runs\n6. 6 runs\n7. Leave\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        if(rn != ch){
            // btscore = btscore + ch+1;
            if (ch == 1){
                btscore = btscore + 1;
            }
            else if (ch == 2){
                btscore = btscore + 2;
            }
            else if (ch == 3){
                btscore = btscore + 3;
            }
            else if (ch == 4){
                btscore = btscore + 4;
            }
            else if (ch == 5){
                btscore = btscore + 5;
            }
            else if (ch == 6){
                btscore = btscore + 6;
            }
            else if (ch == 7){
                btscore = btscore + 0;
            }
            else{
                printf("\nInvalid choice\n Dot ball");
            }
            printf("\n%s, your score is %d", name, btscore);
            printf("\n%s, you have %d wicket/s left", name, wick);
        }
        else{
            printf("\n%s, Thats a wicket!", name);
            wick = wick - 1;
            printf("\n%s, you have %d wicket/s left", name, wick);
        }
        if(btscore == target || btscore > target){
            printf("\n%s score is %d",name, btscore);
            printf("\n%s target was %d",name, target);
            printf("\n****%s won the game******", name);
            printf("\n----------------------------------------------------");
            break;
        }
        if (wick == 0 && btscore < target){
            printf("\n%s score is %d",name, btscore);
            printf("\n%s target was %d",name, target);
            printf("\n\n**********%s YOU LOST the match!!*************", name);
            printf("\n----------------------------------------------------");
        }
        if(wick == 4){
            printf("\n%s, thats an end of this innings", name);
            printf("\n%s, your score is %d", name, btscore);
            return btscore;
            // printf("Computer's target is %d", target);
            break;
        }
    }
}

int cbat_chase(int target) {
    int comp, cmpscore = 0;
    comp = rand() % 100;
    int cmpwick = 3;
    printf("\n%s, will bowl\nGood Luck", name);
    while (cmpwick > 0 && cmpscore < target){
        srand(time(0));
        int cmp = (rand() % (6 - 1 + 1)) + 1;
        // Bowling
        int ch;
        printf("\nEnter your choice which you think computer will play (1-7): ");
        scanf("%d", &ch);
        if(cmp != ch){
            // cmpscore = cmpscore + ch+1;
            if(cmp==1){
                cmpscore = cmpscore + 1;
            }
            else if(cmp==2){
                cmpscore = cmpscore + 2;
            }
            else if(cmp==3){
                cmpscore = cmpscore + 3;
            }
            else if(cmp==4){
                cmpscore = cmpscore + 4;
            }
            else if(cmp==5){
                cmpscore = cmpscore + 5;
            }
            else if(cmp==6){
                cmpscore = cmpscore + 6;
            }
            else if(cmp==7){
                cmpscore = cmpscore + 0;
            }
            else{
                printf("\nInvalid choice\n Dot ball");
            }
            printf("\nComputer's score is %d", cmpscore);
            printf("\nComputer have %d wicket/s left", cmpwick);
        }
        else{
            printf("\n%sThats a wicket!", name);
            cmpwick = cmpwick - 1;
            printf("\nComputer's score is %d", cmpscore);
            printf("\nComputer have %d wicket/s left", cmpwick);
        }
        if(cmpscore == target || cmpscore > target){
            printf("\nComputer's score is %d", cmpscore);
            printf("\nComputer's target was %d", target);
            printf("\n*****Computer won the game*******");
            printf("\n----------------------------------------------------");
            break;
        }
        if (cmpwick == 0 && cmpscore < target){
            printf("\n*****Computer lost the game*******");
            printf("\nComputer's score is %d", cmpscore);
            printf("\nComputer's target was %d", target);
            printf("\n\n**********%s YOU WON the match!!*************", name);
            printf("\n----------------------------------------------------");
            break;
        }
        if(cmpwick == 4){
            printf("\nThats an end of Computer's innings");
            printf("\nComputer score is %d", cmpscore);
            return cmpscore;
            break;
        }
    }
}

void playgame(char name[], int order) {
    //Order == 1 then batting first else bowling first
    if (order == 1 && name != "Comp"){
        //user batting first
        int target = 0;
        int btsco = 0, cmsco = 0;
        btsco = ubat_first();
        // user scored while batting 1st
        printf("\n%s, your score is %d", name, btsco);
        printf("\nComputer's target is %d", (btsco+1));
        target = btsco + 1;
        cmsco = cbat_chase(target);
        // check_target(btsco, cmsco);
    }
    else if(order == 1 && name == "Comp"){
        int cmpsco = cbat_first();
        int target = 0;
        target = cmpsco + 1;
        // user will bat 2nd
        printf("\nComputer score is %d", cmpsco);
        printf("\nYour target is %d", target);
        int btsco = ubat_chase(target);
    }
    else if(order == 2 && name != "Comp"){
        int target = 0;
        int btsco = 0, cmsco = 0;
        cmsco = cbat_first();
        // user will bat 2nd
        printf("\nComputer's score is %d", cmsco);
        printf("\n%s your target is %d",name, (cmsco+1));
        target = cmsco + 1;
        btsco = ubat_chase(target);
        // check_target(btsco, cmsco);
    }
    else if(order == 2 && name == "Comp"){
        int btsco = ubat_first();
        int target = 0;
        target = btsco + 1;
        // user will bat 2nd
        printf("\nYour score is %d", btsco);
        printf("\nComputer's target is %d", target);
        int cmsco = cbat_chase(target);
    }
}
