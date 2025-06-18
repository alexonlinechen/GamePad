//https://github.com/blackketter/ESP32-BLE-Combo/tree/master

//使用ESP32 

#include <BleCombo.h>

#define BTN_1 21      // Pin button is attached to
#define BTN_2 19
#define BTN_3 18
#define BTN_4 5
#define BTN_5 17
#define BTN_6 16

#define BTN_up 23
#define BTN_down 22
#define BTN_left 3
#define BTN_right 1

#define BTN_leftside 4
#define BTN_rightside 15

int Mode = 1;    // 1(鍵盤方向鍵) 2(鍵盤WASD)  3(滑鼠模式)


int old_BTN_1_State = HIGH;
int old_BTN_2_State = HIGH;
int old_BTN_3_State = HIGH;
int old_BTN_4_State = HIGH;
int old_BTN_5_State = HIGH;
int old_BTN_6_State = HIGH;

int old_BTN_up_State = HIGH;
int old_BTN_down_State = HIGH;
int old_BTN_left_State = HIGH;
int old_BTN_right_State = HIGH;

int old_BTN_leftside_State = HIGH;
int old_BTN_rightside_State = HIGH;


void setup()
{
    
     
     pinMode(BTN_1, INPUT_PULLUP);
     pinMode(BTN_2, INPUT_PULLUP);
     pinMode(BTN_3, INPUT_PULLUP);
     pinMode(BTN_4, INPUT_PULLUP);
     pinMode(BTN_5, INPUT_PULLUP);
     pinMode(BTN_6, INPUT_PULLUP);

     pinMode(BTN_up, INPUT_PULLUP);
     pinMode(BTN_down, INPUT_PULLUP);
     pinMode(BTN_left, INPUT_PULLUP);
     pinMode(BTN_right, INPUT_PULLUP);

     pinMode(BTN_leftside, INPUT_PULLUP);
     pinMode(BTN_rightside, INPUT_PULLUP);
          
      Keyboard.begin();
      Mouse.begin();
     
     Serial.begin(115200);     
  
}




 void loop()
{
  KeyMode();
  if (Mode == 1)keyboard();
  if (Mode == 2)keyboard_WASD();
  if (Mode == 3)mouse();
    //delay(100);   
}





