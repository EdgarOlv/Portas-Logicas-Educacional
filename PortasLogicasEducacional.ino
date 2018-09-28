void setup()
{
  pinMode(13, OUTPUT);
}

void loop()
{
  digitalWrite(13, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(13, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}#include<Wire.h>
#include<LiquidCrystal_I2C.h>
int contador=0;
int contador2=0;

const int botao = 9;   //menu 1
const int botao2 = 5;  // entrada a 1
const int botao3 = 6;  //entrada b 1
const int botao4 = 8;  //menu 2
const int botao5 = 7;  //entrada 2

boolean troca =  false;
boolean troca1 = false;
boolean troca2 = false;
boolean troca3 = false;
boolean troca4 = false;
boolean troca5 = false;

//Declaração do desenho
byte caminho2[8] = { 0x4,0x4,0x7,0x0,0x0,0x0,0x1f}; // Caminho porta OR
byte por[8] = { 0x18,0x14,0xa,0x9,0xa,0x14,0x18};  // Porta OR
byte linhaand[8] = { 0x0,0x1f,0x0,0x0,0x1f,0x0,0x0};  // Linha dupla AND
byte entraa[8] = { 0x0,0x1f,0x0,0xe,0x11,0x1f,0x11};  // Caracter A
byte linharect[8] = { 0x0,0x1f,0x0,0x0,0x0,0x0,0x0 }; // Linha superior B
byte curva[8] = { 0x0,0x0,0x0,0x1c,0x4,0x4,0x4 }; // Curva para OR
byte negacao[8] = {0x0,0x0,0xc,0x12,0x12,0xc,0x0}; // Negação
// fim da declaração

//inicia o display e seleciona as entradas e saidas
LiquidCrystal_I2C lcd(0x3b, 16, 4);
LiquidCrystal_I2C lcda(0x3f, 16, 2);

void setup() 
{
  lcd.init();
  lcda.init();
  lcd.backlight(); 
  lcda.backlight(); 
  
    pinMode(botao, INPUT);   //Menu
    pinMode(botao2, INPUT);  //Entrada B
    pinMode(botao3, INPUT);  //Entrada A
    pinMode(botao4, INPUT);  //Menu
    pinMode(botao5, INPUT);  //Entrada B

    pinMode(13, OUTPUT);
    
      //Saudação   
  lcd.setCursor(0, 0); 
  lcd.print("Seja Bem Vindo!!");
  lcd.setCursor(-4, 2);
  lcd.print("-Portas Logicas-");
  delay(1500);
  lcd.clear();

  //Desenho ---------
  lcda.createChar(1, caminho2);
  lcda.createChar(2, por);
  lcda.createChar(3, linhaand);
  lcda.createChar(4, entraa);
  lcda.createChar(5, linharect);
  lcda.createChar(6, curva);
  lcda.createChar(7, negacao);
  //Desenho ---------
  
} // Termina Void Setup

void loop() {

//Desenho ---------

//lcda.setCursor(8,0);
//lcda.print((char)2);

lcda.setCursor(7,0);
lcda.print((char)3);

lcda.setCursor(10,0);
lcda.print((char)6);

lcda.setCursor(10,1);
lcda.print((char)1);

//lcda.setCursor(10,1);
//lcda.write(240);

lcda.setCursor(9,0);
lcda.print("-");

lcda.setCursor(6,0);
lcda.print((char)3);

lcda.setCursor(5,0);
lcda.print((char)4);

lcda.setCursor(3,0);
lcda.print("B");

lcda.setCursor(4,0);
lcda.print((char)5);

lcda.setCursor(4,1);
lcda.write(95);

lcda.setCursor(5,1);
lcda.write(95);

lcda.setCursor(6,1);
lcda.write(95);

lcda.setCursor(7,1);
lcda.write(95);

lcda.setCursor(8,1);
lcda.write(95);

lcda.setCursor(9,1);
lcda.write(95);

lcda.setCursor(3,1);
lcda.print("C");


//lcda.setCursor(7,0);
//lcda.print("|");
/*
 AND--------------------
lcda.setCursor(8,0);
lcda.print("D");
OR-----------------------
lcda.setCursor(8,0);
lcda.print((char)2);
NOT-----------------------
lcda.setCursor(8,0);
lcda.print(">");
XOR---------------------
lcda.setCursor(7,0);
lcda.print("|");
XNOR--------------------

NAND---------------------

*/
//Desenho ---------

  int estado  =0;
  int estado2 =0;
  int estado3 =0;
  int estado4 =0;
  int estado5 =0;
  int estado6 =0;
  
//faz a leitura do estado dos botoes

  estado = digitalRead(botao);  //Menu 1
  estado2 = digitalRead(botao2);//Entrada B 1 
  estado3 = digitalRead(botao3);//Entrada A 1 
  estado4 = digitalRead(botao3);
  estado5 = digitalRead(botao4);//Menu 2
  estado6 = digitalRead(botao5);//Entrada A 2

int saida=0;

//controle da sequencia do menu

//Menu A -------------
if (estado == HIGH) 
  {     
     delay(250);  
     contador=contador+1;
  }
    if (contador==6)
    {
      contador=0;
    }                           //Menu B -------------
                                if (estado5 == HIGH) 
                                  {     
                                     delay(250);  
                                     contador2=contador2+1;
                                  }
                                    if (contador2==6)
                                    {
                                      contador2=0;
                                    }
//menu A
 switch(contador){
   
   case 0: // Porta Logica AND    ------------------------------------
   
   lcda.setCursor(8,0); // Impressao porta AND
   lcda.print("D");

   //Entrada A 
      if (estado3 == HIGH & troca==false ){
         delay(150);
         troca=true;
      }else{
          delay(150);
          if(troca==true & estado3==HIGH){ 
             troca=false;
           }
       }
   //Entrada B
   if (estado2 == HIGH & troca3==false ){
         delay(150);
         troca3=true;
   }else{
       delay(150);
       if(troca3==true & estado2==HIGH){ 
           troca3=false;
          }
    }
   //Impressao dos valores
   
       lcd.setCursor(0, 0);
       lcd.print("Porta logica AND");

     //Impressao Entrada A  
        lcd.setCursor(2,1);
     if (troca==1){
        lcd.print("1");
     }else{
        lcd.print("0");
     } 
     //Impressao Entrada B
        lcd.setCursor(6,1);
    if (troca3==1){
        lcd.print("1");
     }else{
        lcd.print("0");
     } 
     //Saida
     if (troca==1 and troca3==1){
        lcd.setCursor(13,1);
        lcd.print("1");
        saida=1;
     }
     else{
        lcd.setCursor(13,1);
        lcd.print("0");
        saida=0;
     }
   break;   
   
   case 1: // Porta Logica OR          ---------------------------------

   lcda.setCursor(8,0);
   lcda.print((char)2);

    //Entrada A
      if (estado3 == HIGH & troca==false ){
         delay(150);
         troca=true;
      }else{
          delay(150);
          if(troca==true & estado3==HIGH){ 
             troca=false;
           }
       }
   //Entrada B
   if (estado2 == HIGH & troca3==false ){
         delay(150);
         troca3=true;
   }else{
       delay(150);
       if(troca3==true & estado2==HIGH){ 
           troca3=false;
          }
    }
   //Impressao dos valores
   
       lcd.setCursor(0, 0);
       lcd.print("Porta logica OR ");

     //Impressao Entrada A  
        lcd.setCursor(2,1);
     if (troca==1){
        lcd.print("1");
     }else{
        lcd.print("0");
     } 
     //Impressao Entrada B
        lcd.setCursor(6,1);
    if (troca3==1){
        lcd.print("1");
     }else{
        lcd.print("0");
     } 
     //Saida
     if ((troca==1 and troca3==0) or (troca==0 and troca3==1) or (troca==1 and troca3==1)){
        lcd.setCursor(13,1);
        lcd.print("1");
        saida=1;
     }
     else{
        lcd.setCursor(13,1);
        lcd.print("0");
        saida=0;
     }
   break;
   
   case 2: //Porta Logica NOT           --------------------------------

      lcda.setCursor(8,0);
      lcda.print(">");

      if (estado3 == HIGH & troca2==false ){
         delay(150);
         troca2=true;
         }else{
          delay(150);
      if(troca2==true & estado3==HIGH){ 
           troca2=false;
          }
       }
      
    lcd.setCursor(0, 0);
   lcd.print("Porta logica NOT");
   
          lcd.setCursor(6,1);
          lcd.print(" ");
          lcd.setCursor(2,1);
          
     if (troca2==1){
        lcd.print("1");
           }else{
         lcd.print("0");
     } 
     //Saida
     if (troca2==0){
        lcd.setCursor(13,1);
        lcd.print("1");
        saida=1;
     }
     else{
        lcd.setCursor(13,1);
        lcd.print("0");
        saida=0;
     }
   break;

 case 3: // Porta Logica XOR             -------------------------------

    lcda.setCursor(7,0);
    lcda.print("|");
    lcda.setCursor(8,0);
    lcda.print((char)2);
 
    //Entrada A
      if (estado3 == HIGH & troca==false ){
         delay(150);
         troca=true;
      }else{
          delay(150);
          if(troca==true & estado3==HIGH){ 
             troca=false;
           }
       }
   //Entrada B
   if (estado2 == HIGH & troca3==false ){
         delay(150);
         troca3=true;
   }else{
       delay(150);
       if(troca3==true & estado2==HIGH){ 
           troca3=false;
          }
    }
   //Impressao dos valores
   
       lcd.setCursor(0, 0);
       lcd.print("Porta logica XOR");

     //Impressao Entrada A  
        lcd.setCursor(2,1);
     if (troca==1){
        lcd.print("1");
     }else{
        lcd.print("0");
     } 
     //Impressao Entrada B
        lcd.setCursor(6,1);
    if (troca3==1){
        lcd.print("1");
     }else{
        lcd.print("0");
     } 
     //Saida
     if ((troca==1 and troca3==0) or (troca==0 and troca3==1)){
        lcd.setCursor(13,1);
        lcd.print("1");
        saida=1;
     }
     else{
        lcd.setCursor(13,1);
        lcd.print("0");
        saida=0;
     }
   break;

   case 4: //Porta Logica XNOR            -----------------------------

    lcda.setCursor(7,0);
    lcda.print("|");
    lcda.setCursor(8,0);
    lcda.print((char)2);
    lcda.setCursor(9,0);
    lcda.print((char)7);
   //Entrada A
      if (estado3 == HIGH & troca==false ){
         delay(150);
         troca=true;
      }else{
          delay(150);
          if(troca==true & estado3==HIGH){ 
             troca=false;
           }
       }
   //Entrada B
   if (estado2 == HIGH & troca3==false ){
         delay(150);
         troca3=true;
   }else{
       delay(150);
       if(troca3==true & estado2==HIGH){ 
           troca3=false;
          }
    }
   //Impressao dos valores
   
       lcd.setCursor(0, 0);
       lcd.print("Porta logic XNOR");

     //Impressao Entrada A  
        lcd.setCursor(2,1);
     if (troca==1){
        lcd.print("1");
     }else{
        lcd.print("0");
     } 
     //Impressao Entrada B
        lcd.setCursor(6,1);
    if (troca3==1){
        lcd.print("1");
     }else{
        lcd.print("0");
     } 
     //Saida
     if ((troca==1 and troca3==1) or (troca==0 and troca3==0)){
        lcd.setCursor(13,1);
        saida=1;
        lcd.print("1");
     }
     else{
        lcd.setCursor(13,1);
        saida=0;
        lcd.print("0");
     }
   break;

  case 5: // Porta Logica NAND         ---------------------------------

    lcda.setCursor(8,0);
    lcda.print("D");
    lcda.setCursor(9,0);
    lcda.print((char)7);
  

    //Entrada A
      if (estado3 == HIGH & troca==false ){
         delay(150);
         troca=true;
      }else{
          delay(150);
          if(troca==true & estado3==HIGH){ 
             troca=false;
           }
       }
   //Entrada B
   if (estado2 == HIGH & troca3==false ){
         delay(150);
         troca3=true;
   }else{
       delay(150);
       if(troca3==true & estado2==HIGH){ 
           troca3=false;
          }
    }
   //Impressao dos valores
   
       lcd.setCursor(0, 0);
       lcd.print("Porta logic NAND");

     //Impressao Entrada A  
        lcd.setCursor(2,1);
     if (troca==1){
        lcd.print("1");
     }else{
        lcd.print("0");
     } 
     //Impressao Entrada B
        lcd.setCursor(6,1);
    if (troca3==1){
        lcd.print("1");
     }else{
        lcd.print("0");
     } 
     //Saida
     if ((troca==1 and troca3==0) or (troca==0 and troca3==1) or (troca==0 and troca3==0)){
        lcd.setCursor(13,1);
        lcd.print("1");
     }
     else{
        lcd.setCursor(13,1);
        lcd.print("0");
     }
   break;
   
   default:
   contador=0;
   
 }//Termina SWITCH A
//////////////////////////////////////////////////////////////////////////////////////////////////B
//menu B
 switch(contador2){

   case 0: // Porta Logica AND    ------------------------------------
   
   lcda.setCursor(13,1);// Apagar Bolinha da Nand
   lcda.print(" ");//
   
   lcda.setCursor(11,1);
   lcda.print("D");
   
   //Entrada A 
      if (estado6 == HIGH & troca4==false ){
         delay(150);
         troca4=true;
      }else{
          delay(150);
          if(troca4==true & estado6==HIGH){ 
             troca4=false;
           }
       }
   //Impressao dos valores
   
       lcd.setCursor(-4, 2);
       lcd.print("Porta logica AND");

     //Impressao Entrada A  
        lcd.setCursor(-2,3);
     if (troca4==1){
        lcd.print("1");
     }else{
        lcd.print("0");
     } 
     
     lcd.setCursor(2,5);
         lcd.print(saida);

         if(saida==1 & troca4 ==1){
           lcd.setCursor(9,5);
           lcd.print("1");
           digitalWrite(13,HIGH);
         }else{
            lcd.setCursor(9,5);
            lcd.print("0");
            digitalWrite(13,LOW);
         
         }
   break;   
   
        case 1: // Porta Logica OR    ------------------------------------
        
      lcda.setCursor(13,1);// Apagar Bolinha da Nand
      lcda.print(" ");//
      
      lcda.setCursor(11,1);
      lcda.print((char)2);
        
   //Entrada A 
      if (estado6 == HIGH & troca4==false ){
         delay(150);
         troca4=true;
      }else{
          delay(150);
          if(troca4==true & estado6==HIGH){ 
             troca4=false;
           }
       }
   //Impressao dos valores
   
       lcd.setCursor(-4, 2);
       lcd.print("Porta logica OR ");

     //Impressao Entrada A  
        lcd.setCursor(-2,3);
     if (troca4==1){
        lcd.print("1");
     }else{
        lcd.print("0");
     } 
     
     lcd.setCursor(2,5);
         lcd.print(saida);

         if((troca4==1 and saida==0) or (troca4==0 and saida==1) or (troca4==1 and saida==1)){
           lcd.setCursor(9,5);
           lcd.print("1");
           digitalWrite(13,HIGH);
         }else{
            lcd.setCursor(9,5);
            lcd.print("0");
            digitalWrite(13,LOW);
         
         }
   break;

      case 2: // Porta Logica NOT    ------------------------------------
      
      lcda.setCursor(13,1);// Apagar Bolinha da Nand
      lcda.print(" ");//
      
      lcda.setCursor(11,1);
      lcda.print(">");
  
   //Entrada A 
      if (estado6 == HIGH & troca4==false ){
         delay(150);
         troca4=true;
      }else{
          delay(150);
          if(troca4==true & estado6==HIGH){ 
             troca4=false;
           }
       }
       
   //Impressao dos valores
   
       lcd.setCursor(-4, 2);
       lcd.print("Porta logica NOT");
       
     lcd.setCursor(2,3);
    lcd.print(" ");

     lcd.setCursor(-2,5);
         lcd.print(saida);


         if(saida==0){
           lcd.setCursor(9,5);
           lcd.print("1");
           digitalWrite(13,HIGH);
         }else{
            lcd.setCursor(9,5);
            lcd.print("0");
            digitalWrite(13,LOW);
         
         }
   break;
   
      case 3: // Porta Logica XOR    ------------------------------------

    lcda.setCursor(13,1);// Apagar Bolinha da Nand
    lcda.print(" ");//

    lcda.setCursor(11,1);
    lcda.print("|");
    lcda.setCursor(12,1);
    lcda.print((char)2);
  
   //Entrada A 
      if (estado6 == HIGH & troca4==false ){
         delay(150);
         troca4=true;
      }else{
          delay(150);
          if(troca4==true & estado6==HIGH){ 
             troca4=false;
           }
       }
   //Impressao dos valores
   
       lcd.setCursor(-4, 2);
       lcd.print("Porta logica XOR");

     //Impressao Entrada A  
        lcd.setCursor(-2,3);
     if (troca4==1){
        lcd.print("1");
     }else{
        lcd.print("0");
     } 
     
     lcd.setCursor(2,5);
         lcd.print(saida);
         if((troca4==1 and saida==0) or (troca4==0 and saida==1)){
           lcd.setCursor(9,5);
           lcd.print("1");
           digitalWrite(13,HIGH);
         }else{
            lcd.setCursor(9,5);
            lcd.print("0");
            digitalWrite(13,LOW);
         
         }
   break;

         case 4: // Porta Logica XNOR    ------------------------------------

    lcda.setCursor(11,1);
    lcda.print("|");
    lcda.setCursor(12,1);
    lcda.print((char)2);
    lcda.setCursor(13,1);
    lcda.print((char)7);

   //Entrada A 
      if (estado6 == HIGH & troca4==false ){
         delay(150);
         troca4=true;
      }else{
          delay(150);
          if(troca4==true & estado6==HIGH){ 
             troca4=false;
           }
       }
   //Impressao dos valores
   
       lcd.setCursor(-4, 2);
       lcd.print("Porta logic XNOR");

     //Impressao Entrada A  
        lcd.setCursor(-2,3);
     if (troca4==1){
        lcd.print("1");
     }else{
        lcd.print("0");
     } 
     
     lcd.setCursor(2,5);
         lcd.print(saida);
         
         if((troca4==1 and saida==1) or (troca4==0 and saida==0)){
           lcd.setCursor(9,5);
           lcd.print("1");
           digitalWrite(13,HIGH);
         }else{
            lcd.setCursor(9,5);
            lcd.print("0");
            digitalWrite(13,LOW);
         
         }
   break;

            case 5: // Porta Logica NAND    ------------------------------------

    lcda.setCursor(11,1);
    lcda.print("D");
    lcda.setCursor(12,1);
    lcda.print((char)7);
    lcda.setCursor(13,1);// Limpar bolinha 
    lcda.print(" ");//
    
   //Entrada A 
      if (estado6 == HIGH & troca4==false ){
         delay(150);
         troca4=true;
      }else{
          delay(150);
          if(troca4==true & estado6==HIGH){ 
             troca4=false;
           }
       }
   //Impressao dos valores
   
       lcd.setCursor(-4, 2);
       lcd.print("Porta logic NAND");

     //Impressao Entrada A  
        lcd.setCursor(-2,3);
     if (troca4==1){
        lcd.print("1");
     }else{
        lcd.print("0");
     } 
     
     lcd.setCursor(2,5);
         lcd.print(saida);
         
         if((troca4==1 and saida==0) or (troca4==0 and saida==1) or (troca4==0 and saida==0)){
           lcd.setCursor(9,5);
           lcd.print("1");
           digitalWrite(13,HIGH);
         }else{
            lcd.setCursor(9,5);
            lcd.print("0");
            digitalWrite(13,LOW);
         
         }
   break;
   
   default:
   contador=0;
 }// Termina SWITCH B
}// Termina Void Loop 


