#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

class Menu
{

private:

    int Variable;

    enum MenuOptions
    {
        Resume,

        Exit,
    };


public:

    Menu();

    void goToMenu();

    void inMenu(int Variable);

    void exit();



};


#endif // MENU_H_INCLUDED
