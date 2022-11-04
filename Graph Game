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
#include "generate.h"
using namespace sf;
using namespace std;
const int N =1e5+5;
vector<vector<int>>All_Cycles(N);
vector<vector<int>>graph(N);
// counting from zeros ..
// make this number rand from loop
int num_nodes = 3;
// read solution from python file
bool ok10=false;
bool ok20=false;
int cnt2 =0;
bool pp=true;
bool p=false;
// check if it visited or not ..
bool vis[N];
void read_solution()
{
    // open file  and read
    // put ans in all Cycles ..
    fstream file ;
    file.open("output.txt", ios::in);
    if(file.is_open()) {
        string line ;

        while(getline(file,line)) {
            for(int i=0; i<line.size(); i++) {
                if(line[i]>='0'&&line[i]<='9') {
                    All_Cycles[cnt2].push_back(line[i]-48);
                }
            }
            cnt2++;

        }
    }
    file.close();

}
int sz = 30;
void send_input ()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);
    vector<pair<int,int>>foo;
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            if(i==j)continue;
            foo.push_back({i, j});
        }
    }
    std::shuffle(std::begin(foo), std::end(foo), e);
    for(int i=0; i<8; i++) {
        graph[foo[i].first].push_back(foo[i].second);
    }

    fstream file ;
    file.open("input.txt", ios :: out);
    if(file.is_open()) {
        //file<<  << endl;
    }
    file.close();
}
// check if map of player is correct ...
map<int,int>mp;
bool check()
{
    int correct =0 ;
    for(int i=1; i<=4; i++) {
        if(mp[i]==1)correct++;
    }

    for(int i=0; i<cnt2; i++) {

        int cnt =0;
        if(vis[i])continue;
        for(int j=0; j<All_Cycles[i].size(); j++) {
            for(int k=1; k<=4; k++) {
                if(mp[k]== 1 && k == All_Cycles[i][j]+1) {
                    cnt++;
                    break;
                }
            }


        }
        if(cnt == correct&& cnt ==All_Cycles[i].size()) {
            vis[i]=true;
            return true;

        }
    }
    return false;

}
struct point {
    int x,  y, raduis;
} a[4];

