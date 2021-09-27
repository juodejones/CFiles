//Created  by Juode

#include <stdio.h>

int getDiscount(int price)
{
	if (price<1000)
		return (price*5)/100;
	else if ((price >= 1000) && (price < 5000))
		return (price*10)/100;
	else if (price >=5000)
		return (price*15)/100;

}

void main()
{
	struct details
	{
		char name[20];
		int price;
		int quantity;
	};
	
	int n, discount, totalPrice = 0;
	printf("Enter number of items : ");
	scanf("%d", &n);
	
	struct details items[n];
	
	for (int i = 0; i < n; i++)
	{
		printf("Item name : ");
		scanf("%s", items[i].name);
		printf("Quantity : ");
		scanf("%d", &items[i].quantity);
		printf("Price : ");
		scanf("%d", &items[i].price);
		totalPrice += items[i].price;
	}
	
	for (int i = 0; i < n; i++)
		printf("%s | Price : %d | Quantity : %d\n", items[i].name, items[i].price, items[i].quantity);
	discount = getDiscount(totalPrice);
	printf("Total price = %d\n", totalPrice);
	printf("Discount = %d\n", discount);
	printf("Final price = %d\n", (totalPrice-discount));
	
}

