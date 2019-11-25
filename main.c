#include <stdio.h>
#include <string.h>

struct CreateAccount{
	int account_number = 0;
	int balance = 0;
	char name[20] = "";
	char address[20] = "";
	char date_of_birth[20] = "";
	char account_type[10] = "";

	void deposit(int amount){
		balance += amount;
		printf("$%d deposited successfully!\n", amount);
	}
	void withdraw(int amount){
		if(amount <= balance && balance != 0){
			balance -= amount;	
			printf("$%d withdrawn successfully!\n", amount);
		}
		else{
			printf("There is not enough balance to withdraw.\n");
		}
		
	}

	void printInfo(){
		printf("Account details >>> \n");
		printf("\tAccount Number : %d\n", account_number);
		printf("\tName : %s\n", name);
		printf("\tAddress : %s\n", address);
		printf("\tDate of Birth : %s\n", date_of_birth);
		printf("\tAccount Type : %s\n\n", account_type);
	}
};

int searchAccount(int acc_num_, CreateAccount * accounts){
	for(int i = 0; i < 20; i++){
		if(acc_num_ == accounts[i].account_number){
			return i;
		}
	}
	return -1;
}

int main(){
	struct CreateAccount accounts[20];
	int acc_count = 0;

	while(1){
		int command;
		printf("===============================================\n");
		printf("Enter <0> to tarminate the program.\nEnter <1> to creating new account.\nEnter <2> to search an account.\nEnter <3> to print all account names.\nEnter <4> to deposit in a account.\nEnter <5> to withdraw from a account.\nEnter <6> to remove an account.\n");
		scanf("%d", &command);
		printf("===============================================\n");
		if(command == 0){
			return 0;
		}
		else if(command == 1){
			printf("Name of the account owner : ");
			scanf("%s", accounts[acc_count].name);
			printf("Address of the account owner : ");
			scanf("%s", accounts[acc_count].address);
			printf("Date of Birth of the account owner : ");			
			scanf("%s", accounts[acc_count].date_of_birth);
			printf("Account type : ");
			scanf("%s", accounts[acc_count].account_type);
			printf("Account number : ");
			scanf("%d", &accounts[acc_count].account_number);
			printf("\nAccount created successfully!\n\n");

			accounts[acc_count].printInfo();
			acc_count++;
		}
		else if(command == 2){
			int search_key;
			printf("Please, enter the account ID : ");
			scanf("%d", &search_key);

			//account search and print info by account number
			if(searchAccount(search_key, accounts) == -1){
					printf("Account Not Found!\n");
			}
			else {
				accounts[searchAccount(search_key, accounts)].printInfo();	
			}
		}
		else if(command == 3){
			printf("\n");
			if(acc_count == 0){
				printf("There is no account in the database.\n");
			}
			for(int i = 0; i < 20; i++){
				if(accounts[i].account_number != 0){
					printf("%s(%d) : $%d", accounts[i].name, accounts[i].account_number, accounts[i].balance);
					printf("\n");
				}
			}
			printf("\n");
		}
		else if(command == 4){
			int temp_id;
			int temp_depo;
			printf("Enter the account number : ");
			scanf("%d", &temp_id);
				if(searchAccount(temp_id, accounts) == -1){
					printf("\nAccount Not Found!\n\n");
				}
				else {
					printf("Enter deposit amount : ");
					scanf("%d", &temp_depo);
					accounts[searchAccount(temp_id, accounts)].deposit(temp_depo);
					printf("\nCurrent balance is : $%d\n\n", accounts[searchAccount(temp_id, accounts)].balance);	
				}
		}
		else if(command == 5){
			int temp_id;
			int temp_wd;
			printf("Enter the account number : ");
			scanf("%d", &temp_id);
				if(searchAccount(temp_id, accounts) == -1){
					printf("\nAccount Not Found!\n\n");
				}
				else {
					printf("Enter withdraw amount : ");
					scanf("%d", &temp_wd);
					accounts[searchAccount(temp_id, accounts)].withdraw(temp_wd);
					printf("\nCurrent balance is : $%d\n\n", accounts[searchAccount(temp_id, accounts)].balance);	
				}
		}
		else if(command == 6){
			int temp_id;
			int search_key;
			printf("Enter the account number : ");
			scanf("%d", &search_key);

			//account search
			if(searchAccount(search_key, accounts) == -1){
					printf("Account Not Found!\n");

			}
			else {
				temp_id = searchAccount(search_key, accounts);	
				for(int i = temp_id; i < acc_count - 1; i++){
					accounts[i].account_number = accounts[i+1].account_number;
					accounts[i].balance = accounts[i+1].balance;
					strcpy(accounts[i].name, accounts[i+1].name);
					strcpy(accounts[i].address, accounts[i+1].address);
					strcpy(accounts[i].date_of_birth, accounts[i+1].date_of_birth);
					strcpy(accounts[i].account_type, accounts[i+1].account_type);
				}
				accounts[acc_count-1].account_number = 0;
				acc_count--;

				printf("\nAccount removed successfully!\n\n");
			}



		}
		else{
			printf("\nYou entered a wrong command!. Try again.\n\n");
		}
	}
}
