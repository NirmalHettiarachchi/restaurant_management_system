#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

void details(void);
void addItem(void);
void checkStock(void);
void removeItem(void);
void addOrRemoveStock(void);
void adjustProfit(void);
void adjustPrice(void);
void sell(void);
void seeBills(void);
void showList(void);
void lastDesition(int functionName);

int main()
{
    for(int i=1000;;i++)
    {
        FILE *checkFp = NULL;
        char iStr[10];
        itoa(i, iStr, 10);
        checkFp = fopen(iStr, "r");

        if(checkFp == NULL)
            break;

        char checkC;
        int line = 0;

        while((checkC = fgetc(checkFp))!=EOF)
        {
            if(checkC=='\n')
                line++;
        }

        if(line <= 2)
        {
            fclose(checkFp);
            remove(iStr);
        }
        fclose(checkFp);
    }

    FILE *newFp1 = NULL;
    FILE *newFp2 = NULL;
    newFp1 = fopen("0","r");
    newFp2 = fopen("1000","r");

    if(newFp1==NULL && newFp2==NULL)
    {
        system("cls");
        system("color 3F");
        printf("\n\n\n\n\t\t\t\t\t\tW");
        Sleep(75);
        printf("E");
        Sleep(75);
        printf("L");
        Sleep(75);
        printf("C");
        Sleep(75);
        printf("O");
        Sleep(75);
        printf("M");
        Sleep(75);
        printf("E ");
        Sleep(75);
        printf("N");
        Sleep(75);
        printf("E");
        Sleep(75);
        printf("W ");
        Sleep(75);
        printf("U");
        Sleep(75);
        printf("S");
        Sleep(75);
        printf("E");
        Sleep(75);
        printf("R");
        Sleep(370);
        printf("\n\n\n\t\tInstructions: ");
        printf("\n\n\t\t\t-> First add items by selecting '8.Add a new item' in the main menu");
        printf("\n\t\t\t-> Then you can continue using the app");
        printf("\n\n\t\tPress any key to continue...");
        getch();
    }
    fclose(newFp1);
    fclose(newFp2);

    system("cls");
    system("color 0F");
    int choice;

    printf("\n\n\n\n\n\n\n\n\t\t\t\t\tLoading");

    Sleep(100);
    printf(" .");
    Sleep(100);
    printf(" .");
    Sleep(100);
    printf(" .");
    Sleep(100);
    system("cls");

    printf("\n\t\t\t\t\t\tWELCOME TO MAIN MENU");
    printf("\n\t\t\t\t\t\t--------------------");
    printf("\n\n\t\t 1.Sell");
    printf("\n\n\t\t 2.Add or remove stock");
    printf("\n\n\t\t 3.Check available stocks");
    printf("\n\n\t\t 4.Check details of an existing item");
    printf("\n\n\t\t 5.Adjust profit from an existing item");
    printf("\n\n\t\t 6.Adjust price of an existing item");
    printf("\n\n\t\t 7.See bills, income and profits etc.");
    printf("\n\n\t\t 8.Add a new item");
    printf("\n\n\t\t 9.Remove an item");
    printf("\n\n\t\t 10.Exit");

    printf("\n\n\n\t\t\t Enter choice: ");
    scanf("%d",&choice);

    if(choice == 1)
        sell();

    if(choice == 2)
        addOrRemoveStock();

    if(choice == 3)
        checkStock();

    if(choice == 4)
        details();

    if(choice == 5)
        adjustProfit();

    if(choice == 6)
        adjustPrice();

    if(choice == 7)
        seeBills();

    if(choice == 8)
        addItem();

    if(choice == 9)
        removeItem();

    if(choice == 10)
    {
        system("cls");
        exit(0);
    }

    else
        main();

    return 0;
}

