#pragma once
/* 
*	This file is used so that important constants that will be changed 
*	often during testing can be put all in the same place
*/

#define PLAYER_OVERALL_SCALE 3.0f


#define ENEMY_SPAWN_DELAY 750
#define SPAWN_ACCELERATION 10
#define MIN_SPAWN_DELAY 500


#define FIRE_DELAY 150
#define BULLET_SPEED 4
#define BULLET_DAMAGE 1
#define BULLET_SCALE .0075f * PLAYER_OVERALL_SCALE
#define GUN_SCALE .03f * PLAYER_OVERALL_SCALE


#define ENEMY_SPEED .25f
#define ENEMY_DAMAGE 1
#define ENEMY_HEALTH_MAX 5
#define ENEMY_HEALTH_MIN 2
#define ENEMY_SCALE .2f


#define PLAYER_SPEED 1
#define PLAYER_HEALTH 1000
#define PLAYER_SCALE .05f * PLAYER_OVERALL_SCALE
#define SCORE_MULTIPLIER 100