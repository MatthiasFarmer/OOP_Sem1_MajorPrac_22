#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

int main(){

    RenderWindow window(VideoMode(1000,600),"Simulator Menu",Style::Default);
    Font font;
    font.loadFromFile("C:\\Users\\jacob\\Downloads\\open-sans\\OpenSans-Regular\\"); 

    // main loop

    while (window.isOpen()){

        //Checking events

            Event event;
            while (window.pollEvent(event)){

                if (event.type == Event::Closed){
                    window.close(); 
                }
            }

        // render
        window.clear();

        if (!font.loadFromFile("C:\\Users\\jacob\\Downloads\\open-sans\\OpenSans-Regular\\")){
                cout << "unable to access font" << endl; 
            }
            // Drawing "Start"
            Text text1;
            text1.setFont(font);
            text1.setString("Start:");
            text1.setCharacterSize(12);
            text1.setFillColor(Color::Red);
            text1.setPosition(500,300);
            
            // Drawing "Start"
            Text text2;
            text2.setFont(font);
            text2.setString("Help:");
            text2.setCharacterSize(12);
            text2.setFillColor(Color::Red);
            text2.setPosition(500,200);

            window.draw(text1);

            window.draw(text2);

            window.display(); 

        }



    return 0; 
}