# include <menu.hh>
# include <X11/Xlib.h>

# include <QPainter>
# include <QKeyEvent>

Menu::Menu(QWidget * parent) : QWidget(parent)
{
	//Metodos para saber tamaño de la pantalla usando la libreria X11/Xlib
	Display * disp = XOpenDisplay(NULL);
	Screen * scrn = DefaultScreenOfDisplay(disp);

	this->width_ = scrn->width;
	this->height_ = scrn->height; 

	//quito la barra de ventana 
	setWindowFlags(Qt::CustomizeWindowHint);
	
	//calculo lugar de los pixmap segun el ancho y alto de la pantalla
	PIXMAPS_X = (width_/2 - 80);
	PIXMAPS_Y = 200;

  cursor.setX(PIXMAPS_X - 150);
  cursor.setY(PIXMAPS_Y);

  op = Option::START;

  s = new Scenario();
}

void Menu::closeEvent(QCloseEvent *)
{
  this->~Menu();
}

void Menu::paintEvent(QPaintEvent *)
{
  QPainter painter(this);
  QPixmap *play, *configs, *exit, *qpix_cursor, *title;
  
  if(maximized)
  	this->resize(width_, height_);
  else
  	this->resize(width_ - (width_/5), height_);

  PIXMAPS_X  = (width()/2 - 80);
  
  cursor.setX(PIXMAPS_X - 150);

  //si esta pausado cambio el pixmap
  if(s->is_paused())
    play = new QPixmap(":menu/sprites/continue.png");
  else
    play = new QPixmap(":menu/sprites/play.png");

  //asigno los pixmap de las opciones del menu
  configs = new QPixmap(":menu/sprites/options.png");
  exit = new QPixmap(":menu/sprites/quit.png");
  qpix_cursor = new QPixmap(":menu/sprites/arrow.png");
  title = new QPixmap(":menu/sprites/titulo.png");

  //si no ha muerto sale el fondo normal
  if(not s->is_hero_dead())
  {
    QImage * img = new QImage(":/scenario/sprites/forest.jpg");
    QBrush bg_brush(*img);

    //pinto el fondo del menu
    painter.fillRect(0, 0, this->width(), this->height(), bg_brush);

    //pinto el titulo segun el ancho de la pantalla
    if(maximized)
    {
    	if(width() < 1100)
	  		painter.drawPixmap(50, 20, *title);
	  	else if(width() < 1200)
	  		painter.drawPixmap(120, 20, *title);
	  	else
	  		painter.drawPixmap(250, 20, *title);
    }
	  else
	  {
	  	if(width() < 900)
	  		painter.drawPixmap(5, 20, *title);
	  	else if(width() < 1000)
	  		painter.drawPixmap(40, 20, *title);
	  	else
	  		painter.drawPixmap(120, 20, *title);
	  }

    //pinto las opciones normales del menu
    if(not in_options)
    {
    	painter.drawPixmap(PIXMAPS_X, PIXMAPS_Y, *play);
	  	painter.drawPixmap(PIXMAPS_X, PIXMAPS_Y + 105, *configs);
	  	painter.drawPixmap(PIXMAPS_X, PIXMAPS_Y + 210, *exit);
	  	painter.drawPixmap(cursor.x(), cursor.y() - 20, *qpix_cursor);
    }
    else //pinto los pixmap que ofrece options
    {
    	exit = new QPixmap(":menu/sprites/back.png");
    	
    	//cambio el sprite de tamaño segun el tamaño del menu
    	if(maximized) 
    		configs = new QPixmap(":menu/sprites/minimized.png");
    	else
    		configs = new QPixmap(":menu/sprites/full_screen.png");
    	
    	painter.drawPixmap(PIXMAPS_X, PIXMAPS_Y + 105, *configs);
    	painter.drawPixmap(PIXMAPS_X, PIXMAPS_Y + 210, *exit);
    	painter.drawPixmap(cursor.x(), cursor.y() - 20, *qpix_cursor);
    }
  }
  else //menu al morir
  {
    //pinto el fondo del menu con game_over
    if(width() > 1100)
    {
    	QImage * img = new QImage(":/menu/sprites/game_overFULL.png");
    	QBrush bg_brush(*img);

    	painter.fillRect(0, 0, this->width(), this->height(), bg_brush);
    }
    else
    {
    	QImage * img = new QImage(":/menu/sprites/game_overMIN.png");
    	QBrush bg_brush(*img);

    	painter.fillRect(0, 0, this->width(), this->height(), bg_brush);
    }

    //pinto las opciones normales del menu
    if(not in_options)
    {
			painter.drawPixmap(PIXMAPS_X, PIXMAPS_Y + 55, *play);
	  	painter.drawPixmap(PIXMAPS_X, PIXMAPS_Y + 160, *configs);
	  	painter.drawPixmap(PIXMAPS_X, PIXMAPS_Y + 275, *exit);
	  	painter.drawPixmap(cursor.x(), cursor.y() + 35, *qpix_cursor);
    }
    else //pinto los pixmap que ofrece options
    {
    	exit = new QPixmap(":menu/sprites/back.png");
    	
    	//cambio el sprite de tamaño segun el tamaño del menu
    	if(maximized) 
    		configs = new QPixmap(":menu/sprites/minimized.png");
    	else
    		configs = new QPixmap(":menu/sprites/full_screen.png");

	  	painter.drawPixmap(PIXMAPS_X, PIXMAPS_Y + 160, *configs);
	  	painter.drawPixmap(PIXMAPS_X, PIXMAPS_Y + 275, *exit);
	  	painter.drawPixmap(cursor.x(), cursor.y() + 35, *qpix_cursor);
    }

    game_started = false;
  }
}

