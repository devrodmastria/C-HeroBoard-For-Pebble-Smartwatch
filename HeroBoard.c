/*
This is a Pebble app keyboard based on the game Guitar Hero. 
It is NOT a final product/watchapp. It is meant to be used with T3/T9 text prediction scripts. 
When completed, it could be implemented as an exclusive keyboard for Pebble. 
It was developed by rodrigo@mastria.com.br as part of the HackIllinois.org 2015
*/

#include <pebble.h> 
  
Window *window;
AppTimer *timer1;
const int delta = 7;   // defines the speed of the animation. 5 is faster and 10 is slower

TextLayer *ABC_layer;
const int ABC_layer_w = 144;
const int ABC_layer_h = 125; //85

TextLayer *ABC_layer2;
const int ABC_layer2_w = 144;
const int ABC_layer2_h = 125;

TextLayer *letter_layer;
const int letter_layer_w = 144;
const int letter_layer_h = 125;

int dx;
int dx2;
int dx3;

TextLayer *text_layer;
const int text_layer_w = 144;
const int text_layer_h = 20;



static void up_click_handler(ClickRecognizerRef recognizer, void * context) {
  
    GRect current = layer_get_frame(text_layer_get_layer(ABC_layer));
    GRect current2 = layer_get_frame(text_layer_get_layer(ABC_layer2));
  
///////////////////////////////// display respective letters
    if (current.origin.x < 40 && current.origin.x > 13)
      {
 //   layer_set_hidden((Layer *)letter_layer, false); 
    text_layer_set_text(letter_layer, "A B C"); //square box that covers the animation and show the letters
  }
  
  if (current2.origin.x < 40 && current2.origin.x > 13)
    {
    text_layer_set_text(letter_layer, "A B C");
    
  }
  
  if (current.origin.x < 83 && current.origin.x > 60)
    {
      text_layer_set_text(text_layer, "J K L");
  }
  
  if (current2.origin.x < 83 && current2.origin.x > 60)
    {
      text_layer_set_text(text_layer, "J K L");
  }
  
  if (current.origin.x < 140 && current.origin.x > 110)
    {
      text_layer_set_text(text_layer, "S T U");
  }
  
  if (current2.origin.x < 140 && current2.origin.x > 110)
    {
      text_layer_set_text(text_layer, "S T U");
  }
  
}

static void select_click_handler(ClickRecognizerRef recognizer, void * context) {
 //////////////////////////////// analyze layer current position
    GRect current = layer_get_frame(text_layer_get_layer(ABC_layer));
    GRect current2 = layer_get_frame(text_layer_get_layer(ABC_layer2));
///////////////////////////////// display respective 
  
  if (current.origin.x < 40 && current.origin.x > 13)
    {
      text_layer_set_text(text_layer, "D E F");
  }
  
  if (current2.origin.x < 40 && current2.origin.x > 13)
    {
      text_layer_set_text(text_layer, "D E F");
  }
  
    if (current.origin.x < 83 && current.origin.x > 50)
    {
      text_layer_set_text(text_layer, "M N O");
  }
  
  if (current2.origin.x < 83 && current2.origin.x > 50)
    {
      text_layer_set_text(text_layer, "M N O");
  }
  
    if (current.origin.x < 140 && current.origin.x > 100)
    {
      text_layer_set_text(text_layer, "V W X");
  }
  
  if (current2.origin.x < 140 && current2.origin.x > 100)
    {
      text_layer_set_text(text_layer, "V W X");
  }

}

static void down_click_handler(ClickRecognizerRef recognizer, void * context) {
    
  
    GRect current = layer_get_frame(text_layer_get_layer(ABC_layer));
    GRect current2 = layer_get_frame(text_layer_get_layer(ABC_layer2));
////////////////////////////////////////////////////////////////////////////// display respective letter block
  if (current.origin.x < 40 && current.origin.x > 13)
    {
      text_layer_set_text(text_layer, "G H I");
  }
  
  if (current2.origin.x < 40 && current2.origin.x > 13)
    {
      text_layer_set_text(text_layer, "G H I");
  }
  
    if (current.origin.x < 83 && current.origin.x > 45)
    {
      text_layer_set_text(text_layer, "P Q R"); //  S
  }
  
  if (current2.origin.x < 83 && current2.origin.x > 45)
    {
      text_layer_set_text(text_layer, "P Q R");
  }
  
    if (current.origin.x < 140 && current.origin.x > 90)
    {
      text_layer_set_text(text_layer, "Y Z [space]"); 
  }
  
  if (current2.origin.x < 140 && current2.origin.x > 90)
    {
      text_layer_set_text(text_layer, "Y Z [space]");
  }
  
}

