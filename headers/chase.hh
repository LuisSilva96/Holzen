# ifndef CHASE_STATE_MODULE
# define CHASE_STATE_MODULE

# include <state.hh>
# include <alert.hh>
# include <attack.hh>

class Chase : public State
{
public:
  ~Chase()override{}
  void behave(Creature &, Entity &, double) override;
};

# endif
