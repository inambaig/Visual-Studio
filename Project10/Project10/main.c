#include <stdio.h>
#include<stdlib.h>
#include "list.h";

void flush()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF)
		;
}
void main()
{
	rider_st *list_head = NULL;
	int id = 0;
	char *first_name = malloc(50);
	char *last_name = malloc(50);
	double ave_rating = 0;
	double distance = 0;
	while (1)
	{
		printf("Enter id : ");
		scanf_s("%d", &id);
		if (id == 8)
			break;
		printf("Enter first name : ");
		fgets(first_name, 25, stdin);
		flush();
		printf("Enter last name : ");
		fgets(last_name, 25, stdin);
		flush();
		printf("Enter Average Rating : ");
		scanf_s("%d", &ave_rating);
		printf("Enter distance : ");
		scanf_s("%d", &distance);
		printf("Distance : %d", distance);
		rider_st *newrider = create_new_rider(id, first_name, last_name, ave_rating, distance);

		char option = 0;
		printf("Where do u wanna insert this node\n\n\t\t\tPress 1) Front\n\n\t\t\t2) End\n\n\t\t\t2) Ordered");
		scanf_s("%c", &option);

		while (option<'1' || option>'3')
		{
			printf("\t\t\tInvalid option , Enter again : ");
			scanf_s("%c", &option);
		}
		if (option == '1')
		{
			rider_st *p = newrider;
			front_insert(&list_head, p);
			list_head=list_head;
			//menu();
		}
		else if (option == '2')
		{
			rider_st *p = newrider;
			end_insert(&list_head, p);
			list_head = list_head;
			//menu();
		}
		else if (option == '3')
		{
			rider_st *p = newrider;
			ordered_insert(&list_head, p);
			//menu();
		}
	}
	rider_st st = find_next_distance_rider(list_head, 5);
	st = st;
	printf("Distance %d, %d", st.distance, st.ID);
	empty(&list_head);
	
	system("pause>0");
}
//void menu()
//{
//	char option;
//	system("cls");
//	printf("================================================================================\n\n"
//		"\t\t\t\tWELCOME\n\n\n"
//		"================================================================================\n\n"
//		"\t\t\t1)create new rider\n\n\t\t\t2)front insert\n\n\t\t\t3)end insert\n\n\t\t\t4)ordered insert\n\n\t\t\t5)empty\n\n\t\t\t6)find next distance rider\n\n\t\t\t7)Exit\n\n\t\t\tChoose option : ");
//	scanf_s("%s %d",option);
//	while(option<'1' || option>'7')
//	{
//		printf("\t\t\tInvalid option , Enter again : ");
//		scanf_s("%s %d",option);
//	}
//	if(option == '1')
//	{
//		create_new_rider();
//		menu();
//	}
//	else if(option == '2')
//	{
//		front_insert();
//		menu();
//	}
//	else if(option=='3')
//	{
//		end_insert();
//		menu();
//	}
//	else if(option=='4')
//	{
//		ordered_insert();
//		menu();
//	}
//	else if(option=='5')
//	{
//		empty();
//		menu();
//	}
//	else if(option=='6')
//	{
//		deletes();
//		menu();
//	}
//	else
//	{
//		cout<<"\n\t\t\tprogram is going to exit";
//	}
//}