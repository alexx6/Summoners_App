#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "../LAB3/LAB3_CODE/Summoners.h"

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
    menu1_text.setString(sf::String("Start game"));
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
    menu3_text.setString(sf::String("Save game"));
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

        if (menu1.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window))))
            menu1.setFillColor(sf::Color(151, 182, 255));
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

    sf::RectangleShape del_school(sf::Vector2f(15, 5));
    del_school.setFillColor(sf::Color::Red);
    del_school.setPosition(0, -100);

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

                        if (selected2 > 2) {
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
                                case 3:
                                    level.ModifySkill(level.GetSchoolList()[selected].SkillList[selected1].Name, level.GetSchoolList()[selected].Name).RequiredSchoolLevel = std::stoi(std::string(text.getString().toAnsiString()));
                                    vot2[selected2].setString(std::string("Required school level:             ") + std::to_string(level.GetSchoolList()[selected].SkillList[selected1].RequiredSchoolLevel));
                                    break;
                                case 4:
                                    level.ModifySkill(level.GetSchoolList()[selected].SkillList[selected1].Name, level.GetSchoolList()[selected].Name).MaxQuantity = std::stoi(std::string(text.getString().toAnsiString()));
                                    vot2[selected2].setString(std::string("Maximum quantity:                  ") + std::to_string(level.GetSchoolList()[selected].SkillList[selected1].MaxQuantity));
                                    break;
                                case 5:
                                    level.ModifySkill(level.GetSchoolList()[selected].SkillList[selected1].Name, level.GetSchoolList()[selected].Name).Entity_Parameters.Damage = std::stoi(std::string(text.getString().toAnsiString()));
                                    vot2[selected2].setString(std::string("Damage:                                    ") + std::to_string(level.GetSchoolList()[selected].SkillList[selected1].Entity_Parameters.Damage));
                                    break;
                                case 6:
                                    level.ModifySkill(level.GetSchoolList()[selected].SkillList[selected1].Name, level.GetSchoolList()[selected].Name).Entity_Parameters.Defense = std::stoi(std::string(text.getString().toAnsiString()));
                                    vot2[selected2].setString(std::string("Defense:                                    ") + std::to_string(level.GetSchoolList()[selected].SkillList[selected1].Entity_Parameters.Defense));
                                    break;
                                case 7:
                                    level.ModifySkill(level.GetSchoolList()[selected].SkillList[selected1].Name, level.GetSchoolList()[selected].Name).Entity_Parameters.MaxHealth = std::stoi(std::string(text.getString().toAnsiString()));
                                    vot2[selected2].setString(std::string("Maximum health:                     ") + std::to_string(level.GetSchoolList()[selected].SkillList[selected1].Entity_Parameters.MaxHealth));
                                    break;
                                case 8:
                                    level.ModifySkill(level.GetSchoolList()[selected].SkillList[selected1].Name, level.GetSchoolList()[selected].Name).Entity_Parameters.Speed = std::stoi(std::string(text.getString().toAnsiString()));
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
            del_school.setPosition(vot[selected].getPosition() + sf::Vector2f(vot[selected].getGlobalBounds().width - 3, vot[selected].getGlobalBounds().height + - 10));


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
    sf::Vector2f offset(190, 100);
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

    offset = menu1.getPosition() + sf::Vector2f(250, 400);
    sf::RectangleShape menu5(menu1);
    sf::Text menu5_text(menu1_text);
    menu5.setPosition(offset);
    menu5_text.setPosition(offset);
    menu5_text.setString("Load map");

    menu2_text.move(70, 20);
    menu3_text.move(50, 20);
    menu4_text.move(50, 20);
    menu5_text.move(75, 20);

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
                            level.SaveEntities(text.getString());
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
                        if (level.LoadEntities(text.getString())) return 0;
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

       //Load map
        if (menu5.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
            menu5.setFillColor(sf::Color(151, 182, 255));
            if (event.type == sf::Event::MouseButtonPressed) {

            }
        }
        else menu5.setFillColor(sf::Color::White);

        if (return_image.getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
            return_image.setColor(sf::Color(150, 150, 150));
            if (event.type == sf::Event::MouseButtonPressed) {
                CurrentScene = 0;
                return 0;
            }
        }
        else return_image.setColor(sf::Color::White);


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
        window.draw(menu5);
        window.draw(menu5_text);
        window.draw(return_image);
        window.display();
    }
}

int main()
{
    Summoners_Game::Level level;
    int CurrentScene = 0;
    sf::ContextSettings settings;
    settings.antialiasingLevel = 4;
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Battle of summoners", sf::Style::Titlebar | sf::Style::Close, settings);
    window.setVerticalSyncEnabled(true);
    sf::Image icon;
    icon.loadFromFile("Resources/return_button0.png");
    window.setIcon(64, 64, icon.getPixelsPtr());
    while (CurrentScene != -1) {
        switch (CurrentScene) {
        case 0: MainScene(window, CurrentScene); break;
        case 2: SchoolManager(window, CurrentScene, level); break;
        case 3: SaveLoad(window, CurrentScene, level); break;
        }
    }
    return 0;
}