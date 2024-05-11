/** Generated by itemis CREATE code generator. */


#include "../src/sc_types.h"

#include "Statechart.h"
#include "Statechart_required.h"

/*! \file
Implementation of the state machine 'Statechart'
*/

#ifndef SC_UNUSED
#define SC_UNUSED(P) (void)(P)
#endif

/* prototypes of all internal functions */
static void enseq_a_Browse_default(Statechart* handle);
static void enseq_a_ProductExpeled_default(Statechart* handle);
static void enseq_a_Insert_default(Statechart* handle);
static void enseq_a_Error_default(Statechart* handle);
static void enseq_a_ChangeExpeled_default(Statechart* handle);
static void enseq_a_default(Statechart* handle);
static void exseq_a_Browse(Statechart* handle);
static void exseq_a_ProductExpeled(Statechart* handle);
static void exseq_a_Insert(Statechart* handle);
static void exseq_a_Error(Statechart* handle);
static void exseq_a_ChangeExpeled(Statechart* handle);
static void exseq_a(Statechart* handle);
static void react_a__entry_Default(Statechart* handle);

/*! State machine reactions. */
static sc_integer react(Statechart* handle, const sc_integer transitioned_before);

/*! The reactions of state Browse. */
static sc_integer a_Browse_react(Statechart* handle, const sc_integer transitioned_before);

/*! The reactions of state ProductExpeled. */
static sc_integer a_ProductExpeled_react(Statechart* handle, const sc_integer transitioned_before);

/*! The reactions of state Insert. */
static sc_integer a_Insert_react(Statechart* handle, const sc_integer transitioned_before);

/*! The reactions of state Error. */
static sc_integer a_Error_react(Statechart* handle, const sc_integer transitioned_before);

/*! The reactions of state ChangeExpeled. */
static sc_integer a_ChangeExpeled_react(Statechart* handle, const sc_integer transitioned_before);


static void clear_in_events(Statechart* handle);

static void micro_step(Statechart* handle);

/*! Performs a 'run to completion' step. */
static void run_cycle(Statechart* handle);




static void statechart_internal_set_balance(Statechart* handle, sc_integer value)
;
static void statechart_internal_set_choice(Statechart* handle, sc_integer value)
;


static void statechart_eventqueue_init(statechart_eventqueue * eq, statechart_event *buffer, sc_integer capacity);
static sc_integer statechart_eventqueue_size(statechart_eventqueue * eq);
static void statechart_event_init(statechart_event * ev, StatechartEventID name);
static statechart_event statechart_eventqueue_pop(statechart_eventqueue * eq);
static sc_boolean statechart_eventqueue_push(statechart_eventqueue * eq, statechart_event ev);
static void statechart_add_event_to_queue(statechart_eventqueue * eq, StatechartEventID name);
static sc_boolean statechart_dispatch_event(Statechart* handle, const statechart_event * event);
static statechart_event statechart_get_next_event(Statechart* handle);
static sc_boolean statechart_dispatch_next_event(Statechart* handle);


void statechart_init(Statechart* handle)
{
	sc_integer i;
	
	for (i = 0; i < STATECHART_MAX_ORTHOGONAL_STATES; ++i)
	{
		handle->stateConfVector[i] = Statechart_last_state;
	}
	
				
	clear_in_events(handle);
	
	
	/* Default init sequence for statechart Statechart */
	statechart_light_set_l1(handle, bool_false);
	statechart_light_set_l2(handle, bool_false);
	statechart_light_set_l3(handle, bool_false);
	statechart_light_set_l4(handle, bool_false);
	statechart_internal_set_balance(handle, 0);
	statechart_internal_set_choice(handle, 0);
	
	handle->isExecuting = bool_false;
	statechart_eventqueue_init(&handle->in_event_queue, handle->in_buffer, STATECHART_IN_EVENTQUEUE_BUFFERSIZE);
}

