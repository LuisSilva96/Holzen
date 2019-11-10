# include <arrow.hh>

void Arrow::update_col_rec()
{
  QRect current_rect;
  current_rect.setX(get_x());
  current_rect.setY(get_y());
  current_rect.setHeight(sprites[row].height());
  current_rect.setWidth(sprites[row].width());

  set_collision_rect(current_rect);
}

Arrow::Arrow(const QVector2D &p)
{
  QPixmap sprite(":/arrow/sprites/ArrowU.png");

  set_object_sprite(sprite);

  set_x(p);
  set_y(p);

  set_collision(false);
  update_col_rec();
}

Arrow::Arrow(const QVector2D &p, int _row)
  : speed(12), lpos(p)
{
  sprites[3].load(":/arrow/sprites/ArrowU.png");
  sprites[0].load(":/arrow/sprites/ArrowD.png");
  sprites[1].load(":/arrow/sprites/ArrowL.png");
  sprites[2].load(":/arrow/sprites/ArrowR.png");

  set_x(p);
  set_y(p);

  row = _row;
  
  set_collision(false);
  update_col_rec();
}

void Arrow::move()
{
  if (row == 0)
    {
      set_y(get_y() + speed);

      if (get_y() < 0)
    	set_y(0);
    }
  else if(row == 1)
    {
      set_x(get_x() - speed);
    }
  else if(row == 2)
    {
      set_x(get_x() + speed);

      if (get_x() < 0)
	set_x(0);
    }
  else if(row == 3)
    {
      set_y(get_y() - speed);
    }
  update_col_rec();
}

void Arrow::draw(QPainter & painter)
{
  //  painter.drawRect(this->get_collision_rect());
  painter.drawPixmap(get_x(),get_y(), sprites[row]);
}

Object_Type Arrow::get_type()
{
  return Object_Type::ARROW;
}

void Arrow::damage(Entity & prey, Entity & hunter)
{
  prey.recieve_damage(hunter);
}

QVector2D & Arrow::get_lpos()
{
  return lpos;
}