void Menu::keyPressEvent(QKeyEvent * evt)
{
  switch (evt->key())
  {
    case Qt::Key_Return:
    	if(in_options and op == Option::EXIT)
    	{
    		in_options = false;
    		repaint();
      	break;
    	}
    	if(in_options)
    	{
    		maximized = not maximized;
	    	
	    	repaint();
	    	break;
    	}

      choice(op);
      repaint();
      break;
    case Qt::Key_Up:
      if((cursor.y() <= 200) or (in_options and op == Option::CONFIGURATION))
       cursor.setY(410);
     	else
      	cursor.setY(cursor.y() - 105);

      switch(cursor.y())
        {
        case 200:
          op = Option::START;
          break;
        case 305:
          op = Option::CONFIGURATION;
          break;
        case 410:
          op = Option::EXIT;
          break;
        }
  
      repaint();
      break;
    case Qt::Key_Down:
    	if(in_options and op == Option::CONFIGURATION)
    		cursor.setY(410);
    	else if(in_options and op == Option::EXIT)
    		cursor.setY(305);
      else if(cursor.y() >= 410)
       cursor.setY(200);
     	else
      	cursor.setY(cursor.y() + 105);

      switch(cursor.y())
        {
        case 200:
          op = Option::START;
          break;
        case 305:
          op = Option::CONFIGURATION;
          break;
        case 410:
          op = Option::EXIT;
          break;
        }

      repaint();
      break;
    case Qt::Key_Escape:
    	if(s->is_paused())
    	{
    		in_options = false;
    		
    		op = Option::START;
    		choice(op);
    	}
  		break;
  }
}

void Menu::choice(Option op)
{
  switch (op)
  {
    case Option::START:
    	this->hide();
			
      if(s->is_hero_dead())
        s = new Scenario();

      if(not game_started)
      {
        s->start();
        game_started = true;
      }
			
			if(s->is_paused())
				s->unpause();
      
      s->show();
      break;
    case Option::CONFIGURATION:
    	in_options = true;
      break;
    case Option::EXIT:
    	close();
      break;
  }
}

Menu::~Menu()
{
	delete s;
}
