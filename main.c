#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct customers
{
    char name[60];
    char phone[12];
    char address[50];
    int day, month, year;
    char id[15];
    int day2, month2, year2;
    int age;
    float money;
    int account_type;
};
void create_account(int *i, struct customers data[])
{

    int j = *i;


start:
    printf("Please enter your name(do not contain digits or specialcharacters): ");
    scanf(" %[^\n]s",data[j].name);
    int n;
    for (n = 0; (data[j].name[n]) != '\0'; n++)
    {
        if (!((data[j].name[n] >= 'a' && data[j].name[n] <= 'z') || (data[j].name[n] >= 'A' && data[j].name[n] <= 'Z') || data[j].name[n] == ' '))
        {

            printf("the must not contain a digit or aspecialcharacter \n");
            goto start;
        }
    }
  start3:
    printf("please enter your age (must be more than or equal 20 year): ");
    if (!(scanf("%d", &data[j].age)))
    {
        getchar();
        printf("the age must be only digits \n");


goto start3;
}

    else {
    if (!((data[j].age) >= 20))
    {

        printf("you must have 20 years old to create account\n");
      goto start3;
    }
    }
    start40:
    printf("Please enter the date of creation: ");
    if ((scanf("%d%*c%d%*c%d", &data[j].day2, &data[j].month2, &data[j].year2))!=3)
    {
        getchar();
        goto start40;
    }
    else{
    if (!((data[j].day2 > 0 && data[j].day2 <= 31) && (data[j].month2 > 0 && data[j].month2 <= 12) && (data[j].year2)>=2022))
    {
        printf("enter a valid  date\n");
        goto start40;
    }
    }
start2:
    printf("Please enter your phone number (must be 11 digits): ");
    scanf(" %[^\n]s",data[j].phone);

    for (n = 0; (data[j].phone[n]) != '\0'; n++)
    {
        if (!((data[j].phone[n] >= '0' && data[j].phone[n] <= '9')))
        {
            printf("enter a valid phone number: \n");
            goto start2;
        }
    }
    if (!(n == 11))
    {
        printf("enter a valid phone number: \n");
        goto start2;
    }
    printf("Please enter your address: ");
    scanf(" %[^\n]s",data[j].address);
start20:
    printf("Please enter your birth day: ");
    if ((scanf("%d%*c%d%*c%d", &data[j].day, &data[j].month, &data[j].year))!=3)
    {
        getchar();
        printf("enter a valid birth day\n");
        goto start20;
    }
    else{
    if (!((data[j].day > 0 && data[j].day <= 31) && (data[j].month > 0 && data[j].month <= 12) && (data[j].year) == 2022 - (data[j].age)))
    {
        printf("enter a valid birth date\n");
        goto start20;
    }
    }
start4:
    printf("Please enter your id ( must be 14 digits): ");
    scanf(" %[^\n]s",data[j].id);
    for (n = 0; (data[j].id[n]) != '\0'; n++)
    {
        if (!((data[j].id[n] >= '0' && data[j].id[n] <= '9')))
        {

            printf("enter a valid id: \n");
            goto start4;
        }
    }
    if (!(n == 14))
    {
        printf("enter a valid id: \n");
        goto start4;
    }
start5:
    printf("please enter the money (must be equal or more than 50$): ");
    if (!(scanf("%f", &data[j].money)))
    {
        getchar();
        printf("the money must be only digits\n");
        goto start5;
    }

    else {
    if (!((data[j].money) >= 50.0))
    {

        printf("you must enter equal or more than 50$ \n");
        goto start5;
    }
    }
    printf("please choose the servis you need: \n");
start6:
    printf("(1)saving(%%5)\n(2)current(%%10)\n(3)investment(%%15)\n");
    if (!(scanf("%d", &data[j].account_type)))
    {
        getchar();
        goto start6;
    }
    else {
    if (!((data[j].account_type) > 0 && (data[j].account_type) < 4))
    {
        printf("please enter a right choose \n");
        goto start6;
    }
    }

    printf(" Your account number is :[ %d ] please do not forget it\n", j + 100);

    return;
}
void view_list(int *accountnumber, struct customers data[])
{
    printf("\n \n \n");
    int j = (*accountnumber) - 100;
    printf("Your account number is:%d \n", j + 100);
    printf("Your name is: %s\n", data[j].name);
    printf("Your id is %s\n", data[j].id);
    printf("Your phone number is: %s\n", data[j].phone);
    printf("Your address is: %s\n", data[j].address);
    printf("Your birth day: %d/%d/%d\n", data[j].day, data[j].month, data[j].year);
    printf("your money is: %f\n", data[j].money);
    printf("\n \n \n");
}
void edit(int *accountnumber, struct customers data[])
{
    int acn = *accountnumber;

    printf("Edit your address : ");
    scanf(" %[^\n]s",data[acn-100].address);
start16:
    printf("Edit your phone number: ");
    scanf(" %[^\n]s",data[acn-100].phone);
    int n;
    for (n = 0; (data[acn - 100].phone[n]) != '\0'; n++)
    {
        if (!((data[acn - 100].phone[n] >= '0' && data[acn - 100].phone[n] <= '9')))
        {

            printf("enter a valid phone number: \n");
            goto start16;
        }
    }
    if (!(n == 11))
    {

        printf("enter a valid phone number: \n");
        goto start16;
    }

    return;
}
void transact(int *accountnumber, struct customers data[])
{
    int choose;
    float dp;
    int cn = *accountnumber;

    printf("The date of the day : ");
    start22:
    if ((scanf("%d%*c%d%*c%d", &data[cn - 100].day2, &data[cn - 100].month2, &data[cn - 100].year2)!=3))
    {
        getchar();
       printf("this date is not valid\n");
       goto start22;
    }
    else {
    if (!((data[cn - 100].day2 > 0 && data[cn - 100].day2 <= 31) && (data[cn - 100].month2 > 0 && data[cn - 100].month2 <= 12) && (data[cn - 100].year2 > 0 && data[cn - 100].year2 >= 2022)))
    {

        printf("Enter a valid date of day\n");
        goto start22;
    }
    }
    printf("please choose the service you need:  \n");
start7:
    printf("(1)deposit\n(2)withdraw\n");
    if (!(scanf("%d", &choose)))
    {
        getchar();
        goto start7;
    }
    else {
    if (!((choose == 1) || (choose == 2)))
    {

        printf("enter a right choose: \n");
        goto start7;
    }
    }

    if (choose == 1)
    {
    start8:
        printf("please enter the money to deposit: \n");
        if (!(scanf("%f", &dp)))
        {
            getchar();
            printf("the money must be only digits\n");
            goto start8;
        }
        else{
        if (!(dp > 0))
        {

            printf("enter a valid money :\n");
            goto start8;
        }
        }

        data[cn - 100].money += dp;
        printf("Now your total money is: %.3f\n", data[cn - 100].money);
    }
    else if (choose == 2)
    {
    start9:
        printf("please enter the money to withdraw: \n");
        if (!(scanf("%f", &dp)))
        {
            getchar();
            printf("the money must be only digits\n");
            goto start9;
        }
        else {
        if (!(dp > 0))
        {

            printf("enter a valid money :\n");
            goto start9;
        }
        }
        data[cn - 100].money -= dp;
        printf("Now your total money is: %.f\n", data[cn - 100].money);
        return;
    }
}
void erase(int *accountnumber, struct customers data[])
{
    int cn = *accountnumber - 100;
    strcpy(data[cn].id, "");
    strcpy(data[cn].name, "");
    data[cn].day2 = 0;
    data[cn].month2 = 0;
    data[cn].year2 = 0;
    strcpy(data[cn].address, "");
    strcpy(data[cn].phone, "");
    data[cn].day = 0;
    data[cn].month = 0;
    data[cn].year = 0;
    data[cn].money = 0.0;

    return;
}
void see(int *accountnumber, struct customers data[])
{

    printf("\n \n \n");
    int j = (*accountnumber) - 100;
    float interest = data[j].money;

    printf("Your account number is:%d \n", j + 100);
    printf("Your name is: %s\n", data[j].name);
    printf("Your id is %s\n", data[j].id);
    printf("Your phone number is: %s\n", data[j].phone);
    printf("Your address is: %s\n", data[j].address);
    printf("Your birth day: %d/%d/%d\n", data[j].day, data[j].month, data[j].year);
    printf("your money is: %f\n", data[j].money);
    printf("your age is: %d \n", data[j].age);
    printf("the date of last edit: %d/%d/%d \n", data[j].day2, data[j].month2,++data[j].year2);
    if ((data[j].account_type) == 1)
    {
        printf("the type of your account is: sving\n");
        printf("the interest to your money till now: %.3f\n", interest * (5.0 / 100.000));
    }
    if ((data[j].account_type) == 2)
    {
        printf("the type of your account is: current\n");
        printf("the interest to your money till now: %.3f\n", interest * (10.0 / 100.000));
    }
    if ((data[j].account_type) == 3)
    {
        printf("the type of your account is: investment\n");
        printf("the interest to your money till now: %.3f\n", interest * (15.0 / 100.000));
    }

    printf("\n \n \n");
}
void search(char searchname[], struct customers data[])
{
    char username[60];
    strcpy(username, searchname);
    printf("%s", username);

    int i = 0;
    int j;
    for (i = 0; i < 99; i++)
    {
        if ((strcmp(username, data[i].name)) == 0)
        {
            printf("Your account number is:%d \n", i + 100);
            printf("Your name is: %s\n", data[i].name);
            printf("Your id is %s\n", data[i].id);
            printf("Your phone number is: %s\n", data[i].phone);
            printf("Your address is: %s\n", data[i].address);
            printf("Your birth day: %d/%d/%d\n", data[i].day, data[i].month, data[i].year);
            printf("your money is: %f\n", data[i].money);
            return;
        }
    }
    printf("\n there is no account by this name\n");
    return;
}
void sort(int *i, struct customers data[])
{
    int j = *i;
    int h;
    int k;
    for (h = 0; h < j - 1; h++)
    {
        for (k = h + 1; k < j; k++)
        {
            if (strcmp(data[h].name, data[k].name) > 0)
            {
                char temp[100];
                int temp2;
                strcpy(temp, data[h].name);
                strcpy(data[h].name, data[k].name);
                strcpy(data[k].name, temp);
                strcpy(temp, data[h].id);
                strcpy(data[h].id, data[k].id);
                strcpy(data[k].id, temp);
                temp2 = data[h].day;
                data[h].day = data[k].day;
                data[k].day = temp2;
                temp2 = data[h].month;
                data[h].month = data[k].month;
                data[k].month = temp2;
                temp2 = data[h].year;
                data[h].year = data[k].year;
                data[k].year = temp2;
                strcpy(temp, data[h].address);
                strcpy(data[h].address, data[k].address);
                strcpy(data[k].address, temp);
                strcpy(temp, data[h].phone);
                strcpy(data[h].phone, data[k].phone);
                strcpy(data[k].phone, temp);

                temp2 = data[h].money;
                data[h].money = data[k].money;
                data[k].money = temp2;
                temp2 = data[h].age;
                data[h].age = data[k].age;
                data[k].age = temp2;
            }
        }
    }
    j = *i;
    for (h = 0; h < j; h++)
    {
        printf("the account number : %d\n\n", h + 1);
        printf("Your account number is:%d \n", h + 100);
        printf("Your name is: %s\n", data[h].name);
        printf("Your id is %s\n", data[h].id);
        printf("Your phone number is: %s\n", data[h].phone);
        printf("Your address is: %s\n", data[h].address);
        printf("Your birth day: %d/%d/%d\n", data[h].day, data[h].month, data[h].year);
        printf("your money is: %f\n", data[h].money);
        printf("\n\n");
    }
}

