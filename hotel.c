#include<stdio.h>
#include<conio.h>
#include<string.h>
#include <stdlib.h>
#include<time.h>
#include<windows.h>

typedef struct GuestInfo {
    char Name[20];
    char ID[12];
    char Contactnum[10];
    int roomNumber;
} GuestInfo;

GuestInfo guestInfo[100];

typedef struct HotelInfo {
    char roomType[20];
    int roomNumber;
    int roomPrice;
    char currentstatus;
} HotelInfo;

typedef struct HotelData {
    int maxRoom;
    int currentCount;
} HotelData;

HotelData hotelData = {100, 0};

HotelInfo hotelInfo[100];

void Welcome();

void ViewHotelInfo();

void ViewOneRoom();

void ViewGuestInfo();

void ViewOneGuest();

void GuestCheckIn();

void GuestCheckOut();

void SaveGARInfo();

void SaveGuestInfo();

void SaveHotelInfo();

void Welcome(void) {
    printf("Welcome to use the hotel information management system!\n"); //welcome banner
}


void ViewHotelInfo(void) //room facilities
{
    int k;
    printf("View passenger information");
    printf("\nThe following is the hotel room information\nroom type\t room number\t\t price \t\tcurrent status\n");
    for (k = 0; k < 100; k++) {
        printf("%s\t%d\t\t\t%dLKR\t\t%s\n", hotelInfo[k].roomType, hotelInfo[k].roomNumber, hotelInfo[k].roomPrice,
               hotelInfo[k].currentstatus == 'y' ? "Not available" : "Available");
    }
    printf("Press any key to return to the main menu\n");
    getch();
    system("cls");
}

void ViewOneRoom(void) //room information by search 
{
    int i;
    int roomNumber;
    int index = -1;
    printf("Find a room ");
    printf("\nPlease enter the room number you are looking for \n");
    scanf("%d", &roomNumber);
    for (i = 0; i < 100; i++) {
        if (hotelInfo[i].roomNumber == roomNumber)
            index = i; //if user entered a room number it shows the room data in inventory

    }
    if (index == -1)
        printf("The room number you entered does not exist \n");
    else {
        printf("Room Type\t\t Room No.\t\t Room Price\t\t  Current Status \n");
        printf("%s\t\t%d\t\t\t%dLKR\t\t\t%s\n", hotelInfo[index].roomType, hotelInfo[index].roomNumber,
               hotelInfo[index].roomPrice, hotelInfo[index].currentstatus == 'y' ? "Not available" : "Available");
    }
    printf("Press any key to return to the main menu \n");
    getch();
    system("cls");
}

void ViewGuestInfo(void) //View all passengers information
{
    int i;
    printf("View passenger information ");
    if (guestInfo[0].roomNumber == 0)
        printf("\nNo travelers staying \n");
    else {
        printf("\nThe following is the passenger information, respectively:\nName\t\tID number\tContactnum\tRoom number\n");
        for (i = 0; i < hotelData.currentCount; i++) {
            printf("%s\t%s\t%s\t%d\n", guestInfo[i].Name, guestInfo[i].ID, guestInfo[i].Contactnum,
                   guestInfo[i].roomNumber);
        }
    }
    printf("Press any key to return to the main menu\n");
    getch();
    system("cls");
}

void ViewOneGuest(void) //View a passenger information search by name
{
    char Name[10];
    int i;
    int j = -1;
    printf("View a room information");
    if (guestInfo[0].roomNumber == 0)
        printf("\nNo passenger information\n");
    else {
        printf("\nPlease enter the name of the passenger you are looking for \n");
        scanf("%s", Name);
        for (i = 0; i < hotelData.currentCount; i++) {
            if (strcmp(guestInfo[i].Name, Name) == 0) {
                j = i;
                break;
            }
        }
        if (j == -1) {
            printf("The passenger does not exist\n");
        } else {
            printf("The following is the information of %s \n", guestInfo[j].Name);
            printf("Name\t\t\t ID number\t\t Contact number\t\t room number \n");
            printf("%s\t\t%s\t\t%s\t\t%d\n", guestInfo[j].Name, guestInfo[j].ID, guestInfo[j].Contactnum,
                   guestInfo[j].roomNumber);
        }
    }
    printf("Press any key to return to the main menu \n");
    getch();
    system("cls");
}


