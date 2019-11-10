#include <bar.hh>

Bar::Bar(const QVector2D pos, const QBrush brush, int s_x, int s_y)
{
  max_val = 1;
  current_val = 1;

  size_x = s_x;
  size_y = s_y;

  setRect(pos.x(), pos.y(), size_x, size_y);
  setBrush(brush);

  QPixmap sprite(":/scenario/sprites/bar.png");
  object_sprite = sprite;
}

void Bar::update_bar()
{
  double fill_fraction = double(current_val) / max_val;
  setRect(rect().x(), rect().y(), fill_fraction * size_x, size_y);
}

int Bar::get_current_val()
{
  return current_val;
}

void Bar::set_current_val(int v)
{
  current_val = v;
}

void Bar::set_max_val(int v)
{
  max_val = v;
}

void Bar::increment(int amount)
{
  current_val = current_val + amount;
  update_bar();
}

void Bar::decrement(int amount)
{
  current_val = current_val - amount;
  update_bar();
}

int Bar::get_size_x()
{
  return this->size_x;
}

int Bar::get_size_y()
{
  return this->size_y;
}

QPixmap Bar::get_sprite()
{
  return object_sprite;
}