int main()
{
    send_input();


    // read solution
    read_solution();
    //send_input (); // send to pytho
    // make window
    Texture t1;
    t1.loadFromFile("C:\\Users\\Lenovo\\Desktop\\scripts\\myfirstproject\\alyaa.png");
    Texture t2;
    t2.loadFromFile("C:\\Users\\Lenovo\\Desktop\\scripts\\myfirstproject\\levele.png");
    //620 269
    Sprite s(t1);
    Sprite s2(t2);
    sf::View view;
    s2.setPosition(120,50);

    view.reset(sf::FloatRect(100, 100, 100, 100));


    sf::RenderWindow window(sf::VideoMode(800, 600), "Find_All_Cycles_Graph");

    // draw
    // object system
    sf::Text text;

    sf::Font font ;

    font.loadFromFile("C:\\Users\\Lenovo\\Desktop\\scripts\\myfirstproject\\arial.ttf");
    int score = 0;
    sf::Text Cycles_Found ;
    Cycles_Found.setCharacterSize(20);
    Cycles_Found.setPosition(10,10);
    Cycles_Found.setFont(font);
    sf::Text levels ;
    levels.setCharacterSize(20);
    levels.setPosition(10,60);
    levels.setFont(font);
    std::ostringstream ssScore;
    ssScore << "Cycles_Found : "<<score ;
    std::ostringstream sslevel;
    int level =0;
    sslevel << "Level : "<<level;

    Cycles_Found.setString(ssScore.str());
    levels.setString(sslevel.str());


    sf::CircleShape shape1(40.f);
    sf::CircleShape shape3(40.f);
    sf::CircleShape shape4(40.f);
    sf::CircleShape shape2(40.f);
    sf::RectangleShape line(sf::Vector2f(150.f, 5.f));
    // draw arrow
    bool ok1 =false;
    bool ok2 =false;
    bool ok3=false;
    bool ok4 =false;

    shape1.setFillColor(sf::Color::White);


    shape2.setFillColor(sf::Color::White);


    shape3.setFillColor(sf::Color::White);


    shape4.setFillColor(sf::Color::White);
    sf::Clock clock;

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            // node1
            if(event.type == sf::Event::KeyPressed && ok1==false) {
                if(event.key.code == sf::Keyboard::Num1) {
                    ok1=true;
                    ok20=false;
                }



            } else if(event.type == sf::Event::KeyPressed&& ok1 ==true) {
                if(event.key.code == sf::Keyboard::Num1) {
                    ok1=false;

                }



            }
            // node 2

            if(event.type == sf::Event::KeyPressed && ok2==false) {
                if(event.key.code == sf::Keyboard::Num2) {
                    ok2=true;
                    ok20=false;

                }



            } else if(event.type == sf::Event::KeyPressed&& ok2 ==true) {
                if(event.key.code == sf::Keyboard::Num2) {
                    ok2=false;
                }



            }
            // node 3
            if(event.type == sf::Event::KeyPressed && ok3==false) {
                if(event.key.code == sf::Keyboard::Num3) {
                    ok3=true;
                    ok20=false;
                }



            } else if(event.type == sf::Event::KeyPressed&& ok3 ==true) {
                if(event.key.code == sf::Keyboard::Num3) {
                    ok3=false;
                }



            }
            // node 4
            if(event.type == sf::Event::KeyPressed && ok4==false) {
                if(event.key.code == sf::Keyboard::Num4) {
                    ok20=false;
                    ok4=true;
                }



            }
            // node4
            else if(event.type == sf::Event::KeyPressed&& ok4 ==true) {
                if(event.key.code == sf::Keyboard::Num4) {
                    ok4=false;
                }




            }
            // enter pressed
            if(event.type == sf::Event::KeyPressed) {
                if(event.key.code == sf::Keyboard::Enter) {
                    if(check()) {
                        cout << "test passed\n";
                        ok10=true; // passsed
                        score++;
                        ssScore.str("");
                        ssScore<< "Cycles_Found :"<< score ;
                        Cycles_Found.setString(ssScore.str());


                    } else cout << "answer isn't correct\n";
                    for(int i=1; i<=4; i++) {
                        mp[i]=0;
                    }
                    if(!ok20)
                        ok20=true;//restarted
                    ok1=false;
                    ok2=false;
                    ok3=false;
                    ok4=false;

                }

            }

        }




        window.clear(sf::Color::Black);
        if(ok1) {

            mp[1]=1;
            shape1.setFillColor(sf::Color::Blue);
        } else if(!ok1) {
            mp[1]=0;
            shape1.setFillColor(sf::Color::White);
        }
        if(ok2) {

            mp[2]=1;
            shape2.setFillColor(sf::Color::Blue);
        } else if(!ok2) {
            mp[2]=0;
            shape2.setFillColor(sf::Color::White);
        }
        if(ok3) {

            mp[3]=1;
            shape3.setFillColor(sf::Color::Blue);
        } else if(!ok3) {

            mp[3]=0;
            shape3.setFillColor(sf::Color::White);
        }
        if(ok4) {

            mp[4]=1;
            shape4.setFillColor(sf::Color::Blue);
        } else if(!ok4) {
            mp[4]=0;
            shape4.setFillColor(sf::Color::White);
        }
        if(ok20) {
            shape1.setFillColor(sf::Color::White);
            shape2.setFillColor(sf::Color::White);
            shape3.setFillColor(sf::Color::White);
            shape4.setFillColor(sf::Color::White);

        }


        shape1.setPosition(350,22);
        a[0].x=350;
        a[0].y =22;
        a[0].raduis=shape1.getRadius();
        window.draw(shape1);
        // number of node
        sf::Text text;
        text.setString("one");
        text.setFont(font);
        text.setPosition(a[0].x+10,a[0].y+5);
        text.setCharacterSize(30);
        text.setColor(sf::Color::Red);
        window.draw(text);
        //////
        shape2.setPosition(140,230);
        a[1].x=140;
        a[1].y =230;
        a[1].raduis=shape2.getRadius();
        // Set number of node
        window.draw(shape2);
        text.setString("two");

        text.setFont(font);
        text.setPosition(a[1].x+10,a[1].y+5);
        text.setCharacterSize(30);
        text.setColor(sf::Color::Red);
        window.draw(text);
        ////

        shape3.setPosition(140*4,230);
        a[2].x=140*4;
        a[2].y =230;
        a[2].raduis=shape3.getRadius();
        // Set number of node
        window.draw(shape3);
        text.setString("three");
        text.setFont(font);
        text.setPosition(a[2].x+10,a[2].y+5);
        text.setCharacterSize(30);
        text.setColor(sf::Color::Red);
        window.draw(text);
        ////
        shape4.setPosition(350,500);
        a[3].x=350;
        a[3].y =500;
        a[3].raduis=shape4.getRadius();
        // Set number of node
        window.draw(shape4);
        text.setString("four");

        text.setFont(font);
        text.setPosition(a[3].x+10,a[3].y+5);
        text.setCharacterSize(30);
        text.setColor(sf::Color::Red);
        window.draw(text);
        // number of cycles_found
        window.draw(Cycles_Found);
        window.draw(levels);
        ////

        for(int i=0; i<num_nodes; i++) {
            for(int j=0; j<graph[i].size(); j++) {
                if(i == graph[i][j]) continue;// if edge between node and it's self
                //handling time later...
                sf::Vertex line2[] = {
                    sf::Vertex(sf::Vector2f(a[i].x+a[i].raduis, a[i].y)),

                    sf::Vertex(sf::Vector2f( a[graph[i][j]].x+a[graph[i][j]].raduis, a[graph[i][j]].y))
                };
                window.draw(line2, 2, sf::Lines);
                sf::Vertex arrow[] = {
                    sf::Vertex(sf::Vector2f((a[i].x+a[i].raduis+a[graph[i][j]].x+a[graph[i][j]].raduis)/2, (a[i].y+ a[graph[i][j]].y)/2)),

                    sf::Vertex(sf::Vector2f((a[i].x+a[i].raduis+a[graph[i][j]].x+a[graph[i][j]].raduis)/2.f+20,(a[i].y+ a[graph[i][j]].y)/2.f-10)),
                    // sf::Vertex(sf::Vector2f((a[i].x+a[i].raduis+a[graph[i][j]].x+a[graph[i][j]].raduis)/2-50,(a[i].y+ a[graph[i][j]].y)/2.f -10))
                };
                sf::Vertex arrow2[] = {
                    sf::Vertex(sf::Vector2f((a[i].x+a[i].raduis+a[graph[i][j]].x+a[graph[i][j]].raduis)/2, (a[i].y+ a[graph[i][j]].y)/2)),

                    //sf::Vertex(sf::Vector2f((a[i].x+a[i].raduis+a[graph[i][j]].x+a[graph[i][j]].raduis)/2.f-,(a[i].y+ a[graph[i][j]].y)/2.f-10)),
                    sf::Vertex(sf::Vector2f((a[i].x+a[i].raduis+a[graph[i][j]].x+a[graph[i][j]].raduis)/2-20,(a[i].y+ a[graph[i][j]].y)/2.f -10))
                };
                sf::Vertex arrow3[] = {
                    sf::Vertex(sf::Vector2f((a[i].x+a[i].raduis+a[graph[i][j]].x+a[graph[i][j]].raduis)/2, (a[i].y+ a[graph[i][j]].y)/2)),

                    //sf::Vertex(sf::Vector2f((a[i].x+a[i].raduis+a[graph[i][j]].x+a[graph[i][j]].raduis)/2.f-,(a[i].y+ a[graph[i][j]].y)/2.f-10)),
                    sf::Vertex(sf::Vector2f((a[i].x+a[i].raduis+a[graph[i][j]].x+a[graph[i][j]].raduis)/2+40,(a[i].y+ a[graph[i][j]].y)/2.f +20))
                };
                sf::Vertex arrow4[] = {
                    sf::Vertex(sf::Vector2f((a[i].x+a[i].raduis+a[graph[i][j]].x+a[graph[i][j]].raduis)/2, (a[i].y+ a[graph[i][j]].y)/2)),

                    //sf::Vertex(sf::Vector2f((a[i].x+a[i].raduis+a[graph[i][j]].x+a[graph[i][j]].raduis)/2.f-,(a[i].y+ a[graph[i][j]].y)/2.f-10)),
                    sf::Vertex(sf::Vector2f(((a[i].x+a[i].raduis+a[graph[i][j]].x+a[graph[i][j]].raduis)/2)-40,((a[i].y+ a[graph[i][j]].y)/2.f) +20))
                };
                if(a[graph[i][j]].y > a[i].y) {
                    arrow[0].color = sf::Color::Red;
                    arrow2[0].color = sf::Color::Red;
                    window.draw(arrow, 2, sf::Lines);
                    window.draw(arrow2, 2, sf::Lines);



                }
                if(a[graph[i][j]].y < a[i].y) {
                    arrow3[0].color = sf::Color::Red;
                    arrow4[0].color = sf::Color::Red;
                    window.draw(arrow3, 2, sf::Lines);
                    window.draw(arrow4, 2, sf::Lines);


                }
                if(a[graph[i][j]].y == a[i].y && a[graph[i][j]].x > a[i].x) {
                    sf::Vertex arrow5[] = {
                        sf::Vertex(sf::Vector2f((a[i].x+a[i].raduis+a[graph[i][j]].x+a[graph[i][j]].raduis)/2, (a[i].y+ a[graph[i][j]].y)/2)),

                        //sf::Vertex(sf::Vector2f((a[i].x+a[i].raduis+a[graph[i][j]].x+a[graph[i][j]].raduis)/2.f-,(a[i].y+ a[graph[i][j]].y)/2.f-10)),
                        sf::Vertex(sf::Vector2f((a[i].x+a[i].raduis+a[graph[i][j]].x+a[graph[i][j]].raduis)/2 -20,(a[i].y+ a[graph[i][j]].y)/2.f +20))
                    };
                    sf::Vertex arrow6[] = {
                        sf::Vertex(sf::Vector2f((a[i].x+a[i].raduis+a[graph[i][j]].x+a[graph[i][j]].raduis)/2, (a[i].y+ a[graph[i][j]].y)/2)),

                        //sf::Vertex(sf::Vector2f((a[i].x+a[i].raduis+a[graph[i][j]].x+a[graph[i][j]].raduis)/2.f-,(a[i].y+ a[graph[i][j]].y)/2.f-10)),
                        sf::Vertex(sf::Vector2f((a[i].x+a[i].raduis+a[graph[i][j]].x+a[graph[i][j]].raduis)/2-20,(a[i].y+ a[graph[i][j]].y)/2.f -20))
                    };
                    arrow5[0].color = sf::Color::Red;
                    arrow6[0].color = sf::Color::Red;
                    window.draw(arrow5, 2, sf::Lines);
                    window.draw(arrow6, 2, sf::Lines);



                }
                if(a[graph[i][j]].y == a[i].y && a[graph[i][j]].x < a[i].x) {
                    sf::Vertex arrow5[] = {
                        sf::Vertex(sf::Vector2f((a[i].x+a[i].raduis+a[graph[i][j]].x+a[graph[i][j]].raduis)/2, (a[i].y+ a[graph[i][j]].y)/2)),

                        //sf::Vertex(sf::Vector2f((a[i].x+a[i].raduis+a[graph[i][j]].x+a[graph[i][j]].raduis)/2.f-,(a[i].y+ a[graph[i][j]].y)/2.f-10)),
                        sf::Vertex(sf::Vector2f((a[i].x+a[i].raduis+a[graph[i][j]].x+a[graph[i][j]].raduis)/2 +20,(a[i].y+ a[graph[i][j]].y)/2.f +20))
                    };
                    sf::Vertex arrow6[] = {
                        sf::Vertex(sf::Vector2f((a[i].x+a[i].raduis+a[graph[i][j]].x+a[graph[i][j]].raduis)/2, (a[i].y+ a[graph[i][j]].y)/2)),

                        //sf::Vertex(sf::Vector2f((a[i].x+a[i].raduis+a[graph[i][j]].x+a[graph[i][j]].raduis)/2.f-,(a[i].y+ a[graph[i][j]].y)/2.f-10)),
                        sf::Vertex(sf::Vector2f((a[i].x+a[i].raduis+a[graph[i][j]].x+a[graph[i][j]].raduis)/2+20,(a[i].y+ a[graph[i][j]].y)/2.f -20))
                    };
                    arrow5[0].color = sf::Color::Red;
                    arrow6[0].color = sf::Color::Red;
                    window.draw(arrow5, 2, sf::Lines);
                    window.draw(arrow6, 2, sf::Lines);



                }



            }


        }



        if(score == cnt2 && p) { // p-->true
            score=0;
            level++;
            ssScore.str("");
            sslevel.str("");
            sslevel << "Level :" <<level ;
            ssScore<< "Cycles_Found :"<< score ;
            Cycles_Found.setString(ssScore.str());
            levels.setString(sslevel.str());
            memset(vis,0, sizeof vis);
            cnt2=0;
            for(int i=0; i<4; i++) {
                All_Cycles[i].clear();
            }
            for(int i=0; i<4; i++) {
                graph[i].clear();
            }

            send_input();
            read_solution();
            p=false;
        }
        if(score == cnt2 && p ==false)
        {
            pp=true;
            window.clear(sf::Color::White);
            window.draw(s2);
            p=true;
        }
        window.display();
        if( pp )
        {
            sleep(3);
            pp=false;
        }

    }





}
