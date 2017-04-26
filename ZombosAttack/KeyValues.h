#pragma once
/* 
*	This file is used so that important constants that will be changed 
*	often during testing can be put all in the same place
*/

#define PLAYER_OVERALL_SCALE 3.0f

// in milliseconds
#define ENEMY_SPAWN_DELAY 250
#define SPAWN_ACCELERATION 5
#define MIN_SPAWN_DELAY 100

// in milliseconds
#define FIRE_DELAY 2 

#define BULLET_SPEED 6
#define BULLET_DAMAGE 1
#define BULLET_SCALE .0075f * PLAYER_OVERALL_SCALE
#define GUN_SCALE .05f * PLAYER_OVERALL_SCALE

// in milliseconds
#define ENEMY_DAMAGE_DELAY 2000
#define ENEMY_SPEED .1f
#define ENEMY_DAMAGE 1
#define ENEMY_HEALTH_MAX 1
#define ENEMY_HEALTH_MIN 2
#define ENEMY_SCALE .07f


#define PLAYER_SPEED .6f
#define PLAYER_HEALTH 5
#define PLAYER_SCALE .05f * PLAYER_OVERALL_SCALE