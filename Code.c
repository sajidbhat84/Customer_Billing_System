#include<stdio.h>
#include<string.h>
#include<conio.h>

struct item
{
	int productno;
	char productname[10];
	int quantity;
	int price;
}
item;
struct customer
{
	int productno;
	char productname[10];
	int quantity;
	int price;
	int amount;
}
cst[100];
int t=0;
int n=0; //used in Quantity and Records.txt
int k=0;
int ba=0;
int ti=0;
void create()
{
	int i=0;
	FILE *fp;
	fp=fopen("Records.txt","a");
	if(fp==NULL)
	{
		printf("Error\n");
	}
	printf("\t");
	printf("Enter the Number of Records:");
	scanf("%d",&n);
	printf("\n");
	FILE *fpq;
	fpq=fopen("Quantity.txt","a");
	//fprintf(fp,"ProductNo\t,ProductName\t, Quantity\t, Price\n");
	fprintf(fpq,"%d\n",n);
	fclose(fpq);
	while(i<n)
	{
	    printf("\t");
		printf("Enter Product Code:");
		scanf("%d",&item.productno);
		printf("\t");
		printf("Enter Product Name:");
		scanf("%s",item.productname);
		printf("\t");
		printf("Enter Quantity:");
		scanf("%d",&item.quantity);
		printf("\t");
		printf("Enter Price:");
		scanf("%d",&item.price);
		printf("\n");
		i++;
		fprintf(fp,"%d\t%s\t%d\t%d\n",item.productno,item.productname,item.quantity,item.price);
	}
	fclose(fp);
	printf("\t");
	printf("Records are Created");
	printf("\n");
	printf("\n");
}
void bill()
{
	int na=0;  //used for product number in scanf function
	int a=0;	
	int cont=0;
	int k=0;
	int r=0;
	int w=0;
	int ch=0;
	int l=0;	
	int bi=0;
	int ln=0;
    printf("\t");
	l3 : printf("Enter the Product Number:");
	scanf("%d",&na);
	printf("\n");
	FILE *fp;
	fp=fopen("Records.txt","r");
	FILE *fptr;
	fptr=fopen("temp.txt","w");
	while(!(feof(fp)))
	{
		l++;
		fscanf(fp,"%d",&item.productno);
		fscanf(fp,"%s",item.productname);
		fscanf(fp,"%d",&item.quantity);
		fscanf(fp,"%d",&item.price);
		if(item.productno == na)
		{
			ln++;
			if(ln==2)
			break;
			printf("Enter the Quantity:");
			scanf("%d",&a);
			if(a <= item.quantity)
			{
				cst[ti].productno=item.productno;
				strcpy(cst[ti].productname,item.productname);
				cst[ti].quantity=a;
				cst[ti].price=item.price;
				item.quantity=item.quantity-a;
				ti++;
			}
			else
			{
				printf("Sorry Out of Stock\n");
				bi++;
			}
		}
		else
		{
			cont++;
			fprintf(fptr,"%d\t",item.productno);
			fprintf(fptr,"%s\t",item.productname);
			fprintf(fptr,"%d\t",item.quantity);
			fprintf(fptr,"%d\t",item.price);
			continue;
		}
		fprintf(fptr,"%d\t",item.productno);
		fprintf(fptr,"%s\t",item.productname);
		fprintf(fptr,"%d\t",item.quantity);
		fprintf(fptr,"%d\t",item.price);
	}
	if(l==cont)
	printf("Error:Choose Properly\n");
	fclose(fptr);
	fclose(fp);
	remove("Records.txt");
	rename("temp.txt","Records.txt");
	ln=0;
	printf("Do you Want to Shop More:\nPress 1 for More\nPress 2 to Exit");
	scanf("%d",&k);
	if(k==1)
	goto l3;
}

