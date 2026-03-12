#include <stdio.h>
#include <SDL3/SDL.h>
#include "inputs.h"
#include <stdbool.h>
void handleInput(struct Game *game) {
	SDL_Event event;
    game->event = &event;
	while (SDL_PollEvent(game->event)) {
		switch (game->event->type) {
		case SDL_EVENT_QUIT:
			game->running = 0;
			break;
		case SDL_EVENT_KEY_DOWN:
			switch (game->event->key.key) {
			case SDLK_ESCAPE:
				game->running = 0;
				break;
			case SDLK_F11:
				SDL_WindowFlags flags = SDL_GetWindowFlags(game->gameWindow);
				if (flags & SDL_WINDOW_FULLSCREEN){
					SDL_SetWindowFullscreen(game->gameWindow, false);
				}
				else{
					SDL_SetWindowFullscreen(game->gameWindow, true);
				}
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}
}
void playerInput(struct Game *game) {
	const bool *state = SDL_GetKeyboardState(NULL);
	/*player->dx = 0.0f;
	player->dy = 0.0f;
	if (state[SDL_SCANCODE_UP]) {
		player->dy = -5.0f;
	}
	if (state[SDL_SCANCODE_DOWN]) {
		player->dy = 5.0f;
	}*/
}


