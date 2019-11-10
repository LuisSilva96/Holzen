#ifndef MENU_CLASS
#define MENU_CLASS

# include <scenario.hh>

class Scenario;
class Menu;
extern Menu * menu;

enum class Option
  {START, CONFIGURATION, EXIT};

class Menu : public QWidget
{
  Q_OBJECT

private:
  Scenario *s;
  Option op;
  QPoint cursor;
  bool game_started = false;
  bool in_options = false;
  bool maximized = true;
  int PIXMAPS_X;
  int PIXMAPS_Y;
  unsigned width_;
  unsigned height_;

public:
  Menu(QWidget * parent = nullptr);
  ~Menu();

  void closeEvent(QCloseEvent *) override;
  void paintEvent(QPaintEvent *) override;
  void keyPressEvent(QKeyEvent *) override;

  void choice(Option);
};

#endif // MENU_CLASS
