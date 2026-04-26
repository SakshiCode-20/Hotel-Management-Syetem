#include<stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Date structure
struct Date {
    int day;
    int month;
    int year;
};
// Structure for storing data
char room_ch;
struct Detail
{
    int roomNo;
    int status;
    float price;
    char roomType[2];//S-Single,D-Double,F-Family
    struct Date checkIn;
} Hotel[6][7]; 

void displaySingle(){
     printf("All the single rooms available: \n");
    for(int i=0; i<6; i++){
        for(int j=0; j<=3; j++){
            
                printf("%d ",Hotel[i][j].roomNo);
                 printf(" %d",Hotel[i][j].status);
                printf(" %s", Hotel[i][j].roomType);
                printf("%.2f\n",Hotel[i][j].price);
            
            
        }
    }
}
void displayDouble(){
     printf("All the Double rooms available:\n ");
    for(int i=0; i<6; i++){
        for(int j=4; j<=5; j++){
            
               
                printf("%d ",Hotel[i][j].roomNo);
                 printf(" %d",Hotel[i][j].status);
                printf(" %s\n", Hotel[i][j].roomType);
                printf("%.2f",Hotel[i][j].price);
            
        }
    }
}
void displayFamily(){
    printf("All the Family rooms available: \n");
    for(int i=0; i<6; i++){
        for(int j=6; j<7; j++){
               
                printf("%d ",Hotel[i][j].roomNo);
                 printf(" %d",Hotel[i][j].status);
                printf(" %s\n", Hotel[i][j].roomType);
                printf("%.2f",Hotel[i][j].price);
            
        }
    }
}
void roomAvailable()
{
    printf("All the rooms available: \n");
    for(int i=0; i<6; i++)
    {
        for(int j=0; j<7; j++)
        {
                printf("%d ",Hotel[i][j].roomNo);
                printf(" %d",Hotel[i][j].status);
                printf(" %s\n", Hotel[i][j].roomType);
                
        }
    }
}
void viewSingle(){
     printf("All the single rooms available: \n");
    for(int i=0; i<6; i++){
        for(int j=0; j<=3; j++){
            if(Hotel[i][j].status==0) //checking only rooms which are available(status=0)
            {
               
                printf("%d ",Hotel[i][j].roomNo);
                printf("%.2f\n",Hotel[i][j].price);
            }
            
        }
    }
}
void viewDouble(){
     printf("All the Double rooms available:\n");
    for(int i=0; i<6; i++){
        for(int j=4; j<=5; j++){
            if(Hotel[i][j].status==0) //checking only rooms which are available(status=0)
            {
               
                printf("%d ",Hotel[i][j].roomNo);
                printf("%.2f\n",Hotel[i][j].price);
            }
            
        }
    }
}
void viewFamily(){
    printf("All the Family rooms available: \n");
    for(int i=0; i<6; i++){
        for(int j=6; j<7; j++){
            if(Hotel[i][j].status==0) //checking only rooms which are available(status=0)
            {
                
                printf("%d ",Hotel[i][j].roomNo);
                printf("%.2f\n",Hotel[i][j].price);
            }
            
        }
    }
}

void checkIn(char preference){
    int room_ch2;
    if(preference == 'Y' || preference =='y')
    {
        printf("Enter room number:-\n");
        scanf("%d",&room_ch2);
        for(int i=0; i<6; i++)
        {
            for(int j=0; j<7; j++)
            {
                if(Hotel[i][j].roomNo==room_ch2) //checking only rooms which are available(status=0)
                {
                    Hotel[i][j].status=1;
                    
                    printf("Enter Check-in Date (DD/MM/YY): ");
                    scanf("%d/%d/%d",
                          &Hotel[i][j].checkIn.day,
                          &Hotel[i][j].checkIn.month,
                          &Hotel[i][j].checkIn.year);
                    printf("Room Allotted: %d\n",Hotel[i][j].roomNo );  
                    return;
                }
            }
        }
    }
    else if(preference == 'N' || preference =='n'){
        if(room_ch=='s'||room_ch=='S'){
            for(int i=0; i<6; i++){
                for(int j=0; j<4; j++){
                    if(Hotel[i][j].status == 0){
                        Hotel[i][j].status = 1;
                        printf("Enter Check-in Date (DD/MM/YY): ");
                        scanf("%d/%d/%d",
                          &Hotel[i][j].checkIn.day,
                          &Hotel[i][j].checkIn.month,
                          &Hotel[i][j].checkIn.year);
                        printf("Room Allotted: %d\n",Hotel[i][j].roomNo );
                        return;
                    }
                }
            }
        }
        else if(room_ch=='D'||room_ch=='d'){
            for(int i=0; i<6; i++){
                for(int j=4; j<6; j++){
                    if(Hotel[i][j].status == 0){
                        Hotel[i][j].status = 1;
                        printf("Enter Check-in Date (DD/MM/YY): ");
                        scanf("%d/%d/%d",
                          &Hotel[i][j].checkIn.day,
                          &Hotel[i][j].checkIn.month,
                          &Hotel[i][j].checkIn.year);
                        printf("Room Allotted: %d\n",Hotel[i][j].roomNo );
                        return;
                    }
                }
            }
        }
        else {
            for(int i=0; i<6; i++){
                for(int j=6; j<7; j++){
                    if(Hotel[i][j].status == 0){
                        Hotel[i][j].status = 1;
                        printf("Enter Check-in Date (DD/MM/YY): ");
                        scanf("%d/%d/%d",
                          &Hotel[i][j].checkIn.day,
                          &Hotel[i][j].checkIn.month,
                          &Hotel[i][j].checkIn.year);
                        printf("Room Allotted: %d\n",Hotel[i][j].roomNo );
                        return;
                    }
                }
            }
        }
    }
    else{
        printf("All Rooms are booked..better luck next time!!");
        return;
    }
}
void checkOut(){
    int room_ch3;
    printf("\n Enter your room no\n");
    scanf("%d",&room_ch3);

    for(int i=0; i<6; i++){
        for(int j=0; j<7; j++){

            if(Hotel[i][j].roomNo==room_ch3){

                if(Hotel[i][j].status==0){
                    printf("Oops..You choose the wrong room!\nTry again\n");
                    return;
                }

                struct Date checkOut;

                printf("Enter Check-out Date (DD/MM/YY): ");
                scanf("%d/%d/%d",
                      &checkOut.day,
                      &checkOut.month,
                      &checkOut.year);

                int days = (checkOut.year - Hotel[i][j].checkIn.year)*365 +
                           (checkOut.month - Hotel[i][j].checkIn.month)*30 +
                           (checkOut.day - Hotel[i][j].checkIn.day);

                if(days<=0){
                    printf("Invalid dates!\n");
                    return;
                }

                float bill = days * Hotel[i][j].price;

                printf("\nRoom No: %d\n",room_ch3);
                printf("Stay: %d days\n",days);
                printf("Total Amount: %.2f\n",bill);

                Hotel[i][j].status=0;
                printf("Successfully checked-out!!\n");

                return;
            }
        }
    }

    printf("Room not found!\n");
}