void addItem(void)
{
    char *iName = (char *)malloc(30*sizeof(char));
    char *price = (char *)malloc(5*sizeof(char));
    char *curStock = (char *)malloc(10*sizeof(char));
    char *profit = (char *)malloc(5*sizeof(char));

    system("cls");
    printf("\n\t\t\t\t\t\t   ADD A NEW ITEM");
    printf("\n\t\t\t\t\t\t -----------------");
    printf("\n\n\t\t Item name: ");
    scanf(" ");
    gets(iName);

    printf("\n\t\t Item price: Rs.");
    scanf("%s",price);

    printf("\n\t\t Current stock: ");
    scanf("%s",curStock);

    printf("\n\t\t Profit from 1 item: Rs.");
    scanf("%s",profit);

    FILE *newFp = NULL;

    for(int i = 0;;i++)
    {
        char iStr[4];
        itoa(i,iStr,10);

        FILE *readFp = NULL;
        readFp = fopen(iStr,"r");

        if(readFp == NULL)
        {
            newFp = fopen(iStr, "w+");
            break;
        }
        fclose(readFp);
    }

    fputs(iName, newFp);
    fputs("\n",newFp);
    fputs(price, newFp);
    fputs("\n",newFp);
    fputs(curStock, newFp);
    fputs("\n",newFp);
    fputs(profit, newFp);

    free(iName);
    free(price);
    free(curStock);
    free(profit);

    fclose(newFp);

    lastDesition(8);
}

void checkStock(void)
{
    system("cls");

    printf("\n\t\t\t\t\t\t    AVAILABLE STOCKS");
    printf("\n\t\t\t\t\t\t   ------------------\n");

    FILE *readFp = NULL;

    printf("\n\t\tItem\t\t\t   |\tAvailable stock\t\n");
    printf("\t\t-----------------------------------------------\n");

    int i;
    for(i = 0; ;i++)
    {
        char iStr[4];
        char holder;

        itoa(i, iStr, 10);
        readFp = fopen(iStr, "r");

        if(readFp == NULL)
            break;

        printf("\t\t%d. ",i+1);

        char *itemStr = (char *)malloc(25*sizeof(char));

        int i = 0;
        char c;
        while((c=fgetc(readFp))!=EOF)
        {
            if(c=='\n')
                break;
            printf("%c",c);
            itemStr[i] = c;
            i++;
        }
        itemStr[i] = '\0';

        fseek(readFp, 0, SEEK_SET);
        int line = 0;

        if(strlen(itemStr)<=12 && strlen(itemStr)>5)
            printf("\t\t   |        ");
        else if(strlen(itemStr)==5)
            printf("\t\t   |        ");
        else if(strlen(itemStr)<5)
            printf("\t\t\t   |        ");
        else if(strlen(itemStr)==22 || strlen(itemStr)==21)
            printf("  |        ");
        else if(strlen(itemStr)==20)
            printf("    |        ");
        else if(strlen(itemStr)>=23)
            printf("|        ");
        else
            printf("\t   |        ");

        free(itemStr);

        while((holder = fgetc(readFp)) != EOF)
        {
            if(holder == '\n')
                line++;

            if(line == 2 && holder != '\n')
                printf("%c", holder);

            if(line == 3)
                break;
        }

        printf("\n\t\t-----------------------------------------------");
        printf("\n");
        fclose(readFp);
    }
    lastDesition(3);
}

void showList(void)
{
    FILE *readFp = NULL;

    int i;
    for(i = 0; ;i++)
    {
        char iStr[4];

        itoa(i, iStr, 10);
        readFp = fopen(iStr, "r");

        if(readFp == NULL)
            break;

        printf("\t\t%d. ",i+1);

        char *itemStr = (char *)malloc(35*sizeof(char));
        fgets(itemStr, 35, readFp);
        printf("%s",itemStr);
        free(itemStr);

        fclose(readFp);
    }
}

void removeItem(void)
{
    system("cls");

    printf("\n\t\t\t\t\t\t  REMOVE AN ITEM");
    printf("\n\t\t\t\t\t\t ----------------\n");

    showList();
    char removeChoiceStr[4];

    int removeChoice;
    printf("\n\n\tEnter item number to remove: ");
    scanf("%d",&removeChoice);

    itoa(removeChoice-1, removeChoiceStr, 10);

    FILE *deleteFp = NULL;

    int i;
    for(i = 0; ;i++)
    {
        char iStr[4];

        itoa(i, iStr, 10);
        deleteFp = fopen(iStr, "r");

        if(deleteFp == NULL)
            break;

        if(strcmp(iStr, removeChoiceStr)==0)
        {
                fclose(deleteFp);
                break;
        }

        fclose(deleteFp);
    }

    int deleteOrNot;

    printf("\n\n\tRemove selected item:");
    printf("\n\t\t1.Yes\n\t\t2.No\n\n\t\tEnter choice: ");
    scanf("%d",&deleteOrNot);

    if(deleteOrNot == 1)
    {
        remove(removeChoiceStr);

        for(int j=i+1;;j++)
        {
            FILE *renameFp = NULL;
            char renameStr[4];

            itoa(j, renameStr,10);
            renameFp = fopen(renameStr,"r");

            if(renameFp == NULL)
                break;

            char newName[4];
            itoa(j-1,newName,10);

            fclose(renameFp);
            rename(renameStr,newName);
        }
        printf("\n\n\tItem has been removed successfully");
    }
    else
    {
        printf("\n\n\tItem removal has been canceled");
    }
    lastDesition(9);
}

