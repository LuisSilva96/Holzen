# ifndef NONINTERACTUABLE_CLASS
# define NONINTERACTUABLE_CLASS

# include <object.hh>

class Noninteractuable : public Object
{
public:
  explicit Noninteractuable();
  Object_Type get_type() override;
  void behave(Entity &) override;
};

# endif
