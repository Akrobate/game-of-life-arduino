#include "U8glib/U8glib.h"
#include "GameOfLife.h"
#define backlight_pin 10

//U8GLIB_PCD8544 u8g(8, 4, 7, 5, 6);  // CLK=8, DIN=4, CE=7, DC=5, RST=6
// CLK=8, DIN=4, CE=7, DC=5, RST=6
U8GLIB_PCD8544 u8g(8, 7, 5, 6, 4);
GameOfLife gol;
// GameOfLife * gol = new GameOfLife();

int count = 0;

void draw() {

    gol.initWorld(count++);
    for (int i = 0; i < SIZE_X; i++) {
        for (int j = 0; j < SIZE_Y; j++) {
            if(gol.checkCell(i, j, gol.world)) {
                u8g.drawPixel(i,j);
            }
        }
    }

    //delay(100);




    /*
u8g.setFont(u8g_font_baby);  // select font
String list[8] = {"ZZZZAbc fdfsd", "Lorem ipsum", "sic amet", "solorit", "solorit", "Lorem ipsum", "aRTIOM", "lYNDA"};
u8g.setFont(u8g_font_baby);  // select font
for(int i = 0; i < 8; i++) {
    u8g.drawStr(0, 6 + (i*6), list[i].c_str());
}
*/
    /*
    u8g.setPrintPos(15, 15);  // set position
    u8g.print(10, 0);  // display temperature from DHT11
    u8g.drawStr(30, 15, "c ");
    u8g.setPrintPos(15, 35);
    u8g.print(10, 0);  // display humidity from DHT11
    u8g.drawStr(30, 35, "% ");
    */
}

void setup(void) {
  analogWrite(backlight_pin, 200);  /* Set the Backlight intensity */
  u8g.setContrast(125);
  gol.initWorld(0);
}

void loop(void) {
  u8g.firstPage();
  do {
    draw();
  } while( u8g.nextPage() );
  //delay(100);  // Delay of 5sec before accessing DHT11 (min - 2sec)
}
