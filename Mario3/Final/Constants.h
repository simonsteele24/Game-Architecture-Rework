#pragma once
#include "Vector2.h"

// Game Performance-related constant variables
const double MAX_TIME_BETWEEN_FRAMES = 16.7;
const int FRAMES_PER_SECOND_DIVISOR = 1000;
const int DEFAULT_SCALING_VALUE = 1;

// Asset-related constant variables
const string TEXT_FILE_PATH = "..\\..\\Mario3\\final\\ModFile.txt";
const string UI_TEXT_FILE_PATH = "..\\..\\Mario3\\final\\ModUIFile.txt";
const string LEVEL_TEXT_FILE_PATH = "..\\..\\Mario3\\final\\Level_";
const string SAVE_STATE_TEXT_FILE_PATH = "..\\..\\Mario3\\final\\SaveState.txt";
const string GAME_TEXT_FILE_PATH = "..\\..\\Mario3\\final\\ModGameFiles.txt";
const string ENGLISH_TEXT_FILE_PATH = "..\\..\\Mario3\\final\\English.txt";
const string PIRATE_TEXT_FILE_PATH = "..\\..\\Mario3\\final\\Pirate.txt";
const string VULCAN_TEXT_FILE_PATH = "..\\..\\Mario3\\final\\Vulcan.txt";
const string ASSET_PATH_TWO = "..\\..\\Mario3\\Assets\\";


//UI
const string NAME_OF_GAME_OVER_WORD = "GAMEOVER";
const string NAME_OF_ESCAPE_TO_END_WORD = "ESCAPETOEND";
const string NAME_OF_SCORE_WORD = "SCORE";
const string NAME_OF_COINS_WORD = "COINS";
const string NAME_OF_LIVES_WORD = "LIVES";
const string NAME_LEVEL_COMPLETION_WORD = "LEVELCOMPLETION";
const string NAME_OF_GAME = "NAMEOFGAME";
const string NAME_OF_START = "NAMEOFSTART";
const string NAME_OF_LOAD_GAME_WORD = "LOADGAME";
const string NAME_OF_SETTINGS_WORD = "SETTINGS";
const string NAME_OF_QUIT_WORD = "QUIT";
const string NAME_OF_SOUND_WORD = "SOUND";
const string NAME_OF_LANGUAGE_WORD = "LANGUAGE";
const string NAME_OF_BACK_WORD = "BACK";
const string NAME_OF_EASY_WORD = "EASY";
const string NAME_OF_MEDIUM_WORD = "MEDIUM";
const string NAME_OF_HARD_WORD = "HARD";
const string NAME_OF_ON_WORD = "ON";
const string NAME_OF_OFF_WORD = "OFF";
const string NAME_OF_ENGLISH_WORD = "ENGLISH";
const string NAME_OF_PIRATE_WORD = "PIRATE";
const string NAME_OF_VULCAN_WORD = "VULCAN";
const string NAME_OF_SCORE_TEXT = "Score Label";
const string NAME_OF_SCORE_AMOUNT_TEXT = "Score Amount";
const string NAME_OF_COIN_TEXT = "Coin Text";
const string NAME_OF_LIVES_TEXT = "Lives Text";
const string NAME_OF_GAME_STATUS_TEXT = "Status Text";
const string NAME_OF_BACKGROUND_BUFFER = "Background";
const string NAME_OF_BACKGROUND_TEAR_BUFFER = "Tear Background";
const string NAME_OF_BACKGROUND_END_BUFFER = "End Background";


//Audio
const string THEME_FILE_PATH = "..\\..\\Mario3\\Assets\\Audio\\maintheme.flac";
const string CASTLE_THEME_FILE_PATH = "..\\..\\Mario3\\Assets\\Audio\\castletheme.flac";
const string AUDIO_JUMP_FILE_PATH = "..\\..\\Mario3\\Assets\\Audio\\jump.wav";
const string AUDIO_COIN_FILE_PATH = "..\\..\\Mario3\\Assets\\Audio\\coin.wav";
const string AUDIO_POWERUP_FILE_PATH = "..\\..\\Mario3\\Assets\\Audio\\powerup.wav";
const string AUDIO_STOMP_FILE_PATH = "..\\..\\Mario3\\Assets\\Audio\\stomp.wav";
const string AUDIO_KICK_FILE_PATH = "..\\..\\Mario3\\Assets\\Audio\\kick.wav";
const string AUDIO_LOST_LIFE_FILE_PATH = "..\\..\\Mario3\\Assets\\Audio\\lostlife.wav";

const string NAME_OF_THEME = "Theme";
const string NAME_OF_SECONDARY_THEME = "Themes";
const string NAME_OF_CASTLE_THEME = "CastleTheme";
const string NAME_OF_AUDIO_JUMP = "Jump";
const string NAME_OF_AUDIO_COIN = "Coin";
const string NAME_OF_AUDIO_POWERUP = "Powerup";
const string NAME_OF_AUDIO_STOMP = "Stomp";
const string NAME_OF_AUDIO_KICK = "Kick";
const string NAME_OF_AUDIO_LOST_LIFE = "LostLife";

