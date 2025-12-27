#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STK 50
#define MAX_PUR 200
#define NAMEL 30
#define TRY 3


/* functions */
int find_idx(char stk[][NAMEL], int l, const char *nm);                                               /*l : number of products in stock (same as stock count)*/
void show_stock(char stk[][NAMEL], int qstk[], int pr[], int l);
void print_bill(char pname[][NAMEL], int pqty[], int pprice[], int c);

int find_idx(char stk[][NAMEL], int l, const char *nm){
    int i;
    for(i=0;i<l;i++){
	if(strcmp(stk[i], nm)==0) return i;
    }
    return -1;
}

void show_stock(char stk[][NAMEL], int qstk[], int pr[], int l){
    int i;
    if(l==0){
	printf("\n\tKindly Add The Product First!");
	return;
    }
    printf("\n\n\tStock Product Listout\n");
    printf("\t~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\n\n\tStock Product Name\tStock Product Quantity\tStock Product Price\n");
    for(i=0;i<l;i++){
	printf("\n\t%s\t\t\t%d\t\t\t%d", stk[i], qstk[i], pr[i]);
    }
}

void print_bill(char pname[][NAMEL], int pqty[], int pprice[], int c){
    int i;
    int g=0;
    if(c==0){
	printf("\nNo items purchased yet!");
	return;
    }
    printf("\n\t--------------------------");
    printf("\n\t\t\t\tBill\n");
    printf("\t----------------------------");
    printf("\n\tProduct Name \tProduct Quantity \tProduct Price");
    for(i=0;i<c;i++){
	int line = pqty[i] * pprice[i];
	printf("\n\t%s", pname[i]);
	printf("\t\t%d", pqty[i]);
	printf("\t\t\t%d", line);
	g += line;
    }
    printf("\n--------------------------------------------------------------------------------");
    printf("\n\t\t\tGrand Total : %d", g);
    printf("\n--------------------------------------------------------------------------------");
}