void display()
{
	int nk=0;
	FILE *fp;
	fp=fopen("Records.txt","r");
	if(feof(fp))
	{
		printf("Error in Opening Files\n");
	}
	printf("\t");
printf("==============================================================\n");
	printf("\t");
	printf("|Product Number\t|Product Name\t|Quantity\t|Price\t\n");
	printf("\t");
printf("==============================================================\n");
	while(nk!=n)
	{
		nk++;
		fscanf(fp,"%d",&item.productno);
		if(item.productno==0)
		{
		    printf("\t");
			printf("There are no items in Cart");
			printf("\n");
			break;
		}
		fscanf(fp,"%s",item.productname);
		fscanf(fp,"%d",&item.quantity);
		fscanf(fp,"%d",&item.price);
printf("\n\t  %14d|\t%8s|\t%8d|\t%d|\n",item.productno,item.productname,item.quantity,item.price);
	}
fclose(fp);
}
void invoice()
{
	int j;
	int o;
	float gt=0;
	if(ti==0)
	{
		printf("There are No Products in your Cart");
		printf("\n");
	}

	printf("\n\n");
	printf("************************  SS TRADERS  *********************************");
	printf("\n");
	printf("****************************INVOICE**************************");
	printf("\n\n");
	printf("product number\t| product name\t| price\t| quantity\t| amount\t|\n");
	printf("*************************************************************\n");
	for(o=0;o<ti;o++)
	{
		cst[o].amount=0;
		cst[o].amount=((cst[o].price)*(cst[o].quantity));
		gt=gt+cst[o].amount;
	}
	for(j=0;j<ti;j++)
	{
		printf("%6d\t       |%9s   \t  | %3d\t|%3d\t        |   %3d\n",cst[j].productno,cst[j].productname,cst[j].price,cst[j].quantity,cst[j].amount);
	}
	printf("\nAmount Payable:%f",gt);
	printf("\n");
	printf("Thank you for Shopping");
	printf("\n");
	printf("Visit Again");
	printf("\n");
}
int main()
{
	char ch,password[10],q[10]="123456";
	int s=0;
	int y=0;
	int w=1;
	int i;
	FILE *fpe;
	fpe=fopen("Quantity.txt","r");
	fscanf(fpe,"%d",&n);
	fclose(fpe);
	printf("\n");
	printf("************************************************************************************************************************");
	printf("\n");
	printf("*****************************************    WELCOME TO SS TRADERS   *************************************************");
	printf("\n");
	printf("\t                                THE ALL U CAN GET AT ONE PLACE\n");
	printf("\t\t\t\t\t ADDRESS:NEW YORK CITY\ n");
	printf("\t\t\tOWNER:SURAJ PANDIT\t\t\tCONTACT NO:7005588225");
	printf("\n");
	//printf("\t\t\t\t\t");
printf("************************************************************************************************************************\n");
    //printf("      Reference Number: %d\n",n);
    q: printf("\n\t");
    printf("****************************");
    printf("\n");
    printf("\t");
    printf("Please Select an Option: ");
    printf("\n");
    printf("\t");
    printf("****************************");
    printf("\n");
    printf("\t");
	printf("01. ADMINISTRATOR");
	printf("\n\t");
	printf("02. CUSTOMER");
	printf("\n\t");
	printf("03. EXIT");
	printf("\n");
	printf("\n\t");
	printf("Please Enter an Option: ");
	scanf("%d",&s);

	switch(s)
	{
	          case 1: printf("\tEnter Password:\t");
              for(i=0;i<6;i++)
              {
              ch = getch();
              password[i] = ch;
              ch = '*' ;
               printf("%c",ch);
              }
              password[i]='\0';
              if(strcmp(password,q))
              {
                  printf("\n\t");
              printf("Wrong Password Please Try Again");
              printf("\n\n");
              goto q;
             }
               else
               printf("\n\t");
               printf("Access Granted\n");
               printf("\n\n");
               printf("\t");
               printf("****************************");
               printf("\n");
               printf("\t");
               printf("Please Select an Option: ");
               printf("\n");
               printf("\t");
               printf("****************************");
               printf("\n");
              printf("\t01.CREATE");
	printf("\n\t");
               printf("02.DISPLAY");
	printf("\n\t");
              printf("03.MAIN MENU");
              printf("\n");
             printf("\n");
	printf("\t");
	 printf("Please Enter an Option: ");
               scanf("%d",&y);
	 switch(y)
		   {
        	case 1:create();
        	 goto q;
                  case 2:display();
                         goto q;
                  case 3: goto q;
                  default : printf("error\n");
		 goto q;
        		}
		   break;
case 2:
               printf("\n");
               printf("\t");
               printf("****************************");
               printf("\n");
               printf("\t");
               printf("Plese Select an Option: ");
               printf("\n");
               printf("\t");
               printf("****************************");
               printf("\n");
               printf("\t");
               printf("01.BILL");
               printf("\n\t");
               printf("02.INVOICE");
               printf("\n\t");
               printf("03.DISPLAY");
               printf("\n\t");
               printf("04.MAIN MENU");
               printf("\n\t");
               printf("Please Enter an Option: ");
               scanf("%d",&y);
               printf("\n");
               switch(y)
		        {
                    case 1 : bill();
        		 goto q;
                  case 2 : invoice();
                             goto q;
                  case 3 : display();
                             goto q;
                   case 4: goto q;
                    default : printf("Error\n");
                              goto q;
        		}
		       break;
      case 3: printf("\tExiting...\n");
      break;
      default : printf("error\n");
      break;
	}
}