#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100
#define ACCOUNT_SIZE 20

char account_num[SIZE][ACCOUNT_SIZE];
char name[SIZE][10];
int money[SIZE];

int auto_creater=1000000001; // 100-000-0001
int head=0;


void menu();

void create_account();
void show_account(char _account_num[]);

void deposit(char _name[]);
void withdrawal(char _name[]);
void draw_line();


int main() {
    menu();
    printf("good bye!!\n");
}

void menu() {
    int select;
    char temp_name[10];

    while(1) {
        draw_line();
        printf("*** menu ***\n");
        printf("\n");
        printf(" 1. create accout\n");
        printf(" 2. account balance\n");
        printf(" 3. deposit\n");
        printf(" 4. withdrawal\n");
        printf(" 5. exit\n");
        printf("\n");
        printf("select: ");

        scanf("%d", &select);
        switch (select)
        {
        case 1:
            create_account();
            break;

        case 2:
            printf("account number: ");
            scanf("%s", temp_name);
            show_account(temp_name);
            break;

        case 3:
            printf("account number: ");
            scanf("%s", temp_name);
            deposit(temp_name);
            break;

        case 4:
            printf("user name: ");
            scanf("%s", temp_name);
            withdrawal(temp_name);
            break;

        case 5:
            return;

        default:
            printf("wrong access!\n");
            break;
        }
    }
}

void create_account() {
    int i;

    draw_line();
    
    sprintf(account_num[head], "%d", auto_creater);

    printf("input user name: ");
    scanf("%s", name[head]);

    money[head] = 0;

    auto_creater++;
    head++;

    printf("\naccount create success!\n");
    printf("your account number is <%s>\n", account_num[head-1]);
}

void show_account(char _account_num[]){
    int i, j=0;
    char temp[ACCOUNT_SIZE];
    draw_line();

    for(i = 0; i < strlen(_account_num); i++) {
        if(!('0' <= _account_num[i] && _account_num[i] <= '9')) {
            if(_account_num[i] != '-') {
                printf("wrong input, only use[0]~[9] or [-]\n");
                return;
            }
        }
    }

    for(i = 0; i < strlen(_account_num); i++) {
        if('0' <= _account_num[i] && _account_num[i] <= '9') {
            temp[j++] = _account_num[i];
        }
    }

    for(i = 0; i < head; i++) {
        if(!strcmp(temp, account_num[i])) {
            printf("---\"%s\"'s account---\n", name[i]);
            printf("amout: %d\n", money[i]);
            return;
        }
    }
    
    printf("cannout found account <%s>.\n", _account_num);
}

void deposit(char _account_num[]) {
    int i, j=0, value;
    char temp[ACCOUNT_SIZE];
    
    for(i = 0; i < strlen(_account_num); i++) {
        if(!('0' <= _account_num[i] && _account_num[i] <= '9')) {
            if(_account_num[i] != '-') {
                printf("wrong input, only use[0]~[9] or [-]\n");
                return;
            }//compare account number fine '-'
        }
    }

    for(i = 0; i < strlen(_account_num); i++) {
        if('0' <= _account_num[i] && _account_num[i] <= '9') {
            temp[j++] = _account_num[i];
        }// save account num on temp
    }

    for(i = 0; i < head; i++) {
        if(!strcmp(temp, account_num[i])) {
            printf("input balance: ");
            scanf("%d", &value);
            money[i] += value;
            draw_line();
            return;
        } 
        // add money
    }
    printf("cannot found user <%s>.\n", _account_num);
    draw_line();
    return;
}

void withdrawal(char _account_num[]){
    int i, value, j=0;
    char temp[ACCOUNT_SIZE];
    draw_line();
    for(i = 0; i < strlen(_account_num); i++) {
        if(!('0' <= _account_num[i] && _account_num[i] <= '9')) {
            if(_account_num[i] != '-') {
                printf("wrong input, only use[0]~[9] or [-]\n");
                return;
            }
        }
    }
    for(i = 0; i < strlen(_account_num); i++) {
        if('0' <= _account_num[i] && _account_num[i] <= '9') {
            temp[j++] = _account_num[i];
        }
    }
    for(i = 0; i < head; i++) {
        if(!strcmp(_account_num, account_num[i])) {
            printf("input balance: ");
            scanf("%d", &value);
            if(money[i]>value){
                money[i] -= value;
                draw_line();
                return;
            }
            else{
                printf("no money!\n");
                draw_line();
                return;
            }
        } 
    }
    printf("cannot found user <%s>.\n", _account_num);
    draw_line();
    return;
}

void draw_line() {
    printf("=======================================\n");
}