void statechart_enter(Statechart* handle)
{
	/* Activates the state machine. */
	if (handle->isExecuting == bool_true)
	{ 
		return;
	} 
	handle->isExecuting = bool_true;
	/* Default enter sequence for statechart Statechart */
	enseq_a_default(handle);
	handle->isExecuting = bool_false;
}

void statechart_exit(Statechart* handle)
{
	/* Deactivates the state machine. */
	if (handle->isExecuting == bool_true)
	{ 
		return;
	} 
	handle->isExecuting = bool_true;
	/* Default exit sequence for statechart Statechart */
	exseq_a(handle);
	handle->isExecuting = bool_false;
}

/*!
Can be used by the client code to trigger a run to completion step without raising an event.
*/
void statechart_trigger_without_event(Statechart* handle) {
	run_cycle(handle);
}


sc_boolean statechart_is_active(const Statechart* handle)
{
	sc_boolean result = bool_false;
	sc_integer i;
	
	for(i = 0; i < STATECHART_MAX_ORTHOGONAL_STATES; i++)
	{
		result = result || handle->stateConfVector[i] != Statechart_last_state;
	}
	
	return result;
}

/* 
 * Always returns 'false' since this state machine can never become final.
 */
sc_boolean statechart_is_final(const Statechart* handle)
{
	SC_UNUSED(handle);
	return bool_false;
}

sc_boolean statechart_is_state_active(const Statechart* handle, StatechartStates state)
{
	sc_boolean result = bool_false;
	switch (state)
	{
		case Statechart_a_Browse :
			result = (sc_boolean) (handle->stateConfVector[SCVI_STATECHART_A_BROWSE] == Statechart_a_Browse
			);
				break;
		case Statechart_a_ProductExpeled :
			result = (sc_boolean) (handle->stateConfVector[SCVI_STATECHART_A_PRODUCTEXPELED] == Statechart_a_ProductExpeled
			);
				break;
		case Statechart_a_Insert :
			result = (sc_boolean) (handle->stateConfVector[SCVI_STATECHART_A_INSERT] == Statechart_a_Insert
			);
				break;
		case Statechart_a_Error :
			result = (sc_boolean) (handle->stateConfVector[SCVI_STATECHART_A_ERROR] == Statechart_a_Error
			);
				break;
		case Statechart_a_ChangeExpeled :
			result = (sc_boolean) (handle->stateConfVector[SCVI_STATECHART_A_CHANGEEXPELED] == Statechart_a_ChangeExpeled
			);
				break;
			default:
				result = bool_false;
				break;
		}
		return result;
	}

static void clear_in_events(Statechart* handle)
{
	handle->ifaceBut.B1_raised = bool_false;
	handle->ifaceBut.B2_raised = bool_false;
	handle->ifaceBut.B3_raised = bool_false;
	handle->ifaceBut.B4_raised = bool_false;
}

static void micro_step(Statechart* handle)
{
	switch(handle->stateConfVector[ 0 ])
	{
		case Statechart_a_Browse :
		{
			a_Browse_react(handle,-1);
			break;
		}
		case Statechart_a_ProductExpeled :
		{
			a_ProductExpeled_react(handle,-1);
			break;
		}
		case Statechart_a_Insert :
		{
			a_Insert_react(handle,-1);
			break;
		}
		case Statechart_a_Error :
		{
			a_Error_react(handle,-1);
			break;
		}
		case Statechart_a_ChangeExpeled :
		{
			a_ChangeExpeled_react(handle,-1);
			break;
		}
		default: 
			/* do nothing */
			break;
	}
}

static void run_cycle(Statechart* handle)
{
	/* Performs a 'run to completion' step. */
	if (handle->isExecuting == bool_true)
	{ 
		return;
	} 
	handle->isExecuting = bool_true;
	statechart_dispatch_next_event(handle);
	do
	{ 
		micro_step(handle);
		clear_in_events(handle);
	} while (statechart_dispatch_next_event(handle) == bool_true);
	handle->isExecuting = bool_false;
}