void details(void)
{
    system("cls");

    printf("\n\t\t\t\t\tCHECK DETAILS OF AN EXISTING ITEM");
    printf("\n\t\t\t\t\t---------------------------------\n");

    showList();

    int detailsChoice;
    printf("\n\n\tEnter item number to see details: ");
    scanf("%d",&detailsChoice);

    FILE *detailsFp = NULL;
    char detailsChoiceStr[4];
    itoa(detailsChoice - 1, detailsChoiceStr, 10);

    for(int i = 0;;i++)
    {
        char iStr[4];
        itoa(i, iStr, 10);
        detailsFp = fopen(iStr, "r");

        if(detailsFp == NULL)
            break;

        if(strcmp(iStr, detailsChoiceStr)==0)
        {
            char holder;

            printf("\n\t\t\t\t\t  Item name\t\t:  ");
            while((holder = fgetc(detailsFp))!='\n')
                printf("%c",holder);

            printf("\n\n\t\t\t\t\t  Price\t\t\t:  Rs.");
            while((holder = fgetc(detailsFp))!='\n')
                printf("%c",holder);

            printf("\n\n\t\t\t\t\t  Available stock\t:  ");
            while((holder = fgetc(detailsFp))!='\n')
                printf("%c",holder);

            printf("\n\n\t\t\t\t\t  Profit per item\t:  Rs.");
            while((holder = fgetc(detailsFp))!=EOF)
                printf("%c",holder);

        }
        fclose(detailsFp);
    }
    lastDesition(4);
}

void addOrRemoveStock(void)
{
    system("cls");

    printf("\n\t\t\t\t\t\tADD OR REMOVE STOCK");
    printf("\n\t\t\t\t\t       ---------------------\n");

    int addOrRemove;
    printf("\n\t1.Add stock\n\t2.Remove stock");
    printf("\n\t\tEnter choice: ");
    scanf("%d",&addOrRemove);

    if(addOrRemove == 1)
    {
        system("cls");
        printf("\n\t\t\t\t\t\t   ADD STOCK");
        printf("\n\t\t\t\t\t\t  -----------\n");
    }

    else if(addOrRemove == 2)
    {
        system("cls");
        printf("\n\t\t\t\t\t\t  REMOVE STOCK");
        printf("\n\t\t\t\t\t\t  ------------\n");
    }

    showList();

    int addOrRemoveItem;
    printf("\n\n\tEnter item number to %s stock: ",addOrRemove==1?"add":"remove");
    scanf("%d",&addOrRemoveItem);

    FILE *stockFp = NULL;
    char stockStr[10];
    itoa(addOrRemoveItem - 1, stockStr, 10);

    int i;
    for(i = 0;;i++)
    {
        char iStr[5];
        itoa(i, iStr, 10);
        stockFp = fopen(iStr, "r");

        if(stockFp == NULL)
            break;

        if(strcmp(iStr, stockStr)==0)
        {
            char stockSizeStr[10];
            int stockSize = 0;
            char holder;
            int line = 0;
            while((holder=fgetc(stockFp))!=EOF)
            {
                if(holder=='\n')
                    line++;
                if(line == 2)
                    break;
            }
            fgets(stockSizeStr, 10, stockFp);
            stockSize = atoi(stockSizeStr);

            printf("\n\n\tAvailable stock: %d",stockSize);

            int changingStock;
            printf("\n\t\tStock to %s: ",addOrRemove==1?"add":"remove");
            scanf("%d",&changingStock);

            int changedStock;

            if(addOrRemove == 1)
                changedStock = stockSize + changingStock;

            else if(addOrRemove == 2)
            {
                changedStock = stockSize - changingStock;
                if(changedStock < 0)
                {
                    printf("\n\n\tStock can not be updated.");
                    goto below;
                }
            }
            printf("\n\n\tStock updated successfully.");
            printf("\n\tAvailable stock: %d",changedStock);

            fseek(stockFp,0,SEEK_SET);

            FILE *writeFp;
            writeFp = fopen("temp","w+");

            char *iName = (char *)malloc(30*sizeof(char));
            char *price = (char *)malloc(5*sizeof(char));
            char *profit = (char *)malloc(5*sizeof(char));

            fgets(iName, 30, stockFp);
            fputs(iName, writeFp);

            fgets(price, 5, stockFp);
            fputs(price, writeFp);

            char changedStockStr[5];
            itoa(changedStock, changedStockStr, 10);
            fputs(changedStockStr, writeFp);

            char ch;
            while((ch=fgetc(stockFp))!=EOF)
            {
                if(ch == '\n')
                    break;
            }

            fputs("\n",writeFp);
            fgets(profit, 5, stockFp);
            fputs(profit, writeFp);

            fclose(writeFp);
            fclose(stockFp);

            remove(stockStr);
            rename("temp", stockStr);
        }
        below:
        fclose(stockFp);
    }
    lastDesition(2);
}

