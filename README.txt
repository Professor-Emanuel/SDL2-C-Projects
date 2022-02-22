Using Visual Studio Community 2019!

How to download and setup SDL on WINDOWS:	

Setting up the libraries, includes and linking has to be done for each new project:
https://www.youtube.com/watch?v=QQzAHcojEKg&list=PLhfAbcv9cehhkG7ZQK0nfIGJC_C-wSLrx&ab_channel=Let%27sMakeGames
						
https://www.libsdl.org/download-2.0.php

1. 2D_GameEngine - just render a white rectangle

2. 2D_GameEngine - Textures - adds on the previous project, adding a player that moves from left corner to the right corner.

The project requires libpng16-16.dll, zlib1.dll and SDL2_image.dll, which can be found here in SDL2_image-2.0.1, and SDL2_image-2.0.1 needs to be linked as we did with SDL2 in the first 2 projects:
https://www.dropbox.com/s/9jwm4mrxji7fvl2/Dev.zip?dl=0&file_subpath=%2FDev

How to link:
https://www.youtube.com/watch?v=YrWQsuDT3NE&list=PLhfAbcv9cehhkG7ZQK0nfIGJC_C-wSLrx&index=4&ab_channel=Let%27sMakeGames

3. 2D_GameEngine - Frame Rate - adds on the previous project, computing frame rates which will make the game act the same on any device

4. 2D_GameEngine - Texture Loader - adds on the previous project, we created a class function to take care of the texture rendering

5. 2D_GameEngine - GameObject - adds on the previous project, when we create a player, we don't want code all over in the main, so we can create a new object to take care of player movement, and update & render parts
NOT WORKING yet, no code errors, but player is not rendered anymore after encapsulation everything in the GameObject class.

6. 2D_GameEngine - 







Additional sources:

http://lazyfoo.net/SDL_tutorials/index.php