sc_boolean statechart_light_get_l1(const Statechart* handle)
{
	return handle->ifaceLight.L1;
}
void statechart_light_set_l1(Statechart* handle, sc_boolean value)
{
	handle->ifaceLight.L1 = value;
}
sc_boolean statechart_light_get_l2(const Statechart* handle)
{
	return handle->ifaceLight.L2;
}
void statechart_light_set_l2(Statechart* handle, sc_boolean value)
{
	handle->ifaceLight.L2 = value;
}
sc_boolean statechart_light_get_l3(const Statechart* handle)
{
	return handle->ifaceLight.L3;
}
void statechart_light_set_l3(Statechart* handle, sc_boolean value)
{
	handle->ifaceLight.L3 = value;
}
sc_boolean statechart_light_get_l4(const Statechart* handle)
{
	return handle->ifaceLight.L4;
}
void statechart_light_set_l4(Statechart* handle, sc_boolean value)
{
	handle->ifaceLight.L4 = value;
}
void statechart_but_raise_b1(Statechart* handle)
{
	statechart_add_event_to_queue(&(handle->in_event_queue), Statechart_but_B1);
	run_cycle(handle);
}

void statechart_but_raise_b2(Statechart* handle)
{
	statechart_add_event_to_queue(&(handle->in_event_queue), Statechart_but_B2);
	run_cycle(handle);
}

void statechart_but_raise_b3(Statechart* handle)
{
	statechart_add_event_to_queue(&(handle->in_event_queue), Statechart_but_B3);
	run_cycle(handle);
}

void statechart_but_raise_b4(Statechart* handle)
{
	statechart_add_event_to_queue(&(handle->in_event_queue), Statechart_but_B4);
	run_cycle(handle);
}






static void statechart_internal_set_balance(Statechart* handle, sc_integer value)
{
	handle->internal.Balance = value;
}
static void statechart_internal_set_choice(Statechart* handle, sc_integer value)
{
	handle->internal.Choice = value;
}


/* implementations of all internal functions */

/* 'default' enter sequence for state Browse */
static void enseq_a_Browse_default(Statechart* handle)
{
	/* 'default' enter sequence for state Browse */
	handle->stateConfVector[0] = Statechart_a_Browse;
}

/* 'default' enter sequence for state ProductExpeled */
static void enseq_a_ProductExpeled_default(Statechart* handle)
{
	/* 'default' enter sequence for state ProductExpeled */
	handle->stateConfVector[0] = Statechart_a_ProductExpeled;
}

/* 'default' enter sequence for state Insert */
static void enseq_a_Insert_default(Statechart* handle)
{
	/* 'default' enter sequence for state Insert */
	handle->stateConfVector[0] = Statechart_a_Insert;
}

/* 'default' enter sequence for state Error */
static void enseq_a_Error_default(Statechart* handle)
{
	/* 'default' enter sequence for state Error */
	handle->stateConfVector[0] = Statechart_a_Error;
}

/* 'default' enter sequence for state ChangeExpeled */
static void enseq_a_ChangeExpeled_default(Statechart* handle)
{
	/* 'default' enter sequence for state ChangeExpeled */
	handle->stateConfVector[0] = Statechart_a_ChangeExpeled;
}

/* 'default' enter sequence for region a */
static void enseq_a_default(Statechart* handle)
{
	/* 'default' enter sequence for region a */
	react_a__entry_Default(handle);
}

/* Default exit sequence for state Browse */
static void exseq_a_Browse(Statechart* handle)
{
	/* Default exit sequence for state Browse */
	handle->stateConfVector[0] = Statechart_last_state;
}

/* Default exit sequence for state ProductExpeled */
static void exseq_a_ProductExpeled(Statechart* handle)
{
	/* Default exit sequence for state ProductExpeled */
	handle->stateConfVector[0] = Statechart_last_state;
}

