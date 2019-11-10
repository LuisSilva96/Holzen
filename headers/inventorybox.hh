# ifndef INVENTORYBOX_CLASS
# define INVENTORYBOX_CLASS

# include <htlist.H>
# include <consumable.hh>

class InventoryBox
{
private:
  Object * object;
  int counter;
  QPixmap nums[10];

public:
  InventoryBox();
  InventoryBox(Object *,const int);
  ~InventoryBox();

  void increase_counter();
  void decrease_counter();
  void set_counter(int);
  int get_counter();
  QPixmap get_num_sprite(int &);
  QPixmap get_sprite();
  void object_behave(Entity &);

  Object_Type get_type();
};

# endif
