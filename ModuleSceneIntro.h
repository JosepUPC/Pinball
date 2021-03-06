#pragma once
#include "Module.h"
#include "p2List.h"
#include "p2Point.h"
#include "Globals.h"
#include "p2DynArray.h"

class PhysBody;

enum lightnum {
	Ll = 0, Ul, Vl, Il, Tl,
	Pp, Op, Wp, Ep, Rp, Dp, Up, Np, Kp,
	Ww, Iw, Nw,
	LCK,
	TwoP, ThreeP,
	__LAST
};

struct LightBoost {
	bool isLighted;
	PhysBody* sensor;
	iPoint pos;
	SDL_Rect rect;
	SDL_Texture* tex;
};

class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro(Application* app, bool start_enabled = true);
	~ModuleSceneIntro();

	bool Start();
	update_status Update();
	bool CleanUp();
	void OnCollision(PhysBody* bodyA, PhysBody* bodyB);
	void SetSensors();
	void AddBall();

public:
	bool BallisUp;
	bool Dead;
	bool end_game;
	uint ball_count;

	p2List<PhysBody*> isUp;
	p2List<PhysBody*> isDown;

	// Bodies
	p2List<PhysBody*> circles;
	p2List<PhysBody*> boxes;
	p2List<PhysBody*> ricks;
	p2List<PhysBody*> BouncyCircles;
	p2List<PhysBody*> RedRectangles;
	PhysBody* GreyBlocker;
	PhysBody* BBPatch;
	PhysBody* RDTriangle;
	PhysBody* BckgroundCol;
	PhysBody* LShapeL;
	PhysBody* LShapeR;
	PhysBody* TRRed;
	PhysBody* TLRed;
	PhysBody* BouncyDL;
	PhysBody* BouncyDR;
	PhysBody* BckPatch;
	PhysBody* GridRampPatch;

	//Ramps
	PhysBody* TRRamp;
	PhysBody* TRRampE;
	PhysBody* StartingRamp;
	PhysBody* TopRamp;
	PhysBody* GridRamp;

	LightBoost lightboosts[__LAST];

	// Sensors / Triggers
	PhysBody* StartingBall;
	PhysBody* StartingRampSensor;
	PhysBody* TRRampSensor;
	PhysBody* TRRampSensorOut;
	PhysBody* TRRampExit;
	PhysBody* TopRampExit;
	PhysBody* GridRampSensor;
	PhysBody* TopRampSensor;
	PhysBody* GridRampExitL;
	PhysBody* GridRampExitR;
	PhysBody* FailSensor;

	PhysBody* sensor;
	bool sensed;
	bool ball_available;
	// Textures
	SDL_Texture* spring;
	SDL_Texture* left_kicker;
	SDL_Texture* right_kicker;
	SDL_Texture* background;
	SDL_Texture* foreground;
	SDL_Texture* ball;
	SDL_Texture* circle;
	SDL_Texture* box;
	SDL_Texture* rick;
	uint bonus_fx;
	p2Point<int> ray;
	bool ray_on;
	float spring_x = 457.0f, spring_y = 884.0f;
	int ball_force = 0;
	//FX
	uint kicker_fx;
	uint bouncy_fx;
	uint fail_fx;
	// Music is a fx because LoadMus was not working properly (distortion sounds)
	uint music;
	bool music_playing = false;


