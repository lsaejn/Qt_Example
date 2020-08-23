#include "QtShadowWidgets_Alime.h"
#include <QPainter>

ShadowWidget::ShadowWidget(int shadowSize, QWidget* parent)
    : QWidget(parent)
{
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlag(Qt::FramelessWindowHint);
    setMouseTracking(true);
    //
    //m_shadow->setImage(image, QPoint(shadowSize + 1, shadowSize + 1));
}

#include <qmath.h>
void ShadowWidget::paintEvent(QPaintEvent* e)
{
    int borderSize = 1;
    QPainterPath path;
    path.setFillRule(Qt::WindingFill);
    path.addRect(borderSize, borderSize, this->width() - borderSize*2, this->height() - borderSize*2);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.fillPath(path, QBrush(Qt::white));

    QColor color(0, 0, 0, 50);
    for (int i = 0; i < borderSize; i++)
    {
        QPainterPath path;
        path.setFillRule(Qt::WindingFill);
        path.addRect(borderSize - i, borderSize - i, this->width() - (borderSize - i) * 2, this->height() - (borderSize - i) * 2);
        color.setAlpha(150 - qSqrt(i) * 50);
        painter.setPen(color);
        painter.drawPath(path);
    }
}