void adjustProfit(void)
{
    system("cls");

    printf("\n\t\t\t\t\t\tADJUST PROFIT");
    printf("\n\t\t\t\t\t       ---------------\n");

    showList();

    int newProfitItem;
    printf("\n\n\tEnter item number to adjust profit: ");
    scanf("%d",&newProfitItem);

    FILE *profitFp = NULL;
    char newProfitItemStr[10];
    itoa(newProfitItem - 1, newProfitItemStr, 10);

    int i;
    for(i = 0;;i++)
    {
        char iStr[5];
        itoa(i, iStr, 10);
        profitFp = fopen(iStr, "r");

        if(profitFp == NULL)
            break;

        if(strcmp(iStr, newProfitItemStr)==0)
        {
            char oldProfitStr[10];

            char holder;
            int line = 0;
            while((holder=fgetc(profitFp))!=EOF)
            {
                if(holder=='\n')
                    line++;
                if(line == 3)
                    break;
            }
            fgets(oldProfitStr, 10, profitFp);

            printf("\n\n\tCurrent profit from an item: Rs.%s",oldProfitStr);

            int newProfit;
            printf("\n\t\tNew profit from an item: Rs.");
            scanf("%d",&newProfit);

            printf("\n\n\tProfit updated successfully.");
            printf("\nUpdated profit: Rs.%d",newProfit);

            fseek(profitFp,0,SEEK_SET);

            FILE *writeFp;
            writeFp = fopen("temp","w+");

            char *iName = (char *)malloc(30*sizeof(char));
            char *price = (char *)malloc(5*sizeof(char));
            char *stock = (char *)malloc(10*sizeof(char));

            fgets(iName, 30, profitFp);
            fputs(iName, writeFp);

            fgets(price, 5, profitFp);
            fputs(price, writeFp);

            fgets(stock, 10, profitFp);
            fputs(stock, writeFp);

            char newProfitStr[5];
            itoa(newProfit, newProfitStr, 10);
            fputs(newProfitStr, writeFp);

            fclose(writeFp);
            fclose(profitFp);

            remove(newProfitItemStr);
            rename("temp", newProfitItemStr);
        }
        fclose(profitFp);
    }
    lastDesition(5);
}

