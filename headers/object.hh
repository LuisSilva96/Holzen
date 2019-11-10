# ifndef OBJECT_H
# define OBJECT_H

# include <iostream>

# include <QApplication>
# include <QVector2D>
# include <QRect>
# include <QPixmap>
# include <QString>
# include <QPainter>
# include <QTimer>
# include <QDebug>
# include <entity.hh>

enum class Object_Type
  {
    CONSUMABLE,
    SMALLHEALTHPOTION,
    BIGHEALTHPOTION,
    SMALLMANAPOTION,
    BIGMANAPOTION,
    ARROW,
    NONINTERACTUABLE,
    INTERACTUABLE,
    BUSH,
    CHEST,
    TREE
  };

class Object : public QObject
{
  Q_OBJECT

private:
  QVector2D position;
  QPixmap object_sprite;
  QRect collision_rect;
  QString identifier;
  QTimer * lifetime;
  bool deleting;

public:
  explicit Object();
  explicit Object(const Object &);
  explicit Object(const QVector2D &&, const QPixmap &);
  explicit Object(const QVector2D &, const QPixmap &, const QString &);
  virtual ~Object(){}

  float get_x() const;
  float get_y() const;
  QPixmap get_object_sprite() const;
  QString get_identifier() const;
  QRect get_collision_rect() const;
  bool get_deleting() const;
  QVector2D get_pos() const;

  void set_x(const QVector2D &);
  void set_y(const QVector2D &);
  void set_x(float &&);
  void set_y(float &&);
  void set_object_sprite(const QPixmap &);
  void set_identifier(const QString &);
  void set_collision_rect(const QRect &);
  void set_col_rect_x(float &&);
  void set_col_rect_y(float &&);
  void set_col_rect_height(float &&);
  void set_col_rect_width(float &&);
  void set_deleting(bool);

  void object_picked_up();
  virtual void draw(QPainter &) = 0;
  virtual void behave(Entity &) = 0;
  virtual Object_Type get_type() = 0;

public slots:

  void destroy();

};

# endif
