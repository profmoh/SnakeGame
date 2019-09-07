//#include <iostream>
//#include <string>
//#include <SDL.h>
//#include <SDL_image.h>
//#include "respath.h"
//#include "cleanup.h"
//
//using namespace std;
//
//const int SCREEN_WIDTH = 640;
//const int SCREEN_HEIGHT = 480;
//
//const int TILE_SIZE = 40;
//
///**
// * Log an SDL error with some error message to the output stream of our choice
// * @param os The output stream to write the message to
// * @param msg The error message to write, format will be msg error: SDL_GetError()
// */
//void logSDLError(std::ostream &os, const std::string &msg) {
//	os << msg << " error: " << SDL_GetError() << std::endl;
//}
//
///**
// * Loads an image into a texture on the rendering device
// * @param file The image file to load
// * @param ren The renderer to load the texture onto
// * @return the loaded texture, or nullptr if something went wrong.
// */
//SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren) {
//	SDL_Texture *texture = IMG_LoadTexture(ren, file.c_str());
//
//	if (texture == nullptr) {
//		logSDLError(std::cout, "LoadTexture");
//	}
//
//	return texture;
//}
//
///**
// * Draw an SDL_Texture to an SDL_Renderer at position x, y, with some desired
// * width and height
// * @param tex The source texture we want to draw
// * @param ren The renderer we want to draw to
// * @param x The x coordinate to draw to
// * @param y The y coordinate to draw to
// * @param w The width of the texture to draw
// * @param h The height of the texture to draw
// */
//void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w,
//		int h) {
//	//Setup the destination rectangle to be at the position we want
//	SDL_Rect dst;
//
//	dst.x = x;
//	dst.y = y;
//	dst.w = w;
//	dst.h = h;
//
//	SDL_RenderCopy(ren, tex, NULL, &dst);
//}
//
///**
// * Draw an SDL_Texture to an SDL_Renderer at position x, y, preserving
// * the texture's width and height
// * @param tex The source texture we want to draw
// * @param ren The renderer we want to draw to
// * @param x The x coordinate to draw to
// * @param y The y coordinate to draw to
// */
//void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y) {
//	int w, h;
//
//	SDL_QueryTexture(tex, NULL, NULL, &w, &h);
//
//	renderTexture(tex, ren, x, y, w, h);
//}
//
//int main(int argc, char* argv[]) {
//
//	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
//		logSDLError(std::cout, "SDL_Init");
//
//		return 1;
//	}
//
//	SDL_Window *window = SDL_CreateWindow("Snake Game", 100, 100, SCREEN_WIDTH,
//			SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
//
//	if (window == nullptr) {
//		logSDLError(std::cout, "CreateWindow");
//		SDL_Quit();
//		return 1;
//	}
//
//	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,
//			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
//
//	if (renderer == nullptr) {
//		logSDLError(std::cout, "CreateRenderer");
////		cleanup(window);
//		SDL_DestroyWindow(window);
//		SDL_Quit();
//		return 1;
//	}
//
//	const std::string resPath = getResourcePath("images");
//	SDL_Texture *background = loadTexture(resPath + "background.jpg", renderer);
//	SDL_Texture *image = loadTexture(resPath + "image.bmp", renderer);
//
//	if (background == nullptr || image == nullptr) {
//		cleanup(background, image, renderer, window);
//
//		SDL_Quit();
//
//		return 1;
//	}
//
//	SDL_RenderClear(renderer);
//
//	int bW, bH;
//
//	SDL_QueryTexture(background, NULL, NULL, &bW, &bH);
//
//	renderTexture(background, renderer, 0, 0);
//	renderTexture(background, renderer, bW, 0);
//	renderTexture(background, renderer, 0, bH);
//	renderTexture(background, renderer, bW, bH);
//
////	int iW, iH;
////
////	SDL_QueryTexture(image, NULL, NULL, &iW, &iH);
////
////	int x = SCREEN_WIDTH / 2 - iW / 2;
////	int y = SCREEN_HEIGHT / 2 - iH / 2;
////
////	renderTexture(image, renderer, x, y);
//
//	SDL_RenderPresent(renderer);
//	SDL_Delay(1000);
//
//	cleanup(background, image, renderer, window);
//	SDL_Quit();
//
//	return 0;
//}
