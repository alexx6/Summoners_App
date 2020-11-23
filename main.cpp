#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "../LAB3/LAB3_CODE/Summoners.h"
#include <algorithm>


int MainScene(sf::RenderWindow& window, int& CurrentScene) {
    window.clear();
    sf::Event event;
    
    sf::Font font1;
    font1.loadFromFile("Resources/18888.ttf");
    sf::Vector2f offset(440, 100);
    sf::RectangleShape menu1(sf::Vector2f(400,100));
    menu1.setFillColor(sf::Color::White);
    sf::Text menu1_text;
    menu1_text.setFont(font1);
    menu1_text.setString(sf::String("Play game"));
    menu1_text.setFillColor(sf::Color::Black);
    menu1_text.setCharacterSize(50);
    menu1_text.setPosition(70,20);
    menu1.setPosition(menu1.getPosition() + offset);
    menu1_text.setPosition(menu1_text.getPosition() + offset);

    offset += sf::Vector2f(0, 200);
    sf::RectangleShape menu2(sf::Vector2f(400, 100));
    menu2.setFillColor(sf::Color::White);
    sf::Text menu2_text;
    menu2_text.setFont(font1);
    menu2_text.setString(sf::String("Show schools"));
    menu2_text.setFillColor(sf::Color::Black);
    menu2_text.setCharacterSize(45);
    menu2_text.setPosition(52, 20);
    menu2.setPosition(menu2.getPosition() + offset);
    menu2_text.setPosition(menu2_text.getPosition() + offset);

    offset += sf::Vector2f(0, 200);
    sf::RectangleShape menu3(sf::Vector2f(400, 100));
    menu3.setFillColor(sf::Color::White);
    sf::Text menu3_text;
    menu3_text.setFont(font1);
    menu3_text.setString(sf::String("Save/Load"));
    menu3_text.setFillColor(sf::Color::Black);
    menu3_text.setCharacterSize(50);
    menu3_text.setPosition(73, 20);
    menu3.setPosition(menu3.getPosition() + offset);
    menu3_text.setPosition(menu3_text.getPosition() + offset);

    menu1.setOutlineThickness(7);
    menu1.setOutlineColor(sf::Color::Black);
    menu2.setOutlineThickness(7);
    menu2.setOutlineColor(sf::Color::Black);
    menu3.setOutlineThickness(7);
    menu3.setOutlineColor(sf::Color::Black);

    sf::Texture b_t;
    b_t.create(1280, 720);
    b_t.loadFromFile("Resources/menu_background.png");
    sf::Sprite back_image;
    back_image.setTexture(b_t);

    sf::Texture e_t;
    e_t.loadFromFile("Resources/exitsprite0.png");
    sf::Sprite exit_button;
    exit_button.setTexture(e_t);
    exit_button.scale(sf::Vector2f(0.2, 0.2));
    exit_button.setPosition(sf::Vector2f(1180, 620));

    event.type = sf::Event::MouseMoved;
    while (true)
    {
        window.pollEvent(event);

        if (event.type == sf::Event::Closed) {
            window.close();
            CurrentScene = -1;
            return 0;
        }

        if (menu1.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
            menu1.setFillColor(sf::Color(151, 182, 255));
            if (event.type == sf::Event::MouseButtonPressed) {
                CurrentScene = 1;
                return 0;
            }
        }
        else menu1.setFillColor(sf::Color::White);

        if (menu2.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
            menu2.setFillColor(sf::Color(151, 182, 255));
            if (event.type == sf::Event::MouseButtonPressed) {
                CurrentScene = 2;
                return 0;
            }
        }
        else menu2.setFillColor(sf::Color::White);
        if (menu3.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
            menu3.setFillColor(sf::Color(151, 182, 255));
            if (event.type == sf::Event::MouseButtonPressed) {
                CurrentScene = 3;
                return 0;
            }
        }
        else menu3.setFillColor(sf::Color::White);

        if (exit_button.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
            exit_button.setColor(sf::Color(150, 150, 150));
            if (event.type == sf::Event::MouseButtonPressed) {
                window.close();
                CurrentScene = -1;
                return -1;
            }
        }
        else exit_button.setColor(sf::Color::White);

        window.clear();

        window.draw(back_image);
        window.draw(menu1);
        window.draw(menu1_text);
        window.draw(menu2);
        window.draw(menu2_text);
        window.draw(menu3);
        window.draw(menu3_text);
        window.draw(exit_button);

        window.display();
    }
}

