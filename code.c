#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include "linklist.h"
long int money=0;
long int space=0;
struct theatre
{
    int id;
    char name[100];
    char genre[100];
    char date[10];
    char place[20];
    int price;
};
void add()
{
    system("cls");
    FILE *a;
    struct theatre *ptr=(struct theatre*)malloc(sizeof(struct theatre));
    a=fopen("file1.txt","a");
    printf("Enter the id    : ");
    scanf("%d",&(ptr->id));
    printf("Enter the name  : ");
    scanf("%s",(ptr->name));
    printf("Enter the genre : ");
    scanf("%s",(ptr->genre));
    printf("Enter the date  : ");
    scanf("%s",(ptr->date));
    printf("Enter the place : ");
    scanf("%s",(ptr->place));
    printf("Enter the price : ");
    scanf("%d",&(ptr->price));
    fprintf(a,"\n");
    fprintf(a,"%d",(ptr->id));
    fprintf(a," ");
    fprintf(a,"%s",(ptr->name));
    fprintf(a," ");
    fprintf(a,"%s",(ptr->genre));
    fprintf(a," ");
    fprintf(a,"%s",(ptr->date));
    fprintf(a," ");
    fprintf(a,"%s",(ptr->place));
    fprintf(a," ");
    fprintf(a,"%d",(ptr->price));
    //fprintf(a,"\n");
    printf("\nRecord added successfully");
    _getch();
    fclose(a);
}
void viewfile(FILE *ptr1)
{
    char ch;
    while((ch=fgetc(ptr1))!=EOF)
        putchar(ch);
}
void deleteline(FILE *ptr1, FILE *ptr2,int l)
{
    char buf[10000];
    int c=1;
    while((fgets(buf,10000,ptr1))!=NULL)
    {
        if(l!=c)
            fputs(buf,ptr2);
        c++;
    }
}
void remove1()
{
    FILE *ptr1;
    FILE *ptr2;
    char way[1000];
    long int l;
    //C:\Users\Vatsal\Desktop\c++\sem2project\file1.txt
    printf("Enter the location of the file     : ");
    scanf("%s",way);
    printf("Enter line which you want to remove: ");
    scanf("%ld",&l);
    ++l;
    ptr1=fopen(way,"r");
    ptr2=fopen("delete_temp.tmp","w");
    printf("\nFile contents before removing line.\n\n");
    viewfile(ptr1);
    rewind(ptr1);
    deleteline(ptr1,ptr2,l);
    fclose(ptr1);
    fclose(ptr2);
    remove(way);
    rename("delete_temp.tmp",way);
    printf("\n\n\nFile contents after removing line %d .\n\n",l-1);
    ptr1=fopen(way,"r");
    viewfile(ptr1);
    fclose(ptr1);
    _getch();
}
void bill()
{
    system("cls");
    money=0;
    space=0;
    FILE *a;
    char ch1,ch2;
    int seats,cost;
    char name[100];
    struct theatre *ptr=(struct theatre*)malloc(sizeof(struct theatre));
    a=fopen("file2.txt","r");
    while((ch1=fgetc(a))!=EOF)
    {
        if(ch1=='\n')
        {
            fscanf(a,"%s %s %d %d",name,ptr->name,&seats,&cost);
            money+=cost;
            space+=seats;
        }
    }
    printf("TRANSACTIONS :\n\n");
    printf(" Total collection    : %d Rs\n",money);
    printf(" Total seats booked  : %d\n",space);
    rewind(a);
    while((ch2=fgetc(a))!=EOF)
    {
        if(ch2=='\n')
        {
            fscanf(a,"%s %s %d %d",name,(ptr->name),&seats,&cost);
            printf("\n* ");
            printf("  Name         : %s\n",name);
            printf("    Movie        : %s\n",ptr->name);
            printf("    Seats booked : %d\n",seats);
            printf("    Cost         : %d\n\n",cost);
        }
    }
    fclose(a);
    _getch();

}
void view()
{
    system("cls");
    FILE *a;
    char ch;
    struct theatre *ptr=(struct theatre*)malloc(sizeof(struct theatre));
    a=fopen("file1.txt","r");
    printf("NOW SHOWING :\n");
    //while((ch=fgetc(a))!=EOF)
    //{
      //  printf("%c",ch);
    //}
    while((ch=fgetc(a))!=EOF)
    {
        if(ch=='\n')
        {
            fscanf(a,"%d %s %s %s %s %d",&(ptr->id),(ptr->name),(ptr->genre),(ptr->date),(ptr->place),&(ptr->price));
            //enqueue(&q,ptr->id,ptr->name,ptr->genre,ptr->date,ptr->place,ptr->price);
            //dequeue(q);
            printf("\n* ");
            printf("  id    : %d\n",ptr->id);
            printf("    name  : %s\n",ptr->name);
            printf("    genre : %s\n",ptr->genre);
            printf("    date  : %s\n",ptr->date);
            printf("    place : %s\n",ptr->place);
            printf("    price : %d\n\n",ptr->price);
        }
    }
    //printf("%d",q->front);
    //display(&q);
    fclose(a);
    _getch();
}
void book()
{
    system("cls");
    char name[100];
    printf("Enter your name    : ");
    scanf("%s",name);
    printf("Enter the movie id : ");
    int n1,n2;
    scanf("%d",&n1);
    printf("Number of tickets  : ");
    scanf("%d",&n2);
    FILE *a;
    FILE *b;
    char ch;
    struct theatre *ptr=(struct theatre*)malloc(sizeof(struct theatre));
    a=fopen("file1.txt","r");
    b=fopen("file2.txt","a");
    while((ch=fgetc(a))!=EOF)
    {
        if(ch=='\n')
        {
            fscanf(a,"%d %s %s %s %s %d",&(ptr->id),(ptr->name),(ptr->genre),(ptr->date),(ptr->place),&(ptr->price));
            if((ptr->id)==n1)
            {
                int cost=(ptr->price)*n2;
                printf("\n\n");
                printf("   Movie info : \n");
                printf("             ");
                //printf("%d %s %s %s %d",(ptr->id),(ptr->name),(ptr->date),(ptr->place),(ptr->price));
                printf("Movie   : ");
                printf("%s\n",ptr->name);
                printf("             ");
                printf("Genre   : ");
                printf("%s\n",ptr->genre);
                printf("             ");
                printf("Date    : ");
                printf("%s\n",ptr->date);
                printf("             ");
                printf("Place   : ");
                printf("%s\n",ptr->place);
                printf("             ");
                printf("Price   : ");
                printf("%d\n",cost);
                printf("\n\n");
                printf("Do you want to confirm your booking ? \n");
                printf("(y/n) : ");
                char c;
                getchar();
                scanf("%c",&c);
                if(c=='y')
                {
                    printf("\n\n");
                    printf("         Booking successful......");
                    fprintf(b,"\n");
                    fprintf(b,"%s",name);
                    fprintf(b," ");
                    fprintf(b,"%s",(ptr->name));
                    fprintf(b," ");
                    fprintf(b,"%d",n2);
                    fprintf(b," ");
                    fprintf(b,"%d",(cost));
                    //money+=cost;
                    //space+=n2;

                }
                break;
            }
        }

    }
    fclose(a);
    fclose(b);
    _getch();

}
void rate()
{
    system("cls");
    FILE *c;
    c=fopen("file3.txt","a");
    printf("\n                                              FEEDBACK FORM\n\n\n\n\n");
    char d[100];
    int k;
    printf("                             Name                   : ");
    scanf("%s",d);
    printf("\n\n");
    printf("                             Experience(out of 10)  : ");
    scanf("%d",&k);
    fprintf(c,"\n");
    fprintf(c,"%s",d);
    fprintf(c," ");
    fprintf(c,"%d",k);
    if(k<=6)
    {
        printf("\n\n\n\n                     Thank you we will try to make it more better.....");
    }
    else{
        printf("\n\n\n\n                     Thank you and have a nice day........");
    }
    fclose(c);
    _getch();
}
void rating()
{
    system("cls");
    printf("USER'S RATING :\n\n\n");
    FILE *c;
    int k;
    char ch;
    char d[100];
    c=fopen("file3.txt","r");
    while((ch=fgetc(c))!=EOF)
    {
        if(ch=='\n')
        {
            fscanf(c,"%s %d",d,&k);
            //printf("%d",k);
            insertfirst(k,d);
        }
    }
    sort();
    printList();
    while(!isempty())
    {
        deletefirst();
    }
    _getch();
    //system("cls");
}
void admin()
{
    int k;
    do
{
    system("cls");
    //system("cls");
    printf("(1) Add movie\n\n");
    printf("(2) Remove movie\n\n");
    printf("(3) Transactions\n\n");
    printf("(4) View movies\n\n");
    printf("(5) View ratings\n\n");
    printf("(6) Exit\n\n");
    printf("Select one of these options : ");
    scanf("%d",&k);
    switch(k)
    {
    case 1:
        {
            add();
            break;
        }
    case 2:
        {
            remove1();
            break;
        }
    case 3:
        {
            bill();
            break;
        }
    case 4:
        {
            view();
            break;
        }
    case 5:
        {
            rating();
            break;
        }
    case 6:
        {
            exit(0);
            break;
        }
    default:
        {
            printf("\n\n");
            printf("Error , Try again...");
            _getch();
            admin();
            break;
        }
    }
}while(k!=0);
}
void login()
{
    system("cls");
    int username[100],password[100];
    printf("\n                            Please login into the network for further details :\n");
    printf("\n\n\n\n\n");
    printf("                                          USERNAME : ");
    scanf("%s",username);
    printf("\n                                          PASSWORD : ");
    scanf("%s",password);
    if(strcmp(username,"avengers")==0 && strcmp(password,"endgame")==0)
    {
        printf("\n\n\n");
        printf("                          Login successful! Press any key to continue.......");
        _getch();
        admin();
    }
    else{
        printf("\n\n\n");
        printf("                                    Try again..........");
        _getch();
        login();
    }
}
void booking()
{
    int k;
    do{
        system("cls");
        printf("\n              Welcome,\n                      to the world of Galactic Cinematic Universe.....\n\n\n\n\n\n");
        printf("                                   (1) Movies on air\n\n\n");
        printf("                                           (2) Book tickets\n\n\n");
        printf("                                                   (3) Rate us\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("                                                                                                        (4) Exit\n\n");
        scanf("%d",&k);
        switch(k)
        {
        case 1:
            {
                view();
                break;
            }
        case 2:
            {
                book();
                break;
            }
        case 3:
            {
                rate();
                break;
            }
        case 4:
            {
                exit(0);
                return;
            }
        default :
            {
                printf("\n\n");
                printf("Error , Try again...");
                _getch();
                booking();
                break;
            }
        }
    }while(k!=0);
}
int main()
{
    printf("                                     *******************************************");printf("\n");
    printf("                                                GALACTIC CINEMAS         ");printf("\n");
    printf("                               ******************                 ************    ");printf("\n");
    printf("                                       *****************************    ****");printf("\n");
    printf("\n\n\n");
    printf("                                                    You are\n\n");
    printf("                                        (1): Admin           (2): User\n                                                       ");
    int n;
    scanf("%d",&n);
    if(n==1)
        login();
    else if(n==2)
        booking();
    return 0;
}
