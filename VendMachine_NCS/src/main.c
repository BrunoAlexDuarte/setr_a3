/* Includes. Add according to the resources used  */
#include <zephyr/kernel.h>          /* for k_msleep() */
#include <zephyr/device.h>          /* for device_is_ready() and device structure */
#include <zephyr/devicetree.h>		/* for DT_NODELABEL() */
#include <zephyr/drivers/gpio.h>    /* for GPIO api*/
/* StateMachine generated code */
#include "../../VendMachine/src/sc_types.h"
#include "../../VendMachine/src-gen/Statechart_required.h"
#include "../../VendMachine/src-gen/Statechart.h"

/* Get led 0-3 and button 0-3 node IDs. Refer to the DTS file */
#define LED0_NODE DT_ALIAS(led0)
#define LED1_NODE DT_ALIAS(led1)
#define BUT0_NODE DT_ALIAS(sw0)
#define BUT1_NODE DT_ALIAS(sw1)
#define BUT2_NODE DT_ALIAS(sw2)
#define BUT3_NODE DT_ALIAS(sw3)

/* Get the device pointer, pin number, and configuration flags for led 0-3 and button 0-3. A build error on this line means your board is unsupported. */
static const struct gpio_dt_spec led_0 = GPIO_DT_SPEC_GET(LED0_NODE, gpios);
static const struct gpio_dt_spec led_1 = GPIO_DT_SPEC_GET(LED1_NODE, gpios);
static const struct gpio_dt_spec but_0 = GPIO_DT_SPEC_GET(BUT0_NODE, gpios);
static const struct gpio_dt_spec but_1 = GPIO_DT_SPEC_GET(BUT1_NODE, gpios);
static const struct gpio_dt_spec but_2 = GPIO_DT_SPEC_GET(BUT2_NODE, gpios);
static const struct gpio_dt_spec but_3 = GPIO_DT_SPEC_GET(BUT3_NODE, gpios);

Statechart StateMachine; // The statemachine structure variable 

/* Define the callback functions */
void but0_pressed(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
{
    statechart_but_raise_b1(&StateMachine);
    return;
}

void but1_pressed(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
{
    statechart_but_raise_b2(&StateMachine);
	return;
}

void but2_pressed(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
{
    statechart_but_raise_b3(&StateMachine);
	return;
}

void but3_pressed(const struct device *dev, struct gpio_callback *cb, uint32_t pins)
{
    statechart_but_raise_b4(&StateMachine);
	return;
}

/*
 * The main function
 */
int main(void)
{
	int ret = 0;

	// Define variables for holding callback data 
	static struct gpio_callback but0_cb_data;
	static struct gpio_callback but1_cb_data; 
    static struct gpio_callback but2_cb_data;  
    static struct gpio_callback but3_cb_data;

	/* Check if devices are ready */
	if(!device_is_ready(led_0.port) || !device_is_ready(led_1.port) ||
        !device_is_ready(but_0.port) || !device_is_ready(but_1.port) ||
        !device_is_ready(but_2.port) || !device_is_ready(but_3.port)) {

	    return 0;
	}	

	/* Configure the GPIO pins for input/output and set active logic */
	/* Note that the devicetree activates the internal pullup and sets the active low flag */
	/*   so an external resistor is not needed and pressing the button causes a logic level of 1*/
	
    ret = gpio_pin_configure_dt(&led_0, GPIO_OUTPUT_INACTIVE);
	if(ret < 0) {
		return 0;
	}
    ret = gpio_pin_configure_dt(&led_1, GPIO_OUTPUT_INACTIVE);
	if(ret < 0) {
		return 0;
	}

	ret = gpio_pin_configure_dt(&but_0, GPIO_INPUT);
	if(ret < 0) {
		return 0;
	}
    ret = gpio_pin_configure_dt(&but_1, GPIO_INPUT);
	if(ret < 0) {
		return 0;
	}
    ret = gpio_pin_configure_dt(&but_2, GPIO_INPUT);
	if(ret < 0) {
		return 0;
	}
    ret = gpio_pin_configure_dt(&but_3, GPIO_INPUT);
	if(ret < 0) {
		return 0;
	}

	/* Set interrupt */
	ret = gpio_pin_interrupt_configure_dt(&but_0, GPIO_INT_EDGE_TO_ACTIVE);
	gpio_init_callback(&but0_cb_data, but0_pressed, BIT(but_0.pin));
    ret = gpio_pin_interrupt_configure_dt(&but_1, GPIO_INT_EDGE_TO_ACTIVE);
	gpio_init_callback(&but1_cb_data, but1_pressed, BIT(but_1.pin));
    ret = gpio_pin_interrupt_configure_dt(&but_2, GPIO_INT_EDGE_TO_ACTIVE);
	gpio_init_callback(&but2_cb_data, but2_pressed, BIT(but_2.pin));
    ret = gpio_pin_interrupt_configure_dt(&but_3, GPIO_INT_EDGE_TO_ACTIVE);
	gpio_init_callback(&but3_cb_data, but3_pressed, BIT(but_3.pin));
	
	/* Add the callback function by calling gpio_add_callback()   */
	gpio_add_callback(but_0.port, &but0_cb_data);
    gpio_add_callback(but_1.port, &but1_cb_data);
    gpio_add_callback(but_2.port, &but2_cb_data);
    gpio_add_callback(but_3.port, &but3_cb_data);

    statechart_init(&StateMachine);
    statechart_enter(&StateMachine);

	return 0;
}


/* ******************************************************************** 
 * Implementation of external functions called by the StateMachine
 * ********************************************************************/

void statechart_changeLed(Statechart* handle, const sc_integer id) {
    switch (id) {
        case 0:
            gpio_pin_set_dt(&led_0, 0);
            gpio_pin_set_dt(&led_1, 0);
            break; 
    	case 1:
            gpio_pin_set_dt(&led_0, 0);
            gpio_pin_set_dt(&led_1, 1);
            break; 
		case 2:
            gpio_pin_set_dt(&led_0, 1);
            gpio_pin_set_dt(&led_1, 0);
            break;                   
    	case 3:
            gpio_pin_set_dt(&led_0, 1);
            gpio_pin_set_dt(&led_1, 1);
            break;       
        default:
            break;
    }
}

void statechart_showState(Statechart* handle, const sc_integer state) {
	printf("\e[1;1H\e[2J");
	switch (state) {
		case 0: // Insert
			printf("Balance: %d.", StateMachine.internal.Balance);
			break;
		case 1: // Browse
			printf("Product selected: %d.", StateMachine.internal.Choice);
			break;
		case 2: // ChangeExpeled
			printf("Change expeled.");
			break;
		case 3: // ProductExpeled
			printf("Product expeled.\n");
			printf("New balance: %d.", StateMachine.internal.Balance); 
			break;
		case 4: // Error
			printf("Insufficient balance for product %d.\n", StateMachine.internal.Choice);
			printf("Current balance: %d.\n", StateMachine.internal.Balance);
			printf("Required balance: %d.\n", StateMachine.internal.Choice);
			break; 
		default:
			break;
	}
}