void adjustPrice(void)
{
    system("cls");

    printf("\n\t\t\t\t\t\tADJUST PRICE");
    printf("\n\t\t\t\t\t       --------------\n");

    showList();

    int newPriceItem;
    printf("\n\n\tEnter item number to adjust price: ");
    scanf("%d",&newPriceItem);

    FILE *priceFp = NULL;
    char newPriceItemStr[10];
    itoa(newPriceItem - 1, newPriceItemStr, 10);

    int i;
    for(i = 0;;i++)
    {
        char iStr[5];
        itoa(i, iStr, 10);
        priceFp = fopen(iStr, "r");

        if(priceFp == NULL)
            break;

        if(strcmp(iStr, newPriceItemStr)==0)
        {
            char oldPriceStr[10];

            char holder;
            int line = 0;
            while((holder=fgetc(priceFp))!=EOF)
            {
                if(holder=='\n')
                    line++;
                if(line == 1)
                    break;
            }
            fgets(oldPriceStr, 10, priceFp);

            printf("\n\n\tCurrent price of an item: Rs.%s",oldPriceStr);

            int newPrice;
            printf("\n\tNew price of an item: Rs.");
            scanf("%d",&newPrice);

            printf("\n\n\tPrice updated successfully.");
            printf("\n\tUpdated price: Rs.%d",newPrice);

            fseek(priceFp,0,SEEK_SET);

            FILE *writeFp;
            writeFp = fopen("temp","w+");

            char *iName = (char *)malloc(30*sizeof(char));
            char *stock = (char *)malloc(10*sizeof(char));
            char *profit = (char *)malloc(5*sizeof(char));

            fgets(iName, 30, priceFp);
            fputs(iName, writeFp);

            char newPriceStr[5];
            itoa(newPrice, newPriceStr, 10);
            fputs(newPriceStr, writeFp);

            while((holder=fgetc(priceFp))!=EOF)
            {
                if(holder == '\n')
                    break;
            }

            fputs("\n",writeFp);

            fgets(stock, 10, priceFp);
            fputs(stock, writeFp);

            fgets(profit, 5, priceFp);
            fputs(profit, writeFp);

            fclose(writeFp);
            fclose(priceFp);

            remove(newPriceItemStr);
            rename("temp", newPriceItemStr);
        }
        fclose(priceFp);
    }
    lastDesition(6);
}

