#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2Point.h"

class ModulePlayer : public Module
{
public:
	ModulePlayer(Application* app, bool start_enabled = true);
	virtual ~ModulePlayer();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	int font_score = -1;
	char score_text[10];
	char lifes_text[10];
	char highscore_text[10];
	int scorex2 = 1;


	uint highscore = 0;
	uint score = 0;
	uint lifes = 4;
};