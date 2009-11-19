#include <QWidget>

class Ball : public QWidget
{
public:
	Ball(Qwidget parent);
private:
	int x, int y;
	
	void paintEvent(QPaintEvent *event);
	bool inScreen();
}
	
