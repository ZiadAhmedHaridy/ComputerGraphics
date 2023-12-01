
#include <stdlib.h>

#include<Gl/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<windows.h>
#include<math.h>

const float PI = 3.1415926f;

float angle1 = 30.0f; //train
float angle2 = 0.2f; // bird
float angle3 = 0.0f; //wheel
float angle4 = 0.0f;//wheel


float speed_train = 3.0f;
float speed_bird = 2.0f;

//cloud speed
float cloud_x = 0;
float cloud_y = 0;
float cloud_x2 = 0;
float cloud_y2 = 0;
int cloudStatus = 1;

//bird Stuff
float bird2_x = 0;
float bird2_y = 0 ;
int bird2Status = 1;
//sun stuff and moon
float sun_x = 0;
float sun_y = 0;
int sunStatus = 1 ;
float moon_x = 0 ;
float moon_y = 0 ;
int moonStatus = 1;


void handleKeyPress(unsigned char key, int x, int y)
{
    switch(key)
    {
    case 27 :
        exit(0);
    default:
        break;
    }
    glutPostRedisplay();
}
void idle()
{
    glutPostRedisplay(); //if we will modify the scene like we move some objects we need
}
void init(void)
{
    glMatrixMode(GL_PROJECTION); //Handles how the 3D scene is projected onto a 2D viewport,
    gluOrtho2D(-300.0,300.0,-200.0,200.0);
}
void initRendering()
{
    glEnable(GL_DEPTH_TEST); //Enables depth testing, which is crucial for rendering 3D scenes correctly.
    glEnable(GL_COLOR_MATERIAL); // if we remove it the screen will become black and white This command allows the OpenGL material properties to track the current color set using glColor*()
    glEnable(GL_LIGHTING); //Enable lighting
    glEnable(GL_LIGHT0);

}

void DrawCircle(float cx,float cy,float r, int num_segments)
{
    glBegin(GL_POLYGON);
    for(int i = 0; i<num_segments; i++ ) //segments  make circle more smooth
    {
        float theta = 2.0f *PI * float(i)/float(num_segments);
        float x = r*cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(x+cx,y+cy);
    }
    glEnd();
}

void drawSun()
{
    glPushMatrix();
    glColor3f(1.000,1.000,0.000);
    DrawCircle(100,50,20,100);
    glPopMatrix();
}

void drawMoon()
{
    glPushMatrix();
    glColor3f(3.0,1.0,0.5);
    DrawCircle(100,50,20,100);
    glPopMatrix();
}

void sun()
{

    if(sunStatus == 1)
    {
        sun_x +=0.001;
        sun_y += .01;
    }
    if(sun_x>17)
    {
        sun_x = 0;
        sun_y = 0;
    }
    glPushMatrix();
    glTranslatef(sun_x,sun_y,0.0);
    drawSun();
    glPopMatrix();
}
void bird2()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    glColor3f(.133,.545,.133);

    glBegin(GL_POLYGON);
    glVertex2i(180,140);
    glVertex2i(180,130);
    glVertex2i(170,125);
    glVertex2i(160,130);
    glVertex2i(160,140);
    glEnd();

//green bird
    glBegin(GL_POLYGON);
    glColor3f(.180,.545,.341);
    glVertex2i(160,130);
    glVertex2i(160,140);
    glVertex2i(150,137);
    glVertex2i(152,132);
    glEnd();

//green bird
    glBegin(GL_POLYGON);
    glColor3f(1.000,0.000,0.000);
    glVertex2i(145,135);
    glVertex2i(150,137);
    glVertex2i(152,132);
    glEnd();

//green bird

    glBegin(GL_POLYGON);
    glColor3f(.180,0.545,0.341);
    glVertex2i(180,140);
    glVertex2i(180,130);
    glVertex2i(190,133);
    glVertex2i(195,140);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.180,.545,.341);
    glVertex2i(180,140);
    glVertex2i(195,140);
    glVertex2i(190,144);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.545,.271,.075);
    glVertex2i(170,125);
    glVertex2i(189,130);
    glVertex2i(185,122);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.133,.545,.133);
    glVertex2i(160,140);
    glVertex2i(170,155);
    glVertex2i(185,160);
    glVertex2i(180,140);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.180,.545,.341);
    glVertex2i(185,160);
    glVertex2i(180,158.33);
    glVertex2i(190,150);
    glEnd();

    glPopMatrix();
}

void bird2m()
{


    if(bird2Status == 1)
    {
        bird2_x -= .4;
        bird2_y += .01;
    }
    if(bird2_x <-500)
    {
        bird2_x = 200;
        bird2_y = 0;
    }
    glPushMatrix();
    glTranslated(bird2_x,bird2_y,0.0);
    bird2();
    glPopMatrix();
}

void moon()
{
    if(moonStatus == 1)
    {
        moon_x += .001;
        moon_y += .01;

    }

    if(moon_x >17) // sun will rise again
    {
        moon_x = 0 ;
        moon_y = 0 ;
    }
    glPushMatrix();
    glTranslatef(moon_x,moon_y,0.0);
    drawMoon();

    glPopMatrix();
}

