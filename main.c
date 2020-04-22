#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <math.h>
#include <windows.h>

//declare
char job[26][50]={"Beg","Wash cars","Work at the Supermarket","Fastfood Worker","Postman","Small Part Time Job","Food Deliverer","Costraction Worker","Bus Driver","Driver","Administrative Workers","Policeman","Goverment Worker","Programmer","Bank Clerk","News Repoeter","Actor","Military Employee","Office Mannager","Police Officer","Senior Programer","Supermarket Owner","Office CEO","Big YouTuber","Military Officer","President"};
int job_salary[26]={1,5,20,30,50,60,70,100,140,150,170,200,250,350,500,600,700,750,800,1000,1400,4000,6000,12000,30000,60000};
char health_care_name[8][40]={"Pills from Trash","Sleep","Homiopaty(totally useless)","Paracetamol And Rest","Small Clinic","Big Clinic","The Nice Doctor Next Door","Hospital"};
int health_care_price[8]={0,5,15,30,50,100,200,500};
char education_name[8][50]={"Learned to Talk","Basic Mathmematics","Finish School","Know How to use Basic Tools","Finish College","Have a Deploma","Finish University","A Phd"};
int education_buying_cost[8]={0,100,7500,10000,13000,25000,20000,100000};
char trasport_name[8][30]={"Barefoot","Shoes","Bicycle","Small Old small Car","Motorcycle","Pick-up Truck","Expesive Car","Helicoper"};
int trasport_buying_cost[8]={0,40,500,3000,20000,25000,100000,200000};
char food[8][40]={"Eat trash","Eat hotdog","Eat fastfood","Eat microwave meal","Eat Self Made Meal","Eat in Cheap Restaurant","Eatin Expensive Restaurant","Eat from Private Chef"};
int food_price[8]={0,5,15,30,50,100,200,500};

char prevoius_menu;
char trasport_save_loction[]={"traspot.txt"};
char education_save_loction[]={"education.txt"};
int age_year=18,age_month=0,age_day=0,currnt_hunger=300,total_hunger=300,current_health=300,total_health=300,momey=0,saving=0;
char menu_chooes_int,trasport_own_till=0;
bool newgame=1,wait=0;
char name[50]="Charecter_Fahim";
char lodging[10][25]={"Cardboard Box","","",""};
char Education[10][25]={"None","","",""};
    FILE * fp;
//protoyepring
void trasport_lister();
void looper(int list,int money_needed,int chozen_one);
void _Food_save(int add_or_reduce);
bool _Food_save_cheaker(int add_or_reduce);
void food_lister();
void spacer();
void health_lister();
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
void _trasport_save();
bool _trasport_chacker(int pos);
void job_lister();
void job_looper(int list,int jobs_salary,int chozen_one);
void _Lodging();
void _Education();
bool _education_chacker(int pos);
void  _education_save();
void cprinter(int dddef_choi, int pppic);
void _Main_Menu_Bar();
void _Money();
void _Money_save(int add_or_reduce);
bool _Money_save_cheaker(int add_or_reduce);
void _Savings();
void _Saving_save(int add_to_saving);
void conditon_less_looper_print(int dddef_choi, int pppic);
//main
void death(){
    age_year=18,age_month=0,currnt_hunger=300,total_hunger=300,momey=0,saving=0;
    frist_time_opening_the_game();
}
void food_lister(){
        printf("____________________Food(7)______________________\n");
        for (int i = 0; i < 8; i++)
        {
        looper(i,food_price[i],0);
        printf("\n");

        }
}
void trasport_lister(){
        for (int i = 0; i < 8; i++)
        {
        looper(i,trasport_buying_cost[i],2);
        if(i<=trasport_own_till){
            printf("   [Owned]");
        }
        printf("\n");
        }
}
int education_own_till=0;
void education_lister(){
        for (int i = 0; i < 8; i++)
        {
        looper(i,education_buying_cost[i],3);
        if(i<=education_own_till){
            printf("   [Owned]");
        }
        printf("\n");
        }
}
void health_lister(){
        printf("____________________health(9)______________________\n");
        for (int i = 0; i < 8; i++)
        {
        looper(i,health_care_price[i],1);
        printf("\n");
        }
}
void job_lister(){
        printf("____________________job(4)______________________\n");
        for (int i = 0; i < 26; i++)
        {
        job_looper(i,job_salary[i],0);
        }
}
void job_looper(int list,int jobs_salary,int chozen_one){//job looper
    int i=0;
    switch(chozen_one){
        case 0:
        for (; job[list][i]!=0 ; i++)
        {
            printf("%c",job[list][i]);
        }
        printf(" (%c)",65+list);
        for (; i < 100-i; i++)
        {
            printf(" ");
        }
        printf("%d",job_salary[list]);
        break;
    }
    printf("\n");
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

    case 2://TRASOPORT
        for (; trasport_name[list][i]!=0 ; i++)
        {
            printf("%c",trasport_name[list][i]);
        }
        //printf(" (%c)",65+list);
        for (; i < 100-i; i++)
        {
            printf(" ");
        }
        printf("%d",trasport_buying_cost[list]);
        if(list==trasport_own_till+1){
        printf(" (%c to buy next)",65+list);
        }
    break;
    case 3://TRASOPORT
        for (; education_name[list][i]!=0 ; i++)
        {
            printf("%c",education_name[list][i]);
        }
        //printf(" (%c)",65+list);
        for (; i < 100-i; i++)
        {
            printf(" ");
        }
        printf("%d",education_buying_cost[list]);
        if(list==education_own_till+1){
        printf(" (%c to buy next)",65+list);
        }
    break;
    default:
        break;
    }
}