int main()
{
    int accountnumber;

    struct customers data[100];
    int i = 0;
    int choosen;

    while (1)
    {
        do
        {
            start30:
            printf(" \t \t \t \t Welcome to the bank\n");
            printf("Please,choose one of this services from (1) to (9):\n\n");
            printf("(1)Create a new account.\n(2)View list\n(3)Edit an account\n(4)Transact( deposit and withdraw money)\n(5)Erase an account\n(6)See an account\n(7)Search about an account\n(8)Sort my data\n");
            printf("(9)Exit from the program\n");
            if (!(scanf("%d", &choosen)))
            {
                getchar();
                goto start30;
            }
        } while (choosen < 1 || choosen > 9);
        if (choosen == 1)
        {
            create_account(&i, data);
            i++;
            printf("\n-----------------------------\n");
        }

        else if (choosen == 2)
        {
        start10:
            printf("Please enter your account number: ");
            if (!(scanf("%d", &accountnumber)))
            {
                getchar();
                printf("this account number is not valid \n");
                goto start10;
            }
            else {
            if (!((accountnumber >= 100) && (accountnumber < (100 + i))))
            {
                printf("there is no account created by this number\n");
                goto start10;
            }
            }
            view_list(&accountnumber, data);
            printf("\n-----------------------------\n");
        }
        else if (choosen == 3)
        {
        start11:
            printf("Please enter the account number: ");
            if (!(scanf("%d", &accountnumber)))
            {
                getchar();
                printf("this account number is not valid\n");
                goto start11;
            }
            else {
            if ((accountnumber >= 100) && (accountnumber < (100 + i)))
            {
            }
            else
            {
                printf("there is no account created by this number\n");
                goto start11;
            }
            }
            edit(&accountnumber, data);
            printf("\n-----------------------------\n");
        }
        else if (choosen == 4)
        {
        start12:
            printf("please enter the account number: ");
            if (!(scanf("%d", &accountnumber)))
            {
                getchar();
                printf("this account number is not valid\n");
                goto start12;
            }
            else{
            if ((accountnumber >= 100) && (accountnumber < (100 + i)))
            {
            }
            else
            {
                printf("there is no account created by this number\n");
                goto start12;
            }
            }
            transact(&accountnumber, data);
            printf("\n\n");
            printf("\n-----------------------------\n");
        }
        else if (choosen == 5)
        {
        start13:
            printf("please enter the number of your account: ");
            if (!(scanf("%d", &accountnumber)))
            {
                getchar();
                printf("this account number is not valid\n");
                goto start13;
            }
            else {
            if ((accountnumber >= 100) && (accountnumber < (100 + i)))
            {
            }
            else
            {
                printf("there is no account created by this number\n");
                goto start13;
            }
            }
            erase(&accountnumber, data);
            printf("your account is erased \n");
            printf("\n-----------------------------\n");
        }
        else if (choosen == 6)
        {
        start14:
            printf("please enter the number of your account: ");
            if (!(scanf("%d", &accountnumber)))
            {
                getchar();
                printf("this account number is not valid\n");
                goto start14;
            }
            else {
            if ((accountnumber >= 100) && (accountnumber < (100 + i)))
            {
            }
            else
            {
                printf("there is no account created by this number\n");
                goto start14;
            }
            }
            see(&accountnumber, data);
            printf("\n-----------------------------\n");
        }
        else if (choosen == 7)
        {
            char searchname[60];
            printf("Please enter the name to search about your account:  ");
            scanf(" %[^\n]s",searchname);
            search(searchname, data);
            printf("\n-----------------------------\n");
        }
        else if (choosen == 8)
        {
            sort(&i, data);
            printf("\n-----------------------------\n");
            int h;
            int k;
            for (h = 0; h < i - 1; h++)
            {
                for (k = h + 1; k < i; k++)
                {
                    if (strcmp(data[h].name, data[k].name) < 0)
                    {
                        char temp[100];
                        int temp2;
                        strcpy(temp, data[h].name);
                        strcpy(data[h].name, data[k].name);
                        strcpy(data[k].name, temp);
                        strcpy(temp, data[h].id);
                        strcpy(data[h].id, data[k].id);
                        strcpy(data[k].id, temp);
                        temp2 = data[h].day;
                        data[h].day = data[k].day;
                        data[k].day = temp2;
                        temp2 = data[h].month;
                        data[h].month = data[k].month;
                        data[k].month = temp2;
                        temp2 = data[h].year;
                        data[h].year = data[k].year;
                        data[k].year = temp2;
                        strcpy(temp, data[h].address);
                        strcpy(data[h].address, data[k].address);
                        strcpy(data[k].address, temp);
                        strcpy(temp, data[h].phone);
                        strcpy(data[h].phone, data[k].phone);
                        strcpy(data[k].phone, temp);

                        temp2 = data[h].money;
                        data[h].money = data[k].money;
                        data[k].money = temp2;
                        temp2 = data[h].age;
                        data[h].age = data[k].age;
                        data[k].age = temp2;
                    }
                }
            }
        }
        else if (choosen == 9)
        {
            printf("Thank you for your visit\n");
            return 0;
        }
    }

    return 0;
}