void sell(void)
{
    system("cls");

    printf("\n\t\t\t\t\t\tSELL ITEMS");
    printf("\n\t\t\t\t\t       ------------\n");

    showList();

    int newSellItem;
    int fullProfit = 0;
    int fullPrice = 0;

    FILE *newBill = NULL;

    int j;
    char jStr[10];
    for(j = 1000;;j++)
    {
        itoa(j, jStr, 10);

        FILE *billHave = NULL;
        billHave = fopen(jStr, "r");

        if(billHave == NULL)
            break;

        fclose(billHave);
    }

    newBill = fopen(jStr, "w+");

    above:
    printf("\n\tEnter item number to sell: ");
    scanf("%d",&newSellItem);

    FILE *sellFp = NULL;
    char newSellItemStr[10];
    itoa(newSellItem - 1, newSellItemStr, 10);

    int i;
    for(i = 0;;i++)
    {
        char iStr[5];
        itoa(i, iStr, 10);
        sellFp = fopen(iStr, "r");

        if(sellFp == NULL)
            break;

        if(strcmp(iStr, newSellItemStr)==0)
        {
            char *iName = (char *)malloc(30*sizeof(char));
            char *iStock = (char *)malloc(10*sizeof(char));
            char *iPrice = (char *)malloc(5*sizeof(char));
            char *iProfit = (char *)malloc(5*sizeof(char));
            int quantity;

            fgets(iName, 30, sellFp);

            fgets(iPrice, 5, sellFp);

            fgets(iStock, 10, sellFp);

            fgets(iProfit, 10, sellFp);

            int stockInt = atoi(iStock);
            int priceInt = atoi(iPrice);
            int profitInt = atoi(iProfit);

            printf("\t\t\t\t\t|\tItem\t\t\t:\t%s",iName);
            printf("\t\t\t\t\t|\tAvailable stock\t\t:\t%d",stockInt);
            notEnoughStock:
            printf("\n\t\t\t\t\t|\tQuantity\t\t:\t");
            scanf("%d",&quantity);

            if(quantity>stockInt)
            {
                printf("\t\t\t\t\t\t\t\t\aNot enough stock!");
                goto notEnoughStock;
            }

            printf("\t\t\t\t\t|\tPrice (Rs.%d * %d)\t:\tRs.%d",priceInt,quantity,priceInt*quantity);

            fullProfit += (profitInt * quantity);
            fullPrice += (priceInt * quantity);

            char updatedStock[10];
            itoa(stockInt-quantity, updatedStock, 10);

            fseek(sellFp, 0, SEEK_SET);

            FILE *writeFp = NULL;
            writeFp = fopen("temp","w+");

            fgets(iName, 30, sellFp);
            fputs(iName, writeFp);

            fgets(iPrice, 5, sellFp);
            fputs(iPrice, writeFp);

            fputs(updatedStock, writeFp);

            char holder;
            while((holder=fgetc(sellFp))!=EOF)
            {
                if(holder=='\n')
                    break;
            }

            fputs("\n", writeFp);
            fgets(iProfit, 5, sellFp);
            fputs(iProfit, writeFp);

            int sellAnotherItem;
            printf("\n\t1.Add another item to the bill\n\t2.Finish\n\t\tEnter choice: ");
            scanf("%d",&sellAnotherItem);

            fprintf(newBill,"\t\tItem\t\t\t:\t%s",iName);
            fprintf(newBill,"\t\tQuantity\t\t:\t%d\n",quantity);
            fprintf(newBill,"\t\tPrice\t\t\t:\tRs.%d (Rs.%d*%d)\n",priceInt*quantity,priceInt,quantity);
            fprintf(newBill,"\t\tProfit\t\t\t:\tRs.%d (Rs.%d*%d)\n\n",profitInt*quantity,profitInt,quantity);

            free(iName);
            free(iStock);
            free(iPrice);
            free(iProfit);
            fclose(sellFp);
            fclose(writeFp);

            remove(newSellItemStr);
            rename("temp", newSellItemStr);

            if(sellAnotherItem != 2)
                goto above;
            if(sellAnotherItem == 2)
                {
                    time_t t;
                    time(&t);
                    printf("\n\t\t\t\t\t|\tBill value\t\t:\tRs.%d",fullPrice);
                    printf("\n\n\t%s",ctime(&t));
                    fprintf(newBill,"\t\tDate and time\t\t:\t%s\n\n",ctime(&t));

                    char fullProfitStr[15];
                    char fullIncomeStr[20];

                    FILE *fullProfitReadFile = NULL;
                    fullProfitReadFile = fopen("fullProfit","r");

                    if(fullProfitReadFile==NULL)
                    {
                        FILE *fullProfitFile = NULL;
                        fullProfitFile = fopen("fullProfit","w+");

                        itoa(fullPrice, fullIncomeStr, 10);
                        itoa(fullProfit, fullProfitStr, 10);

                        fputs(fullIncomeStr, fullProfitFile);
                        fputs("\n",fullProfitFile);
                        fputs(fullProfitStr, fullProfitFile);
                        fputs("\n",fullProfitFile);
                        fputs(ctime(&t), fullProfitFile);

                        fclose(fullProfitFile);
                    }

                    else
                    {
                        char oldFullIncomeStr[20];
                        fgets(oldFullIncomeStr, 20, fullProfitReadFile);

                        int oldFullIncome = atoi(oldFullIncomeStr);
                        int newFullIncome = oldFullIncome+fullPrice;

                        char oldFullProfitStr[15];
                        fgets(oldFullProfitStr, 15, fullProfitReadFile);

                        int oldFullProfit = atoi(oldFullProfitStr);
                        int newFullProfit = oldFullProfit+fullProfit;

                        itoa(newFullIncome, fullIncomeStr, 10);
                        itoa(newFullProfit, fullProfitStr, 10);

                        FILE *fullProfitFile = NULL;
                        fullProfitFile = fopen("fullProfit","w+");

                        fputs(fullIncomeStr, fullProfitFile);
                        fputs("\n",fullProfitFile);
                        fputs(fullProfitStr, fullProfitFile);
                        fputs("\n",fullProfitFile);
                        fputs(ctime(&t), fullProfitFile);

                        fclose(fullProfitFile);
                        fclose(fullProfitReadFile);
                    }
                printf("\tBill has been added successfully");
                }
        }
        fclose(sellFp);
    }
    fprintf(newBill,"\t\tBill value\t\t:\tRs.%d",fullPrice);
    fprintf(newBill,"\n\t\tProfit from the bill\t:\tRs.%d\n",fullProfit);
    fclose(newBill);
    lastDesition(1);
}

