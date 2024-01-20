#include <SDL3/SDL.h>
//#include <SDL3/SDL2_gfxPrimitives.h>
//#include <SDL3/SDL2_gfxPrimitives_font.h>
#include <SDL3/SDL2_gfxPrimitives.c>
#include <SDL3/SDL2_rotozoom.c>
#include <SDL3/SDL2_framerate.c>

int main( int argc, char* argv[] )
{
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Init( SDL_INIT_VIDEO );

	window = SDL_CreateWindow(
		"sequencer",
		640,
		480,
		0
	);

	if( !window )
	{
		SDL_Log( "Whoops! Window ain't happening: %s", SDL_GetError() );
		SDL_Quit();
		return 1;
	}

	renderer = SDL_CreateRenderer( window, NULL, SDL_RENDERER_ACCELERATED );
	if( !renderer )
	{
		SDL_Log( "Bummer, no renderer: %s", SDL_GetError() );
		SDL_DestroyWindow( window );
		SDL_Quit();
		return 1;
	}

	SDL_bool running = SDL_TRUE;
	while( running )
	{
		SDL_Event event;
		while( SDL_PollEvent( &event ) )
		{
			if( event.type == SDL_EVENT_QUIT )
			{
				running = SDL_FALSE;
			}
		}

		//SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255 );
		//SDL_RenderClear( renderer );

		stringRGBA(renderer,16, 16, "HELLO",0xffu,0xffu,0xffu,0xffu);

		//thickLineRGBA(renderer,0,0,200,100,4,255,255,255,255);
		//characterRGBA(renderer,32,32,'A',255,255,255,255);

		SDL_RenderPresent( renderer );
	}

	SDL_DestroyRenderer( renderer );
	SDL_DestroyWindow( window );
	SDL_Quit();
	return 0;
}
