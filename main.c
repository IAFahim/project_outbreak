#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <math.h>
#include <windows.h>

//declare

int age_year=18,age_month=0,age_day=0,currnt_hunger=300,total_hunger=300,current_health=300,total_health=300,momey=0,saving=0;
char menu_chooes_int;
bool newgame=1,wait=0;
char name[50]="Charecter_Fahim";
char trasport[10][25]={"Barefoot","Shoe","Bus","Cycle"};
char lodging[10][25]={"Cardboard Box","","",""};
char Education[10][25]={"None","","",""};
    FILE * fp;
//protoyepring
void _Food_save(int add_or_reduce);
bool _Food_save_cheaker(int add_or_reduce);
void food_lister();
void spacer();
void frist_time_opening_the_game();
void main_menu();
void _Name();
void _Food();
void _Age_year_month_day();
void _Age_year_save();
void _Age_month_save(int month);
void _Age_day_save(int day);
void _Age_day();
void _Health();
void _Health_save(int add_or_reduce);
bool _Health_save_checker(int add_or_reduce);
void loading_bar(int size);
void _Trasport();
void _Lodging();
void _Education();
void cprinter(int dddef_choi, int pppic);
void _Food_and_Health_show();
void _Main_Menu_Bar();
void _Money();
void _Money_save(int add_or_reduce);
bool _Money_save_cheaker(int add_or_reduce);
void _Savings();
void _Saving_save(int add_to_saving);
//main
void death(){
    age_year=18,age_month=0,currnt_hunger=300,total_hunger=300,momey=0,saving=0;
    frist_time_opening_the_game();
}

void main(){
    //new game_read_cheak
    if((fp=fopen("newgame.txt","r"))==NULL){
        frist_time_opening_the_game();
    }
    fclose(fp);
    printf("__Welcome To Life simulator");
    //hunger_load
    main_menu();
}
char ng[40]="newgame.txt";
void frist_time_opening_the_game(){
    //chacking if its a new game
    fp=fopen(ng,"w");
    fprintf(fp,"%d",0);
    fclose(fp);
    //name_save

    fp=fopen("name.txt","w");
    fprintf(fp,"%s",name);
    fclose(fp);
    //hunger_save

    fp=fopen("hunger.txt","w");
    fprintf(fp,"%d",currnt_hunger);
    fclose(fp);
    //health_save

    fp=fopen("health.txt","w");
    fprintf(fp,"%d",current_health);
    fclose(fp);
    //money_save

    fp=fopen("money.txt","w");
    fprintf(fp,"%d",momey);
    fclose(fp);
    //savings_save

    fp=fopen("health.txt","w");
    fprintf(fp,"%d",current_health);
    fclose(fp);
    //age_year_save

    fp=fopen("age_year.txt","w");
    fprintf(fp,"%d",age_year);
    fclose(fp);
    //age_day_save

    fp=fopen("age_day.txt","w");
    fprintf(fp,"%d",age_day);
    fclose(fp);
    //saving_save

    fp=fopen("savings.txt","w");
    fprintf(fp,"%d",saving);
    fclose(fp);
}
void _Name(){
    //name_load
    fp=fopen("name.txt","r");
    fscanf(fp, "%s", &name);
    printf("%s\n", name );
    fclose(fp);
}
void _Food(){
    fp=fopen("hunger.txt","r");
    fscanf(fp, "%d", &currnt_hunger);
    fclose(fp);
    printf("Hunger:\t\t %d/%d ",currnt_hunger,total_hunger); loading_bar(30*(currnt_hunger/(float)total_hunger));
}
bool _Food_save_cheaker(int add_or_reduce){
    if(currnt_hunger==300 && add_or_reduce>0){
        spacer();
        printf("You can\'t buy this stuff. You have No hunger");
        wait=1;
        return 0;
    }
    currnt_hunger+=add_or_reduce;
    if(currnt_hunger>300){
    currnt_hunger=300;
    return 1;
    }
    return 1;
}
void _Food_save(int add_or_reduce){
    if(currnt_hunger<=0){
    currnt_hunger=0;
    //death();
    }
    fp=fopen("hunger.txt","w");
    fprintf(fp, "%d", currnt_hunger);
    fclose(fp);
    wait=0;
}
void _Age_year_month_day(){
    fp=fopen("age_day.txt","r");
    fscanf(fp, "%d", &age_day);
    fclose(fp);
    fp=fopen("age_year.txt","r");
    fscanf(fp, "%d", &age_year);
    fclose(fp);
    printf("Age:\t\t Y-%d D-%d\n",age_year,age_day);
}
void _Age_year_save(){
    fp=fopen("age_year.txt","w");
    fprintf(fp, "%d", ++age_year);
    fclose(fp);
}
void _Age_day(){
    fp=fopen("age_day.txt","r");
    fscanf(fp, "%d", &age_day);
    fclose(fp);
    printf("Age:\t\t %d,%d\n",age_year,age_month);
}
void _Age_day_save(int day){
    if(day+age_day>365){
        age_day=(day+age_day)-365;
        _Age_year_save();
    }else{
        age_day+=day;
    }
    fp=fopen("age_day.txt","w");
    fprintf(fp, "%d", age_day);
    fclose(fp);
    main_menu();
}
void _Health(){
            
    fp=fopen("health.txt","r");
    fscanf(fp, "%d", &current_health);
    fclose(fp);
    printf("Health:\t\t %d/%d ",current_health,total_health); loading_bar(30*(current_health/(float)total_health));
}
bool _Health_save_checker(int add_or_reduce){
    if(current_health==300 && add_or_reduce>0){
        spacer();
        printf("You can\'t buy this stuff. You have Full health");
        wait=1;
        return 0;
    }
    current_health+=add_or_reduce;
    if(current_health>300){
    current_health=300;
    return 1;
    }
    return 1;
    }
