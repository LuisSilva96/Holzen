# ifndef CREATURE_BASE_CLASS
# define CREATURE_BASE_CLASS

# include <entity.hh>
# include <smallhealthpotion.hh>
# include <bighealthpotion.hh>
# include <smallmanapotion.hh>
# include <bigmanapotion.hh>
# include <state.hh>
# include <chrono>
# include <random>

class State;

enum class Sprite_Direction
  {LEFT, RIGHT, UP, DOWN};

enum class Creature_Type
  {BLOCK, BEE};

class Creature : public Entity
{
protected:
  State * as;
  State * ps;
  
private:
  Object * obj;
  Sprite_Direction direction; 
  double speed;
  
public:

  explicit Creature(){}
  explicit Creature(const Creature &){} 
  explicit Creature(const QVector2D & , Object_Type){}
  explicit Creature(QVector2D &&, Object_Type){}
  virtual ~Creature();

  void set_drop(Object_Type);
  void set_state(State *);
  void set_speed(long double);
  
  Object * get_drop() const;
  State * get_state() const;
  double get_speed();
  
  void calc_vel(const QVector2D &, long double);
  void calc_vel(const QVector2D &&, long double);
  virtual void move(double &) = 0;
  virtual void move(double &&) = 0;
  void recieve_damage(const Entity &)override;
  
  virtual void update(Entity &, double &) = 0;
  virtual void sprite_manager(Sprite_Direction) = 0;
  virtual void draw(QPainter &) = 0;
  virtual Creature_Type type() = 0;
};

# endif
