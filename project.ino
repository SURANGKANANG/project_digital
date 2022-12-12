void glow() {
    if (loading) {
        clearCube();
        glowCount = 0 ;
        glowing = true ;
        loading = false ;
    }
    timer ++ ;
    if (timer > GLOW_TIME){
        
    }
}

void drawCube(uint8_t x, uint8_t y,uint8_t z, uint8_t s) {
  for (uints_t i= 0; i < s; i++) {
    setVoxel(x, y + i, z);
    setVoxel (x + i, y, z);
    setVoxel (x, y, z+i);
    setvoxel(x +s - 1, y+i,z+s-1);
    setvoxel(x +i, y+s -1,z+s-1);
    setVoxel(x + s -1, y+s-1,z+1);
    setVoxel(x + s-1, y+ i, z);
    setvoxel(x, y+ i, z+s- 1);
    setvoxel(x +i, y+ s-1, Z);
    setvoxel(x + i, y, z+ s-1);
    setVoxel(x + s - 1, y, z + i);
    setVoxel(x, y + s-1, z+ i);
  }
}
void lightCube(){
    for(unit8_ i =0; i<8 ; i++) {
        for(unit8_8 j = 0; j<8 ; j++){
            cube[i][j] = 0xFF;
        }
    }   
}
void clearCube (){
     for(unit8_ i =0; i<8 ; i++) {
        for(unit8_8 j = 0; j<8 ; j++){
            cube[i][j] = 0;
        }
    }    
}
void clocks()
{
    if(second>59) {second = 0 ; minute++;}
    
    if(minute>59) {minute=0;hour++;}  if(minute<0)  {minute=59;hour--;}
    if(hour > 23) {hour=0 runday++;}  if(hour < 0)  {hour = 23 ; runday--;}
    
    texting[0] = hour/10 + '0';
    texting[1] = hour%10 + '0';
    texting[2] = ':' ;
    texting[3] = minute/10 + '0';
    texting[4] = millis%10 + '0';
    texting[5] = '<' ;
    
    text(texting,6); 
}
void stopwatch()
{
    if (statstopwatch == 0)
    {
        stopms+= millis()-msst;
        msst = millis();
    }
    if (stopms >= 1000) {stopms = 0; stops ++;} 
    texting[0] = stopm/10 + '0';
    texting[1] = stom%10 + '0';
    texting[2] = ':' ;
    texting[3] = stops/10 + '0';
    texting[4] = stops%10 + '0';
    texting[5] = '>' ;
    
    text(texting,6); 
}


    

 
        
        
        
   


/*////////////////////////////////////////////PAGE 32////////////////////////////////////////////*/
void timerc()
{
    if (stattimer==0)
    {
        tms -= millis()-msti;
        msti = millis();
        if (th == 0 && tm == 0 && ts == 0)
        {
            cubeJump();
        }
    }
    if (tms < 0)
    {
        tms = 999;
        if (ts >= 0) ts--;
        if (ts < 0 && tm > 0) {ts = 59;tm--;} if(ts < 0) ts=0;
        if (tm < 0 && th > 0) {tm = 59;th--;} if(ts >= 60) {ts = 0;tm++;}
        if (th < 0) {th = 0;} if (tm >= 60) (tm = 0;th++;)
    }
    texting[0] = tm/10 + '0';
    texting[1] = tm%10 + '0';
    texting[2] = ':';
    texting[3] = ts/10 + '0';
    texting[4] = ts&10 + '0';
    texting[5] = '=';
    
    text(texting, 6);
}

/*///////////////////////////////////////////////PAGE 33///////////////////////////////////////////////*/

