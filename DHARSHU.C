#include<stdio.h>
#include<conio.h>
void main(){
	int list,product;
	clrscr();
	printf("\t\t\t**********\n");
	printf("\t\t\tDHARSHU SUPER MARKET\n");
	printf("\t\t\t**********\n");
	printf("Enter the number:");
	scanf("%d",&list);
	switch(list){
		case 1:
			printf("Add the product details");
			break;
		case 2:
			printf("Product listout");
			break;
		case 3:
			printf("View single product");
			break;
		case 4:
			printf("Update the product cost");
			break;
		case 5:
			printf("Update the product quantity");
			break;
		case 6:
			printf("Purchashing");
			break;
		case 7:
			printf("Billing");
			break;
		default:
			printf("Invalid");
			break;
		}