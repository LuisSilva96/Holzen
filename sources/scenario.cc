# include <scenario.hh>
# include <parser.hh>

Scenario::Scenario(QWidget * parent)
  : QWidget(parent), hero(QVector2D(WIDTH / 2, HEIGHT / 2))
{
  setWindowFlags(Qt::CustomizeWindowHint);
  
  now = new Now();
  
  Parser p("scenario.txt");
  
  p.build_scenario(*this);

  //Metodo de musica errores al compilar
  /*
    music = new QMediaPlayer(this);
    music->setMedia(QUrl("qrc:/sounds/sprites/Zelda WW - Dragon Roost Island Orchestra.mp3"));
    connect(music,SIGNAL(stateChanged(QMediaPlayer::State)),SLOT(replayMusic(QMediaPlayer::State)));
  */
}

void Scenario::slot_update()
{
  DynList<Object *> objects1;

  auto dt = now->elapsed() / 1000.0;

  hero.update(dt);

  for (auto item : creatures)
    item->update(hero,dt);

  for (auto arr : arrows)
    arr->move();

  armament_colliding();

  clean_creature();
  clean_arrow();
  
  for (auto item : objects)
    if(!item->get_deleting())
      objects1.append(item);
     
  for (auto item : interactuables)
    {
     item->behave(hero);
     
     if(static_cast<Interactuable *>(item)->get_current_sprite())
     {
     	 objects1.append(new SmallHealthPotion(QVector2D(item->get_x() - 20, item->get_y())));
     	 
     	 static_cast<Interactuable *>(item)->set_current_sprite(0);
     }
    }
  
  objects.swap(objects1);

  repaint();
}

void Scenario::slot_for_inventory()
{
  repaint();
}

void Scenario::slot_for_dying()
{
  if (hero.get_hp() <= 1)
    {
      hero_dead = true;
      paused = false;

      timer.stop();
      timer2.stop();
      timer3.stop();

      this->hide();

      menu->show();
    }
}

void Scenario::start()
{
  connect(&timer, SIGNAL(timeout()), this, SLOT(slot_update()));

  timer.setInterval(60);
  timer.start();

  connect(&timer2, SIGNAL(timeout()), this, SLOT(slot_for_dying()));

  timer2.setInterval(1);
  timer2.start();

  connect(&timer3, SIGNAL(timeout()), this, SLOT(slot_for_inventory()));

  timer3.setInterval(60);
  timer3.start();

  now->start();
}

void Scenario::unpause()
{
  timer.start(60);
  timer2.start(1);
  timer3.start(60);

  now = new Now();
  now->start();
}

void Scenario::paintEvent(QPaintEvent *)
{
  QPainter painter(this);

  //music->setVolume(40);
  //music->play();

  QImage * img = new QImage(":/scenario/sprites/suelo.png");

  //FONDO MARRON
  *img = img->copy(1, 34, 15, 15);
  //FONDO VERDE CON PIEDRAS
  //*img = img->copy(69, 18, 15, 15);

  //FONDO GRIS
  //*img = img->copy(19, 34, 15, 15);

  //FONDO BLANCO
  //*img = img->copy(35, 34, 15, 15);

  //FONDO MARRON 3
  //*img = img->copy(35, 69, 15, 15);

  QBrush bg_brush(*img);

  //cambio el tamaño del escenario al del menu
  this->resize(menu->width(), HEIGHT);
  setWindowState(Qt::WindowActive);

  painter.fillRect(0, 0, this->width(), this->height(), bg_brush);

  if(hero.get_pos().x() > this->width())
    hero.set_pos_x(this->width() - 50);

  for (auto item : creatures)
    item->draw(painter);

  for (auto obj : objects)
    painter.drawPixmap(obj->get_x(), obj->get_y(), obj->get_object_sprite());

  for (auto obj : background_objects)
    obj->draw(painter);
    
  for (auto obj : interactuables)
    painter.drawPixmap(obj->get_x(), obj->get_y(), obj->get_object_sprite());

  for (auto arr : arrows)
    arr->draw(painter);
    
  hero.draw(painter);
  hero.draw_inventory(painter);
}