/* Default exit sequence for state Insert */
static void exseq_a_Insert(Statechart* handle)
{
	/* Default exit sequence for state Insert */
	handle->stateConfVector[0] = Statechart_last_state;
}

/* Default exit sequence for state Error */
static void exseq_a_Error(Statechart* handle)
{
	/* Default exit sequence for state Error */
	handle->stateConfVector[0] = Statechart_last_state;
}

/* Default exit sequence for state ChangeExpeled */
static void exseq_a_ChangeExpeled(Statechart* handle)
{
	/* Default exit sequence for state ChangeExpeled */
	handle->stateConfVector[0] = Statechart_last_state;
}

/* Default exit sequence for region a */
static void exseq_a(Statechart* handle)
{
	/* Default exit sequence for region a */
	/* Handle exit of all possible states (of Statechart.a) at position 0... */
	switch(handle->stateConfVector[ 0 ])
	{
		case Statechart_a_Browse :
		{
			exseq_a_Browse(handle);
			break;
		}
		case Statechart_a_ProductExpeled :
		{
			exseq_a_ProductExpeled(handle);
			break;
		}
		case Statechart_a_Insert :
		{
			exseq_a_Insert(handle);
			break;
		}
		case Statechart_a_Error :
		{
			exseq_a_Error(handle);
			break;
		}
		case Statechart_a_ChangeExpeled :
		{
			exseq_a_ChangeExpeled(handle);
			break;
		}
		default: 
			/* do nothing */
			break;
	}
}

/* Default react sequence for initial entry  */
static void react_a__entry_Default(Statechart* handle)
{
	/* Default react sequence for initial entry  */
	statechart_internal_set_choice(handle, 0);
	statechart_internal_set_balance(handle, 0);
	statechart_changeLed(handle,handle->internal.Choice);
	enseq_a_Insert_default(handle);
}


static sc_integer react(Statechart* handle, const sc_integer transitioned_before)
{
	/* State machine reactions. */
	SC_UNUSED(handle);
	return transitioned_before;
}

static sc_integer a_Browse_react(Statechart* handle, const sc_integer transitioned_before)
{
	/* The reactions of state Browse. */
 			sc_integer transitioned_after = transitioned_before;
	if ((transitioned_after) < (0))
	{ 
		if (handle->ifaceBut.B1_raised == bool_true)
		{ 
			exseq_a_Browse(handle);
			statechart_internal_set_balance(handle, handle->internal.Balance + 1);
			enseq_a_Insert_default(handle);
			react(handle,0);
			transitioned_after = 0;
		}  else
		{
			if (handle->ifaceBut.B2_raised == bool_true)
			{ 
				exseq_a_Browse(handle);
				statechart_internal_set_balance(handle, handle->internal.Balance + 2);
				enseq_a_Insert_default(handle);
				react(handle,0);
				transitioned_after = 0;
			}  else
			{
				if (((handle->ifaceBut.B4_raised) == bool_true) && (((handle->internal.Choice) == (0)) == bool_true))
				{ 
					exseq_a_Browse(handle);
					statechart_internal_set_balance(handle, 0);
					enseq_a_ChangeExpeled_default(handle);
					react(handle,0);
					transitioned_after = 0;
				}  else
				{
					if (handle->ifaceBut.B3_raised == bool_true)
					{ 
						exseq_a_Browse(handle);
						statechart_internal_set_choice(handle, (((handle->internal.Choice + 1)) % 4));
						statechart_changeLed(handle,handle->internal.Choice);
						enseq_a_Browse_default(handle);
						react(handle,0);
						transitioned_after = 0;
					}  else
					{
						if (((handle->ifaceBut.B4_raised) == bool_true) && ((((handle->internal.Choice) != (0)) && ((handle->internal.Balance) >= (handle->internal.Choice))) == bool_true))
						{ 
							exseq_a_Browse(handle);
							statechart_internal_set_balance(handle, handle->internal.Balance - handle->internal.Choice);
							enseq_a_ProductExpeled_default(handle);
							react(handle,0);
							transitioned_after = 0;
						}  else
						{
							if (((handle->ifaceBut.B4_raised) == bool_true) && ((((handle->internal.Choice) != (0)) && ((handle->internal.Balance) < (handle->internal.Choice))) == bool_true))
							{ 
								exseq_a_Browse(handle);
								enseq_a_Error_default(handle);
								react(handle,0);
								transitioned_after = 0;
							} 
						}
					}
				}
			}
		}
	} 
	/* If no transition was taken */
	if ((transitioned_after) == (transitioned_before))
	{ 
		/* then execute local reactions. */
		transitioned_after = react(handle,transitioned_before);
	} 
	return transitioned_after;
}

