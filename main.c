#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>


#define WIDTH 	800
#define HEIGHT 	600
#define TITLE 	"TITLE"

/* Prototypes des  structures (si necessaire) */


/* Prototypes des fonctions */
void 	sdl_print_error(char *msg);
void 	Destroy_Alls(SDL_Window *window, SDL_Renderer *renderer);


/* Prototypes des Fonctions qui seront appellées dans le main */
/* Fonction qui initialise les données*/
void 	Load_Game(); 
// fonction qui met a jour les données
void 	Update_Game(); 
// fonction qui affiche a l'écran
void 	Draw_Game(SDL_Renderer *renderer); 

/* Variables goblales */


int 	main(int argc, char *argv[])
{
	/* Initialisation de la sdl */
	if (0 != SDL_Init(SDL_INIT_VIDEO))
	{
		sdl_print_error("Initialisation de la SDL");
	}

	/* Création des renderer et window */
	SDL_Window 		*window   = NULL;
	SDL_Renderer 	*renderer = NULL;

	/* Initialisation de la window */
	window 	= SDL_CreateWindow("GAME OF LIFE ( M.A.Souaré )", 
								SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
								WIDTH, HEIGHT, 0);
	
	/* Gestion de l'erreur si l'alloc échoue */
	if (!window)
	{
		sdl_print_error("Initialisation de la window");
		SDL_Quit();
	}

	/* Initialisation du renderer */
	renderer = SDL_CreateRenderer(window, -1, 0);
	
	/* Gestion de l'erreur si l'alloc échoue */
	if (!renderer)
	{
		sdl_print_error("Initialisation du renderer");
		SDL_DestroyWindow(window);
	}

	/* ************************************************** */
	SDL_Event	event;
	SDL_bool 	game_loop = SDL_TRUE;

	Load_Game();

	while (game_loop)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				game_loop = SDL_FALSE;
			}

			if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
				case SDLK_q:
					game_loop = SDL_FALSE;
					break;
				default:
					break;
				}
			}
		}
		
		
		Update_Game();
		Draw_Game(renderer);

		SDL_Delay(delay);
	}

	return (EXIT_SUCCESS);
}

/* Cette fonction permet d'afficher une erreur */
void 	sdl_print_error(char *msg){
	fprintf(stderr, "ERROR : %s => %s.\n", msg, SDL_GetError());
}

/* Cette fonction detruit et libère les window et renderer */
void 	Destroy_Alls(SDL_Window *window, SDL_Renderer *renderer){
	if (renderer)
		SDL_DestroyRenderer(renderer);
	
	if (window){
		SDL_DestroyWindow(window);
	}

	
	fprintf(stdout, "Liberatioin sdl\n");
	SDL_Quit();
}


/* Implémentation des fonctions qui seront appellées dans le main 
 * Load_Game() 		=> Initialisation du jeu (appellée une seule fois);
 * Update_Game() 	=> Mise à jour des données du jeu ;
 * Draw_Game() 		=> Affichage à l'écran ;
*/
void	Load_Game()
{
}


void	Update_Game()
{

}

void	Draw_Game(SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	/* *************************************************************************** */
	
	/* *************************************************************************** */
	SDL_RenderPresent(renderer);
}

/* ************************************************************** */