int SchoolManager(sf::RenderWindow& window, int& CurrentScene, Summoners_Game::Level& level) {
    window.clear();
    sf::Event event;

    //Vector of schools
    std::vector<sf::RectangleShape> vor;
    std::vector<sf::Text> vot;

    //Initializing the form
    sf::Font font1;
    font1.loadFromFile("Resources/18888.ttf");
    sf::Vector2f offset(30, 30);
    sf::RectangleShape menu(sf::Vector2f(400, 100));
    menu.setFillColor(sf::Color::White);
    sf::Text text;
    text.setFont(font1);
    text.setFillColor(sf::Color::Black);
    text.setCharacterSize(45);
    text.setPosition(15, 20);
    menu.setPosition(menu.getPosition() + offset);
    text.setPosition(text.getPosition() + offset);
    menu.setOutlineThickness(7);
    menu.setOutlineColor(sf::Color::Black);

    //Vectors of skills and skill parameters
    std::vector<sf::RectangleShape> vor1;
    std::vector<sf::Text> vot1;
    std::vector<sf::Text> vot2;

    //Vector of schools
    for (int i = 0; i < level.GetSchoolList().size(); i++) {
        text.setString(level.GetSchoolList()[i].Name);
        menu.setSize(sf::Vector2f(text.getGlobalBounds().width + 30, 100));
        vor.push_back(menu);
        vot.push_back(text);
    }

    //Background image
    sf::Texture b_t;
    b_t.create(1280, 720);
    b_t.loadFromFile("Resources/menu_background.png");
    sf::Sprite back_image;
    back_image.setTexture(b_t);
    
    //Return button
    sf::Texture r_t;
    r_t.loadFromFile("Resources/return_button0.png");
    sf::Sprite return_image;
    return_image.setTexture(r_t);
    return_image.setPosition(1175, 610);
    sf::RectangleShape b;

    //IDs of selected school, skill and parameter
    int selected = -1;
    int selected1 = -1;
    int selected2 = -1;

    //Lines between parameters
    sf::RectangleShape line;
    line.setSize(sf::Vector2f(600, 3));
    line.setFillColor(sf::Color::Black);

    //Parameters backlight
    sf::RectangleShape pb;
    pb.setFillColor(sf::Color(0, 0, 0, 100));
    pb.setSize(sf::Vector2f(600, 35));

    //pause background
    sf::Texture pause_texture;
    pause_texture.create(1280, 720);
    sf::Sprite pause_sprite;
    pause_sprite.setColor(sf::Color(70, 70, 70));

    //Input rectangle
    sf::RectangleShape input;
    input.setFillColor(sf::Color::White);
    input.setOutlineColor(sf::Color::Black);
    input.setOutlineThickness(3);

    //input window sign
    sf::Text sign;
    sign.setFont(font1);
    sign.setFillColor(sf::Color::White);
    sign.setCharacterSize(60);

    //Add new school button
    sf::Texture a0_t;
    a0_t.loadFromFile("Resources/additem_button0.png");
    sf::Sprite additem0_image;
    additem0_image.setTexture(a0_t);
    additem0_image.setScale(2, 2);

    //Add new skill button
    sf::Sprite additem1_image;
    additem1_image.setTexture(a0_t);
    additem1_image.setScale(1.5, 1.5);
    additem1_image.setPosition(0, -100);

    for (int i = 0; i < vor.size(); i++) {
        vor[i].setPosition(vor[i].getPosition() + sf::Vector2f(0, 120 * i));
        vot[i].setPosition(vot[i].getPosition() + sf::Vector2f(0, 120 * i));
    }

    bool rf = true;

    sf::RectangleShape del_school(sf::Vector2f(15, 15));
    del_school.setFillColor(sf::Color::Red);
    del_school.setPosition(0, -100);
    del_school.setOutlineThickness(-1);
    del_school.setOutlineColor(sf::Color::Black);

    event.type = sf::Event::MouseMoved;
    while (true)
    {
        window.pollEvent(event);

        if (event.type == sf::Event::Closed) {
            window.close();
            CurrentScene = -1;
            return 0;
        }

        //School scroll
        if (vor.size() > 0 && event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel && abs(event.mouseWheelScroll.delta) > 0.1 && sf::Mouse::getPosition(window).x < 640
            && ((event.mouseWheelScroll.delta > 0 && vor[0].getPosition().y < 30) || (event.mouseWheelScroll.delta < 0 && vor.back().getPosition().y + 200 > 690))) {
            if (event.mouseWheelScroll.delta > 10) event.mouseWheelScroll.delta = 10;
            if (event.mouseWheelScroll.delta < -10) event.mouseWheelScroll.delta = -10;
            for (int i = 0; i < vor.size(); i++) {
                vor[i].setPosition(vor[i].getPosition() + sf::Vector2f(0, 10*event.mouseWheelScroll.delta));
                vot[i].setPosition(vot[i].getPosition() + sf::Vector2f(0, 10*event.mouseWheelScroll.delta));
            }
        }

        //Skill scroll
        else if (selected >= 0 && sf::Mouse::getPosition(window).x >= 640 && vor1.size() > 0
            && ((event.mouseWheelScroll.delta > 0 && vor1[0].getPosition().y < 30) || (event.mouseWheelScroll.delta < 0 && vor1.back().getPosition().y + vor1.back().getSize().y > 690))) {
            if (event.mouseWheelScroll.delta > 10) event.mouseWheelScroll.delta = 10;
            if (event.mouseWheelScroll.delta < -10) event.mouseWheelScroll.delta = -10;
            for (int i = 0; i < vor1.size(); i++) {
                vor1[i].setPosition(vor1[i].getPosition() + sf::Vector2f(0, 10 * event.mouseWheelScroll.delta));
                vot1[i].setPosition(vot1[i].getPosition() + sf::Vector2f(0, 10 * event.mouseWheelScroll.delta));
            }
        }
        else event.mouseWheelScroll.delta = 0;
        
        //School selection
        for (int i = 0; i < vor.size(); i++) {
            if (vor[i].getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
                if (i != selected) {
                    vor[i].setFillColor(sf::Color(151, 182, 255));
                    if (event.type == sf::Event::MouseButtonPressed) {
                        vor1.clear();
                        vot1.clear();
                        for (int j = 0; j < level.GetSchoolList()[i].SkillList.size(); j++) {
                            text.setString(level.GetSchoolList()[i].SkillList[j].Name);
                            menu.setSize(sf::Vector2f(600, 100));
                            menu.setPosition(640, 30);
                            text.setPosition(655, 50);
                            vor1.push_back(menu);
                            vot1.push_back(text);
                            vor1[j].setPosition(vor1[j].getPosition() + sf::Vector2f(0, 120 * j));
                            vot1[j].setPosition(vot1[j].getPosition() + sf::Vector2f(0, 120 * j));
                        }
                        selected = i;
                        selected1 = -1;
                        vot2.clear();

                        event.type = sf::Event::MouseMoved;
                    }
                }
            }
            else vor[i].setFillColor(sf::Color::White);
        }

        //Skill selection
        for (int i = 0; i < vor1.size(); i++) {
            if (vor1[i].getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))) && rf) {
                if (i != selected1) {
                    vor1[i].setFillColor(sf::Color(151, 182, 255));
                    if (event.type == sf::Event::MouseButtonPressed) {
                        vor1[i].setSize(vor1[i].getSize() + sf::Vector2f(0, 298));
                        for (int j = i + 1; j < vor1.size(); j++) {
                            vor1[j].setPosition(vor1[j].getPosition() + sf::Vector2f(0, 298));
                            vot1[j].setPosition(vot1[j].getPosition() + sf::Vector2f(0, 298));
                        }
                        if (selected1 >= 0) {
                            vor1[selected1].setSize(vor1[selected1].getSize() - sf::Vector2f(0, 298));
                            for (int j = selected1 + 1; j < vor1.size(); j++) {
                                vor1[j].setPosition(vor1[j].getPosition() - sf::Vector2f(0, 298));
                                vot1[j].setPosition(vot1[j].getPosition() - sf::Vector2f(0, 298));
                            }
                        }
                        selected1 = i;
                        //Adding skill description
                        vot2.clear();
                        text.setCharacterSize(30);

                        text.setString(std::string("Entity name: ") + level.GetSchoolList()[selected].SkillList[selected1].Entity_Parameters.Name);
                        vot2.push_back(text);
                        text.setString(std::string("Amorality: ") + ((level.GetSchoolList()[selected].SkillList[selected1].Entity_Parameters.Amoral) ? "amoral" : "not amoral"));
                        vot2.push_back(text);
                        text.setString(std::string("Domination:                              ") + std::to_string(level.GetSchoolList()[selected].Domination));
                        vot2.push_back(text);
                        text.setString(std::string("Required school level:             ") + std::to_string(level.GetSchoolList()[selected].SkillList[selected1].RequiredSchoolLevel));
                        vot2.push_back(text);
                        text.setString(std::string("Maximum quantity:                  ") + std::to_string(level.GetSchoolList()[selected].SkillList[selected1].MaxQuantity));
                        vot2.push_back(text);
                        text.setString(std::string("Damage:                                    ") + std::to_string(level.GetSchoolList()[selected].SkillList[selected1].Entity_Parameters.Damage));
                        vot2.push_back(text);
                        text.setString(std::string("Defense:                                    ") + std::to_string(level.GetSchoolList()[selected].SkillList[selected1].Entity_Parameters.Defense));
                        vot2.push_back(text);
                        text.setString(std::string("Maximum health:                     ") + std::to_string(level.GetSchoolList()[selected].SkillList[selected1].Entity_Parameters.MaxHealth));
                        vot2.push_back(text);
                        text.setString(std::string("Speed:                                       ") + std::to_string(level.GetSchoolList()[selected].SkillList[selected1].Entity_Parameters.Speed));
                        vot2.push_back(text);

                        text.setCharacterSize(45);

                        event.type = sf::Event::MouseMoved;
                    }
                }
            }
            else {
                vor1[i].setFillColor(sf::Color::White);
            }
        }

        //Return button
        if (return_image.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
            return_image.setColor(sf::Color(150,150,150));
            if (event.type == sf::Event::MouseButtonPressed) {
                CurrentScene = 0;
                return 0;
            }
            rf = false;
        }
        else {
            return_image.setColor(sf::Color::White); 
            rf = true;
        }

        //Selected school color
        if (selected >= 0) {
            vor[selected].setFillColor(sf::Color(87,138,255));
        }

        //Selected skill color
        if (selected1 >= 0) {
            vor1[selected1].setFillColor(sf::Color(87, 138, 255));
        }

        //Update skill parameters position
        for (int i = 0; i < vot2.size(); i++)
            vot2[i].setPosition(vot1[selected1].getPosition() + sf::Vector2f(0, 60 + i * 35));


        /////// Edit parameters ////////
        
        pb.setPosition(600, -100);
        for (int i = 0; i < vot2.size(); i++) {
            if ((vot2[i].getGlobalBounds().left - 15 <= sf::Mouse::getPosition(window).x) && (sf::Mouse::getPosition(window).x <= vot2[i].getGlobalBounds().left + 585) &&
                (vot2[i].getGlobalBounds().top - 10 < sf::Mouse::getPosition(window).y) && (sf::Mouse::getPosition(window).y <= vot2[i].getGlobalBounds().top + 25)) {
                pb.setPosition(vot2[i].getPosition() + sf::Vector2f(-15, 3));
                selected2 = i;
                //New value input
                if (event.type == sf::Event::MouseButtonPressed) {
                    pause_texture.update(window);
                    pause_sprite.setTexture(pause_texture);
                    text.setString("");
                    while (selected2 >= 0) {
                        window.pollEvent(event);
                        if (event.type == sf::Event::Closed) {
                            window.close();
                            CurrentScene = -1;
                            return 0;
                        }

                        if (selected2 >= 2) {
                            sign.setString("Enter new value");
                            input.setSize(sf::Vector2f(10, 100));
                            if (event.type == sf::Event::TextEntered) {
                                if (text.getString().getSize() < 4 && (event.text.unicode == '0' || event.text.unicode == '1' || event.text.unicode == '2' ||
                                    event.text.unicode == '3' || event.text.unicode == '4' || event.text.unicode == '5' ||
                                    event.text.unicode == '6' || event.text.unicode == '7' ||
                                    event.text.unicode == '8' || event.text.unicode == '9')) {
                                    text.setString(text.getString() + event.text.unicode);
                                }
                                else if (event.text.unicode == '\b') text.setString(text.getString().substring(0, text.getString().getSize() - 1));
                                event.type = sf::Event::MouseMoved;
                            }
                            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && text.getString() != "") {
                                switch (selected2) {
                                case 2:
                                    level.GetSchoolList()[selected].Domination = std::stoi(text.getString().toAnsiString());
                                    vot2[selected2].setString(std::string("Domination:                              ") + std::to_string(level.GetSchoolList()[selected].Domination));
                                    break;
                                case 3:
                                    level.ModifySkill(level.GetSchoolList()[selected].SkillList[selected1].Name, level.GetSchoolList()[selected].Name).RequiredSchoolLevel = std::stoi(text.getString().toAnsiString());
                                    vot2[selected2].setString(std::string("Required school level:             ") + std::to_string(level.GetSchoolList()[selected].SkillList[selected1].RequiredSchoolLevel));
                                    break;
                                case 4:
                                    level.ModifySkill(level.GetSchoolList()[selected].SkillList[selected1].Name, level.GetSchoolList()[selected].Name).MaxQuantity = std::stoi(text.getString().toAnsiString());
                                    vot2[selected2].setString(std::string("Maximum quantity:                  ") + std::to_string(level.GetSchoolList()[selected].SkillList[selected1].MaxQuantity));
                                    break;
                                case 5:
                                    level.ModifySkill(level.GetSchoolList()[selected].SkillList[selected1].Name, level.GetSchoolList()[selected].Name).Entity_Parameters.Damage = std::stoi(text.getString().toAnsiString());
                                    vot2[selected2].setString(std::string("Damage:                                    ") + std::to_string(level.GetSchoolList()[selected].SkillList[selected1].Entity_Parameters.Damage));
                                    break;
                                case 6:
                                    level.ModifySkill(level.GetSchoolList()[selected].SkillList[selected1].Name, level.GetSchoolList()[selected].Name).Entity_Parameters.Defense = std::stoi(text.getString().toAnsiString());
                                    vot2[selected2].setString(std::string("Defense:                                    ") + std::to_string(level.GetSchoolList()[selected].SkillList[selected1].Entity_Parameters.Defense));
                                    break;
                                case 7:
                                    level.ModifySkill(level.GetSchoolList()[selected].SkillList[selected1].Name, level.GetSchoolList()[selected].Name).Entity_Parameters.MaxHealth = std::stoi(text.getString().toAnsiString());
                                    vot2[selected2].setString(std::string("Maximum health:                     ") + std::to_string(level.GetSchoolList()[selected].SkillList[selected1].Entity_Parameters.MaxHealth));
                                    break;
                                case 8:
                                    level.ModifySkill(level.GetSchoolList()[selected].SkillList[selected1].Name, level.GetSchoolList()[selected].Name).Entity_Parameters.Speed = std::stoi(text.getString().toAnsiString());
                                    vot2[selected2].setString(std::string("Speed:                                       ") + std::to_string(level.GetSchoolList()[selected].SkillList[selected1].Entity_Parameters.Speed));
                                    break;
                                }
                                break;
                            }
                            input.setPosition(630 - text.getGlobalBounds().width / 2, 310);
                            text.setPosition(input.getPosition().x + 10, 335);
                            input.setSize(sf::Vector2f(text.getGlobalBounds().width + 20, 100));
                        }
                        else {
                            input.setPosition(630, -200);
                            if (selected2 == 0) {
                                sign.setString("Enter new name");
                                if (event.type == sf::Event::TextEntered && !sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                                    if (text.getString().getSize() < 15 && event.text.unicode != '\b') {
                                        text.setString(text.getString() + event.text.unicode);
                                    }
                                    else if (event.text.unicode == '\b') text.setString(text.getString().substring(0, text.getString().getSize() - 1));
                                    event.type = sf::Event::MouseMoved;
                                }
                                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && text.getString() != "") {
                                    level.ModifySkill(level.GetSchoolList()[selected].SkillList[selected1].Name, level.GetSchoolList()[selected].Name).Entity_Parameters.Name = text.getString();
                                    vot2[selected2].setString(std::string("Entity name: ") + level.GetSchoolList()[selected].SkillList[selected1].Entity_Parameters.Name);
                                    break;
                                }
                                input.setPosition(630 - text.getGlobalBounds().width / 2, 310);
                                text.setPosition(input.getPosition().x + 10, 335);
                                input.setSize(sf::Vector2f(text.getGlobalBounds().width + 20, 100));
                            }
                            if (selected2 == 1) {
                                sign.setString("'a' (amoral) 'n' (not amoral)");
                                if (event.type == sf::Event::TextEntered && !sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && (event.text.unicode == 'a' || event.text.unicode == 'n' || event.text.unicode == '\b')) {
                                    if (text.getString().getSize() < 1 && event.text.unicode != '\b') {
                                        text.setString(text.getString() + event.text.unicode);
                                    }
                                    else if (event.text.unicode == '\b') text.setString(text.getString().substring(0, text.getString().getSize() - 1));
                                    event.type = sf::Event::MouseMoved;
                                }
                                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && text.getString() != "") {
                                    if (text.getString() == "a") {
                                        level.ModifySkill(level.GetSchoolList()[selected].SkillList[selected1].Name, level.GetSchoolList()[selected].Name).Entity_Parameters.Amoral = true;
                                        vot2[selected2].setString(std::string("Amorality: ") + "amoral");
                                    }
                                    else {
                                        level.ModifySkill(level.GetSchoolList()[selected].SkillList[selected1].Name, level.GetSchoolList()[selected].Name).Entity_Parameters.Amoral = false;
                                        vot2[selected2].setString(std::string("Amorality: ") + "not amoral");
                                    }
                                    break;
                                }
                                input.setPosition(630 - text.getGlobalBounds().width / 2, 310);
                                text.setPosition(input.getPosition().x + 10, 335);
                                input.setSize(sf::Vector2f(text.getGlobalBounds().width + 20, 100));
                            }
                        }
                        

                        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                            selected2 = -1;
                        }

                        sign.setPosition(sf::Vector2f(640 - sign.getGlobalBounds().width / 2, 200));

                        window.clear();
                        window.draw(pause_sprite);
                        window.draw(input);
                        window.draw(text);
                        window.draw(sign);
                        window.display();
                    }
                }
            }
        }

        ///////////////////////////////
        if (vot.size() > 0)
            additem0_image.setPosition(vot.back().getPosition() + sf::Vector2f(0, 100));
        else additem0_image.setPosition(sf::Vector2f(30, 30));

        if (additem0_image.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
            additem0_image.setColor(sf::Color(150, 150, 150));
            if (event.type == sf::Event::MouseButtonPressed) {
                pause_texture.update(window);
                pause_sprite.setTexture(pause_texture);
                text.setString("");
                sign.setString("Enter name of school to add");
                while (true) {
                    window.pollEvent(event);
                    if (event.type == sf::Event::Closed) {
                        window.close();
                        CurrentScene = -1;
                        return 0;
                    }
                    input.setPosition(630, -200);
                    if (event.type == sf::Event::TextEntered && !sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                        if (text.getString().getSize() < 15 && event.text.unicode != '\b') {
                            text.setString(text.getString() + event.text.unicode);
                        }
                        else if (event.text.unicode == '\b') text.setString(text.getString().substring(0, text.getString().getSize() - 1));
                        event.type = sf::Event::MouseMoved;
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && text.getString() != "") {
                        if (level.AddSchool(text.getString(), 0)) return 0;
                        else {
                            sign.setString("School already exists, try again");
                            text.setString("");
                        }
                    }

                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) break;

                    input.setPosition(630 - text.getGlobalBounds().width / 2, 310);
                    text.setPosition(input.getPosition().x + 10, 335);
                    input.setSize(sf::Vector2f(text.getGlobalBounds().width + 20, 100));
                    sign.setPosition(sf::Vector2f(640 - sign.getGlobalBounds().width / 2, 200));

                    window.clear();
                    window.draw(pause_sprite);
                    window.draw(input);
                    window.draw(text);
                    window.draw(sign);
                    window.display();
                }

            }
        }
        else {
            additem0_image.setColor(sf::Color::White);
        }

        if (selected >= 0) additem1_image.setPosition(vor[selected].getPosition() + sf::Vector2f(vor[selected].getGlobalBounds().width, 25));
        if (additem1_image.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
            additem1_image.setColor(sf::Color(100, 100, 200));
            if (event.type == sf::Event::MouseButtonPressed) {
                pause_texture.update(window);
                pause_sprite.setTexture(pause_texture);
                text.setString("");
                sign.setString("Enter name of skill to add");
                while (true) {
                    window.pollEvent(event);
                    if (event.type == sf::Event::Closed) {
                        window.close();
                        CurrentScene = -1;
                        return 0;
                    }
                    input.setPosition(630, -200);
                    if (event.type == sf::Event::TextEntered && !sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                        if (text.getString().getSize() < 15 && event.text.unicode != '\b') {
                            text.setString(text.getString() + event.text.unicode);
                        }
                        else if (event.text.unicode == '\b') text.setString(text.getString().substring(0, text.getString().getSize() - 1));
                        event.type = sf::Event::MouseMoved;
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && text.getString() != "") {
                        if (level.AddSkill(text.getString(), vot[selected].getString())) {
                            menu.setSize(sf::Vector2f(600, 100));
                            if (vot1.size() > 0) {
                                menu.setPosition(vor1.back().getPosition() + sf::Vector2f(0, vor1.back().getGlobalBounds().height + 20));
                                text.setPosition(vot1.back().getPosition() + sf::Vector2f(0, vor1.back().getGlobalBounds().height + 20));
                            }
                            else {
                                menu.setPosition(640, 30);
                                text.setPosition(655, 50);
                            }
                            vor1.push_back(menu);
                            vot1.push_back(text);
                            break;
                        }
                        else {
                            sign.setString("Skill already exists, try again");
                            text.setString("");
                        }
                    }

                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) break;

                    input.setPosition(630 - text.getGlobalBounds().width / 2, 310);
                    text.setPosition(input.getPosition().x + 10, 335);
                    input.setSize(sf::Vector2f(text.getGlobalBounds().width + 20, 100));
                    sign.setPosition(sf::Vector2f(640 - sign.getGlobalBounds().width / 2, 200));

                    window.clear();
                    window.draw(pause_sprite);
                    window.draw(input);
                    window.draw(text);
                    window.draw(sign);
                    window.display();
                }
            }
        }
        else {
            additem1_image.setColor(sf::Color(129, 129, 255));
        }

        if (selected >= 0)
            del_school.setPosition(vor[selected].getPosition() + sf::Vector2f(vor[selected].getGlobalBounds().width - 29, vor[selected].getGlobalBounds().height - 29));

        if (del_school.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
            del_school.setFillColor(sf::Color(150, 0, 0));
            if (event.type == sf::Event::MouseButtonPressed) {
                level.GetSchoolList().erase(level.GetSchoolList().begin() + selected);
                return 0;
            }
        }
        else {
            del_school.setFillColor(sf::Color::Red);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            CurrentScene = 0;
            return 0;
        }


        window.clear();
        //Draw background
        window.draw(back_image);
        //Draw list of schools
        for (int i = 0; i < vor.size(); i++) {
            window.draw(vor[i]);
            window.draw(vot[i]);
        }
        window.draw(additem0_image);
        window.draw(additem1_image);
        window.draw(del_school);
        //Draw list of skills
        for (int i = 0; i < vor1.size(); i++) {
            window.draw(vor1[i]);
            window.draw(vot1[i]);
        }
        //Draw parameters backlight
        if (pb.getPosition().y + 35 >= 0)
            window.draw(pb);
        //Draw skill parameters
        for (int i = 0; i < vot2.size(); i++) {
            window.draw(vot2[i]);
            line.setPosition(vot2[i].getPosition() - sf::Vector2f(15, 0));
            window.draw(line);
        }
        window.draw(return_image);
        window.display();

    }
}

