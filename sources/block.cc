# include <block.hh>

constexpr unsigned HP = 10;
constexpr unsigned DEF = 4;
constexpr unsigned ATCK = 4;
constexpr unsigned LVL = 4;
constexpr unsigned EXP = 4;
constexpr unsigned COLRECTw = 32;
constexpr unsigned COLRECTh = 44;
constexpr double REACH = 150;
constexpr double SPEED = 400;

Block::Block(const QVector2D & position, Object_Type tp) 
{
  sprites = new QPixmap*[4];

  for(int i = 0; i < 4; i++)
    sprites[i] = new QPixmap[3];

  sprites[0][0].load(":/creatures/sprites/d1.png");
  sprites[0][1].load(":/creatures/sprites/d2.png");
  sprites[0][2].load(":/creatures/sprites/d3.png");
  sprites[1][0].load(":/creatures/sprites/ug1.png");
  sprites[1][1].load(":/creatures/sprites/ug2.png");
  sprites[1][2].load(":/creatures/sprites/ug3.png");
  sprites[2][0].load(":/creatures/sprites/lg1.png");
  sprites[2][1].load(":/creatures/sprites/lg2.png");
  sprites[2][2].load(":/creatures/sprites/lg3.png");
  sprites[3][0].load(":/creatures/sprites/dg1.png");
  sprites[3][1].load(":/creatures/sprites/dg2.png");
  sprites[3][2].load(":/creatures/sprites/dg3.png");

  
  this->set_hp(HP);
  this->set_def(DEF);
  this->set_atck(ATCK);
  this->set_pos(position);
  this->set_lvl(LVL);
  this->set_exp(EXP);
  this->set_vel(QVector2D(0,0));
  this->set_state(new Alert());
  this->set_drop(tp);
  this->set_col_rect(QRect(position.x(),position.y(),
			   COLRECTw,COLRECTh));
  this->set_speed(SPEED);
}

Block::Block(QVector2D && position, Object_Type tp) 
{
  sprites = new QPixmap*[4];

  for(int i = 0; i < 4; i++)
    sprites[i] = new QPixmap[3];

  sprites[0][0].load(":/creatures/sprites/d1.png");
  sprites[0][1].load(":/creatures/sprites/d2.png");
  sprites[0][2].load(":/creatures/sprites/d3.png");
  sprites[1][0].load(":/creatures/sprites/ug1.png");
  sprites[1][1].load(":/creatures/sprites/ug2.png");
  sprites[1][2].load(":/creatures/sprites/ug3.png");
  sprites[2][0].load(":/creatures/sprites/lg1.png");
  sprites[2][1].load(":/creatures/sprites/lg2.png");
  sprites[2][2].load(":/creatures/sprites/lg3.png");
  sprites[3][0].load(":/creatures/sprites/dg1.png");
  sprites[3][1].load(":/creatures/sprites/dg2.png");
  sprites[3][2].load(":/creatures/sprites/dg3.png");

  
  this->set_hp(HP);
  this->set_def(DEF);
  this->set_atck(ATCK);
  this->set_pos(position);
  this->set_lvl(LVL);
  this->set_exp(EXP);
  this->set_state(new Alert());
  this->set_drop(tp);
  this->set_col_rect(QRect(position.x()+COLRECTw/2,position.y()+COLRECTw/2,
			   COLRECTw,COLRECTh));
  this->set_speed(SPEED);
}

Block::~Block()
{
}

void Block::update(Entity & prey, double & dt)
{
  //this->table(prey.get_pos());
  auto ptr = this->get_state();
  ptr->behave(*this, prey, dt);
}

void Block::draw(QPainter & painter)
{
  painter.drawPixmap(get_pos().toPoint(), sprites[row][col]);  
  return;
}

void Block::sprite_manager(Sprite_Direction dir)
{
  switch (dir)
    {
    case Sprite_Direction::LEFT :
      {
	// cerr << "LEFT\n";
	this->row = 2;
	return;
      }
    case Sprite_Direction::RIGHT :
      {
	// cerr << "RIGHT\n";
	this->row = 3;
	return;
      }
    case Sprite_Direction::UP :
      {
	// cerr << "UP\n";
	this->row = 1;
	return;
      }
    case Sprite_Direction::DOWN :
      {
	// cerr << "DOWN\n";
	this->row = 0;
	return;
      }
    }
}

void Block::move(double & t)
{
  auto vel = this->get_vel();
  if ( vel.x() > vel.y())
    {
      if ( vel.x() > 0)
	this->sprite_manager(Sprite_Direction::RIGHT);
      else
	this->sprite_manager(Sprite_Direction::LEFT);
    }
  else
    {
      if (vel.y() > 0)
	this->sprite_manager(Sprite_Direction::DOWN);
      else
	this->sprite_manager(Sprite_Direction::UP);
    }

  if (col == 2)
    col = 0;
  col++;  

  // cerr << col << '\t' << row << endl;
  
  this->set_pos((this->get_pos())+(this->get_vel()*t));
  this->set_col_rect(QRect(this->get_pos().x(),
			   this->get_pos().y(),
			   sprites[row][col].width()
			   ,sprites[row][col].height()));
  
  return;
}

void Block::move(double && t)
{
  auto vel = this->get_vel();
  if ( vel.x() > vel.y())
    {
      if ( vel.x() > 0)
	this->sprite_manager(Sprite_Direction::RIGHT);
      else
	this->sprite_manager(Sprite_Direction::LEFT);
    }
  else
    {
      if (vel.y() > 0)
	this->sprite_manager(Sprite_Direction::DOWN);
      else
	this->sprite_manager(Sprite_Direction::UP);
    }

  if (col == 2)
    col = 0;
  col++;  

  // cerr << col << '\t' << row << endl;
  
  this->set_pos((this->get_pos())+(this->get_vel()*t));
  this->set_col_rect(QRect(this->get_pos().x(),
			   this->get_pos().y(),
			   sprites[row][col].width()
			   ,sprites[row][col].height()));
  
  return;
}

Creature_Type Block::type()
{
  return Creature_Type::BLOCK;
}

void Block::table(QVector2D prey)
{
  /*cerr << "Posición: " << this->get_pos().x() << '\t' << this->get_pos().y() << endl;
  cerr << "Velocidad: " << this->get_vel().x() << '\t' << this->get_vel().y() << endl;
  cerr << "Prey position: " << prey.x() << '\t' << prey.y() << endl;
  cerr << "Distance between: " << (prey - this->get_pos()).length() << endl;
	*/
  return;
}