void KeyMode(){
            int now_BTN_1_State = digitalRead(BTN_1);
            int now_BTN_2_State = digitalRead(BTN_2);
            int now_BTN_3_State = digitalRead(BTN_3);
            int now_BTN_4_State = digitalRead(BTN_4);
 if (now_BTN_1_State == LOW && now_BTN_2_State == LOW && now_BTN_3_State == LOW && now_BTN_4_State == LOW){

  Mode++;

  if(Mode>=4)Mode=1; 
  Serial.print("Mode:");
  Serial.println(Mode);
  delay(2000);
  
 }  
}




  void keyboard(){

   if (Keyboard.isConnected())
    {    
            int now_BTN_1_State = digitalRead(BTN_1);
            int now_BTN_2_State = digitalRead(BTN_2);
            int now_BTN_3_State = digitalRead(BTN_3);
            int now_BTN_4_State = digitalRead(BTN_4);
            int now_BTN_5_State = digitalRead(BTN_5);
            int now_BTN_6_State = digitalRead(BTN_6);

            int now_BTN_up_State = digitalRead(BTN_up);
            int now_BTN_down_State = digitalRead(BTN_down);
            int now_BTN_left_State = digitalRead(BTN_left);
            int now_BTN_right_State = digitalRead(BTN_right);

            int now_BTN_leftside_State = digitalRead(BTN_leftside);
            int now_BTN_rightside_State = digitalRead(BTN_rightside);
            

        if (now_BTN_1_State != old_BTN_1_State)
        {
            if (now_BTN_1_State == LOW){Keyboard.press(KEY_ESC); Serial.println("ESC"); }
                else{Keyboard.release(KEY_ESC);}
             }

        if (now_BTN_2_State != old_BTN_2_State)
        {
            if (now_BTN_2_State == LOW){Keyboard.press(KEY_RETURN); Serial.println("ENTER"); }
            else{Keyboard.release(KEY_RETURN);}
        }

        if (now_BTN_3_State != old_BTN_3_State)
        {
            if (now_BTN_3_State == LOW){Keyboard.press(KEY_BACKSPACE); Serial.println("BTN3");}
            else{Keyboard.release(KEY_BACKSPACE);}
        }

        if (now_BTN_4_State != old_BTN_4_State)
        {
            if (now_BTN_4_State == LOW){Keyboard.press(KEY_END);Serial.println("BTN4");}
              else{Keyboard.release(KEY_END);}
        }

        if (now_BTN_5_State != old_BTN_5_State)
        {
            if (now_BTN_5_State == LOW){Keyboard.press(KEY_PAGE_UP);Serial.println("BTN5");}
            else{Keyboard.release(KEY_PAGE_UP);}
        }

        if (now_BTN_6_State != old_BTN_6_State)
        {
            if (now_BTN_6_State == LOW){Keyboard.press(KEY_PAGE_DOWN);Serial.println("BTN6");}
            else{Keyboard.release(KEY_PAGE_DOWN);}
        }

        if (now_BTN_up_State != old_BTN_up_State)
        {
            if (now_BTN_up_State == LOW){Keyboard.press(KEY_UP_ARROW);Serial.println("BTN-上");}
            else{Keyboard.release(KEY_UP_ARROW);}
        }

        if (now_BTN_down_State != old_BTN_down_State)
        {
            if (now_BTN_down_State == LOW){Keyboard.press(KEY_DOWN_ARROW);Serial.println("BTN-下");}
            else{Keyboard.release(KEY_DOWN_ARROW);}
        }

       if (now_BTN_left_State != old_BTN_left_State)
        {
            if (now_BTN_left_State == LOW){Keyboard.press(KEY_LEFT_ARROW);Serial.println("BTN-左");}
            else{Keyboard.release(KEY_LEFT_ARROW);}
        }

        if (now_BTN_right_State != old_BTN_right_State)
        {
            if (now_BTN_right_State == LOW){Keyboard.press(KEY_RIGHT_ARROW);Serial.println("BTN-Right");}
            else{Keyboard.release(KEY_RIGHT_ARROW);}
        }

 
       
       if (now_BTN_leftside_State != old_BTN_leftside_State)
        {
            if (now_BTN_leftside_State == LOW){Keyboard.press(KEY_LEFT_SHIFT);Serial.println("BTN-左側");}
            else{Keyboard.release(KEY_LEFT_SHIFT);}
        }


        
        if (now_BTN_rightside_State != old_BTN_rightside_State)
        {
            if (now_BTN_rightside_State == LOW){Keyboard.press(KEY_RIGHT_SHIFT);Serial.println("BTN-右側");}
            else{Keyboard.release(KEY_RIGHT_SHIFT);}
        }


        old_BTN_1_State = now_BTN_1_State;
        old_BTN_2_State = now_BTN_2_State;
        old_BTN_3_State = now_BTN_3_State;
        old_BTN_4_State = now_BTN_4_State;
        old_BTN_5_State = now_BTN_5_State;
        old_BTN_6_State = now_BTN_6_State;

        old_BTN_up_State = now_BTN_up_State;
        old_BTN_down_State = now_BTN_down_State;
        old_BTN_left_State = now_BTN_left_State;
        old_BTN_right_State = now_BTN_right_State;

        old_BTN_leftside_State = now_BTN_leftside_State;
        old_BTN_rightside_State = now_BTN_rightside_State;

        
    }
    delay(10);

  }




  void keyboard_WASD(){

   if (Keyboard.isConnected())
    {    
            int now_BTN_1_State = digitalRead(BTN_1);
            int now_BTN_2_State = digitalRead(BTN_2);
            int now_BTN_3_State = digitalRead(BTN_3);
            int now_BTN_4_State = digitalRead(BTN_4);
            int now_BTN_5_State = digitalRead(BTN_5);
            int now_BTN_6_State = digitalRead(BTN_6);

            int now_BTN_up_State = digitalRead(BTN_up);
            int now_BTN_down_State = digitalRead(BTN_down);
            int now_BTN_left_State = digitalRead(BTN_left);
            int now_BTN_right_State = digitalRead(BTN_right);

            int now_BTN_leftside_State = digitalRead(BTN_leftside);
            int now_BTN_rightside_State = digitalRead(BTN_rightside);
            

        if (now_BTN_1_State != old_BTN_1_State)
        {
            if (now_BTN_1_State == LOW){Keyboard.press(KEY_ESC); Serial.println("ESC"); }
                else{Keyboard.release(KEY_ESC);}
             }

        if (now_BTN_2_State != old_BTN_2_State)
        {
            if (now_BTN_2_State == LOW){Keyboard.press(KEY_RETURN); Serial.println("ENTER"); }
            else{Keyboard.release(KEY_RETURN);}
        }

        if (now_BTN_3_State != old_BTN_3_State)
        {
            if (now_BTN_3_State == LOW){Keyboard.press(KEY_BACKSPACE); Serial.println("BTN3");}
            else{Keyboard.release(KEY_BACKSPACE);}
        }

        if (now_BTN_4_State != old_BTN_4_State)
        {
            if (now_BTN_4_State == LOW){Keyboard.press(KEY_END);Serial.println("BTN4");}
              else{Keyboard.release(KEY_END);}
        }

        if (now_BTN_5_State != old_BTN_5_State)
        {
            if (now_BTN_5_State == LOW){Keyboard.press(KEY_PAGE_UP);Serial.println("BTN5");}
            else{Keyboard.release(KEY_PAGE_UP);}
        }

        if (now_BTN_6_State != old_BTN_6_State)
        {
            if (now_BTN_6_State == LOW){Keyboard.press(KEY_PAGE_DOWN);Serial.println("BTN6");}
            else{Keyboard.release(KEY_PAGE_DOWN);}
        }

        if (now_BTN_up_State != old_BTN_up_State)
        {
            if (now_BTN_up_State == LOW){Keyboard.write('W');Serial.println("BTN-上(W)");}
          
        }

        if (now_BTN_down_State != old_BTN_down_State)
        {
            if (now_BTN_down_State == LOW){Keyboard.write('S');Serial.println("BTN-下(S)");}
           
        }

       if (now_BTN_left_State != old_BTN_left_State)
        {
            if (now_BTN_left_State == LOW){Keyboard.write('A');Serial.println("BTN-左(A)");}
            else{Keyboard.release(KEY_LEFT_ARROW);}
        }

        if (now_BTN_right_State != old_BTN_right_State)
        {
            if (now_BTN_right_State == LOW){Keyboard.write('D');Serial.println("BTN-Right(D)");}
     
        }

 
       
       if (now_BTN_leftside_State != old_BTN_leftside_State)
        {
            if (now_BTN_leftside_State == LOW){Keyboard.press(KEY_LEFT_SHIFT);Serial.println("BTN-左側");}
            else{Keyboard.release(KEY_LEFT_SHIFT);}
        }


        
        if (now_BTN_rightside_State != old_BTN_rightside_State)
        {
            if (now_BTN_rightside_State == LOW){Keyboard.press(KEY_RIGHT_SHIFT);Serial.println("BTN-右側");}
            else{Keyboard.release(KEY_RIGHT_SHIFT);}
        }


        old_BTN_1_State = now_BTN_1_State;
        old_BTN_2_State = now_BTN_2_State;
        old_BTN_3_State = now_BTN_3_State;
        old_BTN_4_State = now_BTN_4_State;
        old_BTN_5_State = now_BTN_5_State;
        old_BTN_6_State = now_BTN_6_State;

        old_BTN_up_State = now_BTN_up_State;
        old_BTN_down_State = now_BTN_down_State;
        old_BTN_left_State = now_BTN_left_State;
        old_BTN_right_State = now_BTN_right_State;

        old_BTN_leftside_State = now_BTN_leftside_State;
        old_BTN_rightside_State = now_BTN_rightside_State;

        
    }
    delay(10);

  }




void mouse(){

   if (Keyboard.isConnected()){
           // int now_BTN_leftside_State = digitalRead(BTN_leftside);
            int now_BTN_1_State = digitalRead(BTN_1);
            int now_BTN_3_State = digitalRead(BTN_3);
            int now_BTN_4_State = digitalRead(BTN_4);
            int now_BTN_up_State = digitalRead(BTN_up);
            int now_BTN_down_State = digitalRead(BTN_down);
            int now_BTN_left_State = digitalRead(BTN_left);
            int now_BTN_right_State = digitalRead(BTN_right);
            
            
            if (now_BTN_3_State == LOW)Mouse.click(MOUSE_LEFT);

            if (now_BTN_4_State == LOW)Mouse.click(MOUSE_RIGHT);

            if (now_BTN_up_State == LOW)Mouse.move(0,-4);

            if (now_BTN_down_State == LOW)Mouse.move(0,4);
           
            if (now_BTN_left_State == LOW)Mouse.move(-4,0);
            
            if (now_BTN_right_State == LOW)Mouse.move(4,0);
          delay(10);
         
        }
   }

      