//Player 
const string NAME_OF_PLAYER = "Player";
const string NAME_OF_PLAYER_JUMP = "Player_Jump";
const string NAME_OF_PLAYER_RED = "Player_Red";
const string NAME_OF_PLAYER_RED_JUMP = "Player Red";
const string NAME_OF_PLAYER_GREEN = "Player_Green";
const string NAME_OF_PLAYER_GREEN_JUMP = "Player_Green_Jump";
const string NAME_OF_PLAYER_DEATH_ANIMATION = "Player_Death";
const string NAME_OF_SUPER_PLAYER = "Super_Player";
const string NAME_OF_SUPER_PLAYER_JUMP = "Super_Player_Jump";
const string NAME_OF_SUPER_PLAYER_RED = "Super_Player_Red";
const string NAME_OF_SUPER_PLAYER_RED_JUMP = "Super_Player_Red_Jump";
const string NAME_OF_SUPER_PLAYER_GREEN = "Super_Player_Red";
const string NAME_OF_SUPER_PLAYER_GREEN_JUMP = "Super_Player_Green_Jump";


//Environmental 
const string NAME_OF_BIG_HILL = "Big_Hill";
const string NAME_OF_CLOUD = "Cloud";
const string NAME_OF_PIPE = "Pipe";
const string NAME_OF_HORIZONTAL_PIPE = "Horizontal_Pipe";
const string NAME_OF_WOOD_BLOCK = "Wood_Block";
const string NAME_OF_DEFAULT_BLOCK = "Default_Block";
const string NAME_OF_BRICK_BLOCK = "Brick_Block";
const string NAME_OF_QUESTION_BLOCK = "Question_Block";
const string NAME_OF_EMPTY_QUESTION_BLOCK = "Empty_Question_Block";
const string NAME_OF_END_BLOCK = "End_Block";
const string NAME_OF_TALL_BLUE_BOX_ANIMATION = "Tall_Blue_Box";
const string NAME_OF_LARGE_GREEN_BOX_ANIMATION = "Large_Green_Box";
const string NAME_OF_MEDIUM_RED_BOX_ANIMATION = "Medium_Red_Box";
const string NAME_OF_LONG_GREEN_BOX_ANIMATION = "Long_Green_Box";
const string NAME_OF_LARGE_WHITE_BOX_ANIMATION = "Large_White_Box";
const string NAME_OF_LARGE_RED_BOX_ANIMATION = "Large_Red_Box";
const string NAME_OF_LARGE_BLUE_BOX_ANIMATION = "Large_Blue_Box";
const string NAME_OF_TALL_GREEN_BOX_ANIMATION = "Tall_Green_Box";
const string NAME_OF_SMALL_ORANGE_BOX_ANIMATION = "Small_Orange_Box";
const string NAME_OF_BLUE_FLOATING_BOX_ANIMATION = "Blue_Floating_Box";
const string NAME_OF_GREEN_FLOATING_BOX_ANIMATION = "Green_Floating_Box";
const string NAME_OF_LARGE_RED_FLOATING_BOX_ANIMATION = "Large_Red_Floating_Box";
const string NAME_OF_SMALL_RED_FLOATING_BOX_ANIMATION = "Small_Red_Floating_Box";
const string NAME_OF_BUSH_ANIMATION = "Bush";
const string NAME_OF_LAVA_ANIMATION = "Lava";
const string NAME_OF_FIREBALL_UP_ANIMATION = "Fireball_Up";
const string NAME_OF_FIREBALL_DOWN_ANIMATION = "Fireball_Down";
const string NAME_OF_DONUT_BUSH_ANIMATION = "Donut_Bush";
const string NAME_OF_DONUT_HILL_ONE = "Donut_Hill_One";
const string NAME_OF_DONUT_HILL_TWO = "Donut_Hill_Two";
const string NAME_OF_DEEP_GRASS_ANIMATION = "Deep_Grass";
const string NAME_OF_GRASS_ANIMATION = "Grass";
const string NAME_OF_SLOPE_LEFT_CORNER = "Grass_Left_Corner";
const string NAME_OF_SLOPE_RIGHT_CORNER = "Grass_Right_Corner";
const string NAME_OF_SLOPE_LEFT = "Grass_Left";
const string NAME_OF_SLOPE_RIGHT = "Grass_Right";
const string NAME_OF_SLOPE_TOP = "Grass_Top";
const string NAME_OF_PLATFORM_LEFT = "Platform_Left";
const string NAME_OF_PLATFORM_MIDDLE = "Platform_Middle";
const string NAME_OF_PLATFORM_RIGHT = "Platform_Right";
const string NAME_OF_LARGE_PLATFORM = "Large_Platform";
const string NAME_OF_POLE = "Pole";
const string NAME_OF_CASTLE_BLOCK = "Castle_Block";
const string NAME_OF_MENU_TEXT = "Menu";

