#ifndef RINGWAIT1_H
#define RINGWAIT1_H

#include <QtMath>
#include <QDialog>
#include <QPainter>
#include <QTimerEvent>

class RingWait1 : public QDialog
{
    Q_OBJECT

private:
    int offset;

public:
    RingWait1(QWidget *parent = nullptr);
    ~RingWait1();

protected:
    void paintEvent(QPaintEvent*);
    void timerEvent(QTimerEvent*);
};
#endif
