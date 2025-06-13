#include "food_order.h"

int	process_food_order(struct OrderRequest *request)
{
	int	restaurant_status;
	struct OrderConfirmation *confirmation;
	int	notification;

	restaurant_status = check_restaurant_status(request);
	if ( restaurant_status == 1)
	{
		confirmation = create_standard_confirmation();
		notification = 1;
	}
	else
	{
		confirmation = create_preorder_confirmation(void);
		notification = 0;
	}
	send_confirmation_notification(confirmation);
	return(notification)
}


// // Checks if the restaurant is open based on the order. Returns 1 if open, 0 if closed.
// int check_restaurant_status(struct OrderRequest *request);
// // Creates a confirmation for an immediate order. Returns NULL on failure.
// struct OrderConfirmation *create_standard_confirmation(void);
// // Creates a confirmation for a future (pre-order). Returns NULL on failure.
// struct OrderConfirmation *create_preorder_confirmation(void);
// // Sends the confirmation to the user.
// void send_confirmation_notification(struct OrderConfirmation *confirmation);