void seeBills(void)
{
    system("cls");

    printf("\n\t\t\t\t\t SEE BILLS, INCOME AND PROFITS, ETC.");
    printf("\n\t\t\t\t\t------------------------------------\n");

    int choice;
    printf("\n\t1.See bills\n\t2.Check income and profits\n\t3.Remove all\n\n\t\tEnter choice: ");
    scanf("%d",&choice);

    if(choice == 1)
    {
        for(int i=1000;;i++)
        {
            FILE *seeBill = NULL;

            char iStr[10];
            itoa(i, iStr, 10);

            seeBill = fopen(iStr, "r");

            if(seeBill == NULL)
                break;

            char ch;
            printf("\n\t\t\t\t\tBill %d\n\t\t\t\t\t------\n\n",i-999);
            while((ch=fgetc(seeBill))!=EOF)
            {
                printf("%c",ch);
            }
            printf("\t\t--------------------------------------------------------\n");
            fclose(seeBill);
        }
    }

    if(choice == 2)
    {
        FILE *readProfit = NULL;
        readProfit = fopen("fullProfit", "r");

        if(readProfit==NULL)
            printf("\n\tNo records available!");
        else
        {
            char fullIncome[20];
            char fullProfit[15];
            char *upTime = (char *)malloc(25*sizeof(char));
            fgets(fullIncome, 20, readProfit);
            fgets(fullProfit, 15, readProfit);

            printf("\n\n\t\t\t\tRecorded income\t\t: Rs.%s",fullIncome);
            printf("\n\t\t\t\tRecorded full profit\t: Rs.%s",fullProfit);
            fgets(upTime, 25, readProfit);
            printf("\n\t\t\t\tLast updated\t\t: %s",upTime);
            free(upTime);
            fclose(readProfit);
        }
    }

    if(choice == 3)
    {
        int deleteOrNot;
        printf("\n\tRemove all?\n\t\t1.Yes\n\t\t2.No\n\n\t\t\tEnter choice: ");
        scanf("%d",&deleteOrNot);
        if(deleteOrNot==1)
        {
            remove("fullProfit");
            for(int k=1000;;k++)
            {
                char kStr[10];
                itoa(k,kStr,10);
                FILE *deleteAll = NULL;
                deleteAll = fopen(kStr, "r");

                if(deleteAll == NULL)
                    break;

                fclose(deleteAll);
                remove(kStr);
            }
            printf("\n\n\tAll records have been removed successfully");
        }
        else
            printf("\n\n\tRemoval has been canceled");
    }
    lastDesition(7);
}

void lastDesition(int functionName)
{
    int mainOrAnother;

    if(functionName==3)
    {
        printf("\n\n\t1.Go to menu\n\t2.Exit");
        printf("\n\n\t\tEnter choice: ");
        scanf("%d",&mainOrAnother);
        if(mainOrAnother == 1)
            main();
        if(mainOrAnother == 2)
        {
            system("cls");
            exit(0);
        }
    }
    else
    {
        char *description = (char *)malloc(50*sizeof(char));

        if(functionName == 1)
            strcpy(description, "Add another bill");

        if(functionName == 2)
            strcpy(description, "Change stock of another item");

        if(functionName == 4)
            strcpy(description, "Check details of another item");

        if(functionName == 5)
            strcpy(description, "Adjust profit of another item");

        if(functionName == 6)
            strcpy(description, "Adjust price of another item");

        if(functionName == 7)
            strcpy(description, "See bills, profits, etc. again");

        if(functionName == 8)
            strcpy(description, "Add another item");

        if(functionName == 9)
            strcpy(description, "Remove another item");

        printf("\n\n\t1.Go to menu\n\t2.%s\n\t3.Exit",description);

        printf("\n\n\t\tEnter choice: ");
        scanf("%d",&mainOrAnother);
        free(description);

        if(mainOrAnother == 1)
            main();

        if(mainOrAnother == 2)
        {
                if(functionName == 1)
                    sell();

                if(functionName == 2)
                    addOrRemoveStock();

                if(functionName == 4)
                    details();

                if(functionName == 5)
                    adjustProfit();

                if(functionName == 6)
                    adjustPrice();

                if(functionName == 7)
                    seeBills();

                if(functionName == 8)
                    addItem();

                if(functionName == 9)
                    removeItem();
        }

        if(mainOrAnother == 3)
        {
            system("cls");
            exit(0);
        }
    }
}





