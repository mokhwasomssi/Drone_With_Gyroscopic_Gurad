/**
 * @file   rc.h
 * @brief  change rc transmitter channel data to quadcopter command
 * @author mokhwasomssi
 * @date   2021-08-31
 */


#ifndef __RC_H__
#define __RC_H__


#include "ibus.h"


typedef struct 
{
    bool arming;

    int16_t roll;
    int16_t pitch;
    int16_t yaw;
    uint16_t trottle;
} rc_command_t;


void rc_init(int8_t max_angle, int8_t min_angle);
bool rc_update(rc_command_t* rc_command);
bool is_rc_lost();


#endif /* __RC_H__ */