void Statn()
{
    //gate
    glBegin(GL_POLYGON);
    glColor3f(1.000,.627,.478);
    glVertex2i(-50,-80);
    glVertex2i(-50,35);
    glColor3f(.3,.2,.0);
    glVertex2i(10,75);
    glVertex2i(70,35);
    glVertex2i(70,-80);
    glEnd();
    //door
    glBegin(GL_POLYGON);
    glColor3f(.3,.2,.0);
    glVertex2i(-60,-80);
    glVertex2i(-60,40);
    glColor3f(1.000,0.627,.478);
    glVertex2i(10,90);
    glVertex2i(80,40);
    glVertex2i(80,-80);
    glEnd();
    //room
    glBegin(GL_POLYGON);
    glColor3f(1.000,.549,.0000);
    glVertex2i(-100,-80);
    glVertex2i(-100,110);
    glColor3f(.957,.643,.376);
    glVertex2i(50,110);
    glVertex2i(100,70);
    glVertex2i(80,40);
    glVertex2i(10,90);
    glVertex2i(-60,40);
    glVertex2i(-60, -80);
    glEnd();

    //left room window
    glBegin(GL_POLYGON);
    glColor3f(1.000,0.627,0.478);
    glVertex2i(-170,-70);
    glVertex2i(-170,40);
    glColor3f(.3,.2,.0);
    glVertex2i(-110,40);
    glVertex2i(-110,-70);
    glEnd();

    //LEFT ROOM
    glBegin(GL_POLYGON);
    glColor3f(.3,.2,.0);
    glVertex2i(-180,-80);
    glVertex2i(-180,110);
    glColor3f(1.000,.627,.478);
    glVertex2i(-100,110);
    glVertex2i(-100,-80);
    glEnd();

    //roof
    glBegin(GL_POLYGON);
    glColor3f(.698,.133,.133);
    glVertex2i(-190,110);
    glColor3f(.863,.078,.235);
    glVertex2i(-140,165);
    glVertex2i(-90,110);

    glEnd();//LEFT ROOF

    //room window
    glBegin(GL_POLYGON);
    glColor3f(.3,.2,.0);
    glVertex2i(90,-20);
    glVertex2i(90,30);
    glColor3i(1,627,376);
    glVertex2i(140,30);
    glVertex2i(140,-20);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.95,.64,.37);
    glVertex2i(80,-80);
    glVertex2i(80,40);
    glColor3i(1,627,376);
    glVertex2i(150,40);
    glVertex2i(150,-80);
    glEnd();

    //room r8
    glBegin(GL_POLYGON);
    glColor3f(.957,.643,.376);
    glVertex2i(70,40);
    glColor3f(1.000,.549,.0);
    glVertex2i(115,90);
    glVertex2i(160,40);
    glEnd();

}

void aiub()
{
    //wall
    glBegin(GL_POLYGON);
    glColor3f(.980,.502,.447);
    glVertex2i(-300,0);
    glVertex2i(-300,90);
    glColor3f(.871,.722,.529);
    glVertex2i(-280,90);
    glVertex2i(-280,0);
    glEnd();
    //globe window
    glBegin(GL_POLYGON);
    glColor3f(.416,.353,.804);
    glVertex2i(-300,40);
    glVertex2i(-300,55);
    glColor3f(.373,.620,.627);
    glVertex2i(-235,55);
    glVertex2i(-235,40);
    glEnd();

    //globe window
    glBegin(GL_POLYGON);
    glColor3f(.416,.353,.804);
    glVertex2i(-300,70);
    glVertex2i(-300,85);
    glColor3f(.373,.620,.627);
    glVertex2i(-215,85);
    glVertex2i(-225,70);
    glEnd();


    //globe window
    glBegin(GL_POLYGON);
    glColor3f(.416,.353,.804);
    glVertex2i(-300,100);
    glVertex2i(-300,115);
    glColor3f(.373,.620,.627);
    glVertex2i(-210,115);
    glVertex2i(-210,100);
    glEnd();


    //globe window
    glBegin(GL_POLYGON);
    glColor3f(.416,.353,.804);
    glVertex2i(-300,130);
    glVertex2i(-300,145);
    glColor3f(.373,.620,.627);
    glVertex2i(-225,145);
    glVertex2i(-215,130);
    glEnd();

    //globe window
    glBegin(GL_POLYGON);
    glColor3f(.416,.353,.804);
    glVertex2i(-300,160);
    glVertex2i(-285.5,170);
    glColor3f(.373,.620,.627);
    glVertex2i(-252.5,170);
    glVertex2i(-235,160);
    glEnd();

    glPushMatrix();
    //CRICLE OF AIUB BACKGROUND !!!!
    glColor3f(.275,.510,.7);
    DrawCircle(-270,110,65,100);
    glPopMatrix();

    glBegin(GL_POLYGON); //AIUB globe floor
    glColor3f(.275,.510,.706);
    glVertex2i(-300,25);
    glVertex2i(-300,60);
    glVertex2i(-230,60);
    glVertex2i(-230,25);
    glEnd();

}

