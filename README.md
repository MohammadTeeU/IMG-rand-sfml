# Random Image using c++/sfml

## idea of works
The 8-bit is data of one color, it  will generate range of colors from 0 to 255 for basics colors [red, green and blue].
So, first will identity size of image [it like matrix] :

    sf::Uint8 pix[x*y*4]; //linear array ordring 

we multiply by 4 because three RGB and A [alpha or opacity].

set random value in this array:

    for(int i=0;i<x*y*4;i++){ pix[i]=rng(rand); }

then load array in image :

    sf::Image img;
    img.create(x,y,pix);

then set image on texture to display it on screen

    sf::Texture tex;
    tex.loadFromImage(img);

    while(win.isOpen())
    {
    win.clear();
    win.draw(tex);
    win.display();
    }
    

## build

for linux :
 1. `$ sudo apt-get install libsfml-dev`
 2. go to `app/src/main/jni/`
 3.  `$ g++ -c main.cpp`
 4. `$ g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system`
 5. `$ ./sfml-app`

for android:

 1. first should have:
     	 - android SDK [https://developer.android.com/studio]
    	 - android NDK [https://developer.android.com/ndk]
    	 - gradle [https://gradle.org/]
 2. build SFML for android [https://github.com/SFML/SFML/wiki/Tutorial%3A-Building-SFML-for-Android]
 3. go to root of project will see `local.properties` file open it in text editor, and change paths of SDK and NDK
 4. open CLI and type `gradle build` 
 5. plug your android phone using USB.
 6. also on root folder of project open CLI and type `gradle installDebug`
 7. you will see app install on your phone



 ## works app
 <img width=200 src="https://github.com/MohammadTeeU/IMG-rand-sfml/blob/master/screenshoot/1.png"/>
<hr>
 <img width=200 src="https://github.com/MohammadTeeU/IMG-rand-sfml/blob/master/screenshoot/2.png"/>
<hr>

