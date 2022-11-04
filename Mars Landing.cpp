#include <SFML/Graphics.hpp>
#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<sstream>
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <SFML/Audio.hpp>
using namespace std;
using namespace sf;
double y = 0;
double y2 = 230 ;
double y3 = 200;
bool done= false;
int cnt =0 ;
int speed_h ;
int speed_v =-40;
int fuel =400;
int power_user =0;
int rotate_user =0;
bool donee =false;
bool pointIsOnLine(int m, int c, int x, int y)
{
    // If (x, y) satisfies the equation of the line
    if (y == ((m * x) + c))
        return true;

    return false;
}

void read_test()
{
    int x, y,rotatee,power ;
    speed_h = 0;
    //speed_v =-500 + ( std::rand() % ( 500+500 + 1 ) );// generate random value to speed_v ..
    power =  0 + ( std::rand() % ( 4 - 0 + 1 ) );
    rotatee = -90 + ( std::rand() % ( 90 +90+ 1 ) );

}
int xsp, yp;
void read_input()
{

    //open file  and read
    // put ans in all Cycles ..
    fstream file ;
    file.open("intput.txt", ios::in);
    if(file.is_open()) {
        string line ;

        while(getline(file,line)) {
            power_user =line[0];
            rotate_user=line[2];

        }
    }
    file.close();



}
bool  checkinput (int power_user, int rotate_user )
{
    if (speed_v <= -40 && power_user ==4 &&rotate_user == 0 ) {
        return true;

    } else if (speed_v > -40 && power_user== 0 &&rotate_user == 0) {
        return true;
    }
    return false;
}
int xs =500;
int xss =610;
int xsss =580;
int main()
{
    read_test();
    read_input();
    // Create the main window
    // 994 1000 fire
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML window");
    // rocket
    sf::Texture rocket;
    rocket.loadFromFile("C:\\Users\\Lenovo\\Desktop\\scripts\\challange\\rockect1.png");
    sf::Sprite rockett;
    rockett.setTexture(rocket);
    rockett.setPosition(500,y);
    // fire //130 , 0  ,,,, 0 ,0
    sf::Texture fire;
    sf::Texture fire2;
    fire.loadFromFile("C:\\Users\\Lenovo\\Desktop\\scripts\\challange\\fire5.jpg");
    fire2.loadFromFile("C:\\Users\\Lenovo\\Desktop\\scripts\\challange\\fire5.jpg");
    sf::Sprite firee ;
    sf::Sprite firee2;
    firee.setTexture(fire);

    firee2.setTexture(fire2);
    firee2.setTextureRect(sf::IntRect(130,0,100, 140));
    firee.setTextureRect(sf::IntRect(0,0,100, 140));
    firee.setPosition(610,230);
    firee2.setPosition(610,230);
    firee.setRotation(firee.getRotation() + 180);
    firee2.setRotation(firee2.getRotation() + 180);

    sf::Texture fire3 ;
    fire3.loadFromFile("C:\\Users\\Lenovo\\Desktop\\scripts\\challange\\fire5.jpg");
    sf::Sprite firee3;
    firee3.setTexture(fire3);
    firee3.setTextureRect(sf::IntRect(40,200,120, 160));
    firee3.setPosition(580,200);

    firee3.setRotation(firee3.getRotation() + 180);
    //////////////////////////////////////////////////



    ///////////////////////////////////////////

    // Load a sprite to display
    sf::Texture texture;
    sf::Sprite sprite(texture);

    // draw landing of mars
    /// drawing landing ////
    sf::Vertex line1[] = {
        sf::Vertex(sf::Vector2f(0,600 )),

        sf::Vertex(sf::Vector2f( 150, 400))
    };

    sf::Vertex line2[] = {
        sf::Vertex(sf::Vector2f(150, 400)),
        sf::Vertex(sf::Vector2f(400, 900))
    };
    sf::Vertex line3[] = {
        sf::Vertex(sf::Vector2f(400, 900)),

        sf::Vertex(sf::Vector2f( 700, 900))
    };

    sf::Vertex line4[] = {
        sf::Vertex(sf::Vector2f(700, 900)),
        sf::Vertex(sf::Vector2f(850, 300))
    };

    sf::Vertex line5[] = {
        sf::Vertex(sf::Vector2f(850, 300)),
        sf::Vertex(sf::Vector2f(900, 500))
    };

    sf::Vertex line6[] = {
        sf::Vertex(sf::Vector2f(900,500)),
        sf::Vertex(sf::Vector2f(1000, 500))
    };


    line1[0].color = sf::Color::Red;
    line1[1].color =sf::Color::Red;
    line2[0].color = sf::Color::Red;
    line2[1].color =sf::Color::Red;
    line3[0].color = sf::Color::Red;
    line3[1].color =sf::Color::Red;
    line4[0].color = sf::Color::Red;
    line4[1].color =sf::Color::Red;

    line5[0].color = sf::Color::Red;
    line5[1].color =sf::Color::Red;
    line6[0].color = sf::Color::Red;
    line6[1].color =sf::Color::Red;
    /////////////////////////////////////////////

    /////////////// draw counters/////////////////////
    // ostring
    std::ostringstream sstimer;
    std::ostringstream sspeed_v;
    std::ostringstream sspeed_h;
    std::ostringstream ssfuel;
    std::ostringstream ssposition_x;
    std::ostringstream ssposition_y;
    int mins =0;
    int hours= 0;
    int second =0;

    int pos_x = 0;
    int pos_y =0 ;
    // printing


    /// texture and font
    sf::Font font ;
    font.loadFromFile("C:\\Users\\Lenovo\\Desktop\\scripts\\myfirstproject\\arial.ttf");
    /// timer ///
    sf::Text timer ;
    timer.setCharacterSize(20);
    timer.setPosition(50,50);
    timer.setFont(font);
    timer.setString(sstimer.str());
    /// speed v and h
    sf::Text speed_hh ;
    speed_hh.setCharacterSize(20);
    speed_hh.setPosition(750,90);
    speed_hh.setFont(font);

    sf::Text speed_vv ;
    speed_vv.setCharacterSize(20);
    speed_vv.setPosition(750,130);
    speed_vv.setFont(font);

    /// position x && position y
    sf::Text pos_xx ;
    pos_xx.setCharacterSize(20);
    pos_xx.setPosition(50,90);
    pos_xx.setFont(font);


    sf::Text pos_yy ;
    pos_yy.setCharacterSize(20);
    pos_yy.setPosition(50,130);
    pos_yy.setFont(font);

    /// fuel
    sf::Text fuell ;
    fuell.setCharacterSize(20);
    fuell.setPosition(750,50);
    fuell.setFont(font);
    /////////////////////////////////////////////////////////
    // final part
    sf::Texture fail;
    fail.loadFromFile("C:\\Users\\Lenovo\\Desktop\\scripts\\challange\\png.png");
    sf::Sprite faill;
    faill.setTexture(fail);
    faill.setPosition(440,800);
    faill.setTextureRect(sf::IntRect(0,0,200, 200));

    sf::Texture fail2;
    fail2.loadFromFile("C:\\Users\\Lenovo\\Desktop\\scripts\\challange\\png.png");
    sf::Sprite faill2;
    faill2.setTexture(fail2);
    faill2.setPosition(430,800);
    faill2.setTextureRect(sf::IntRect(150,0,200, 200));

    sf::Texture fail3;
    fail3.loadFromFile("C:\\Users\\Lenovo\\Desktop\\scripts\\challange\\png.png");
    sf::Sprite faill3;
    faill3.setTexture(fail3);
    faill3.setPosition(430,800);
    faill3.setTextureRect(sf::IntRect(360,0,200, 200));

    sf::Texture fail4;
    fail4.loadFromFile("C:\\Users\\Lenovo\\Desktop\\scripts\\challange\\png.png");
    sf::Sprite faill4;
    faill4.setTexture(fail4);
    faill4.setPosition(430,800);
    faill4.setTextureRect(sf::IntRect(570,0,200, 200));









    ////////////////////////////////////////////////////////////


    // Start the game loop
    while (window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::KeyPressed ) {
                if(event.key.code == sf::Keyboard::Left && done ==false) {
                    xs+=5*-1;
                    xss+=5*-1;
                    xsss+=5*-1;
                    rockett.setPosition(xs,y);
                    firee.setPosition(xss,y2);
                    firee2.setPosition(xss,y2);
                    firee3.setPosition(xsss,y3);
                } else if(event.key.code == sf::Keyboard::Right && done ==false) {

                    xs+=5;
                    xss+=5;
                    xsss+=5;
                    rockett.setPosition(xs, y);
                    firee.setPosition(xss,y2);
                    firee2.setPosition(xss,y2);
                    firee3.setPosition(xsss,y3);
                }



            }


        }

        ////// update timer //////
        if(second == 150 && done==false) {
            second =0 ;
            if(!done)
                fuel--;
            mins++;

        } else if(done ==false) {
            second++;
        }
        if(mins == 59 && done ==false) {
            hours++;
            speed_v--;

            mins=0;
        }
        sstimer.str("");
        string ss = to_string(hours);
        string mm = to_string(mins);
        if(mm.size()== 0) {
            mm+="00";
        } else if(mm.size()==1) {
            mm ="0"+mm;
        }
        if(ss.size()==0) {
            ss+="00";
        } else if(ss.size()== 1) {
            ss= "0"+ss;

        }
        sstimer<< "TIME    "<<ss << ":"<< mm  ;
        timer.setString(sstimer.str());
        //////////////////////////////

        /////update postion/////
        ssposition_x.str("");
        ssposition_y.str("");
        if(done==false) {
            pos_y =rockett.getPosition().y;
            pos_x =rockett.getPosition().x;
        }

        ssposition_y<< "POSTION Y     "<<pos_y ;
        ssposition_x <<"POSTION X     "<<pos_x;
        pos_xx.setString(ssposition_x.str());
        pos_yy.setString(ssposition_y.str());

        ///////////////////////////


        // update fuel & speed ////
        sspeed_h.str(" ");
        ssfuel.str(" ");
        sspeed_v.str(" ");

        sspeed_v<< "VERTICAL SPEED  "<<speed_v ;
        sspeed_h<< "HORZATIAL SPEED   "<<speed_h;
        string ff = to_string(fuel);
        string zeros ;
        for(int i= ff.size(); i<=4; i++) {
            zeros+='0';


        }
        ssfuel << "FUEL  "<< zeros <<fuel ;
        fuell.setString(ssfuel.str());
        speed_vv.setString(sspeed_v.str());
        speed_hh.setString(sspeed_h.str());



        /////   ///

        window.clear();

        // Draw the landing on window
        window.draw(line1, 2, sf::Lines);
        window.draw(line2, 2, sf::Lines);
        window.draw(line3, 2, sf::Lines);
        window.draw(line4,2, sf::Lines);
        window.draw(line5, 2, sf::Lines);
        window.draw(line6,2, sf::Lines);
        ///////////////////////////////
        ////////Draw counter////
        window.draw(timer);
        window.draw(pos_xx);
        window.draw(pos_yy);
        window.draw(speed_hh);
        window.draw(speed_vv);
        window.draw(fuell);
        ////////////////////////
        /// draw rocket///


        rockett.setPosition(xs, y);
        firee.setPosition(xss,y2);
        firee2.setPosition(xss,y2);
        firee3.setPosition(xss,y3);


        if(cnt%3== 1 && done ==false)
            window.draw(firee2);
        else if(cnt%3 == 0 && done ==false) window.draw(firee);
        else if(done ==false) {
            window.draw(firee3);
        }



        /////////////////


        if(((xs >= 400&& xs <= 700 )&& ((long long)y==800 )) || ((xs >=850&&xs<=1000) &&((long long)y ==400) ) ) {

            xss =0;
            xsss=0;
            y2=0;
            y3=0;
            done =true;


        } else if(((xs >= 0 && xs<=100)&& (y<=600 && y >=300)) ) {
          // cout <<"2";
            xsp=xs;
            yp=y;
            xss =0;
            xsss=0;
            y2=0;
            y3=0;


        } else if((xs >=150 && xs <=230) && (y>=400 && y<=900)) {
            xsp=xs;
            yp=y;

            xss =0;
            xsss=0;
            y2=0;
            y3=0;


        } else if((xs>= 700 && xs <=850) && (y>=300 && y <=900)) {
            //cout<<xs<< " "<< y<<'\n';
            xsp=xs;
            yp=y;
            xss =0;
            xsss=0;
            y2=0;
            y3=0;



        } else if(xs >=800&& xs <=850 && y>=320&& y<=500) {
            //cout << "4";
            xsp=xs;
            yp=y;
            xss =0;
            xsss=0;
            y2=0;
            y3=0;



        } else if(done==false){

            y+=.1;
            y2+=.1;
            y3+=.1;
        }

          if(!((long long)xsp == (long long)xs &&(long long)yp ==(long long)y))
         window.draw(rockett);
        // cout << xsp << " "<< yp <<'\n';
        if((long long)xsp == (long long)xs &&(long long)yp ==(long long)y) {
               // cout << 44 ;
             done =true;
            faill.setPosition(xsp, yp);
            faill2.setPosition(xsp, yp);
            faill3.setPosition(xsp, yp);
            faill4.setPosition(xsp, yp);

            if(cnt%4 == 0)
               window.draw(faill);
            else if(cnt%4 == 1)
                window.draw(faill2);
            else if(cnt %4 ==2)
                window.draw(faill3);
            else if(cnt %4 == 3)
                window.draw(faill4);
        }

        cnt++;

        // Update the window
        window.display();
    }


}