void drawCloud()
{

    glPushMatrix();
    glColor3f(.8,.8,.8);
//first cloud
    DrawCircle(-130,170,25,100);
    DrawCircle(-160,175,25,100);
    DrawCircle(-100,165,25,100);
    DrawCircle(-140,155,25,100);

//second cloud
    DrawCircle(130,170,25,100);
    DrawCircle(160,175,25,100);
    DrawCircle(100,165,25,100);
    DrawCircle(140,155,25,100);

    glPushMatrix();

}

void drawClock()
{

    glPushMatrix();

    glColor3f(.663,.663,.663);
    DrawCircle(-140,75,25,100);
    glPopMatrix();
}

void cloud()
{

    if(cloudStatus == 1)
    {
        cloud_x  -= .2;
    }
    if(cloud_x < -1100)
    {
        cloud_x += 650 ;
    }
    glPushMatrix();

}

void cloud2()
{
    if(cloudStatus == 1)
    {
        cloud_x2  -= .3;
    }
    if(cloud_x2 > 600)
    {
        cloud_x2 = -1150 ;
    }
    glPushMatrix();
    glTranslatef(cloud_x2 + 500,cloud_y2 + 50,.00);
    drawClock();
    glPopMatrix();

}
void plants()
{
    //Grass beside tree
    glBegin(GL_POLYGON);
    glColor3f(.0,.6,.1);
    glVertex2i(175,-20);
    glVertex2i(160,0);
    glVertex2i(150,10);
    glVertex2i(170,0);
    glVertex2i(160,30);
    glVertex2i(180,10);
    glVertex2i(185,50);
    glColor3f(.6,1.000,.184);
    glVertex2i(190,10);
    glVertex2i(210,30);
    glVertex2i(200,0);
    glVertex2i(220,10);
    glVertex2i(210,0);
    glVertex2i(195,-20);
    glEnd();

//tree
    glBegin(GL_POLYGON);
    glColor3f(.0,.6,.1);
    glVertex2i(245,-20);
    glVertex2i(230,0);
    glVertex2i(220,10);
    glVertex2i(240,0);
    glVertex2i(230,30);
    glVertex2i(250,10);
    glVertex2i(255,50);
    glColor3f(.6,1.000,.184);
    glVertex2i(260,10);
    glVertex2i(280,30);
    glVertex2i(270,0);
    glVertex2i(290,10);
    glVertex2i(280,0);
    glVertex2i(265,-20);
    glEnd();

    //grass bag
    glBegin(GL_POLYGON);
    glColor3f(.0,.6,.1);
    glVertex2i(-245,-20);
    glVertex2i(-230,0);
    glVertex2i(-220,10);
    glVertex2i(-240,0);
    glVertex2i(-230,30);
    glVertex2i(250,10);
    glVertex2i(-255,50);
    glColor3f(.6,1.000,.184);
    glVertex2i(-260,10);
    glVertex2i(-280,30);
    glVertex2i(-270,0);
    glVertex2i(-290,10);
    glVertex2i(-280,0);
    glVertex2i(-265,-20);
    glEnd();

    //grass bag
    glBegin(GL_POLYGON);
    glColor3f(.0,.6,.1);
    glVertex2i(-175,-20);
    glVertex2i(-160,0);
    glVertex2i(-150,10);
    glVertex2i(-170,0);
    glVertex2i(-160,30);
    glVertex2i(-180,10);
    glVertex2i(-185,50);
    glColor3f(.6,1.000,.184);
    glVertex2i(-190,10);
    glVertex2i(-210,30);
    glVertex2i(-200,0);
    glVertex2i(-220,10);
    glVertex2i(-210,0);
    glVertex2i(-195,-20);
    glEnd();

    glColor3f(.545098,.270588,.0745098);
    glBegin(GL_POLYGON);
    glVertex2i(180,0);
    glVertex2i(180,70);
    glColor3f(.804,.522,.247);
    glVertex2i(170,70);
    glVertex2i(170,0);
    glEnd();

    glColor3f(.0,.5,.0);
    glBegin(GL_POLYGON);
    glVertex2i(220,70);
    glVertex2i(190,85);
    glColor3f(.678,1.000,.184);
    glVertex2i(160,85);
    glVertex2i(130,70);
    glEnd();


    glColor3f(.0,.5,.0);
    glBegin(GL_POLYGON);
    glVertex2i(215,85);
    glVertex2i(185,100);
    glColor3f(.678,1.000,.184);
    glVertex2i(165,100);
    glVertex2i(135,85);
    glEnd();

    glColor3f(.0,.5,.0); //tree number 2 part of it not all
    glBegin(GL_POLYGON);
    glVertex2i(210,100);
    glColor3f(.678,1.000,.184);
    glVertex2i(175,135);
    glVertex2i(140,100);
    glEnd();
    //super left tree middle triangle
    glColor3f(.0,.5,.0);
    glBegin(GL_POLYGON);
    glVertex2i(-240,70);
    glVertex2i(-210,85);
    glColor3f(.678,1.000,.184);
    glVertex2i(-180,85);
    glVertex2i(-150,70);
    glEnd();
    //super left tree before middle triangle
    glColor3f(.0,.5,.0);
    glBegin(GL_POLYGON);
    glVertex2i(-235,85);
    glVertex2i(-205,100);
    glColor3f(.678,1.000,.184);
    glVertex2i(-185,100);
    glVertex2i(-155,85);
    glEnd();

    //left tree top triangle
    glBegin(GL_POLYGON);
    glColor3f(.0,.5,.0);
    glVertex2i(-240,100);
    glColor3f(.678,1.000,.184);
    glVertex2i(-195,135);
    glVertex2i(-160,100);
    glEnd();
    //super left tree leg
    glColor3f(.545098,.270588,.0745098);
    glBegin(GL_POLYGON);
    glVertex2i(-200,0);
    glVertex2i(-200,70);
    glColor3f(.804,.522,.247);
    glVertex2i(-190,70);
    glVertex2i(-190,0);
    glEnd();

    glPushMatrix();
    //right tree papers circles
    glColor3f(.133,.545,.133);
    DrawCircle(210,105,25,100);
    DrawCircle(250,95,25,100);
    DrawCircle(275,95,25,100);
    DrawCircle(240,130,25,100);
    DrawCircle(250,115,25,100);

    glPopMatrix();

    glColor3f(.545098,.270588,.0745098);
    glBegin(GL_POLYGON);
    glVertex2i(250,0);
    glVertex2i(250,80);
    glColor3f(.804,.522,.247);
    glVertex2i(235,80);
    glVertex2i(235,0);
    glEnd();
}

