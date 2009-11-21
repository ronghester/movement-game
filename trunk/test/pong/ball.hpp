#include <QWidget>

class Ball : public QWidget
{
public:
	Ball(QWidget *parent);
private:
	int x, y;
	
	void paintEvent(QPaintEvent *event);
	bool inScreen();
};
	