static sc_integer a_ProductExpeled_react(Statechart* handle, const sc_integer transitioned_before)
{
	/* The reactions of state ProductExpeled. */
 			sc_integer transitioned_after = transitioned_before;
	if ((transitioned_after) < (0))
	{ 
		if (((handle->ifaceBut.B4_raised) == bool_true) && (((handle->internal.Balance) > (0)) == bool_true))
		{ 
			exseq_a_ProductExpeled(handle);
			statechart_internal_set_choice(handle, 0);
			enseq_a_Browse_default(handle);
			react(handle,0);
			transitioned_after = 0;
		}  else
		{
			if (((handle->ifaceBut.B4_raised) == bool_true) && (((handle->internal.Balance) == (0)) == bool_true))
			{ 
				exseq_a_ProductExpeled(handle);
				statechart_internal_set_choice(handle, 0);
				enseq_a_Insert_default(handle);
				react(handle,0);
				transitioned_after = 0;
			} 
		}
	} 
	/* If no transition was taken */
	if ((transitioned_after) == (transitioned_before))
	{ 
		/* then execute local reactions. */
		transitioned_after = react(handle,transitioned_before);
	} 
	return transitioned_after;
}

static sc_integer a_Insert_react(Statechart* handle, const sc_integer transitioned_before)
{
	/* The reactions of state Insert. */
 			sc_integer transitioned_after = transitioned_before;
	if ((transitioned_after) < (0))
	{ 
		if (handle->ifaceBut.B3_raised == bool_true)
		{ 
			exseq_a_Insert(handle);
			enseq_a_Browse_default(handle);
			react(handle,0);
			transitioned_after = 0;
		}  else
		{
			if (handle->ifaceBut.B1_raised == bool_true)
			{ 
				exseq_a_Insert(handle);
				statechart_internal_set_balance(handle, handle->internal.Balance + 1);
				enseq_a_Insert_default(handle);
				react(handle,0);
				transitioned_after = 0;
			}  else
			{
				if (handle->ifaceBut.B2_raised == bool_true)
				{ 
					exseq_a_Insert(handle);
					statechart_internal_set_balance(handle, handle->internal.Balance + 2);
					enseq_a_Insert_default(handle);
					react(handle,0);
					transitioned_after = 0;
				} 
			}
		}
	} 
	/* If no transition was taken */
	if ((transitioned_after) == (transitioned_before))
	{ 
		/* then execute local reactions. */
		transitioned_after = react(handle,transitioned_before);
	} 
	return transitioned_after;
}

static sc_integer a_Error_react(Statechart* handle, const sc_integer transitioned_before)
{
	/* The reactions of state Error. */
 			sc_integer transitioned_after = transitioned_before;
	if ((transitioned_after) < (0))
	{ 
		if (handle->ifaceBut.B4_raised == bool_true)
		{ 
			exseq_a_Error(handle);
			enseq_a_Browse_default(handle);
			react(handle,0);
			transitioned_after = 0;
		} 
	} 
	/* If no transition was taken */
	if ((transitioned_after) == (transitioned_before))
	{ 
		/* then execute local reactions. */
		transitioned_after = react(handle,transitioned_before);
	} 
	return transitioned_after;
}