void backGroundDay()
{

    glBegin(GL_POLYGON);
    glColor3f(.565,.933,.565);
    glVertex2i(300,70);
    glVertex2i(-300,70);
    glColor3f(.0,.9,.0);
    glVertex2i(-300,20);
    glVertex2i(300,-20);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.565,.933,.565);
    glVertex2i(300,-120);
    glVertex2i(-300,-120);
    glColor3f(.0,.9,.0);
    glVertex2i(-300,-200);
    glVertex2i(300,-200);
    glEnd();


    glBegin(GL_POLYGON); //sky
    glColor3f(.03,.73,.96);
    glVertex2i(300,65);
    glVertex2i(-300,65);
    glColor3f(.7,.7,1.0);
    glVertex2i(-300,200);
    glVertex2i(300,200);
    glEnd();

    glColor3f(.0,.6,.1); //grass
    glVertex2i(35,-200);
    glVertex2i(20,-180);
    glVertex2i(10,-170);
    glVertex2i(30,-180);
    glVertex2i(20,-150);
    glVertex2i(40,-170);
    glVertex2i(45,-130);
    glColor3f(.6,.8,.1);
    glVertex2i(50,-170);
    glVertex2i(70,-150);
    glVertex2i(60,-180);
    glVertex2i(80,-170);
    glVertex2i(70,-180);
    glVertex2i(55,-200);
    glEnd();

    //grass big

    glColor3f(.0,.6,.1);
    glVertex2i(105,-200);
    glVertex2i(90,-180);
    glVertex2i(80,-170);
    glVertex2i(100,-180);
    glVertex2i(90,-150);
    glVertex2i(110,-170);
    glVertex2i(115,-130);
    glColor3f(.7,.8,.1);
    glVertex2i(120,-170);
    glVertex2i(140,-150);
    glVertex2i(130,-180);
    glVertex2i(150,-170);
    glVertex2i(140,-180);
    glVertex2i(125,-200);
    glEnd();

    //grass big
    glColor3f(.0,.6,.1);
    glVertex2i(175,-200);
    glVertex2i(160,-180);
    glVertex2i(150,-170);
    glVertex2i(170,-180);
    glVertex2i(160,-150);
    glVertex2i(180,-170);
    glVertex2i(185,-130);
    glColor3f(.7,.8,.1);
    glVertex2i(190,-170);
    glVertex2i(210,-150);
    glVertex2i(200,-180);
    glVertex2i(220,-170);
    glVertex2i(210,-180);
    glVertex2i(195,-200);
    glEnd();
    //grass ibbibibib
    glColor3f(.0,.6,.1);
    glVertex2i(245,-200);
    glVertex2i(230,-180);
    glVertex2i(220,-170);
    glVertex2i(240,-180);
    glVertex2i(230,-150);
    glVertex2i(250,-170);
    glVertex2i(255,-130);
    glColor3f(.7,.8,.1);
    glVertex2i(260,-170);
    glVertex2i(280,-150);
    glVertex2i(270,-180);
    glVertex2i(290,-170);
    glVertex2i(280,-180);
    glVertex2i(265,-200);
    glEnd();

    //grass ibbibibib
    glColor3f(.0,.6,.1);
    glVertex2i(-35,-200);
    glVertex2i(-20,-180);
    glVertex2i(-10,-170);
    glVertex2i(-30,-180);
    glVertex2i(-20,-150);
    glVertex2i(-40,-170);
    glVertex2i(-45,-130);
    glColor3f(.7,.8,.1);
    glVertex2i(-50,-170);
    glVertex2i(-70,-150);
    glVertex2i(-60,-180);
    glVertex2i(-80,-170);
    glVertex2i(-70,-180);
    glVertex2i(-55,-200);
    glEnd();


    //grass ibbibibib
    glColor3f(.0,.6,.1);
    glVertex2i(-105,-200);
    glVertex2i(-90,-180);
    glVertex2i(-80,-170);
    glVertex2i(-100,-180);
    glVertex2i(-90,-150);
    glVertex2i(-110,-170);
    glVertex2i(-115,-130);
    glColor3f(.7,.8,.1);
    glVertex2i(-120,-170);
    glVertex2i(-140,-150);
    glVertex2i(-130,-180);
    glVertex2i(-150,-170);
    glVertex2i(-140,-180);
    glVertex2i(-125,-200);
    glEnd();
    //grass ibbibibib
    glColor3f(.0,.6,.1);
    glVertex2i(-175,-200);
    glVertex2i(-160,-180);
    glVertex2i(-150,-170);
    glVertex2i(-170,-180);
    glVertex2i(-160,-150);
    glVertex2i(-180,-170);
    glVertex2i(-185,-130);
    glColor3f(.7,.8,.1);
    glVertex2i(-190,-170);
    glVertex2i(-210,-150);
    glVertex2i(-200,-180);
    glVertex2i(-220,-170);
    glVertex2i(-210,-180);
    glVertex2i(-195,-200);
    glEnd();

    //grass ibbibibib
    glColor3f(.0,.6,.1);
    glVertex2i(-245,-200);
    glVertex2i(-230,-180);
    glVertex2i(-220,-170);
    glVertex2i(-240,-180);
    glVertex2i(-230,-150);
    glVertex2i(-250,-170);
    glVertex2i(-255,-130);
    glColor3f(.7,.8,.1);
    glVertex2i(-260,-170);
    glVertex2i(-280,-150);
    glVertex2i(-270,-180);
    glVertex2i(-290,-170);
    glVertex2i(-280,-180);
    glVertex2i(-265,-200);
    glEnd();
}