void GuestCheckIn(void) //room booking
{
    int i, j;
    int roomNumber;
    int day;
    int fee;
    printf("Passenger check-in ");
    if (hotelData.currentCount < hotelData.maxRoom) {
        printf("\nPlease enter the passenger's name, ID number, Contact number \n");
        scanf("%s %s %s", guestInfo[hotelData.currentCount].Name, guestInfo[hotelData.currentCount].ID,
              guestInfo[hotelData.currentCount].Contactnum);
        printf("The current empty room has the following \n");

        for (i = 0; i < 100; i++) {
            if (hotelInfo[i].currentstatus == 'n') {
                printf("%d ", hotelInfo[i].roomNumber);
            }
        }
        printf("\nPlease select the room number you want to check in \n");
        selroom:
        scanf("%d", &guestInfo[hotelData.currentCount].roomNumber);
        switch (guestInfo[hotelData.currentCount].roomNumber / 100) {
            case 1:
                hotelInfo[guestInfo[hotelData.currentCount].roomNumber - 101].currentstatus = 'y';
                break;
            case 2:
                hotelInfo[guestInfo[hotelData.currentCount].roomNumber - 181].currentstatus = 'y';
                break;
            case 3:
                hotelInfo[guestInfo[hotelData.currentCount].roomNumber - 261].currentstatus = 'y';
                break;
            case 4:
                hotelInfo[guestInfo[hotelData.currentCount].roomNumber - 341].currentstatus = 'y';
                break;
            case 5:
                hotelInfo[guestInfo[hotelData.currentCount].roomNumber - 421].currentstatus = 'y';
                break;
            default:
                printf("The entered room number is not incorrect please re enter:");
                goto selroom;
        }

        printf("Please enter the number of days to stay \n");
        scanf("%d", &day);
        if (101 <= guestInfo[hotelData.currentCount].roomNumber && guestInfo[hotelData.currentCount].roomNumber <= 120)
            fee = day * 2000;
        if (201 <= guestInfo[hotelData.currentCount].roomNumber && guestInfo[hotelData.currentCount].roomNumber <= 320)
            fee = day * 2600;
        if (401 <= guestInfo[hotelData.currentCount].roomNumber && guestInfo[hotelData.currentCount].roomNumber <= 420)
            fee = day * 3000;
        if (421 <= guestInfo[hotelData.currentCount].roomNumber && guestInfo[hotelData.currentCount].roomNumber <= 520)
            fee = day * 3500;

        printf("Payable: %d LKR \n", fee);
        printf("Registration is successful, welcome to stay! \nThe information is as follows \n\n");
        printf("Name\t\t ID number\t Contact number\t   room number \n");
        printf("%s\t%s\t  %s\t   %d\n", guestInfo[hotelData.currentCount].Name, guestInfo[hotelData.currentCount].ID,
               guestInfo[hotelData.currentCount].Contactnum, guestInfo[hotelData.currentCount].roomNumber);
        time_t now;
        struct tm *tm_now;
        time(&now);
        tm_now = localtime(&now);
        printf("check-in time %dYear %dmonth %dday %d:%d:%d\n", tm_now->tm_year + 1900, tm_now->tm_mon + 1,
               tm_now->tm_mday, tm_now->tm_hour, tm_now->tm_min, tm_now->tm_sec);
        hotelData.currentCount++;

    } else
        printf("Sorry, the business is so good, the rooms are full. ");
    printf("\nPress any key to return to the main menu \n");
    getch();
    system("cls");
}