int SaveLoad(sf::RenderWindow& window, int& CurrentScene, Summoners_Game::Level& level) {
    window.clear();
    sf::Event event;
    sf::Font font1;
    font1.loadFromFile("Resources/18888.ttf");
    sf::Vector2f offset(190, 200);
    sf::RectangleShape menu1(sf::Vector2f(400, 100));
    menu1.setFillColor(sf::Color::White);
    sf::Text menu1_text;
    menu1_text.setFont(font1);
    menu1_text.setString("Save game");
    menu1_text.setFillColor(sf::Color::Black);
    menu1_text.setCharacterSize(50);
    menu1_text.setPosition(70, 20);
    menu1.setOutlineThickness(7);
    menu1.setOutlineColor(sf::Color::Black);
    menu1.setPosition(menu1.getPosition() + offset);
    menu1_text.setPosition(menu1_text.getPosition() + offset);

    offset = menu1.getPosition() + sf::Vector2f(500, 0);
    sf::RectangleShape menu2(menu1);
    sf::Text menu2_text(menu1_text);
    menu2.setPosition(offset);
    menu2_text.setPosition(offset);
    menu2_text.setString("Load game");

    offset = menu1.getPosition() + sf::Vector2f(0, 200);
    sf::RectangleShape menu3(menu1);
    sf::Text menu3_text(menu1_text);
    menu3.setPosition(offset);
    menu3_text.setPosition(offset);
    menu3_text.setString("Save entities");

    offset = menu1.getPosition() + sf::Vector2f(500, 200);
    sf::RectangleShape menu4(menu1);
    sf::Text menu4_text(menu1_text);
    menu4.setPosition(offset);
    menu4_text.setPosition(offset);
    menu4_text.setString("Load entities");

    menu2_text.move(70, 20);
    menu3_text.move(50, 20);
    menu4_text.move(50, 20);

    sf::Texture b_t;
    b_t.create(1280, 720);
    b_t.loadFromFile("Resources/menu_background.png");
    sf::Sprite back_image;
    back_image.setTexture(b_t);

    sf::Texture r_t;
    r_t.loadFromFile("Resources/return_button0.png");
    sf::Sprite return_image;
    return_image.setTexture(r_t);
    return_image.setPosition(1175, 610);
    sf::RectangleShape b;

    sf::Texture pause_texture;
    pause_texture.create(1280, 720);
    sf::Sprite pause_sprite;
    pause_sprite.setColor(sf::Color(70, 70, 70));

    sf::Text sign;
    sign.setFont(font1);
    sign.setFillColor(sf::Color::White);
    sign.setCharacterSize(60);

    sf::RectangleShape input;
    input.setFillColor(sf::Color::White);
    input.setOutlineColor(sf::Color::Black);
    input.setOutlineThickness(3);

    sf::Text text(menu1_text);
    event.type = sf::Event::MouseMoved;
    while (true)
    {
        window.pollEvent(event);

        if (event.type == sf::Event::Closed) {
            window.close();
            CurrentScene = -1;
            return 0;
        }

        //Save game
        if (menu1.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
            menu1.setFillColor(sf::Color(151, 182, 255));
            if (event.type == sf::Event::MouseButtonPressed) {

            }
        }
        else menu1.setFillColor(sf::Color::White);

        //Load game
        if (menu2.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
            menu2.setFillColor(sf::Color(151, 182, 255));
            if (event.type == sf::Event::MouseButtonPressed) {
                
            }
        }
        else menu2.setFillColor(sf::Color::White);

        //Save entities
        if (menu3.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
            menu3.setFillColor(sf::Color(151, 182, 255));
            if (event.type == sf::Event::MouseButtonPressed) {
                pause_texture.update(window);
                pause_sprite.setTexture(pause_texture);
                text.setString("");
                sign.setString("Enter save file name");
                while (true) {
                    window.pollEvent(event);
                    if (event.type == sf::Event::Closed) {
                        window.close();
                        CurrentScene = -1;
                        return 0;
                    }
                    input.setPosition(630, -200);
                    if (event.type == sf::Event::TextEntered && !sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                        if (text.getString().getSize() < 15 && event.text.unicode != '\b') {
                            text.setString(text.getString() + event.text.unicode);
                        }
                        else if (event.text.unicode == '\b') text.setString(text.getString().substring(0, text.getString().getSize() - 1));
                        event.type = sf::Event::MouseMoved;
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && text.getString() != "") {
                        if (level.GetSchoolList().size()) {
                            level.SaveEntities(text.getString() + std::string(".sed"));
                            return 0;
                        }
                        else {
                            sign.setString("Nothing to save");
                            text.setString("");
                        }
                    }

                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) break;

                    input.setPosition(630 - text.getGlobalBounds().width / 2, 310);
                    text.setPosition(input.getPosition().x + 10, 335);
                    input.setSize(sf::Vector2f(text.getGlobalBounds().width + 20, 100));
                    sign.setPosition(sf::Vector2f(640 - sign.getGlobalBounds().width / 2, 200));

                    window.clear();
                    window.draw(pause_sprite);
                    window.draw(input);
                    window.draw(text);
                    window.draw(sign);
                    window.display();
                }
            }
        }
        else menu3.setFillColor(sf::Color::White);

        //Load entities
        if (menu4.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
            menu4.setFillColor(sf::Color(151, 182, 255));
            if (event.type == sf::Event::MouseButtonPressed) {
                pause_texture.update(window);
                pause_sprite.setTexture(pause_texture);
                text.setString("");
                sign.setString("Enter save file name");
                while (true) {
                    window.pollEvent(event);
                    if (event.type == sf::Event::Closed) {
                        window.close();
                        CurrentScene = -1;
                        return 0;
                    }
                    input.setPosition(630, -200);
                    if (event.type == sf::Event::TextEntered && !sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                        if (text.getString().getSize() < 15 && event.text.unicode != '\b') {
                            text.setString(text.getString() + event.text.unicode);
                        }
                        else if (event.text.unicode == '\b') text.setString(text.getString().substring(0, text.getString().getSize() - 1));
                        event.type = sf::Event::MouseMoved;
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && text.getString() != "") {
                        if (level.LoadEntities(text.getString() + std::string(".sed"))) return 0;
                        else {
                            sign.setString("File not found");
                            text.setString("");
                        }
                    }

                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) break;

                    input.setPosition(630 - text.getGlobalBounds().width / 2, 310);
                    text.setPosition(input.getPosition().x + 10, 335);
                    input.setSize(sf::Vector2f(text.getGlobalBounds().width + 20, 100));
                    sign.setPosition(sf::Vector2f(640 - sign.getGlobalBounds().width / 2, 200));

                    window.clear();
                    window.draw(pause_sprite);
                    window.draw(input);
                    window.draw(text);
                    window.draw(sign);
                    window.display();
                }
            }
        }
        else menu4.setFillColor(sf::Color::White);


        if (return_image.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
            return_image.setColor(sf::Color(150, 150, 150));
            if (event.type == sf::Event::MouseButtonPressed) {
                CurrentScene = 0;
                return 0;
            }
        }
        else return_image.setColor(sf::Color::White);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            CurrentScene = 0;
            return 0;
        }


        window.clear();
        window.draw(back_image);
        window.draw(menu1);
        window.draw(menu1_text);
        window.draw(menu2);
        window.draw(menu2_text);
        window.draw(menu3);
        window.draw(menu3_text);
        window.draw(menu4);
        window.draw(menu4_text);
        window.draw(return_image);
        window.display();
    }
}

