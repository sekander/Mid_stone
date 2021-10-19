#pragma once

#define SCREEN_WIDTH 1366
#define SCREEN_HEIGHT 768 

#define SPLASH_STATE_SHOW_TIME 3.0

#define SPLASH_SCENE_BACKGROUND_FILEPATH "Resources/res/nintendo-switch-minimal.jpg"


//#define MAIN_MENU_BACKGROUND_FILEPATH "Resources/res/arcade_menu.jpg"
#define MAIN_MENU_BACKGROUND_FILEPATH "Resources/res/main_menu.png"


#define GAME_BACKGROUND_FILEPATH "Resources/res/blue_background.jpg"
#define GAME_OVER_BACKGROUND_FILEPATH "Resources/res/game_over_background.jpg"

//#define GAME_TITLE_FILEPATH "Resources/res/game_title.png"
//#define GAME_TITLE_FILEPATH "Resources/res/title.png"
#define GAME_TITLE_FILEPATH "Resources/res/alexi.png"

//#define PLAY_BUTTON_FILEPATH "Resources/res/PlayButton.png"
#define PLAY_BUTTON_FILEPATH "Resources/res/play_bt.png"

#define PIPE_UP_FILEPATH 		"Resources/res/PipeUp.png"
#define PIPE_DOWN_FILEPATH	"Resources/res/PipeDown.png"
#define PIPE_SCORING_FILEPATH	"Resources/res/InvisibleScoringPipe.png"
#define HIGH_SCORE_FILEPATH "Resources/HighScore.txt"

#define LAND_FILEPATH "Resources/res/land.png"

#define PIPE_MOVEMENT_SPPED 200.0f
#define PIPE_SPAWN_FREQUENCY 3.0f;

#define BIRD_FRAME_1_FIILEPATH "Resources/res/bird-01.png"
#define BIRD_FRAME_2_FIILEPATH "Resources/res/bird-02.png"
#define BIRD_FRAME_3_FIILEPATH "Resources/res/bird-03.png"
#define BIRD_FRAME_4_FIILEPATH "Resources/res/bird-04.png"


#define PLAYER_FILEPATH "Resources/res/sprite_sheet.png"
#define MAGIK_FILEPATH "Resources/res/magik8.png"


#define FONT_FILEPATH "Resources/fonts/FlappyFont.ttf"

#define GAME_OVER_TITLE_FILEPATH  "Resources/res/Game-Over-Title.png"

#define GAME_OVER_BODY_FILEPATH  	"Resources/res/Game-Over-Body.png"


#define HIT_SOUND_FILEPATH "Resources/audio/Hit.wav"
#define POINT_SOUND_FILEPATH "Resources/audio/Point.wav"
#define WING_SOUND_FILEPATH "Resources/audio/Wing.wav"

#define BIRD_ANIMATION_DURATION 0.5f

#define BIRD_STATE_STILL 1
#define BIRD_STATE_FALLING 2
#define BIRD_STATE_FLYING 3

#define GRAVITY						350.0f
#define FLYING_SPEED			350.0f
#define FLYING_DURATION		0.25f

#define SPRITE_WIDTH 32
#define SPRITE_HEIGHT 32
#define DIRECTION_Y_DOWN_INITAL     0
#define DIRETION_Y_LEFT_INITAL      1
#define DIRECTION_Y_RIGHT_INITAL    2
#define DIRECTION_Y_UP_INITAL       3

#define DIRECTION_X_DOWN_INITAL     0
#define DIRECTION_X_LEFT_INITAL     0
#define DIRECTION_X_RIGHT_INITAL    0
#define DIRECTION_X_UP_INITAL       0

#define X_FRAMES_1 0
#define X_FRAMES_2 1
#define X_FRAMES_3 2



#define DEGTORAD 0.0174532925199432957f
#define RADTODEG 57.295779513082320876f


enum Game_States
{
	e_Ready,
	e_Playing,
	e_GameOver
};

#define FLASH_SPEED	1500.0f

#define TIME_BEFORE_GAME_OVER_APPEARS 1.5f