void plantsAtGround() // green bags at bottoms
{
    //start
    glBegin(GL_POLYGON);
    glColor3f(.741,.718,.420);
    glVertex2i(-300,-20);
    glVertex2i(-300,-120);
    glVertex2i(300,-20);
    glEnd();

    //grass big
    glBegin(GL_POLYGON);
    glColor3f(.0,.6,.1);
    glVertex2i(35,-200);
    glVertex2i(20,-180);
    glVertex2i(10,-170);
    glVertex2i(30,-180);
    glVertex2i(20,-150);
    glVertex2i(40,-170);
    glVertex2i(45,-130);
    glColor3f(.7,.8,.1);
    glVertex2i(50,-170);
    glVertex2i(70,-150);
    glVertex2i(60,-180);
    glVertex2i(80,-170);
    glVertex2i(70,-180);
    glVertex2i(55,-200);
    glEnd();

    //right grass at ground
    glBegin(GL_POLYGON);
    glColor3f(.0,.6,.1);
    glVertex2i(105,-200);
    glVertex2i(90,-180);
    glVertex2i(80,-170);
    glVertex2i(100,-180);
    glVertex2i(90,-150);
    glVertex2i(110,-170);
    glVertex2i(115,-130);
    glColor3f(.7,.8,.1);
    glVertex2i(120,-170);
    glVertex2i(140,-150);
    glVertex2i(130,-180);
    glVertex2i(150,-170);
    glVertex2i(140,-180);
    glVertex2i(125,-200);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.0,.6,.1);
    glVertex2i(115,-200);
    glVertex2i(100,-180);
    glVertex2i(90,-170);
    glVertex2i(110,-180);
    glVertex2i(100,-150);
    glVertex2i(120,-170);
    glVertex2i(125,-130);
    glColor3f(.7,.8,.1);
    glVertex2i(130,-170);
    glVertex2i(150,-150);
    glVertex2i(140,-180);
    glVertex2i(160,-170);
    glVertex2i(150,-180);
    glVertex2i(135,-200);
    glEnd();

    //
    glBegin(GL_POLYGON);
    glColor3f(.0,.6,.1);
    glVertex2i(175,-200);
    glVertex2i(160,-180);
    glVertex2i(150,-170);
    glVertex2i(170,-180);
    glVertex2i(160,-150);
    glVertex2i(180,-170);
    glVertex2i(185,-130);
    glColor3f(.7,.8,.1);
    glVertex2i(190,-170);
    glVertex2i(210,-150);
    glVertex2i(200,-180);
    glVertex2i(220,-170);
    glVertex2i(210,-180);
    glVertex2i(195,-200);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.0,.6,.1);
    glVertex2i(245,-200);
    glVertex2i(230,-180);
    glVertex2i(220,-170);
    glVertex2i(240,-180);
    glVertex2i(230,-150);
    glVertex2i(250,-170);
    glVertex2i(255,-130);
    glColor3f(.7,.8,.1);
    glVertex2i(260,-170);
    glVertex2i(280,-150);
    glVertex2i(270,-180);
    glVertex2i(290,-170);
    glVertex2i(280,-180);
    glVertex2i(265,-200);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.0,.6,.1);
    glVertex2i(145,-200);
    glVertex2i(130,-180);
    glVertex2i(120,-170);
    glVertex2i(140,-180);
    glVertex2i(130,-150);
    glVertex2i(150,-170);
    glVertex2i(155,-130);
    glColor3f(.7,.8,.1);
    glVertex2i(160,-170);
    glVertex2i(180,-150);
    glVertex2i(170,-180);
    glVertex2i(190,-170);
    glVertex2i(180,-180);
    glVertex2i(165,-200);
    glEnd();


}

