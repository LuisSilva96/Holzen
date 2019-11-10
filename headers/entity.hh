# ifndef ENTITY_BASE_CLASS
# define ENTITY_BASE_CLASS

# include <QVector2D>
# include <QRect>
# include <QPixmap>
# include <QSet>
# include <QKeyEvent>


using namespace std;

class Entity
{
private:		
  unsigned hp;
  unsigned def;
  unsigned atck;
  unsigned mana;
  QVector2D vel;
  QVector2D pos;
  QRect col_rect;
  unsigned lvl;
  unsigned exp;

protected:
  
  QPixmap ** sprites;
  
public:
    
  virtual ~Entity(){}
 		
  void set_hp(const unsigned &);
  void set_def(const unsigned &);
  void set_atck(const unsigned &);
  void set_lvl(const unsigned &);
  void set_exp(const unsigned &);
  void set_vel(const QVector2D &);
  void set_pos(const QVector2D &);
  void set_pos_x(float &&);
  void set_pos_y(float &&);
  void set_col_rect(const QRect &);
  void set_col_rect_x(float &&);
  void set_col_rect_y(float &&);
  void set_col_rect_height(float &&);
  void set_col_rect_width(float &&);
  void set_hp(unsigned &&);
  void set_mana(const unsigned );
  void set_def(unsigned &&);
  void set_atck(unsigned &&);
  void set_lvl(unsigned &&);
  void set_exp(unsigned &&);
  void set_vel(QVector2D &&);
  void set_pos(QVector2D &&);
  void set_col_rect(QRect &&);
  void decreise_hp(unsigned &&);
  
  const unsigned & get_hp() const;
  const unsigned & get_mana() const;
  const unsigned & get_def() const;
  const unsigned & get_atck() const;
  const QVector2D & get_vel() const;
  const QVector2D & get_pos() const;
  const QRect & get_col_rect() const;
  const unsigned & get_lvl() const;
  const unsigned & get_exp() const;
  
  virtual void recieve_damage(const Entity &)= 0;
};

# endif