void Scenario::keyPressEvent(QKeyEvent * evt)
{
  switch (evt->key())
    {
      case Qt::Key_Q:
      {
        if(hero.get_mana() > 1 and hero.hide_inventory() and not hero.is_attacking() )
				{
					Arrow * arrow;

					hero.Q_ability();

					if(hero.get_row() == 1 or hero.get_row() == 2)
					{
					  arrow = new Arrow(QVector2D(hero.get_pos().x(), hero.get_pos().y()
								+ 20), hero.get_row());
						arrows.append(arrow);
						
						arrow = new Arrow(QVector2D(hero.get_pos().x(), hero.get_pos().y()
								+ 10), hero.get_row());
						arrows.append(arrow);		
						
						arrow = new Arrow(QVector2D(hero.get_pos().x(), hero.get_pos().y()
								+ 30), hero.get_row());
						arrows.append(arrow);		
					}
					else if(hero.get_row() == 0 or hero.get_row() == 3)
					{
					  arrow = new Arrow(QVector2D(hero.get_pos().x() + 25,
								hero.get_pos().y()), hero.get_row());
						arrows.append(arrow);		
						
						arrow = new Arrow(QVector2D(hero.get_pos().x() + 35,
								hero.get_pos().y()), hero.get_row());
						arrows.append(arrow);		
						
						arrow = new Arrow(QVector2D(hero.get_pos().x() + 15,
								hero.get_pos().y()), hero.get_row());
						arrows.append(arrow);		
					}
					
					
				}
      }
      break;
    
    case Qt::Key_Space:
      {
        if(not hero.is_attacking() and hero.hide_inventory())
				{
					Arrow * arrow;

					hero.attack();

					if(hero.get_row() == 1 or hero.get_row() == 2)
					  arrow = new Arrow(QVector2D(hero.get_pos().x(), hero.get_pos().y()
								+ 20), hero.get_row());
					else if(hero.get_row() == 0 or hero.get_row() == 3)
					  arrow = new Arrow(QVector2D(hero.get_pos().x() + 25,
								hero.get_pos().y()), hero.get_row());

					arrows.append(arrow);
				}
      }
      break;
    case Qt::Key_Up:
      {
        if(hero.hide_inventory())
          hero.move(evt, this->width(), this->height(), background_objects, interactuables);
        else
	  {
	    if(hero.hide_inventory_options())
	      hero.update_selected_position(0,-1);
	    else
	      {
		hero.update_selected_options(-1);
	      }
	  }
      }

      break;
    case Qt::Key_Right:
      {
        if(hero.hide_inventory())
          hero.move(evt, this->width(), this->height(), background_objects, interactuables);
        else
	  {
	    if(hero.hide_inventory_options())
	      hero.update_selected_position(1,0);
	    else
	      {

	      }
	  }
      }

      break;
    case Qt::Key_Down:
      {
        if(hero.hide_inventory())
          hero.move(evt, this->width(), this->height(), background_objects, interactuables);
        else
	  {
	    if(hero.hide_inventory_options())
	      hero.update_selected_position(0,1);
	    else
	      {
		hero.update_selected_options(1);
	      }
	  }
      }

      break;
    case Qt::Key_Left:
      {
        if(hero.hide_inventory())
          hero.move(evt, this->width(), this->height(), background_objects, interactuables);
        else
	  {
	    if(hero.hide_inventory_options())
	      hero.update_selected_position(-1,0);
	    else
	      {

	      }
	  }
      }

      break;
    case Qt::Key_Z:
      {
        if(hero.hide_inventory())
          hero.picking_object(objects);
        else
	  {
	    if(!hero.get_options())
	      {
		hero.select_option();
	      }
	    hero.update_options();
	  }
      }
      break;
    case Qt::Key_I:
      //si ya tengo abierto el inventario quito la pausa del juego
      if(not hero.hide_inventory())
    	{
    	  this->unpause();
    	  hero.update_inventory();
    	  break;
    	}
      
      hero.update_inventory();
      timer.stop();
      break;
    case Qt::Key_Escape:
      {
    	timer.stop();
    	timer2.stop();

    	this->hide();
    	menu->show();
    	paused = true;
      }
      break;
    }
}

void Scenario::keyReleaseEvent(QKeyEvent * evt)
{
  hero.release_key(evt);
}

void Scenario::make_creature(QVector2D & vect, Object_Type tp, Creature_Type ctp)
{
  switch(ctp)
    {
    case Creature_Type::BLOCK:
      {
	this->creatures.append(new Block(vect,tp));
	return;
      }
    case Creature_Type::BEE:
      {
	this->creatures.append(new Bee(vect,tp));
	return;
      }
    }
}

void Scenario::make_creature(QVector2D && vect, Object_Type tp, Creature_Type ctp)
{
  switch(ctp)
    {
    case Creature_Type::BLOCK:
      {
	this->creatures.append(new Block(vect,tp));
	return;
      }
    case Creature_Type::BEE:
      {
	this->creatures.append(new Bee(vect,tp));
	return;
      }
    }
}

void Scenario::make_creature(QVector2D & vect, Creature_Type ctp)
{
  srand(time(NULL));
	int rands = 1 + rand() % 7;

  switch(ctp)
    {
    case Creature_Type::BLOCK:
      {
	this->creatures.append(new Block(vect, static_cast<Object_Type>(rands)));
	return;
      }
    case Creature_Type::BEE:
      {
	this->creatures.append(new Bee(vect, static_cast<Object_Type>(rands)));
	return;
      }
    }
}

