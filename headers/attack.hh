# ifndef ATTACKING_STATE_MODULE
# define ATTACKING_STATE_MODULE

# include <state.hh>
# include <alert.hh>
# include <chase.hh>

class Attack : public State
{
public:
  ~Attack()override{}
  void behave(Creature &, Entity &, double) override;
};

# endif
