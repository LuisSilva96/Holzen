# ifndef ALERT_STATE_MODULE
# define ALERT_STATE_MODULE

# include <state.hh>
# include <chase.hh>
# include <attack.hh>

class Alert : public State
{
public:
  ~Alert()override{}
  void behave(Creature &, Entity &, double) override;
};

# endif
