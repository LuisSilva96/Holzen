#ifndef ARROW_CLASS
#define ARROW_CLASS

# include <armament.hh>

class Arrow: public Armament
{
private:
  void update_col_rec();

  QPixmap sprites[4];
  int row = 0;
  int speed;
  QVector2D lpos;
  
public:
  Arrow(const QVector2D &);
  Arrow(const QVector2D &, int);
  ~Arrow() override{}

  void draw(QPainter &)override;

  Object_Type get_type() override;

  void damage(Entity &, Entity &) override;

  void move();

  QVector2D & get_lpos();
};

#endif // ARROW_HH
