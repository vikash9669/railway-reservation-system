#include <stdio.h>
#include <stdlib.h>
#include "conio2.h"
#include "rlyres.h"
int main()
{
    int choice,ticket_no;
    int result,i,train_no;
    int*pticket_no;
    char*pmob_no,*ptrain_no;
    add_trains();
    Passenger*ptr;
    while(1)
    {
        choice=enterchoice();
        if(choice==9)
            exit(0);
        switch(choice)
        {
            case 1:
                    view_trains();
                    getch();
                    clrscr();
                    break;
            case 2:
                    ptr=get_passenger_details();
                    clrscr();
                    if(ptr!=NULL)
                    {
                        ticket_no=book_ticket(*ptr);
                        if(ticket_no==-1)
                        {
                            textcolor(LIGHTRED);
                            printf("booking failed!");
                        }
                        else
                        {
                            clrscr();
                           textcolor(LIGHTGREEN);
                           printf("Ticket booked successfully \nYour ticket no is:%d\n",ticket_no);
                        }
                        for(i=1;i<=80;i++)
                         printf("*");
                        textcolor(WHITE);
                        printf("\n Press any key to go back in main screen:");
                        getch();
                        clrscr();
                    }
                    break;
            case 3:
                    clrscr();

                    ticket_no=accept_ticket_no();
                    if(ticket_no!=0)
                    {
                        view_ticket(ticket_no);
                    }
                      textcolor(WHITE);
                      printf("\n Press any key to go back to the main screen:");
                      getch();
                      clrscr();

                    break;
            case 4:
                    clrscr();
                    pmob_no=accept_mob_no();
                    if(pmob_no!=NULL)
                    {
                        pticket_no=get_ticket_no(pmob_no);
                        view_all_tickets(pmob_no,pticket_no);
                    }
                    clrscr();
                    break;
            case 5:

                    clrscr();
                    view_all_bookings();
                    clrscr();

                    break;
            case 6:

                    clrscr();
                    ptrain_no=accept_train_no();
                    if(ptrain_no!=NULL)
                        view_booking(ptrain_no);
                    clrscr();

                    break;
            case 7:

                    clrscr();
                    ticket_no=accept_ticket_no();
                    if(ticket_no!=0)
                    {
                      result=cancel_ticket(ticket_no);
                      if(result==0)
                      {
                          textcolor(LIGHTRED);
                          printf("Sorry!No ticket booked of ticket no %d",ticket_no);


                      }
                      else if(result==1)
                      {
                          textcolor(LIGHTGREEN);
                          printf("Ticket no %d successfully cancelled",ticket_no);
                      }

                    textcolor(WHITE);
                    printf("\n\nPress any key to go back to main screen:");
                    }
                    getch();
                    clrscr();
                    break;
            case 8:

                    clrscr();
                    train_no=accept_train_no();
                    if(train_no!=0)
                    {
                      i=cancel_train(train_no);
                        if(i==0)
                        {
                            textcolor(LIGHTRED);
                            printf("Sorry! no train found");
                        }
                      else if(i==1)
                      {
                          textcolor(LIGHTGREEN);
                          printf("Train no %s successfully cancelled",train_no);
                      }
                    textcolor(WHITE);
                    printf("\n\nPress any key to go back to main screen:");
                    }
                    getch();
                    clrscr();

                    break;
            default:
                        textcolor(LIGHTRED);
                        printf("Wrong Choice! Try Again\n");
                        getch();
                        clrscr();
        }
    }
    return 0;
}
