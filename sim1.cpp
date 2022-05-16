#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>
using namespace std;
using namespace sf; 

// DOnt worry about this class

class make_game{
    private:



    public:
        make_game(){
            
        }

};


// Class that builds a start menu and renders
// in future can implement with a class which renders everything
// "menu" will become a class to provide what to render

class menu{
    public:
        // initialise how big the window will be
        int window_width = 1000;
        int window_height = 600;
        Font font; 
       
       // Default constrauctor, does everything basically
        menu(){
            
            RenderWindow window(VideoMode(window_width,window_height),"Simulator Menu",Style::Default);

            if (!font.loadFromFile("C:\\Users\\jacob\\Downloads\\open-sans\\OpenSans-Regular.ttf")){
                cout << "unable to access font" << endl; 
            }

             // Drawing "Start:"
            Text text1;
            text1.setFont(font);
            text1.setString("Start:");
            text1.setCharacterSize(40);
            text1.setFillColor(Color::White);
            text1.setPosition(window_width/2,200);
            
            // Drawing "Help:"
            Text text2;
            text2.setFont(font);
            text2.setString("Help:");
            text2.setCharacterSize(40);
            text2.setFillColor(Color::White);
            text2.setPosition(window_width/2,300);

            // Drawing "Exit"
            Text text3;
            text3.setFont(font);
            text3.setString("Exit");
            text3.setCharacterSize(40);
            text3.setFillColor(Color::White);
            text3.setPosition(window_width/2,400);


            // Essentially the game loop
            while (window.isOpen()){

                //Checking events

                Event event;
                while (window.pollEvent(event)){

                    if (event.type == Event::Closed){
                        window.close(); 
                        break; 
                    }
                }

                // render the text in the window
                window.clear();
            
                window.draw(text1);
                window.draw(text2);
                window.draw(text3);

                window.display(); 

            }

        }

};


// main creates a menu
int main(){

    menu _menu;
    _menu = menu(); 

    return 0; 
}