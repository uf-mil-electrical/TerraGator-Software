#ifndef RELAY_H_
#define RELAY_H_

#include <stdbool.h>

bool relayEnabled;


/*
@brief initializes the GPIO pin that connects to the relay's control NMOS
*/
void relay_init();

/*
@brief call to get state of relay 
@returns relayEnabled indicating relay state
*/
bool get_relay_state();

/*
@brief sets the control relay HIGH
*/
void enable_relay();

/*
@brief sets the control relay LOW
*/
void kill_relay();

#endif