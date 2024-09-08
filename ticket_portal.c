#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct database
{
    char movie_name[20];
    char theatre_name[20];
    int price;
    char show_time[10];
    int tickets;
    int ticket_available;
    int booked_seats[100];
    char language[10];

}database;

void display()
{

    FILE *fp;
    int space;
    char or='|';
    database d;
    char search_movie[30];
    int s_no=1,found=0;
    fp=fopen("portal_database.txt","r");
    printf("\n\nMOVIE-NAME\t\tTHEATRE-NAME\t\tPRICE\t      SHOW-TIME\t   TICKETS\t  LANGUAGE\t\t\n");
    while(fread(&d,sizeof(database),1,fp))
    {

        printf("\n%d)",s_no);
        printf("%-23s",d.movie_name);
        printf("%-23s",d.theatre_name);
        printf("%-15d",d.price);
        printf("%-14s",d.show_time);
        printf("%-14d",d.ticket_available);
        printf("%-5s",d.language);
        s_no++;

    }
    printf("\n\n");
    printf("Enter movie name to view Booked tickets : ");
    scanf(" %[^\n]s",search_movie);
    fclose(fp);
    fp=fopen("portal_database.txt","r");
    while(fread(&d,sizeof(database),1,fp))
    {

        if(strcmp(search_movie,d.movie_name)==0)
        {
            printf("\n_____________________________________________________________________________\n|%76c\n| ",or);
            found =1;
            for(int i=1;i<=d.tickets;i++)
            {
                int booked=0;
                for(int j=0;j<100;j++)
                {
                    if(i==d.booked_seats[j])
                    {
                        booked=1;
                    }
                }

                if(booked==1)
                {
                    if(i%10==0)
                    {
                        printf("\033[0m\033[1;42m%d\033[0m  |",i);
                        if(i==10)
                        {
                            printf(" \033[0m\033[1;31;42m  \033[0m -> BOOKED");
                        }
                        if(d.tickets!=i)
                            printf("\n| ");
                        else
                            printf("\n");
                    }
                    else
                    printf(" \033[0m\033[1;42m%d\033[0m\t",i);
                }
                else
            {
                    if(i%10==0)
                    {
                        printf("%d  |",i);
                        if(i==10)
                        {
                            printf("\033[0m\033[1;31;42m  \033[0m -> BOOKED");
                        }
                        if(d.tickets!=i)
                            printf("\n| ");
                        else
                            printf("\n");
                    }
                    else
                    printf(" %d\t",i);
                }

                space=(d.tickets%10)*8;
            }
            if(space!=0)
            {
                for(int i=0;i<76-space;i++)
                {
                    printf(" ");
                }
                printf("%c\n|___________________________________________________________________________|",or);
            }
            else
            printf("|___________________________________________________________________________|");
            printf("\n\n");
        }
    }

    fclose(fp);

}

