/*
This is a Pebble app keyboard based on the game Guitar Hero. 
It is a semi-ready watchapp. When completed, it could be implemented as an exclusive keyboard for Pebble. 
It was developed by rodrigo@mastria.com.br as part of the HackIllinois.org 2015
*/
#include <pebble.h>
  
Window *window;
AppTimer *timer1;
const int delta = 6;   // defines the speed of the animation. 5 is faster and 10 is slower

TextLayer *ABC_layer;
const int ABC_layer_w = 144; //144
const int ABC_layer_h = 168; //124

TextLayer *ABC_layer2;

int dx;
int dx2;
int dx3;

TextLayer *text_layer;
const int text_layer_w = 144;
const int text_layer_h = 32;

TextLayer *instruction_layer;
const int instruction_layer_w = 144;
const int instruction_layer_h = 32;

char *lettersText = "Q W E R T Y U I O P\n\n\n\nA S D F G H J K L ?\n\n\n\nZ X C V B N M  ,  .";
char *fontText = FONT_KEY_GOTHIC_18_BOLD;

char *initial_message = "";
char *final_message = "";
// name_with_extension = malloc(strlen(name)+1+4); /* make space for the new string (should check the return value ...) */
// strcpy(name_with_extension, name); /* copy name into the new var */
// strcat(name_with_extension, extension); /* add the extension

char *itoa(int num)
{
  static char buff[20] = {};
  int i = 0, temp_num = num, length = 0;
  char *string = buff;
  if(num >= 0) {
    // count how many characters in the number
    while(temp_num) {
    temp_num /= 10;
    length++;
    }
    // assign the number to the buffer starting at the end of the 
    // number and going to the begining since we are doing the
    // integer to character conversion on the last number in the
    // sequence
    for(i = 0; i < length; i++) {
      buff[(length-1)-i] = '0' + (num % 10);
      num /= 10;
    }
    buff[i] = '\0'; // can't forget the null byte to properly end our string
  }
  else
    return "Unsupported Number";
  return string;
}


void setLetter (char *letter){
  
  final_message = malloc(strlen(initial_message)+1+1); /* make space for the new string (should check the return value ...) */
  strcpy(final_message, initial_message); //copy name into the new var
  strcat(final_message, letter); /* add the extension */
  initial_message = final_message;
  text_layer_set_text(text_layer, final_message);
  
}

static void up_click_handler(ClickRecognizerRef recognizer, void * context) {
  
  GRect current = layer_get_frame(text_layer_get_layer(ABC_layer));
  GRect current2 = layer_get_frame(text_layer_get_layer(ABC_layer2));
  
///////////////////////////////// map respective letters
  
  int a = current.origin.x;
  if (a > 118)
    setLetter("q");
  else if (a > 102)
    setLetter("w");
  else if (a > 90)
    setLetter("e");
  else if (a > 77)
    setLetter("r");
  else if (a > 65)
    setLetter("t");
  else if (a > 51)
    setLetter("y");
  else if (a > 38)
    setLetter("u");
  else if (a > 30)
    setLetter("i");
  else if (a > 17)
    setLetter("o");
  else if (a > 0)
    setLetter("p");
    
  
  
  int a2 = current.origin.x;
  if (a2 > 118)
    setLetter("q");
  else if (a2 > 102)
    setLetter("w");
  else if (a2 > 90)
    setLetter("e");
  else if (a2 > 77)
    setLetter("r");
  else if (a2 > 65)
    setLetter("t");
  else if (a2 > 51)
    setLetter("y");
  else if (a2 > 38)
    setLetter("u");
  else if (a2 > 30)
    setLetter("i");
  else if (a2 > 17)
    setLetter("o");
  else if (a2 > 0)
    setLetter("p");
  
}

