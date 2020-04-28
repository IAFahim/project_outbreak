#include<stdio.h>
#include<string.h>
#define total_file_list_size 100
#define total_file_lenght_size 64
#define  scan_mode 0   //Smart_mode=1 Accurate_mode=0

typedef struct Data
{
    char name[50];
    char email[50];
};

void main()
{   
    system("dir > dir.txt");
    system("cls");
    FILE *fp;
    char c,search,file_names[total_file_list_size][total_file_lenght_size]={0};
    printf("This code will try to find file extention \nEx: [File_name].[Your Input][xx] [Your Input]: ");
    scanf("%c",&search);
    int size=0,list_size=0,flag=0,i=0,j=0,tf=1;
    fp=fopen("dir.txt","r");
    if(scan_mode) while((c=fgetc(fp))!= EOF ){
        i++;
        if(c=='.'){
            if((c=fgetc(fp))=='.'){
                while((c=fgetc(fp))!= EOF ){
                    if(tf){
                        i+=50;
                        tf=0;
                        fseek(fp,i,0);
                    }else{
                        i+=42;
                    }
                    fseek(fp,i,0);
                    while ((c=fgetc(fp))!='\n')
                    {
                        i++;
                        file_names[list_size][j++]=c;
                    if(c=='.'){
                        if((c=fgetc(fp))==search){
                            flag++;
                        }                        
                        file_names[list_size][j++]=c;
                    }
                    }if(flag){
                    file_names[list_size][j]=0;
                    printf("[%d] %s\n",list_size+1,file_names[list_size]);
                    list_size++;    
                    }
                    j=0,flag=0;
                }
                break;
            }
        }
    }else while((c=fgetc(fp))!= EOF ){
        i++;
        if(c=='.'){
            if((c=fgetc(fp))=='.'){
                while((c=fgetc(fp))!= EOF ){
                    if(tf){
                        i+=50;
                        tf=0;
                        fseek(fp,i,0);
                    }else{
                        i+=41;
                    }
                    fseek(fp,i,0);
                    while ((c=fgetc(fp))!='\n')
                    {
                        i++;
                        file_names[list_size][j++]=c;
                    
                    }int t;
                    for (t = j-1; file_names[list_size][t]!='.'&& t>j-4; t--){}
                        //printf("end at %d i am at %d ",j,t);
                        if(file_names[list_size][++t]==search)
                        {
                            file_names[list_size][j]=0;
                            printf("[%d] %s\n",list_size+1,file_names[list_size]);
                            list_size++;
                        }
                        //break;
                        j=0;                    
                }
                break;
            }
        }
    }
    
    if(list_size){
    fclose(fp);
    fflush(fp);
    int choes=0;
    printf("Pick to look in: ");
    scanf("%d",&choes);
    printf("%s\n",file_names[--choes]);
    fp=fopen(file_names[choes],"r");
    system("cls");
    while ((c=fgetc(fp))!=EOF)
    {//name fineder
        putchar(c);
    }fclose(fp);
    getchar();
    }else
    {
        printf("No extition Found");
    }
}