int user()
{
    int temp;
    printf("\n\n");
    system("echo $(tput setaf 2; tput bold) !! Welcome User !!$(tput sgr 0) ");
show:
    printf("\n1)Display Movies\n2)Book tickets\n3)Exit\n");
    system("echo $(tput setaf 4)Enter choice : $(tput sgr 0) ");
    scanf("%d",&temp);
    switch(temp)
    {
        case 1:
            {
                display();
                break;
            }
        case 2:
            {
                int space;
                char or='|';
                FILE *fp;                                                   
                FILE *fp1;                                                  
                database d;                                                 
                char search_movie[20];                                      
                int book_tickets=0,found=0,s_no=0;
                fp=fopen("portal_database.txt","r");
                printf("\n\nMOVIE-NAME\t\tTHEATRE-NAME\t\tPRICE\t      SHOW-TIME\t   TICKETS\t  LANGUAGE\t\t\n");
                while(fread(&d,sizeof(database),1,fp))
                {

                    printf("\n%d)",s_no+1);
                    printf("%-23s",d.movie_name);
                    printf("%-23s",d.theatre_name);
                    printf("%-15d",d.price);
                    printf("%-14s",d.show_time);
                    printf("%-14d",d.ticket_available);
                    printf("%-5s",d.language);
                    s_no++;

                }
                printf("\n\n");
                fclose(fp);
                printf("Enter movie name to Book tickets : ");                    
                scanf(" %[^\n]s",search_movie);                             
                fp=fopen("portal_database.txt","r");                        
                fp1=fopen("temp.txt","w");                                  
                while(fread(&d,sizeof(database),1,fp))                      
                {    

                    if(strcmp(search_movie,d.movie_name)==0)             
                    {   
                        printf("\n_____________________________________________________________________________\n|%76c\n| ",or);
                        found =1;
                        for(int i=1;i<=d.tickets;i++)
                        {
                            int booked=0;
                            for(int j=0;j<100;j++)
                            {
                                if(i==d.booked_seats[j])
                                {
                                    booked=1;
                                }
                            }
                            if(booked==1)
                            {
                                if(i%10==0)
                                {
                                    printf("\033[0m\033[1;44m%d\033[0m  |",i);
                                    if(i==10)
                                    {
                                        printf("\033[0m\033[1;31;44m  \033[0m -> BOOKED");
                                    }
                                    if(d.tickets!=i)
                                        printf("\n| ");
                                    else
                                        printf("\n");
                                }
                                else
                                printf("\033[0m\033[1;44m%d\033[0m\t",i);
                            }
                            else
                        {
                                if(i%10==0)
                                {
                                    printf("%d  |",i);
                                    if(i==10)
                                    {
                                        printf("\033[0m\033[1;31;44m  \033[0m -> BOOKED");
                                    }
                                    if(d.tickets!=i)
                                        printf("\n| ");
                                    else
                                        printf("\n");

                                }
                                else
                                printf("%d\t",i);
                            }
                            space=(d.tickets%10)*8;
                        }
                        if(space!=0)
                        {
                            for(int i=0;i<76-space;i++)
                            {
                                printf(" ");
                            }
                            printf("%c\n|___________________________________________________________________________|",or);
                        }
                        else
                        printf("|___________________________________________________________________________|");
                        printf("\n\n");
                        printf("No of Tickets to book\t: ");
                        scanf("%d",&book_tickets);

                        int flag_2=0,temp=0;
                        for(int j=0;j<100;j++)
                        {
                            if(d.booked_seats[j]==0&&flag_2!=book_tickets)
                            {
                            re_book:
                                printf("Enter the seat number to book\t:");
                                scanf("%d",&temp);
                                for(int i=0;i<100;i++)
                                {
                                    if(temp==d.booked_seats[i])
                                    {
                                        system("echo $(tput blink;tput setaf 5; tput bold)----Seat is already Booked----$(tput sgr 0) ");
                                        goto re_book;
                                    }


                                }
                                d.booked_seats[j]=temp;
                                flag_2++;

                            }
                            else
                            continue;
                        }

                        printf("\n\n");
                        d.ticket_available=d.ticket_available-book_tickets;  
                    }  

                    fwrite(&d,sizeof(database),1,fp1);                                                                                      
                }                                                           
                fclose(fp);                                                 
                fclose(fp1);                                                
                if(found==1)                                                
                {                                                           
                    database b1;                                            
                    fp1=fopen("temp.txt","r");                              
                    fp=fopen("portal_database.txt","w");                    
                    while(fread(&b1,sizeof(database),1,fp1))                
                    {                                                       
                        fwrite(&b1,sizeof(database),1,fp);                  

                    }                                                       
                    fclose(fp);                                             
                    fclose(fp1);                                            

                    break;
                }
            }


        case 3:
            {
                system("echo $(tput blink;tput setaf 1; tput bold)----User Exited----$(tput sgr 0) ");

                return 0;
            }

    }

    goto show;


}