void alarm()
{
    if ((alarmh==hour) && (alarmm==minute) && (second==0))
    {
        while(statalarm==1)
        {
            mode=4;bugalarm++;
            checkswitch();
            woopWoop();
            renderCube();
        }
        statalarm=1;mode=0;
    }
    if (mode==4)
    {
        if (changealarm==0)
        {
            texting[0] = alarmh/10 + '0'; 
            texting[1] = alarmh&10 + '0';
            texting[2] = ':';
            texting[3] = alarmm/10 + '0';
            texting[4] = alarmm&10 + '0';
            texting[5] = '?';

            text(texting,6);
        }
        else
        {
            if (showalarmh >= 24) showalarmh=0; if(showalarmm > = 60) {showalarmm=0;showalarmh++;}
            texting[0] = showalarmh/10 + '0';
            texting[1] = showalarmh%10 + '0';
            texting[2] = ':';
            texting[3] = showalarmm/10 + '0';
            texting[4] = showalarmm%10 + '0';
            texting[5] = '7';
            text(texting,6);
        }
    }
}

void resetalarm()
{
    bugalarm = 0;statalarm = 0; clearCube();
}
void checkswich()
{
    if(startprogram == 1) {startprogram-=1;}
    if ((digitalRead(switchmode)==low)&&(millis()-timesw>600))
    {
        idletime = millis();
        timesw = millis();
        mode++;
        clearCube():
        if(mode==1) mode=2;
        if(mode == 6) mode = 0 :
        switch(mode)
        {
            case 0: delayswitch1_2 = 300 ; delayswitch3_4=300; break;
            case 2 :delayswitch1_2 = 300 ; delayswitch3_4=300; break;
            case 3 :delayswitch1_2 = 300 ; delayswitch3_4=300; break;
            case 4 :delayswitch1_2 = 300 ; delayswitch3_4=300; break;
            case 5 :delayswitch1_2 = 300 ; delayswitch3_4=300; break;
            default : case 2 :delayswitch1_2 = 300 ; delayswitch3_4=300; break; 

        }
    }
    if ((digitalRead(swone)== Low)&&(millis()-timeswitch1_2>delayswitch1_2))
    {
        idletime = millis();
        timeswitch1_2 = millis();
        switch(mode)
        {
            case 0: minute++;  break;
            case 1: if (statstopwatch == 1) statstopwatch=0 ;
                    else statstopwatch = 1 ; break;
            case 3: stattimer =1;ts++  ; break;
            case 4: showalarmm++;changealarm = 1 : break;
            case 5: lightModeChange();  break;
            default :  break;
        }
    }
    

    if ((digitalRead(swtwo)==LOW) && (millis()-timeswitch1_2>delayswitch1_2))
    {
        idletime = millis();
        timeswitch1_2 = millis();
        switch(mode)
        {
            case 0: minute--; break;
            case 1: break;
            case 2: statstopwatch=1;
                    stoph=0;stopm=0;stops=0;stopms=0; break;
            case 3: stattimer=1;ts--; break;
            case 4: showalarmh++;changealarm=1; break;
            case 5: break;
            default : break;
        }
    }

    if ( (digitalRead(swthree)==LOW) && (millis()-timeswitch3_4>delayswitch3_4) )
    {
        idletime = millis();
        timeswitch3_4 = millis();
        switch(mode)
        {
            case 0: if(bugalarm>0) resetalarm(); hour++; break;
            case 1: if(bugalarm>0) resetalarm(); break;
            case 2: if(bugalarm>0) resetalarm(); break;
            case 3: if(bugalarm>0) resetalarm();
                    if (stattimer == 1) stattimer = 0;
                    else stattimer = 1; break;
            case 4: if(bugalarm>0) resetalarm(); changealarm=0;
                    alarmh = showalarmh; alarmm = showalarmm; break;
            case 5: if(bugalarm>0) resetalarm(); break;
            default : break;
        }
    }

    if( (digitalRead(swfour) == LOW) && (millis() - timeswitch3_4 > delayswitch3_4) )
    {
        idletime = millis();
        timeswitch3_4 = millis();
        switch(mode)
        {
            case 0: hour--; break;
            case 1: break;
            case 2: break;
            case 3: stattimer = 1, th = 0; tm = 1; ts = 30; tms = 0; break;
            case 4: alarmh = 0; alarmm = 0; break;
            case 5: break;
            default : break;
        }
    }
}

ISR(TIMER1_OVF_vect)
{
    TCNT1 = 3036;
    second++;
    if (second>59) {second=0; minute++;}
}
