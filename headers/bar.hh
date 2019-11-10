#ifndef BAR_CLASS
#define BAR_CLASS

//QT INCLUDES
# include <QGraphicsRectItem>
# include <QPixmap>
# include <QVector2D>
# include <QBrush>

class Bar: public QGraphicsRectItem
{
private:
  int max_val;
  int current_val;
  int size_x;
  int size_y;
  QPixmap object_sprite;

public:
  explicit Bar(const QVector2D, const QBrush, int, int);
  ~Bar(){}
  void update_bar();
  int get_current_val();
  int get_size_x();
  int get_size_y();
  QPixmap get_sprite();
  void set_current_val(int v);
  void set_max_val(int v);
  void increment(int amount);
  void decrement(int amount);
};

#endif // BAR_H
