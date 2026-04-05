#ifndef PI5_MSGS_H_
#define PI5_MSGS_H_

typedef struct cmd_vel{
    float vx;
    float vy; // vy should be very close to zero for differential drive robot 
    float wz; 
} cmd_vel_t;

typedef struct pose {
    float x;
    float y; 
    float theta; 
} pose_t; 

#endif 