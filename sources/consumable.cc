# include "consumable.hh"
# include <QDebug>

Consumable::Consumable()
{

  //empty

}
/*
void Consumable::behaviour(const QString & _identifier)
{
  //empty
}
*/
void Consumable::behave(Entity & hero)
{
  //empty
}

Object_Type Consumable::get_type()
{
  return Object_Type::CONSUMABLE;
}
