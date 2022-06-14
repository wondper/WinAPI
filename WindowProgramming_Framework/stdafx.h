// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#pragma comment (lib, "msimg32.lib")


//C++
#include<string>
#include<random>
#include<ctime>

//Sound
#include<fmod.h>
using namespace std;

//Game
#define stage 3 // 스테이지 개수 입니다
#define MAX_m 10 // 최대 몬스터 생성 갯수입니다.

#define STAGE_ONE_ZOMBIE 3 // 최대 몬스터 생성 갯수입니다.

#define STAGE_TWO_ZOMBIE 3
#define STAGE_TWO_BEE 3

#define STAGE_THREE_ZOMBIE 6
#define STAGE_THREE_BEE 6

#define CAKE 0
#define MEGAZINE 1
#define SCOPE 2
#define ZOMBIE 3
#define BEE 4
#define BOSS 5

#define STAGE_TEST_ZOMBIE 3
#define STAGE_TEST_BEE 3
#define STAGE_TEST_BOSS 1

#define STAGE_FIXED_OBJECT_KIND 3
#define STAGE_ONE_ADDITIONAL_OBJECT_KIND 1
#define STAGE_TWO_ADDITIONAL_OBJECT_KIND 2
#define STAGE_THREE_ADDITIONAL_OBJECT_KIND 3

#define CAKE_COUNT 3
#define MEGAZINE_COUNT 3
#define SCOPE_COUNT 2

#define BITMAP_SPRITE_COUNT 6
#define MAX_OBJECT_KIND 6


#define OBJECT_CREATE 0
#define MONSTER_ATTACK 1
#define MONSTER_HIT 2
#define MONSTER_DEATH 3

#define OBJECT_NOT_DRAW 8
#define OBJECT_DELETE 9
#define MONSTER_NONE 10

#define SOUND_NUM 10