std::vector<int> PossibleDestinations(sf::RenderWindow& window, Summoners_Game::Level& level, int sp, int count = 10) {
    std::vector<int> c;
    int i = 0;
    int dd = 0;
    int n;
    if (level.GetCellType(sp % level.GetSizeX(), sp / level.GetSizeX()) != Summoners_Game::CellType::CELL_WALL) c.push_back(sp);
    while (dd < count) {
        n = c.size();
        while (i < n) {
            if (c[i] % level.GetSizeX() < (level.GetSizeX() - 1) && level.GetCellType(c[i] % level.GetSizeX() + 1, c[i] / level.GetSizeX()) != Summoners_Game::CellType::CELL_WALL) {
                if (std::find(c.begin(), c.end(), c[i] + 1) == c.end()) {
                    c.push_back(c[i] + 1);
                }
            }
            if ((c[i] % level.GetSizeX() > 0) && level.GetCellType(c[i] % level.GetSizeX() - 1, c[i] / level.GetSizeX()) != Summoners_Game::CellType::CELL_WALL) {
                if (std::find(c.begin(), c.end(), c[i] - 1) == c.end()) {
                    c.push_back(c[i] - 1);
                }
            }
            if (c[i] / level.GetSizeX() < (level.GetSizeY() - 1) && level.GetCellType(c[i] % level.GetSizeX(), c[i] / level.GetSizeX() + 1) != Summoners_Game::CellType::CELL_WALL) {
                if (std::find(c.begin(), c.end(), c[i] + level.GetSizeX()) == c.end()) {
                    c.push_back(c[i] + level.GetSizeX());
                }
            }
            if ((c[i] / level.GetSizeX() > 0) && level.GetCellType(c[i] % level.GetSizeX(), c[i] / level.GetSizeX() - 1) != Summoners_Game::CellType::CELL_WALL) {
                if (std::find(c.begin(), c.end(), c[i] - level.GetSizeX()) == c.end()) {
                    c.push_back(c[i] - level.GetSizeX());
                }
            }
            i++;
        }
        dd++;
    }
    return c;
}