void railLine()
{
    //start railway
    glBegin(GL_POLYGON);
    glColor3f(.502,.000,.000);
    glVertex2i(-300,-70);
    glVertex2i(-300,-75);
    glVertex2i(300,-75);
    glVertex2i(300,-70);
    glEnd();

    //start wood
    glBegin(GL_POLYGON);
    glColor3f(.502,.000,.000);
    glVertex2i(-300,-60);
    glVertex2i(-300,-65);
    glVertex2i(300,-65);
    glVertex2i(300,-60);
    glEnd();

    glBegin(GL_POLYGON);// start wood
    glColor3f(.545,.271,.075);
    glVertex2i(-300,-80);
    glVertex2i(-300,-55);
    glVertex2i(-285,-55);
    glVertex2i(-285,-80);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.545,.271,.075);
    glVertex2i(-270,-80);
    glVertex2i(-270,-55);
    glVertex2i(-255,-55);
    glVertex2i(-255,-80);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(.545,.271,.075);
    glVertex2i(-240,-80);
    glVertex2i(-240,-55);
    glVertex2i(-225,-55);
    glVertex2i(-225,-80);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(.545,.271,.075);
    glVertex2i(-210,-80);
    glVertex2i(-210,-55);
    glVertex2i(-195,-55);
    glVertex2i(-195,-80);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.545,.271,.075);
    glVertex2i(-180,-80);
    glVertex2i(-180,-55);
    glVertex2i(-165,-55);
    glVertex2i(-165,-80);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.545,.271,.075);
    glVertex2i(-150,-80);
    glVertex2i(-150,-55);
    glVertex2i(-135,-55);
    glVertex2i(-135,-80);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(.545,.271,.075);
    glVertex2i(-120,-80);
    glVertex2i(-120,-55);
    glVertex2i(-105,-55);
    glVertex2i(-105,-80);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(.545,.271,.075);
    glVertex2i(-90,-80);
    glVertex2i(-90,-55);
    glVertex2i(-75,-55);
    glVertex2i(-75,-80);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.545,.271,.075);
    glVertex2i(-60,-80);
    glVertex2i(-60,-55);
    glVertex2i(-45,-55);
    glVertex2i(-45,-80);
    glEnd();

    glBegin(GL_POLYGON);//start wood
    glColor3f(.545,.271,.075);
    glVertex2i(-30,-80);
    glVertex2i(-30,-55);
    glVertex2i(-15,-55);
    glVertex2i(-15,-80);
    glEnd();

    glBegin(GL_POLYGON);//start wood
    glColor3f(.545,.271,.075);
    glVertex2i(0,-80);
    glVertex2i(0,-55);
    glVertex2i(15,-55);
    glVertex2i(15,-80);
    glEnd();

    glBegin(GL_POLYGON);//start wood
    glColor3f(.545,.271,.075);
    glVertex2i(30,-80);
    glVertex2i(30,-55);
    glVertex2i(45,-55);
    glVertex2i(45,-80);
    glEnd();


    glBegin(GL_POLYGON);//start wood
    glColor3f(.545,.271,.075);
    glVertex2i(60,-80);
    glVertex2i(60,-55);
    glVertex2i(75,-55);
    glVertex2i(75,-80);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.545,.271,.075);
    glVertex2i(90,-80);
    glVertex2i(90,-55);
    glVertex2i(105,-55);
    glVertex2i(105,-80);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.545,.271,.075);
    glVertex2i(120,-80);
    glVertex2i(120,-55);
    glVertex2i(135,-55);
    glVertex2i(135,-80);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.545,.271,.075);
    glVertex2i(150,-80);
    glVertex2i(150,-55);
    glVertex2i(165,-55);
    glVertex2i(165,-80);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.545,.271,.075);
    glVertex2i(180,-80);
    glVertex2i(180,-55);
    glVertex2i(195,-55);
    glVertex2i(195,-80);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.545,.271,.075);
    glVertex2i(210,-80);
    glVertex2i(210,-55);
    glVertex2i(225,-55);
    glVertex2i(225,-80);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.545,.271,.075);
    glVertex2i(240,-80);
    glVertex2i(240,-55);
    glVertex2i(255,-55);
    glVertex2i(255,-80);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.545,.271,.075);
    glVertex2i(270,-80);
    glVertex2i(270,-55);
    glVertex2i(285,-55);
    glVertex2i(285,-80);
    glEnd();
}

void wheell()
{
    glRotatef(angle3,3.0,3.0,1.0);
    glTranslatef(-180,-60,0.0);
    glColor3f(.0,.0,.0);
    glBegin(GL_POLYGON);
    for(int i = 0 ; i<200; i++)
    {
        float A = (i*2*PI)/50;
        float r = 10.15;
        float x = r* cos(A);
        float y = r*sin(A);
        glVertex2f(x,y);
    }
    glEnd();
}

