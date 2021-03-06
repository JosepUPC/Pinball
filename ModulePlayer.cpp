#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "ModuleFonts.h"
#include "ModuleInput.h"
#include "ModuleRender.h"

ModulePlayer::ModulePlayer(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{

	font_score = App->fonts->Load("pinball/score_font.png", "1234567890", 1);

	LOG("Loading player");
	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	return true;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	if (App->input->GetKey(SDL_SCANCODE_H) == KEY_REPEAT) {
		sprintf_s(highscore_text, 9, "%d", highscore);
		App->fonts->Blit(200, 12, 0, highscore_text);
	}
	else {
		sprintf_s(score_text, 9, "%d", score);
		App->fonts->Blit(200, 12, 0, score_text);
	}

	sprintf_s(lifes_text, 2, "%d", lifes);
	App->fonts->Blit(400, 12, 0, lifes_text);

	return UPDATE_CONTINUE;
}