int main()
{
    float singleRoomPrice=1000;
    float doubleRoomPrice=1500;
    float familyRoomPrice=2000;
    
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<7;j++)
        {
            Hotel[i][j].roomNo=((i+1)*100)+(j+1); //To allot room no like 101,102...
            Hotel[i][j].status=0;
            if(j>=0&&j<=3)
            {
                Hotel[i][j].price=1000;
                strcpy(Hotel[i][j].roomType,"S");
            }
            else if(j>=4&&j<=5)
            {
                Hotel[i][j].price=1500;
                strcpy(Hotel[i][j].roomType,"D");
            }
            else
            {
                Hotel[i][j].price=2000;
                strcpy(Hotel[i][j].roomType,"F");
            }
        }
    }
    
    
    char preference;
    int ch;
    while(1)
    {
        printf("***Welcome to Paradise***\n");
        printf("What do you want to access?\n");
        printf("1.Check-in\n"); 
        printf("2.Check-out\n");
        printf("3.Current Status\n");
        printf("4.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            
            printf("Which type of room you want?\n");
            printf("***Enter your choice***\n");
            printf("1.Press 'S/s' for Single Room\n");
            printf("2.Press 'D/d' for Double Room\n");
            printf("3.Press 'F/f' for Family Room\n");
            scanf(" %c",&room_ch);         
            switch(room_ch)
            {
                case 's':
                case 'S':
                        
                        viewSingle();
                        printf("\nDo you have a preference for the room?\n 1.Enter Y/y for Yes\n2. Enter N/n for no\n");
                        scanf(" %c", &preference);
                        switch(preference){
                            case 'Y':
                            case 'y':
                            case 'N':
                            case 'n':
                            checkIn(preference);
                            break;
                        }
            
                break;
                case 'd':
                case 'D':
                        // char preference;
                        viewDouble();
                        printf("\nDo you have a preference for the room?\n1.Enter Y/y for Yes\n2.Enter N/n for no\n");
                        scanf(" %c", &preference);
                        switch(preference){
                            case 'Y':
                            case 'y':
                            case 'N':
                            case 'n':
                            checkIn(preference);
                        }
                 break;
                case 'f':
                case 'F':
                        // char preference;
                        viewFamily();
                        printf("\nDo you have a preference for the room?\n 1.Enter Y/y for Yes\n2. Enter N/n for no\n");
                        scanf(" %c", &preference);
                        switch(preference){
                            case 'Y':
                            case 'y':
                            case 'N':
                            case 'n':
                            checkIn(preference);
                        }
                   break;
                
             
            }
            break;
            case 2:
                //check out function call
                checkOut();
                break;
            case 3:
            char display_ch;
            printf("Which type of room's status do you want to see?\n");
            printf("1.Press S/s for Single Rooms\n");
            printf("2.Press D/d for Double Rooms\n");
            printf("3.Press F/f for Family Rooms\n");
            printf("4.Press A/a for all Available Rooms\n");
            scanf(" %c",&display_ch);
            switch(display_ch)
            {
                case 'S':
                case 's':
                displaySingle();
                break;
                case 'D':
                case 'd':
                displayDouble();
                break;
                case 'F':
                case 'f':
                displayFamily();
                break;
                case 'A':
                case 'a':
                roomAvailable();
                break;
            }
            
            break;
            case 4:
            printf("Thank you 😊");
            exit(0);
            default:
            printf("Invalid choice\n");
           
        }
    }
}