int SchoolUpgrade(sf::RenderWindow& window, Summoners_Game::Level& level, int& currentplayer) {
    sf::Event event;

    //Vector of schools
    std::vector<sf::RectangleShape> vor;
    std::vector<sf::Text> vot;

    //Initializing the form
    sf::Font font1;
    font1.loadFromFile("Resources/18888.ttf");
    sf::Vector2f offset(30, 30);
    sf::RectangleShape menu(sf::Vector2f(400, 100));
    menu.setFillColor(sf::Color::White);
    sf::Text text;
    text.setFont(font1);
    text.setFillColor(sf::Color::Black);
    text.setCharacterSize(45);
    text.setPosition(15, 20);
    menu.setPosition(menu.getPosition() + offset);
    text.setPosition(text.getPosition() + offset);
    menu.setOutlineThickness(7);
    menu.setOutlineColor(sf::Color::Black);

    //Vectors of skills and skill parameters
    std::vector<sf::RectangleShape> vor1;
    std::vector<sf::Text> vot1;
    std::vector<sf::Text> vot2;

    //Vector of schools
    for (int i = 0; i < level.GetSchoolList().size(); i++) {
        text.setString(level.GetSchoolList()[i].Name);
        menu.setSize(sf::Vector2f(text.getGlobalBounds().width + 30, 100));
        vor.push_back(menu);
        vot.push_back(text);
    }

    //Background image
    sf::Texture b_t;
    b_t.create(1280, 720);
    b_t.loadFromFile("Resources/menu_background.png");
    sf::Sprite back_image;
    back_image.setTexture(b_t);

    //Return button
    sf::Texture r_t;
    r_t.loadFromFile("Resources/return_button0.png");
    sf::Sprite return_image;
    return_image.setTexture(r_t);
    return_image.setPosition(window.getSize().x - 105, window.getSize().y - 105);
    sf::RectangleShape b;

    //IDs of selected school, skill and parameter
    int selected = -1;
    int selected1 = -1;
    int selected2 = -1;

    //Lines between parameters
    sf::RectangleShape line;
    line.setSize(sf::Vector2f(600, 3));
    line.setFillColor(sf::Color::Black);

    //pause background
    sf::Texture pause_texture;
    pause_texture.create(window.getSize().x, window.getSize().y);
    pause_texture.update(window);
    sf::Sprite pause_sprite;
    pause_sprite.setTexture(pause_texture);
    pause_sprite.setColor(sf::Color(70, 70, 70));

    //Input rectangle
    sf::RectangleShape input;
    input.setFillColor(sf::Color::White);
    input.setOutlineColor(sf::Color::Black);
    input.setOutlineThickness(3);

    //input window sign
    sf::Text sign;
    sign.setFont(font1);
    sign.setFillColor(sf::Color::White);
    sign.setCharacterSize(60);

    //Add new school button
    sf::Texture a0_t;
    a0_t.loadFromFile("Resources/upgradearrow.png");
    sf::Sprite additem0_image;
    additem0_image.setTexture(a0_t);
    additem0_image.setScale(2, 2);

    //Upgrade button
    sf::Sprite additem1_image;
    additem1_image.setTexture(a0_t);
    additem1_image.setScale(1.5, 1.5);
    additem1_image.setPosition(0, -100);
    additem1_image.setScale(sf::Vector2f(0.25, 0.25));

    for (int i = 0; i < vor.size(); i++) {
        vor[i].setPosition(vor[i].getPosition() + sf::Vector2f(0, 120 * i));
        vot[i].setPosition(vot[i].getPosition() + sf::Vector2f(0, 120 * i));
    }

    bool rf = true;

    sf::RectangleShape del_school(sf::Vector2f(15, 15));
    del_school.setFillColor(sf::Color::Red);
    del_school.setPosition(0, -100);
    del_school.setOutlineThickness(-1);
    del_school.setOutlineColor(sf::Color::Black);

    sf::Text sl(text);
    sl.setString("LVL");
    sl.setCharacterSize(30);
    sl.setOutlineColor(sf::Color::Black);
    sl.setOutlineThickness(1);
    sl.setFillColor(sf::Color::Red);

    sf::Clock wt;
    sf::Text warningtext(text);
    warningtext.setFillColor(sf::Color::White);
    warningtext.setCharacterSize(70 * level.GetSizeX() / 19);
    warningtext.setOutlineColor(sf::Color::Black);
    warningtext.setOutlineThickness(3);
    bool warning = false;

    event.type = sf::Event::MouseMoved;
    while (true)
    {
        window.pollEvent(event);

        if (event.type == sf::Event::Closed) {
            return 0;
        }

        //School scroll
        if (vor.size() > 0 && event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel && abs(event.mouseWheelScroll.delta) > 0.1 && sf::Mouse::getPosition(window).x < 640
            && ((event.mouseWheelScroll.delta > 0 && vor[0].getPosition().y < 30) || (event.mouseWheelScroll.delta < 0 && vor.back().getPosition().y + 200 > window.getSize().y - 30))) {
            if (event.mouseWheelScroll.delta > 10) event.mouseWheelScroll.delta = 10;
            if (event.mouseWheelScroll.delta < -10) event.mouseWheelScroll.delta = -10;
            for (int i = 0; i < vor.size(); i++) {
                vor[i].setPosition(vor[i].getPosition() + sf::Vector2f(0, 10 * event.mouseWheelScroll.delta));
                vot[i].setPosition(vot[i].getPosition() + sf::Vector2f(0, 10 * event.mouseWheelScroll.delta));
            }
        }

        //Skill scroll
        else if (selected >= 0 && sf::Mouse::getPosition(window).x >= 640 && vor1.size() > 0
            && ((event.mouseWheelScroll.delta > 0 && vor1[0].getPosition().y < 30) || (event.mouseWheelScroll.delta < 0 && vor1.back().getPosition().y + vor1.back().getSize().y > window.getSize().y - 30))) {
            if (event.mouseWheelScroll.delta > 10) event.mouseWheelScroll.delta = 10;
            if (event.mouseWheelScroll.delta < -10) event.mouseWheelScroll.delta = -10;
            for (int i = 0; i < vor1.size(); i++) {
                vor1[i].setPosition(vor1[i].getPosition() + sf::Vector2f(0, 10 * event.mouseWheelScroll.delta));
                vot1[i].setPosition(vot1[i].getPosition() + sf::Vector2f(0, 10 * event.mouseWheelScroll.delta));
            }
        }
        else event.mouseWheelScroll.delta = 0;

        //School selection
        for (int i = 0; i < vor.size(); i++) {
            if (vor[i].getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
                if (i != selected) {
                    vor[i].setFillColor(sf::Color(151, 182, 255));
                    if (event.type == sf::Event::MouseButtonPressed) {
                        vor1.clear();
                        vot1.clear();
                        for (int j = 0; j < level.GetSchoolList()[i].SkillList.size(); j++) {
                            text.setString(level.GetSchoolList()[i].SkillList[j].Name);
                            menu.setSize(sf::Vector2f(600, 100));
                            menu.setPosition(640, 30);
                            text.setPosition(655, 50);

                            menu.setFillColor(sf::Color::White);

                            vor1.push_back(menu);
                            vot1.push_back(text);
                            vor1[j].setPosition(vor1[j].getPosition() + sf::Vector2f(0, 120 * j));
                            vot1[j].setPosition(vot1[j].getPosition() + sf::Vector2f(0, 120 * j));
                        }
                        selected = i;
                        selected1 = -1;
                        vot2.clear();

                        event.type = sf::Event::MouseMoved;
                    }
                }
            }
            else vor[i].setFillColor(sf::Color::White);
        }

        //Skill selection
        for (int i = 0; i < vor1.size(); i++) {
            if (vor1[i].getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))) && rf) {
                if (i != selected1) {
                    vor1[i].setFillColor(sf::Color(151, 182, 255));
                    if (event.type == sf::Event::MouseButtonPressed) {
                        vor1[i].setSize(vor1[i].getSize() + sf::Vector2f(0, 298));
                        for (int j = i + 1; j < vor1.size(); j++) {
                            vor1[j].setPosition(vor1[j].getPosition() + sf::Vector2f(0, 298));
                            vot1[j].setPosition(vot1[j].getPosition() + sf::Vector2f(0, 298));
                        }
                        if (selected1 >= 0) {
                            vor1[selected1].setSize(vor1[selected1].getSize() - sf::Vector2f(0, 298));
                            for (int j = selected1 + 1; j < vor1.size(); j++) {
                                vor1[j].setPosition(vor1[j].getPosition() - sf::Vector2f(0, 298));
                                vot1[j].setPosition(vot1[j].getPosition() - sf::Vector2f(0, 298));
                            }
                        }
                        selected1 = i;
                        //Adding skill description
                        vot2.clear();
                        text.setCharacterSize(30);

                        text.setString(std::string("Entity name: ") + level.GetSchoolList()[selected].SkillList[selected1].Entity_Parameters.Name);
                        vot2.push_back(text);
                        text.setString(std::string("Amorality: ") + ((level.GetSchoolList()[selected].SkillList[selected1].Entity_Parameters.Amoral) ? "amoral" : "not amoral"));
                        vot2.push_back(text);
                        text.setString(std::string("Domination:                              ") + std::to_string(level.GetSchoolList()[selected].Domination));
                        vot2.push_back(text);
                        text.setString(std::string("Required school level:             ") + std::to_string(level.GetSchoolList()[selected].SkillList[selected1].RequiredSchoolLevel));
                        vot2.push_back(text);
                        text.setString(std::string("Maximum quantity:                  ") + std::to_string(level.GetSchoolList()[selected].SkillList[selected1].MaxQuantity));
                        vot2.push_back(text);
                        text.setString(std::string("Damage:                                    ") + std::to_string(level.GetSchoolList()[selected].SkillList[selected1].Entity_Parameters.Damage));
                        vot2.push_back(text);
                        text.setString(std::string("Defense:                                    ") + std::to_string(level.GetSchoolList()[selected].SkillList[selected1].Entity_Parameters.Defense));
                        vot2.push_back(text);
                        text.setString(std::string("Maximum health:                     ") + std::to_string(level.GetSchoolList()[selected].SkillList[selected1].Entity_Parameters.MaxHealth));
                        vot2.push_back(text);
                        text.setString(std::string("Speed:                                       ") + std::to_string(level.GetSchoolList()[selected].SkillList[selected1].Entity_Parameters.Speed));
                        vot2.push_back(text);

                        text.setCharacterSize(45);

                        event.type = sf::Event::MouseMoved;
                    }
                }
            }
            else if (level.GetSummoner()[currentplayer].GetSchoolLevels()[selected] >= level.GetSchoolList()[selected].SkillList[i].RequiredSchoolLevel) {
                vor1[i].setFillColor(sf::Color(214, 178, 255));
            }
            else {
                vor1[i].setFillColor(sf::Color::White);
            }
        }

        //Return button
        if (return_image.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
            return_image.setColor(sf::Color(150, 150, 150));
            if (event.type == sf::Event::MouseButtonPressed) {
                return 0;
            }
            rf = false;
        }
        else {
            return_image.setColor(sf::Color::White);
            rf = true;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) return 0;

        //Selected school color
        if (selected >= 0) {
            vor[selected].setFillColor(sf::Color(87, 138, 255));
        }

        //Selected skill color
        if (selected1 >= 0) {
            vor1[selected1].setFillColor(sf::Color(87, 138, 255));
        }

        //Update skill parameters position
        for (int i = 0; i < vot2.size(); i++)
            vot2[i].setPosition(vot1[selected1].getPosition() + sf::Vector2f(0, 60 + i * 35));


        if (selected >= 0) additem1_image.setPosition(vor[selected].getPosition() + sf::Vector2f(vor[selected].getGlobalBounds().width, 25));
        if (additem1_image.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
            additem1_image.setColor(sf::Color(100, 100, 200));
            if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                try {
                    level.GetSummoner()[currentplayer].Upgrade(selected);
                    currentplayer = (currentplayer + 1) % 2;
                    return 0;
                }
                catch (std::exception& ex) {
                    wt.restart();
                    warning = true;
                    warningtext.setPosition(level.GetSizeX() * 40 - 400 * level.GetSizeX() / 19, level.GetSizeY() * 40 - 100);
                    warningtext.setFillColor(sf::Color(255, 100, 100, 0));
                    warningtext.setString(ex.what());
                }
                event.type = sf::Event::MouseMoved;
            }
        }
        else {
            additem1_image.setColor(sf::Color(129, 129, 255));
        }

        window.clear();
        //Draw background
        window.draw(pause_sprite);
        //Draw list of schools
        for (int i = 0; i < vor.size(); i++) {
            window.draw(vor[i]);
            window.draw(vot[i]);
            sl.setString(sf::String("LVL ") + std::to_string(level.GetSummoner()[currentplayer].GetSchoolLevels()[i]));
            sl.setPosition(vor[i].getPosition() + vor[i].getSize() - sf::Vector2f(sl.getGlobalBounds().width, sl.getGlobalBounds().height) - sf::Vector2f(2,6));
            window.draw(sl);
        }
        window.draw(additem1_image);
        //Draw list of skills
        for (int i = 0; i < vor1.size(); i++) {
            window.draw(vor1[i]);
            window.draw(vot1[i]);
        }
        //Draw skill parameters
        for (int i = 0; i < vot2.size(); i++) {
            window.draw(vot2[i]);
            line.setPosition(vot2[i].getPosition() - sf::Vector2f(15, 0));
            window.draw(line);
        }
        window.draw(return_image);

        if (warning && wt.getElapsedTime().asSeconds() < 5) {
            window.draw(warningtext);
            if (wt.getElapsedTime().asMilliseconds() < 500) {
                warningtext.setOutlineColor(sf::Color(0, 0, 0, 0) + sf::Color(0, 0, 0, wt.getElapsedTime().asMilliseconds() * 255 / 500));
                warningtext.setFillColor(sf::Color(255, 100, 100, 0) + sf::Color(0, 0, 0, wt.getElapsedTime().asMilliseconds() * 255 / 500));
            }
            else {
                warningtext.setFillColor(sf::Color(255, 100, 100) - sf::Color(0, 0, 0, (wt.getElapsedTime().asMilliseconds() - 500) * 255 / 4500));
                warningtext.setOutlineColor(sf::Color::Black - sf::Color(0, 0, 0, (wt.getElapsedTime().asMilliseconds() - 500) * 255 / 4500));
            }
        }
        else warning = false;

        window.display();
    }
}

