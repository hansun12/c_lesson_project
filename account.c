#include <stdio.h>
#include <string.h>

char account_num[20];
char name[10];
int money;

void menu();

void create_account();
void show_account(char _name[]);

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
            printf("user name: ");
            scanf("%s", temp_name);
            show_account(temp_name);
            break;

        case 3:
            printf("user name: ");
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
    printf("input account number: ");
    scanf("%s", account_num);
    
    for(i=0; i < strlen(account_num); i++) {
        if(!('0' < account_num[i] && account_num[i] < '9')) {
            if(account_num[i] == '-') {
                continue;
            }
            printf("wrong input, please input [0]~[9] or [-]\n");
            return;
        }
    }

    printf("input user name: ");
    scanf("%s", name);

    money = 0;

    printf("\naccount create success!\n");
}

void show_account(char _name[]){
    draw_line();
    printf("<check account>\n");
    if(!strcmp(_name, name)) {
        printf("account number: %s\n", account_num);
        printf("balance: %d\n", money);

        printf("\ndone!\n");
        return;
    }

    printf("cannout found user <%s>\n",_name);
}

void deposit(char _name[]) {
    int amount;

    draw_line();
    printf("<deposit>\n");
    if(strcmp(_name, name)) {
        printf("cannot access account<%s>\n", _name);
        return;
    }
    printf("input price: ");
    scanf("%d", &amount);
    money += amount;
    printf("\ndone!\n");
    return;
}

void withdrawal(char _name[]){
    int amount;
    
    draw_line();
    printf("<withdrawal>\n");
    if(strcmp(_name, name)) {
        printf("cannot access account<%s>\n", _name);
        return;
    }
    printf("input price: ");
    scanf("%d",&amount);
    money -= amount;
    printf("\ndone!\n");
    return;


}

void draw_line() {
    printf("=======================================\n");
}