void GuestCheckOut(void) //passenger check out
{
    char Name[10];
    int i = 0;
    int j = -1;
    printf("Passenger check out ");
    if (guestInfo[0].roomNumber == 0)
        printf("\nNo passenger information \n");
    else {
        printf("\nNumber of existing passenger registrations %d\n\n", hotelData.currentCount);
        printf("Please enter the name of the passenger who wants to check out \n");
        scanf("%s", Name);
        for (i = 0; i < hotelData.currentCount; i++) {
            printf("%s", guestInfo[i].Name);
            if (strcmp(guestInfo[i].Name, Name) == 0) {
                j = i;
                break;
            }
        }
        if (j == -1)
            printf("The passenger does not exist \n");
        else {
            for (i = j; i < hotelData.currentCount - 1; i++) {
                strcpy(guestInfo[i].Name, guestInfo[i + 1].Name);
                strcpy(guestInfo[i].ID, guestInfo[i + 1].ID);
                strcpy(guestInfo[i].Contactnum, guestInfo[i + 1].Contactnum);
                guestInfo[i].roomNumber = guestInfo[i + 1].roomNumber;
            }

            for (i = 0; i < 100; i++) {
                if (guestInfo[j].roomNumber == hotelInfo[i].roomNumber) {
                    hotelInfo[i].currentstatus = 'n';
                    break;
                }
            }
            hotelData.currentCount--;
            time_t now;
            struct tm *tm_now;
            time(&now);
            tm_now = localtime(&now);
            printf(" Check out successfully \ncheck-out time%d-%d-%d %d:%d:%d\nWelcome next time \n\n",
                   tm_now->tm_year + 1900, tm_now->tm_mon + 1, tm_now->tm_mday, tm_now->tm_hour, tm_now->tm_min,
                   tm_now->tm_sec);
        }
    }
    printf("\nPress any key to return to the main menu \n");
    getch();
    system("cls");
}

void main(void) //main function
{

    FILE *fp;
    int i;
    if ((fp = fopen("Hotel Information2.txt", "rb")) == NULL) //open hotel information2 file
    {
        printf("fail to open the file \n");
        return;
    }
    for (i = 0; i < 100; i++) {
        fscanf(fp, "%s %d %d %c\n", hotelInfo[i].roomType, &hotelInfo[i].roomNumber, &hotelInfo[i].roomPrice,
               &hotelInfo[i].currentstatus);
    }
    fclose(fp);
    if ((fp = fopen("Guest Information2.txt", "rb")) == NULL) //open guest information2 file
    {
        printf("No passenger check-in record \n");
    } else {
        i = 0;
        while (!feof(fp)) {
            fscanf(fp, "%s %s %s %d\n", guestInfo[i].Name, guestInfo[i].ID, guestInfo[i].Contactnum,
                   &guestInfo[i].roomNumber);
            if (guestInfo[i].Name[0] == '\0')
                break;
            hotelData.currentCount++;
            i++;
        }
        fclose(fp);
    }

    printf("Total number of rooms- %d\nNumber of existing hotel registrations- %d\n", hotelData.maxRoom,
           hotelData.currentCount);
    do {
        printf("\n");
        Welcome();
        printf("Please select a function \n");
        printf(
                "1 View hotel information \n"
                "2 View a room information \n"
                "3 View passenger information \n"
                "4 Find a certain passenger information \n"
                "5 Passenger check-in\n"
                "6 Passenger check out \n"
                "7 Save and exit \n");
        printf("\n");
        scanf("%d", &i);
        if (i < 1 || i > 8)
            printf("You entered incorrectly\n");
        else {
            switch (i) {
                case 1:
                    ViewHotelInfo();
                    break;
                case 2:
                    ViewOneRoom();
                    break;
                case 3:
                    ViewGuestInfo();
                    break;
                case 4:
                    ViewOneGuest();
                    break;
                case 5:
                    GuestCheckIn();
                    break;
                case 6:
                    GuestCheckOut();
                    break;
                case 7:
                    fp = fopen("Hotel Information2.txt", "w"); //write data
                    for (i = 0; i < 100; i++) {
                        fprintf(fp, "%s %d %d %c\n", hotelInfo[i].roomType, hotelInfo[i].roomNumber,
                                hotelInfo[i].roomPrice, hotelInfo[i].currentstatus);
                    }
                    fclose(fp);
                    if (hotelData.currentCount == 0) {
                        printf("No guest check-in information \n");
                        fp = fopen("Guest Information2.txt", "w");
                        fclose(fp);
                        getch();
                        system("cls");
                        exit(0);
                    } else {
                        i = 0;
                        printf("The number of hotel registrations is %d\n", hotelData.currentCount);
                        fp = fopen("Guest Information2.txt", "w"); //write data
                        for (i = 0; i < hotelData.currentCount; i++) {
                            fprintf(fp, "%s %s %s %d\n", guestInfo[i].Name, guestInfo[i].ID, guestInfo[i].Contactnum,
                                    guestInfo[i].roomNumber);
                        }
                        fclose(fp);
                        getch();
                        system("cls");
                        exit(0);
                    }
            }
        }
    } while (1);
}