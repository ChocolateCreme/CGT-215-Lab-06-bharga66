// CGT-215-Lab-06-bharga66.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
int main() {
	// i chose to stick with the winter and yoda images
	string background = "images1/backgrounds/winter.png";
	string foreground = "images1/characters/yoda.png";
	Texture backgroundTex;
	if (!backgroundTex.loadFromFile(background)) {
		cout << "Couldn't Load Image" << endl;
		exit(1);
	}
	Texture foregroundTex;
	if (!foregroundTex.loadFromFile(foreground)) {
		cout << "Couldn't Load Image" << endl;
		exit(1);
	}
	Image backgroundImage;
	backgroundImage = backgroundTex.copyToImage();
	Image foregroundImage;
	foregroundImage = foregroundTex.copyToImage();
	Vector2u sz = backgroundImage.getSize();
	for (int y = 0; y < sz.y; y++) {
		for (int x = 0; x < sz.x; x++) {

			Color winterI = backgroundImage.getPixel(x, y);
			Color yodaI = foregroundImage.getPixel(x, y);
			// if the green value is greater than the red and blue values
			// then the code will replace the pixel with the winter image pixel
			if (yodaI.g > yodaI.r && yodaI.g > yodaI.b) {
				backgroundImage.setPixel(x, y, winterI);
			}

			else {
				backgroundImage.setPixel(x, y, yodaI);
			}
		}
	}

	backgroundTex.loadFromImage(backgroundImage);

	// a few small changes i made to display the edited image correctly
	RenderWindow window(VideoMode(1024, 768), "Here's the output");

	Sprite sprite1;
	sprite1.setTexture(backgroundTex);

	window.clear();
	window.draw(sprite1);
	window.display();
	while (true);
}