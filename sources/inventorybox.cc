# include "inventorybox.hh"

InventoryBox::InventoryBox()
{
  counter = 0;
}

InventoryBox::InventoryBox(Object * _object, const int _counter)
{
  object = _object;
  counter = _counter;
}

InventoryBox::~InventoryBox()
{
  //empty
}

void InventoryBox::increase_counter()
{
  counter++;
}

void InventoryBox::set_counter(int _counter)
{
  counter = _counter;
}

int InventoryBox::get_counter()
{
  return counter;
}

void InventoryBox::decrease_counter()
{
  if(get_counter() > 1)
  {
    counter--;
  }
}

QPixmap InventoryBox::get_num_sprite(int & num)
{
  nums[0].load(":/numbers/sprites/numbers-2.png");
  nums[1].load(":/numbers/sprites/numbers-1.png");
  nums[2].load(":/numbers/sprites/numbers-3.png");
  nums[3].load(":/numbers/sprites/numbers-4.png");
  nums[4].load(":/numbers/sprites/numbers-5.png");
  nums[5].load(":/numbers/sprites/numbers-6.png");
  nums[6].load(":/numbers/sprites/numbers-7.png");
  nums[7].load(":/numbers/sprites/numbers-8.png");
  nums[8].load(":/numbers/sprites/numbers-9.png");
  nums[9].load(":/numbers/sprites/numbers-10.png");

  return nums[num];
}

QPixmap InventoryBox::get_sprite()
{
  return object->get_object_sprite();
}

void InventoryBox::object_behave(Entity & hero)
{
  object->behave(hero);
}

Object_Type InventoryBox::get_type()
{
  return object->get_type();
}
