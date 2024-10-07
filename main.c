#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

/*functions outside of main*/

void add_item(Item *item_list, double price, const char *sku, const char 
*category, const char *name, int index)
{
	item_list[index].price = price;
	item_list[index].sku = (char *)malloc(strlen(sku) + 1);
	strcpy(item_list[index].sku, sku);
		
	item_list[index].category = (char *)malloc(strlen(category) + 1); 
	strcpy(item_list[index].category, category);
	
	item_list[index].name = (char *)malloc(strlen(name) + 1);
	strcpy(item_list[index].name, name);
}

void free_items(Item *item_list, int size)
{
	for(int i = 0; i < size; i++) {
		free(item_list[i].sku);
		free(item_list[i].category); 
		free(item_list[i].name);

	}
	free(item_list);
}

double average_price(Item *item_list, int size)
{	
	if(size ==0) return 0.0;
	double total = 0.0;

	for(int i = 0; i < size; i++) {
		total += item_list[i].price;
	}
	return total / size;
}

void print_items(Item *item_list, int size)
{
	for(int i = 0; i < size; i++) {
		printf("#############\n");
		printf("Item name: %s\n", item_list[i].name);
		printf("Item sku: %s\n", item_list[i].sku);
		printf("Item category: %s\n", item_list[i].category);
		printf("Item price: %lf\n", item_list[i].price);
		printf("#############\n");
	}
}

int main(int argc, char *argv[]) 
{

	int item_num = 5;
	Item *item_list = (Item *)malloc(item_num * sizeof(Item));

	add_item(item_list, 5.00, "19282", "Breakfast", "Reeses Cereal", 0);
	add_item(item_list, 3.95, "79862", "Dairy", "Milk", 1);
	add_item(item_list, 7.50, "12345", "Beverage", "Orange Juice", 2);
	add_item(item_list, 12.99, "54321", "Snacks", "Chips", 3);
	add_item(item_list, 2.75, "67890", "Vegetables", "Carrot", 4);
	
	print_items(item_list, item_num);

	double avg_price = average_price(item_list, item_num);
	printf("##########\n");
	printf("Average price of items: %lf\n", avg_price);
	printf("##########\n");

	if(argc == 2) 
	{
		char *search_sku = argv[1];
		int found = 0;
		for(int i = 0; i < item_num; i++) 
		{
			if(strcmp(item_list[i].sku, search_sku) == 0) 
			{
				printf("Item found!\n");
				printf("Item Name: %s\n", item_list[i].name);
				printf("Item Sku: %s\n", item_list[i].sku);
				printf("Item category: %s\n", item_list[i].category);
				printf("Item price: %lf\n", item_list[i].price);
				found = 1;
				break;
			}
		}

		if(!found) 
		{

			printf("Item not found.\n");
		}
	}	

	free_items(item_list, item_num);

	return 0;
}