void Scenario::make_creature(QVector2D && vect, Creature_Type ctp)
{
  srand(time(NULL));
	int rands = 1 + rand() % 7;
	
  switch(ctp)
    {
    case Creature_Type::BLOCK:
      {  
	this->creatures.append(new Block(vect, static_cast<Object_Type>(rands)));
	return;
      }
    case Creature_Type::BEE:
      {
	this->creatures.append(new Bee(vect, static_cast<Object_Type>(rands)));
	return;
      }
    }
}

void Scenario::make_consumable(QVector2D && pos, Object_Type obj)
{
  switch(obj)
    {
    case Object_Type::SMALLHEALTHPOTION:
      {
	this->objects.append(new SmallHealthPotion(pos));
	return;
      }
    case Object_Type::ARROW:
      {
	this->objects.append(new Arrow(pos));
	return;
      }
    case Object_Type::BIGHEALTHPOTION :
      {
	this->objects.append(new BigHealthPotion(pos));
	return;
      }
    case Object_Type::SMALLMANAPOTION :
      {
	this->objects.append(new SmallManaPotion(pos));
	return;
      }
    case Object_Type::BIGMANAPOTION :
      {
	this->objects.append(new BigManaPotion(pos));
	return;
      }
    }
}

void Scenario::make_consumable(const QVector2D & pos, Object_Type obj)
{
  switch(obj)
    {
    case Object_Type::SMALLHEALTHPOTION:
      {
	this->objects.append(new SmallHealthPotion(pos));
	return;
      }
    case Object_Type::ARROW:
      {
	this->objects.append(new Arrow(pos));
	return;
      }
    case Object_Type::BIGHEALTHPOTION :
      {
	this->objects.append(new BigHealthPotion(pos));
	return;
      }
    case Object_Type::SMALLMANAPOTION :
      {
	this->objects.append(new SmallManaPotion(pos));
	return;
      }
    case Object_Type::BIGMANAPOTION :
      {
	this->objects.append(new BigManaPotion(pos));
	return;
      }
    }
}


void Scenario::make_background_object(QVector2D && pos, Object_Type obj)
{
  switch(obj)
    {
    case Object_Type::BUSH:
      {
	this->background_objects.append(new Bush(pos));
	return;
      }
    case Object_Type::TREE:
      {
      	int random_sprite = rand() % 2;
      	this->background_objects.append(new Tree(pos, random_sprite));
	return;
      }
    }
}

void Scenario::make_interactuable(QVector2D && pos, Object_Type obj)
{
  switch(obj)
    {
    case Object_Type::CHEST:
      {
	this->interactuables.append(new Chest(pos));
	return;
      }
    }
}

void Scenario::closeEvent(QCloseEvent *)
{
  this->~Scenario();
}

Scenario::~Scenario()
{
  for (auto item : creatures)
    delete item;

  for (auto item : objects)
    delete item;

  for (auto item : arrows)
    delete item;

  for (auto item : background_objects)
    delete item;

  delete now;
  //delete music;
}

bool Scenario::is_paused()
{
  return this->paused;
}

bool Scenario::is_hero_dead()
{
  return this->hero_dead;
}

void Scenario::clean_arrow()
{

  DynList<Arrow *>::iterator it(this->arrows);

  while (it.has_current())
    {
      auto arrow = it.get_current();

      if(arrow->get_pos().x() < -12 or arrow->get_pos().y() < -12 or
	 arrow->get_pos().x() > width() or arrow->get_pos().y() > height() or
	 arrow->get_collision() == true or
	 (arrow->get_pos() - arrow->get_lpos()).length() >= 300)
		it.del();
      else
	it.next();
    }

}

void Scenario::armament_colliding()
{
  for (auto arrow : arrows)
    {
      for (auto creature : creatures)
	if (arrow->colliding(creature->get_col_rect()))
	  arrow->damage(*creature,hero);

      for (auto objs : background_objects)
	arrow->colliding(objs->get_collision_rect());
    }
}

void Scenario::clean_creature()
{
  DynList<Creature *>::iterator it(this->creatures);

  while (it.has_current())
    {
      auto creature = it.get_current();      
      if(creature->get_hp() == 0)
	{
	  auto *obj = creature->get_drop();
	  if(obj != nullptr)
	  	make_consumable(creature->get_pos(),creature->get_drop()->get_type());
	  	
    hero.set_exp(hero.get_exp()+creature->get_exp());
	  it.del();
	}
      else
	it.next();
    }
}

//Metodo de musica errores al compilar
/*
  void Scenario::replay_music(QMediaPlayer::State s)
  {
  if (s == QMediaPlayer::StoppedState)
  music->play();
  }
*/
