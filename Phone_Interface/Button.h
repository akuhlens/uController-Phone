#ifndef Button_h
#define Button_h
#include "mbed.h"
#include "UserInterface.h"
#include "SeeedStudioTFTv2.h"
#include "Command.h"

class Button: public Touchable, public Drawable{
    protected:
    // these two is very hacky and needs removed
      Command          *controller; 
      SeeedStudioTFTv2 *display; 
      int x, y, width, height, bordorWidth, bgColor, fgColor;
      char* label;

    public:
      virtual void touch(point& p) = 0;
      virtual void draw();
      Button(int x, int y, int width, int height, char* label, Command *ctl, SeeedStudioTFTv2 *display);
};

class CharButton: public Button {
    private:
     char value;
     char* subValue;
    public:
     virtual void touch(point& p);
     virtual void draw();
     CharButton(int x, int y, int width, int height, char* label, char value, char *subValue, Command *ctl, SeeedStudioTFTv2 *display);
};

class CommandButton: public Button {
    private:
      commands command;
    public:
      virtual void touch(point& p);
      CommandButton(int x, int y, int width, int height, commands cmd, char* label, Command *ctl, SeeedStudioTFTv2 *display);
};
#endif
