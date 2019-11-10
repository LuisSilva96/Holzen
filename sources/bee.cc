# include <bee.hh>

constexpr unsigned HP = 4;
constexpr unsigned DEF = 1;
constexpr unsigned ATCK = 2;
constexpr unsigned LVL = 2;
constexpr unsigned EXP = 2;
constexpr unsigned COLRECTw = 10;
constexpr unsigned COLRECTh = 10;
constexpr long double SPEED = 900;

Bee::Bee(const QVector2D & position, Object_Type tp) 
{
  this->set_hp(HP);
  this->set_def(DEF);
  this->set_atck(ATCK);
  this->set_pos(position);
  this->set_lvl(LVL);
  this->set_exp(EXP);
  this->set_vel(QVector2D(0,0));
  this->set_state(new Alert());
  this->set_drop(tp);
  this->set_col_rect(QRect(position.x()+COLRECTw/2,position.y()+COLRECTw/2,
			   COLRECTw,COLRECTh));
  this->set_speed(SPEED);
}

Bee::Bee(QVector2D && position, Object_Type tp) 
{
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

Bee::~Bee()
{
}

void Bee::update(Entity & prey, double & dt)
{
  this->table(prey.get_pos());
  auto ptr = this->get_state();
  ptr->behave(*this, prey, dt);
}

void Bee::draw(QPainter & painter)
{
  
  //painter.drawRect(this->get_col_rect());
  return;
}

void Bee::sprite_manager(Sprite_Direction dir)
{
  switch (dir)
    {
    case Sprite_Direction::LEFT :
      {
      }
    case Sprite_Direction::RIGHT :
      {
      }
    case Sprite_Direction::UP :
      {
      }
    case Sprite_Direction::DOWN :
      {
      }
    }
}

void Bee::move(double & t)
{
  this->set_pos((this->get_pos())+(this->get_vel()*t));
  this->set_col_rect(QRect(this->get_pos().x()+COLRECTw/2,
			   this->get_pos().y()+COLRECTh/2,
			   COLRECTw,COLRECTh));
  
  return;
}

void Bee::move(double && t)
{
  this->set_pos((this->get_pos())+(this->get_vel()*t));
  this->set_col_rect(QRect(this->get_pos().x()+(COLRECTw/2),
			   this->get_pos().y()+(COLRECTh/2),
			   COLRECTw,COLRECTh));
  return;
}

Creature_Type Bee::type()
{
  return Creature_Type::BLOCK;
}

void Bee::table(QVector2D prey)
{
  /*cerr << "Posición: " << this->get_pos().x() << '\t' << this->get_pos().y() << endl;
  cerr << "Velocidad: " << this->get_vel().x() << '\t' << this->get_vel().y() << endl;
  cerr << "Prey position: " << prey.x() << '\t' << prey.y() << endl;
  cerr << "Distance between: " << (prey - this->get_pos()).length() << endl;
	*/
  return;
}