void cprinter(int dddef_choi, int pppic){
    switch (dddef_choi)
    {
    case 1:
        for (int i = 0; lodging[pppic][i] !=0 ; i++)
        {
            printf("%c",lodging[pppic][i]);
        }
        break;
    case 0:
        for (int i = 0; trasport_name[pppic][i] !=0 ; i++)
        {
            printf("%c",trasport_name[pppic][i]);
        }
        break;
    case 2:
        for (int i = 0; education_name[pppic][i] !=0 ; i++)
        {
            printf("%c",education_name[pppic][i]);
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
    //trasoport_save

    fp=fopen(trasport_save_loction,"w");
    fprintf(fp, "%d", trasport_own_till);
    fclose(fp);
    //eucation

    fp=fopen(education_save_loction,"w");
    fprintf(fp, "%d", education_own_till);
    fclose(fp);
}

char name_save_location[]="name.txt";
void _Name(){
    //name_load
    fp=fopen("name.txt","r");
    fscanf(fp, "%s", &name);
    printf("%s\n", name );
    fclose(fp);
}
char hunger_save_location[]="hunger.txt";
void _Food(){
    fp=fopen(hunger_save_location,"r");
    fscanf(fp, "%d", &currnt_hunger);
    fclose(fp);
    printf("Hunger:\t\t %d/%d ",currnt_hunger,total_hunger); loading_bar(30*(currnt_hunger/(float)total_hunger));
}
bool _Food_save_cheaker(int add_or_reduce){
    if(currnt_hunger==300 && add_or_reduce>0&& prevoius_menu=='7'){
        spacer();
        printf("You can\'t buy this stuff. You have No hunger");
        wait=1;
        return 0;
    }
    wait=0;
    return 1;
}
void _Food_save(int add_or_reduce){
    currnt_hunger+=add_or_reduce;
    if(currnt_hunger>300){
    currnt_hunger=300;
    }
    if(currnt_hunger<=0){
    currnt_hunger=0;
    //death();
    }
    
    fp=fopen(hunger_save_location,"w");
    fprintf(fp, "%d", currnt_hunger);
    fclose(fp);
    wait=0;
}
char age_day_save_location[]="age_day.txt";
char age_year_save_location[]="age_year.txt";
void _Age_year_month_day(){
    fp=fopen(age_day_save_location,"r");
    fscanf(fp, "%d", &age_day);
    fclose(fp);
    fp=fopen(age_year_save_location,"r");
    fscanf(fp, "%d", &age_year);
    fclose(fp);
    printf("Age:\t\t Y-%d D-%d\n",age_year,age_day);
}
void _Age_year_save(){
    fp=fopen(age_year_save_location,"w");
    fprintf(fp, "%d", ++age_year);
    fclose(fp);
}
void _Age_day(){
    fp=fopen(age_day_save_location,"r");
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
    fp=fopen(age_day_save_location,"w");
    fprintf(fp, "%d", age_day);
    fclose(fp);
    main_menu();
}
char health_save_location[]="health.txt";
void _Health(){

    fp=fopen(health_save_location,"r");
    fscanf(fp, "%d", &current_health);
    fclose(fp);
    printf("Health:\t\t %d/%d ",current_health,total_health); loading_bar(30*(current_health/(float)total_health));
}
bool _Health_save_checker(int add_or_reduce){
    if(current_health==300 && add_or_reduce>0 && prevoius_menu=='9'){
        spacer();
        printf("You can\'t buy this stuff. You have Full health");
        wait=1;
        return 0;
    }else{
        wait=0;
        return 1;
    }
    }
void _Health_save(int add_or_reduce){
    current_health+=add_or_reduce;
    if(current_health>300){
    current_health=300;
    }
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
    wait=0;
    return true;
    }
}
bool _trasport_chack_before_a_job(int pos){
    if(pos<=trasport_own_till){
        wait=1;
        return 1;
    }else{
        conditon_less_looper_print(0,pos);
        printf(" you need to unlock this first");
        wait=0;
        return 0;
    }
}
bool _trasport_chacker(int pos){
    if(pos<=trasport_own_till){
        printf("You already own this item");
        wait=1;
        return 0;
    }
    if(pos==0){
        wait=0;
        return 1;
    }
    if(pos==trasport_own_till+1){
        return 1;
    }else{
        conditon_less_looper_print(0,trasport_own_till+1);
        printf(" you need to unlock this first");
        wait =1;
        return 0;       
    }
}
bool _education_chack_before_a_job(int pos){
    if(pos<=education_own_till){
        wait=1;
        return 1;
    }else{
        conditon_less_looper_print(1,pos);
        printf(" you need to unlock this first");
        wait=0;
        return 0;
    }
}
bool _education_chacker(int pos){
    if(pos<=education_own_till){
        printf("You already own this item");
        wait=1;
        return 0;
    }
    if(pos==education_own_till+1){
        wait=0;
        return 1;
    }else{
        conditon_less_looper_print(1,education_own_till+1);
        printf(" you need to unlock this first");
        wait=1;
        return 0;       
    }
}
void conditon_less_looper_print(int dddef_choi, int pppic){
    switch (dddef_choi)
    {
    case 0:
    for (int i = 0; trasport_name[pppic][i] !=0 ; i++)
        {
            printf("%c",trasport_name[pppic][i]);
        }
    break;       
    case 1:
    for (int i = 0; education_name[pppic][i] !=0 ; i++)
        {
            printf("%c",education_name[pppic][i]);
        }
    break;       
    }
}
void _Money_save(int add_or_reduce){
    momey+=add_or_reduce;
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
void _Trasport(){
    printf("Transport:\t ");
    fp=fopen(trasport_save_loction,"r");
    fscanf(fp, "%d", &trasport_own_till);
    fclose(fp);
    cprinter( 0, trasport_own_till);
}
void _trasport_save(){
        fp=fopen(trasport_save_loction,"w");
        fprintf(fp, "%d", ++trasport_own_till);
        fclose(fp);
}
void _Lodging(){
    printf("Lodging:\t ");
    cprinter( 1, 0);
}
void _Education(){
    printf("Education:\t ");
    fp=fopen(education_save_loction,"r");
    fscanf(fp, "%d", &education_own_till);
    fclose(fp);
    cprinter( 2, 0);
}
void  _education_save(){
        fp=fopen(trasport_save_loction,"w");
        fprintf(fp, "%d", ++trasport_own_till);
        fclose(fp);
}
int x=200,y=0;

void gotoxy()
{
COORD coord;
printf("|");
coord.X = x;
coord.Y = y++;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void _Main_Menu_Bar(){
    printf("|__<<_____ Buy Food(7) ]____________[ Buy Health(9) ]_____>>__|\n");
    printf("\n|_<<___Home(0)__Work(1)__Shop(2)__Skill(3)__Save&Exit(~)___>>_| Pick: ");
    scanf("%c",&menu_chooes_int);
    fflush(stdin);
    
}
int trasport_needed=0,education_needed=0;
void main_menu(){
    //system("mode 800");
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
        //spacer();//just to look good _he he
        //_Lodging();
        spacer();//just to look good _he he
        _Education();
        break;

        case '1':
        prevoius_menu=menu_chooes_int;
        system("cls");
        printf("_______Work(1)__________________________________________\n");
        switch (prevoius_menu)//get your jobs here
        {
        case '1':
            spacer();//just to look good _he he
            _Food();
            spacer();//just to look good _he he
            _Health();
            spacer();//just to look good _he he
            _Money();
            spacer();//just to look good _he he
            _Savings();
            job_lister();
        //job_lister
        break;
        }
        break;

        case '2':
        prevoius_menu=menu_chooes_int;
        system("cls");
        printf("____________Shop(2)____________________________________\n");
        switch (prevoius_menu)//get your jobs here
        {
        case '2':
            spacer();//just to look good _he he
            _Food();
            spacer();//just to look good _he he
            _Health();
            spacer();//just to look good _he he
            _Money();
            _Savings();
            spacer();
            _Trasport();
            trasport_lister();
                //job_lister
        break;
        }
        break;

        case '3':
            prevoius_menu=menu_chooes_int;
            system("cls");
            printf("____________________Skills(3)__________________________\n");
            switch (prevoius_menu)//get your jobs here
            {
            case '3':
                spacer();//just to look good _he he
                _Food();
                spacer();//just to look good _he he
                _Health();
                spacer();//just to look good _he he
                _Money();
                _Savings();
                spacer();
                _Education();
                education_lister();
                    //job_lister
            break;
            }
        break;

        case '~':
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
        case '1'://work Beg
            Food_add_red=-5;money_add_red=job_salary[0];education_needed=0;trasport_needed=0;health_add_red=-1;
            if(_trasport_chack_before_a_job(trasport_needed)&&_education_chack_before_a_job(education_needed)){
                _Food_save(Food_add_red); _Money_save(money_add_red); _Age_day_save(1); _Health_save(health_add_red) ;
            }else
            {
                break;
            }
        break;
        case '2'://buy stuff
            money_add_red=-trasport_buying_cost[0];
            if(_Money_save_cheaker(money_add_red)&&_trasport_chacker(0)){
                _Money_save(money_add_red); _trasport_save(); _Age_day_save(1);
            }else{
                break;
            }
        break;
        case '3'://education stuff
            money_add_red=-education_buying_cost[0];
            if(_Money_save_cheaker(money_add_red)&&_education_chacker(0)){
                _Money_save(money_add_red); _education_save(); _Age_day_save(1);
            }else{
                break;
            }
        break;
        case '7'://eat_garvage
            Food_add_red=5,health_add_red=-5,day_add=1;
            if( _Health_save_checker(health_add_red)&& _Food_save_cheaker(Food_add_red)){
                _Food_save(Food_add_red);_Health_save(health_add_red) ;_Age_day_save(day_add);
            }else{
                break;
            }
        break;
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
        case '1'://work Wash cars
            Food_add_red=-5;money_add_red=job_salary[1];education_needed=0;trasport_needed=1;health_add_red=-2;
            if(_trasport_chack_before_a_job(trasport_needed)&&_education_chack_before_a_job(education_needed)){
                _Food_save(Food_add_red); _Money_save(money_add_red); _Age_day_save(1); _Health_save(health_add_red);
            }else
            {
                break;
            }
        break;
        
        case '3'://education stuff
            money_add_red=-education_buying_cost[1];
            if(_Money_save_cheaker(money_add_red)&&_education_chacker(1)){
                _Money_save(money_add_red); _education_save();_Age_day_save(30); _Age_day_save(1);
            }else{
                break;
            }
        break;
        case '2'://buy stuff
            money_add_red=-trasport_buying_cost[1];
            if(_Money_save_cheaker(money_add_red)&&_trasport_chacker(1)){
                _Money_save(money_add_red); _trasport_save(); _Age_day_save(1);
            }else{
                break;
            }
        break;
        case '7'://Eat hotdog
            money_add_red=-5,Food_add_red=10,health_add_red=-1,day_add=1;
            if(_Money_save_cheaker(money_add_red)&& _Health_save_checker(health_add_red)&& _Food_save_cheaker(Food_add_red)){
                _Money_save(money_add_red); _Food_save(Food_add_red);_Health_save(health_add_red) ;_Age_day_save(day_add);
            }else{
                break;
            }
        break;
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
        case '1'://work Work at the Supermarket
            Food_add_red=-5;money_add_red=job_salary[2];education_needed=1;trasport_needed=1;health_add_red=-5;
            if(_trasport_chack_before_a_job(trasport_needed)&&_education_chack_before_a_job(education_needed)){
                _Food_save(Food_add_red); _Money_save(money_add_red); _Age_day_save(1);_Health_save(health_add_red) ;
            }else
            {
                break;
            }

        break;
        
        case '3'://education stuff
            money_add_red=-education_buying_cost[2];
            if(_Money_save_cheaker(money_add_red)&&_education_chacker(2)){
                _Money_save(money_add_red); _education_save(); _Age_day_save(1);
            }else{
                break;
            }
        break;
        case '2'://buy stuff
            money_add_red=-trasport_buying_cost[2];
            if(_Money_save_cheaker(money_add_red)&&_trasport_chacker(2)){
                _Money_save(money_add_red); _trasport_save(); _Age_day_save(1);
            }else{
                break;
            }
        break;
        case '7'://Eat fastfood
            money_add_red=-15,Food_add_red=20,day_add=1;
            if(_Money_save_cheaker(money_add_red)&&_Food_save_cheaker(Food_add_red)){
                _Money_save(money_add_red); _Food_save(Food_add_red);_Age_day_save(day_add);
            }else{
                break;
            }
        break;
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
            case '1'://work Fastfood Worker
            Food_add_red=-5;money_add_red=job_salary[3];education_needed=1;trasport_needed=1;health_add_red=-10;
            if(_trasport_chack_before_a_job(trasport_needed)&&_education_chack_before_a_job(education_needed)){
                _Food_save(Food_add_red); _Money_save(money_add_red); _Age_day_save(7); _Health_save(health_add_red) ;
            }else
            {
                break;
            }

        break;
        
        case '3'://education stuff
            money_add_red=-education_buying_cost[3];
            if(_Money_save_cheaker(money_add_red)&&_education_chacker(3)){
                _Money_save(money_add_red); _education_save(); _Age_day_save(1);
            }else{
                break;
            }
        break;
        case '2'://buy stuff
            money_add_red=-trasport_buying_cost[3];
            if(_Money_save_cheaker(money_add_red)&&_trasport_chacker(3)){
                _Money_save(money_add_red); _trasport_save(); _Age_day_save(1);
            }else{
                break;
            }
        break;
        case '7'://Eat microwave meal
            money_add_red=-30,Food_add_red=40,day_add=1;
            if(_Money_save_cheaker(money_add_red)&&_Food_save_cheaker(Food_add_red)){
                _Money_save(money_add_red); _Food_save(Food_add_red);_Age_day_save(day_add);
            }else{
                break;
            }
        break;
        case '9'://Paracetamol
            money_add_red=-30,health_add_red=40,Food_add_red=-5,day_add=1;
            if(_Money_save_cheaker(money_add_red)&& _Health_save_checker(health_add_red)&& _Food_save_cheaker(Food_add_red)){
                _Money_save(money_add_red);_Health_save(health_add_red);_Food_save(Food_add_red); _Age_day_save(day_add);
            }else{
                break;
            }
        }
        break;
        case 'e':case 'E':

        switch (prevoius_menu)
        {
            case '1'://work Postman
            Food_add_red=-5;money_add_red=job_salary[4];education_needed=2;trasport_needed=2;health_add_red=-10;
            if(_trasport_chack_before_a_job(trasport_needed)&&_education_chack_before_a_job(education_needed)){
                _Food_save(Food_add_red); _Money_save(money_add_red); _Age_day_save(3);
            }else
            {
                break;
            }
        break;
        
        case '3'://education stuff
            money_add_red=-education_buying_cost[4];
            if(_Money_save_cheaker(money_add_red)&&_education_chacker(4)){
                _Money_save(money_add_red); _education_save(); _Age_day_save(1);
            }else{
                break;
            }
        break;
        case '2'://buy stuff
            money_add_red=-trasport_buying_cost[4];
            if(_Money_save_cheaker(money_add_red)&&_trasport_chacker(4)){
                _Money_save(money_add_red); _trasport_save(); _Age_day_save(1);
            }else{
                break;
            }
        break;
        case '7'://Eat Self made meal
            money_add_red=-50,Food_add_red=70,day_add=1;
            if(_Money_save_cheaker(money_add_red)&&_Food_save_cheaker(Food_add_red)){
                _Money_save(money_add_red); _Food_save(Food_add_red);_Age_day_save(day_add);
            }else{
                break;
            }
        break;
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
            case '1'://work Small Part Time Job
            Food_add_red=-5;money_add_red=job_salary[5];education_needed=2;trasport_needed=2;health_add_red=-20;
            if(_trasport_chack_before_a_job(trasport_needed)&&_education_chack_before_a_job(education_needed)){
                _Food_save(Food_add_red); _Money_save(money_add_red); _Age_day_save(7);
            }else
            {
                break;
            }

        break;
        
         case '3'://education stuff
            money_add_red=-education_buying_cost[5];
            if(_Money_save_cheaker(money_add_red)&&_education_chacker(5)){
                _Money_save(money_add_red); _education_save(); _Age_day_save(1);
            }else{
                break;
            }
        break;   
        case '2'://buy stuff
            money_add_red=-trasport_buying_cost[5];
            if(_Money_save_cheaker(money_add_red)&&_trasport_chacker(5)){
                _Money_save(money_add_red); _trasport_save(); _Age_day_save(1);
            }else{
                break;
            }
        break;
        case '7'://Eat in cheap restaurant
            money_add_red=-100,Food_add_red=100,day_add=1;
            if(_Money_save_cheaker(money_add_red)&&_Food_save_cheaker(Food_add_red)){
                _Money_save(money_add_red); _Food_save(Food_add_red);_Age_day_save(day_add);
            }else{
                break;
            }
        break;
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
            case '1'://work Food Deliverer
            Food_add_red=-5;money_add_red=job_salary[6];education_needed=2;trasport_needed=2; health_add_red=-30;
            if(_trasport_chack_before_a_job(trasport_needed)&&_education_chack_before_a_job(education_needed)){
                _Food_save(Food_add_red); _Money_save(money_add_red); _Age_day_save(1); _Health_save(health_add_red) ;
            }else
            {
                break;
            }
        break;
        
        case '3'://education stuff
            money_add_red=-education_buying_cost[6];
            if(_Money_save_cheaker(money_add_red)&&_education_chacker(6)){
                _Money_save(money_add_red); _education_save(); _Age_day_save(1);
            }else{
                break;
            }
        break;    
        case '2'://buy stuff
            money_add_red=-trasport_buying_cost[6];
            if(_Money_save_cheaker(money_add_red)&&_trasport_chacker(6)){
                _Money_save(money_add_red); _trasport_save(); _Age_day_save(1);
            }else{
                break;
            }
        break;
        case '7'://Eatin expensive restaurant
            money_add_red=-200,Food_add_red=200,day_add=1;
            if(_Money_save_cheaker(money_add_red)&&_Food_save_cheaker(Food_add_red)){
                _Money_save(money_add_red); _Food_save(Food_add_red); _Age_day_save(day_add);
            }else{
                break;
            }
        break;
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
            case '1'://work Costraction Worker
            Food_add_red=-5;money_add_red=job_salary[7];education_needed=1;trasport_needed=2;health_add_red=-40;
            if(_trasport_chack_before_a_job(trasport_needed)&&_education_chack_before_a_job(education_needed)){
                _Food_save(Food_add_red); _Money_save(money_add_red); _Age_day_save(7); _Health_save(health_add_red) ;
            }else
            {
                break;
            }
        break;
        
        case '2'://buy stuff
            money_add_red=-trasport_buying_cost[7];
            if(_Money_save_cheaker(money_add_red)&&_trasport_chacker(7)){
                _Money_save(money_add_red); _trasport_save(); _Age_day_save(1);
            }else{
                break;
            }
        break;
        case '7'://Eat from private chef
            money_add_red=-500,Food_add_red=300,health_add_red=10,day_add=3;
            if(_Money_save_cheaker(money_add_red)&&_Food_save_cheaker(Food_add_red)&&_Health_save_checker(health_add_red)){
                _Money_save(money_add_red); _Food_save(Food_add_red); _Health_save(health_add_red); _Age_day_save(day_add);
            }else{
                break;
            }
        break;
        case '9'://hospoital
            money_add_red=-500,health_add_red=300,Food_add_red=-15,day_add=3;
            if(_Money_save_cheaker(money_add_red)&& _Health_save_checker(health_add_red)&& _Food_save_cheaker(Food_add_red)){
                _Money_save(money_add_red);_Health_save(health_add_red);_Food_save(Food_add_red);_Age_day_save(day_add);
            }else{
                break;
            }
        break;
        case 'i':case 'I':
            switch (prevoius_menu)
            { 
            case '1'://work Bus Driver
            Food_add_red=-5;money_add_red=job_salary[8];education_needed=1;trasport_needed=3;health_add_red=-50;
            if(_trasport_chack_before_a_job(trasport_needed)&&_education_chack_before_a_job(education_needed)){
                _Food_save(Food_add_red); _Money_save(money_add_red); _Age_day_save(1); _Health_save(health_add_red) ;
            }else
            {
                break;
            }
        break;
        
            }
        break;
        case 'j':case 'J':
            switch (prevoius_menu)
            {
                 
            case '1'://work Driver
            Food_add_red=-5;money_add_red=job_salary[9];education_needed=3;trasport_needed=3;health_add_red=-60;
            if(_trasport_chack_before_a_job(trasport_needed)&&_education_chack_before_a_job(education_needed)){
                _Food_save(Food_add_red); _Money_save(money_add_red); _Age_day_save(1); _Health_save(health_add_red) ;
            }else
            {
                break;
            }
        break;
        
            }
        break;
        case 'k':case 'K':
            switch (prevoius_menu)
            {
                 
            case '1'://work Administrative Workers
            Food_add_red=-5;money_add_red=job_salary[10];education_needed=4;trasport_needed=4;health_add_red=-70;
            if(_trasport_chack_before_a_job(trasport_needed)&&_education_chack_before_a_job(education_needed)){
                _Food_save(Food_add_red); _Money_save(money_add_red); _Age_day_save(1); _Health_save(health_add_red) ;
            }else
            {
                break;
            }
        break;
        
            }
        break;
        case 'l':case 'L':
            switch (prevoius_menu)
            {
                 
            case '1'://work Policeman
            Food_add_red=-5;money_add_red=job_salary[11];education_needed=4;trasport_needed=3;health_add_red=-80;
            if(_trasport_chack_before_a_job(trasport_needed)&&_education_chack_before_a_job(education_needed)){
                _Food_save(Food_add_red); _Money_save(money_add_red); _Age_day_save(1); _Health_save(health_add_red) ;
            }else
            {
                break;
            }
        break;
        
            }
        break;
        case 'm':case 'M':
            switch (prevoius_menu)
            {
                 
            case '1'://work Goverment Worker
            Food_add_red=-5;money_add_red=job_salary[12];education_needed=5;trasport_needed=4;health_add_red=-90;
            if(_trasport_chack_before_a_job(trasport_needed)&&_education_chack_before_a_job(education_needed)){
                _Food_save(Food_add_red); _Money_save(money_add_red); _Age_day_save(1); _Health_save(health_add_red) ;
            }else
            {
                break;
            }
        break;
        
            }
        break;
        
        case 'n':case 'N':
            switch (prevoius_menu)
            {
                 
            case '1'://work Programmer
            Food_add_red=-5;money_add_red=job_salary[13];education_needed=6;trasport_needed=4;health_add_red=-100;
            if(_trasport_chack_before_a_job(trasport_needed)&&_education_chack_before_a_job(education_needed)){
                _Food_save(Food_add_red); _Money_save(money_add_red); _Age_day_save(1); _Health_save(health_add_red) ;
            }else
            {
                break;
            }
        break;
        
            }
        case 'o':case 'O':
            switch (prevoius_menu)
            {
                 
            case '1'://work Bank Clerk
            Food_add_red=-5;money_add_red=job_salary[14];education_needed=5;trasport_needed=4;health_add_red=-120;
            if(_trasport_chack_before_a_job(trasport_needed)&&_education_chack_before_a_job(education_needed)){
                _Food_save(Food_add_red); _Money_save(money_add_red); _Age_day_save(1); _Health_save(health_add_red) ;
            }else
            {
                break;
            }
        break;
        
            }
        case 'p':case 'P':
            switch (prevoius_menu)
            {
                 
            case '1'://work News Repoeter
            Food_add_red=-5;money_add_red=job_salary[15];education_needed=5;trasport_needed=4;health_add_red=-130;
            if(_trasport_chack_before_a_job(trasport_needed)&&_education_chack_before_a_job(education_needed)){
                _Food_save(Food_add_red); _Money_save(money_add_red); _Age_day_save(30); _Health_save(health_add_red) ;
            }else
            {
                break;
            }
        break;
        
            }
        case 'q':case 'Q':
            switch (prevoius_menu)
            {
                 
            case '1'://work Actor
            Food_add_red=-5;money_add_red=job_salary[16];education_needed=6;trasport_needed=4;health_add_red=-140;
            if(_trasport_chack_before_a_job(trasport_needed)&&_education_chack_before_a_job(education_needed)){
                _Food_save(Food_add_red); _Money_save(money_add_red); _Age_day_save(30); _Health_save(health_add_red) ;
            }else
            {
                break;
            }
        break;
        
            }
        break;
        
        case 'r':case 'R':
            switch (prevoius_menu)
            {
                 
            case '1'://work Military Employee
            Food_add_red=-5;money_add_red=job_salary[17];education_needed=6;trasport_needed=5;health_add_red=-150;
            if(_trasport_chack_before_a_job(trasport_needed)&&_education_chack_before_a_job(education_needed)){
                _Food_save(Food_add_red); _Money_save(money_add_red); _Age_day_save(30); _Health_save(health_add_red) ;
            }else
            {
                break;
            }
        break;
        
            }
        break;
        
        case 's':case 'S':
            switch (prevoius_menu)
            {
                 
            case '1'://work Military Employee
            Food_add_red=-5;money_add_red=job_salary[18];education_needed=6;trasport_needed=5;health_add_red=-160;
            if(_trasport_chack_before_a_job(trasport_needed)&&_education_chack_before_a_job(education_needed)){
                _Food_save(Food_add_red); _Money_save(money_add_red); _Age_day_save(30); _Health_save(health_add_red) ;
            }else
            {
                break;
            }
        break;
        
            }
        break;
        case 't':case 'T':
            switch (prevoius_menu)
            {
                 
            case '1'://work Police Officer
            Food_add_red=-5;money_add_red=job_salary[19];education_needed=6;trasport_needed=5;health_add_red=-170;
            if(_trasport_chack_before_a_job(trasport_needed)&&_education_chack_before_a_job(education_needed)){
                _Food_save(Food_add_red); _Money_save(money_add_red); _Age_day_save(30); _Health_save(health_add_red) ;
            }else
            {
                break;
            }
        break;
        
            }
        break;  
        case 'u':case 'U':
            switch (prevoius_menu)
            {
                 
            case '1'://work Senior Programer
            Food_add_red=-5;money_add_red=job_salary[20];education_needed=6;trasport_needed=5;health_add_red=-185;
            if(_trasport_chack_before_a_job(trasport_needed)&&_education_chack_before_a_job(education_needed)){
                _Food_save(Food_add_red); _Money_save(money_add_red); _Age_day_save(7); _Health_save(health_add_red) ;
            }else
            {
                break;
            }
        break;
        
            }
        break;  
        case 'v':case 'V':
            switch (prevoius_menu)
            {
                 
            case '1'://work Supermarket Owner
            Food_add_red=-5;money_add_red=job_salary[21];education_needed=6;trasport_needed=5;health_add_red=-190;
            if(_trasport_chack_before_a_job(trasport_needed)&&_education_chack_before_a_job(education_needed)){
                _Food_save(Food_add_red); _Money_save(money_add_red); _Age_day_save(30); _Health_save(health_add_red) ;
            }else
            {
                break;
            }
        break;
        
            }
        break;  
        case 'w':case 'W':
            switch (prevoius_menu)
            {
                 
            case '1'://work Office CEO
            Food_add_red=-5;money_add_red=job_salary[22];education_needed=6;trasport_needed=6;health_add_red=-200;
            if(_trasport_chack_before_a_job(trasport_needed)&&_education_chack_before_a_job(education_needed)){
                _Food_save(Food_add_red); _Money_save(money_add_red); _Age_day_save(90); _Health_save(health_add_red) ;
            }else
            {
                break;
            }
        break;
        
            }
        break;  
        case 'x':case 'X':
            switch (prevoius_menu)
            {
                 
            case '1'://work Big YouTuber
            Food_add_red=-5;money_add_red=job_salary[23];education_needed=6;trasport_needed=5;health_add_red=-210;
            if(_trasport_chack_before_a_job(trasport_needed)&&_education_chack_before_a_job(education_needed)){
                _Food_save(Food_add_red); _Money_save(money_add_red); _Age_day_save(30); _Health_save(health_add_red) ;
            }else
            {
                break;
            }
        break;
        
            }
        break;  
        case 'y':case 'Y':
            switch (prevoius_menu)
            {
                 
            case '1'://work Military Officer
            Food_add_red=-5;money_add_red=job_salary[24];education_needed=7;trasport_needed=6;health_add_red=-220;
            if(_trasport_chack_before_a_job(trasport_needed)&&_education_chack_before_a_job(education_needed)){
                _Food_save(Food_add_red); _Money_save(money_add_red); _Age_day_save(270); _Health_save(health_add_red) ;
            }else
            {
                break;
            }
        break;
        
            }
        break;  
        case 'z':case 'Z':
            switch (prevoius_menu)
            {
                 
            case '1'://work President
            Food_add_red=-5;money_add_red=job_salary[25];education_needed=7;trasport_needed=7;health_add_red=-300;
            if(_trasport_chack_before_a_job(trasport_needed)&&_education_chack_before_a_job(education_needed)){
                _Food_save(Food_add_red); _Money_save(money_add_red); _Age_day_save(365); _Health_save(health_add_red) ;
            }else
            {
                break;
            }      break;
        
            }
        break;  
        default:

        break;
    }
    }
    if(wait&&(menu_chooes_int>='a'&&menu_chooes_int<='Z')){
        main_menu();
    }
        _Main_Menu_Bar();
    }while (1);
}
