#include<stdio.h>
#include<string.h>
#define Male_Seats 10
#define Female_Seats 10
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

	seat Bus[Total_Seats];
	
	void initializeBus(){
	for(int i=0;i < Total_Seats;i++){
		Bus[i].seatNo=i+1;
		Bus[i].status=0;
		Bus[i].gender='M','F';
		strcpy(Bus[i].name," ");
		Bus[i].fare=0;
		}
	}
	
	
	void ShowSeatChart(){
		printf("\n MALE SECTION: Seat 1-10| Fare:%d\n",MaleTicket_Price);
			for(int i=0 ; i<Male_Seats ; i++){
				if(Bus[i].status==0){
					printf("%d ",Bus[i].seatNo);
						}else{
							printf("[M] ");
						}
								if((i+1)%10==0){
									printf("\n");
								}
							}
								printf("\n");
		printf("FEMALE SECTION: Seat 11-20| Fare:%d\n",FemaleTicket_Price);
			for(int i=Male_Seats ; i<Total_Seats ; i++){
				if(Bus[i].status==0){
					printf("%d ",Bus[i].seatNo);
						}else{
							printf("[F] ");
						}
								if((i+1)%10==0){
									printf("\n");
								}
							}
								printf("\n");
						}
						
	void BookSeat(){
		int seatNo;
			char gender;
				ShowSeatChart();
					printf("\nTicket Price for Male= %d\n ",MaleTicket_Price);
						printf("Ticket Price for Female= %d\n",FemaleTicket_Price);
							printf("\nenter Category : Male= M,  Female= F\n ");
								scanf(" %c",&gender);
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
			if(Bus[seatNo-1].status==1){
				printf("Seat %d Already Booked by %s!\n",seatNo,Bus[seatNo-1].name);
					printf("\n");
						return;
			}
			printf("Enter Passenger Name: ");
				scanf(" %[^\n]s",Bus[seatNo-1].name);
					Bus[seatNo-1].status=1;
						Bus[seatNo-1].gender=gender;
						if(gender=='M'){
							Bus[seatNo-1].gender='M';
							Bus[seatNo-1].fare=MaleTicket_Price;
						}else 
						if(gender=='F'){
							Bus[seatNo-1].gender='F';
								Bus[seatNo-1].fare=FemaleTicket_Price;
						}
		printf("\n");
						
							
	printf("TICKET CONFIRMED\n");
	printf("Seat No: %d\n",seatNo);
	printf("Name: %s\n",Bus[seatNo-1].name);
	printf("Gender: %c\n",Bus[seatNo-1].gender);
	printf("Fare: %d\n",Bus[seatNo-1].fare);
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
			if(Bus[seatNo-1].status==0){
				printf("Seat %d is Already empty!\n",seatNo);
					return;
		}
			printf("Booking Cancelled For %s | Refund %d\n",Bus[seatNo-1].name,Bus[seatNo-1].fare);
				printf("\n");
					Bus[seatNo-1].status=0;
					Bus[seatNo-1].gender=' ';
					Bus[seatNo-1].fare=0;
					strcpy(Bus[seatNo-1].name," ");
	}
	
	void ShowAllBookings(){
		int Male_SeatsBooked=0,Female_SeatsBooked=0,TotalCollection=0;
			printf("Male Booking Seats\n");
				for(int i=0;i<Male_Seats;i++){
					if(Bus[i].status==1){
						printf("Seat: %d | Name : %s | Fare: %d\n",Bus[i].seatNo,Bus[i].name,Bus[i].fare);
							Male_SeatsBooked++;
								TotalCollection+=Bus[i].fare;
										printf("\n");
				}
			}
		
					if(Male_SeatsBooked==0){
						printf("No Male Bookings yet!\n");
							printf("\n");
			}
			printf("Female Booking Seats\n");
				for(int i=Female_Seats;i<Total_Seats;i++){
					if(Bus[i].status==1){
						printf("Seats: %d | Name: %s | Fare: %d\n",Bus[i].seatNo,Bus[i].name,Bus[i].fare);
							Female_SeatsBooked++;
								TotalCollection+=Bus[i].fare;
									printf("\n");
				}
			}
					if(Female_SeatsBooked==0){
						printf("No Female Booking yet!\n");
							printf("\n");
			}	
				printf("Whole Collection Summary\n");
				printf("Male Booked: %d/10\n",Male_SeatsBooked);
				printf("Female Booked: %d/10\n",Female_SeatsBooked);
				printf("Empty Seats: %d\n",Total_Seats-Male_SeatsBooked-Female_SeatsBooked);
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
	

