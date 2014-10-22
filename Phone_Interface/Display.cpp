#include "Display.h"
#include "Arial12x12.h"

Display::Display(int x, int y, int width, int height, Command *ctl, SeeedStudioTFTv2 *display){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->content = (char*) malloc(256 * sizeof(char));
    this->contentIndex = 0;
    this->controller = ctl;
    this->display = display;
    this->bgColor = Black;
    this->fgColor = White;
    this->bordorWidth = 4;
}
      
void Display::draw(){
    for(int i=0;i<bordorWidth;++i)
        display->rect(x+i,y+i,x+width-i,y+height-i,fgColor);
    display->fillrect(x+bordorWidth,y+bordorWidth,x+width-bordorWidth,y+height-bordorWidth,bgColor);
    
    display->locate(x+bordorWidth+5,y+bordorWidth+6);
    display->background(bgColor);
    display->foreground(fgColor);
    display->set_font((unsigned char*) Arial12x12);
    display->printf("%s\n",content);
    //display->character(x+(width/2)-6,y+(height/2)-6,);
}
void Display::sendInput(char *c){
    if(*c == '\b'){
        content[--contentIndex] = '\0';
    }else if(*c == 13){
        content[0] = '\0';
        contentIndex = 0;
    }else{
        content[contentIndex++] = *c;
        content[contentIndex] = '\0';
    }
    
    draw();
}

/*void Display::deleteInput(int n){
    if(n>contentIndex){
        contentIndex = 0;
        content[0] = '\0';
    }else{
        contentIndex -= n+1;
        content[++contentIndex] = '\0';
    }
    draw();
}*/