void main(){
    int l=0, s=0, f=0, st=0, lim=TRY, c=0;
    int ch, extra;
    int pr[MAX_STK];           /* price for stock items */
    int qstk[MAX_STK];         /* stock quantities */
    int pqty[MAX_PUR];         /* purchased quantities */
    int pprice[MAX_PUR];       /* purchase-locked price (price at time of purchase) */
    char stk[MAX_STK][NAMEL];  /* stock item names */
    char pname[MAX_PUR][NAMEL];/* purchased item names */
    char opt;

    clrscr();
    do{
	clrscr();
	printf("\t\t\t\t*****************\n");
	printf("\t\t\t\t DEPARMENT STORE\n");
	printf("\t\t\t\t*****************\n");
	printf("\t\t\t1.Add The Stock Product Details.\n");
	printf("\t\t\t2.Stock Product Listout.\n");
	printf("\t\t\t3.Stock Product Is Avaliable Or Unavaliable.\n");
	printf("\t\t\t4.Update The Stock Product Cost.\n");
	printf("\t\t\t5.Update The Stock Product Quantity.\n");
	printf("\t\t\t6.Purchashing product\n");
	printf("\t\t\t7.Billing\n");
	printf("\t\t\t8.Exit\n");
	printf("\n\n\tEnter The Choice:");
	scanf("%d",&ch);

	switch(ch){
	    case 1:
		printf("\n\n\tAdd The Stock Product Details\n");
		printf("\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		if(l >= MAX_STK){
		    printf("\n\tStock limit reached!");
		    break;
		}
		printf("\n\tEnter The Stock Product Name     :");
		scanf("%29s", stk[l]);
		printf("\n\n\tEnter The Stock Product Quantity :");
		scanf("%d",&qstk[l]);
		printf("\n\n\tEnter The Stock Product Price    :");
		scanf("%d",&pr[l]);
		s++;
		l++;
		printf("\n\t\t\t\t----------------------------\n");
		printf("\t\t\t\tProduct Is Added Sucessfully\n");
		printf("\t\t\t\t----------------------------");
		break;

	    case 2:
		show_stock(stk, qstk, pr, l);
		break;

	    case 3:
		if(s>0){
		    char tmp[NAMEL];
		    printf("\n\n\tStock is available or unavailable\n");
		    printf("\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		    printf("\n\tEnter the product name :");
		    scanf("%29s", tmp);
		    f = find_idx(stk, l, tmp);
		    if(f != -1){
			printf("\n\tProduct quantity");
			printf("\tProduct price");
			printf("\n\t%d", qstk[f]);
			printf("\t\t\t%d", pr[f]);
		    } else {
			printf("\n\n\tThe product is not available!\n");
		    }
		}else{
		    printf("\n\tKindly Add The Product First!");
		}
		break;

	    case 4:
		if(s>0){
		    char tmp[NAMEL];
		    printf("\n\n\tUpdate The product Cost\n");
		    printf("\t~~~~~~~~~~~~~~~~~~~~~~~\n");
		    printf("\n\tEnter The Product Name  :");
		    scanf("%29s", tmp);
		    f = find_idx(stk, l, tmp);
		    if(f != -1){
			printf("\n\tProduct Quantity      : %d", qstk[f]);
			printf("\n\n\tProduct price          : %d", pr[f]);
			st=0;
			while(st<lim){
			    int newp;
			    printf("\n\n\tEnter The Updated Price : ");
			    scanf("%d",&newp);
			    if(newp>0){
				pr[f] = newp;
				printf("\n\tUpdated Product Price : %d",pr[f]);
				printf("\n\n\tProduct Name \tProduct Quantity \tProduct Price");
				printf("\n\t%s",stk[f]);
				printf("\t\t%d",qstk[f]);
				printf("\t\t\t%d",pr[f]);
				printf("\n\t\t\t---------------------------\n");
				printf("\t\t\tUpdate The Cost Sucessfully\n");
				printf("\t\t\t---------------------------\n");
				break;
			    }else{
				printf("\n\t\t\tGive The Positive Value?");
			    }
			    st++;
			}
			if(st==lim){
			    printf("\n\n\t\tYour Attempt Is Over Try Again Later!");
			}
		    } else {
			printf("\n\tThe Product Is Unavailable!");
		    }
		}else{
		    printf("\n\tKindly Add The Product First!");
		}
		break;

	    case 5:
		if(s>0){
		    char tmp[NAMEL];
		    printf("\n\n\tUpdate The Product Quantity\n");
		    printf("\t~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		    printf("\tEnter The Product Name :");
		    scanf("%29s", tmp);
		    f = find_idx(stk, l, tmp);
		    if(f != -1){
			printf("\n\tProduct Quantity : %d", qstk[f]);
			printf("\n\n\tProduct Price   : %d", pr[f]);
			st=0;
			while(st<lim){
			    printf("\n\n\tEnter The Updated Quantity  :");
			    scanf("%d",&extra);
			    if(extra>0){
				qstk[f] = qstk[f] + extra;
				printf("\n\n\tUpdated Product Quantity : %d", qstk[f]);
				printf("\n\n\tProduct Name \tProductQuantity \tProduct Price");
				printf("\n\t%s", stk[f]);
				printf("\t\t\t%d", qstk[f]);
				printf("\t\t\t%d", pr[f]);
				printf("\n\t\t\t-------------------------------\n");
				printf("\t\t\tUpdate The Quantity Sucessfully\n");
				printf("\t\t\t-------------------------------\n");
				break;
			    }else{
				printf("\n\t\t\tGive The Positive Value?");
			    }
			    st++;
			}
			if(st==lim){
			    printf("\n\n\tYour Attempt Is Over Try Again Later!");
			}
		    } else {
			printf("\n\tThe Product Is Unavaliable!");
		    }
		}else{
		    printf("\n\tKindly Add The Product First!");
		}
		break;

	    case 6:
		if(s > 0){
		    if(c >= MAX_PUR){
			printf("\n\tCart Full!");
			break;
		    }
		    printf("\n\n\tPurchasing product\n");
		    printf("\t~~~~~~~~~~~~~~~~~~~~~~~\n");
		    printf("\n\tEnter The Purchasing Product Name : ");
		    scanf("%29s", pname[c]);
		    f = find_idx(stk, l, pname[c]);
		    if(f != -1){
			printf("\n\tAvailable Quantity : %d", qstk[f]);
			printf("\n\tPrice per unit     : %d", pr[f]);
			printf("\n\tEnter The Purchasing Product Quantity : ");
			scanf("%d", &pqty[c]);
			if(pqty[c] > qstk[f]){
			    printf("\n\tNot enough stock available!");
			    /* undo name since not purchased */
			    pname[c][0] = '\0';
			} else {
			    qstk[f] = qstk[f] - pqty[c];
			    pprice[c] = pr[f]; /* lock price at purchase time */
			    printf("\n\tProduct added to cart successfully!");
			    c++;
			}
		    } else {
			printf("\n\tThe Product Is Unavailable!");
		    }
		}else{
		    printf("\n\tKindly Add The Product First!");
		}
		break;

	    case 7:
		print_bill(pname, pqty, pprice, c);
		break;

	    case 8:
		exit(0);
		break;

	    default:
		printf("Invalid");
		break;
	} /* end switch */

	/* ask continue (use getche for Turbo C) */
	st = 0;
	while(st < lim){
	    printf("\n\n\tDo You Want To Continue? Y/N: ");
	    opt = getche(); /* reads char immediately */
	    if(opt=='y' || opt=='Y' || opt=='n' || opt=='N'){
		break;
	    } else {
		printf("\n\n\tGive The Valid Option..?");
	    }
	    st++;
	}
	if(st==lim){
	    printf("\n\n\tYour Attempt Is Over Try Again Later..");
	    break;
	}

    } while(opt=='y' || opt=='Y');

    getch();
}