void wheell2()
{
    glRotatef(angle4,2.0,2.0,1.0);
    glTranslatef(30.00,.0,.0);
    glColor3f(.0,.0,.0);
    glBegin(GL_POLYGON);
    for(int i = 0 ; i<200; i++)
    {
        float A = (i*2*PI)/50;
        float r = 10.15;
        float x = r* cos(A);
        float y = r*sin(A);
        glVertex2f(x,y);
    }
    glEnd();
}

void wheell3()
{
    glRotatef(angle4,2.0,2.0,1.0);
    glTranslatef(-80.800,.0,.0);
    glColor3f(.0,.0,.0);
    glBegin(GL_POLYGON);
    for(int i = 0 ; i<200; i++)
    {
        float A = (i*2*PI)/50;
        float r = 12.15;
        float x = r* cos(A);
        float y = r*sin(A);
        glVertex2f(x,y);
    }
    glEnd();
}

void wheell4()
{

    glRotatef(angle4,2.0,2.0,1.0);
    glTranslatef(-100.800,.0,.0);
    glColor3f(.0,.0,.0);
    glBegin(GL_POLYGON);
    for(int i = 0 ; i<200; i++)
    {
        float A = (i*2*PI)/50;
        float r = 12.15;
        float x = r* cos(A);
        float y = r*sin(A);
        glVertex2f(x,y);
    }
    glEnd();
}
void wheell5()
{

    glRotatef(angle4,2.0,2.0,1.0);
    glTranslatef(30.800,.0,.0);
    glColor3f(.0,.0,.0);
    glBegin(GL_POLYGON);
    for(int i = 0 ; i<200; i++)
    {
        float A = (i*2*PI)/50;
        float r = 12.15;
        float x = r* cos(A);
        float y = r*sin(A);
        glVertex2f(x,y);
    }
    glEnd();
}
void wheell6()
{

    glRotatef(angle4,2.0,2.0,1.0);
    glTranslatef(-130.800,.0,.0);
    glColor3f(.0,.0,.0);
    glBegin(GL_POLYGON);
    for(int i = 0 ; i<200; i++)
    {
        float A = (i*2*PI)/50;
        float r = 12.15;
        float x = r* cos(A);
        float y = r*sin (A);
        glVertex2f(x,y);
    }
    glEnd();
}
void wheell7()
{

    glRotatef(angle4,2.0,2.0,1.0);
    glTranslatef(30.800,.0,.0);
    glColor3f(.0,.0,.0);
    glBegin(GL_POLYGON);
    for(int i = 0 ; i<200; i++)
    {
        float A = (i*2*3.14)/50;
        float r = 12.15;
        float x = r* cos(A);
        float y = r*sin(A);
        glVertex2f(x,y);
    }
    glEnd();
}

void train()
{

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(angle1,.0,.0);
    glColor3f(1,0,0);

    // front body have have 3mod
    glBegin(GL_POLYGON);
    glColor3f(1.0,.940,.0);
    glVertex2i(-200,-10);
    glVertex2i(-200,-60);
    glVertex2i(-140,-60);
    glVertex2i(-140,-10);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.184,.310,310);
    glVertex2i(-140,-60);
    glVertex2i(-140,-35);
    glVertex2i(-130,-60);
    glEnd();



    glBegin(GL_POLYGON); //light
    glColor3f(.184,.310,310);
    glVertex2i(-140,-30);
    glVertex2i(-140,-15);
    glVertex2i(-135,-15);
    glVertex2i(-135,-30);
    glEnd();


    glBegin(GL_POLYGON);//chminy
    glColor3f(.863,.078,.235);
    glVertex2i(-170,-10);
    glVertex2i(-170,20);
    glVertex2i(-150,20);
    glVertex2i(-150,-10);
    glEnd();

    glBegin(GL_POLYGON); //chminy conn
    glColor3f(.184,.310,310);
    glVertex2i(-175,20);
    glVertex2i(-175,25);
    glVertex2i(-145,25);
    glVertex2i(-145,20);
    glEnd();


    glBegin(GL_POLYGON);//driver room window
    glColor3f(.663,.663,.663);
    glVertex2i(-250,-10);
    glVertex2i(-250,30);
    glVertex2i(-210,30);
    glVertex2i(-210,-10);
    glEnd();

    glBegin(GL_POLYGON); //driver room roof
    glColor3f(.184,.310,310);
    glVertex2i(-265,40);
    glVertex2i(-265,45);
    glVertex2i(-195,45);
    glVertex2i(-195,40);
    glEnd();


    glBegin(GL_POLYGON);//driver Box
    glColor3f(.184,.310,310);
    glVertex2i(-260,-60);
    glVertex2i(-260,40);
    glVertex2i(-200,40);
    glVertex2i(-200,-60);
    glEnd();

    //con
    glBegin(GL_POLYGON);
    glColor3f(.184,.310,310);
    glVertex2i(-260,-60);
    glVertex2i(-260,-50);
    glVertex2i(-280,-50);
    glVertex2i(-280,-60);
    glEnd();


    glBegin(GL_POLYGON); //roof
    glColor3f(.184,.310,310);
    glVertex2i(-365,40);
    glVertex2i(-365,45);
    glVertex2i(-275,45);
    glVertex2i(-275,40);
    glEnd();

    glBegin(GL_POLYGON);// window
    glColor3f(.663,.663,.663);
    glVertex2i(-350,-10);
    glVertex2i(-350,30);
    glVertex2i(-290,30);
    glVertex2i(-290,-10);
    glEnd();


    //middle polygon structure
    glBegin(GL_POLYGON);
    glColor3f(.294,0,.510);
    glVertex2i(-360,-60);
    glVertex2i(-360,40);
    glVertex2i(-280,40);
    glVertex2i(-280,-60);
    glEnd();

    glBegin(GL_POLYGON); //last car  window
    glColor3f(.663,.663,.663);
    glVertex2i(-450,-10);
    glVertex2i(-450,30);
    glVertex2i(-390,30);
    glVertex2i(-390,-10);
    glEnd();

    glBegin(GL_POLYGON); // body 2
    glColor3f(.0,.0,0);
    glVertex2i(-460,-60);
    glVertex2i(-460,50);
    glVertex2i(-380,50);
    glVertex2i(-380,-60);
    glEnd();


    glBegin(GL_POLYGON); //body 2 roof
    glColor3f(.184,.310,.310);
    glVertex2i(-465,40);
    glVertex2i(-465,45);
    glVertex2i(-375,45);
    glVertex2i(-375,40);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.184,.310,310);
    glVertex2i(-460,-60);
    glVertex2i(-460,40);
    glVertex2i(-380,40);
    glVertex2i(-380,-60);
    glEnd();

    wheell();
    wheell2();
    wheell3();
    wheell4();
    wheell5();
    wheell6();
    wheell7();

    glPopMatrix(); //train finished

}

