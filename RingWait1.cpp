#include "RingWait1.h"

RingWait1::RingWait1(QWidget *parent)
    : QDialog(parent)
{
    offset=0;
    //������ʱ��
    startTimer(50);
    //���ÿؼ���С
    setFixedSize(150,150);
    //ȥ�������� �����ö� ȥ��������ͼ��
    setWindowFlags(Qt::FramelessWindowHint|Qt::Tool|Qt::WindowCloseButtonHint|Qt::WindowStaysOnTopHint);

    //���ô��ڱ���͸��
    setAttribute(Qt::WA_TranslucentBackground, true);
}

RingWait1::~RingWait1()
{}

void RingWait1::timerEvent(QTimerEvent*)
{
    ++offset;
    if(offset>11)
        offset=0;
   update();
}

void RingWait1::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);  // �����

    int width=this->width();
    int height=this->height();

    //�����ƶ����м�
    painter.translate(width >> 1, height>> 1);

    //����ƫ������
    int offsetDest=(width-30)/2;

    painter.setPen(Qt::NoPen);

    //����СԲ����
    for(int i=0;i<12;++i){
        QPoint point(0,0);
        painter.setBrush(QColor(73,124,255,255-i*30));
        point.setX(offsetDest*qSin((-offset+i)*M_PI/6));
        point.setY(offsetDest*qCos((-offset+i)*M_PI/6));
        painter.drawEllipse(point.x()-10, point.y()-10, 20, 20);
    }
}
