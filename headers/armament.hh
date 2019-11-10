# ifndef ARMAMENT_CLASS
# define ARMAMENT_CLASS

# include <object.hh>
# include <entity.hh>

class Armament : public Object
{
public:
  explicit Armament();
  virtual ~Armament();
  virtual void damage(Entity &, Entity &) = 0;

  bool get_collision();
  void set_collision(bool);
  bool colliding(const QRect &);
  void behave(Entity &) override;
private:
  bool collision;
};

# endif
