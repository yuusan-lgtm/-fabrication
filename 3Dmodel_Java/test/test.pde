PShape airplane;
PShape iland;
PShape cloud;
float pX, pY;
float a;
float b,c,d,e ;

void setup() {
  airplane=loadShape("飛行機.obj");
  iland = loadShape("untitled-1.obj");
  cloud = loadShape("雲.obj");
  size(700, 600, P3D);
  frameRate(60);
  airplane.scale(20);
  iland.scale(30);
  cloud.scale(20);
  noStroke();
}

void draw() {
  background(#6080ff);
  translate(width/2, height/2, 0);
  lights();

  if (mousePressed == true) {
    pX += (mouseX - pmouseX)*0.02;
  }
  if (mousePressed == true) {
    pY += (mouseY - pmouseY)*0.02;
  } 
  //島  
  pushMatrix();
  translate(20, -250, 0);
  rotateX(pY);
  rotateY(pX);
  shape(iland);
  popMatrix();
  //飛行機  
  pushMatrix();
  translate(100, -510, 0);
  rotateX(pY);
  rotateY(pX);
  translate(-100*a, 300, 0 );
  shape(airplane);
  popMatrix();
  a += 0.03;
  if (a >= 4) {
    a = 0;
  }
  //雲  
  pushMatrix();
  translate(100, -350, 0);
  rotateX(pY);
  rotateY(pX);
  translate(-100*b, 260, -120 );
  shape(cloud);
  popMatrix();
  b += Math.random()/70;
  if (b >= 3) {
    b = 0;
  }
  pushMatrix();
  translate(100, -350, 0);
  rotateX(pY);
  rotateY(pX);
  translate(-100*c, 260, 40 );
  shape(cloud);
  popMatrix();
  c += Math.random()/100;
  if (c >= 3) {
    c = 0;
  }
  pushMatrix();
  translate(100, -350, 0);
  rotateX(pY);
  rotateY(pX);
  translate(-100*d, 260, 40 );
  shape(cloud);
  popMatrix();
  d += Math.random()/90;
  if (d >= 3) {
    d = 0;
  }
  pushMatrix();
  translate(100, -350, 0);
  rotateX(pY);
  rotateY(pX);
  translate(-100*e, 260, 120 );
  shape(cloud);
  popMatrix();
  e += Math.random()/80;
  if (e >= 3) {
    e = 0;
  }
}
