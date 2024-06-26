/** Generated by itemis CREATE code generator. */

#ifndef STATECHART_REQUIRED_H_
#define STATECHART_REQUIRED_H_

#include "../src/sc_types.h"
#include "Statechart.h"

#ifdef __cplusplus
extern "C"
{
#endif 

/*! \file
This header defines prototypes for all functions that are required by the state machine implementation.

This state machine makes use of operations declared in the state machines interface or internal scopes. Thus the function prototypes:
- statechart_changeLed
- statechart_showState
are defined.

These functions will be called during a 'run to completion step' (runCycle) of the statechart. 
There are some constraints that have to be considered for the implementation of these functions:
- never call the statechart API functions from within these functions.
- make sure that the execution time is as short as possible.

*/

extern void statechart_changeLed( Statechart* handle, const sc_integer id);
extern void statechart_showState( Statechart* handle, const sc_integer state);





#ifdef __cplusplus
}
#endif 

#endif /* STATECHART_REQUIRED_H_ */
