#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>
//declare

int age_year=18,age_month=0,age_day=0,currnt_hunger=300,total_hunger=300,current_health=300,total_health=300,momey=0,saving=0;
int menu_chooes_int;
bool newgame=1;
char name[50]="Fahimmanowar";
char trasport[10][25]={"Barefoot","Shoe","Bus","Cycle"};
char lodging[10][25]={"Cardboard Box","","",""};
char Education[10][25]={"None","","",""};
    FILE * fp;
//protoyepring

void frist_time_opening_the_game();
void c();
void main_menu();
void _Name();
void _Food();
void _Age();
void _Health();
void loading_bar(int size);
void _Money_and_Savings();
void _Trasport();
void _Lodging();
void _Education();
void cprinter(int dddef_choi, int pppic);
void _Food_and_Health_show();
void _Main_Menu_Bar();
//main
death(){
    age_year=18,age_month=0,currnt_hunger=300,total_hunger=300,momey=0,saving=0;
}

void main(){
    c();
    if((fp=fopen("newgame.txt","r"))==NULL)
    printf("error");
    frist_time_opening_the_game();
    fscanf(fp,"%d",newgame);
    if(newgame){
        frist_time_opening_the_game();
    }
    fclose(fp);
    
    
    printf("__Welcome To Life simulator");
    //hunger_load
    main_menu();
}
void frist_time_opening_the_game(){
    //chacking if its a new game
    fp=fopen("newgame.txt","w");
    fprintf(fp,"%d",0);
    fclose(fp);
    death();
    //name_save

    fp=fopen("name.txt","w");
    fprintf(fp,"%s",name);
    fclose(fp);
    //hunger_save

    fp=fopen("hunger.txt","w");
    fprintf(fp,"%d",currnt_hunger);
    fclose(fp);
    
    fp=fopen("health.txt","w");
    fprintf(fp,"%d",current_health);
    fclose(fp);
    
    fp=fopen("money.txt","w");
    fprintf(fp,"%d",momey);
    fclose(fp);
    
    fp=fopen("health.txt","w");
    fprintf(fp,"%d",saving);
    fclose(fp);
    
    fp=fopen("age_year.txt","w");
    fprintf(fp,"%d",age_year);
    fclose(fp);
    
    fp=fopen("age_month.txt","w");
    fprintf(fp,"%d",age_month);
    fclose(fp);
    
    fp=fopen("age_day.txt","w");
    fprintf(fp,"%d",age_day);
    fclose(fp);

}
void _Name(){
    //name_load
    fp=fopen("name.txt","r");
    fscanf(fp, "%s", name);
    printf("%s\n", name );
    fclose(fp);
}
void _Food(){
    fp=fopen("hunger.txt","r");
    fscanf(fp, "%d", &currnt_hunger);
    fclose(fp);
    printf("Food:\t\t %d/%d ",currnt_hunger,total_hunger); loading_bar(30*(currnt_hunger/(float)total_hunger));
}
void _Food_save(int add_or_reduce){
    fp=fopen("hunger.txt","w");
    currnt_hunger-=add_or_reduce;
    if(currnt_hunger>300){
    currnt_hunger=300;
    }
    currnt_hunger-=add_or_reduce;
    if(currnt_hunger<=0){
    currnt_hunger=0;
    }
    fscanf(fp, "%d", currnt_hunger);
    fclose(fp);
}
void _Age(){
    printf("Age:\t\t %d,%d\n",age_year,age_month);
}
void _Health(){
    printf("Health:\t\t %d/%d ",current_health,total_health); loading_bar(30*(current_health/(float)total_health));
}
void _Money_and_Savings(){
    printf("Money: %d\t Saving: %d\n",momey,saving);
    printf("\n");
}
void _Trasport(){
    printf("Transport:\t ");
    cprinter( 0, 0);
}
void _Lodging(){
    printf("Lodging:\t ");
    cprinter( 1, 0);
}
void _Education(){
    printf("Education:\t ");
    cprinter( 2, 0);
}
void _Food_and_Health_show(){
    printf("|__<<____[ Buy Food(7) ]_____________[ Buy Health(9) ]_____>>__|\n");
}
void _Main_Menu_Bar(){
    printf("\n|_<<___Home(0)__Work(1)__Shop(2)__Skill(3)__Save&Exit(4)___>>_| Pick: ");
    scanf("%d",&menu_chooes_int);   
}

void main_menu(){
    //printf("  ______              _ \n");
    //printf(" |  ____|            | |\n");
    //printf(" | |__ ___   ___   __| |\n");
    //printf(" |  __/ _ \\ / _ \\ / _` |\n");
    //printf(" | | | (_) | (_) | (_| |\n");
    //printf(" |_|  \\___/ \\___/ \\__,_|\n");
    menu_chooes_int=0;
    do{

    switch (menu_chooes_int)
    {
        case 0:
        printf("______Home(0)___________________\n");
        _Name();
        _Age();
        _Food();
        _Health();
        _Money_and_Savings();

        _Trasport();
        _Lodging();
        _Education();
        _Food_and_Health_show();
        break;

        case 1:
        break;

        case 2:
        break;

        case 3:
        break;

        case 4:
        exit(1);
        break;

        case 7:
        system("cls");
        //system("Echo ^G");
        _Food();
        _Health();
        food_lister();
        
        break;

        case 8:
        break;

        default:
        
        break;
    }
        _Main_Menu_Bar();
    }while (1);
    {
        /* code */
    }
    
    //printf("");
    //printf("");
    //printf("");
}
char food[7][40]={"Eat hotdog","Eat fastfood","Eat microwave meal","Eat Self made meal","Eat in cheap restaurant","Eatin expensive restaurant","Eat from private chef"};
int food_price[8]={0,5,15,30,50,100,200,500};
void food_lister(){
        printf("_Food______________________\n");
        for (int i = 0; i < 7; i++)
        {
        looper(i,food_price[i],0);
        }
        
}
void looper(int list,int money_needed,int chozen_one){
    if( momey>=money_needed){
        printf("[+] ");
    }
    else
    {
        printf("[X] ");
    }
    int i=0;
    switch (chozen_one)
    {
    case 0:
    for (; food[list][i]!=0 ; i++)
    {
        printf("%c",food[list][i]);
    }
    for (; i < 100-i; i++)
    {
        printf(" ");
    }
    printf("%d",food_price[list]);    
    break;
    
    default:
        break;
    }
    printf("\n");
}

void cprinter(int dddef_choi, int pppic){
    switch (dddef_choi)
    {
    case 0:
        for (int i = 0; trasport[pppic][i] !=0 ; i++)
        {
            printf("%c",trasport[pppic][i]);
        }
        break;
    case 1:
        for (int i = 0; lodging[pppic][i] !=0 ; i++)
        {
            printf("%c",lodging[pppic][i]);
        }
        break;
    case 2:
        for (int i = 0; Education[pppic][i] !=0 ; i++)
        {
            printf("%c",Education[pppic][i]);
        }
        break;
    case 3:
        
        break;
    default:
        break;
    }
    printf("\n");
}

void loading_bar(int size){
    printf("\t|");
    for (int i = 0; i < 30-size; i++)
    {
    printf(" ");
    }
    for (int i = 0; i < size; i++)
    {
    printf("%c",178);
    }
    printf("|");
    printf("\n");
}
void c(){
    system("cls");
    printf("_____");
    
}