static sc_integer a_ChangeExpeled_react(Statechart* handle, const sc_integer transitioned_before)
{
	/* The reactions of state ChangeExpeled. */
 			sc_integer transitioned_after = transitioned_before;
	if ((transitioned_after) < (0))
	{ 
		if (handle->ifaceBut.B4_raised == bool_true)
		{ 
			exseq_a_ChangeExpeled(handle);
			statechart_internal_set_choice(handle, 0);
			enseq_a_Insert_default(handle);
			react(handle,0);
			transitioned_after = 0;
		} 
	} 
	/* If no transition was taken */
	if ((transitioned_after) == (transitioned_before))
	{ 
		/* then execute local reactions. */
		transitioned_after = react(handle,transitioned_before);
	} 
	return transitioned_after;
}




static void statechart_eventqueue_init(statechart_eventqueue * eq, statechart_event *buffer, sc_integer capacity)
{
	eq->events = buffer;
	eq->capacity = capacity;
	eq->push_index = 0;
	eq->pop_index = 0;
	eq->size = 0;
}

static sc_integer statechart_eventqueue_size(statechart_eventqueue * eq)
{
	return eq->size;
}

static statechart_event statechart_eventqueue_pop(statechart_eventqueue * eq)
{
	statechart_event event;
	if(statechart_eventqueue_size(eq) <= 0) {
		statechart_event_init(&event, Statechart_invalid_event);
	}
	else {
		event = eq->events[eq->pop_index];
		
		if(eq->pop_index < eq->capacity - 1) {
			eq->pop_index++;
		} 
		else {
			eq->pop_index = 0;
		}
		eq->size--;
	}
	return event;
}
static sc_boolean statechart_eventqueue_push(statechart_eventqueue * eq, statechart_event ev)
{
	if(statechart_eventqueue_size(eq) == eq->capacity) {
		return bool_false;
	}
	else {
		eq->events[eq->push_index] = ev;
		
		if(eq->push_index < eq->capacity - 1) {
			eq->push_index++;
		}
		else {
			eq->push_index = 0;
		}
		eq->size++;
		
		return bool_true;
	}
}
static void statechart_event_init(statechart_event * ev, StatechartEventID name)
{
	ev->name = name;
}

static void statechart_add_event_to_queue(statechart_eventqueue * eq, StatechartEventID name)
{
	statechart_event event;
	statechart_event_init(&event, name);
	statechart_eventqueue_push(eq, event);
}

static sc_boolean statechart_dispatch_event(Statechart* handle, const statechart_event * event) {
	switch(event->name) {
		case Statechart_but_B1:
		{
			handle->ifaceBut.B1_raised = bool_true;
			return bool_true;
		}
		case Statechart_but_B2:
		{
			handle->ifaceBut.B2_raised = bool_true;
			return bool_true;
		}
		case Statechart_but_B3:
		{
			handle->ifaceBut.B3_raised = bool_true;
			return bool_true;
		}
		case Statechart_but_B4:
		{
			handle->ifaceBut.B4_raised = bool_true;
			return bool_true;
		}
		default:
			return bool_false;
	}
}

static statechart_event statechart_get_next_event(Statechart* handle)
{
	statechart_event next_event;
	statechart_event_init(&next_event, Statechart_invalid_event);
	if(statechart_eventqueue_size(&(handle->in_event_queue)) > 0) {
		next_event = statechart_eventqueue_pop(&(handle->in_event_queue));
	}
	return next_event;
}

static sc_boolean statechart_dispatch_next_event(Statechart* handle)
{
	statechart_event nextEvent;
	nextEvent = statechart_get_next_event(handle);
	return statechart_dispatch_event(handle, &nextEvent);
}