int admin()
{

    int flag_1=0,i=0;
    char admin_name[20];
    char password[20];
re_enter:
    if(flag_1==3)
    {
        system("echo $(tput blink;tput setaf 1) -----you reached maximum limit-----$(tput sgr 0) ");
        return 1;
    }
    printf("\nAdmin name:\t");
    scanf(" %s",admin_name);
    system("bash pass_check_TP.sh");
    FILE *fp;
    fp=fopen("password.txt","r");
    fscanf(fp,"%s",password);
    fclose(fp);
    //printf("Password:\t");
    /*	while((password[i]=_getchar())!='\n')
    {
        i++;
        printf("*");
    }
    password[i]='\0'; */


    if(strcmp(admin_name,"Rajubhai")!=0)
    {     
        flag_1++;
        system("echo $(tput setaf 1; tput bold) INCORRECT USERNAME$(tput sgr 0) ");
        goto re_enter;
    }
    if(strcmp(password,"unknown")!=0)
    {  
        flag_1++;
        printf("\n");
        system("echo $(tput setaf 1; tput bold) INCORRECT PASSWORD$(tput sgr 0) "); 
        goto re_enter;
    }
    else
{

        int size;
        char *choice;
        int temp;
        printf("\n");
        system("echo $(tput setaf 2; tput bold) ENTERED ADMIN$(tput sgr 0) ");
    show:
        printf("1)Enter data\n2)Display data\n3)Insert data\n4)Search data\n5)Update data\n6)Delete data\n7)Exit\n");
        system("echo $(tput setaf 4) Enter choice : $(tput sgr 0) ");
        scanf("%d",&temp);
        switch(temp)
        {
            case 1:
                {
                    FILE *fp;
                    fp=fopen("portal_database.txt","w");
                    database *d;
                    printf("Enter the no .of datas\n");
                    scanf("%d",&size);
                    d=(database*)calloc(size,sizeof(database));
                    for(int i=0;i<size;i++)
                    {
                        printf("-----%d Data-----\n",i+1);
                        printf("Movie name\t: ");
                        scanf(" %[^\n]s",d[i].movie_name);
                        printf("Theatre name\t: ");
                        scanf(" %[^\n]s",d[i].theatre_name);
                        printf("Price\t\t: ");
                        scanf("%d",&d[i].price);
                        printf("show-time\t: ");
                        scanf(" %[^\n]s",d[i].show_time);
                        printf("Tickets\t\t: ");
                        scanf("%d",&d[i].tickets);
                        d[i].ticket_available=d[i].tickets;
                        printf("Language\t: ");
                        scanf(" %s",d[i].language);
                        fwrite(&d[i],sizeof(database),1,fp);
                    }
                    fclose(fp);
                    break;
                }
            case 2:
                {
                    /*			FILE *fp;
                    database d;
                    int s_no=1;
                    fp=fopen("portal_database.txt","r");
                    printf("\n\nMovie-name\t\tTheatre-name\t\tPrice\t      show-time\t   Tickets\t  Language\t\t");
                    while(fread(&d,sizeof(database),1,fp))
                    { 

                        printf("\n%d)",s_no);
                        printf("%-23s",d.movie_name);
                        printf("%-23s",d.theatre_name);
                        printf("%-15d",d.price); 
                        printf("%-14s",d.show_time);
                        printf("%-14d",d.ticket_available);
                        printf("%-5s",d.language);

                        s_no++;
                    }
                    printf("\n\n");

                 fclose(fp); */
                    display();
                    break;
                }
            case 3:
                {
                    FILE *fp;
                    fp=fopen("portal_database.txt","a");
                    database *d;
                    printf("Enter the no .of datas\n");
                    scanf("%d",&size);
                    d=(database*)calloc(size,sizeof(database));
                    for(int i=0;i<size;i++)
                    {
                        printf("-----Append %d Data-----\n",i+1);
                        printf("Movie name\t: ");
                        scanf(" %[^\n]s",d[i].movie_name);
                        printf("Theatre name\t: ");
                        scanf(" %[^\n]s",d[i].theatre_name);
                        printf("Price\t\t: ");
                        scanf("%d",&d[i].price);
                        printf("show-time\t: ");
                        scanf(" %[^\n]s",d[i].show_time);
                        printf("Tickets\t\t: ");
                        scanf("%d",&d[i].tickets);
                        d[i].ticket_available=d[i].tickets;
                        printf("Language\t: ");
                        scanf(" %s",d[i].language);
                        fwrite(&d[i],sizeof(database),1,fp);
                    }
                    fclose(fp);
                    break;


                }
            case 5:
                {
                    FILE *fp;
                    FILE *fp1;
                    database d;
                    char search_movie[20];
                    int s_no=1,found=0;
                    printf("Enter movie name to Update : ");
                    scanf(" %[^\n]s",search_movie);
                    fp=fopen("portal_database.txt","r");
                    fp1=fopen("temp.txt","w");
                    while(fread(&d,sizeof(database),1,fp))
                    { 
                        if(strcmp(search_movie,d.movie_name)==0)
                        {
                            found =1;
                            printf("New Theatre name\t: ");                             
                            scanf(" %[^\n]s",d.theatre_name);                    
                            printf("New Price\t: ");                                  
                            scanf("%d",&d.price);                                
                            printf("New show-time\t: ");                                
                            scanf(" %[^\n]s",d.show_time);                       
                            printf("New Tickets\t: ");                                
                            scanf("%d",&d.tickets);
                            d.ticket_available=d.tickets;
                            printf("New Language\t: ");                                 
                            scanf(" %s",d.language); 

                        }
                        fwrite(&d,sizeof(database),1,fp1);

                    }
                    fclose(fp);
                    fclose(fp1);
                    if(found==1)
                    { 
                        database b1;
                        fp1=fopen("temp.txt","r");
                        fp=fopen("portal_database.txt","w");
                        while(fread(&b1,sizeof(database),1,fp1))
                        {
                            fwrite(&b1,sizeof(database),1,fp); 

                        }
                        fclose(fp);
                        fclose(fp1);


                    }
                    if(found==0)
                        system("echo $(tput blink;tput setaf 1; tput bold) DATA NOT FOUND !!$(tput sgr 0) ");
                    printf("\n\n");

                    break;

                }
            case 4:
                {
                    FILE *fp;
                    database d;
                    char search_movie[30];
                    int s_no=1,found=0;
                    printf("Enter movie name to search : ");
                    scanf(" %[^\n]s",search_movie);
                    fp=fopen("portal_database.txt","r");
                    while(fread(&d,sizeof(database),1,fp))
                    {
                        if(strcmp(search_movie,d.movie_name)==0)
                        {
                            found =1;
                            printf("\n\nMovie-name\t\tTheatre-name\t\tPrice\t      show-time\t   Tickets\t  Language\t\t\n");
                            printf("%-23s",d.movie_name);
                            printf("%-23s",d.theatre_name);
                            printf("%-15d",d.price);
                            printf("%-14s",d.show_time);
                            printf("%-14d",d.ticket_available);
                            printf("%-5s",d.language);

                            s_no++;
                        }

                    }
                    if(found==0)
                        system("echo $(tput blink;tput setaf 1; tput bold) MOVIE NOT FOUND !!$(tput sgr 0) ");
                    printf("\n\n");

                    fclose(fp);
                    break;
                }
            case 6:
                {
                    FILE *fp;
                    FILE *fp1;
                    database d;
                    char search_movie[20];
                    int s_no=1,found=0;
                    printf("Enter movie name to Delete : ");
                    scanf(" %[^\n]s",search_movie);
                    fp=fopen("portal_database.txt","r");
                    fp1=fopen("temp.txt","w");
                    while(fread(&d,sizeof(database),1,fp))
                    {
                        if(strcmp(search_movie,d.movie_name)==0)
                        {
                            found =1;
                        }
                        else
                        fwrite(&d,sizeof(database),1,fp1);

                    }
                    fclose(fp);
                    fclose(fp1);
                    if(found==1)
                    {
                        database b1;
                        fp1=fopen("temp.txt","r");
                        fp=fopen("portal_database.txt","w");
                        while(fread(&b1,sizeof(database),1,fp1))
                        {
                            fwrite(&b1,sizeof(database),1,fp);

                        }
                        fclose(fp);
                        fclose(fp1);


                    }
                    if(found==0)
                        system("echo $(tput blink;tput setaf 1; tput bold) DATA NOT FOUND !!$(tput sgr 0) ");
                    printf("\n\n");

                    break;

                }
            case 7:
                {
                    system("echo $(tput blink;tput setaf 1; tput bold)----Admin Exited----$(tput sgr 0) ");
                    return 0;
                }



        }
        goto show;



    }
}
int main()
{
    int login_as;
    printf("\n\n");
login:
    system("echo  $(tput setaf 1;tput setab 7;tput bold)  Log IN as $(tput sgr 0) ");
    printf("\n 1)user\n 2)ADMIN\n 3)Exit\n Enter choice\t: ");
    scanf("%d",&login_as);
    if(login_as==1)
    {
        user();
        goto login;
    }
    if(login_as==2)
    {
        admin();
        goto login;
    }
    if(login_as==3) {
        return 0;
    }
    else
    goto login;
}