int Play(sf::RenderWindow& window, int& CurrentScene, Summoners_Game::Level& level) {

    //Ground tile
    sf::Texture ground_t;
    ground_t.loadFromFile("Resources/Map/ground_tile.png");
    sf::Sprite ground_tile;
    ground_tile.setTexture(ground_t);
    //wall tile
    sf::Texture wall_t;
    wall_t.loadFromFile("Resources/Map/wall_tile.png");
    sf::Sprite wall_tile;
    wall_tile.setColor(sf::Color(150, 150, 150));
    wall_tile.setTexture(wall_t);
    //Summoner sprites
    sf::Texture summoner_t;
    summoner_t.loadFromFile("Resources/summoner_sprite.png");
    sf::Sprite summoner0_sprite;
    summoner0_sprite.setTexture(summoner_t);
    sf::Sprite summoner1_sprite(summoner0_sprite);
    summoner1_sprite.setColor(sf::Color(255, 255, 0));
    //Text and button
    sf::Vector2f offset(sf::Vector2f(level.GetSizeX() * 80 + 50, 20));
    sf::Font font1;
    font1.loadFromFile("Resources/18888.ttf");
    sf::Text utext;
    utext.setFont(font1);
    utext.setFillColor(sf::Color::Black);
    utext.setCharacterSize(30);
    sf::RectangleShape menu(sf::Vector2f(300, 40));
    menu.setFillColor(sf::Color::White);
    menu.setOutlineThickness(7);
    menu.setOutlineColor(sf::Color::Black);
    menu.setPosition(menu.getPosition() + offset);
    utext.setPosition(utext.getPosition() + offset);
    sf::Text title(utext);
    title.setFillColor(sf::Color::White);
    title.move(50, 0);
    //////////////////////////////////////////

    sf::RectangleShape hl;
    hl.setSize(sf::Vector2f(80, 80));
    hl.setFillColor(sf::Color(255, 255, 255, 50));

    sf::RectangleShape hl1(hl);
    hl1.setFillColor(sf::Color(0, 255, 0, 30));

    int x, y, sizex, sizey;
    sizex = level.GetSizeX();
    sizey = level.GetSizeY();

    int speed = 10;

    std::vector<int> pd;

    int selected = 1;

    static int currentplayer = 0;
    int gamestate = 0; //0 - summoner is selected, 1 - squad is selected
    bool pressedupgradeschool = false;

    sf::Event event;
    event.type = sf::Event::MouseMoved;
    while (true)
    {
        window.pollEvent(event);

        if (event.type == sf::Event::Closed) {
            window.close();
            CurrentScene = 0;
            return 0;
        }

        if (currentplayer == 0) {
            title.setString("Player0's turn");
            window.draw(title);
        }
        else {
            title.setString("Player0's turn");
            window.draw(title);
        }

        if (gamestate == 0) {

        }

        if (pressedupgradeschool) {
            SchoolUpgrade(window, level, currentplayer);
            pressedupgradeschool = false;
        }
            

        window.clear();
        for (int i = 0; i < level.GetDungeon().size(); i++) {
            x = i % sizex;
            y = i / sizex;
            ground_tile.setPosition(x * 80, y * 80);
            window.draw(ground_tile);
            if (level.GetCellType(x, y) == Summoners_Game::CellType::CELL_WALL) {
                wall_tile.setPosition(x * 80, y * 80);
                window.draw(wall_tile);
            }
            if (level.GetCellType(x, y) == Summoners_Game::CellType::CELL_SUMMONER) {

                if ((static_cast<Summoners_Game::Cell_Summoner*>(level.GetDungeon()[i]))->Object == &level.GetSummoner()[0]) {
                    summoner0_sprite.setPosition(x * 80, y * 80);
                }
                else {
                    summoner1_sprite.setPosition(x * 80, y * 80);
                }
            }
        }
        for (int i = 0; i < level.GetDungeon().size(); i++) {
            x = i % sizex;
            y = i / sizex;
            hl.setPosition(x * 80, y * 80);
            if (hl.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
                window.draw(hl);
                if (selected == 1) {
                    pd = PossibleDestinations(window, level, i);
                    for (int i = 0; i < pd.size(); i++) {
                        hl1.setPosition((pd[i] % level.GetSizeX()) * 80, (pd[i] / level.GetSizeX()) * 80);
                        window.draw(hl1);
                    }
                }
               
            }
        }

        //Highlighting player's entities
        hl.setPosition(level.GetSummoner()[currentplayer].GetInfo().x * 80, level.GetSummoner()[currentplayer].GetInfo().y * 80);
        window.draw(hl);
        for (int i = 0; i < level.GetSummoner()[currentplayer].GetSquad().size(); i++) {
            hl.setPosition(level.GetSummoner()[currentplayer].GetSquad()[i]->GetSquadInfo().x * 80, level.GetSummoner()[currentplayer].GetSquad()[i]->GetSquadInfo().y * 80);
            window.draw(hl);
        }

        if (gamestate == 0) {
            //Summmon squad button
            utext.setPosition(level.GetSizeX() * 80 + 90, 70);
            menu.setPosition(level.GetSizeX() * 80 + 50, 70);
            utext.setString("Summon squad");
            if (menu.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
                menu.setFillColor(sf::Color(151, 182, 255));
                if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                }
            }
            else {
                menu.setFillColor(sf::Color::White);
            }
            window.draw(menu);
            window.draw(utext);
            
            //Upgrade school button
            utext.move(0, 60);
            menu.move(0, 60);
            utext.setString("Upgrade school");
            if (menu.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
                menu.setFillColor(sf::Color(151, 182, 255));
                if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    pressedupgradeschool = true;
                }
            }
            else {
                menu.setFillColor(sf::Color::White);
            }
            window.draw(menu);
            window.draw(utext);
        }
        


        window.draw(summoner0_sprite);
        window.draw(summoner1_sprite);

        
        window.draw(title);

        window.display();

    }

}