private:
	// Pivot 0, 0
	int RDTriangle_pts[6] = {
		33, 907,
		33, 839,
		138, 909
	};

	// Pivot 0, 0
	int TopRamp_pts[94] = {
		28, 108,
		46, 89,
		62, 76,
		88, 62,
		103, 59,
		115, 56,
		130, 56,
		146, 55,
		165, 57,
		185, 58,
		201, 61,
		219, 63,
		246, 68,
		267, 71,
		291, 80,
		323, 92,
		345, 103,
		364, 115,
		386, 131,
		401, 146,
		420, 168,
		432, 184,
		439, 211,
		446, 237,
		446, 247,
		446, 262,
		439, 287,
		396, 278,
		407, 247,
		403, 225,
		397, 207,
		391, 190,
		374, 165,
		359, 149,
		340, 137,
		322, 126,
		307, 116,
		281, 110,
		266, 103,
		237, 97,
		218, 96,
		204, 96,
		181, 95,
		157, 92,
		128, 93,
		102, 96,
		88, 105
	};

	// Pivot 0, 0
	int BckPatch_pts[12] = {
		97, 104,
		110, 86,
		128, 72,
		147, 64,
		112, 82,
		97, 103
	};

	// Pivot 0, 0
	int GridRamp_pts[172] = {
		147, 97,
		198, 98,
		193, 111,
		186, 121,
		173, 129,
		160, 133,
		139, 144,
		128, 151,
		127, 233,
		109, 253,
		109, 312,
		103, 326,
		92, 340,
		99, 347,
		107, 361,
		109, 381,
		107, 401,
		101, 415,
		92, 426,
		99, 434,
		105, 447,
		108, 460,
		108, 474,
		105, 489,
		97, 507,
		93, 513,
		104, 521,
		109, 534,
		109, 645,
		105, 654,
		101, 664,
		91, 672,
		77, 685,
		65, 698,
		66, 729,
		51, 735,
		37, 733,
		37, 724,
		37, 711,
		37, 688,
		46, 676,
		56, 666,
		66, 656,
		75, 645,
		78, 632,
		77, 535,
		71, 528,
		65, 540,
		64, 600,
		61, 612,
		52, 619,
		43, 629,
		32, 646,
		32, 786,
		32, 919,
		5, 919,
		5, 644,
		9, 627,
		18, 612,
		31, 602,
		33, 589,
		34, 567,
		34, 534,
		39, 521,
		49, 510,
		42, 496,
		34, 483,
		33, 448,
		48, 426,
		45, 415,
		36, 402,
		32, 365,
		37, 352,
		49, 342,
		43, 328,
		35, 310,
		35, 256,
		13, 233,
		10, 133,
		13, 125,
		23, 122,
		58, 118,
		83, 113,
		109, 110,
		130, 102,
		138, 101
	};

	// Pivot 0, 0
	int TRRamp_pts[160] = {
		287, 325,
		308, 237,
		317, 213,
		333, 198,
		351, 194,
		365, 195,
		381, 201,
		391, 212,
		395, 223,
		397, 240,
		387, 324,
		393, 344,
		402, 353,
		413, 365,
		421, 380,
		424, 396,
		423, 410,
		414, 426,
		406, 435,
		396, 447,
		381, 459,
		378, 467,
		375, 482,
		381, 495,
		391, 500,
		405, 512,
		415, 526,
		419, 537,
		420, 554,
		420, 570,
		413, 585,
		403, 594,
		391, 603,
		381, 613,
		376, 623,
		377, 636,
		384, 648,
		394, 659,
		402, 664,
		411, 675,
		418, 688,
		422, 706,
		423, 726,
		418, 734,
		406, 739,
		392, 734,
		394, 723,
		391, 705,
		389, 693,
		379, 683,
		367, 672,
		356, 660,
		347, 640,
		348, 618,
		355, 601,
		365, 587,
		382, 574,
		391, 564,
		392, 550,
		385, 533,
		369, 519,
		359, 508,
		348, 487,
		347, 469,
		351, 455,
		360, 443,
		370, 431,
		385, 416,
		395, 402,
		393, 385,
		381, 369,
		368, 357,
		361, 337,
		359, 316,
		361, 298,
		361, 277,
		368, 249,
		362, 235,
		354, 237,
		344, 343
	};


	// Pivot 0, 0
	int LoopRampTriggered_pts[24] = {
		191, 176,
		200, 178,
		209, 188,
		209, 289,
		214, 292,
		236, 292,
		239, 285,
		240, 185,
		230, 166,
		219, 155,
		204, 147,
		192, 146
	};

	// Pivot 0, 0
	int LoopRampOut_pts[34] = {
		240, 124,
		239, 197,
		239, 220,
		222, 237,
		193, 244,
		178, 242,
		162, 233,
		151, 222,
		144, 207,
		143, 185,
		149, 168,
		158, 158,
		171, 149,
		179, 146,
		201, 146,
		210, 149,
		210, 126
	};

	// Pivot 0, 0
	int TLRed_pts[34] = {
		108, 406,
		122, 401,
		100, 208,
		90, 127,
		93, 116,
		99, 103,
		85, 108,
		65, 126,
		51, 145,
		42, 167,
		42, 192,
		46, 221,
		50, 244,
		58, 263,
		73, 303,
		83, 335,
		101, 387
	};
	// Pivot 0, 0
	int StartingRamp_pts[50] = {
		330, 93,
		346, 96,
		373, 105,
		390, 115,
		406, 125,
		419, 139,
		428, 148,
		443, 172,
		449, 196,
		452, 223,
		454, 882,
		481, 881,
		482, 183,
		477, 164,
		466, 143,
		453, 124,
		438, 105,
		416, 88,
		391, 77,
		365, 67,
		341, 63,
		326, 62,
		303, 62,
		313, 78,
		323, 85
	};

	// Pivot 0, 0
	int BouncyDL_pts[16] = {
		64, 666,
		71, 659,
		78, 661,
		85, 675,
		119, 773,
		117, 781,
		105, 783,
		64, 755
	};

	// Pivot 0, 0
	int BouncyDR_pts[14] = {
		336, 776,
		340, 784,
		351, 783,
		394, 755,
		393, 665,
		383, 659,
		372, 666
	};

	// Pivot 0, 0
	int TRRed_pts[30] = {
		389, 290,
		378, 255,
		399, 211,
		401, 159,
		392, 138,
		378, 126,
		375, 106,
		380, 93,
		395, 92,
		426, 116,
		433, 128,
		434, 154,
		430, 182,
		420, 217,
		404, 257
	};

	// Pivot 0, 0
	int TRRampE_pts[22] = {
		277, 377,
		273, 370,
		273, 284,
		280, 274,
		299, 275,
		350, 301,
		374, 330,
		348, 406,
		336, 401,
		346, 306,
		298, 281
	};

	// Pivot 0, 0
	int LShapeR_pts[14] = {
		425, 676,
		421, 676,
		420, 770,
		318, 843,
		325, 849,
		419, 785,
		424, 775
	};

	// Pivot 0, 0
	int LShapeL_pts[18] = {
		33, 682,
		36, 681,
		37, 769,
		40, 777,
		47, 781,
		141, 843,
		131, 849,
		41, 788,
		32, 781
	};

	// Pivot 0, 0
	int BckgroundCol_pts[178] = {
		452, 905,
		322, 907,
		450, 822,
		450, 651,
		443, 637,
		433, 630,
		423, 619,
		417, 600,
		426, 582,
		432, 572,
		433, 553,
		425, 520,
		419, 492,
		426, 477,
		430, 467,
		425, 458,
		415, 448,
		407, 434,
		467, 158,
		468, 129,
		456, 98,
		447, 82,
		435, 74,
		416, 63,
		390, 56,
		258, 56,
		238, 63,
		220, 73,
		211, 89,
		208, 107,
		209, 127,
		209, 172,
		240, 169,
		239, 99,
		262, 98,
		269, 101,
		269, 117,
		267, 207,
		246, 248,
		242, 373,
		245, 382,
		255, 400,
		262, 410,
		240, 407,
		219, 399,
		183, 386,
		173, 376,
		163, 313,
		210, 298,
		220, 290,
		236, 285,
		233, 260,
		157, 285,
		137, 197,
		128, 186,
		128, 152,
		139, 144,
		157, 135,
		179, 124,
		194, 114,
		200, 97,
		191, 74,
		175, 67,
		139, 67,
		120, 76,
		140, 59,
		137, 57,
		107, 58,
		76, 69,
		53, 83,
		42, 91,
		25, 112,
		13, 140,
		6, 174,
		5, 211,
		9, 260,
		48, 430,
		52, 450,
		49, 465,
		10, 546,
		11, 556,
		35, 581,
		35, 594,
		28, 604,
		15, 615,
		9, 627,
		7, 642,
		4, 986,
		327, 985
	};


};
