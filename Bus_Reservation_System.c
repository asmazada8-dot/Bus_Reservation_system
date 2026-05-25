#include<stdio.h>
#include<string.h>
#define Rows 5
#define Cols 4
#define Total_Seats 20
#define MaleTicket_Price 500
#define FemaleTicket_Price 450
typedef struct seat{
	int seatNo;
	int status;
	char gender;
	char name[40];
	int fare;
}seat;

	seat Bus[Rows][Cols];
	
	// Initialize all Seats
	void initializeBus(){
		int SeatNum=1;
	for(int i=0;i < Rows;i++){
		for(int j=0;j<Cols;j++){
			Bus[i][j].seatNo=SeatNum++;
			Bus[i][j].status=0;
			strcpy(Bus[i][j].name,"");
	Bus[i][j].gender=' ' ;
	Bus[i][j].fare=0 ;
		}
	}
}
	
	// Show Seat Chart
	void ShowSeatChart(){
		// Male Section From 1-10
		printf(" MALE SECTION: Seat 1-10| Fare:%d\n",MaleTicket_Price);
		for(int i=0;i<Rows;i++){
			for(int j=0;j<Cols;j++){
				if(Bus[i][j].seatNo<=Total_Seats/2){
				if(Bus[i][j].status==0){      // Male Seats Only
					printf("%2d ",Bus[i][j].seatNo);// FOR MALE Seat Book    2 space are fix from %2d
						}else{
							printf("[M] ");//print 'M' on Male Book Seat
						}
					}
				}
					printf("\n");
			}
			
		// Female Section From 11-20
		printf("FEMALE SECTION: Seat 11-20| Fare:%d\n",FemaleTicket_Price);
		for(int i=0;i<Rows;i++){
			for(int j=0; j<Cols ; j++){
				if(Bus[i][j].seatNo>10){
					if(Bus[i][j].status==0){
						printf("%2d ",Bus[i][j].seatNo);//FOR FEMALE Seat Book
							}else{
								printf("[F] ");//	Print 'F' on Female Book Seat
									}
								}
							}
								printf("\n");
						}
					}
						
	void BookSeat(){
		int seatNo;
			char gender;
				ShowSeatChart();
					printf("\nTicket Price for Male= %d\n ",MaleTicket_Price);
						printf("Ticket Price for Female= %d\n",FemaleTicket_Price);
							printf("\nenter Category : Male= M,  Female= F\n ");
								scanf(" %c",&gender);
								//For Male Booking Seat
									if(gender=='M' || gender=='m'){
										printf("Enter Male Seat NO 1-10:");
											scanf("%d",&seatNo);
												if(seatNo < 1 || seatNo > 10){
													printf("Error: Male Seat Availablr From 1-10 Only\n");
														printf("\n");
															return;
													}
										gender='M';
			}else
			//For Female Booking Seat
				if(gender=='F' || gender=='f'){
					printf("Enter Female Seat NO 11-20:");
						scanf("%d",&seatNo);
							if(seatNo < 11 || seatNo > 20){
								printf("Error: Female Seat Available From 11-20 Only\n");
									printf("\n");
										return;
									}
										gender='F';
			}
			else{
				printf("Invalid Category !Enter M or F\n");
					printf("\n");
						return;
			}
			// 	TO MAKE 2D ARRAY
			int i=(seatNo-1)/Cols ; //Row
			int j=(seatNo-1)%Cols ; //Column
			if(Bus[i][j].status==1){
				printf("Seat %d Already Booked by %s!\n",seatNo,Bus[i][j].name);
					printf("\n");
						return;
			}
			printf("Enter Passenger Name: ");
				scanf(" %[^\n]s",Bus[i][j].name);
					Bus[i][j].status=1;
						Bus[i][j].gender=gender;
						if(gender=='M'){
							Bus[i][j].gender='M';
							Bus[i][j].fare=MaleTicket_Price;
						}else 
						if(gender=='F'){
							Bus[i][j].gender='F';
								Bus[i][j].fare=FemaleTicket_Price;
						}
		printf("\n");
						
							
	printf("TICKET CONFIRMED\n");
	printf("Seat No: %d\n",seatNo);
	printf("Name: %s\n",Bus[i][j].name);
	printf("Gender: %c\n",Bus[i][j].gender);
	printf("Fare: %d\n",Bus[i][j].fare);
	printf("\n");		
	}
	
	void CancelSeat(){
		int seatNo;
			printf("Enter Seat No to Cancel:");
				scanf("%d",&seatNo);
					if(seatNo<1 || seatNo >Total_Seats){
						printf("Invalid Seat Number\n ");
								printf("\n");
									return;
		}
		// TO MAKE 2D ARRAY
		int i=(seatNo-1)/Cols ; //Row
		int j=(seatNo-1)%Cols ; //COolumn
			if(Bus[i][j].status==0){
				printf("Seat %d is Already empty!\n",seatNo);
					printf("\n");
						return;
		}
			printf("Booking Cancelled For %s | Refund %d\n",Bus[i][j].name,Bus[i][j].fare);
				printf("\n");
					Bus[i][j].status=0;
					Bus[i][j].gender=' ';
					Bus[i][j].fare=0;
					strcpy(Bus[i][j].name,"");
	}
	
	void ShowAllBookings(){
		int Male_SeatsBooked=0,Female_SeatsBooked=0,TotalCollection=0;
			printf("Male Booking Seats\n");
				for(int i=0;i<Rows;i++){
					for(int j=0;j<Cols;j++){
						if(Bus[i][j].status==1 && Bus[i][j].gender=='M'){
							printf("Seat: %d | Name : %s | Fare: %d\n",Bus[i][j].seatNo,Bus[i][j].name,Bus[i][j].fare);
								Male_SeatsBooked++;
									TotalCollection+=Bus[i][j].fare;
										printf("\n");
				}
			}
		}
		
					if(Male_SeatsBooked==0){
						printf("No Male Bookings yet!\n");
							printf("\n");
			}
			printf("Female Booking Seats\n");
				for(int i=0;i<Rows;i++){
					for(int j=0;j<Cols;j++){
						if(Bus[i][j].status==1 && Bus[i][j].gender=='F'){
							printf("Seats: %d | Name: %s | Fare: %d\n",Bus[i][j].seatNo,Bus[i][j].name,Bus[i][j].fare);
								Female_SeatsBooked++;
									TotalCollection+=Bus[i][j].fare;
										printf("\n");
				}
			}
		}
					if(Female_SeatsBooked==0){
						printf("No Female Booking yet!\n");
							printf("\n");
			}	
				printf("Whole Collection Summary\n");
				printf("Male Booked: %d/10\n",Male_SeatsBooked);
				printf("Female Booked: %d/10\n",Female_SeatsBooked);
				printf("Empty Seats: %d\n",Total_Seats-Male_SeatsBooked+Female_SeatsBooked);
				printf("Total Cllection:%d\n",TotalCollection);
				printf("\n");
	}
int main(){
	int choice;
	initializeBus();
	int i=0;
	while(i<Total_Seats){
		printf("BUS RESERVATION  SYSTEM Male:%d PER TICKET\n",MaleTicket_Price);
			printf("BUS RESERVATION SYSTEM Female:%d PER TICKET\n",FemaleTicket_Price);
				printf("Total 20 Seats: 1-10 Male| 11-20 Female\n");
					printf("1.BOOK SEAT\n");
						printf("2.CANCEL SEAT\n");
							printf("3.Show all booking and collection\n");
								printf("4.Show Seat Chart\n");
									printf("5.Exit\n\n");
		printf("Enter choice: ");
		scanf("%d",&choice);
	
		
	switch(choice){
		case 1:
			BookSeat();
			break;
		case 2:
			CancelSeat();
			break;
		case 3:
			ShowAllBookings();
			break;
		case 4:
			ShowSeatChart();
			break;
		case 5:
			printf("Exit Thank You\n");
			break;
			return 0;
	default:
		printf("Invalid choice!\n");
			}
		}
			return 0;
	}				
	