static void select_click_handler(ClickRecognizerRef recognizer, void * context) {
  
 //////////////////////////////// analyze layer current position
  GRect current = layer_get_frame(text_layer_get_layer(ABC_layer));
  GRect current2 = layer_get_frame(text_layer_get_layer(ABC_layer2));
///////////////////////////////// display respective 
  
 
  int a = current.origin.x;
  if (a > 116)
    setLetter("a");
  else if (a > 103)
    setLetter("s");
  else if (a > 90)
    setLetter("d");    
  else if (a > 78)
    setLetter("f");
  else if (a > 65)
    setLetter("g");
  else if (a > 52)
    setLetter("h");
  else if (a > 41)
    setLetter("j");
  else if (a > 29)
    setLetter("k");    
  else if (a > 17)
    setLetter("l");   
  else if (a > 0)
    setLetter("?");

  int a2 = current2.origin.x;
  if (a2 > 116)
    setLetter("a");
  else if (a2 > 103)
    setLetter("s");
  else if (a2 > 90)
    setLetter("d");    
  else if (a2 > 78)
    setLetter("f");
  else if (a2 > 65)
    setLetter("g");
  else if (a2 > 52)
    setLetter("h");
  else if (a2 > 41)
    setLetter("j");
  else if (a2 > 29)
    setLetter("k");    
  else if (a2 > 17)
    setLetter("l");   
  else if (a2 > 0)
    setLetter("?");

}

static void down_click_handler(ClickRecognizerRef recognizer, void * context) {
  
  GRect current = layer_get_frame(text_layer_get_layer(ABC_layer));
  GRect current2 = layer_get_frame(text_layer_get_layer(ABC_layer2));
////////////////////////////////////////////////////////////////////////////// display respective letter block
 
  int a = current.origin.x;
  if (a > 115)
    setLetter("z");
  else if (a > 101)
    setLetter("x");
  else if (a > 88)
    setLetter("c");
  else if (a > 75)
    setLetter("v");
  else if (a > 62)
    setLetter("b");
  else if (a > 49)
    setLetter("n");
  else if (a > 29)
    setLetter("m");
  else if (a > 17)
    setLetter(",");
  else if (a > 0)
    setLetter(".");
    
  int a2 = current2.origin.x;
  if (a2 > 115)
    setLetter("z");
  else if (a2 > 101)
    setLetter("x");
  else if (a2 > 88)
    setLetter("c");
  else if (a2 > 75)
    setLetter("v");
  else if (a2 > 62)
    setLetter("b");
  else if (a2 > 49)
    setLetter("n");
  else if (a2 > 29)
    setLetter("m");
  else if (a2 > 17)
    setLetter(",");
  else if (a2 > 0)
    setLetter(".");
   
}

static void long_down_click_handler(ClickRecognizerRef recognizer, void * context) {
  
  final_message = malloc(strlen(initial_message)+1+1); /* make space for the new string (should check the return value ...) */
  strcpy(final_message, initial_message); //copy name into the new var
  strcat(final_message, " "); /* add the extension */
  initial_message = final_message;
  text_layer_set_text(text_layer, final_message);
  
}

static void long_up_click_handler(ClickRecognizerRef recognizer, void * context) {
  
  initial_message = "";
  text_layer_set_text(text_layer, initial_message);
  
}


static void long_select_click_handler(ClickRecognizerRef recognizer, void * context) {
  
  // confirm message / send to someone
  
}

static void long_back_click_handler(ClickRecognizerRef recognizer, void * context) {
  
    GRect current = layer_get_frame(text_layer_get_layer(ABC_layer));
    GRect current2 = layer_get_frame(text_layer_get_layer(ABC_layer2));

    if (current.origin.x < ABC_layer_w)
    {
        dx = 1;
    }
    else if (current.origin.x > ABC_layer_w - 1)
    {
        current.origin.x = -ABC_layer_w;
        dx = 1;
    }
    
    if (current2.origin.x <ABC_layer_w)
      {
      dx2 = 1;
    }
    else if(current2.origin.x > ABC_layer_w - 1)
      {
      current2.origin.x = -ABC_layer_w;
      dx2 = 1;
    }
  
    //Move the square to the next position, modifying the x value
    GRect next = GRect(current.origin.x + dx, current.origin.y, ABC_layer_w, ABC_layer_h);
    layer_set_frame(text_layer_get_layer(ABC_layer), next);
  
    GRect next2 = GRect(current2.origin.x + dx2, current2.origin.y, ABC_layer_w, ABC_layer_h);
    layer_set_frame(text_layer_get_layer(ABC_layer2), next2);
  
    if (current.origin.x >= 0)
      text_layer_set_text(instruction_layer, itoa(current.origin.x));
    if (current2.origin.x >= 0)
      text_layer_set_text(instruction_layer, itoa(current2.origin.x));
  
}

