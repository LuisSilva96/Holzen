# ifndef CONSUMABLE_CLASS
# define CONSUMABLE_CLASS

# include <object.hh>
//# include <entity.hh>

class Consumable : public Object
{

public:
  explicit Consumable();
  virtual ~Consumable() override{}
  //virtual void behave(Entity &) = 0;
  void behave(Entity &) override;
  Object_Type get_type() override;
};

# endif