int MapEditor(int& CurrentScene, Summoners_Game::Level& level, bool& gamestarted) {

    sf::ContextSettings settings;
    settings.antialiasingLevel = 4;
    sf::RenderWindow window(sf::VideoMode(level.GetSizeX()*80 + 400, level.GetSizeY() * 80), "Map editor", sf::Style::Titlebar | sf::Style::Close, settings);
    window.setVerticalSyncEnabled(true);
    sf::Image icon;
    icon.loadFromFile("Resources/return_button0.png");
    window.setIcon(64, 64, icon.getPixelsPtr());
    window.setPosition(sf::Vector2i(0, 0));

    if (gamestarted) {
        Play(window, CurrentScene, level);
        return 0;
    }

    //Ground tile
    sf::Texture ground_t;
    ground_t.loadFromFile("Resources/Map/ground_tile.png");
    sf::Sprite ground_tile;
    ground_tile.setTexture(ground_t);
    //wall tile
    sf::Texture wall_t;
    wall_t.loadFromFile("Resources/Map/wall_tile.png");
    sf::Sprite wall_tile;
    wall_tile.setColor(sf::Color(150, 150, 150));
    wall_tile.setTexture(wall_t);

    //Summoner sprites
    sf::Texture summoner_t;
    summoner_t.loadFromFile("Resources/summoner_sprite.png");
    sf::Sprite summoner0_sprite;
    summoner0_sprite.setTexture(summoner_t);
    sf::Sprite summoner1_sprite(summoner0_sprite);
    summoner1_sprite.setColor(sf::Color(255, 255, 0));

    sf::RectangleShape hl;
    hl.setSize(sf::Vector2f(80, 80));
    hl.setFillColor(sf::Color(255, 255, 255, 50));

    //buttons
    sf::Font font1;
    font1.loadFromFile("Resources/18888.ttf");
    sf::Vector2f offset(sf::Vector2f(level.GetSizeX()*80 + 50, 20));
    sf::RectangleShape menu1(sf::Vector2f(300, 40));
    menu1.setFillColor(sf::Color::White);
    sf::Text menu1_text;
    menu1_text.setFont(font1);
    menu1_text.setString("Load map");
    menu1_text.setFillColor(sf::Color::Black);
    menu1_text.setCharacterSize(30);
    menu1_text.setPosition(75, 1);
    menu1.setOutlineThickness(7);
    menu1.setOutlineColor(sf::Color::Black);
    menu1.setPosition(menu1.getPosition() + offset);
    menu1_text.setPosition(menu1_text.getPosition() + offset);
    
    offset = sf::Vector2f(0, 50);
    sf::RectangleShape menu2(menu1);
    sf::Text menu2_text(menu1_text);
    menu2_text.setString("Save map");
    menu2.setPosition(menu1.getPosition() + offset);
    menu2_text.setPosition(menu1_text.getPosition() + offset);

    sf::RectangleShape menu3(menu1);
    sf::Text menu3_text(menu1_text);
    menu3_text.setString("Start game");
    menu3.setPosition(sf::Vector2f(menu1.getPosition().x, window.getSize().y - 70));
    menu3_text.setPosition(sf::Vector2f(menu1_text.getPosition().x, window.getSize().y - 70));

    
    offset = sf::Vector2f(-10, window.getSize().y / 2 - 80);
    sf::Text w_text(menu1_text);
    w_text.setString("Map width: ");
    w_text.setFillColor(sf::Color::White);
    w_text.setPosition(menu1_text.getPosition() + offset);

    offset = sf::Vector2f(-10, 60);
    sf::Text h_text(menu1_text);
    h_text.setString("Map height: ");
    h_text.setFillColor(sf::Color::White);
    h_text.setPosition(w_text.getPosition() + offset);

    sf::RectangleShape menu4(menu1);
    sf::Text menu4_text(menu1_text);
    menu4_text.setString("Apply changes");
    menu4.setPosition(sf::Vector2f(menu1.getPosition().x, h_text.getPosition().y + 80));
    menu4_text.setPosition(sf::Vector2f(menu1_text.getPosition().x - 30, h_text.getPosition().y + 80));

    sf::CircleShape wu(10, 3);
    wu.setPosition(w_text.getPosition() + sf::Vector2f(150, 5));

    sf::CircleShape wd(wu);
    wd.setRotation(180);
    wd.move(20,35);

    sf::CircleShape hu(10, 3);
    hu.setPosition(h_text.getPosition() + sf::Vector2f(160, 5));

    sf::CircleShape hd(hu);
    hd.setRotation(180);
    hd.move(20, 35);
    

    int x, y, sizex, sizey;
    sizex = level.GetSizeX();
    sizey = level.GetSizeY();

    int new_w = sizex;
    int new_h = sizey;

    sf::Text sign;
    sign.setFont(font1);
    sign.setFillColor(sf::Color::White);
    sign.setCharacterSize(60);

    sf::RectangleShape input;
    input.setFillColor(sf::Color::White);
    input.setOutlineColor(sf::Color::Black);
    input.setOutlineThickness(3);

    sf::Text text(menu1_text);
    text.setCharacterSize(50);

    sf::Texture pause_texture;
    pause_texture.create(1280, 720);
    sf::Sprite pause_sprite;
    pause_sprite.setColor(sf::Color(70, 70, 70));

    int summoner_drag = -1;
    bool warning = false;

    //Warning
    sf::Clock wt;
    sf::Text warningtext(text);
    warningtext.setFillColor(sf::Color::White);
    warningtext.setCharacterSize(70 * sizex / 19);
    warningtext.setString("Current map can't be used \nbecause summoners are \nisolated from each other");

    sf::Event event;
    event.type = sf::Event::MouseMoved;
    while (true)
    {
        window.pollEvent(event);

        if (event.type == sf::Event::Closed) {
            window.close();
            CurrentScene = 0;
            return 0;
        }

        if (menu1.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
            menu1.setFillColor(sf::Color(151, 182, 255));
            if (event.type == sf::Event::MouseButtonPressed) {
                pause_texture.update(window);
                pause_sprite.setTexture(pause_texture);
                text.setString("");
                sign.setString("Enter map file name");
                while (true) {
                    window.pollEvent(event);
                    if (event.type == sf::Event::Closed) {
                        window.close();
                        CurrentScene = -1;
                        return 0;
                    }
                    input.setPosition(630, -200);
                    if (event.type == sf::Event::TextEntered && !sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                        if (text.getString().getSize() < 15 && event.text.unicode != '\b') {
                            text.setString(text.getString() + event.text.unicode);
                        }
                        else if (event.text.unicode == '\b') text.setString(text.getString().substring(0, text.getString().getSize() - 1));
                        event.type = sf::Event::MouseMoved;
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && text.getString() != "") {
                        if (level.LoadMap(text.getString() + std::string(".smd"))) {
                            return 0;
                        }
                        else {
                            sign.setString("Map not found");
                            text.setString("");
                        }
                    }

                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) break;

                    input.setPosition(window.getSize().x / 2 - text.getGlobalBounds().width / 2, window.getSize().y / 2);
                    text.setPosition(input.getPosition().x + 10, input.getPosition().y + 25);
                    input.setSize(sf::Vector2f(text.getGlobalBounds().width + 20, 100));
                    sign.setPosition(sf::Vector2f(window.getSize().x / 2 - sign.getGlobalBounds().width / 2, window.getSize().y / 4));

                    window.clear();
                    window.draw(pause_sprite);
                    window.draw(input);
                    window.draw(text);
                    window.draw(sign);
                    window.display();
                }
            }
        }
        else  menu1.setFillColor(sf::Color::White);

        if (menu2.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
            menu2.setFillColor(sf::Color(151, 182, 255));
            if (event.type == sf::Event::MouseButtonPressed) {
                pause_texture.update(window);
                pause_sprite.setTexture(pause_texture);
                text.setString("");
                sign.setString("Enter map file name");
                while (true) {
                    window.pollEvent(event);
                    if (event.type == sf::Event::Closed) {
                        window.close();
                        CurrentScene = -1;
                        return 0;
                    }
                    input.setPosition(630, -200);
                    if (event.type == sf::Event::TextEntered && !sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                        if (text.getString().getSize() < 15 && event.text.unicode != '\b') {
                            text.setString(text.getString() + event.text.unicode);
                        }
                        else if (event.text.unicode == '\b') text.setString(text.getString().substring(0, text.getString().getSize() - 1));
                        event.type = sf::Event::MouseMoved;
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && text.getString() != "") {
                        if (level.SaveMap(text.getString() + std::string(".smd"))) {
                            return 0;
                        }
                        else {
                            sign.setString("Something wrong happened");
                            text.setString("");
                        }
                    }

                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) break;

                    input.setPosition(window.getSize().x / 2 - text.getGlobalBounds().width / 2, window.getSize().y / 2);
                    text.setPosition(input.getPosition().x + 10, input.getPosition().y + 25);
                    input.setSize(sf::Vector2f(text.getGlobalBounds().width + 20, 100));
                    sign.setPosition(sf::Vector2f(window.getSize().x / 2 - sign.getGlobalBounds().width / 2, window.getSize().y / 4));

                    window.clear();
                    window.draw(pause_sprite);
                    window.draw(input);
                    window.draw(text);
                    window.draw(sign);
                    window.display();
                }
            }
        }
        else  menu2.setFillColor(sf::Color::White);


        if (wu.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
            wu.setFillColor(sf::Color::Green);
            if (new_w == 19) {
                wu.setFillColor(sf::Color::Red);
            }
            else if (event.type == sf::Event::MouseButtonPressed) {
                new_w += 1;
            }
        }
        else wu.setFillColor(sf::Color::White);

        if (wd.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
            wd.setFillColor(sf::Color::Green);
            if (new_w == 12) {
                wd.setFillColor(sf::Color::Red);
            }
            else if (event.type == sf::Event::MouseButtonPressed) {
                new_w -= 1;
            }
        }
        else wd.setFillColor(sf::Color::White);

        if (hu.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
            hu.setFillColor(sf::Color::Green);
            if (new_h == 12) {
                hu.setFillColor(sf::Color::Red);
            }
            else if (event.type == sf::Event::MouseButtonPressed) {
                new_h += 1;
            }
        }
        else hu.setFillColor(sf::Color::White);

        if (hd.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
            hd.setFillColor(sf::Color::Green);
            if (new_h == 9) {
                hd.setFillColor(sf::Color::Red);
            }
            else if (event.type == sf::Event::MouseButtonPressed) {
                new_h -= 1;
            }
        }
        else hd.setFillColor(sf::Color::White);

        if (menu4.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
            menu4.setFillColor(sf::Color(151, 182, 255));
            if (event.type == sf::Event::MouseButtonPressed) {
                level.SetSize(new_w, new_h);
                return 0;
            }
        }
        else  menu4.setFillColor(sf::Color::White);

        if (menu3.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
            menu3.setFillColor(sf::Color(151, 182, 255));
            if (event.type == sf::Event::MouseButtonPressed) {
                std::vector<int> pd;
                pd = PossibleDestinations(window, level, level.GetSummoner()[0].GetInfo().x + sizex * level.GetSummoner()[0].GetInfo().y, 150);
                if (std::find(pd.begin(), pd.end(), level.GetSummoner()[1].GetInfo().x + sizex * level.GetSummoner()[1].GetInfo().y) != pd.end()) {
                    gamestarted = true;
                    level.GetSummoner()[0].GetSchoolLevels().reset(level.GetSchoolList().size());
                    level.GetSummoner()[1].GetSchoolLevels().reset(level.GetSchoolList().size());
                    Play(window, CurrentScene, level);
                    return 0;
                }
                else {
                    wt.restart();
                    warning = true;
                    warningtext.setPosition(sizex * 40 - 400 * sizex / 19, sizey * 40 - 100);
                    warningtext.setFillColor(sf::Color(255,255,255,0));
                }
            }
        }
        else  menu3.setFillColor(sf::Color::White);


        //Dragging summoners
        if (summoner_drag == -1 && summoner0_sprite.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && event.type == sf::Event::MouseButtonPressed) {
                summoner_drag = 0;
            }
        }
        if (summoner_drag == -1 && summoner1_sprite.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && event.type == sf::Event::MouseButtonPressed) {
                summoner_drag = 1;
            }
        }
        if (summoner_drag == 0) {
            summoner0_sprite.setPosition(sf::Vector2f(sf::Mouse::getPosition(window)) - sf::Vector2f(40, 40));
            if (event.type == sf::Event::MouseButtonReleased) {
                if (0 <= sf::Mouse::getPosition(window).y && sf::Mouse::getPosition(window).y <= sizey * 80 && 0 <= sf::Mouse::getPosition(window).x && sf::Mouse::getPosition(window).x <= sizex * 80) {
                    if (level.GetCellType(sf::Mouse::getPosition(window).x / 80, sf::Mouse::getPosition(window).y / 80) == Summoners_Game::CellType::CELL_EMPTY) {
                        level.GetDungeon()[level.GetSummoner()[0].GetInfo().x + sizex * level.GetSummoner()[0].GetInfo().y] = new Summoners_Game::Cell(Summoners_Game::CellType::CELL_EMPTY);
                        level.GetDungeon()[sf::Mouse::getPosition(window).x / 80 + sizex * (sf::Mouse::getPosition(window).y / 80)] = new Summoners_Game::Cell_Summoner(&level.GetSummoner()[0]);
                        level.GetSummoner()[0].GetInfo().x = sf::Mouse::getPosition(window).x / 80;
                        level.GetSummoner()[0].GetInfo().y = sf::Mouse::getPosition(window).y / 80;
                    }
                }
                summoner_drag = -1;
            }
        }
        if (summoner_drag == 1) {
            summoner1_sprite.setPosition(sf::Vector2f(sf::Mouse::getPosition(window)) - sf::Vector2f(40, 40));
            if (event.type == sf::Event::MouseButtonReleased) {
                if (0 <= sf::Mouse::getPosition(window).y && sf::Mouse::getPosition(window).y <= sizey * 80 && 0 <= sf::Mouse::getPosition(window).x && sf::Mouse::getPosition(window).x <= sizex * 80) {
                    if (level.GetCellType(sf::Mouse::getPosition(window).x / 80, sf::Mouse::getPosition(window).y / 80) == Summoners_Game::CellType::CELL_EMPTY) {
                        level.GetDungeon()[level.GetSummoner()[1].GetInfo().x + sizex * level.GetSummoner()[1].GetInfo().y] = new Summoners_Game::Cell(Summoners_Game::CellType::CELL_EMPTY);
                        level.GetDungeon()[sf::Mouse::getPosition(window).x / 80 + sizex * (sf::Mouse::getPosition(window).y / 80)] = new Summoners_Game::Cell_Summoner(&level.GetSummoner()[1]);
                        level.GetSummoner()[1].GetInfo().x = sf::Mouse::getPosition(window).x / 80;
                        level.GetSummoner()[1].GetInfo().y = sf::Mouse::getPosition(window).y / 80;
                    }
                }
                summoner_drag = -1;
            }
        }

        event.type = sf::Event::MouseMoved;

        w_text.setString("Width: " + std::to_string(new_w));
        h_text.setString("Height: " + std::to_string(new_h));


        window.clear();
        //draw map
        for (int i = 0; i < level.GetDungeon().size(); i++) {
            x = i % sizex;
            y = i / sizex;
            ground_tile.setPosition(x * 80, y * 80);
            window.draw(ground_tile);
            if (level.GetCellType(x, y) == Summoners_Game::CellType::CELL_WALL) {
                wall_tile.setPosition(x * 80, y * 80);
                window.draw(wall_tile);
            }

 
            if (summoner_drag == -1 && level.GetCellType(x, y) == Summoners_Game::CellType::CELL_SUMMONER) {
                if ((static_cast<Summoners_Game::Cell_Summoner*>(level.GetDungeon()[i]))->Object == &level.GetSummoner()[0]) {
                    summoner0_sprite.setPosition(x * 80, y * 80);
                }
                else {
                    summoner1_sprite.setPosition(x * 80, y * 80);
                }
            }


            if (ground_tile.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
                hl.setPosition(x * 80, y * 80);
                window.draw(hl);
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && level.GetDungeon()[i]->Type == Summoners_Game::CellType::CELL_EMPTY && summoner_drag == -1) {
                    level.GetDungeon()[i] = new Summoners_Game::Cell(Summoners_Game::CellType::CELL_WALL);
                }
                else if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && level.GetDungeon()[i]->Type == Summoners_Game::CellType::CELL_WALL && summoner_drag == -1) {
                    level.GetDungeon()[i] = new Summoners_Game::Cell(Summoners_Game::CellType::CELL_EMPTY);
                }
            }
        }

        window.draw(summoner0_sprite);
        window.draw(summoner1_sprite);

        //draw buttons
        window.draw(menu1);
        window.draw(menu1_text);
        window.draw(menu2);
        window.draw(menu2_text);
        window.draw(menu3);
        window.draw(menu3_text);
        window.draw(menu4);
        window.draw(menu4_text);
        //draw size modifiers
        window.draw(w_text);
        window.draw(h_text);
        window.draw(wu);
        window.draw(wd);
        window.draw(hu);
        window.draw(hd);
        //Draw warning when one summoner can't reach the other
        if (warning && wt.getElapsedTime().asSeconds() < 5) {
            window.draw(warningtext);
            if (wt.getElapsedTime().asMilliseconds() < 500)
                warningtext.setFillColor(sf::Color(255,255,255,0) + sf::Color(0, 0, 0, wt.getElapsedTime().asMilliseconds() * 255 / 500));
            else
                warningtext.setFillColor(sf::Color::White - sf::Color(0, 0, 0, (wt.getElapsedTime().asMilliseconds()-500) * 255 / 4500));
        }
        else warning = false;

        window.display();
    }
}

int main()
{
    Summoners_Game::Level level;
    bool gamestarted = false;

    _mkdir("Save");
    _mkdir("Save/Maps");
    _mkdir("Save/Entities");

    int CurrentScene = 0;
    sf::ContextSettings settings;
    settings.antialiasingLevel = 4;
    sf::RenderWindow window(sf::VideoMode(1280,720), "Battle of summoners", sf::Style::Titlebar | sf::Style::Close, settings);
    window.setVerticalSyncEnabled(true);
    sf::Image icon;
    icon.loadFromFile("Resources/return_button0.png");
    window.setIcon(64, 64, icon.getPixelsPtr());
    window.setPosition(sf::Vector2i(320, 180));
    while (CurrentScene != -1) {
        switch (CurrentScene) {
        case 0: window.setVisible(true); MainScene(window, CurrentScene); break;
        case 1: window.setVisible(false); MapEditor(CurrentScene, level, gamestarted); break;
        case 2: SchoolManager(window, CurrentScene, level); break;
        case 3: SaveLoad(window, CurrentScene, level); break;
        }
    }
    return 0;
}