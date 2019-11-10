# include <entity.hh>

void Entity::set_hp(const unsigned & health)
{
  this->hp = health;
  return;
}

void Entity::set_mana(const unsigned mna)
{
  this->mana = mna;
  return;
}

void Entity::set_def(const unsigned & def)
{
  this->def = def;
  return;
}

void Entity::set_atck(const unsigned & a)
{
  this->atck = a;
  return;
}

void Entity::set_vel(const QVector2D & v)
{
  this->vel = v;
  return;
}

void Entity::set_pos(const QVector2D & pos)
{
  this->pos = pos;
  return;
}

void Entity::set_pos_x(float &&n)
{
  this->pos.setX(n);
  return;
}

void Entity::set_pos_y(float &&n)
{
  this->pos.setY(n);
  return;
}

void Entity::set_col_rect(const QRect & rect)
{
  this->col_rect = rect;
  return;
}

void Entity::set_col_rect_x(float && n)
{
  this->col_rect.setX(n);
  return;
}

void Entity::set_col_rect_y(float && n)
{
  this->col_rect.setY(n);
  return;
}

void Entity::set_col_rect_height(float && n)
{
  this->col_rect.setHeight(n);
  return;
}

void Entity::set_col_rect_width(float && n)
{
  this->col_rect.setWidth(n);
  return;
}

void Entity::set_lvl(const unsigned & level)
{
  this->lvl = level;
  return;
}

void Entity::set_exp(const unsigned & xp)
{
  this->exp = xp;
}		

void Entity::set_exp(unsigned && xp)
{
  this->exp = xp;
}		


void Entity::set_lvl(unsigned && level)
{
  this->lvl = level;
  return;
}

void Entity::set_hp(unsigned && health)
{
  this->hp = health;
  return;
}

void Entity::set_atck(unsigned && a)
{
  this->atck = a;
  return;
}

void Entity::set_def(unsigned && def)
{
  this->def = def;
  return;
}


void Entity::set_vel(QVector2D && v)
{
  this->vel = v;
  return;
}

void Entity::set_pos(QVector2D && pos)
{
  this->pos = pos;
  return;
}

void Entity::set_col_rect(QRect && rect)
{
  this->col_rect = rect;
  return;
}

void Entity::decreise_hp(unsigned &&dmg_received)
{
  if(dmg_received < this->hp)
    this->hp -= dmg_received;
  else
    this->hp = 0;
}

const unsigned int & Entity::get_hp()const
{
  return this->hp;
}

const unsigned int & Entity::get_mana()const
{
  return this->mana;
}

const unsigned int & Entity::get_def() const
{
  return this->def;
}

const unsigned int & Entity::get_atck() const
{
  return this->atck;
}

const QVector2D & Entity::get_vel() const
{
  return this->vel;
}

const QVector2D & Entity::get_pos() const
{
  return this->pos;
}

const QRect & Entity::get_col_rect() const
{
  return this->col_rect;
}

const unsigned int & Entity::get_lvl() const
{
  return this->lvl;
}

const unsigned int & Entity::get_exp() const
{
  return this->exp;
}