void _Health_save(int add_or_reduce){
    if(current_health<=0){
        current_health=0;
        //death();
    }
    fp=fopen("health.txt","w");
    fprintf(fp, "%d", current_health);
    fclose(fp);
    wait=0;
}
void _Money(){
    fp=fopen("money.txt","r");
    fscanf(fp, "%d", &momey);
    fclose(fp);
    printf("Money: %d\t ",momey);
}
bool _Money_save_cheaker(int add_or_reduce){
    int temp=momey;
    if((temp+=add_or_reduce)<0){
    spacer();
    printf("You can\'t buy this stuff. You Need %d",-(add_or_reduce+momey));
    wait=1;
    return false;
    }else{
    momey+=add_or_reduce;
    }
    wait=0;
    return true;
}
void _Money_save(int add_or_reduce){
    fp=fopen("money.txt","w");
    fprintf(fp, "%d", momey);
    fclose(fp);
}
void _Savings(){
    printf("Saving: %d\n",saving);
    printf("\n");
}
void _Saving_save(int add_to_saving){
    saving+=add_to_saving;
    fp=fopen("savings.txt","w");
    fprintf(fp, "%d", saving);
    fclose(fp);
}
int trasport_postion=0;
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
    
    printf("|__<<____[ Buy Food(7) ]____________[ Buy Health(9) ]_____>>__|\n");
}
char prevoius_menu;
void _Main_Menu_Bar(){
    printf("\n|_<<___Home(0)__Work(1)__Shop(2)__Skill(3)__Save&Exit(X)___>>_| Pick: ");
    scanf("%c",&menu_chooes_int);
    fflush(stdin);
}
void main_menu(){
    //printf("  ______              _ \n");
    //printf(" |  ____|            | |\n");
    //printf(" | |__ ___   ___   __| |\n");
    //printf(" |  __/ _ \\ / _ \\ / _` |\n");
    //printf(" | | | (_) | (_) | (_| |\n");
    //printf(" |_|  \\___/ \\___/ \\__,_|\n");
    menu_chooes_int='0';
    int Food_add_red=0,health_add_red=0,money_add_red=0,day_add=0;
    do{

    switch (menu_chooes_int)
    {
        case '0':
        prevoius_menu=menu_chooes_int;
        system("cls");
        system("color 02");
        //system("mode 75,50");
        printf("___Home(0)______________________________________________\n");
        _Name();
        spacer();//just to look good _he he
        _Age_year_month_day(); 
        spacer();//just to look good _he he
        _Food();
        spacer();//just to look good _he he
        _Health();
        spacer();//just to look good _he he
        _Money();
        _Savings();
        spacer();//just to look good _he he
        _Trasport();
        spacer();//just to look good _he he
        _Lodging();
        spacer();//just to look good _he he
        _Education();
        _Food_and_Health_show();
        break;

        case '1':
        prevoius_menu=menu_chooes_int;
        system("cls");
        printf("_______Work(1)__________________________________________\n");
        break;

        case '2':
        prevoius_menu=menu_chooes_int;
        system("cls");
        printf("____________Shop(2)____________________________________\n");
        break;

        case '3':
        prevoius_menu=menu_chooes_int;
        system("cls");
        printf("____________________Skills(3)__________________________\n");
        break;

        case 'x':case 'X':
        exit(1);
        break;

        case '7':
        prevoius_menu=menu_chooes_int;
        system("cls");
        //system("Echo ^G");
        _Food();
        _Health();
        _Money();
        _Savings();
        food_lister();
        
        break;

        case '9':
        prevoius_menu=menu_chooes_int;
        system("cls");
        //system("Echo ^G");
        _Food();
        _Health();
        _Money();
        _Savings();
        health_lister();
        break;

        case 'a':case 'A':

        switch (prevoius_menu)
        {
        case '7'://eat_garvage
            Food_add_red=5,health_add_red=-5,day_add=1;
            if( _Health_save_checker(health_add_red)&& _Food_save_cheaker(Food_add_red)){
                _Food_save(Food_add_red);_Health_save(health_add_red) ;_Age_day_save(day_add);
            }else{
                break;
            }
        case '9'://pills from trash
            health_add_red=5,Food_add_red=-5,day_add=1;
            if(_Health_save_checker(health_add_red)&& _Food_save_cheaker(Food_add_red)){
                _Health_save(health_add_red);_Food_save(Food_add_red);_Age_day_save(day_add);
            }else{
                break;
            }
        }

        break;
        case 'b':case 'B':

        switch (prevoius_menu)
        {
        case '7'://Eat hotdog
            money_add_red=-5,Food_add_red=10,health_add_red=-1,day_add=1;
            if(_Money_save_cheaker(money_add_red)&& _Health_save_checker(health_add_red)&& _Food_save_cheaker(Food_add_red)){
                _Money_save(money_add_red); _Food_save(Food_add_red);_Health_save(health_add_red) ;_Age_day_save(day_add);
            }else{
                break;
            }
        case '9'://sleep
            money_add_red=-5,health_add_red=15,Food_add_red=-5,day_add=1;
            if(_Money_save_cheaker(money_add_red)&& _Health_save_checker(health_add_red)&& _Food_save_cheaker(Food_add_red)){
                _Money_save(money_add_red);_Health_save(health_add_red);_Food_save(Food_add_red);_Age_day_save(day_add);
            }else{
                break;
            }
        }
        break;
        case 'c':case 'C':
        switch (prevoius_menu)
        {
        case '7'://Eat fastfood
            money_add_red=-15,Food_add_red=20,day_add=1;
            if(_Money_save_cheaker(money_add_red)&&_Food_save_cheaker(Food_add_red)){
                _Money_save(money_add_red); _Food_save(Food_add_red);_Age_day_save(day_add);
            }else{
                break;
            }
        case '9'://Go to Grandma
            money_add_red=-15,health_add_red=20,Food_add_red=-5,day_add=1;
            if(_Money_save_cheaker(money_add_red)&& _Health_save_checker(health_add_red)&& _Food_save_cheaker(Food_add_red)){
                _Money_save(money_add_red);_Health_save(health_add_red);_Food_save(Food_add_red);_Age_day_save(day_add);
            }else{
                break;
            }
        }
        break;
        case 'd':case 'D':
        switch (prevoius_menu)
        {
        case '7'://Eat microwave meal
            money_add_red=-30,Food_add_red=40,day_add=1;
            if(_Money_save_cheaker(money_add_red)&&_Food_save_cheaker(Food_add_red)){
                _Money_save(money_add_red); _Food_save(Food_add_red);_Age_day_save(day_add);
            }else{
                break;
            }
        case '9'://Paracetamol
            money_add_red=-30,health_add_red=40,Food_add_red=-5,day_add=1;
            if(_Money_save_cheaker(money_add_red)&& _Health_save_checker(health_add_red)&& _Food_save_cheaker(Food_add_red)){
                _Money_save(money_add_red);_Health_save(health_add_red);_Food_save(Food_add_red);_Age_day_save(day_add);
            }else{
                break;
            }
        }
        break;
        case 'e':case 'E':

        switch (prevoius_menu)
        {
        case '7'://Eat Self made meal
            money_add_red=-50,Food_add_red=70,day_add=1;
            if(_Money_save_cheaker(money_add_red)&&_Food_save_cheaker(Food_add_red)){
                _Money_save(money_add_red); _Food_save(Food_add_red);_Age_day_save(day_add);
            }else{
                break;
            }
        case '9'://Clinic
            money_add_red=-50,health_add_red=70,Food_add_red=-5,day_add=1;
            if(_Money_save_cheaker(money_add_red)&& _Health_save_checker(health_add_red)&& _Food_save_cheaker(Food_add_red)){
                _Money_save(money_add_red);_Health_save(health_add_red);_Food_save(Food_add_red);_Age_day_save(day_add);
            }else{
                break;
            }
        }
        break;
        case 'f':case 'F':

        switch (prevoius_menu)
        {
        case '7'://Eat in cheap restaurant
            money_add_red=-100,Food_add_red=100,day_add=1;
            if(_Money_save_cheaker(money_add_red)&&_Food_save_cheaker(Food_add_red)){
                _Money_save(money_add_red); _Food_save(Food_add_red);_Age_day_save(day_add);
            }else{
                break;
            }
        case '9'://Polyclinic
            money_add_red=-100,health_add_red=100,Food_add_red=-10,day_add=2;
            if(_Money_save_cheaker(money_add_red)&& _Health_save_checker(health_add_red)&& _Food_save_cheaker(Food_add_red)){
                _Money_save(money_add_red);_Health_save(health_add_red);_Food_save(Food_add_red);_Age_day_save(day_add);
            }else{
                break;
            }
        }
        break;
        case 'g':case 'G':
        switch (prevoius_menu)
        {
        case '7'://Eatin expensive restaurant
            money_add_red=-200,Food_add_red=200,day_add=1;
            if(_Money_save_cheaker(money_add_red)&&_Food_save_cheaker(Food_add_red)){
                _Money_save(money_add_red); _Food_save(Food_add_red); _Age_day_save(day_add);
            }else{
                break;
            }
        case '9'://Doctor
            money_add_red=-200,health_add_red=200,Food_add_red=-10,day_add=2;
            if(_Money_save_cheaker(money_add_red)&& _Health_save_checker(health_add_red)&& _Food_save_cheaker(Food_add_red)){
                _Money_save(money_add_red);_Health_save(health_add_red);_Food_save(Food_add_red);_Age_day_save(day_add);
            }else{
                break;
            }
        }
        break;
        case 'h':case 'H':
        switch (prevoius_menu)
        {
        case '7'://Eat from private chef
            money_add_red=-500,Food_add_red=300,health_add_red=10,day_add=3;
            if(_Money_save_cheaker(money_add_red)&&_Food_save_cheaker(Food_add_red)&&_Health_save_checker(health_add_red)){
                _Money_save(money_add_red); _Food_save(Food_add_red); _Health_save(health_add_red); _Age_day_save(day_add);
            }else{
                break;
            }
        case '9'://hospoital
            money_add_red=-500,health_add_red=300,Food_add_red=-15,day_add=3;
            if(_Money_save_cheaker(money_add_red)&& _Health_save_checker(health_add_red)&& _Food_save_cheaker(Food_add_red)){
                _Money_save(money_add_red);_Health_save(health_add_red);_Food_save(Food_add_red);_Age_day_save(day_add);
            }else{
                break;
            }
        break;
        case 'i':case 'I':

        break;
        default:

        break;
    }
    }
    if(wait&&(menu_chooes_int>="a"&&menu_chooes_int<="Z")){
        main_menu();
    }
        _Main_Menu_Bar();
    }while (1);
}
char food[8][40]={"Eat trash","Eat hotdog","Eat fastfood","Eat microwave meal","Eat Self made meal","Eat in cheap restaurant","Eatin expensive restaurant","Eat from private chef"};
int food_price[8]={0,5,15,30,50,100,200,500};
void food_lister(){
        printf("____________________Food(7)______________________\n");
        for (int i = 0; i < 8; i++)
        {
        looper(i,food_price[i],0);
        }
}
char health_care_name[8][40]={"Pills from Trash","Sleep","Go to Grandma","Paracetamol","Clinic","Polyclinic","Doctor","Hospital"};
int health_care_price[8]={0,5,15,30,50,100,200,500};
void health_lister(){
        printf("____________________health(9)______________________\n");
        for (int i = 0; i < 8; i++)
        {
        looper(i,health_care_price[i],1);
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
    case 0://food
    for (; food[list][i]!=0 ; i++)
    {
        printf("%c",food[list][i]);
    }
    printf(" (%c)",65+list);
    for (; i < 100-i; i++)
    {
        printf(" ");
    }
    printf("%d",food_price[list]);
    break;
    
    case 1://health
    for (; health_care_name[list][i]!=0 ; i++)
    {
        printf("%c",health_care_name[list][i]);
    }
    printf(" (%c)",65+list);
    for (; i < 100-i; i++)
    {
        printf(" ");
    }
    printf("%d",health_care_price[list]);
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
void spacer(){
printf("|\t");
}
void gotoxy(int x, int y)
{
COORD coord;
coord.X = x;
coord.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