//Enemies
const string NAME_OF_GOOMBA = "Goomba";
const string NAME_OF_KOOPA = "Koopa";
const string NAME_OF_KOOPA_RIGHT_ANIMATION = "Koopa_Right";
const string NAME_OF_KOOPA_SHELL_SPIN_ANIMATION = "Koopa_Spin";
const string NAME_OF_KOOPA_SHELL_ANIMATION = "Koopa_Stationary";
const string NAME_OF_DRY_BONES_LEFT_ANIMATION = "Dry_Bones_Left";
const string NAME_OF_DRY_BONES_RIGHT_ANIMATION = "Dry_Bones_Right";
const string NAME_OF_DRY_BONES_DOWN_ANIMATION = "Dry_Bones_Down";
const string NAME_OF_PIRANHA = "Piranha";
const string NAME_OF_THWOMP_ANIMATION = "Thwomp";
const string NAME_OF_BOOMBOOM_ANIMATION = "BoomBoom";
const string NAME_OF_BOOMBOOM_SQUISHED_ANIMATION = "BoomBoom_Squished";
const string NAME_OF_BOOMBOOM_DEFENSE_ANIMATION = "BoomBoom_Defense";
const string NAME_OF_BOOMBOOM_JUMP_ANIMATION = "BoomBoom_Jump";


//Collectables
const string NAME_OF_COIN = "Coin";
const string NAME_OF_SUPER_MUSHROOM = "Super_Mushroom";
const string NAME_OF_STARMEN = "Starmen";

// Text
const string GAME_OVER_TEXT = "Game Over";
const string ESCAPE_TO_END_TEXT = "Esape To End";
const string MENU_TEXT_PROMPT_ONE = " 1          ";
const string MENU_TEXT_PROMPT_TWO = " 2          ";
const string MENU_TEXT_PROMPT_THREE = " 3          ";
const string MENU_TEXT_PROMPT_FOUR = " 4          ";

//Level and Other
const int BLOCKS_PER_FLOOR = 160;
const double LENGTH_OF_LEVEL = 5000.0;
const int DEFAULT_DIFFICULTY = 1;
const int MAX_LEVELS = 5;
const int BLOCK_SPACING = 32;
const double THWOMP_UPWARD_SPEED = 3.0f;
const int DRYBONES_COOLDOWN_TIME = 500;
const double FIREBALL_FORCE = -10.0f;
const int MAX_COINS_FOR_LIVES = 100;
const int EASY_VALUE = 1;
const int MEDIUM_VALUE = 2;
const int HARD_VALUE = 3;
const int DEFAULT_LIVES = 4;
const int THEME_PITCH = 10;
const int THEME_VOLUME = 10;
const int FADE_AWAY_TIME = 20;
const float MAX_JUMP_MULTIPLIER = -1.5f;
const int MAX_COLOR_INDEX_OF_STAR = 2;
const int POWERUP_TIMER_MULTIPLIER = 2;
const int INVINCIBILITY_COUNTER_MAX = 10;
const int STARTING_TIME_LIMIT_FOR_INVINCIBILITY = 100;
const float KOOPA_SEPERATION_VALUE = -25.0f;
const float PLAYER_JUMP_OFFSET = 5.0f;
const float PLAYER_SPAWN_OFFSET = 10.0F;
const int HEADER_ONE_FONT_SIZE = 20;
const int HEADER_TWO_FONT_SIZE = 30;
const int HEADER_THREE_FONT_SIZE = 40;
const int CAMERA_OFFSET = 300;
const int CHARACTER_SIZE = 20;
const int PLAYER_DIMENSIONS_OFFSET = 32;
const float TEXT_COLOR_DEFAULT = 255.0f;
const Vector2 SCORE_TEXT_POSITION = Vector2(60, 0);
const Vector2 SCORE_AMOUNT_POSITION = Vector2(200, 0);
const Vector2 COIN_TEXT_POSITION = Vector2(400, 0);
const Vector2 LIVES_TEXT_POSITION = Vector2(650, 0);
const Vector2 GAME_STATUS_TEXT_POSITION = Vector2(400, 300);
const Vector2 ESCAPE_TO_END_TEXT_POSITION = Vector2(300, 320);
const Vector2 GAME_OVER_TEXT_POSITION = Vector2(300, 300);
const Vector2 TITLE_TEXT_POSITION = Vector2(100, 100);
const Vector2 MENU_TEXT_ONE_POSITION = Vector2(250, 200);
const Vector2 MENU_TEXT_TWO_POSITION = Vector2(250, 300);
const Vector2 MENU_TEXT_THREE_POSITION = Vector2(250, 400);
const Vector2 MENU_TEXT_FOUR_POSITION = Vector2(250, 500);