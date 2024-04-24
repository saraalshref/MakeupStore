#include <stdio.h>
#include <windows.h>
#include <conio.h>
COORD coord = {0, 0};
struct product{
    char name[30];
    float price;
    int quantity;

};
typedef struct product product;
struct category{
     char name[30];
     product product[30];
     int PCount;

};
typedef struct category category;

struct makeupStore{
    category Categor[100];
    int cCount;
};
typedef struct makeupStore makeupStore;

void gotoxy(int x, int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void SetColor(int ForgC)
{
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}

void initial_Display(makeupStore* makeupStore)
{


   for(int i=0;i<3;i++){
        makeupStore->Categor[i].PCount=3;

   }

    strcpy(makeupStore->Categor[0].name,"lip sticks");
    strcpy(makeupStore->Categor[1].name,"Foundations");
    strcpy(makeupStore->Categor[2].name,"Concealers");

    strcpy(makeupStore->Categor[0].product[0].name,"Fit Me");
    makeupStore->Categor[0].product[0].price=220;
    makeupStore->Categor[0].product[0].quantity=50;
    strcpy(makeupStore->Categor[0].product[1].name,"amanda");
    makeupStore->Categor[0].product[1].price=100;
    makeupStore->Categor[0].product[1].quantity=30;
    strcpy(makeupStore->Categor[0].product[2].name,"might cinema");
    makeupStore->Categor[0].product[2].price=60;
    makeupStore->Categor[0].product[2].quantity=60;

    strcpy(makeupStore->Categor[1].product[0].name,"Fit Me");
    makeupStore->Categor[1].product[0].price=220;
    makeupStore->Categor[1].product[0].quantity=50;
    strcpy(makeupStore->Categor[1].product[1].name,"girl");
    makeupStore->Categor[1].product[1].price=380;
    makeupStore->Categor[1].product[1].quantity=50;
    strcpy(makeupStore->Categor[1].product[2].name,"Mac");
    makeupStore->Categor[1].product[2].price=1400;
    makeupStore->Categor[1].product[2].quantity=30;


    strcpy(makeupStore->Categor[2].product[0].name,"La girl");
    makeupStore->Categor[2].product[0].price=190;
    makeupStore->Categor[2].product[0].quantity=60;
    strcpy(makeupStore->Categor[2].product[1].name,"MN");
    makeupStore->Categor[2].product[1].price=90;
    makeupStore->Categor[2].product[1].quantity=80;
    strcpy(makeupStore->Categor[2].product[2].name,"Huda Beauty");
    makeupStore->Categor[2].product[2].price=1000;
    makeupStore->Categor[2].product[2].quantity=43;

}
void display(makeupStore* makeupStore){
            for (int i = 0; i < makeupStore->cCount; i++) {
                printf("Category %d",i+1);
                printf(" : %s \n",  makeupStore->Categor[i].name);

        for (int j = 0; j < makeupStore->Categor[i].PCount; j++) {
            printf("Product: %s\n", makeupStore->Categor[i].product[j].name);
            printf("Price: %f\n", makeupStore->Categor[i].product[j].price);
            printf("Quantity: %d\n", makeupStore->Categor[i].product[j].quantity);
            printf("\n");

    }
}
}

void removeCategory(makeupStore* makeupStore){
        char name[20];
        int find=-1;
        printf("enter the name of category you want remove : ");
        scanf("%s",name);
        for(int i=0;i<makeupStore->cCount;i++)
        {
            if(strcmp(makeupStore->Categor[i].name,name)==0){
            find=i;
            break;
        }
        }
        if(find==-1){
            printf("this category not found");
        }
        else{

            for(int i=find;i<makeupStore->cCount-1;i++){

                    makeupStore->Categor[i]=makeupStore->Categor[i+1];

            }
            makeupStore->cCount--;
            printf("category removed successfully \n");
        }
}

 void addProduct(makeupStore* makeupStore)
{   char cName[20];
    char pName[20];
    int quantity;
    float pric;
    int f=-1;
    int numOfProduct;
    printf("enter the category name you want add product in it : ");
    scanf("%s",cName);


    for(int i=0;i<makeupStore->cCount;i++){
        if (strcmp(makeupStore->Categor[i].name, cName) == 0)
        {   f=0;
            int index=makeupStore->Categor[i].PCount;
            for (int n=0;n<3;n++){
                printf("enter the product name : ");
                scanf("%s",pName);
                printf("enter the product quantity : ");
                scanf("%d",&quantity);
                printf("enter the product Price : ");
                scanf("%f",&pric);
                strcpy(makeupStore->Categor[i].product[index].name,pName);
                makeupStore->Categor[i].product[index].price=pric;
                makeupStore->Categor[i].product[index].quantity=quantity;

                makeupStore->Categor[i].PCount++;
                index++;




            }

        }


    }
    if(f==0){
        printf("add successfuly \n");
    }
    else{
        printf("there is no category with this name\n");
    }
}

void Add_Category(makeupStore *makeupStore){
    if (makeupStore->cCount<20){
            printf("enter name of category : ");
           scanf("%s",makeupStore->Categor[makeupStore->cCount].name);
           printf("category added successfully \n");
           makeupStore->cCount++;

    }
}
void removeProduct(makeupStore* makeupStore){
     char c_Name[20];
    char p_Name[20];
    int fCategory=-1;
    int fProduct=-1;
    printf("enter the category name you want remove product from : ");
    scanf("%s",c_Name);
    for(int i=0;i<makeupStore->cCount;i++){
        if (strcmp(makeupStore->Categor[i].name, c_Name) == 0){
            fCategory=i;
            break;
        }
    }
    if(fCategory==-1){
        printf("this category not found");
        return;
    }
    printf("enter the product name : ");
    scanf("%s",p_Name);
    for(int n=0;n<makeupStore->Categor[fCategory].PCount;n++){
        if (strcmp(makeupStore->Categor[fCategory].product[n].name, p_Name) == 0){
            fProduct=n;
        }
    }
    if(fProduct==-1){
        printf("this category not found");
        return;
    }
    free(makeupStore->Categor[fCategory].product[fProduct].name);
    for(int j=0;j<makeupStore->Categor[fCategory].PCount-1;j++){

        makeupStore->Categor[fCategory].product[j]=makeupStore->Categor[fCategory].product[j+1];

    }
    makeupStore->Categor[fCategory].PCount--;
     printf("product remove successfully");

}
void moveProduct(makeupStore* makeupStore){
    char c_name[20];
    char p_name[20];
    char pmove_name[20];
    int fC=-1;
    int fP=-1;

    printf("enter the category name you want move from it : ");
    scanf("%s",c_name);
     for(int i=0;i<makeupStore->cCount;i++){
        if (strcmp(makeupStore->Categor[i].name, c_name) == 0){
            fC=i;
            break;
        }
    }
    if(fC==-1){
        printf("this category not found");
        return;
    }
    printf("enter the product you want move : ");
    scanf("%s",p_name);
      for(int n=0;n<makeupStore->Categor[fC].PCount;n++){
        if (strcmp(makeupStore->Categor[fC].product[n].name, p_name) == 0){
            fP=n;
        }
    }
    if(fP==-1){
        printf("this category not found");
        return;
    }
    printf("enter the product name to replace : ");
    scanf("%s",pmove_name);
    for(int j=0;j<makeupStore->Categor[fC].PCount;j++){
        if(fP==j){

                strcpy(makeupStore->Categor[fC].product[j].name,pmove_name);

        }
    }

     printf("product remove successfully");

}


void sellProduct(makeupStore* makeupStore) {
    int numCategories;
    char c_name[20];
    int numProducts;
    char p_name[20];
    int quantitySold;
    int categoryIndex = -1;
    int productIndex = -1;
    printf("Enter the number of categories you want to sell from: ");
    scanf("%d", &numCategories);

    for (int i = 0; i < numCategories; i++) {

        printf("Enter the category name: ");
        scanf("%s", c_name);

        for (int i = 0; i < makeupStore->cCount; i++) {
            if (strcmp(makeupStore->Categor[i].name, c_name) == 0) {
                categoryIndex = i;
                break;
            }
        }


        if (categoryIndex == -1) {
            printf("Category  not found. \n", c_name);
            continue;
        }


        printf("Enter the number of products you want to sell from category '%s': ", c_name);
        scanf("%d", &numProducts);

        for (int p = 0; p < numProducts; p++) {

            printf("Enter the product name: ");
            scanf("%s", p_name);

            for (int j = 0; j < makeupStore->Categor[categoryIndex].PCount; j++) {
                if (strcmp(makeupStore->Categor[categoryIndex].product[j].name, p_name) == 0) {
                    productIndex = j;
                    break;
                }
                else {
                    productIndex == -1;
                }
            }


            if (productIndex == -1) {
                printf("Product not found in category \n", p_name, c_name);
                continue;
            }

            printf("Enter the quantity sold: ");
            scanf("%d", &quantitySold);

            if (quantitySold > makeupStore->Categor[categoryIndex].product[productIndex].quantity) {
                printf("there is no quantity enough");
                continue;
            }
            else{
            makeupStore->Categor[categoryIndex].product[productIndex].quantity -= quantitySold;
            printf("Sale of %d  of product '%s' from category '%s' successful \n", quantitySold, p_name, c_name);
            printf("Remaining quantity: %d \n", makeupStore->Categor[categoryIndex].product[productIndex].quantity);
            }
        }
    }
}


int main()
{
makeupStore makeupStore;
makeupStore.cCount=3;
   int selectOption=0;

   while(1){
       gotoxy(5,0);
       printf("welcome to Sara Makeup Store");

    gotoxy(5,3);
    if(selectOption==0)
       {

            SetColor(0x0E);
            printf("-> Add category");
            SetColor(0x0F);
        }
       else
        {
           printf("  Add category");
        }
        gotoxy(5,4);
    if(selectOption==1)
       {

            SetColor(0x0E);

            printf("-> Display");
            SetColor(0x0F);
        }
       else
        {
           printf("  Display");
        }
        gotoxy(5,5);
    if(selectOption==2)
       {

            SetColor(0x0E);
            printf("-> Remove Category");

            SetColor(0x0F);
        }
       else
        {
           printf("  Remove Category");
        }
        gotoxy(5,6);
    if(selectOption==3)
       {

            SetColor(0x0E);
            printf("-> Add product");

            SetColor(0x0F);
        }
       else
        {
           printf("  Add product");
        }

      gotoxy(5,7);
    if(selectOption==4)
       {

            SetColor(0x0E);
            printf("-> Remove Product");

            SetColor(0x0F);
        }
       else
        {
           printf("  Remove Product");
        }
     gotoxy(5,8);
    if(selectOption==5)
       {

            SetColor(0x0E);
            printf("-> Move Product to Another Category");
            SetColor(0x0F);
        }
       else
        {
           printf("  Move Product to Another Category");
        }
    gotoxy(5,9);
    if(selectOption==6)
       {

            SetColor(0x0E);
            printf("-> sell products");
            SetColor(0x0F);
        }
       else
        {
           printf("   sell products");
        }
    gotoxy(5,10);
    if(selectOption==7)
       {

            SetColor(0x0E);
            printf("-> Exit");
            SetColor(0x0F);
        }
       else
        {
           printf("  Exit");
        }


        char key = _getch();
        switch(key){
    case 72:

            if (selectOption<=0){
                selectOption=7;
            }
            else{
                selectOption--;
            }
            break;
    case 80:

            if (selectOption>=7){
                selectOption=0;
            }
            else{
                selectOption++;
            }
            break;

    case 13:

        switch(selectOption){
    case 0:
            system("cls");
            Add_Category(&makeupStore);
            system("pause");
            system("cls");
            break;

    case 1:
            system("cls");
            initial_Display(&makeupStore);
            display(&makeupStore);
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            removeCategory(&makeupStore);
            system("pause");
            system("cls");
            break;

          case 3:
            system("cls");
            addProduct(&makeupStore);
            system("pause");
            system("cls");
            break;

         case 4:
            system("cls");
            removeProduct(&makeupStore);
            system("pause");
            system("cls");
            break;

            case 5:
            system("cls");
            moveProduct(&makeupStore);
            system("pause");
            system("cls");
            break;

            case 6:
            system("cls");
            sellProduct(&makeupStore);
            system("pause");
            system("cls");
            break;



        }

        }


   }

    return 0;
}
