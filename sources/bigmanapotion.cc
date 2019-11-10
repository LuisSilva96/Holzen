# include <bigmanapotion.hh>
# include <hero.hh>

constexpr unsigned MANA = 5;

BigManaPotion::BigManaPotion() :
  mana(MANA)
{
  QPixmap sprite(":/objects/sprites/bigmana.png");

  set_object_sprite(sprite);
}

BigManaPotion::BigManaPotion(const QVector2D & _position)
  : mana(MANA)
{
  QPixmap sprite(":/objects/sprites/bigmana.png");

  set_object_sprite(sprite);

  QRect _collision_rect;

  _collision_rect.setX(_position.x());
  _collision_rect.setY(_position.y());
  _collision_rect.setWidth(get_object_sprite().width());
  _collision_rect.setHeight(get_object_sprite().height());

  set_collision_rect(_collision_rect);

  set_x(_position);
  set_y(_position);

}

void BigManaPotion::behave(Entity & hero)
{
  dynamic_cast<Hero &>(hero).increment_life(this->mana);
}

Object_Type BigManaPotion::get_type()
{
  return Object_Type::SMALLMANAPOTION;
}