void bird()
{

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(angle2,0.0,.0);
    glColor3f(.133,.545,.133);

    glBegin(GL_POLYGON);
    glVertex2i(-180,160);
    glVertex2i(-180,150);
    glVertex2i(-170,145);
    glVertex2i(-160,150);
    glVertex2i(-160,160);
    glEnd();

//green bird
    glBegin(GL_POLYGON);
    glColor3f(.180,.545,.341);
    glVertex2i(-160,150);
    glVertex2i(-160,160);
    glVertex2i(-150,157);
    glVertex2i(-152,152);
    glEnd();

//green bird
    glBegin(GL_POLYGON);
    glColor3f(1.000,0.000,0.000);
    glVertex2i(-145,135);
    glVertex2i(-150,137);
    glVertex2i(-152,132);
    glEnd();

//green bird

    glBegin(GL_POLYGON);
    glColor3f(.180,0.545,0.341);
    glVertex2i(-180,160);
    glVertex2i(-180,150);
    glVertex2i(-190,153);
    glVertex2i(-195,160);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.180,.545,.341);
    glVertex2i(-180,160);
    glVertex2i(-195,160);
    glVertex2i(-190,164);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.545,.271,.075);
    glVertex2i(-170,145);
    glVertex2i(-189,150);
    glVertex2i(-185,142);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.133,.545,.133);
    glVertex2i(-160,160);
    glVertex2i(-170,175);
    glVertex2i(-185,180);
    glVertex2i(-180,160);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(.180,.545,.341);
    glVertex2i(-185,180);
    glVertex2i(-180,178.33);
    glVertex2i(-190,170);
    glEnd();

    glPopMatrix();
}

void drawSceneDay()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    drawClock();
    train();
    railLine();
    plantsAtGround();
    Statn();
    plants();
    aiub();
    bird();
    bird2m();
    cloud();
    cloud2();
    sun();
    backGroundDay();
    glutSwapBuffers();
}
void update(int value)
{
    if (speed_train >1||speed_train<0)
    {
        speed_train = 0.0f;

    }
    angle1 += speed_train;

    if(angle1 > 800)
    {
        angle1 -= 1000;

    }
    if(speed_bird>1 || speed_bird<0)
    {
        speed_bird = 0.0f;
    }
    angle2 += speed_bird;
    if(angle2 >500)
    {
        angle2 -= 800;
    }
    glutTimerFunc(20,update,0); //recursion
}

void specialKeys(int key,int x, int y)
{


    switch(key)
    {
    case GLUT_KEY_UP:
        speed_train+= 0.05f;
        update(0);
        break;

    case GLUT_KEY_DOWN:
        speed_train-= 0.05f;
        update(0);
        break;

    case GLUT_KEY_RIGHT:
        speed_bird+= 0.05f;
        update(0);
        break;

    case GLUT_KEY_LEFT:
        speed_bird-= 0.05f;
        update(0);
        break;

    case GLUT_KEY_F11:
        glutFullScreen();
        break;
    case GLUT_KEY_F12:
        glutReshapeWindow(1200,800); // Set window size to original
        glutInitWindowPosition(0,0);
        break;

    }
}
int main(int argc, char** argv)
{
    //basic setup
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(1200,800);
    glutCreateWindow("Ziad AHmed Mohamed Hassan / 211010307");
    glutDisplayFunc(drawSceneDay);

    // know which button is clicked
    glutSpecialFunc(specialKeys);
    initRendering();
    glutIdleFunc(idle);
    init();
    glutKeyboardFunc(handleKeyPress);
    glutTimerFunc(20,update,0);
    glutMainLoop();
    return 0 ;
}