static void click_config_provider(void *context) {
  window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler);
  window_single_click_subscribe(BUTTON_ID_UP, up_click_handler);
  window_single_click_subscribe(BUTTON_ID_DOWN, down_click_handler);
}

void timer_callback(void *data) {
    //Get current position
    GRect current = layer_get_frame(text_layer_get_layer(ABC_layer));
    GRect current2 = layer_get_frame(text_layer_get_layer(ABC_layer2));
    //    GRect current3 = layer_get_frame(text_layer_get_layer(intro_layer));
 

    if (current.origin.x < 144)
    {
      
        dx = 1;
         
    }
    else if (current.origin.x > 143)
    {
        current.origin.x = -144;
        dx = 1;
    }
    
    if (current2.origin.x <144)
      {
      dx2 = 1;
    }
    else if(current2.origin.x > 143)
      {
      current2.origin.x = -144;
      dx2 = 1;
    }
  
    //Move the square to the next position, modifying the x value
    GRect next = GRect(current.origin.x + dx, current.origin.y, ABC_layer_w, ABC_layer_h);
    layer_set_frame(text_layer_get_layer(ABC_layer), next);
  
    GRect next2 = GRect(current2.origin.x + dx2, current2.origin.y, ABC_layer2_w, ABC_layer2_h);
    layer_set_frame(text_layer_get_layer(ABC_layer2), next2);
    
    //Register next execution
    timer1 = app_timer_register(delta, (AppTimerCallback) timer_callback, NULL);
}

void window_load(Window *window)
{ 

  
  
  ABC_layer = text_layer_create(GRect(-72, 0, ABC_layer_w, ABC_layer_h));  //-72 x origin , set it to 0 and comment out the timer1 line (234) to see the static image on the watch
  text_layer_set_background_color(ABC_layer, GColorClear);
  text_layer_set_text_color(ABC_layer, GColorBlack);
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(ABC_layer));
  text_layer_set_text(ABC_layer, " STU     JKL    ABC\n\n VWX    MNO    DEF\n\n YZ_     PQR    GHI");
  text_layer_set_font(ABC_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  text_layer_set_text_alignment(ABC_layer, GTextAlignmentLeft);
  
  ABC_layer2 = text_layer_create(GRect(-216, 0, ABC_layer2_w, ABC_layer2_h));
  text_layer_set_background_color(ABC_layer2, GColorClear);
  text_layer_set_text_color(ABC_layer2, GColorBlack);
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(ABC_layer2));
  text_layer_set_text(ABC_layer2, " STU     JKL    ABC\n\n VWX    MNO    DEF\n\n YZ_     PQR    GHI");
  text_layer_set_font(ABC_layer2, fonts_get_system_font(FONT_KEY_GOTHIC_24_BOLD));
  text_layer_set_text_alignment(ABC_layer2, GTextAlignmentLeft);
  
  text_layer = text_layer_create(GRect(0, 132, text_layer_w, text_layer_h));
  text_layer_set_background_color(text_layer, GColorBlack);
  text_layer_set_text_color(text_layer, GColorWhite);
  text_layer_set_text(text_layer, "Type Like Guitar Hero");
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(text_layer));
  text_layer_set_text_alignment(text_layer, GTextAlignmentCenter);
/*  
  letter_layer = text_layer_create(GRect(0, 0, letter_layer_w, letter_layer_h));
  text_layer_set_background_color(text_layer, GColorBlack);
  text_layer_set_text_color(text_layer, GColorWhite);
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(text_layer));
  text_layer_set_text_alignment(text_layer, GTextAlignmentCenter);
  layer_set_hidden((Layer *)letter_layer, true);
*/
  
 timer1 = app_timer_register(delta, (AppTimerCallback) timer_callback, NULL);

}



void window_unload(Window *window)
{

  //Cancel timer
app_timer_cancel(timer1);
 
//Destroy square layer
text_layer_destroy(ABC_layer);
text_layer_destroy(ABC_layer2);
text_layer_destroy(text_layer);
  
}

void init()
{
 
      //Initialize the app elements here!
  window = window_create();
  
  window_set_click_config_provider(window, click_config_provider);
  
  window_set_window_handlers(window, (WindowHandlers) { .load = window_load, .unload = window_unload, } );
    
  window_stack_push(window, true);

}
 
void deinit()
{
  //De-initialize elements here to save memory!

  window_destroy(window);

}

int main(void)
{
  init();
  app_event_loop();
  deinit();
}