static void click_config_provider(void *context) {
  window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler);
  window_single_click_subscribe(BUTTON_ID_UP, up_click_handler);
  window_single_click_subscribe(BUTTON_ID_DOWN, down_click_handler);
  
  window_long_click_subscribe(BUTTON_ID_DOWN, 0, long_down_click_handler, NULL); // space
  window_long_click_subscribe(BUTTON_ID_UP, 0, long_up_click_handler, NULL); // delete
//   window_long_click_subscribe(BUTTON_ID_SELECT, 0, long_select_click_handler, NULL); // confirm
//   window_long_click_subscribe(BUTTON_ID_DOWN, 0, long_back_click_handler, NULL); // move banner manually
  
}

void timer_callback(void *data) {
    //Get current position
    GRect current = layer_get_frame(text_layer_get_layer(ABC_layer));
    GRect current2 = layer_get_frame(text_layer_get_layer(ABC_layer2));

    if (current.origin.x < ABC_layer_w)
    {
        dx = 1;
    }
    else if (current.origin.x > ABC_layer_w - 1)
    {
        current.origin.x = -ABC_layer_w;
        dx = 1;
    }
    
    if (current2.origin.x <ABC_layer_w)
      {
      dx2 = 1;
    }
    else if(current2.origin.x > ABC_layer_w - 1)
      {
      current2.origin.x = -ABC_layer_w;
      dx2 = 1;
    }
  
    //Move the square to the next position, modifying the x value
    GRect next = GRect(current.origin.x + dx, current.origin.y, ABC_layer_w, ABC_layer_h);
    layer_set_frame(text_layer_get_layer(ABC_layer), next);
  
    GRect next2 = GRect(current2.origin.x + dx2, current2.origin.y, ABC_layer_w, ABC_layer_h);
    layer_set_frame(text_layer_get_layer(ABC_layer2), next2);
    
    //Register next execution
    timer1 = app_timer_register(delta, (AppTimerCallback) timer_callback, NULL);
}

void window_load(Window *window)
{ 
  
  ABC_layer = text_layer_create(GRect(-72, 0, ABC_layer_w, ABC_layer_h));  //-72 x origin , set it to 0 and comment out the timer1 line (312) to see the static image on the watch
  text_layer_set_background_color(ABC_layer, GColorClear);
  text_layer_set_text_color(ABC_layer, GColorBlack);
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(ABC_layer));
  text_layer_set_text(ABC_layer, lettersText);
  text_layer_set_font(ABC_layer, fonts_get_system_font(fontText));
  text_layer_set_text_alignment(ABC_layer, GTextAlignmentCenter);
  
  ABC_layer2 = text_layer_create(GRect(-216, 0, ABC_layer_w, ABC_layer_h));
  text_layer_set_background_color(ABC_layer2, GColorClear);
  text_layer_set_text_color(ABC_layer2, GColorBlack);
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(ABC_layer2));
  text_layer_set_text(ABC_layer2, lettersText);
  text_layer_set_font(ABC_layer2, fonts_get_system_font(fontText));
  text_layer_set_text_alignment(ABC_layer2, GTextAlignmentCenter);
  
  text_layer = text_layer_create(GRect(0, 30, text_layer_w, text_layer_h));
  text_layer_set_background_color(text_layer, GColorBlack);
  text_layer_set_text_color(text_layer, GColorWhite);
  text_layer_set_font(text_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24));
  text_layer_set_text(text_layer, "Your message");
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(text_layer));
  text_layer_set_text_alignment(text_layer, GTextAlignmentCenter);
  
  instruction_layer = text_layer_create(GRect(0, 105, instruction_layer_w, instruction_layer_h));
  text_layer_set_background_color(instruction_layer, GColorBlack);
  text_layer_set_text_color(instruction_layer, GColorWhite);
  text_layer_set_font(instruction_layer, fonts_get_system_font(FONT_KEY_GOTHIC_24));
  text_layer_set_text(instruction_layer, "Hello World");
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(instruction_layer));
  text_layer_set_text_alignment(instruction_layer, GTextAlignmentCenter);
  
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
  window_destroy(window);
}

int main(void)
{
  init();
  app_event_loop();
  deinit();
}
