# ifndef STATE_CLASS_MODULE
# define STATE_CLASS_MODULE

# include <creature.hh>

class Creature;

class State
{
public:
  virtual ~State(){}
  virtual void behave(Creature &, Entity &, double) = 0;
};

# endif
